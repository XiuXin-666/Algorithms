#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void ShellSort(vector<int>& nums) {
	int sz = nums.size();
	//gap : ����  ÿ����������
	for (int gap = sz / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < sz; i++) {
			//�ڲ���ʵ���Ǽ򵥲�������ֻ�ǱȽϵ��Ǿ���gap������
			int key = nums[i];
			int p = i;
			//�ж�����ʱ��Ҫע���� p-gap ����0 ����������Խ�磬�жϳ���
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
//	cout << "����ǰ: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//  cout << "������: " << endl;
//	ShellSort(nums);
//	cout << "�����: " << endl;
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	return 0;
//}