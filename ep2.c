#include <stdio.h>
#define PI 3.14159
#define EPS_COS 0.000001
#define RAIO_QG 200
#define RAIO_ZA 2000
#define DELTA_ALARME 60
#define EPS 0.01
double cosseno(double theta, double epsilon)
{
    double termo, cosseno;
    int n,i,k;
    theta=(theta*PI)/180;
    n=0;
    while (epsilon!=1){
        epsilon*=10;
        n++;
    }
    cosseno=0;
    termo=1;
    k=0;
    i=0;
    while (k!=n){
        cosseno+=termo;
        termo = termo * -(theta*theta)/((i+2)*(i+1));
        k++;
        i+=2;
    }
    return cosseno;
}
double raiz(double x, double epsilon)
{
    double r,r1;
    r=x;
    r1=0;
    while((r1-r>epsilon) | (r-r1>epsilon)){
        r1=r;
        r=(r+(x/r))/2;
    }
    return r;
}
int localiza (double xi, double yi, double div, double xj, double yj, double djv, double xk, double yk, double dkv, double *xv, double *yv)
{
    double pij,qij,pik,qik,pjk,qjk;
    pij=xi*xi;
    pij-=xj*xj;
    pij+=yi*yi;
    pij-=yj*yj;
    pij-=div*div;
    pij+=djv*djv;
    pij/=2*(xi-xj);
    qij=yj-yi;
    qij/=xi-xj;
    pik=xi*xi;
    pik-=xk*xk;
    pik+=yi*yi;
    pik-=yk*yk;
    pik-=div*div;
    pik+=dkv*dkv;
    pik/=2*(xi-xk);
    qik=yk-yi;
    qik/=xi-xk;
    *yv=pik-pij;
    *yv/=qij-qik;
    *xv=pij;
    *xv+=qij*(*yv);
    if((xi==xk)){
    pij=xi*xi;
    pij-=xj*xj;
    pij+=yi*yi;
    pij-=yj*yj;
    pij-=div*div;
    pij+=djv*djv;
    pij/=2*(xi-xj);
    qij=yj-yi;
    qij/=xi-xj;
    pjk=xj*xj;
    pjk-=xk*xk;
    pjk+=yj*yj;
    pjk-=yk*yk;
    pjk-=djv*djv;
    pjk+=dkv*dkv;
    pjk/=2*(xj-xk);
    qjk=yk-yj;
    qjk/=xj-xk;
    *yv=pjk-pij;
    *yv/=qij-qjk;
    *xv=pij;
    *xv+=qij*(*yv);
    }else if((xi==xj)){
    pik=xi*xi;
    pik-=xk*xk;
    pik+=yi*yi;
    pik-=yk*yk;
    pik-=div*div;
    pik+=dkv*dkv;
    pik/=2*(xi-xk);
    qik=yk-yi;
    qik/=xi-xk;
    pjk=xj*xj;
    pjk-=xk*xk;
    pjk+=yj*yj;
    pjk-=yk*yk;
    pjk-=djv*djv;
    pjk+=dkv*dkv;
    pjk/=2*(xj-xk);
    qjk=yk-yj;
    qjk/=xj-xk;
    *yv=pjk-pik;
    *yv/=qik-qjk;
    *xv=pik;
    *xv+=qik*(*yv);
    }else if(xj==xk){
        return 0;
    }
    return 1;
}
double velocidade(double x0, double y0, double x1, double y1, double deltaT)
{
    double distancia,velocidade;
    distancia=(x0-x1)*(x0-x1)+(y0-y1)*(y0-y1);
    distancia=raiz(distancia,EPS);
    velocidade=distancia/deltaT;
    return velocidade;
}
double dponto(double x0, double y0, double x1, double y1, double epsilon)
{
    double d;
    d=(x1-x0)*(x1-x0) + (y1-y0)*(y1-y0);
    d=raiz(d,epsilon);
    return d;
}
int intercepta(double x0, double y0, double x1, double y1, double *x, double *y)
{
    double m,r,a,c,b,xx,yx,xy,yy,delta;
    r=200;
    m=(y1-y0)/(x1-x0);
    a=(1 + (m*m));
    c=((m*m)*(x0*x0)) + (y0*y0) - (2*m*x0*y0) - (r*r);
    b=(2*m*y0) - (2*(m*m)*x0);
    delta=(b*b) - (4*a*c);
    if(delta<0){
        return 0;
    }
    delta= raiz(delta,EPS);
    xx=((-1*b) + delta)/(2*a);
    xy=((-1*b) - delta)/(2*a);
    yx= m*(xx-x0) + y0;
    yy= m*(xy-x0) + y0;
    if((dponto(x1,y1,xx,yx,EPS))<(dponto(x1,y1,yx,yy,EPS))){
        *x=xx;
        *y=yx;
    }else{
        *x=xy;
        *y=yy;
    }
    if((dponto(x0,y0,xx,yx,0.01))<(dponto(x0,y0,x1,y1,0.01))){
        return 0;
    }else if((dponto(x0,y0,yx,*y,0.01))<(dponto(x0,y0,x1,y1,0.01))){
        return 0;
    }
    if((dponto(x1,y1,yx,*y,0.01))>(dponto(x0,y0,yx,*y,0.01))){
        return 0;
    }
    return 1;
}

int main()
{
    double local,x,y,d,xi,xj,xk,yi,yj,yk,div,djv,dkv,xv,yv,num,H,deltaT,x1,x2,y1,y2,v,distancia,d0,ix,iy,datual,t,alarme;
    int i,n;
    FILE *arq;
    arq = fopen("entrada.txt","r");
    fscanf(arq, "%d", &n);
    if (arq == NULL) {
        printf("Nao consegui abrir o arquivo.\n");
        return 0;
    }
    printf("Programa-demo para o Sistema de Monitoramento de Politeranos\n\n");
    i=0;
    printf("Numero de casos a serem analisados: %d\n",n);
    while (i!=n) {
            fscanf(arq, "%lf", &num);
            printf("\nIDENTIFICACAO: veiculo %.0f\n", num);
            printf("\nAntenas ( id | posicao | H (m) | theta (graus) | distancia (m) )\n");
            fscanf(arq, "%lf", &num);
            printf("%2.0f | ",num);
            fscanf(arq, "%lf", &num);
            printf("(%8.2f,", num);
            x=num;
            fscanf(arq, "%lf", &num);
            printf("%8.2f) |", num);
            y=num;
            fscanf(arq, "%lf", &num);
            H=num;
            printf("%8.2f |", num);
            fscanf(arq, "%lf", &num);
            printf("%10.2f |", num);
            d=H*(cosseno(num,EPS_COS));
            printf("%9.2f\n",d);
            xi=x;
            yi=y;
            div=d;
            fscanf(arq, "%lf", &num);
            printf("%2.0f | ",num);
            fscanf(arq, "%lf", &num);
            printf("(%8.2f,", num);
            x=num;
            fscanf(arq, "%lf", &num);
            printf("%8.2f) |", num);
            y=num;
            fscanf(arq, "%lf", &num);
            H=num;
            printf("%8.2f |", num);
            fscanf(arq, "%lf", &num);
            printf("%10.2f |", num);
            d=H*(cosseno(num,EPS_COS));
            printf("%9.2f\n",d);
            xj=x;
            yj=y;
            djv=d;
            fscanf(arq, "%lf", &num);
            printf("%2.0f | ",num);
            fscanf(arq, "%lf", &num);
            printf("(%8.2f,", num);
            x=num;
            fscanf(arq, "%lf", &num);
            printf("%8.2f) |", num);
            y=num;
            fscanf(arq, "%lf", &num);
            H=num;
            printf("%8.2f |", num);
            fscanf(arq, "%lf", &num);
            printf("%10.2f |", num);
            d=H*(cosseno(num,EPS_COS));
            printf("%9.2f\n",d);
            xk=x;
            yk=y;
            dkv=d;
            local=localiza(xi,yi,div,xj,yj,djv,xk,yk,dkv,&xv,&yv);
            x1=xv;
            y1=yv;
            if(local==0){
                printf("Nao foi possivel realizar a conta");
            }
            printf("\nLocalizacao previa: (%8.2f,%8.2f)\n",xv,yv);
            fscanf(arq, "%lf", &num);
            printf("\nIntervalo de tempo: %.2f segundos\n",num);
            deltaT=num;
            printf("\nAntenas ( id | posicao | H (m) | theta (graus) | distancia (m) )\n");
            fscanf(arq, "%lf", &num);
            printf("%2.0f | ",num);
            fscanf(arq, "%lf", &num);
            printf("(%8.2f,", num);
            x=num;
            fscanf(arq, "%lf", &num);
            printf("%8.2f) |", num);
            y=num;
            fscanf(arq, "%lf", &num);
            H=num;
            printf("%8.2f |", num);
            fscanf(arq, "%lf", &num);
            printf("%10.2f |", num);
            d=H*(cosseno(num,EPS_COS));
            printf("%9.2f\n",d);
            xi=x;
            yi=y;
            div=d;
            fscanf(arq, "%lf", &num);
            printf("%2.0f | ",num);
            fscanf(arq, "%lf", &num);
            printf("(%8.2f,", num);
            x=num;
            fscanf(arq, "%lf", &num);
            printf("%8.2f) |", num);
            y=num;
            fscanf(arq, "%lf", &num);
            H=num;
            printf("%8.2f |", num);
            fscanf(arq, "%lf", &num);
            printf("%10.2f |", num);
            d=H*(cosseno(num,EPS_COS));
            printf("%9.2f\n",d);
            xj=x;
            yj=y;
            djv=d;
            fscanf(arq, "%lf", &num);
            printf("%2.0f | ",num);
            fscanf(arq, "%lf", &num);
            printf("(%8.2f,", num);
            x=num;
            fscanf(arq, "%lf", &num);
            printf("%8.2f) |", num);
            y=num;
            fscanf(arq, "%lf", &num);
            H=num;
            printf("%8.2f |", num);
            fscanf(arq, "%lf", &num);
            printf("%10.2f |", num);
            d=H*(cosseno(num,EPS_COS));
            printf("%9.2f\n",d);
            xk=x;
            yk=y;
            dkv=d;
            local=localiza(xi,yi,div,xj,yj,djv,xk,yk,dkv,&xv,&yv);
            x2=xv;
            y2=yv;
            if(local==0){
                printf("Nao foi possivel realizar a conta");
            }
            printf("\nLocalizacao atual: (%8.2f,%8.2f)\n",xv,yv);
            v=velocidade(x1,y1,x2,y2,deltaT);
            distancia=v*deltaT;
            printf("\nDistancia percorrida: %.2f m\n",distancia);
            printf("Velocidade: %.2f m/s\n",v);
            d0=dponto(x2,y2,0,0,EPS);
            printf("\nDistancia da origem: %.2f\n",d0);
            alarme=1;
            if(v!=0){
                printf("Veiculo em movimento");
            }else{
                printf("Veiculo estacionado");
                alarme=0;
            }
            if(d0<RAIO_QG){
                printf(" no QG\n");
                printf("\n*************************************\n  ALARME, ALARME, ALARME, ALARME !!\n    Salve-se quem puder !\n*************************************");
            }else if(d0<RAIO_ZA){
                printf(" na ZONA DE ALERTA\n");
            }else{
                printf(" fora da ZONA DE ALERTA\n");
                alarme=0;
            }
            if (intercepta(x1,y1,x2,y2,&ix,&iy) && alarme){
                printf("\nTrajetoria INTERCEPTARA QG\n");
                datual=dponto(x2,y2,ix,iy,EPS);
                printf("Distancia atual ao QG e' de %.2f metros\n",datual);
                t=datual/v;
                printf("Interseccao ocorrera em %.2f segundos,\nna coordenada (%8.2f,%8.2f)\n",t,ix,iy);
                if(t<DELTA_ALARME){
                printf("\n*************************************\n  ALARME, ALARME, ALARME, ALARME !!\n    Vistam seus capacetes !\n*************************************\n");
                }
            }else if(!intercepta(x1,y1,x2,y2,&ix,&iy) && alarme){
                printf("\nTrajetoria NAO INTERCEPTARA QG\n");
            }
            i++;
}
return 0;
}
