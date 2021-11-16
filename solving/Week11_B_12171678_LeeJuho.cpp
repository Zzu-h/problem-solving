#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define maxSize 1024
#define RED true
#define BLUE false

int  T, n, redCount = 0, redSum = 0, blueCount = 0, blueSum = 0;
char c;
bool paper[maxSize][maxSize];
void cut(int start_x, int end_x, int start_y, int end_y) {
    bool flag = false, curColor = paper[start_y][start_x];
    int n = end_x - start_x;
    for (size_t i = start_y; i < end_y; i++) {
        for (size_t k = start_x; k < end_x; k++) {
            if (curColor != paper[i][k]) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if (flag) {
        int x_mid = (start_x + end_x) / 2, y_mid = (start_y + end_y) / 2;
        cut(start_x, x_mid, start_y, y_mid);
        cut(x_mid, end_x, start_y, y_mid);
        cut(start_x, x_mid, y_mid, end_y);
        cut(x_mid, end_x,y_mid, end_y);
    }
    else {
        if (curColor == RED) {
            redCount++;
            redSum += n * n;
        }
        else {
            blueCount++;
            blueSum += n * n;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        memset(paper, 0, maxSize * maxSize);
        redCount = 0, redSum = 0, blueCount = 0, blueSum = 0;
        cin >> n;
        for (size_t i = 0; i < n; i++)
            for (size_t k = 0; k < n; k++) {
                cin >> c;
                paper[i][k] = (c == 'R' ? RED : BLUE);
            }
        //Ã³¸®
        cut(0, n, 0, n);
        //cut(0, n / 2, 0, n / 2);
        //cut(n / 2, n, 0, n / 2);
        //cut(0, n / 2, n / 2, n);
        //cut(n / 2, n, n / 2, n);
        cout << redCount << ' ' << redSum << ' ' << blueCount << ' ' << blueSum << '\n';    }
    return 0;
}