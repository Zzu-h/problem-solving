﻿#include<iostream>
#include<algorithm>
#define maxNum 100000
#define inhaC first
#define biryongC second
using namespace std;

typedef pair<int, int> pairs;
pairs arr[maxNum];
bool useflag[maxNum];

bool compare(pairs a, pairs b) {
	if (a.inhaC == b.inhaC) 
		return a.biryongC > b.biryongC;
	return a.inhaC > b.inhaC;
}
void init() {
	for (int i = 0; i < maxNum; i++) {
		arr[0] = { 0,0 };
		useflag[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		//init();
		pairs arr[maxNum];
		bool useflag[maxNum] = { 0 ,};
		int N, in = 0, bi = 0, gap = 0;
		cin >> N;
		for (int i = 0; i < N; i++) 
			cin >> arr[i].inhaC >> arr[i].biryongC;
		sort(arr, arr + N, compare);

		bool turn = true;
		int  inhaIdx = 0, minIdx = 0;
		for (int k = 0; k < N; k++) {
			if (turn) {
				// inha turn
				while (useflag[inhaIdx]) {
					cout << useflag[inhaIdx] << endl;
					inhaIdx++;
				}
				in += arr[inhaIdx].inhaC;
				gap = in - bi;
				useflag[inhaIdx] = true;
				inhaIdx++;
			}
			else {
				// biryong turn
				int minGap = gap;
				for (int i = inhaIdx; i < N; i++) {
					//find min gap with inha
					if (useflag[i])
						continue;
					// 잘못 계산함
					int tempIn = in + arr[i == inhaIdx ? inhaIdx +1 : inhaIdx].inhaC, tempBi = bi + arr[i].biryongC;
					int tempGap = tempIn - tempBi;
					if (minGap > tempGap) {
						minIdx = i;
						minGap = tempGap;
					}
				}
				gap = minGap;
				bi += arr[minIdx].biryongC;
				useflag[minIdx] = true;
			}
			//cout << in << ' ' << bi << endl;
			turn = !turn;
		}
		cout << gap << endl;
	}
	return 0;
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

//#include<iostream>
//#include<queue>
//#define Idx first
//// 아래는 arr을 위한 것
//#define inhaC first
//#define biryongC second
//#define price second
//#define maxNum 100000
//using namespace std;
////평화적으로 자원을 나눠갖지만,
////상대 왕국이 큰 이득을 취하는 것은 원치 않기 때문에,
////각 자원을 나눠서 가진 후
////(자신의 왕국이 확보한 자원의 가치) –(상대방의 왕국이 확보한 자원의 가치)를 최대로 하려고 한다
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
//
///*cout << "inha" << endl;
//while (!inha.empty()) {
//	cout << inha.top().price << ' ' << inha.top().Idx <<endl;
//	inha.pop();
//}
//cout << "\nbiryong" << endl;
//while (!biryong.empty()) {
//	cout << biryong.top().price << ' ' << biryong.top().Idx << endl;
//	biryong.pop();
//}
//cout << endl;*/