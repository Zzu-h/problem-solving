#include<iostream>
using namespace std;
#define maxNum 10000
int T, N, A, B, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> A >> B >> x >> y;
		if (A < B) swap(A, B);
		int g = A - B, ans;
		ans = (g - B % g) * x;
		if (B >= g) 
			ans = min(ans, (B % g)*y);
		cout << g << ' ' << ans << '\n';
	}

	return 0;
}