#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;


/*
	汽水问题
*/
void main1() {
	int tmp;
	while (cin >> tmp) {
		cout << tmp / 2 << endl;
	}
}


/*
	明明的随机数
*/

int main2(void) {
	vector<set<int>> setVec;
	set<int> checSet;
	int count = 0;
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			checSet.insert(tmp);
		}
		setVec.push_back(checSet);
		checSet.clear();
	}
	for (const auto& ele : setVec) {
		for (const auto& elem : ele) {
			cout << elem << endl;
		}
	}
	return 0;
}
/*
	十六进制转十进制
*/
int main3() {
	int num;
	while (cin >> hex >> num) {
		cout << num << endl;
	}
	return 0;
}


/*
	删数
*/
int main4() {
	int n;
	while (cin >> n) {
		queue<int> que;
		for (int i = 0; i < n; ++i) {
			que.push(i);
		}
		int count = 0;
		while (que.size() != 1) {
			if (count != 2) {
				int b = que.front();
				que.pop();
				que.push(b);
				count++;
			}
			else{
				que.pop();
				count = 0;
			}
		}
		cout << que.front() << endl;
	}
	return 0;
}

/*
	字符集合
	abcqweracb
*/
int main5() {
	set<char> chSet;
	string str;
	while (cin >> str) {
		int len = str.size();
		string ret = "";
		for (const auto& ele : str) {
			if (chSet.find((ele)) != chSet.end()) {
				continue;
			}
			chSet.insert((ele));
			ret += ele;
		}
		cout << ret << endl;
		ret.clear();
		chSet.clear();
	}
	return 0;
}
