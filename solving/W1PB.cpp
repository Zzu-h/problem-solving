#include<iostream>
#include<stack>
using namespace std;
#define maxNum 100
int T, N, command, ins;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		stack<int> st, last;
		cin >> N;
		while (N--) {
			cin >> command;
			switch (command)
			{
			case 1:
				cin >> ins;
				if (st.empty() || last.empty()) {
					st.push(ins);
					last.push(ins);
				}
				else {
					st.push(max(ins, st.top()));
					last.push(min(ins, last.top()));
				}
				cout << last.top() << ' ' << st.top() << '\n';
				break;
			case 2:
				if (st.empty() || last.empty())
					break;
				st.pop();
				last.pop();
				break;
			default:
				break;
			}
		}
	}
	return 0;
}