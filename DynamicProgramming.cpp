//������n������������Ϊ����������ɵ�����a1, a2, ��, an������������磺
//���Ӷκ͵����ֵ��������������Ϊ����ʱ����������Ӷκ�Ϊ0��
//�ֱ������ٷ������η�����̬�滮����ɡ�

#include "iostream"
#include "vector"
using namespace std;

//��ٷ�
int E_FindMaxSubSum(vector<int>& nums) {
	int maxSum = 0, curSum;
	for (int i = 0; i <	nums.size(); i++) {
		for (int j = i; j < nums.size(); j++) {
			curSum = 0;
			for (int k = i; k <= j; k++)
				curSum += nums[k];
			if (curSum > maxSum)
				maxSum = curSum;
		}
	}
	return maxSum;
}

//���η�
//����˼·�ǣ��Ƚ�����ֽ�Ϊ�����⣻�����������ٽ�������ϲ�����������⡣
//ʹ�÷��η��Ȿ���˼·�ǣ�
//�������Ϊ 2 ���֡�����[1, 2, 3, 4] ����Ϊ[1, 2] ��[3, 4]
//ͨ���ݹ���㣬�õ����������ֵ���������к��� lsum��rsum
//�������м俪ʼ�����߼�����������к� cross
//���� max(lsum, cross, rsum)
int CrossSum(vector<int>& nums, int left, int right, int mid) {
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

int MaxSubArray(vector<int>& nums, int left, int right) {
	if (left == right) {
		return nums[left];
	}

	int mid = left + (right - left) / 2;
	int lsum = MaxSubArray(nums, left, mid);
	int rsum = MaxSubArray(nums, mid + 1, right);
	int cross = CrossSum(nums, left, right, mid);

	return max(max(lsum, rsum), cross);
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
	return dp[sz-1];
}

//
//int main() {
//	vector<int> nums;
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < 2000; i++) {
//		nums.push_back(rand() % (41) - 10); //���� -10 �� 30 �������
//	}
//	for (int i : nums) {
//		cout << i << " ";
//	}
//	cout << endl << endl;
//	cout << "�������ͣ�" << endl;
//	clock_t Start, End;
//	Start = clock();
//	cout << "ö�ٷ���" << E_FindMaxSubSum(nums) << "		";
//	End = clock();
//	cout << "Run Time is:" << ((double)End - (double)Start)/ CLOCKS_PER_SEC << " s" << endl;
//	clock_t Start1, End1;
//	Start1 = clock();
//	cout << "���η���" << MaxSubArray(nums, 0, nums.size() - 1) << "		";
//	End1 = clock();
//	cout << "Run Time is:" << ((double)End1 - (double)Start1) / CLOCKS_PER_SEC << " s" << endl;
//	clock_t Start2, End2;
//	Start2 = clock();
//	cout << "��̬�滮��" << FindMaxSubSum(nums) << "		";
//	End2 = clock();
//	cout << "Run Time is:" << ((double)End2 - (double)Start2) / CLOCKS_PER_SEC << " s" << endl;
//	return 0;
//}