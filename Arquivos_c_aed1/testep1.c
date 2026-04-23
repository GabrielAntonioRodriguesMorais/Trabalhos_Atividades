#include <stdio.h>

int main()
{

   int i, x, y, n, t;
   x = 1;
   y = -2;
   scanf("%d", &n);
   for (i = 1; i <= n; i++)
   {
      if (i % 2 == 0 && i % 3 == 0)
      {
         t = y;
         y = y - 2;
      }
      else
      {
         t = x;
         x = x + 2;
      }
      printf("%d\n", t);
   }

   return 0;
}