#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
    vector<Node*> children;
    string data;
    int len = 0;
    bool visited = false;
};
class graph{
public:
    vector<Node*> list;
    graph(int size){
        for (int i = 0; i < size; i++) 
            list.push_back(new Node());
    }
    void insert(int a, int b){
        list[a]->children.push_back(list[b]);
    }
    void bfs(){
        queue<Node*> Q;
        list[0]->visited = true;
        list[0]->len = list[0]->data.size();
        Q.push(list[0]);
        while(!Q.empty()){
            Node* v = Q.front();
            Q.pop();
            for(int i = 0; i < v->children.size(); i++){
                Node* temp = v->children[i];
                if(!temp->visited){
                    temp->len = v->len + temp->data.size() + 1;
                    temp->visited = true;
                    Q.push(temp);
                }
            }
        }
    }
    void print(){
        for(auto iter = list.begin(); iter != list.end(); iter++)
            cout<< (*iter)->len << '\n';
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
            int a, b;
            cin>>a>>b;
            g.insert(a-1, b-1);
        }
        for(int i = 0; i<T;i++)
            cin>>g.list[i]->data;

        g.bfs();
        g.print();
    }
    return 0;
}
