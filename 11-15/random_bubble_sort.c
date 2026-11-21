#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 1
#define MAX_LENGTH 1000

/* 读取数组长度：只接受 1~1000 的整数，非法输入会重新提示 */
static int read_length(void)
{
	char line[128];
	char *end;
	long value;
	int c;

	for (;;)
	{
		printf("请输入数组长度 n (%d~%d): ", MIN_LENGTH, MAX_LENGTH);
		if (fgets(line, sizeof(line), stdin) == NULL)
		{
			return -1;  /* 输入结束或读取出错 */
		}

		value = strtol(line, &end, 10);

		/* 跳过整数后面的空白字符，确保整行只包含一个整数 */
		while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')
		{
			end++;
		}

		if (end != line && *end == '\0' && value >= MIN_LENGTH && value <= MAX_LENGTH)
		{
			return (int)value;
		}

		printf("输入不合法，请输入 %d~%d 的整数。\n", MIN_LENGTH, MAX_LENGTH);

		/* 如果这一行太长没有读完，清掉剩余字符，避免影响下一次输入 */
		if (strchr(line, '\n') == NULL)
		{
			while ((c = getchar()) != '\n' && c != EOF)
			{
				;
			}
		}
	}
}

/* 打印数组，每行 20 个元素 */
static void print_array(const int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%5d", arr[i]);
		if ((i + 1) % 20 == 0)
		{
			printf("\n");
		}
	}
	if (n % 20 != 0)
	{
		printf("\n");
	}
}

/* 冒泡排序（升序），通过指针返回比较次数、交换次数和排序趟数 */
static void bubble_sort(int arr[], int n, int *cmp_count, int *swap_count, int *pass_count)
{
	int i, j, swapped, tmp;

	*cmp_count = 0;
	*swap_count = 0;
	*pass_count = 0;

	for (i = 0; i < n - 1; i++)
	{
		(*pass_count)++;  /* 记录实际执行了多少趟 */
		swapped = 0;

		for (j = 0; j < n - 1 - i; j++)
		{
			(*cmp_count)++;  /* 每比较一次相邻元素，比较次数加 1 */
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				(*swap_count)++;  /* 每交换一次，交换次数加 1 */
				swapped = 1;
			}
		}

		if (!swapped)  /* 本趟没有交换，说明已经有序，提前结束 */
		{
			break;
		}
	}
}

int main(void)
{
	int n;
	int *arr;
	int i;
	int cmp_count, swap_count, pass_count;

	n = read_length();
	if (n < 0)
	{
		printf("没有读到有效的数组长度，程序结束。\n");
		return 1;
	}

	arr = (int *)malloc((size_t)n * sizeof(int));
	if (arr == NULL)
	{
		printf("内存分配失败，程序结束。\n");
		return 1;
	}

	srand((unsigned)time(NULL));  /* 用当前时间做随机种子，保证每次运行不同 */
	for (i = 0; i < n; i++)
	{
		arr[i] = rand() % (n + 1);  /* 生成 0~n（含 n）的随机数 */
	}

	printf("\n排序前:\n");
	print_array(arr, n);

	bubble_sort(arr, n, &cmp_count, &swap_count, &pass_count);

	printf("\n排序后:\n");
	print_array(arr, n);

	printf("\n统计结果:\n");
	printf("  比较次数: %d\n", cmp_count);
	printf("  交换次数: %d\n", swap_count);
	printf("  排序趟数: %d\n", pass_count);

	free(arr);
	return 0;
}
