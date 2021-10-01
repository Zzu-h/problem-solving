// boj 공유기 설치
#include<iostream>
#include<algorithm>
#define MAXNUM 1000000
using namespace std;

int n, c, a[MAXNUM];

bool possible(int dist) {
    int prev = a[0], cnt = c - 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] - prev >= dist) {
            prev = a[i];
            --cnt;
            if (cnt == 0)return true;
        }
    }
    return cnt == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; ++i)cin >> a[i];
    sort(a, a + n);

    int l = 1, r = a[n - 1];
    while (l <= r) {
        int mid = (l + r) / 2;

        if (possible(mid))
            l = mid + 1;
        else r = mid - 1;
    }

    cout << r;
}