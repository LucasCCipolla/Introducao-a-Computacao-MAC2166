/***************************************************************/
/**                                                           **/
/**   Lucas Canossa Cipolla          10769542                 **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Marcel Kenji de Carli Silva                  **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINHAS     20
#define MAXCOLUNAS    20
#define MAXNOME       64
#define TRUE           1
#define FALSE          0
#define SUBMARINO     'S'
#define DESTROYER     'D'
#define CRUZADOR      'C'
#define PORTA_AVIAO   'P'
#define HIDRO_AVIAO   'H'
#define BARCO         'B'
#define EXPLOSAO      '*'
#define AGUA          'a'
#define RASTRO        '.'
#define ESQUERDA      'e'
#define BAIXO         'b'
#define DIREITA       'd'
#define CIMA          'c'
int acertou_embarcacao(char ch)
{
    if (ch == 'S' || ch == 'D' || ch == 'C' || ch == 'P' || ch == 'H' || ch == 'B'){
        return TRUE;
    }else{
        return FALSE;
    }
}
void afunda_embarcacao(int linha, int coluna, char mapa[MAXLINHAS][MAXCOLUNAS])
{
    int i, j, di, dj;
    char ch;
    i=linha;
    j=coluna;
    ch=mapa[linha][coluna];
    if(mapa[i][j]=='S'){
        printf("submarino atingido!\n");
        mapa[i][j]='s';
    }
    mapa[linha][coluna]='*';
    for(di=-1;di<=1;di++){
        for(dj=-1;dj<=1;dj++){
            if(mapa[i+di][j+dj]=='D' && ch == 'D'){
                printf("destroyer atingido!\n");
                mapa[i+di][j+dj]='d';
            }
            if(mapa[i+di][j+dj]=='C' && ch == 'C'){
                printf("cruzador atingido!\n");
                mapa[i+di][j+dj]='c';
                i=(i+di);
                j=(j+dj);
                for(di=-1;di<=1;di++){
                    for(dj=-1;dj<=1;dj++){
                        if(mapa[i+di][j+dj]=='C' && ch == 'C'){
                            mapa[i+di][j+dj]='c';
                            i=(i+di);
                            j=(j+dj);
                            for(di=-1;di<=1;di++){
                                for(dj=-1;dj<=1;dj++){
                                    if(mapa[i+di][j+dj]=='C' && ch == 'C'){
                                        mapa[i+di][j+dj]='c';
                                        i=(i+di);
                                        j=(j+dj);
                                        for(di=-1;di<=1;di++){
                                            for(dj=-1;dj<=1;dj++){
                                                if(mapa[i+di][j+dj]=='C' && ch == 'C'){
                                                    mapa[i+di][j+dj]='c';
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                for(di=-1;di<=1;di++){
                    for(dj=-1;dj<=1;dj++){
                        if(mapa[linha+di][coluna+dj]=='C' && ch == 'C'){
                            mapa[linha+di][coluna+dj]='c';
                            i=(linha+di);
                            j=(coluna+dj);
                            for(di=-1;di<=1;di++){
                                for(dj=-1;dj<=1;dj++){
                                    if(mapa[i+di][j+dj]=='C' && ch == 'C'){
                                        mapa[i+di][j+dj]='c';
                                        i=(i+di);
                                        j=(j+dj);
                                        for(di=-1;di<=1;di++){
                                            for(dj=-1;dj<=1;dj++){
                                                if(mapa[i+di][j+dj]=='C' && ch == 'C'){
                                                    mapa[i+di][j+dj]='c';
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                printf("porta-avioes atingido!\n");
                mapa[i+di][j+dj]='p';
                i=(i+di);
                j=(j+dj);
                for(di=-1;di<=1;di++){
                    for(dj=-1;dj<=1;dj++){
                        if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                            mapa[i+di][j+dj]='p';
                            i=(i+di);
                            j=(j+dj);
                            for(di=-1;di<=1;di++){
                                for(dj=-1;dj<=1;dj++){
                                    if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                                        mapa[i+di][j+dj]='p';
                                        i=(i+di);
                                        j=(j+dj);
                                        for(di=-1;di<=1;di++){
                                            for(dj=-1;dj<=1;dj++){
                                                if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                                                    mapa[i+di][j+dj]='p';
                                                    i=(i+di);
                                                    j=(j+dj);
                                                    for(di=-1;di<=1;di++){
                                                        for(dj=-1;dj<=1;dj++){
                                                            if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                                                                mapa[i+di][j+dj]='p';
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            for(di=-1;di<=1;di++){
                    for(dj=-1;dj<=1;dj++){
                        if(mapa[linha+di][coluna+dj]=='P' && ch == 'P'){
                            mapa[linha+di][coluna+dj]='p';
                            i=(linha+di);
                            j=(coluna+dj);
                            for(di=-1;di<=1;di++){
                                for(dj=-1;dj<=1;dj++){
                                    if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                                        mapa[i+di][j+dj]='p';
                                        i=(i+di);
                                        j=(j+dj);
                                        for(di=-1;di<=1;di++){
                                            for(dj=-1;dj<=1;dj++){
                                                if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                                                    mapa[i+di][j+dj]='p';
                                                    i=(i+di);
                                                    j=(j+dj);
                                                    for(di=-1;di<=1;di++){
                                                        for(dj=-1;dj<=1;dj++){
                                                            if(mapa[i+di][j+dj]=='P' && ch == 'P'){
                                                                mapa[i+di][j+dj]='p';
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(mapa[i+di][j+dj]=='H' && ch == 'H'){
                printf("hidro-aviao atingido!\n");
                mapa[i+di][j+dj]='h';
                i=(i+di);
                j=(j+dj);
                for(di=-1;di<=1;di++){
                    for(dj=-1;dj<=1;dj++){
                        if(mapa[i+di][j+dj]=='H' && ch == 'H'){
                            mapa[i+di][j+dj]='h';
                        }
                    }
                }
            }
            if(mapa[i+di][j+dj]=='H' && ch == 'H'){
                mapa[i+di][j+dj]='h';
            }
        }
    }
}
int coluna_inicial_barco(char mapa[MAXLINHAS][MAXCOLUNAS])
{
    int i,j;
    i=1;
    j=1;
    while(mapa[i][j]!= 'B'){
        j++;
    }
    return j;
}
int no_aleatorio(int n)
{
  return  1 + (rand()/(RAND_MAX+1.0))*n;
}
void sorteie_posicao (int no_linhas, int no_colunas, int *linha, int *coluna)
{
  *linha  = no_aleatorio(no_linhas);
  *coluna = no_aleatorio(no_colunas);
}
void inicializa_gerador(int semente)
{
  srand(semente);
}
void leia_ate_barra_n (FILE *arq)
{
    char ch;
    fscanf(arq, "%c", &ch);
    while (ch != '\n'){
        fscanf(arq, "%c", &ch);
    }
}
void leia_mapa (int *no_linhas, int *no_colunas, char mapa[MAXLINHAS][MAXCOLUNAS], int *c_barco)
{
    FILE *arq;
    char nome_arquivo[MAXNOME];
    int no_l;
    int no_c;
    int c_bar;
    int i;
    int j;
    int codigo;
    printf("MSG do QG: prepare-se para a missao.\n");
    printf("MSG do QG: preparando para leitura do mapa.\n");
    printf("MSG do QG: forneca nome do arquivo que contem o mapa: ");
    scanf("%s", nome_arquivo);
    arq = fopen(nome_arquivo,"r");
    if (arq == NULL){
        printf("MSG do QG: erro na abertura do arquivo %s.\n", nome_arquivo);
        printf("MSG do QG: MISSAO ABORTADA!\n\n");
        system("pause");
        exit(-1);
    }
    printf("MSG do QG: arquivo %s foi encontrado.\n", nome_arquivo);
    printf("MSG do QG: mapa esta sendo lido do arquivo %s.\n", nome_arquivo);
    fscanf(arq, "%d %d %d", &no_l, &no_c, &codigo);
    leia_ate_barra_n(arq);
    printf("MSG do QG: mapa tem %d linhas e %d colunas.\n", no_l, no_c);
    printf("MSG do QG: codigo de ataque: %d\n", codigo);
    inicializa_gerador(codigo);
    i=1;
    for (i = 1; i <= no_l; i++)
    {
      for (j = 1; j <= no_c; j++)
        {
          fscanf(arq, "%c", &mapa[i][j]);
        }
      leia_ate_barra_n(arq);
    }
    c_bar=coluna_inicial_barco(mapa);
    printf("MSG do QG: posicao inicial do barco e' (1,%d).\n", c_bar);
    fclose(arq);
    printf("MSG do QG: mapa lido com sucesso.\n");
    *no_linhas  = no_l;
    *no_colunas = no_c;
    *c_barco    = c_bar;
}
void escreva_mapa_tela (int no_linhas, int no_colunas, char mapa[MAXLINHAS][MAXCOLUNAS])
{
    int i,j,chato;
    i=1;
    printf("MSG do QG: segue mapa da batalha.\n\n");
    printf("    MAPA DA BATALHA\n\n");
    printf("    ");
    while(i<=no_colunas){
        printf(" %2d ",i);
        i++;
    }
    i=1;
    printf("\n");
    while(i <= no_linhas){
        j=1;
        printf("    +");
        chato=j;
        while(chato<=no_colunas){
            printf("---+");
            chato++;
        }
        printf("\n");
        printf(" %2d |",i);
        while(j <= no_colunas){
            if(mapa[i][j] ==  'S' || mapa[i][j] ==  'D' || mapa[i][j] ==  'C' || mapa[i][j] ==  'P' || mapa[i][j] ==  'H'){
                printf("   |");
            }else{
                printf(" %c |", mapa[i][j]);
            }
            j++;
        }
        printf("\n");
        i++;
    }
    printf("    +");
    chato=1;
    while(chato<=no_colunas){
        printf("---+");
        chato++;
    }
    printf("\n");
}
void escreva_mapa_arquivo (int no_linhas, int no_colunas, char mapa[MAXLINHAS][MAXCOLUNAS])
{
    FILE *arq;
    int i;
    int j;
    int chato;
    arq = fopen("secreto.dat","w");
    if (arq == NULL){
        printf("MSG do QG:erro na criacao do arquivo secreto.dat.\n");
        printf("MSG do QG:MISSAO ABORTADA!\n\n");
        exit(-1);
    }
    fprintf(arq, "MAPA SECRETO DA BATALHA\n\n");
    fprintf(arq, "no. linhas = %d     no. colunas = %d\n\n", no_linhas,  no_colunas);
    i=1;
    fprintf(arq, "    ");
    while(i <= no_colunas){
        fprintf(arq, "  %d ",i);
        i++;
    }
    i=1;
    fprintf(arq, "\n");
    while(i <= no_linhas){
        j=1;
        fprintf(arq, "    +");
        chato=j;
        while(chato <= no_colunas){
            fprintf(arq, "---+");
            chato++;
        }
        fprintf(arq, "\n");
        fprintf(arq, "  %d |",i);
        while(j <= no_colunas){
            fprintf(arq, " %c |", mapa[i][j]);
            j++;
        }
        fprintf(arq, "\n");
        i++;
    }
    fprintf(arq, "    +");
    chato=1;
    while(chato<=no_colunas){
        fprintf(arq, "---+");
        chato++;
    }
    fprintf(arq, "\n\nFIM DO ARQUIVO.");
    fclose(arq);
}
int main()
{
    char mapa[MAXLINHAS][MAXCOLUNAS], move;
    int no_linhas, no_colunas, c_barco, i, j, ib, jb, cont;
    leia_mapa(&no_linhas, &no_colunas, mapa, &c_barco);
    escreva_mapa_tela(no_linhas, no_colunas,mapa);
    printf("MSG do QG: preparando artilharia para lhe dar cobertura.\n");
    printf("MSG do QG: cuidado com fogo amigo...\n");
    printf("MSG do QG: preparados para iniciar bombardeio da frota inimiga.\n");
    printf("MSG do QG: permissao para iniciar a missao concedida.\n");
    printf("MSG do QG: a sua posicao e' (1,%d).\n",c_barco);
    printf("MSG do QG: Boa sorte!\n\n");
    i=1;
    j=c_barco;
    scanf("%c", &move);
    cont=0;
    while(i!=no_linhas){
        printf("MSG do QG: escolha movimento ('e'=esquerda,'b'=baixo,'d'=direita,'c'=cima): ");
        scanf(" %c",&move);
        printf("MSG do QG: direcao escolhida: %c.\n", move);
        if(move == 'e' || move == 'E'){
            mapa[i][j]='.';
            j--;
            if(mapa[i][j]!= 'H' && mapa[i][j]!= 'S' && mapa[i][j]!= 'D' && mapa[i][j]!= 'C' && mapa[i][j]!= 'P'){
                if(j<=0){
                    printf("MSG do QG: tentou sumir do mapa para coluna -1.\n");
                    j++;
                    printf("MSG do QG: ficou parado em (%d,%d).\n", i, j);
                    mapa[i][j]='B';
                }else{
                    mapa[i][j]='B';
                    printf("MSG do QG: moveu-se para (%d,%d).\n", i, j);
                }
            }else{
                printf("MSG do QG: ha uma embarcacao na posicao (%d,%d).\n",i,j);
                j++;
                printf("MSG do QG: ficou parado em (%d,%d).\n",i,j);
                mapa[i][j]='B';
            }
        }
        if(move == 'b' || move == 'B'){
            mapa[i][j]='.';
            i++;
            if(mapa[i][j]!= 'H' && mapa[i][j]!= 'S' && mapa[i][j]!= 'D' && mapa[i][j]!= 'C' && mapa[i][j]!= 'P'){
                if(i>no_linhas){
                    printf("MSG do QG: tentou sumir do mapa para linha %d.\n", (no_linhas+1));
                    i--;
                    printf("MSG do QG: ficou parado em (%d,%d).\n", i, j);
                    mapa[i][j]='B';
                }else{
                    mapa[i][j]='B';
                    printf("MSG do QG: moveu-se para (%d,%d).\n", i, j);
                }
            }else{
                printf("MSG do QG: ha uma embarcacao na posicao (%d,%d).\n",i,j);
                i--;
                printf("MSG do QG: ficou parado em (%d,%d).\n",i,j);
                mapa[i][j]='B';
            }
        }
        if(move == 'd' || move == 'D'){
            mapa[i][j]='.';
            j++;
            if(mapa[i][j]!= 'H' && mapa[i][j]!= 'S' && mapa[i][j]!= 'D' && mapa[i][j]!= 'C' && mapa[i][j]!= 'P'){
                if(j>no_colunas){
                    printf("MSG do QG: tentou sumir do mapa para coluna %d.\n", (no_colunas+1));
                    j--;
                    printf("MSG do QG: ficou parado em (%d,%d).\n", i, j);
                    mapa[i][j]='B';
                }else{
                    mapa[i][j]='B';
                    printf("MSG do QG: moveu-se para (%d,%d).\n", i, j);
                }
            }else{
                printf("MSG do QG: ha uma embarcacao na posicao (%d,%d).\n",i,j);
                j--;
                printf("MSG do QG: ficou parado em (%d,%d).\n",i,j);
                mapa[i][j]='B';
            }
        }
        if(move == 'c' || move == 'C'){
            mapa[i][j]='.';
            i--;
            if(mapa[i][j]!= 'H' && mapa[i][j]!= 'S' && mapa[i][j]!= 'D' && mapa[i][j]!= 'C' && mapa[i][j]!= 'P'){
                if(i<=0){
                    printf("MSG do QG: tentou sumir do mapa para linha -1.\n");
                    i++;
                    printf("MSG do QG: ficou parado em (%d,%d).\n", i, j);
                    mapa[i][j]='B';
                }else{
                    mapa[i][j]='B';
                    printf("MSG do QG: moveu-se para (%d,%d).\n", i, j);
                }
            }else{
                printf("MSG do QG: ha uma embarcacao na posicao (%d,%d).\n",i,j);
                i++;
                printf("MSG do QG: ficou parado em (%d,%d).\n",i,j);
                mapa[i][j]='B';
            }
        }
        sorteie_posicao(no_linhas, no_colunas, &ib, &jb);
        printf("MSG do QG: posicao (%d,%d), ", ib, jb);
        if(acertou_embarcacao(mapa[ib][jb])){
            printf("BUUMMM\n");
            printf("MSG do QG: posicao (%d,%d), ", ib, jb);
            if(mapa[ib][jb]==mapa[i][j]){
                printf("opsssss... voce foi atingido!\n");
                mapa[i][j]='X';
                escreva_mapa_arquivo(no_linhas, no_colunas, mapa);
                escreva_mapa_tela(no_linhas, no_colunas, mapa);
                printf("MSG do QG: infelizmente voce foi destruido em (%d,%d).\n", i, j);
                printf("MSG do QG: VOCE FRACASSOU EM SUA MISSAO... FICA PARA A PROXIMA.\n\n");
                printf("MSG do QG: MSG final do nosso amado Almirante:\n\n");
                printf("01001101 01000001 01000011 00110010 00110001 00110110 00110110\n\n");
                return 0;
            }else{
                afunda_embarcacao(ib,jb,mapa);
            }
        }else{
            printf("CHUA ... AGUA\n");
            mapa[ib][jb]='a';
        }
        sorteie_posicao(no_linhas, no_colunas, &ib, &jb);
        printf("MSG do QG: posicao (%d,%d), ", ib, jb);
        if(acertou_embarcacao(mapa[ib][jb])){
            printf("BUUMMM\n");
            printf("MSG do QG: posicao (%d,%d), ", ib, jb);
            if(mapa[ib][jb]==mapa[i][j]){
                printf("opsssss... voce foi atingido!\n");
                mapa[i][j]='X';
                escreva_mapa_arquivo(no_linhas, no_colunas, mapa);
                escreva_mapa_tela(no_linhas, no_colunas, mapa);
                printf("MSG do QG: infelizmente voce foi destruido em (%d,%d).\n", i, j);
                printf("MSG do QG: VOCE FRACASSOU EM SUA MISSAO... FICA PARA A PROXIMA.\n\n");
                printf("MSG do QG: MSG final do nosso amado Almirante:\n\n");
                printf("01001101 01000001 01000011 00110010 00110001 00110110 00110110\n\n");
                return 0;
            }else{
                afunda_embarcacao(ib,jb,mapa);
            }
        }else{
            printf("CHUA ... AGUA\n");
            mapa[ib][jb]='a';
        }
        sorteie_posicao(no_linhas, no_colunas, &ib, &jb);
        printf("MSG do QG: posicao (%d,%d), ", ib, jb);
        if(acertou_embarcacao(mapa[ib][jb])){
            printf("BUUMMM\n");
            printf("MSG do QG: posicao (%d,%d), ", ib, jb);
            if((mapa[ib][jb])==(mapa[i][j])){
                printf("opsssss... voce foi atingido!\n");
                mapa[i][j]='X';
                escreva_mapa_arquivo(no_linhas, no_colunas, mapa);
                escreva_mapa_tela(no_linhas, no_colunas, mapa);
                printf("MSG do QG: infelizmente voce foi destruido em (%d,%d).\n", i, j);
                printf("MSG do QG: VOCE FRACASSOU EM SUA MISSAO... FICA PARA A PROXIMA.\n\n");
                printf("MSG do QG: MSG final do nosso amado Almirante:\n\n");
                printf("01001101 01000001 01000011 00110010 00110001 00110110 00110110\n\n");
                return 0;
            }else{
                afunda_embarcacao(ib,jb,mapa);
            }
        }else{
            printf("CHUA ... AGUA\n");
            mapa[ib][jb]='a';
        }
        escreva_mapa_arquivo(no_linhas, no_colunas, mapa);
        escreva_mapa_tela(no_linhas, no_colunas, mapa);
        if(mapa[i][j]==mapa[1][c_barco]){
            cont++;
        }
        if(cont==3){
            printf("MSG do QG: infelizmente voce ficou encalhado em (%d,%d).\n", i, j);
            printf("MSG do QG: VOCE FRACASSOU EM SUA MISSAO... FICA PARA A PROXIMA.\n\n");
            printf("MSG do QG: MSG final do nosso amado Almirante:\n\n");
            printf("01001101 01000001 01000011 00110010 00110001 00110110 00110110\n\n");
            return 0;
        }
    }
    printf("MSG do QG: PARABENS!!! Voce chegou a (%d,%d).\n", i, j);
    printf("MSG do QG: VOCE COMPLETOU A SUA MISSAO COM PICARDIA!\n\n");
    printf("MSG do QG: MSG final do nosso amado Almirante:\n\n");
    printf("01001101 01000001 01000011 00110010 00110001 00110110 00110110\n\n");
    return 0;
}
