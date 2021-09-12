#include<iostream>

#include <string>
#include <vector>

using namespace std;
int dp[12][100];
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int maxIdx = 0;
    for (int i = 0; i < 10; i++) {
        int count = n;
        int ap = 0;
        for(int k= 0; k< i;k++)
            ap += (10 - k);
        for (int k = i; k < 11; k++) {
            if (count - (info[k] + 1) < 0) {
                if(info[k]!=0)
                    ap += (10 - k);
                continue;
            }
            dp[k][i] = info[k] + 1;
            count -= (info[k] + 1);
            dp[11][i] += (10 - k);
        }
        dp[11][i] -= ap;
        if (dp[11][maxIdx] <= dp[11][i])
            maxIdx = i;
    }
    /*for (int k = 0; k < 5; k++){
         for (int i = 0; i < 12; i++)
            cout << dp[i][k] << ' ';
        cout << endl;
    }*/
    if (dp[11][maxIdx] <= 0) {
        answer.push_back(-1);
        return answer;
    }
    else {
        for (int k = 0; k < 11; k++)
            answer.push_back(dp[k][maxIdx]);
        return answer;
    }
}

int main() {
    /*vector<int> info = { 2,1,1,1,0,0,0,0,0,0,0 };
    int n = 5;*/
    vector<int> info = { 0,0,1,2,0,1,1,1,1,1,1 };
    int n = 9;
    vector<int> sets = solution(n, info);

    for (auto iter = sets.begin(); iter != sets.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}