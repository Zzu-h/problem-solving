#include<iostream>
#include<queue>
using namespace std;
#define maxNum 10000
int T, N, a, b;
class Node {
public:
	int idx;
	int strSize;
	bool vistied;
	string str;
	vector<Node*> child;
	Node(int i) {
		this->idx = i;
		this->strSize = 0;
		this->vistied = false;
	}
};
class Tree {
public:
	vector<Node*> list;
	int size;
	Tree(int n) {
		for (size_t i = 0; i <= n; i++)
			list.push_back(new Node(i));
		this->size = n;
	}
	void link(int a, int b) {
		list[a]->child.push_back(list[b]);
	}

	void bfs(int start) {
		queue<Node*> Q;
		list[start]->vistied = true;
		list[start]->strSize = list[start]->str.size();
		Q.push(list[start]);
		while (!Q.empty()) {
			Node* t = Q.front();
			Q.pop();
			for (size_t i = 0; i < t->child.size(); i++) {
				if (!t->child[i]->vistied) {
					t->child[i]->vistied = true;
					t->child[i]->strSize = t->strSize + t->child[i]->str.size() + 1;
					Q.push(t->child[i]);
				}
			}
		}
	}
	void setString() {
		for (size_t i = 1; i <= size; i++)
			cin >> list[i]->str;
	}
	void print() {
		for (size_t i = 1; i <= size; i++)
			cout<< list[i]->strSize << '\n';
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		Tree t(N);
		N--;
		while (N--) {
			cin >> a >> b;
			t.link(a, b);
		}
		t.setString();
		t.bfs(1);
		t.print();
	}

	return 0;
}