#include<iostream>
#include<set>
using namespace std;
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};
struct compare2 {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        return a.second < b.second;
    }
};
int N, K, M, time = 0;
bool top_down = true;
pair<int,int> a;
multiset< pair<int, int>, compare> wating;
multiset< pair<int, int>, compare2> elevator;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        cin >> a.first >> a.second;
        wating.insert(a);
    }
    while (!(wating.empty()  && elevator.empty())) {
        for (int k = 1; k <= K; k++) {
            // 1. elvator Ȯ�� �� �ش� ���� ���� ��� �ִ��� üũ ������ ����
            while (!elevator.empty()) {
                auto iter = elevator.begin();
                if ((*iter).second != k)
                    break;
                elevator.erase(iter);
            }
            // 2. ���� elevator�� ž�� �ο��� �ִ� �ο� �� M���� ���� ��� �ش� ���� �ο��� ����
            while (elevator.size() < M) {
                auto iter = wating.begin();
                if (wating.empty() || (*iter).first != k)
                    break;
                elevator.insert((*iter));
                wating.erase(iter);
            }
            if (wating.empty() && elevator.empty()) {
                cout << time << '\n';
                return 0;
            }
            time++;
        }
        for (int k = K-1; k > 1; k--) {
            // 1. elvator Ȯ�� �� �ش� ���� ���� ��� �ִ��� üũ ������ ����
            while (!elevator.empty()) {
                auto iter = elevator.end();
                iter--;
                if ((*iter).second != k)
                    break;
                elevator.erase(iter);
            }
            // 2. ���� elevator�� ž�� �ο��� �ִ� �ο� �� M���� ���� ��� �ش� ���� �ο��� ����
            while (elevator.size() < M) {
                if (wating.empty())
                    break;
                auto iter = wating.end();
                iter--;
                if ((*iter).first != k)
                    break;
                elevator.insert((*iter));
                wating.erase(iter);
            }
            if (wating.empty() && elevator.empty()) {
                cout << time << '\n';
                return 0;
            }
            time++;
        }
    }
    cout << time << '\n';
    return 0;
}