//#include<iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define endl '\n'
//#define maxNum  1000000
//
//int x[maxNum];
//pair<int, int> list[10000], list2[10000];
//vector<int> ans;
//int n, m = 0;
//
//class CircularQueue {
//private:
//    int queue[10000] = { 0, };
//    int front;
//    int rear;
//    int maxQueueSize;
//public:
//    CircularQueue(int);
//    void enQueue(int item);
//    void deQueue();
//    bool showCircularQueue();
//};
//CircularQueue::CircularQueue(int maxQueueSize)
//    :maxQueueSize(maxQueueSize)
//{
//	front = 0;
//	rear = 0;
//}
//void CircularQueue::enQueue(int item) {
//    queue[rear] = item;
//    rear = ++rear % maxQueueSize;
//}
//
//void CircularQueue::deQueue() {
//    queue[front] = 0;
//    front = ++front % maxQueueSize;
//}
//
//bool CircularQueue::showCircularQueue() {
//    bool flag = true;
//    for (size_t i = 0; i < m - 1; i++)
//        if (queue[(list2[i].second + front) % maxQueueSize] >= queue[(list2[i + 1].second + front) % maxQueueSize]) {
//            flag = false;
//            break;
//        }
//    return flag;
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin >> m >> n;
//    CircularQueue q(m);
//
//    for (size_t i = 0; i < m; i++) {
//        cin >> list[i].first;
//        list[i].second = i;
//    }
//    sort(list, list + m);
//    for (size_t i = 0; i < m; i++) {
//        list2[i].first = i;
//        list2[i].second = list[i].second;
//    }
//    //sort(list2, list2 + m);
//    for (size_t i = 0; i < n; i++)  cin >> x[i];
//    for (size_t i = 0; i < m; i++) q.enQueue(x[i]);
//    if(q.showCircularQueue()) ans.push_back(1);
//    for (size_t i = m; i < n; i++) {
//        q.deQueue();
//        q.enQueue(x[i]);
//        if (q.showCircularQueue()) ans.push_back(i-m+2);
//    }
//    if (ans.empty())
//        cout << 0;
//    else
//        for (size_t i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
//
//    cout << endl;
//    return 0;
//}
//#include <stdio.h>
//
//int matrix[501][2];
//int dp[501][501];
//int mat(int n);
//
//int min(int x, int y) {
//    return x < y ? x : y;
//}
//
//int main() {
//    int n, i, j;
//    scanf_s("%d", &n);
//    for (i = 0; i < n; i++) {
//        scanf_s("%d %d", &matrix[i][0], &matrix[i][1]);
//    }
//    int ans = mat(n);
//    printf("최소연산 횟수 : %d\n", ans);
//}
//
//int mat(int n) {
//    int a, b;
//    int i, j, k;
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n - i; j++) {
//            a = j;
//            b = j + i;
//            if (a == b) {
//                dp[a][b] = 0;
//            }
//            else {
//                dp[a][b] = 987654321;
//                for (k = a; k < b; k++) {
//                    dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
//                }
//            }
//        }
//    }
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++)
//            printf("%d ", dp[i][j]);
//        printf("\n");
//         
//    }
//    return dp[0][n - 1];
//}

#include<iostream>
using namespace std;
const int INF = 9;
int t = 10000000;
int d[INF][INF] = {
  { 0, 2, t, t, t, 7, 3, t, t},
  { 2, 0, 4, t, t, t, 6, t, t},
  { t, 4, 0, 2, t, t, t, 2, t },
  { t, t, 2, 0, 2, t, t, 8, t },
  { t, t, t, 2, 0, 6, t, t, 2 },
  { 7, t, t, t, 6, 0, t, t, 5 },
  { 3, 6, t, t, t, t, 0, 3, 1 },
  { t, t, 2, 8, t, t, 3, 0, 4 },
  { t, t, t, t, 2, 5, 1, 4, 0 },
};

void temp() {
    int a[INF][INF];
    for (int k = 0; k < INF; k++)  // k 는 거쳐가는 정점
        for (int i = 0; i < INF; i++)  // i 는 행 (출발 정점)
            a[k][i] = d[k][i];
    // 시간복잡도 V^3
    for (int k = 0; k < INF; k++) { // k 는 거쳐가는 정점
        for (int i = 0; i < INF; i++)  // i 는 행 (출발 정점)
            for (int j = 0; j < INF; j++)  // j 는 열 (도착 정점)
                if (a[i][k] + a[k][j] < a[i][j])  // 점화식 distance[i,j] = min(distance[i,j], distance[i,n] + distance[n,j])
                    a[i][j] = a[i][k] + a[k][j];
        if (k == 2);

    }
    for (int i = 0; i < INF; i++) {  // i 는 행 (출발 정점)
        for (int j = 0; j < INF; j++)  // j 는 열 (도착 정점)
            cout << (a[i][j] == t ? '\0' - 1 : a[i][j]) << ' ';
        cout << endl;
    }
}
int main() {
	temp();
    return 0;
}