#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxNum 1000000001
bool arr[maxNum] = { 0, };
bool compare(pair<int, int> *a, pair<int, int>*b) {
    if ((*a).first == (*b).first)
        return (*a).second < (*b).second;
    return (*a).first < (*b).first;
}
int minimumDivision(vector<int> a, vector<int> b, int k) {
    int size = a.size();
    vector<pair<int, int>*> list, list2;
    bool flag = false;
    for (size_t i = 0; i < size; i++) {
        list.push_back(new pair<int, int>{ a[i], b[i] });
    }
    sort(list.begin(), list.end(), compare);
    for (size_t i = 0; i < size; i++) {
        cout << (*list[i]).first << ' ' << (*list[i]).second << endl;
    }
    list2.push_back(list[0]);
    int idx = 0;
    for (size_t i = 1; i < size; i++) {
        if ((*list[i]).first <= (*list2[idx]).second) {
            if ((*list[i]).second > (*list2[idx]).second)
                (*list2[idx]).second = (*list[i]).second;
        }
        else { list2.push_back(list[i]); idx++; }
    }

    for (size_t i = 1; i < list2.size(); i++) {
        if ((*list2[i]).first - (*list2[i - 1]).second <= k) {
            flag = true;
        }
    }
    return flag ? list2.size() - 1 : list2.size();
}
int main() {
    cout << minimumDivision({ 1,2,5,10, 1 }, { 2,4,8,11, 7 }, 2) << endl;
    return 0;
}