#include <stdio.h>
#include <math.h>
int c=0;
int a=1;
int kolaps(int x, int y)
{
c=c+1;
a=a*x;
if (c<y)
  kolaps(x, y);
int re;
re = a;
return re;
}

void main()
{
int x, y, z;
scanf ("%d", &x);
scanf ("%d", &y);
z=kolaps(x, y);
printf("%d", z);
}
