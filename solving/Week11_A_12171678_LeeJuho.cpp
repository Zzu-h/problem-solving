#include <iostream>
#include <vector>
#include <string.h>
#include<cmath>
using namespace std;
#define alphaSize 26
#define maxSize 9000000
#define pre second
#define cur first
typedef pair<int[alphaSize], int> p;

int T, M, ans = 0, alpha[alphaSize] = { 0, };
p list[24];
bool check[maxSize] = { 0, };
p dp[maxSize];
pair<int, int> getIdx(int idx) {
    int count = 0, tidx = idx;
    while (tidx > 0) {
        tidx /= 2;
        count++;
    }
    int first = count, second = idx - pow(2, count - 1);
    return { first, second };
}
void useData(int max_, int idx) {
    for (size_t i = 0; i < max_; i++) {
        bool flag = false;
        if (!check[i]) {
            check[i+max_] = false;
            continue;
        }
        int t = 0;
        for (size_t k = 0; k < alphaSize; k++) {
            t = list[idx].first[k] + dp[i].first[k];
            if (alpha[k] - t < 0) {
                check[i+max_] = false;
                flag = true;
                break;
            }
            dp[i+max_].first[k] = t;
        }
        if (flag) continue;
        dp[i+max_].second = list[idx].second + dp[i].second;
        ans = max(ans, dp[i + max_].second);
        check[i + max_] = true;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(list[0].first, 0, alphaSize);
    list[0].second = 0;
    for (size_t i = 0; i < alphaSize; i++) cin >> alpha[i];
    cin >> T;
    for (size_t i = 1; i <= T; i++) {
        string str;
        cin >> str >> list[i].second;
        memset(list[i].first, 0, alphaSize);
        for (size_t k = 0; k < str.size(); k++) list[i].first[str[k] - 'a']++;
    }
    M = pow(2, T);
    check[0] = true;
    for (size_t i = 1; i <= T; i++)
        useData(1 << (i - 1), i);

    cout << ans << '\n';
    return 0;
}

//#include <iostream>
//#include <vector>
//#include <string.h>
//#include<cmath>
//using namespace std;
//#define alphaSize 26
//#define maxSize 9000000
//#define pre second
//#define cur first
//typedef pair<int[alphaSize], int> p;
//
//int T,M, ans = 0, alpha[alphaSize] = { 0, };
//vector<p> list;
//bool check[maxSize] = { 0, };
//p dp[maxSize];
//pair<int,int> getIdx(int idx) {
//    int count = 0, tidx = idx;
//    while (tidx > 0) {
//        tidx /= 2;
//        count++;
//    }
//    int first = count, second = idx - pow(2, count - 1);
//    return { first, second};
//}
//void useData(int idx) {
//    pair<int, int> Idx = getIdx(idx);
//    if (!check[Idx.pre]) {
//        check[idx] = false;
//        return;
//    }
//    int t = 0;
//    for (size_t i = 0; i < alphaSize; i++) {
//        t = list[Idx.cur].first[i] + dp[Idx.pre].first[i];
//        if (alpha[i] - t < 0) {
//            check[idx] = false;
//            return;
//        }
//        dp[idx].first[i] = t;
//    }
//    dp[idx].second = list[Idx.cur].second + dp[Idx.pre].second;
//    ans = max(ans, dp[idx].second);
//    check[idx] = true;
//}
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    p t;
//    memset(t.first, 0, alphaSize);
//    t.second = 0;
//    for (size_t i = 0; i < alphaSize; i++) cin >> alpha[i];
//    cin >> T;
//    list.push_back(t);
//    for (size_t i = 0; i < T; i++) {
//        p temp; string str;
//        cin >> str >> temp.second;
//        memset(temp.first, 0, alphaSize);
//        for (size_t k = 0; k < str.size(); k++) temp.first[str[k] - 'a']++;
//        list.push_back(temp);
//    }
//    T = pow(2, T);
//    check[0] = true;
//    for (size_t i = 1; i < T; i++)
//        useData(i);
//
//    cout << ans << '\n';
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string.h>
//using namespace std;  
//#define alphaSize 26
//typedef pair<int[alphaSize], int> p;
//
//int T, ans = 0, alpha[alphaSize] = { 0, };
//vector<p> list, dp;
//
//void useData(int idxI, int idxK) {
//    for (size_t i = 0; i < alphaSize; i++)
//        if (alpha[i] - (dp[idxK].first[i] + list[idxI].first[i]) < 0) return;
//
//    p temp;
//    for (size_t i = 0; i < alphaSize; i++) temp.first[i] = dp[idxK].first[i] + list[idxI].first[i];
//    temp.second = dp[idxK].second + list[idxI].second;
//    dp.push_back(temp);
//}
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    for (size_t i = 0; i < alphaSize; i++) cin >> alpha[i];
//    cin >> T;
//    for (size_t i = 0; i < T; i++) {
//        p temp; string str;
//        cin >> str >> temp.second;
//        memset(temp.first, 0, alphaSize);
//        for (size_t k = 0; k < str.size(); k++) temp.first[str[k] - 'a']++;
//        list.push_back(temp);
//    }
//
//    for (size_t i = 0; i < T; i++) {
//        size_t temp = dp.size();
//        for (size_t k = 0; k < temp; k++) useData(i, k);
//        dp.push_back(list[i]);
//    }
//
//    for (size_t i = 0; i < dp.size(); i++)
//        ans = max(ans, dp[i].second);
//    cout << ans << '\n';
//    return 0;
//}