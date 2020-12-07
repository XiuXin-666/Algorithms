#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void Merge(vector<int>& A, vector<int>& B, vector<int>& nums) {  //将两个子序列合并
	int i = 0, j = 0;  //两个指针分别指向 A,B 两个数组
	while ((i < A.size()) && (j < B.size())) { // 这个是保证两个表是都是非空
		if (A[i] < B[j]) {
			nums.push_back(A[i++]);
		}
		else {
			nums.push_back(B[j++]);
		}
	}
	while (i < A.size()) {  // B数组已经空了,那么我们将A表的值直接送入到nums中
		nums.push_back(A[i++]);
	}
	while (j < B.size()) {  // A数组已经空了,将B表的数据直接送入到nums中
		nums.push_back(B[j++]);
	}
}

void MergeSort(vector<int>& nums) {  //(函数主体)  递归实现 
	int sz = nums.size();
	vector<int> A;
	vector<int> B;
	if (sz <= 1)
		return;

	for (int i = 0; i < sz; ++i) {
		if (i < (sz >> 1)) {  // sz >> 1 : 右移1位，相当于除以2
			A.push_back(nums[i]);
		}
		else {
			B.push_back(nums[i]);
		}
	}
	MergeSort(A);
	MergeSort(B);
	nums.clear();
	Merge(A, B, nums);

	//for (int i : nums) {
	//	cout << i << " ";
	//}
	//cout << endl;
}

//void MergeSort(vector<int>& nums) { // (函数主体)  迭代实现
//
//
//
//
//
//}

//
//int main() {
//	vector<int> nums;
//	for (int i = 0; i < 50; i++) {
//		nums.push_back(rand() % 100);
//	}
//	cout << "排序前: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "排序中: " << endl;
//	MergeSort(nums);
//	cout << "排序后: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}