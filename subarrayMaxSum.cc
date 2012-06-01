#include <iostream>

int maxSubarraySum(int arr[], int length, int& beg, int& end)
{
	assert(arr!=0);
	int maxSum = 0;
	int tmpSum = 0;
	beg = 0; end = 0;
	for (int i = 0; i < length; i++) {
		tmpSum += arr[i];
		if (tmpSum < 0) {	// discard it
			tmpSum = 0;
			beg = end = i+1;
		} 
		if (tmpSum > maxSum) {
			maxSum = tmpSum;
			end = i+1;
		}
	}
	if (maxSum ==0 ) {		// if all numbers are negative, return max value
		maxSum = arr[0];
		for (int i = 1; i < length; i++) 	
			if (maxSum < arr[i]) {
				maxSum = arr[i];
				beg = i; end = i+1;
			}
	}
	return maxSum;
}

int main()
{
	int arr[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int beg = 0, end = 0;
	std::cout << "max sum = " << maxSubarraySum(arr, 8, beg, end) << std::endl;
	std::cout << "its subarray is :\n";
	for (int i = beg; i < end; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	return 0;
}

