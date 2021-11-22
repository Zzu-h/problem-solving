#include<iostream>
#include <set>
#include<vector>
using namespace std;
typedef pair<int, int> p;
struct compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first)
            return a < b;
         return a.second < b.second;
    }
};
int segment(int x, vector<int> space) {
    int minimum = 2147483647, minIdx = -1, maximum = 0;
    vector<int>mini;
    set<p, compare> list;
    multiset<int> list2;
    for (size_t i = 0; i < x; i++)
        //list.insert({ space[i],i });
        list2.insert(space[i]);
    //p t = (*list.begin());
    //minimum = t.first; minIdx = t.second;
    mini.push_back((*list2.begin()));

    for (size_t i = 1; i + x <= space.size(); i++) {
        list2.erase(space[i-1]);
        list2.insert(space[i + x - 1]);
        if (minimum != (*list2.begin())) {
            minimum = (*list2.begin());
            mini.push_back(minimum);
        }
    }

    for (size_t i = 0; i < mini.size(); i++) {
        cout << mini[i] << endl;
        maximum = max(maximum, mini[i]);
    }

    return maximum;
}
int main() {
    cout << segment(3, { 2,5,4,6,8 }) << endl;
    return 0;
}
//#define maxNum 1000000001
//bool arr[maxNum];
//int main() {
//    return 0;
//}

//int arr[maxNum][maxNum] = { 0, };
//int map[maxNum][maxNum] = { 0, };
//int dx[] = { 0, 0, 1, -1};
//int dy[] = { 1, -1, 0, 0};
//
//void init();
//void bfs(int r, int c) {
//    bool flag = false;
//    queue<pair<int, int>> que;
//    que.push(pair<int, int>(0, 0));
//
//    arr[0][0] = 0;
//    map[0][0] = 1;
//    while (!que.empty()) {
//        int ccx = que.front().first;
//        int ccy = que.front().second;
//        que.pop();
//
//        if (ccx == r && ccy == c)
//            flag = true;
//
//        for (int i = 0; i < 4; i++) {
//            int nx = ccx + dx[i];
//            int ny = ccy + dy[i];
//
//            if (map[ny][nx] == 0) {
//                if (nx >= 0 && nx <= r && ny >= 0 && ny <= c) {
//                    if (!map[ny][nx]) {
//                        arr[ny][nx] = arr[ccy][ccx] + 1;
//                        map[ny][nx] = true;
//                        que.push(pair<int, int>(nx, ny));
//                    }
//                }
//            }
//        }
//    }
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int getNumber(string str) {
//    int n = -1, sum = 0;
//    for (int i = 0; i < str.size(); i++) {
//        switch (str[i]) {
//        case 'a':
//        case 'b':
//            n = 1;
//            break;
//        case 'c':
//        case 'd':
//        case 'e':
//            n = 2;
//            break;
//        case 'f':
//        case 'g':
//        case 'h':
//            n = 3;
//            break;
//        case 'i':
//        case 'j':
//        case 'k':
//            n = 4;
//            break;
//        case 'l':
//        case 'm':
//        case 'n':
//            n = 5;
//            break;
//        case 'o':
//        case 'p':
//        case 'q':
//            n = 6;
//            break;
//        case 'r':
//        case 's':
//        case 't':
//            n = 7;
//            break;
//        case 'u':
//        case 'v':
//        case 'w':
//            n = 8;
//            break;
//        case 'x':
//        case 'y':
//        case 'z':
//            n = 9;
//            break;
//        default:
//            break;
//        }
//        sum += n;
//    }
//    return sum;
//}
//int main() {
//    string str = "asdf";
//    int counter = 0;
//    vector<string> list;
//
//    for (size_t i = 1; i <= str.size(); i++)
//        for (size_t k = 0; k + i<= str.size(); k++)
//            list.push_back(str.substr(k, i));
//        
//    int size = list.size();
//    for (size_t k = 0; k < size; k++)
//        if (getNumber(list[k]) % list[k].size() == 0)
//            counter++;
//}INT_MAX