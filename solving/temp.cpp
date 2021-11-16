#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
#define size 24
#define endl '\n'
typedef pair<string, string> p;
int n;
string cmd;
string str;
p list[size];
bool comp(p& a, p& b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	n = size;
	for(int i = 0;i<size;i++) {
		getline(cin, cmd);
		getline(cin, str);
		list[i].first = cmd;
		list[i].second = str;
		getline(cin, str);
	}
	cout << endl << endl;
	sort(list, list + size, comp);
	for (int i = 0; i < size; i++) {
		cout << list[i].first << "\n" << list[i].second;
		cout << endl<<endl;
	}
	return 0;
}