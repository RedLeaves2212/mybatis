#include<stdio.h>
int w[7][7];
int count = 0;
int A[7];
int B[7];
#define MAX 9999
#define MVNum 100                       	//最大顶点数

int	A[MVNum], B[MVNum];
int w[][7] = {
	{0,	0,	 0,	  0,   0,   0,   0,},
	{0,	MAX, 6,   1,   5,   MAX, MAX},

	{0,	6,   MAX, 5,   MAX, 3,   MAX},

	{0,	1,   5,   MAX, 5,   6,   4},

	{0,	5,   MAX, 5,   MAX, MAX, 2},

	{0,	MAX, 3,   6,   MAX, MAX, 6},

	{0,	MAX, MAX, 4,   2,   6,  MAX}
};
int G( int w[][7]) {
	int minw[7];
	int minv[7];
	for (int i = 2; i <= 6; i++) {
		minw[i] = w[1][i];
		minv[i] = 1;
		count += 2;
	}
	for (int j = 1; j <= 5; j++) {
		int min = 1000;
		count++;
		for (int k = 2; k <= 6; k++) {
			if ((minw[k] > -1000) && (minw[k] < min)) {
				count += 2;
				min = minw[k];
				A[j] = minv[k];
				B[j] = k;
				count += 6;
			}
		}
		minw[B[j]] = -1000;
		count++;
		for (int t = 2; t <= 6; t++) {
			if (w[B[j]][t] < minw[t]) {
				count++;
				minw[t] = w[B[j]][t];
				minv[t] = B[j];
				count += 2;
			}
			printf("%d", count);
		}
		return 0;
	}
}
int main() {
	int minw[7];
	int minv[7];
	int V[7] = { 0,1,2,3,4,5,6 };
	G(w);
	for (int i = 1; i <= 5; i++) {
		printf("输出A[]为：%d\n",A[i]);
		printf("输出B[]的矩阵为：%d \n",B[i]);
	}
}