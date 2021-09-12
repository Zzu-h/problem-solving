#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;
queue<string> sentence;
vector<queue<string>> friends;

void init() {
	while(!sentence.empty())
		sentence.pop();
	friends.clear();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		init();
		int N, M, k;
		bool flag = true;
		cin >> N >> M;

		while (M--) {
			string str;
			cin >> str;
			sentence.push(str);
		}

		while (N--) {
			queue<string> f;
			cin >> k;
			while (k--) {
				string str;
				cin >> str;
				f.push(str);
			}
			friends.push_back(f);
		}
		while (!sentence.empty()) {
			for (int i = 0; i < friends.size(); i++) {
				if (friends[i].front() == sentence.front()) {
					flag = true;
					friends[i].pop();
					sentence.pop();
					break;
				}
				else flag = false;
			}
			if (!flag)
				break;
		}
		cout  << flag << '\n';
	}
	return 0;
}