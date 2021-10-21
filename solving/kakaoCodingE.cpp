#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#pragma once
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	int idx;
	Node* leftChild;
	Node* rightChild;
	Node* parent;

	Node() {
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
	Node(int idx) {
		this->data = NULL;
		this->idx = idx;
		this->leftChild = NULL;
		this->rightChild = NULL;
		this->parent = NULL;
	}
};
bool compare(Node* a, Node* b) {
	return a->idx < b->idx;
}
class binarySearchTree
{
public:
	vector<Node*> Nodes;
	Node* root;
	int sheep;
	int wolf;
	binarySearchTree() {
		this->root = new Node(0);
		this->sheep = 0;
		this->wolf = 0;
		Nodes.push_back(root);
	}
	void insert(int st, int de) {
		int idxSt = findIdx(st);
		if (idxSt == -1) {
			Node* newNode = new Node(de);
			Node* newNodeSt = new Node(st);
			newNodeSt->leftChild = newNode;
			Nodes.push_back(newNodeSt);
			Nodes.push_back(newNode);
		}
		else{
			int idxDe = findIdx(de);
			if (idxDe == -1) {
				Node* newNode = new Node(de);
				if (Nodes[idxSt]->leftChild == NULL)
					Nodes[idxSt]->leftChild = newNode;
				else
					Nodes[idxSt]->rightChild = newNode;
				Nodes.push_back(newNode);
			}
			else {
				if (Nodes[idxSt]->leftChild == NULL)
					Nodes[idxSt]->leftChild = Nodes[idxDe];
				else
					Nodes[idxSt]->rightChild = Nodes[idxDe];
			}
		}
	}
	int findIdx(int index) {
		for (int i = 0; i < Nodes.size(); i++)
			if (Nodes[i]->idx == index)
				return i;
		return -1;
	}
	void sheepsSet(vector<int> info) {
		sort(Nodes.begin(), Nodes.end(), compare);
		for (int i = 0; i < info.size(); i++) {
			Nodes[i]->data = info[i];
			cout << Nodes[i]->idx << ' ' << Nodes[i]->data << endl;
		}
		cout << endl;
	}

	void preorderPrint(Node* curNode) {
		if (curNode != NULL) {
			cout << curNode->data << " ";
			preorderPrint(curNode->leftChild);
			preorderPrint(curNode->rightChild);
		}
	}
	void preorder() {
		preorderPrint(root);
		cout << endl;
	}
};

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
	binarySearchTree bst;
	for (auto iter = edges.begin(); iter != edges.end(); iter++)
		bst.insert( ((*iter)[0]), ((*iter)[1]));
	bst.sheepsSet(info);


    return answer;
}

#include<iostream>

int main() {
    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> edges = { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} };
    vector<int> sets;

    /*for (auto iter = sets.begin(); iter != sets.end(); iter++) {
        cout << *iter << ' ';
    }*/
    cout << solution(info, edges) << endl;
    return 0;
}