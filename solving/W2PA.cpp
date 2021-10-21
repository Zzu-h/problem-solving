#include<iostream>
#include<queue>
using namespace std;
#define friendCount 20
#define maxWord 2000
int T, N, M, ins;

string temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		int ans = 0;
		queue<string> friends[friendCount], str;
		cin >> N >> M;
		for (size_t i = 0; i < M; i++){
			cin >> temp;
			str.push(temp);
		}
		for (size_t i = 0; i < N; i++) {
			cin >> ins;
			while (ins--) {
				cin >> temp;
				friends[i].push(temp);
			}
		}
		while(!str.empty()) {
			bool flag = true;
			for (size_t i = 0; i < N; i++) {
				if (friends[i].empty()) continue;
				if (friends[i].front() == str.front()) {
					friends[i].pop(); str.pop();
					flag = false;
					break;
				}
			}
			if (flag) break;
		}
		if (str.empty()) ans = 1;
		cout << ans << '\n';
	}
	return 0;
}