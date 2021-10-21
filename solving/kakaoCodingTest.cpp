#include <iostream>
#include <vector>
#include<set>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    set<int> x;
    set<int> y;
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        auto xiter = x.find((*iter)[0]);
        auto yiter = y.find((*iter)[1]);
        if (xiter == x.end())
            x.insert((*iter)[0]);
        else
            x.erase(xiter);
        if (yiter == y.end())
            y.insert((*iter)[1]);
        else
            y.erase(yiter);
    }
    ans.push_back(*(x.begin()));
    ans.push_back(*(y.begin()));
    return ans;
}