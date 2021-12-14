//#include<iostream>
//#include <string.h>
//#include <vector>
//using namespace std;
//#define endl '\n'
//#define maxNum  10000
//
//int f, n, m, q = 0;
//char T[maxNum][maxNum] = { 0, };
//int L[26] = { 0, };
//string line[maxNum] = { "", };
//int counter = 0;
//void make_L(string p) {
//    for (size_t i = 0; i < 26; i++) L[i] = -1;
//    for (size_t i = 0; i < p.size(); i++) L[p[i] - 'A'] = i;
//}
//bool boyer(string p) {
//    make_L(p);
//    m = p.size();
//    int i = m - 1, j = m - 1;
//    for (size_t k = 0; k < n; k++) {
//        i = m - 1, j = m - 1;
//        while (i < n) {
//            if (T[k][i] == p[j]) {
//                if (j == 0) return true;
//                else { i--; j--; }
//            }
//            else {
//                int l = L[T[k][i] - 'A'];
//                i = i + m - min(j, 1 + l);
//                j = m - 1;
//            }
//        }
//    }
//
//    for (size_t k = 0; k < n; k++) {
//        i = m - 1, j = m - 1;
//        while (i < n) {
//            if (T[i][k] == p[j]) {
//                if (j == 0) return true;
//                else { i--; j--; }
//            }
//            else {
//                int l = L[T[i][k] - 'A'];
//                i = i + m - min(j, 1 + l);
//                j = m - 1;
//            }
//        }
//    }
//
//    for (size_t k = 0; k < counter; k++) {
//        i = m - 1, j = m - 1; f = line[k].size();
//        while (i < f) {
//            if (line[k][i] == p[j]) {
//                if (j == 0) return true;
//                else { i--; j--; }
//            }
//            else {
//                int l = L[T[k][i] - 'A'];
//                i = i + m - min(j, 1 + l);
//                j = m - 1;
//            }
//        }
//    }
//    return false;
//}
//string s;
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin >> n >> q;
//    for (size_t i = 0; i < n; i++)
//        for (size_t k = 0; k < n; k++)
//            cin >> T[i][k];
//
//    for (size_t k = 0; k < n; k++, counter++)
//        for (size_t y = k, x = 0; y < n && x < n; y++, x++)
//            line[counter].push_back(T[y][x]);
//    for (size_t k = 1; k < n; k++, counter++)
//        for (size_t y = 0, x = k; y < n && x < n; y++, x++)
//            line[counter].push_back(T[y][x]);
//
//    while (q--) {
//        cin >> s;
//        cout << boyer(s) << endl;
//    }
//}

#include<iostream>
#include <string.h>
#include <vector>
using namespace std;
#define endl '\n'
#define maxNum  10000

int f, n, m, q = 0;
char T[maxNum][maxNum] = { 0, };
int F[maxNum] = { 0, };
string line[maxNum] = { "", };

void make_failureFunction(string s) {
    memset(F, 0, maxNum);
    F[0] = 0;
    int i = 1, j = 0, m = s.size();
    while (i < m){
        if (s[i] == s[j]) {
            F[i] = j + 1;
            i++; j++;
        }
        else if (j > 0) j = F[j - 1];
        else {
            F[i] = 0; i++;
        }
    }
}

bool kmp(string p) {
    make_failureFunction(p);
    // 가로
    int i = 0, j = 0, m = p.size();
    for (size_t k = 0; k < n; k++) {
        i = 0, j = 0;
        while (i < n) {
            if (T[k][i] == p[j]) {
                if (j == m - 1) return true;
                else { j++; i++; }
            }
            else {
                if (j > 0) j = F[j - 1];
                else i++;
            }
        }
    }
    // 세로
    i = 0, j = 0;
    for (size_t k = 0; k < n; k++) {
        i = 0, j = 0;
        while (i < n) {
            if (T[i][k] == p[j]) {
                if (j == m - 1) return true;
                else { j++; i++; }
            }
            else {
                if (j > 0) j = F[j - 1];
                else i++;
            }
        }
    }
    // 우측 대각선
    i = 0, j = 0;
    int tN = 2 * n - 1, curN = 0;
    for (size_t k = 0; k < tN; k++) {
        i = 0, j = 0; curN = line[k].size(); 
        while (i < curN) {
            if (line[k][i] == p[j]) {
                if (j == m - 1) return true;
                else { j++; i++; }
            }
            else {
                if (j > 0) j = F[j - 1];
                else i++;
            }
        }
    }
    return false;
}
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     cin >> n >> m;
     for (size_t i = 0; i < n; i++)
         for (size_t k = 0; k < n; k++)
             cin >> T[i][k];
     int count = 0;
     for (size_t k = 0; k < n; k++, count++)
         for (size_t y = k, x = 0; y < n && x < n; y++, x++)
             line[count].push_back(T[y][x]);
     for (size_t k = 1; k < n; k++, count++)
         for (size_t y = 0, x = k; y < n && x < n; y++, x++)
             line[count].push_back(T[y][x]);

     while (m--) {
         cin >> s;
         cout << kmp(s) << endl;
     }
}