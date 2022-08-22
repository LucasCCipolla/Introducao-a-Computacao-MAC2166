/***************************************************************/
/**                                                           **/
/**   Lucas Canossa Cipolla          10769542                 **/
/**   Exercício-Programa 0                                    **/
/**   Professor: Marcel Kenji de Carli Silva                  **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
int main()
{
  int x,i;
  printf("Digite seu numero entre 0 e 10000:");
  scanf("%d",&x);
  i=1;
  if(x<=10000){
  while(x/10!=0){
    x=x/10;
    i++;
    }
  if(x==0){
    i=0;
    }
  printf("Seu numero apresenta %d digito(s)\n",i);
  }
  return 0;
}
