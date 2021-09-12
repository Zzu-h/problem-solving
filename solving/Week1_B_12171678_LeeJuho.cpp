//#include<iostream>
//#include<vector>
//using namespace std;
//int n,min_, max_;
//vector<int> tops;
//
//void init(){
//    min_ = 100001;
//    max_ = -1;
//    tops.clear();
//}
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin>> n;
//    while(n--){
//        init();
//      int ques, type;
//      cin>> ques;
//      while(ques--){
//          cin>>type;
//          if(type == 1){
//              int x;
//              cin>>x;
//              min_ = min(x,min_);
//              max_ = max(x,max_);
//              tops.push_back(x);
//              cout<<min_<< ' '<<max_<<'\n';
//          }
//          else if(type == 2){
//              if(!tops.empty()){
//                    tops.pop_back();
//                        min_ = 100001;
//                        max_ = -1;
//                    for(int i = 0; i< tops.size();i++){
//                        min_ = min(tops[i],min_);
//                        max_ = max(tops[i],max_);
//                    }
//              }
//          }
//      }
//    }
//}

#include<iostream>
#include<stack>
#include<set>
using namespace std;

stack<int> datas;
multiset<int, less<>> aligns;
int k, s, dels, c;

void init() {
	aligns.clear();
	while (!datas.empty())
		datas.pop();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		cin >> c;
		while (c--) {
			cin >> k;
			switch (k)
			{
			case 1:
				cin >> s;
				datas.push(s);
				aligns.insert(s);
				cout << *aligns.begin() << ' ' << *(--aligns.end()) << '\n';
				break;
			case 2:
				if (datas.empty()) break;
				aligns.erase(aligns.find(datas.top()));
				datas.pop();
				break;
			default:
				break;
			}
		}
		init();
	}
	return 0;
}