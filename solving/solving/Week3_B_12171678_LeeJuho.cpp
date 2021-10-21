#include<iostream>
#include<queue>
#define maxNum 2000
using namespace std;
int edge[maxNum][maxNum];
class Node {
public:
    vector<Node*> children;
    string data;
    int len = 0;
    bool visited = false;
    Node(int idx) {
        this->index = idx;
    }
    int index = 0;
};
class graph {
public:
    vector<Node*> list;
    int maxLen = 0;
    graph(int size) {
        for (int i = 0; i < size; i++)
            list.push_back(new Node(i));
    }
    void insert(int a, int b, int c) {
        list[a]->children.push_back(list[b]);
        list[b]->children.push_back(list[a]);
        edge[a][b] = c; edge[b][a] = c;
    }
    int bfs(int idx) {
        int endPoint = idx;
        setFalse();
        queue<Node*> Q;
        list[idx]->visited = true;
        Q.push(list[idx]);
        while (!Q.empty()) {
            Node* v = Q.front();
            Q.pop();
            for (size_t i = 0; i < v->children.size(); i++) {
                Node* temp = v->children[i];
                if (temp->index == idx) continue;
                if (!temp->visited)
                {
                    temp->len = v->len + edge[v->index][temp->index];
                    if (temp->len > maxLen) {
                        endPoint = temp->index;
                        maxLen = temp->len;
                    }
                    temp->visited = true;
                    Q.push(temp);
                }
            }
        }
        return endPoint;
    }
    void print() {
        cout << maxLen << '\n';
    }
    void setFalse() {
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            (*iter)->len = 0;
            (*iter)->visited = false;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    while (N--) {
        int T;
        cin >> T;
        graph g(T);
        for (int i = 0; i < T - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g.insert(a - 1, b - 1, c);
        }
        g.bfs(g.bfs(0));
        
        g.print();
    }
    return 0;
}