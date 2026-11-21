#include <stdio.h>
/* 冒泡排序：把 arr 中的 n 个元素按从小到大排序 */
void paixu(int arr[], int n)
{
	int i, j;
	/* 外层循环控制趟数，最多 n-1 趟；
	   i 同时也表示数组末尾已经排好的元素个数 */
	for(i = 0;i < n - 1;i++)
	{
		int b = 0;  /* 标记本趟是否发生过交换：0 表示没交换，1 表示交换过 */
		/* 内层循环进行相邻比较；末尾 i 个元素已经有序，不用再比 */
		for(j = 0;j < n - 1 - i;j++)
		{
			/* 前一个比后一个大就交换，让较大的数一步步“冒”到后面 */
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j];  /* 借助临时变量交换 arr[j] 和 arr[j+1] */
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				b = 1;  /* 本趟发生了交换 */
			}
		}
		/* 如果本趟一次交换都没有，说明数组已经有序，提前结束 */
		if(!b)
		{
			break;
		}
	}
}
int main()
{
	int arr[10]={1,8,3,10,5,6,2,8,9,7};  /* 待排序的数组 */
	int n = sizeof(arr) / sizeof(arr[0]);  /* 计算数组元素个数 */
	paixu(arr,n);  /* 调用排序函数，数组名 arr 会自动转成首元素地址 */
	/* 输出排序后的结果 */
	for(int i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");  /* 输出换行，让结果更整齐 */
	return 0;
} 
