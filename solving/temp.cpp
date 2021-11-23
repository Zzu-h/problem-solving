#include<iostream>
#include<vector>
using namespace std;

#define children  adj
#define price first
#define node second
#define maxNum 100001

// graph�� node
class Node {
private:
	typedef pair<int, Node*> adjacency;
public:
	// ���� ��尡 ����� vector
	vector<adjacency> adj;
	int data;		//�ڱ� �ڽ��� ������ ��ȣ
	Node(int d) {
		this->data = d;
	}
	// ���� ������ �Էµ� �� �� �޼ҵ带 ���� insert
	void insert(Node* b, int e) {
		adj.push_back({ e, b });
	}
};

// heap structure
class Heap {
private:
	typedef pair<int, Node*> adjacency;
	vector<adjacency> v;		// heap �迭
	int heap_size;					// heap�� ����� ����� size
	int root_index;					// �⺻������ ����� root Index = 1

	// minHeap / maxHeap�� �����ϴ� ��� -> 1�� ��� maxHeap / -1�� ��� minHeap
	int direction;

	// �� ��Ҹ� �ٲٴ� �޼ҵ�
	void swap(int idx1, int idx2);
	void upHeap(int idx);
	void downHeap(int idx);
	// upHeap�� downHeap�� �����ϴ� �� �޼ҵ�
	bool greaterComparator(adjacency& a, adjacency& b);
public:
	Heap(int direction) {
		v.push_back({ -1, new Node(-1) });
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction * -1;
	}
	void insert(adjacency e);		// insert �޼ҵ�
	pair<int, Node*> pop();		// pop �޼ҵ�, ������ ���ÿ� ���� top�� ������� return�Ѵ�.
	Node* top();						// ���� ���� �켱������ ���� Node�� return �Ѵ�.
	int size();								// ���� heap�� ����� ����� size
	bool isEmpty();					// heap�� ����ִ��� Ȯ���ϴ� �޼ҵ�
	int find(Node* e);				// ���ϴ� ��Ҹ� ã�� heap�� ����� index�� return
	void update(int idx, int p);	// index�� �޾� �ش� index�� ����� data�� �����ϴ� �޼ҵ�
};
class Graph {
private:
	Node* find_list[maxNum];								// graph�� ����� node�� list
public:
	void insert(int a, int b, int e);							// graph�� �����ϴ� method
	Node* getNode(int d) { return find_list[d]; }	// �ش��ϴ� data�� node pointer�� return�Ѵ�.
};

class PrimMST {
private:
	typedef pair<int, Node*> adjacency;
	Graph g;									// �ش� ������ ���� graph
	vector<int> print;					// ����� ��������� �����ϴ� vector
	void answerPrint(int count);	// ��� ��������� ����ϴ� �޼ҵ�
public:
	// graph g�� node �������� insert�ϴ� �޼ҵ�
	void graphInsert(int a, int b, int e) { g.insert(a, b, e); }
	void prims(int idx);	// ���� prim �˰����� �����ϴ� �޼ҵ�
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, q, a, b, e;
	char c;
	cin >> n >> m >> q;
	PrimMST p;
	// graph(n) ���� 
	while (m--) {
		// edge insert �κ�
		cin >> a >> b >> e;
		p.graphInsert(a, b, e);
	}
	while (q--) {
		// ��ºκ�
		cin >> c >> a;
		p.prims(a);
	}
}

// node�� �켱������ ���ϴ� �񱳿������̴�.
bool Heap::greaterComparator(adjacency& a, adjacency& b) {
	if (a.price == b.price)
		return a.node->data * direction > b.node->data * direction;
	return a.price * direction > b.price * direction;
}
// �� ��Ұ��� ��ġ�� �����Ѵ�.
void Heap::swap(int idx1, int idx2) {
	v[0] = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = v[0];
}
// upHeap ����
void Heap::upHeap(int idx) {
	if (idx == root_index)
		return;
	else {
		int parent = idx / 2;
		if (greaterComparator(v[parent], v[idx])) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
}
// downHeap ����
void Heap::downHeap(int idx) {
	int left = idx * 2;
	int right = idx * 2 + 1;
	if (right <= heap_size) {
		if (!greaterComparator(v[left], v[right])) {
			if (!greaterComparator(v[left], v[idx])) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else {
			if (!greaterComparator(v[right], v[idx])) {
				swap(right, idx);
				downHeap(right);
			}
			else return;
		}
	}
	else if (left <= heap_size) {
		if (!greaterComparator(v[left], v[idx])) {
			swap(left, idx);
			downHeap(left);
		}
		else return;
	}
	else return;
}
// Heap insert ����, heap size ����
void Heap::insert(adjacency e) {
	v.push_back(e);
	heap_size++;
	upHeap(heap_size);
}
// heap�� �ֻ��� ��带 ������ ���ÿ� �ش� ���� return, heap size ����
pair<int, Node*> Heap::pop() {
	adjacency top = v[root_index];
	v[root_index] = v[heap_size];
	heap_size--;
	v.pop_back();
	downHeap(root_index);
	return top;
}

// primMST���� ������ ����
Node* Heap::top() {
	if (isEmpty())
		return nullptr;
	return v[root_index].node;
}
int Heap::size() {
	if (isEmpty())
		return -1;

	return heap_size;
}
bool Heap::isEmpty() {
	if (heap_size == 0)
		return true;
	else
		return false;
}

// �Էµ� node�� Heap �迭 index�� ã�� return, �� ã�� ��� -1�� return
int Heap::find(Node* e) {
	for (size_t i = 1; i < v.size(); i++)
		if (v[i].node->data == e->data) return i;
	return -1;
}
// �̹� ����� ���� ��ġ�� ���� ���� ��ġ p�� ��
void Heap::update(int idx, int p) {
	// p�� �� ������� ���� �����Ѵ�. �� �� upHeap�� ����(���� �ٲ� ���� ��� �켱������ �� ����.)
	if (v[idx].price * direction > p * direction) {
		v[idx].price = p;
		upHeap(idx);
	}
}

// graph�� insert��
void Graph::insert(int a, int b, int e) {
	Node* a_node, * b_node;
	a_node = find_list[a]; b_node = find_list[b];
	// ����� node�� ���� ��� �� node�� ������ �����Ѵ�.
	if (a_node == nullptr) {
		a_node = new Node(a);
		find_list[a] = a_node;
	}
	if (b_node == nullptr) {
		b_node = new Node(b);
		find_list[b] = b_node;
	}
	// �� �� ������ edge�� ������ �ش�.
	a_node->insert(b_node, e);
	b_node->insert(a_node, e);
}

void PrimMST::prims(int d) {
	bool tree[maxNum] = { 0, };
	int id, counter = 0;
	Heap fringe(-1);		// minHeap���� ��ġ�� ������ �켱������ ����.
	tree[d] = true;

	// �ڱ� �ڽź��� fringe set���� ���Խ�Ű�� tree����⸦ �����Ѵ�. �ڱ��ڽŰ��� ����� 0
	fringe.insert({ 0,  g.getNode(d) });
	while (!fringe.isEmpty()) {
		adjacency t = fringe.pop();										// fringe set���� ���� ��ġ�� ����, �켱������ ���� ���� ���� �����´�.
		Node* curNode = t.node; counter += t.price;		// fringe set���� ������ ��ġ�� ���տ� ����, node�� curNode�� ����
		tree[curNode->data] = true;									// ������ data�� tree set�� ���Եȴ�.
		print.push_back(curNode->data);							// ��� ������� ����� data�� ��´�.
		for (size_t i = 0; i < curNode->adj.size(); i++) {
			adjacency temp = curNode->adj[i];
			// ���� ���� node�� tree�� �����Ѵٸ� fringe set�� ���� �ʴ´�.
			if (!tree[temp.node->data]) {
				if ((id = fringe.find(temp.node)) != -1)			// tree�� �������� �ʰ�, fringe set�� �����Ѵٸ�,
					fringe.update(id, temp.price);						// fringe set�� data�� ��ġ�� �����Ѵ�.
				else
					fringe.insert(curNode->adj[i]);					// tree���� �������� �ʰ�, fringe set���� �������� �ʴٸ�,  fringe set�� ����
			}
		}
	}
	answerPrint(counter);
	print.clear();
}

// counter�� �Է¹޾� ���հ� �Բ� ����� ��ҵ��� ��� ����Ѵ�.
void PrimMST::answerPrint(int counter) {
	cout << counter;
	for (size_t i = 0; i < print.size(); i++) {
		cout << ' ' << print[i];
	}
	cout << '\n';
}