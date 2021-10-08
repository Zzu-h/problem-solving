#include <iostream>
#include <queue>
#define MAXNUM 100000
using namespace std;
struct comp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};
int N, M, maxIdx = 0, minIdx = 0,k;
pair<int, int> guest[MAXNUM] = { {0,0,} }, chkctr[MAXNUM] = { {0,0,} };
priority_queue<pair<int, int>, vector<pair<int,int>>, comp> findmin;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
		cin >> guest[i].first >> guest[i].second;
	for (k = 0; k < N; k++) {
		if (k >= M)
			break;
		findmin.push({ k, guest[k].first });
		chkctr[k].first = guest[k].first;
		chkctr[k].second = guest[k].second;
	}
	for (int i = k; i < M; i++) {
		minIdx = findmin.top().first;
		chkctr[minIdx].first += guest[i].first;
		chkctr[minIdx].second += guest[i].second;
		// first : time / second : price
		findmin.pop();
		findmin.push({ minIdx,chkctr[minIdx].first });
	}
	for (int i = 0; i < N; i++)
		if (chkctr[maxIdx].first < chkctr[i].first)
			maxIdx = i;
	cout << chkctr[maxIdx].first << '\n';
	for (int i = 0; i < N; i++)
		cout << chkctr[i].second << '\n';
	return 0;
}