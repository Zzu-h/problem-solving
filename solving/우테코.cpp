#include <string>
#include <vector>
#include< iostream >
#include<map>
using namespace std;


int arr[1001][1001] = { 0, };
int x = 1, y = 1;
int recently = 1;
int checkX = 0, checkY = 0;
vector<vector<int>> solution(int rows, int columns) {
    int mins = min(rows, columns);
    int maxs = max(rows, columns);
    bool flag = maxs % mins;
    vector<vector<int>> answer;
    //rows == y / col == x
    x = 0; y = 0; recently = 0;
    checkX = 0, checkY = 0;
    int checkArr[1001] = { 0, };
    if(flag)
        while(checkArr[0] == 0) {
            recently++;
            arr[x][y] = recently;
            for (size_t i = 0; i < rows; i++) {
                for (size_t k = 0; k < columns; k++)
                    if (arr[i][k] != 0) {
                        checkArr[0] = 1;
                    }
                    else {
                        checkArr[0] = 0;
                        break;
                    }
            }

            // 이동
            !(recently % 2)? x = ((x+1) % (rows)) : y = ((y+1) % (columns));
        }
    else {
        while (checkArr[0] == 0) {
            recently++;
            arr[x][y] = recently;
            for (size_t i = 0; i < rows; i++) {
                for (size_t k = 0; k < columns; k++)
                    if (arr[i][k] != 0) {
                        checkArr[0] = 1;
                    }
                    else {
                        checkArr[0] = 0;
                        break;
                    }
            }

            // 이동
            !(recently % 2) ? x = ((x + 1) % (rows)) : y = ((y + 1) % (columns));
            if (arr[x][y])
                break;
        }
    }
    for (size_t i = 0; i < rows; i++) {
        answer.push_back({});
        for (size_t k = 0; k < columns; k++)
            answer[i].push_back(arr[i][k]);
    }
    return answer;
}

int main() {

    vector<vector<int>> ans = solution(6, 12);
    for (size_t i = 0; i < ans.size(); i++) {
        for (size_t k = 0; k < ans[0].size(); k++)
            cout << ans[i][k] << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
}

// B
//int getTime(string str) {
//    int h = (str[0] - '0') * 10 + (str[1] - '0');
//    int m = (str[3] - '0') * 10 + (str[4] - '0');
//    return  60 * h + m;
//}
//string getStrTime(int t) {
//    int h = t / 60;
//    int m = t % 60;
//    string time = "";
//    time.push_back((h / 10 + '0')); time.push_back((h % 10 + '0'));
//    time.push_back((':'));
//    time.push_back((m / 10 + '0')); time.push_back((m % 10 + '0'));
//    return time;
//}
//string solution(vector<string> log) {
//    string answer = "";
//    int size = log.size();
//    size_t tot_time = 0;
//    vector<int> time;
//    bool flag = false;
//    for (size_t i = 0; i < size; i++) time.push_back(getTime(log[i]));
//
//    for (size_t i = 0; i < size; i++) {
//        if (flag) {
//            int gap = abs(time[i - 1] - time[i]);
//            if (gap >= 5) tot_time += gap > 105 ? 105 : gap;
//        }
//        flag = !flag;
//    }
//    return  getStrTime(tot_time);
//}

//C
//#include <map>
//
//using namespace std;
//#define m first
//#define p second
//
//int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
//    int answer = 0;
//    int material[26] = { 0, };
//    for (size_t i = 0; i < ings.size(); i++) material[ings[i][0] - 'a'] = stoi(ings[i].substr(2, ings[i].size() - 2));
//    map<string, pair<int, int>> menus;
//    for (size_t i = 0; i < menu.size(); i++) {
//        size_t k = 0;
//        string menu_name = "";
//        int menu_material = 0;
//        int price = 0;
//        for (; k < menu[i].size(); k++)
//            if (menu[i][k] == ' ') break;
//            else menu_name.push_back(menu[i][k]);
//        k++;
//        for (; k < menu[i].size(); k++)
//            if (menu[i][k] == ' ') break;
//            else menu_material += material[menu[i][k] - 'a'];
//        price = stoi(menu[i].substr(k, menu[i].size() - k));
//        menus.insert({ menu_name,{menu_material, price} });
//    }
//    for (size_t i = 0; i < sell.size(); i++) {
//        string name = "";
//        int count = 0;
//        size_t k = 0;
//        for (; k < sell[i].size(); k++)
//            if (sell[i][k] == ' ') break;
//            else name.push_back(sell[i][k]);
//        count = stoi(sell[i].substr(k, sell[i].size() - k));
//        auto temp = menus[name];
//        answer += ((temp.p - temp.m) * count);
//    }
//    return answer;
//}

// D
//#include <algorithm>
//using namespace std;
//
//vector<int> solution(string s) {
//    vector<int> answer;
//    int idx = 0;
//    answer.push_back(1);
//    for (size_t i = 0; i < s.size() - 1; i++) {
//        if (s[i] == s[i + 1]) answer[idx]++;
//        else {
//            answer.push_back(1);
//            idx++;
//        }
//    }
//    if (s[0] == *s.rbegin()) {
//        answer[0] += answer[idx];
//        answer.pop_back();
//    }
//    for (size_t i = 0; i < idx; i++)
//        cout << answer[i] << ' ';
//    cout << endl;
//    sort(answer.begin(), answer.end());
//    return answer;
//}

//E


//F
//#define go first
//#define arrive second
//int times;
//string name;
//const int start_time_Fri = 570, end_time_Fri = 1080;
//const int start_time_Mon = 780, end_time_Mon = 1080;
//
//int getTime(string str) {
//    bool flag = false;
//    if (str.substr(str.size() - 2, str.size()) == "PM") flag = true;
//    str.pop_back(); str.pop_back();
//    int temp = stoi(str) * 60;
//    if (flag) temp += 720;
//    return  temp;
//}
//pair<bool, int> goCheck(int goC) {
//    pair<bool, int> ret;
//    if (goC >= end_time_Fri) {
//        ret.first = true;
//        ret.second = 0;
//    }
//    else if (goC < end_time_Fri) {
//        if (goC >= start_time_Fri) {
//            if (goC >= end_time_Fri - times) {
//                ret.first = true;
//                ret.second = times - (end_time_Fri - goC);
//            }
//            else {
//                ret.first = false;
//                ret.second = 0;
//            }
//        }
//        else {
//            if (times >= (end_time_Fri - start_time_Fri)) {
//                ret.first = true;
//                ret.second = times - (end_time_Fri - start_time_Fri);
//            }
//        }
//    }
//    return ret;
//}
//pair<bool, int> comeCheck(int goC) {
//    pair<bool, int> ret;
//    if (goC <= start_time_Mon) {
//        ret.first = true;
//        ret.second = 0;
//    }
//    else {
//        if (goC <= end_time_Mon) {
//            if (goC <= end_time_Mon - times) {
//                ret.first = true;
//                ret.second = times - (end_time_Mon - goC);
//            }
//            else {
//                ret.first = false;
//                ret.second = 0;
//            }
//        }
//        else {
//            if (times >= (end_time_Mon - start_time_Mon)) {
//                ret.first = true;
//                ret.second = times - (end_time_Mon - start_time_Mon);
//            }
//        }
//    }
//    return ret;
//}
//
//string solution(double t, vector<vector<string>> plans) {
//    t *= 2; times = (int)t * 60; times / 2;
//    string answer = "";
//    vector < pair<string, pair<int, int>>> list;
//    for (size_t i = 0; i < plans.size(); i++) list.push_back({ plans[i][0], {getTime(plans[i][1]),getTime(plans[i][2])} });
//    int useTime = 0;
//    for (size_t i = 0; i < list.size(); i++) {
//        pair<bool, int> check1, check2;
//        // 가는날 체크
//        check1 = goCheck(list[i].second.go);
//        // 오는날 체크
//        check2 = comeCheck(list[i].second.arrive);
//        if (check1.first && check2.first && times >= check1.second + check2.second)
//            answer = list[i].first;
//    }
//    return answer;
//}