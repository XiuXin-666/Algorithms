//给定由n个整数（可能为负整数）组成的序列a1, a2, …, an，求该序列形如：
//的子段和的最大值。当所有整数均为负数时定义其最大子段和为0。
//分别采用穷举法、分治法、动态规划法完成。

#include "iostream"
#include "vector"
using namespace std;

//穷举法
//分治法的做题思路是：先将问题分解为子问题；解决子问题后，再将子问题合并，解决主问题。
//
//使用分治法解本题的思路是：
//
//将数组分为 2 部分。例如[1, 2, 3, 4] 被分为[1, 2] 和[3, 4]
//通过递归计算，得到左右两部分的最大子序列和是 lsum，rsum
//从数组中间开始向两边计算最大子序列和 cross
//返回 max(lsum, cross, rsum)
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
	


//动态规划
int FindMaxSubSum(vector<int>& nums) {
	int sz = nums.size();
	vector<int> dp(sz, 0);
	//base case
	dp[0] = nums[0];
	int res = dp[0];
	//进行状态转移
	for (int i = 1; i < sz; i++) {
		//状态转移方程
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		res = max(res, dp[i]);
	}
	return res;
}


int main() {
	vector<int> nums;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++) {
		nums.push_back(rand() % (41) - 10); //生成 -10 到 30 的随机数
	}
	for (int i : nums) {
		cout << i << " ";
	}
	cout << "最大子序和："<< endl;
	cout << "分治法：" << MaxSubArray(nums, 0, nums.size() - 1) << endl;
	cout << "动态规划：" << FindMaxSubSum(nums) << endl;



	return 0;
}