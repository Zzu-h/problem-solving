#include<iostream>
#include<queue>
using namespace std;
#define maxNum 10000
#define  x first 
#define y second
int T, N, i, b;
struct comp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.x+a.y < b.x+b.y;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> list;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		int inha = 0, biryong = 0;
		bool flag = true;
		while(N--) {
			cin >> i >> b;
			list.push({ i, b });
		}
		while (!list.empty()) {
			if (flag)
				inha += list.top().x;
			else
				biryong += list.top().y;
			list.pop();
			flag = !flag;
		}
		cout << inha - biryong << '\n';
	}
	return 0;
}