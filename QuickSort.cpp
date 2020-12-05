#include<iostream>
#include<vector>
#include<stdlib.h>
#include "time.h"
using namespace std;


void QuickSort(vector<int>& nums, int left, int right) {
	//结束条件
	if (left > right) {
		return;
	}
	//创建两个指针，并将参数值要保存下来
	int i = left;
	int j = right;
	//参考的数值
	int CompNum = nums[left];
	while (i < j) {
		//左移右指针
		while (i < j && nums[j] > CompNum) {
			j--;
		}
		//右移左指针
		while (i < j && nums[i] <= CompNum) {
			i++;
		}
		//交换两个指针所对应的数
		if (i < j) {
			swap(nums[i], nums[j]);
		}
	}
	//最后将比较的数放置在中间
	swap(nums[left], nums[j]);
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
	//递归快排左半部分
	QuickSort(nums, left, i - 1);
	//递归快排右半部分
	QuickSort(nums, i + 1, right);

}


//int main() {
//	vector<int> nums;
//	for (int i = 0; i < 50; i++) {
//		nums.push_back(rand() % 1000);
//	}
//	cout << "排序前: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "排序中: " << endl;
//	QuickSort(nums,0,49);
//	cout << "排序后: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout <<"run time is:" << (double)clock() / CLOCKS_PER_SEC << " s" << endl;
//	return 0;
//}