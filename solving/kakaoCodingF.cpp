#include<iostream>

#include <string>
#include <vector>
#define maxNum 1000
using namespace std;
int arr[maxNum][maxNum];

void setMap(int y1, int x1, int y2, int x2, int degree) {
    for (int x = x1; x <= x2; x++)
        for (int y = y1; y <= y2; y++)
            arr[x][y] += degree;
}
void init() {
    for (int x = 0; x <maxNum; x++)
        for (int y =0; y <maxNum; y++)
            arr[x][y] = 0;
}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    init();
    int answer = 0;
    for (int i = 0; i < skill.size(); i++) {
        int attack = skill[i][5];
        attack = (skill[i][0] - 1) ? attack : (-1 *  attack);
        setMap(skill[i][1], skill[i][2], skill[i][3], skill[i][4], attack);
    }

    int xsize = board.size();
    int ysize = board[0].size();
    for (int x = 0; x < xsize; x++) 
        for (int y = 0; y < ysize; y++) 
             if (arr[y][x] <= 0)
                 if ((board[x][y] + arr[y][x]) <= 0)
                     answer++;

    return (xsize*ysize) - answer;
}


int main() {
    vector<vector<int>> board = { {5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{ 5, 5, 5, 5, 5} };
    vector<vector<int>> skill = { {1, 0, 0, 3, 4, 4},{1, 2, 0, 2, 3, 2},{2, 1, 0, 3, 1, 2},{1, 0, 1, 3, 3, 1} };
    //vector<vector<int>> board = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    //vector<vector<int>> skill = { {1, 1, 1, 2, 2, 4}, {1, 0, 0, 1, 1, 2}, {2, 2, 0, 2, 0, 100} };
    cout << solution(board, skill) << endl;
    return 0;
}