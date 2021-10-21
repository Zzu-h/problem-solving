#include <iostream>
#include <set>
#include <vector>
#include <string.h>
#define MAXNUM 101
using namespace std;

int T, N, M, A, B;
class Node {
public:
    int idx;
    bool visitied = false;
    Node(int index) {
        this->idx = index;
    }
};
class Tree {
private:
    int size;
public:
    vector<Node*> ballList;
    set<Node*> ball_list[MAXNUM];
    bool visited[MAXNUM];
    Tree(int size) {
        this->size = size;
        for (int i = 0; i <= size; i++)
            ballList.push_back(new Node(i));
        memset(visited, false, MAXNUM);
    }
    void linkChild(int a, int b) {
        ball_list[a].insert(ballList[b]);
    }
    set<Node*> give_child_to_parent(int idx) {
        if(visited[idx])
            return  ball_list[idx];
        for (auto iter = ball_list[idx].begin(); iter != ball_list[idx].end(); iter++) {
            set<Node*> temp = give_child_to_parent((*iter)->idx);
            ball_list[idx].insert(temp.begin(), temp.end());
        }
        visited[idx] = true;
        return ball_list[idx];
    }
    void print() {
        for (int i = 1; i <= size; i++)
            give_child_to_parent(i);
        for (int i = 1; i <= size; i++)
            cout << ball_list[i].size() << ' ';
        cout << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        Tree t(N);
        while (M--) {
            cin >> A >> B;
            t.linkChild(A, B);
        }
        t.print();
    }
    return 0;
}
