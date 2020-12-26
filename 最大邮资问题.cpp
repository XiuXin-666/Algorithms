#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//假设某国家发行了n种不同面值的邮票，并且规定每张信封上最多只允许贴m张邮票。
//连续邮资问题要求对于给定的n和m，给出邮票面值的最佳设计，在1张信封上贴出从邮资1开始，
//增量为1的最大连续邮资区间。 
//例如当n = 5，m = 4时，面值为1，3，11，15，32的5种邮票可以贴出邮资的最大连续区间是1到70。


//对于连续邮资问题，用n元组x[1：n]表示n种不同的邮票面值，并约定它们从小到大排列。
//x[1] = 1是惟一的选择。在未确定剩余其它n－1种邮票面值的情况下，只用x[1]一种邮票面值，
//所能得到的最大连续邮资区间是[1：m]。接下来，确定x[2]的取值范围，很明显，
//x[2]的值最小可以取到2，因为x[1] 这时已经为1了。那么最大可以取的值呢？应当是m + 1，
//为什么？因为如果x[2]取m + 2，则在这个方案中，邮资m + 1不可能取得，
//（这个时候，x[2：n]的任何一个面值是不能取的，因为就算只取一张，总和也会至少为m + 2，
//超过m + 1了，反过来，如果只取x[1]面值，则就算把m张全取了，也只能凑到m）。所以，
//在搜索第2张邮票的时候，搜索范围是2 ~m + 2（m + 2不剪取）。在一般的情况下，已选定x[1：i - 1]，
//最大连续邮资区间是[1：r]时，接下来x[i]的可取值范围是[x[i - 1] + 1 ：r + 1]。由此可以看出，
//[x[i - 1] + 1 ：r + 1]（为限界函数）在用回溯法解连续邮资问题时，可用树表示其解空间，
//该解空间树中各结点的度随x的不同取值而变化。


//现在来看在x[1]，x[2]面值确定的情况下，用不超过m张邮票，所得到的最大连续邮资区间是多少？
//最大连续邮资区间总是以1作为起点的，所以我们用max来表示这个最大值，显然，max至少可以取到m，
//因为即使不用x[2]面值，只用x[1]面值的情况下，所能得到的最大值就已经是m了。现在来看在x[1]，
//x[2]面值确定的情况下，用不超过m张邮票，max + 1能不能取到？
//假设在拼凑的过程中，x[2]面值的邮票取t张，则t >= 0，t <= （max + 1） / x[2] && t <= m
//现在x[2]面值的邮票张数已经确定，原问题转化为另一个子问题，即，在x[1]面值确定的情况下，
//用不超过m－t张邮票，max + 1 - t * x[2] 能不能取到？ 。。。。。。
//到这一步就很容易理解了，因为x[1] 面值为1，所以如果要拼凑的值max + 1 - t * x[2] <= m - t的话，
//则只用取max + 1 - t * x[2]张就可以拉。相反，如果max + 1 - t * x[2] > m - t的话，则是不可以满足的。


class Envelope {
public:
	vector<int> findMaxContinuousInterval(vector<int>& nums, int n, int m) {
		sort(nums.begin(), nums.end());
		backTrack(nums, n, m);
		return Sum;
	}

	void backTrack(vector<int>& nums, int& n, int& m) {
		if (Postage == Sum.back() + 1) {
			Sum.push_back(Postage);
			return;
		}
		else {
			for (int i = 0; i < m; i++) {
				for (size_t i = 0; i < nums.size(); i++) {
					if (Postage != Sum.back() + 1) {
						continue;
					}
					Sum.push_back(nums[i]);
					backTrack(nums, n, m);
					Sum.pop_back();
				}
			}
		}
	}

private:
	vector<int> Sum = { 1 };  // 邮资的各种可能
	vector<int> Stamp = { 1 };//记录当前已经选定的邮票面值x[1:i]
								//能贴出各种邮资所需的最少邮票数
	vector<int> Best ;		  // 邮票面值的最优解
	int Postage = 0;		  //邮资
	int MaxPostage = 1;			 //记录当前已经找到的最大连续邮资区间
};

//int main() {
//	Envelope envelope;
//	int n, m;  // n种不同的票价，一张信封上只允许贴m张邮票
//	cin >> n >> m;
//	vector<int> nums(n,0); //  不同面值的票价
//	for (int i = 0; i < n; i++) {
//		cin >> nums[i];
//	}
//	vector<int> res;  //	邮资最大连续区间
//	res = envelope.findMaxContinuousInterval(nums, n, m);
//	for (auto i : res) {
//		cout << i << " ";
//	}
//	return 0;
//}