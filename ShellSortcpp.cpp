#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void ShellSort(vector<int>& nums) {
	int sz = nums.size();
	//gap : 增量  每次排序后减半
	for (int gap = sz / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < sz; i++) {
			//内部其实还是简单插入排序，只是比较的是距离gap的数字
			int key = nums[i];
			int p = i;
			//判断条件时，要注意是 p-gap 大于0 ，否则数组越界，判断出错
			while (p - gap > 0 && key < nums[p - gap]) {
				nums[p] = nums[p - gap];
				p -= gap;
			}
			nums[p] = key;
		}
		for (int i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}
}
//
//int main() {
//	vector<int> nums;
//	for (int i = 0; i < 10; i++) {
//		nums.push_back(rand() % 200);
//	}
//	cout << "排序前: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//  cout << "排序中: " << endl;
//	ShellSort(nums);
//	cout << "排序后: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}