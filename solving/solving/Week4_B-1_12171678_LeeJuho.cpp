#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;
typedef pair<double, double> point;
#define x first
#define y second

point intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int px = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    int py = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
    int p = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    //cout << p << ' ' << px << ' ' << py << '\n';
    if (p == 0 && px == 0 && py == 0)
        return point({ INT_MAX, -1}); // 같은 직선
    else if(p == 0)
        return point({ INT_MAX, INT_MAX }); // 평행
    double x = px / p;
    double y = py / p;
    return point({ x,y });
}

bool compare(pair<point, bool>& a, pair<point, bool>& b) {
    point first = a.first, second = b.first;
    if (first.x == second.x) {
        return first.y > second.y;
    }
    return first.x > second.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    while (N--) {
        int x1, y1, x2, y2, x3, y3, x4, y4, ans = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point p = intersection(x1, y1, x2, y2, x3, y3, x4, y4);
        if (p.x == INT_MAX) {
            if (p.y == INT_MAX) {
                //평행
                ans = 1;
            }
            else {
                // 같은 직선 내에 있음
                pair<point, bool> ar[4] = { {{x1, y1},0}, {{x2, y2},0}, {{x3, y3},1}, {{x4, y4},1} };
                sort(ar, ar + 4, compare);
                bool flag = ar[0].second;
                if (ar[1].second == flag) {
                    if (ar[1].first.x == ar[2].first.x && ar[1].first.y == ar[2].first.y)
                        ans = 2;
                    else
                        ans = 1;
                }
                else {
                    flag = ar[1].second;
                    if (ar[1].first.x == ar[2].first.x && ar[1].first.y == ar[2].first.y)
                        ans = 2;
                    else
                        if (flag == ar[2].second)
                            ans = 4;
                        else
                            ans = 3;
                }
            }
        }
        else {
            // 두 직선 사이에 교점이 존재 교점 비교
            pair<point, bool> ar1[3] = { {{x1, y1},0}, {{x2, y2},0}, {{p.x, p.y },1} };
            pair<point, bool> ar2[3] = { {{x3, y3},0}, {{x4, y4},0}, {{p.x, p.y },1} };
            sort(ar1, ar1 + 3, compare);
            sort(ar2, ar2 + 3, compare);
            if (ar1[1].first.x == ar1[2].first.x && ar1[1].first.y == ar1[2].first.y && ar1[2].second)
                swap(ar1[1], ar1[2]);
            if (ar2[1].first.x == ar2[2].first.x && ar2[1].first.y == ar2[2].first.y && ar2[2].second)
                swap(ar2[1], ar2[2]);
            if(ar1[1].second && ar2[1].second)
                ans = 2;
            else
                ans = 1;
        }

        cout << ans << '\n';
    }
    return 0;
}