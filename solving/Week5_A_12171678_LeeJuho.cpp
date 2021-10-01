#include <iostream>
#include <vector>
#define MAXNUM 5000
using namespace std;

int N, T, input;
vector<int> freq, dp[MAXNUM];

int idx;

bool check(int index) {
	bool flag = false, check_flag = false;
	size_t i, dpsize = dp[index].size();
	for (i = dpsize; i < T; ) {
		auto iter = freq.begin() + i;
		if (i + dpsize >= T) {
			check_flag = true;
			break;
		}
		flag = equal(iter, iter + dpsize, dp[index].begin());
		if (!flag) return flag;
		i += dpsize;
	}
	if(check_flag)
		for (int k = 0; i < T; i++,k++ ) {
			if (freq[i] == dp[index][k])
				flag = true;
			else {
				flag = false;
				return flag;
			}
		}
	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--) {
		cin >> T;
		for (size_t i = 0; i < T; i++) {
			cin >> input;
			freq.push_back(input);
		}

		for (size_t i = 0; i < T; i++) {
			dp[i].insert(dp[i].begin(), freq.begin(), freq.begin()+i+1);
			if (check(i)) {
				dp[i].push_back(freq.size() / dp[i].size());
			}
			else
				dp[i].push_back(0);
		}
		idx = 0;
		for (size_t i = 1; i < T; i++)
			if (dp[idx].back() < dp[i].back())
				idx = i;
		if(dp[idx].back() == 0)
			for (size_t k = 0; k < T; k++)
				cout << freq[k] << ' ';
		else
			for (size_t k = 0; k < dp[idx].size()-1; k++)
				cout << dp[idx][k] << ' ';
		cout << '\n';
		freq.clear();
		for (size_t k = 0; k < MAXNUM; k++)
			dp[k].clear();
	}

	return 0;
}