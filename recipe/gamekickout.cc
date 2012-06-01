#include <iostream>
#define N 7
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int* order, int n)
{
	for (int i = 0; i<n; i++)
		std::cout << order[i] << " ";
	std::cout << "\n";
}
	
void eval(int w[][N], int *order, int* result, int n)
{
	int i, j, m =n;
	for (i = 1; i < n; i*=2) {
		std::cout << "round " << i << std::endl;
		for (j = 0; j+i< n; j+= 2*i) {			
			if (w[order[j]][order[j+i]] == order[j+i])
				swap(&order[j+i], &order[j]);
			result[--m] = order[j+i];			
			print(order, n);
		}
		
	}
	result[0] = order[0];
}

int main()
{
	int w[N][N] = {
		0, 1, 2, 3, 0, 0, 6,
		1, 1, 2, 1, 1, 1, 6,
		2, 2, 2, 2, 2, 2, 6,
		3, 1, 2, 3, 3, 3, 6,
		0, 1, 2, 3, 4, 5, 6,
		0, 1, 2, 3, 4, 5, 6,
		6, 6, 6, 6, 6, 6, 6
	};
	int order[N] = { 1, 3, 4, 2, 0, 5, 6};
	int result[N] = {-1};
	eval(w, order, result, N);
	std::cout << "final No.1 is " << result[0] << std::endl;
	return 0;
} 
