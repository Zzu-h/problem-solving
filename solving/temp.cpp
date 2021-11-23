#include<iostream>
#include<vector>
using namespace std;

#define children  adj
#define price first
#define node second
#define maxNum 100001

// graph의 node
class Node {
private:
	typedef pair<int, Node*> adjacency;
public:
	// 인접 노드가 저장될 vector
	vector<adjacency> adj;
	int data;		//자기 자신의 조형물 번호
	Node(int d) {
		this->data = d;
	}
	// 간선 정보가 입력될 때 이 메소드를 통해 insert
	void insert(Node* b, int e) {
		adj.push_back({ e, b });
	}
};

// heap structure
class Heap {
private:
	typedef pair<int, Node*> adjacency;
	vector<adjacency> v;		// heap 배열
	int heap_size;					// heap에 저장된 요소의 size
	int root_index;					// 기본적으로 저장될 root Index = 1

	// minHeap / maxHeap을 선택하는 요소 -> 1일 경우 maxHeap / -1일 경우 minHeap
	int direction;

	// 두 요소를 바꾸는 메소드
	void swap(int idx1, int idx2);
	void upHeap(int idx);
	void downHeap(int idx);
	// upHeap과 downHeap을 결정하는 비교 메소드
	bool greaterComparator(adjacency& a, adjacency& b);
public:
	Heap(int direction) {
		v.push_back({ -1, new Node(-1) });
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction * -1;
	}
	void insert(adjacency e);		// insert 메소드
	pair<int, Node*> pop();		// pop 메소드, 삭제와 동시에 가장 top의 결과물을 return한다.
	Node* top();						// 현재 가장 우선순위가 높은 Node를 return 한다.
	int size();								// 현재 heap에 저장된 요소의 size
	bool isEmpty();					// heap이 비어있는지 확인하는 메소드
	int find(Node* e);				// 원하는 요소를 찾아 heap에 저장된 index를 return
	void update(int idx, int p);	// index를 받아 해당 index의 요소의 data를 수정하는 메소드
};
class Graph {
private:
	Node* find_list[maxNum];								// graph에 저장될 node의 list
public:
	void insert(int a, int b, int e);							// graph에 저장하는 method
	Node* getNode(int d) { return find_list[d]; }	// 해당하는 data의 node pointer를 return한다.
};

class PrimMST {
private:
	typedef pair<int, Node*> adjacency;
	Graph g;									// 해당 문제에 사용될 graph
	vector<int> print;					// 출력할 결과물들을 저장하는 vector
	void answerPrint(int count);	// 모든 결과물들을 출력하는 메소드
public:
	// graph g에 node 정보들을 insert하는 메소드
	void graphInsert(int a, int b, int e) { g.insert(a, b, e); }
	void prims(int idx);	// 실제 prim 알고리즘을 수행하는 메소드
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, q, a, b, e;
	char c;
	cin >> n >> m >> q;
	PrimMST p;
	// graph(n) 생성 
	while (m--) {
		// edge insert 부분
		cin >> a >> b >> e;
		p.graphInsert(a, b, e);
	}
	while (q--) {
		// 출력부분
		cin >> c >> a;
		p.prims(a);
	}
}

// node의 우선순위를 정하는 비교연산자이다.
bool Heap::greaterComparator(adjacency& a, adjacency& b) {
	if (a.price == b.price)
		return a.node->data * direction > b.node->data * direction;
	return a.price * direction > b.price * direction;
}
// 두 요소간에 위치를 변경한다.
void Heap::swap(int idx1, int idx2) {
	v[0] = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = v[0];
}
// upHeap 수행
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
// downHeap 수행
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
// Heap insert 수행, heap size 증가
void Heap::insert(adjacency e) {
	v.push_back(e);
	heap_size++;
	upHeap(heap_size);
}
// heap의 최상위 노드를 삭제와 동시에 해당 값을 return, heap size 감소
pair<int, Node*> Heap::pop() {
	adjacency top = v[root_index];
	v[root_index] = v[heap_size];
	heap_size--;
	v.pop_back();
	downHeap(root_index);
	return top;
}

// primMST에선 쓰이진 않음
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

// 입력된 node의 Heap 배열 index를 찾아 return, 못 찾을 경우 -1을 return
int Heap::find(Node* e) {
	for (size_t i = 1; i < v.size(); i++)
		if (v[i].node->data == e->data) return i;
	return -1;
}
// 이미 저장된 값의 가치와 새로 들어온 가치 p를 비교
void Heap::update(int idx, int p) {
	// p가 더 작을경우 값을 변경한다. 그 후 upHeap을 수행(새로 바뀐 값이 적어도 우선순위가 더 높다.)
	if (v[idx].price * direction > p * direction) {
		v[idx].price = p;
		upHeap(idx);
	}
}

// graph에 insert함
void Graph::insert(int a, int b, int e) {
	Node* a_node, * b_node;
	a_node = find_list[a]; b_node = find_list[b];
	// 저장된 node가 없을 경우 새 node를 생성해 삽입한다.
	if (a_node == nullptr) {
		a_node = new Node(a);
		find_list[a] = a_node;
	}
	if (b_node == nullptr) {
		b_node = new Node(b);
		find_list[b] = b_node;
	}
	// 그 후 각자의 edge를 연결해 준다.
	a_node->insert(b_node, e);
	b_node->insert(a_node, e);
}

void PrimMST::prims(int d) {
	bool tree[maxNum] = { 0, };
	int id, counter = 0;
	Heap fringe(-1);		// minHeap으로 가치가 낮은게 우선순위가 높다.
	tree[d] = true;

	// 자기 자신부터 fringe set으로 포함시키고 tree만들기를 시작한다. 자기자신과의 관계는 0
	fringe.insert({ 0,  g.getNode(d) });
	while (!fringe.isEmpty()) {
		adjacency t = fringe.pop();										// fringe set에서 가장 가치가 낮은, 우선순위가 가장 높은 값을 꺼내온다.
		Node* curNode = t.node; counter += t.price;		// fringe set에서 꺼내온 가치는 총합에 저장, node는 curNode에 저장
		tree[curNode->data] = true;									// 꺼내온 data는 tree set에 포함된다.
		print.push_back(curNode->data);							// 출력 결과물에 출력할 data를 담는다.
		for (size_t i = 0; i < curNode->adj.size(); i++) {
			adjacency temp = curNode->adj[i];
			// 만일 인접 node가 tree에 존재한다면 fringe set을 돌지 않는다.
			if (!tree[temp.node->data]) {
				if ((id = fringe.find(temp.node)) != -1)			// tree에 존재하지 않고, fringe set에 존재한다면,
					fringe.update(id, temp.price);						// fringe set에 data의 가치를 변경한다.
				else
					fringe.insert(curNode->adj[i]);					// tree에도 존재하지 않고, fringe set에도 존재하지 않다면,  fringe set에 삽입
			}
		}
	}
	answerPrint(counter);
	print.clear();
}

// counter를 입력받아 총합과 함께 출력할 요소들을 모두 출력한다.
void PrimMST::answerPrint(int counter) {
	cout << counter;
	for (size_t i = 0; i < print.size(); i++) {
		cout << ' ' << print[i];
	}
	cout << '\n';
}