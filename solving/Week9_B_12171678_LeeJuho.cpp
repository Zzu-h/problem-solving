#include <iostream>
#include <string.h>
#define maxNum 21
#define b 2
#define w 1
#define null 0
typedef unsigned int ll;
using namespace std;
int T, n, Q, r, c;
int ans = 0, wc = 0, bc = 0;
bool turn = false;
short odelo[maxNum][maxNum];
void init();
bool check (int, int, bool);
void print() {
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++)
            cout << odelo[k][i] << ' ';
        cout << '\n';
    }
    cout << "-----------------------------------" << endl;
}
bool flip(int x, int y, bool turn) {
    bool doFlip;
    int stone = turn ? b : w;
    int tx, ty;

    tx = x + 1; ty = y; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null) { for (int i = x + 1; i <= n; i++) if (stone == odelo[i][y]) { doFlip = true; tx = i; ty = y; break; } else if (odelo[i][y] == null) break; }
    if (doFlip) for (int i = x + 1; i < tx; i++)  odelo[i][ty] = stone;
    tx = x - 1; ty = y; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null) {for (int i = x - 1; i > 0; i--) if (stone == odelo[i][y]) { doFlip = true; tx = i; ty = y; break; } else if (odelo[i][y] == null) break;   }
    if (doFlip) for (int i = x - 1; i > tx; i--)  odelo[i][ty] = stone;
    tx = x; ty = y + 1; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null) {for (int i = y + 1; i <= n; i++) if (stone == odelo[x][i]) { doFlip = true; tx = x; ty = i; break; } else if (odelo[x][i] == null) break;}
    if (doFlip)  for (int i = y + 1; i < ty; i++)  odelo[tx][i] = stone;
    tx = x; ty = y - 1; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null) {for (int i = y - 1; i > 0; i--) if (stone == odelo[x][i]) { doFlip = true; tx = x; ty = i; break; } else if (odelo[x][i] == null) break;   }
    if (doFlip)  for (int i = y - 1; i > ty; i--)  odelo[tx][i] = stone;

    tx = x - 1; ty = y - 1; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null){ for (int ix = x - 1, iy = y - 1; ix > 0 && iy > 0; ix--, iy--) if (stone == odelo[ix][iy]) { doFlip = true; tx = ix; ty = iy; break; } else if (odelo[ix][iy] == null) break;      }
    if (doFlip) for (int ix = x - 1, iy = y - 1; ix > tx && iy > ty; ix--, iy--)  odelo[ix][iy] = stone;
    tx = x - 1; ty = y + 1; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null){ for (int ix = x - 1, iy = y + 1; ix > 0 && iy <= n; ix--, iy++) if (stone == odelo[ix][iy]) { doFlip = true; tx = ix; ty = iy; break; } else if (odelo[ix][iy] == null) break;   }
    if (doFlip) for (int ix = x - 1, iy = y + 1; ix > tx && iy < ty; ix--, iy++)  odelo[ix][iy] = stone;
    tx = x + 1; ty = y - 1; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null){ for (int ix = x + 1, iy = y - 1; ix <= n && iy > 0; ix++, iy--) if (stone == odelo[ix][iy]) { doFlip = true; tx = ix; ty = iy; break; } else if (odelo[ix][iy] == null) break;   }
    if (doFlip) for (int ix = x + 1, iy = y - 1; ix < tx && iy >ty; ix++, iy--)  odelo[ix][iy] = stone;
    tx = x + 1; ty = y + 1; doFlip = false;
    if (stone != odelo[tx][ty] || odelo[tx][ty] != null){ for (int ix = x + 1, iy = y + 1; ix <= n && iy <= n; ix++, iy++) if (stone == odelo[ix][iy]) { doFlip = true; tx = ix; ty = iy; break; } else if (odelo[ix][iy] == null) break;}
    if (doFlip) for (int ix = x + 1, iy = y + 1; ix < tx && iy < ty; ix++, iy++)  odelo[ix][iy] = stone;

    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    bool printFlag = false;
    
    while (T--) {
        cin >> n >> Q;
        init();
        printFlag ? print() : void();
        while (Q--) {
            printFlag ? cout << "cur turn : " << turn + 1 << ' ' : cout << char(0);
            cin >> r >> c;
            // 둘 수 있는지 check 아니면 continue
            if (!check(r, c, turn)) continue;
            if (turn) odelo[r][c] = b;
            else odelo[r][c] = w;
            flip(r, c, turn); // flip
            printFlag ? print() : void();
            turn = !turn;
        }
        for (int i = 1; i <= n; i++) 
            for (int k = 1; k <= n; k++)
                if (odelo[i][k] == b) bc++;
                else if(odelo[i][k] == w)wc++;
        
        if (bc == wc);
        else if (bc > wc) ans = b;
        else ans = w;
        printFlag ? cout << bc << ' '<< wc<< ' '<<  ans << '\n' : cout << ans << '\n';
    }
    return 0;
}
void init() {
    memset(odelo, null, maxNum * maxNum);
    int idx = n / 2;
    odelo[idx][idx] = b;
    odelo[idx + 1][idx + 1] = b;
    odelo[idx][idx+1] = w;
    odelo[idx + 1][idx] = w;
    ans = 0; wc = 0; bc = 0;
    turn = true;
}
bool check(int x, int y, bool turn) {
    int tx, ty;
    int stone = turn ? b : w;
    tx = x + 1; ty = y;
    if (stone != odelo[tx][ty]){ for (int i = x + 1; i <= n; i++) if (stone == odelo[i][y]) return true; else if (odelo[i][y] == null) break;}
    tx = x - 1; ty = y;
    if (stone != odelo[tx][ty]){ for (int i = x - 1; i > 0; i--) if (stone == odelo[i][y]) return true; else if (odelo[i][y] == null) break;   }
    tx = x; ty = y + 1;
    if (stone != odelo[tx][ty]){ for (int i = y + 1; i <= n; i++) if (stone == odelo[x][i]) return true; else if (odelo[x][i] == null) break;}
    tx = x; ty = y - 1;
    if (stone != odelo[tx][ty]){ for (int i = y - 1; i > 0; i--) if (stone == odelo[x][i]) return true; else if (odelo[x][i] == null) break;   }

    tx = x - 1; ty = y - 1;
    if (stone != odelo[tx][ty]){ for (int ix = x - 1, iy = y - 1; ix > 0 && iy > 0; ix--, iy--) if (stone == odelo[ix][iy]) return true; else if (odelo[ix][iy] == null) break;      }
    tx = x - 1; ty = y + 1;
    if (stone != odelo[tx][ty]){ for (int ix = x - 1, iy = y + 1; ix > 0 && iy <= n; ix--, iy++) if (stone == odelo[ix][iy]) return true; else if (odelo[ix][iy] == null) break;   }
    tx = x + 1; ty = y - 1;
    if (stone != odelo[tx][ty]){ for (int ix = x + 1, iy = y - 1; ix <= n && iy > 0; ix++, iy--) if (stone == odelo[ix][iy]) return true; else if (odelo[ix][iy] == null) break;   }
    tx = x + 1; ty = y + 1;
    if (stone != odelo[tx][ty]){ for (int ix = x + 1, iy = y + 1; ix <= n && iy <= n; ix++, iy++) if (stone == odelo[ix][iy]) return true; else if (odelo[ix][iy] == null) break;}
    return false;
}