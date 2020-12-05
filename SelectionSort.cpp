#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void SelectSort(vector<int>& nums) {
	cout << "ÅÅÐòÖÐ: " << endl;
	int sz = nums.size();
	for (int i = 0; i < sz - 1; i++) {
		int MinIndex = i;
		for (int j = i + 1; j < sz; j++) {
			if (nums[j] < nums[MinIndex]) {
				MinIndex = j;
			}
		}
		swap(nums[i], nums[MinIndex]);
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
//		nums.push_back(rand() % 50);
//	}
//	cout << "ÅÅÐòÇ°: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	SelectSort(nums);
//	cout << "ÅÅÐòºó: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}