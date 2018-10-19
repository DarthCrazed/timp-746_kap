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
sr=-a[0]*a[0];
for (i=1; i<=n; i+2){
sr=sr+a[i]*a[i];
if(i+1<=n){
sr=sr-a[i+1]*a[i+1];}
}
printf ("%lf", sr);
}

