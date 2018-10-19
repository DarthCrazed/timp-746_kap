nclude <stdio.h>
#include <malloc.h>


void combsort(int *mas, int n)
{
    int i = 0;
	int con;
	int step;
    step = (n / 1.247);

    while (step >= 1)
	{
		for (i = 0; i + step < n; i++)
		{
			if (mas[i] > mas[i + step])
			{
				con = mas[i];
				mas[i] = mas[i + step];
				mas[i + step] = con;
			}
		}
		step /= 1.247;
	}
	
	for (i = 0; i < n - 1; i++) {
			if (mas[i] > mas[i + 1]) {
				con = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = con;
			}
		}
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

	combsort(mas, n);

	// Вывод элементов массива
	for (i = 0; i < n; i++)
		printf("%d ", mas[i]);
	free(mas);
	getchar();   getchar();
	return 0;


	//scanf("%d", &n);
	return 0;
}
