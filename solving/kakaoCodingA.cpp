#include<iostream>
#include <string>
#include <vector>
#include<set>

using namespace std;
vector<pair<string, string>> reportPair;
// 0. �ߺ� �Ű�� �����Ѵ�. (set)
// 1. �Ű� Ƚ���� �����Ѵ�.
// 2. ���� Ƚ���� ���� ī��Ʈ�Ѵ�.
// 3. �׸��� �̸� �Ű���  (first) �Ű��ڸ� findIndex�� ���� �����´�.
// 4. �ش� Index���� 1ȸ�� ����
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
    vector<int> accumulate(id_list.size()); //���� run error ���ٸ� �迭�� ����
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