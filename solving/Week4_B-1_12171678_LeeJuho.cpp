#include <iostream>
#define INT_MAX 2147483647
using namespace std;
typedef pair<int, int> point;
#define x first
#define y second
class Line {
public:
    int x1, y1, x2, y2;
    Line(int x1, int  y1, int  x2, int  y2) {
        this->x1 = y1 > y2 ? x1 : x2;
        this->x2 = y1 < y2 ? x1 : x2;
        this->y1 = y1 > y2 ? y1 : y2;
        this->y2 = y1 < y2 ? y1 : y2;
    }
};
int gcd(int a, int b) {
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
point intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int px = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    int py = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
    int p = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (p == 0) 
        return point({ INT_MAX,INT_MAX });
    int x = px / p;
    int y = py / p;
    return point({ x,y });
}

bool vectorCheck(int x1, int y1, int x2, int y2, int x3, int y3) {
    // 벡터 크기와 방향이 같다면 n의 값에 따라 다륾
    int vx1 = (x1 - x2), vx2 = (x1 - x3), vy1 = (y1 - y2), vy2 = (y1 - y3);
    int GCD1 = gcd(abs(x1), abs(y1)) , GCD2 = gcd(abs(x2), abs(y2));
    vx1 = x1 / GCD1; vy1 = y1 / GCD1;
    vx2 = x2 / GCD2; vy2 = y2 / GCD2;
    if (vx1 == vx2 && vy1 == vy2)
        return true;
    return false;
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
        Line l1(x1, y1, x2, y2), l2(x3, y3, x4, y4);
        point p = intersection(x1, y1, x2, y2, x3, y3, x4, y4);
        if (p.x == INT_MAX && p.y == INT_MAX) {
            // 평행
            if (vectorCheck(x1, y1, x2, y2, x3, y3)) {
               // 겹침
                if (l1.y1 > l2.y1) {

                }
            }
            else {
                ans = 1;    // 완전한 평행
            }
        }
        else {
            // 교차점 발생
        }

        cout << ans << '\n';
    }
    return 0;
}