#include<iostream>
#include<queue>
#define time first
#define price second
#define maxNum 20000
using namespace std;
typedef  pair<int, int> pairs;
int M, N, t, p;
int arr[maxNum];
struct comp {
	bool operator()(pair<pairs, int>& a, pair<pairs, int>&b) {
		if (a.first.time == b.first.time)
			return a.second > b.second;
		return a.first.time > b.first.time;
	}
};
priority_queue<pair<pairs, int>,vector<pair<pairs, int>>, comp>counters;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int index = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) counters.push({ { 0,0 } ,i });
	for (size_t i = 0; i < M; i++) {
		cin >> t >> p;
		pairs temp = { counters.top().first.time + t, counters.top().first.price+ p };
		index = counters.top().second;
		counters.pop();
		counters.push({ temp, index });
	}
	while(!counters.empty()){
		arr[counters.top().second] = counters.top().first.price;
		if(counters.size() == 1)
			cout << counters.top().first.time << '\n';
		counters.pop();
	}
	for (size_t i = 0; i < N; i++) 
		cout << arr[i] << '\n';
	
	return 0;
}