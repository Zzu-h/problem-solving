#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define maxNum 2001
int T, N, a, b, c;
int edge[maxNum][maxNum] = { 0 };
class Node {
public:
	int idx;
	int edgeSize;
	bool vistied;
	vector<Node*> child;
	Node(int i) {
		this->idx = i;
		this->edgeSize = 0;
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
	void link(int a, int b, int c) {
		list[a]->child.push_back(list[b]);
		list[b]->child.push_back(list[a]);
		edge[a][b] = c; edge[b][a] = c;
	}

	int bfs(int start) {
		setFalse();
		int maxIdx = start;
		queue<Node*> Q;
		list[start]->vistied = true;
		//list[start]->edgeSize = 0;
		Q.push(list[start]);
		while (!Q.empty()) {
			Node* t = Q.front();
			Q.pop();
			for (size_t i = 0; i < t->child.size(); i++) {
				if (!t->child[i]->vistied) {
					t->child[i]->vistied = true;
					t->child[i]->edgeSize = edge[t->child[i]->idx][t->idx] + t->edgeSize;
					if (list[maxIdx]->edgeSize < t->child[i]->edgeSize)
						maxIdx = t->child[i]->idx;
					Q.push(t->child[i]);
				}
			}
		}
		return maxIdx;
	}
	void setFalse() {
		for (size_t i = 1; i <= size; i++) {
			list[i]->edgeSize = 0;
			list[i]->vistied = false;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		memset(edge, 0, maxNum * maxNum);
		cin >> N;
		Tree t(N);
		N--;
		while (N--) {
			cin >> a >> b>> c;
			t.link(a, b, c);
		}
		cout << t.list[t.bfs(t.bfs(1))]->edgeSize << '\n';
	}

	return 0;
}