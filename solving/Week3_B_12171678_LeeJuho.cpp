#include<iostream>
#include<queue>
#define maxNum 2000
using namespace std;
int edge[maxNum][maxNum];
class Node{
public:
    vector<Node*> children;
    string data;
    int len = 0;
    int maxIdx= 0;
    bool visited = false;
    Node(int idx) {
        this->index = idx;
    }
    int index = 0;
};
class graph{
public:
    vector<Node*> list;
    int maxLen = 0;
    graph(int size){
        for (int i = 0; i < size; i++) 
            list.push_back(new Node(i));
    }
    void insert(int a, int b, int c){
        list[a]->children.push_back(list[b]);
        list[b]->children.push_back(list[a]);
        edge[a][b] = c; edge[b][a] = c;
    }
    void bfs(int idx){
        setFalse();
        queue<Node*> Q;
        list[idx]->visited = true;
        Q.push(list[idx]);
        while(!Q.empty()){
            Node* v = Q.front();
            Q.pop();
            for(int i = 0; i < v->children.size(); i++){
                Node* temp = v->children[i];
                if (temp == list[idx])
                    continue;
               if(!temp->visited)
                {
                    temp->len = v->len + edge[v->index][temp->index];
                    temp->visited = true;
                    Q.push(temp);
                }
               else {
                   temp->len = max(temp->len, v->len + edge[v->index][temp->index]);
               }
               list[idx]->len = max(temp->len, list[idx]->len);
            }
        }
        cout << "idx: "<<idx+1<< " len: "<< list[idx]->len << endl;
        maxLen = max(maxLen, list[idx]->len);
    }
    void print(){
        cout << maxLen << '\n';
    }
    void setFalse() {
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            (*iter)->len = 0;
            (*iter)->visited = false;
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    while(N--){
        int T;
        cin>>T;
        graph g(T);
        for(int i = 0; i<T-1;i++){
            int a, b, c;
            cin >> a >> b >> c;
            g.insert(a-1, b-1, c);
        }
        for (int i = 0; i < T; i++) {
            g.bfs(i);
        }
        g.print();
    }
    return 0;
}

/*
2
5
1 2 5
2 3 1
3 4 2
4 5 3
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
*/