#include<iostream>
#include<vector>
#include<stdlib.h>
#include "time.h"
using namespace std;


void QuickSort(vector<int>& nums, int left, int right) {
	//��������
	if (left > right) {
		return;
	}
	//��������ָ�룬��������ֵҪ��������
	int i = left;
	int j = right;
	//�ο�����ֵ
	int CompNum = nums[left];
	while (i < j) {
		//������ָ��
		while (i < j && nums[j] > CompNum) {
			j--;
		}
		//������ָ��
		while (i < j && nums[i] <= CompNum) {
			i++;
		}
		//��������ָ������Ӧ����
		if (i < j) {
			swap(nums[i], nums[j]);
		}
	}
	//��󽫱Ƚϵ����������м�
	swap(nums[left], nums[j]);
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
	//�ݹ������벿��
	QuickSort(nums, left, i - 1);
	//�ݹ�����Ұ벿��
	QuickSort(nums, i + 1, right);

}


//int main() {
//	vector<int> nums;
//	for (int i = 0; i < 50; i++) {
//		nums.push_back(rand() % 1000);
//	}
//	cout << "����ǰ: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "������: " << endl;
//	QuickSort(nums,0,49);
//	cout << "�����: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout <<"run time is:" << (double)clock() / CLOCKS_PER_SEC << " s" << endl;
//	return 0;
//}