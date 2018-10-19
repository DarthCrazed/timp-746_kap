#include <stdio.h>
#include <malloc.h>

void shellsort (int *mas, int n)
{
    int t;
    int step;
    int i = 0;
    int j = 0;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			t = mas[i];
			for (j = i; j >= step; j -= step)
			{
				if (t < mas[j - step])
					mas[j] = mas[j - step];
				else
					break;
			}
			mas[j] = t;
		}

}

int main(void)
{
	int *mas;
	int n = 0;
	int i = 0;
	scanf("%d", &n);

	mas = (int*)malloc(n * sizeof(int));
	// Ввод элементов массива
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &mas[i]);
	}

    shellsort(mas, n);

	// Вывод элементов массива
	for (i = 0; i < n; i++)
		printf("%d ", mas[i]);
	free(mas);
	getchar();   getchar();
	return 0;
}


