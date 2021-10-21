#include <iostream>
#include <set>
#define x first
#define y second
using namespace std;

int T, N, M, K, A, B;

struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        int distanceA = a.x * a.x + a.y * a.y;
        int distanceB = b.x * b.x + b.y * b.y;
        if (distanceA == distanceB)
            if (a.x == b.x)
                return a.y < b.y;
            else
                return a.x < b.x;
        return distanceA < distanceB;
    }
};
set<pair<int, int>, compare> hambugs;
compare comp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        while (M--) {
            cin >> A >> B;
            hambugs.insert({ A, B });
        }
        auto iter = hambugs.begin();
        for (int i = 0; i < K - 1; i++)
            iter++;

        while (N--) {
            pair<int, int> t;
            cin >> t.x >> t.y;
            hambugs.insert(t);
            if (!comp((*iter), t))
                iter--;
            cout << (*iter).x << ' ' << (*iter).y << '\n';
            //cout << "ans: " << (*iter).x << ' ' << (*iter).y << '\n';
        }
        hambugs.clear();
        //cout << "----------------------------------------------" << '\n';
    }
    return 0;
}


//#include <iostream>
//#include <queue>
//#define MAXNUM 1000
//using namespace std;
//
//int T, N, M, K, A, B;
//class hambugs {
//public:
//    double distance;
//    int x, y;
//    hambugs(int x, int y) {
//        this->distance = x * x + y * y;
//        this->x = x;
//        this->y = y;
//    }
//};
//
//struct compare {
//    bool operator()(hambugs &a, hambugs &b) {
//        if (a.distance == b.distance)
//            if (a.x == b.x)
//                return a.y > b.y;
//            else
//                return a.x > b.x;
//        return a.distance > b.distance;
//    }
//};
//priority_queue<hambugs, vector<hambugs>, compare> ham;
//vector<hambugs> temp;
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> T;
//    bool flag = false;
//    while (T--) {
//        cin >> M >> N >> K;
//
//        while (M--) {
//            cin >> A >> B;
//            ham.push(hambugs(A, B));
//        }
//        while (N--) {
//            cin >> A >> B;
//            ham.push(hambugs(A, B));
//
//            for (int i = 0; i < K - 1; i++) {
//                temp.push_back(ham.top());
//                ham.pop();
//            }
//            if (flag) cout <<"ans: "<< ham.top().x << ' ' << ham.top().y << '\n';
//            else cout << ham.top().x << ' ' << ham.top().y << '\n';
//            for (int i = 0; i < K - 1; i++) 
//                ham.push(temp[i]);
//            temp.clear();
//        }
//        while (!ham.empty())
//            ham.pop();
//        if (flag) cout << "----------------------------------------------" << '\n';
//    }
//    return 0;
//}
