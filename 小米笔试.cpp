#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

/*
	密码生成
*/
int main1() {
	int N, M;
	cin >> N >> M;
	vector<int> vec;
	for (int i = 0; i < N; ++i) {
		vec.push_back(0);
	}
	for (int i = 0; i < M; ++i) {
		int left, right;
		cin >> left >> right;
		for (int j = left; j <= right; ++j) {
			vec[j] = i + 1;
		}
	}
	long ret = 0;
	for (int i = 0; i < M; ++i) {
		ret += (vec[i] * i);
	}
	cout << ret % 100000009 << endl;
	return 0;

}

/*
	字符串的有效性
*/
int main2() {
	string str;
	cin >> str;
	stack<char> stk;
	for (const auto& ele : str) {
		if (ele == '(') {
			stk.push(ele);
		}
		else if (ele == ')' && !stk.empty()) {
			stk.pop();
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	cout << "YES" << endl;
	return 0;
}

/*
	平分物品
*/

void check(vector<int>& vec) {
	sort(vec.begin(), vec.end(), [](const auto& num1, const auto& num2) {return num1 > num2; });
	int len = vec.size();
	int AValue, BValue;
	AValue = vec[0]; BValue = 0;
	while (1) {
		for (int i = 1; i < len; ++i) {
			if (accumulate(vec.begin() + i, vec.end(), BValue) > AValue) {

			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	vector<int> vec;
	for (int i = 0; i < T; ++i) {
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		check(vec);
		return 0;
	}
	return 0;
}