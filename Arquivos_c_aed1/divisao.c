#include <stdio.h>

int main(void) {
  int n;
  
  scanf("%d", &n);
  
  if( n % 3  == 0 ){
    printf("Divisível por 3");
  }else if(n % 5 == 0 ){
    printf("Divisível por 5");
  }else if( n % 3  == 0 && n % 5 == 0 ){
    printf("Divisível por Ambos");
  }else{
    printf("Não é divisível por 3 nem por 5");
  }
  
  return 0;
}