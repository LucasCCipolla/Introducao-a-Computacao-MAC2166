/***************************************************************/
/**                                                           **/
/**   Lucas Canossa Cipolla          10769542                 **/
/**   Exercício-Programa 1                                    **/
/**   Professor: Marcel Kenji de Carli Silva                  **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
int main()
{
  int n,x,xx,xy,xz,a,b,c,d,e,f,g,h,i,j,k,l,m; /*Declarando variáveis*/
  printf("MAC2166 - EP1 - O Sistema Monetario de Gwonck\n");
  printf("Digite a quantidade n de numeros a serem convertidos: ");
  scanf("%d",&n); /*Quantidade a ser convertido*/
    while(n!=0){ /*Variável n será utilizada da mesma maneira que um contador*/
  printf("Digite um numero a ser convertido: ");
  scanf("%d",&x); /*Número à ser convertido*/
  xx=x; /*Números aplicados à outra variável para que sejam feitas as operações*/
  xy=x;
  xz=x;
  a=b=c=d=e=f=g=h=i=j=k=l=m=0; /*Variáveis recebendo zero pois o programa é feito para não ler caso seja um zero à esquerda*/
  printf("%d na base 5 e' ",x);
  if(xx/625!=0){ /*Lógica sequencial: se o número máximo é 2000, 625 é o maior múltiplo de 5 que divide, o próximo seria 3125*/
    a=xx/625;
    xx=xx%625;/*Sendo assim, quando dividido por a, o resto ainda deve prosseguir com a sequência de divisões*/
    printf("%d",a);
    }
  if(a!=0 && xx/125==0){ /*Se o anterior for diferente de zero, é necessário que o próximo número, mesmo que seja zero, apareça*/
    b=0;
    printf("%d",b);
  }
  if(xx/125!=0){ /*Caso a divisão por 125 (múltiplo de 5 anterior à 625) seja diferente de zero, b deve ser mostrado*/
    b=xx/125;
    xx=xx%125;
    printf("%d",b);
    }
  if(b!=0 && xx/25==0){
    c=0;
    printf("%d",c);
  }
  if(xx/25!=0){
    c=xx/25;
    xx=xx%25;
    printf("%d",c);
    }
  if(c!=0 && xx/5==0){
    d=0;
    printf("%d",d);
  }
  if(xx/5!=0){ /*Após todo o processo, ainda contabiliza-se o resto da divisão pelo número da base sendo o último número*/
    d=xx/5;
    e=xx%5;
    printf("%d",d);
    }else{
      e=xx; /*Caso d for zero, o que sobrar deve pertencer à última casa de alagaristmos */
      }
      printf("%d\n",e); /*Sendo assim, mostram-se todos os números em sequência e suas divisões pelos múltiplos da base*/
      printf("%d na base 7 e' ",x); /*Repete-se o mesmo processo para as próximas bases*/
  if(xy/343!=0){ /*343 é o maior divisor múltiplo de 7, o próximo seria 2401 que é maior que 2000*/
    f=xy/343;
    xy=xy%343;
    printf("%d",f);
    }
  if(f!=0 && xy/49==0){
    g=0;
    printf("%d",g);
  }
  if(xy/49!=0){
    g=xy/49;
    xy=xy%49;
    printf("%d",g);
    }
  if(g!=0 && xy/7==0){
    h=0;
    printf("%d",h);
  }
  if(xy/7!=0){
    h=xy/7;
    i=xy%7;
    printf("%d",h);
    }else{
      i=xy;
      }
      printf("%d\n",i);
      printf("%d na base 9 e' ",x);
  if(xz/729!=0){ /*729 maior múltiplo de 9 que divide resultados até 2000, o próximo seria 6561*/
    j=xz/729;
    xz=xz%729;
    printf("%d",j);
    }
  if(j!=0 && xz/81==0){
    k=0;
    printf("%d",k);
  }
  if(xz/81!=0){
    k=xz/81;
    xz=xz%81;
    printf("%d",k);
    }
  if(k!=0 && xz/9==0){
    l=0;
    printf("%d",l);
  }
  if(xz/9!=0){
    l=xz/9;
    m=xz%9;
    printf("%d",l);
    }else{
      m=xz;
      }
      printf("%d\n",m);
      n--;
}
return 0;
}
