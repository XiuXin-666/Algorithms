#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void InsertionSort(vector<int>& nums) {
	cout << "ÅÅÐòÖÐ: " << endl;
	int sz = nums.size();
	for (int j = 1; j < sz; j++) {
		int key = nums[j];
		int p = j;
		while (p - 1 >= 0 && key < nums[p - 1]) {
			nums[p] = nums[p - 1];
			p--;
		}
		nums[p] = key;
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
//		nums.push_back(rand() % 80);
//	}
//	cout << "ÅÅÐòÇ°: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	InsertionSort(nums);
//	cout << "ÅÅÐòºó: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}