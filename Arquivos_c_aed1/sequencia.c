#include <stdio.h>

int main(void) {
  int n, m, soma = 0, inicio , fim;
  
  scanf("%d %d", &n, &m);
  
  if(n > m){
  inicio = m;
  fim = n;
  }else{
    inicio = n;
    fim = m;
  }

  for(int i = inicio; i <= fim; i++){
    printf("%d ", i);
    soma += i;
  }
  
  printf("Soma = %d", soma);



return 0;
}