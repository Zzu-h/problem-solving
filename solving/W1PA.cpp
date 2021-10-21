#include<iostream>
using namespace std;
#define maxNum 100
int T, K;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> str >> K;
		bool flag = true;
		int x = 0, y = 0;
		string ar[maxNum];
		for (size_t i = 0; i < str.size(); i++) {
			ar[y].push_back(str[i]);
			if (flag) {
				y++;
				if (y == K) {
					y--;
					flag = !flag;
				}
			}
			else {
				if (y == 0) {
					y++;
					flag = !flag;
				}
				y--;
			}

		}
		for (size_t i = 0; i < K; i++)
			cout << ar[i];
		cout << '\n';
	}
	return 0;
}