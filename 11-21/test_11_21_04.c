//ц╟ещеепР
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[4];
	int a = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	for (a = 0; a < n;a++)
	{
		scanf("%d", &arr[a]);
	}
	int i, j;
	for (i = 0;i < n - 1;i++)
	{
		for (j = 0;j < n - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	for (i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}