#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define endl '\n'
#define maxNum 10000
int T, A, B;
bool visited[maxNum];
int room[maxNum];
int getReverse(int num) {
    int temp = (num % 10)*1000; num /= 10;
    temp += (num % 10) * 100; num /= 10;
    temp += (num % 10) * 10; num /= 10;
    temp += (num % 10);
    return temp;
}
int bfs(int a, int b) {
    memset(visited, false, maxNum);
    memset(room, 0, maxNum);
    int count = 0;
    int child[3];
    queue<int> Q;
    Q.push(A);
    visited[A] = true;
    room[A] = 0;
    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        if (t == b) return room[b];
        child[0] = getReverse(t); child[1] = t - 1; child[2] = t + 1;
        for (int i = 0; i < 3; i++) {
            int getR = child[i];
            if (getR >= 0 && getR < maxNum) {
                if (!visited[getR]) {
                    room[getR] = room[t] + 1;
                    visited[getR] = true;
                    Q.push(getR);
                }
            }
        }
    }
    return room[b];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << bfs(A, B) << endl;
    }

    return 0;
}