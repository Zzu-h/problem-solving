#include<iostream>
#include<queue>
#define Idx first
// 아래는 arr을 위한 것
#define inhaC first
#define biryongC second
#define price second
#define maxNum 100000
using namespace std;


pair<int, int> arr[maxNum];
bool unuseflag[maxNum];

// 정렬 기준
// 1.편차가 큰것
// 2. 자신의 가치가 큰 것
struct compareI {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.price == b.price) {
			return arr[a.Idx].biryongC < arr[b.Idx].biryongC;
		}
		return a.price < b.price;
	}
};
struct compareB {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		if (a.price == b.price) {
			return arr[a.Idx].inhaC < arr[b.Idx].inhaC;
		}
		return a.price < b.price;
	}
};
struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		int deviation1 = abs(arr[a.Idx].inhaC - arr[a.Idx].biryongC);
		int deviation2 = abs(arr[b.Idx].inhaC - arr[b.Idx].biryongC);
		if (deviation1 == deviation2) {
			return a.price < b.price;
		}
		return deviation1 < deviation2;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compareI> inha;
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> biryong;

void init() {
	while (!inha.empty())
		inha.pop();
	while (!biryong.empty())
		biryong.pop();
	for (int i = 0; i < maxNum; i++) {
		unuseflag[i] = true;
		arr[i] = {};
	}
}
int sameThings(bool turn) {
	while (!unuseflag[(turn ? inha.top().Idx : biryong.top().Idx)])
		turn ? inha.pop() : biryong.pop();
	int data = (turn ? inha.top().price : biryong.top().price);
	unuseflag[(turn ? inha.top().Idx : biryong.top().Idx)] = false;
	(turn ? inha.pop() : biryong.pop());
	return data;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		init();
		int N, x, y, in = 0, bi = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			arr[i] = { x, y };
			inha.push({ i,x });
			biryong.push({ i,y });
		}

		/*cout << "inha" << endl;
		while (!inha.empty()) {
			cout << inha.top().price << ' ' << inha.top().Idx <<endl;
			inha.pop();
		}
		cout << "\nbiryong" << endl;
		while (!biryong.empty()) {
			cout << biryong.top().price << ' ' << biryong.top().Idx << endl;
			biryong.pop();
		}
		cout << endl;*/

		bool turn = true;
		while (N--) {
			int temp = sameThings(turn);
			turn ? in += temp : bi += temp;
			turn = !turn;
		}
		cout << in - bi << '\n';
	}
	return 0;
}

//#include<iostream>
//#include<queue>
//#define Idx first
//// 아래는 arr을 위한 것
//#define inhaC first
//#define biryongC second
//#define price second
//#define maxNum 100000
//using namespace std;
//
//
//pair<int, int> arr[maxNum];
//bool unuseflag[maxNum];
//
//struct compareI {
//	bool operator()(pair<int, int>a, pair<int, int>b) {
//		if (a.price == b.price) {
//			return arr[a.Idx].biryongC < arr[b.Idx].biryongC;
//		}
//		return a.price < b.price;
//	}
//};
//struct compareB {
//	bool operator()(pair<int, int>a, pair<int, int>b) {
//		if (a.price == b.price) {
//			return arr[a.Idx].inhaC < arr[b.Idx].inhaC;
//		}
//		return a.price < b.price;
//	}
//};
//
//priority_queue<pair<int, int>,vector<pair<int,int>>, compareI> inha;
//priority_queue<pair<int, int>, vector<pair<int, int>>, compareB> biryong;
//
//void init() {
//	while (!inha.empty())
//		inha.pop();
//	while (!biryong.empty())
//		biryong.pop();
//	for (int i = 0; i < maxNum; i++) {
//		unuseflag[i] = true;
//		arr[i] = {};
//	}
//}
//int sameThings(bool turn) {
//	while (!unuseflag[(turn ? inha.top().Idx : biryong.top().Idx)] )
//		turn ? inha.pop() : biryong.pop();
//	int data = (turn ? inha.top().price : biryong.top().price);
//	unuseflag[(turn ? inha.top().Idx : biryong.top().Idx)] = false;
//	(turn ? inha.pop() : biryong.pop());
//	return data;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	cin >> n;
//	while (n--) {
//		init();
//		int N, x, y, in = 0, bi = 0;
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> x >> y;
//			arr[i] = { x, y };
//			inha.push({ i,x });
//			biryong.push({ i,y });
//		}
//
//		/*cout << "inha" << endl;
//		while (!inha.empty()) {
//			cout << inha.top().price << ' ' << inha.top().Idx <<endl;
//			inha.pop();
//		}
//		cout << "\nbiryong" << endl;
//		while (!biryong.empty()) {
//			cout << biryong.top().price << ' ' << biryong.top().Idx << endl;
//			biryong.pop();
//		}
//		cout << endl;*/
//
//		bool turn = true;
//		while (N--) {
//			int temp = sameThings(turn);
//			turn ? in += temp : bi += temp;
//			turn = !turn;
//		}
//		cout << in - bi << '\n';
//	}
//	return 0;
//}