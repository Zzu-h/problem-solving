#include <iostream>
using namespace std;
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int n, max = 0;
		cin >> n;
		int dp[1001], num[1001];

		for (int i = 1; i <= n; i++) {
			int tmpMax = 0;
			cin >> num[i];

			for (int j = 1; j < i; j++) {
				if (num[j] < num[i])
					if (dp[j] > tmpMax)
						tmpMax = dp[j];
			}
			dp[i] = tmpMax + 1;
			if (dp[i] > max)
				max = dp[i];
		}

		cout << max << '\n';
	}
	return 0;
}