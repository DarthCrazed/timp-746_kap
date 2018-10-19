#include <stdio.h>
#include <malloc.h>
void hoarasort(int* mas, int first, int last)
{

int i = first, j = last;
double con, x = mas[(first + last) / 2];

do {
   while (mas[i] < x)
     i++;
   while (mas[j] > x)
     j--;

   if (i <= j)
   {
     if (i < j)
     {
       con=mas[i];
       mas[i]=mas[j];
       mas[j]=con;
     }
     i++;
     j--;
   }
} while (i <= j);

if (i < last)
   hoarasort(mas, i, last);
if (first < j)
   hoarasort(mas, first,j);
}


int main(void)
{
	int *mas;
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	

	mas = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &mas[i]);
	}
	hoarasort(mas,0,n-1);

	
	for (i = 0; i < n; i++)
		printf("%d ", mas[i]);
	free(mas);
	getchar();   getchar();
	return 0;

}

