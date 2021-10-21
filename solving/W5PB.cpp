#include<iostream>
#include<vector>
using namespace std;
#define maxNum 1000000
int M, N;
int house[maxNum];
bool check(int mid) {
	int cnt = 1;
	int n = 0;

	for (int i = 1; i < N; i++) {
		if (house[i] >= house[n] + mid) {
			cnt++;
			n = i;
		}
	}
	return cnt >= M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N>>M;
	for (size_t i = 0; i < N; i++)
		cin >> house[i];
	int l, r, mid,ans;
	l = 1;
	r = house[N - 1];
	while (l <= r) {
		mid = (l + r) / 2;
		//cout << l << ' ' << mid << ' ' << r << '\n';
		if (check(mid)) {
			// 사람 더 들어올 수 있음
			l = mid + 1;
			ans = mid;
		}
		else
			// 사람 더 못 들어옴
			r = mid-1;
	}
	cout << ans << '\n';
	return 0;
}