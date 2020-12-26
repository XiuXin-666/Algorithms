#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int i;
	int hours;
	int sum;
};

//int main() {
//	int n;
//	cin >> n;
//	vector<Node> nums;
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		Node A;
//		A.i = i + 1;
//		A.hours = a;
//		A.sum = a * b;
//		nums.push_back(A);
//	}
//	sort(nums.begin(), nums.end(), [](Node a, Node b) {
//		if (a.sum == b.sum) {
//			return a.hours > b.hours;
//		}
//		if (a.sum == b.sum && a.hours == b.hours) {
//			return a.i < b.i;
//		}
//		return a.sum > b.sum;
//		});
//	for (int i = 0; i < n; i++) {
//		cout << nums[i].i << " ";
//	}
//	return 0;
//}