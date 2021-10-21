#include<iostream>
#include<vector>
using namespace std;
#define maxNum 5000
int T, N, t;
vector<int> input;
vector<int> dp[maxNum];
void findFreq(int index) {
	int i, k, count = 0;
	bool flag = false;
	for (i = 0; i < input.size();) {
		if (equal(dp[index].begin(), dp[index].end(), input.begin() + i))
			count++;
		else {
			count = 0;
			dp[index].push_back(count);
			return;
		}
		i += dp[index].size();
		if (i+ dp[index].size() >= input.size()) {
			flag = true;
			break;
		}
	}
	if (flag) {
		for (k = 0; i < input.size(); i++,k++) {
			if (input[i] == dp[index][k])
				continue;
			else {
				count = -1;
				break;
			}
		}
		count++;
	}
	dp[index].push_back(count);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		input.clear();
		for (int i = 0; i < maxNum; i++) dp[i].clear();
		cin >> N;
		for (int i = 0; i < N; i++) { 
			cin >> t;
			input.push_back(t);
			dp[i].insert(dp[i].begin(), input.begin(), input.end());
		}
		int maxIdx = N-1;
		dp[maxIdx].push_back(1);
		for (int i = 0; i < N-1; i++) findFreq(i);
		for (int i = 0; i < N-1; i++)
			if (dp[maxIdx][maxIdx + 1] < dp[i][i + 1]) maxIdx = i;
		
		for (int k = 0; k <= maxIdx; k++)
			cout << dp[maxIdx][k] << ' ';
		cout << '\n';
	}

	return 0;
}