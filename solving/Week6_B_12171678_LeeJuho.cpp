#include <iostream>
#include <string.h>
#include <queue>
#define MAXNUM 1000
using namespace std;

bool map[MAXNUM][MAXNUM] = { 1 };
int chk[MAXNUM][MAXNUM] = { 0, };
bool visited[MAXNUM][MAXNUM] = { 1 };
int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0,  1, -1, 1, -1 };
int T, N, ax, ay, bx, by, cx, cy, cdx, cdy;

void init();
int bfs(int x, int y) {
    bool flag = false;
    queue<pair<int, int>> que;
    que.push(pair<int, int>(x, y));

    chk[y][x] = 0;
    visited[y][x] = true;
    while (!que.empty()) {
        int ccx = que.front().first;
        int ccy = que.front().second;
        que.pop();

        if (ccx == bx && ccy == by) 
            flag = true;
        

        for (int i = 0; i < 8; i++) {
            int nx = ccx + dx[i];
            int ny = ccy + dy[i];

            if (map[ny][nx] == 1) {
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (!visited[ny][nx]) {
                        chk[ny][nx] = chk[ccy][ccx] + 1;
                        visited[ny][nx] = true;
                        que.push(pair<int, int>(nx, ny));
                    }
                    else {
                        chk[ny][nx] = min(chk[ny][nx], chk[ccy][ccx] + 1);
                    }
                }
            }
        }
    }
    if (flag)
        return chk[by][bx];
    else
        return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		cin >> ax >> ay >> bx >> by;
		cin >> cx >> cy >> cdx >> cdy;
        ax--; ay--; bx--; by--; cx--; cy--; cdx--; cdy--;
        init();
        int ans = bfs(ax, ay);
        ans = (ans == -1) ? 0 : ans;
        cout << ans<< '\n';
	}
	// bfs 문제고, 인하가 갈 수 있는 모든 방향 탐색
	return 0;
}
void init() {
    /* Initialization */
    memset(map, true, MAXNUM * MAXNUM);
    memset(visited, false, MAXNUM * MAXNUM);
    memset(chk, 0, MAXNUM * MAXNUM);
    for (int x = cdx; x >= 0; x--) {
        if (x == cx && cdy == cy)  break;
        map[cdy][x] = 0;
    }
    for (int x = cdx; x < N; x++) {
        if (x == cx && cdy == cy)  break;
        map[cdy][x] = 0;
    }
    for (int y = cdy; y >= 0; y--) {
        if (cdx == cx && y == cy)  break;
        map[y][cdx] = 0;
    }
    for (int y = cdy; y < N; y++) {
        if (cdx == cx && y == cy)  break;
        map[y][cdx] = 0;
    }

    for (int x = cdx, y = cdy; x >= 0 && y >= 0; x--, y--) {
        if (x == cx && y == cy)  break;
        map[y][x] = 0;
    }
    for (int x = cdx, y = cdy; x < N && y < N; x++, y++) {
        if (x == cx && y == cy)  break;
        map[y][x] = 0;
    }
    for (int x = cdx, y = cdy; x < N && y >= 0; x++, y--) {
        if (x == cx && y == cy)  break;
        map[y][x] = 0;
    }
    for (int x = cdx, y = cdy; x >= 0 && y < N; x--, y++) {
        if (x == cx && y == cy)  break;
        map[y][x] = 0;
    }
    for (int x = cdx, y = cdy; x >= 0 && y >= 0; x--, y--) {
        if (x == cx && y == cy)  break;
        map[y][x] = 0;
    }

    for (int x = cx - 1, count = 0; x < N && count < 3; x++, count++) {
        if (x < 0) continue;
        if ((cy - 1) > 0) map[cy - 1][x] = 0;
        if ((cy + 1) < N) map[cy + 1][x] = 0;
    }
    if (cx != 0) {
        map[cy][cx - 1] = 0;
    }
    if (cx != N - 1)
        map[cy][cx + 1] = 0;
    map[cy][cx] = 0;
}