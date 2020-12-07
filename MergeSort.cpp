#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void Merge(vector<int>& A, vector<int>& B, vector<int>& nums) {  //�����������кϲ�
	int i = 0, j = 0;  //����ָ��ֱ�ָ�� A,B ��������
	while ((i < A.size()) && (j < B.size())) { // ����Ǳ�֤�������Ƕ��Ƿǿ�
		if (A[i] < B[j]) {
			nums.push_back(A[i++]);
		}
		else {
			nums.push_back(B[j++]);
		}
	}
	while (i < A.size()) {  // B�����Ѿ�����,��ô���ǽ�A���ֱֵ�����뵽nums��
		nums.push_back(A[i++]);
	}
	while (j < B.size()) {  // A�����Ѿ�����,��B�������ֱ�����뵽nums��
		nums.push_back(B[j++]);
	}
}

void MergeSort(vector<int>& nums) {  //(��������)  �ݹ�ʵ�� 
	int sz = nums.size();
	vector<int> A;
	vector<int> B;
	if (sz <= 1)
		return;

	for (int i = 0; i < sz; ++i) {
		if (i < (sz >> 1)) {  // sz >> 1 : ����1λ���൱�ڳ���2
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

//void MergeSort(vector<int>& nums) { // (��������)  ����ʵ��
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
//	cout << "����ǰ: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//	cout << "������: " << endl;
//	MergeSort(nums);
//	cout << "�����: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}