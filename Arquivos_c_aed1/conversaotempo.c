#include <stdio.h>

int main(void)
{
  int seg, min, hrs;

  scanf("%d", &seg);

  hrs = seg / 3600;

  min = (seg % 3600) / 60;

  seg = seg % 60;

  printf("%02d:%02d:%02d", hrs, min, seg);

  return 0;
}