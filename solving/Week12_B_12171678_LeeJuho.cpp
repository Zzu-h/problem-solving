#include <iostream>
#include <string.h>
using namespace std;
#define maxNum 500001
#define INT_MAX 2147483647
int  T, n, counting;
int point[maxNum] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        memset(point, 0, maxNum);
        cin >> n;
        int a, b, counter = 0, minD = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            point[a] = (point[a] == 0 ? b : min(point[a], b));
        }
        for (int i = maxNum-1; i > 0; i--) {
            if (point[i] == 0) continue;
            if (point[i] < minD) {
                counter++;
                minD = point[i];
            }
        }
        cout << counter << '\n';
    }
    return 0;
}