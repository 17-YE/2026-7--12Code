//P03 数字黑洞 6174
#include <stdio.h>

int main() {
    int n;
    int i;
    int j;
    // 循环读取直到文件末尾 (EOF)
    while (scanf("%d", &n) != EOF) {
        // 如果初始就是 6174，直接输出 0
        if (n == 6174) {
            printf("0\n");
            continue;
        }
        
        int steps = 0;
        while (n != 6174) {
            // 提取四位数字，不足四位时高位自动补0（因为整数除法截断）
            int d[4];
            d[0] = n / 1000;          // 千位
            d[1] = (n / 100) % 10;    // 百位
            d[2] = (n / 10) % 10;     // 十位
            d[3] = n % 10;            // 个位
            
            // 对4个数字进行降序排序（这里用简单的冒泡排序）
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3 - i; j++) {
                    if (d[j] < d[j+1]) {
                        int temp = d[j];
                        d[j] = d[j+1];
                        d[j+1] = temp;
                    }
                }
            }
            // 排序后 d 数组为降序排列：d[0]最大，d[3]最小
            
            // 组合成最大数 a 和 最小数 b
            int a = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
            int b = d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
            
            // 计算差值作为下一轮的数
            n = a - b;
            steps++;
        }
        
        // 输出操作次数
        printf("%d\n", steps);
    }
    
    return 0;
}
