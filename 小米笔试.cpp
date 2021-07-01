#include<iostream>
#include<functional>
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
int main3() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int num;
		cin >> num;
		vector<int> vec;
		for (int j = 0; j < num; ++j) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		int result = 0;
		int totalValue = accumulate(vec.begin(), vec.end(), 0);
		function<void(int, int, int)> dfs = [&](int index, int val1, int val2) {
			if (val1 == val2) {
				result = max(result, val1 + val2);
			}
			if (index == num || val1 > totalValue / 2 || val2 > totalValue / 2) {
				return;
			}
			dfs(index + 1, val1 + vec[index], val2);
			dfs(index + 1, val1, val2 + vec[index]);
			dfs(index + 1, val1, val2);
		};
		dfs(0, 0, 0);
		cout << totalValue - result << endl;
	}
	return 0;
}

/*
	最短回文串
*/
int main() {
	string str;
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; ++i) {
		string temp;
		temp = str;
		reverse(temp.begin(), temp.end());
		if (str == temp) break;
		str.insert(str.begin() + len, str[i]);
	}
	cout << str << endl;
	return 0;
}