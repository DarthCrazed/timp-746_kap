#include <stdio.h>
#include <math.h>

void main()
{
int n, i;
double sr;
scanf("%d", &n);
int a[n];
for (i = 0; i<=n; i++){
scanf("%d", &a[i]);}
sr=a[0]/n;
for (i=1; i<=n; i++){
sr=sr+a[i]/n;
}
printf ("%lf", sr);
}
