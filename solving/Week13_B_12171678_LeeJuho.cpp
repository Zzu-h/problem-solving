#include<iostream>
#include<set>
#include <string.h>
using namespace std;
#define endl '\n'
#define maxNum  500001

int list[maxNum], ans[maxNum];
set<int> flag;
int f, n, m, q = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> q;
    while (q--) {
        memset(list, 0, maxNum); memset(ans, 0, maxNum);
        flag.clear();

        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> list[i];
        for (int i = m - 1; i >= 0; i--) {
            if (flag.find(list[i]) == flag.end()) flag.insert(list[i]);
            ans[i] = flag.size();
        }
        for (size_t i = 0; i < m; i++) cout << n - ans[i] << endl;
    }
}