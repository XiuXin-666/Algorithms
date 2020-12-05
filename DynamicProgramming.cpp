//������n������������Ϊ����������ɵ�����a1, a2, ��, an������������磺
//���Ӷκ͵����ֵ��������������Ϊ����ʱ����������Ӷκ�Ϊ0��
//�ֱ������ٷ������η�����̬�滮����ɡ�

#include "iostream"
#include "vector"
using namespace std;

//��ٷ�
//���η�������˼·�ǣ��Ƚ�����ֽ�Ϊ�����⣻�����������ٽ�������ϲ�����������⡣
//
//ʹ�÷��η��Ȿ���˼·�ǣ�
//
//�������Ϊ 2 ���֡�����[1, 2, 3, 4] ����Ϊ[1, 2] ��[3, 4]
//ͨ���ݹ���㣬�õ����������ֵ���������к��� lsum��rsum
//�������м俪ʼ�����߼�����������к� cross
//���� max(lsum, cross, rsum)
int CrossSum(vector<int>& nums,int left,int right,int mid) {
	if (left == right) {
		return nums[left];
	}

	int leftMaxSum = INT_MIN;
	int leftSum = 0;
	for (int i = mid; i >= left; --i) {
		leftSum += nums[i];
		leftMaxSum = max(leftMaxSum, leftSum);
	}

	int rightMaxSum = INT_MIN;
	int rightSum = 0;
	for (int i = mid + 1; i <= right; ++i) {
		rightSum += nums[i];
		rightMaxSum = max(rightMaxSum, rightSum);
	}

	return leftMaxSum + rightMaxSum;
}

int Max(int a, int b, int c) {
	if (a > b) {
		b = a;
	}
	if (b > c) {
		c = b;
	}
	return c;
}

int MaxSubArray(vector<int>& nums,int left,int right) {
	if (left == right) {
		return nums[left];
	}

	int mid = (left + right) >> 2;
	int lsum = MaxSubArray(nums, left, mid);
	int rsum = MaxSubArray(nums, mid + 1, right);
	int cross = CrossSum(nums, left, right, mid);

	return Max(lsum, rsum, cross);
}
	


//��̬�滮
int FindMaxSubSum(vector<int>& nums) {
	int sz = nums.size();
	vector<int> dp(sz, 0);
	//base case
	dp[0] = nums[0];
	int res = dp[0];
	//����״̬ת��
	for (int i = 1; i < sz; i++) {
		//״̬ת�Ʒ���
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		res = max(res, dp[i]);
	}
	return res;
}


int main() {
	vector<int> nums;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++) {
		nums.push_back(rand() % (41) - 10); //���� -10 �� 30 �������
	}
	for (int i : nums) {
		cout << i << " ";
	}
	cout << "�������ͣ�"<< endl;
	cout << "���η���" << MaxSubArray(nums, 0, nums.size() - 1) << endl;
	cout << "��̬�滮��" << FindMaxSubSum(nums) << endl;



	return 0;
}