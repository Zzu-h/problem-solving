//#include <iostream>
//
//#include <algorithm>
//
//using namespace std;
//
//
//
//const int MAX = 100;
//
//int triangle[MAX][MAX];
//
//int n;
//
//int cache[MAX][MAX];
//
//
//
//int path(int y, int x)
//
//{
//
//	if (y == n - 1)
//
//		return triangle[y][x];
//
//	int& ret = cache[y][x];
//
//	if (ret != -1)
//
//		return ret;
//
//	return ret = min(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x]; // �κ� ����� �ִ�ġ�� ���Ѵ�.
//
//}
//
//void Init()
//
//{
//
//	for (int i = 0; i < n; ++i)
//
//		for (int j = 0; j <= i; ++j)
//
//			cache[i][j] = -1;
//
//}
//
//int main()
//
//{
//
//	int C;
//
//	cin >> C;
//
//	while (C--)
//
//	{
//
//		cin >> n;
//
//		Init();
//
//		for (int i = 0; i < n; ++i)
//
//			for (int j = 0; j <= i; ++j)
//
//			{
//
//				cin >> triangle[i][j];
//
//			}
//
//		int result = path(0, 0);
//
//		cout << result << endl;
//
//	}
//
//	return 0;
//
//}

#include <iostream>
#include <string.h>
using namespace std;
#define maxNum 200
typedef pair<int, int> p;
#define flow first
#define idx second
int  T, n, counting;
unsigned int point[maxNum][maxNum] = { 0, }, map[maxNum][maxNum] = { 0, };
bool visited[maxNum][maxNum] = { 0, };
void bfs() {
    map[1][0] = point[1][0];
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < i; k++) {
            p left = { i + 1, k }, right = { i + 1, k + 1 };
            if (!visited[left.flow][left.idx]) {
                map[left.flow][left.idx] = map[i][k] + point[left.flow][left.idx];
                visited[left.flow][left.idx] = true;
            }
            else map[left.flow][left.idx] = min(map[i][k] + point[left.flow][left.idx], map[left.flow][left.idx]);
            if (!visited[right.flow][right.idx]) {
                map[right.flow][right.idx] = map[i][k] + point[right.flow][right.idx];
                visited[right.flow][right.idx] = true;
            }
            else map[right.flow][right.idx] = min(map[i][k] + point[right.flow][right.idx], map[right.flow][right.idx]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        memset(point, 0, maxNum * maxNum);
        memset(map, 0, maxNum * maxNum);
        memset(visited, false, maxNum * maxNum);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < i; k++)
                cin >> point[i][k];
        }
        bfs();
        unsigned int mins = map[n][0];
        for (int i = 1; i < n; i++)
            mins = min(mins, map[n][i]);
        cout << mins << '\n';
    }
    return 0;
}