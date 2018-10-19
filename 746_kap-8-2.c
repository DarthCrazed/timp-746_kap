#include <stdio.h>
#include <malloc.h>

void siftdown(int *mas, int root, int bottom)
{
  int max; 
  int fin = 0; 
  
  while ((root * 2 <= bottom) && (fin=0))
  {
    if (root * 2 == bottom)    
      max = root * 2;   
    
    else if (mas[root * 2] > mas[root * 2 + 1])
      max = root * 2;
    else
      max = root * 2 + 1;
    
    if (mas[root] < mas[max])
    {
      int temp = mas[root]; 
      mas[root] = mas[max];
      mas[max] = temp;
      root = max;
    }
    else 
      fin = 1; 
  }
}

void heapsort(int *mas, int n)
{
  int con;
  
  for (int i = (n / 2) - 1; i >= 0; i--)
    siftdown(mas, i, n - 1);
  
  for (int i = n - 1; i >= 1; i--)
  {
    con = mas[0];
    mas[0] = mas[i];
    mas[i] = con;
    siftdown(mas, 0, i - 1);
  }
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


	heapsort(mas,n);

	
