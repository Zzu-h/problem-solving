#include<iostream>
using namespace std;
#define y_ 100
#define x_ 1000
char str_arr[y_][x_];

void init(){
    for(int i = 0; i<y_;i++)
        for(int k = 0; k<x_;k++)
            str_arr[i][k] = '\0';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>> n;
    while(n--){
        init();
        string str;
        int arr_n, i = 0, k = 0;
        int y = 0, x = 0;
        int index = 0;
        bool flag = true;
        cin>> str>>arr_n;
        while(index < str.size()){
            if(flag){
                for(k = 0; k<arr_n; k++){
                    str_arr[k][x] = str[index];
                    index++;
                    if(index >= str.size())
                        break;
                }
                flag = false;
            }
            else{
                for(k = arr_n-1; k >= 0; k--){
                    str_arr[k][x] = str[index];
                    index++;
                    if(index >= str.size())
                        break;
                }
                flag = true;
            }
            x++;
        }
        string ans = "";
        for(;i<arr_n;i++){
            index = 0;
            while(str_arr[i][index] != '\0'){
                ans.push_back(str_arr[i][index]);
                index++;
            }
        }
        cout<<ans<<'\n';
    }
}