#include<iostream>
#include<vector>
#include<stdlib.h>
#include "time.h"
using namespace std;


void HeapSort(vector<int>& nums, int left, int right) {






	for (int i : nums)
	{
		cout << i << " ";
	}

}


//int main() {
//	vector<int> nums;
//	for (int i = 0; i < 100; i++) {
//		nums.push_back(rand() % 100);
//	}
//	cout << "����ǰ: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "������: " << endl;
//	HeapSort(nums, 0, 99);
//	cout << "�����: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "Run Time is:" << (double)clock() / CLOCKS_PER_SEC << " s" << endl;
//	return 0;
//}