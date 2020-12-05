#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void BubbleSort(vector<int>& nums) {
	cout << "ÅÅÐòÖÐ£º" << endl;
	int sz = nums.size();
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - 1 - i; j++) {
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
		for (int i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}
}

//int main() {
//	vector<int> nums;
//	for (int i = 0; i < 10; i++) {
//		nums.push_back(rand() % 100);
//	}
//	cout << "ÅÅÐòÇ°: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	BubbleSort(nums);
//	cout << "ÅÅÐòºó: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}