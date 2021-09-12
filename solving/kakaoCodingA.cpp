#include<iostream>
#include <string>
#include <vector>
#include<set>

using namespace std;
vector<pair<string, string>> reportPair;
// 0. 중복 신고는 무시한다. (set)
// 1. 신고 횟수를 누적한다.
// 2. 정지 횟수를 각기 카운트한다.
// 3. 그리고 이를 신고한  (first) 신고자를 findIndex를 통해 가져온다.
// 4. 해당 Index들은 1회씩 증진
vector<string> find(string name) {
    vector<string> Idx;
    for (int i = 0; i < reportPair.size(); i++) {
        if (reportPair[i].second == name) {
            Idx.push_back(reportPair[i].first);
        }
    }
    return Idx;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    set<string> sets;
    for (auto iter = report.begin(); iter != report.end(); iter++) 
        sets.insert(*iter);
    vector<int> answer(id_list.size());
    vector<int> accumulate(id_list.size()); //만일 run error 난다면 배열로 변경
    vector<string> stopName;
    for (auto iter = sets.begin(); iter != sets.end(); iter++) {
        size_t temp = (*iter).find(' ');
        string first = (*iter).substr(0, temp);
        string second = (*iter).substr(temp + 1, (*iter).size());
        for(int i = 0;i <id_list.size();i++)
            if (second == id_list[i]) {
                accumulate[i]++;
                break;
            }

        reportPair.push_back({ first,  second });
    }
    for (int i = 0; i < id_list.size(); i++)
        if (accumulate[i] >= k)
            stopName.push_back(id_list[i]);
    for (auto iter = stopName.begin(); iter != stopName.end(); iter++) {
        vector<string> temp = find(*iter);
        for (auto it = temp.begin(); it != temp.end(); it++) {
            for(int i = 0; i<id_list.size();i++)
                if(id_list[i] == (*iter))
                    answer[i]++;
        }
    }
    return answer;
}

int main() {
   // string arr[4] = ["muzi", "frodo", "apeach", "neo"];
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;
    vector<int> sets = solution(id_list, report, k);

    for (auto iter = sets.begin(); iter != sets.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}