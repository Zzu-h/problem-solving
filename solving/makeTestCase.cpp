#include <iostream>
#include <fstream>
#include <time.h>
#include <set>
using namespace std;
#define endl '\n'

#define MAX_VAL 1000000 
#define MIN_VAL 1
#define SEED 154164 

unsigned int id, space, price, tempSize, cmdSize;
string name;

#define MOD_NUM (MAX_VAL + 1 - MIN_VAL)
unsigned int PRNG_1() {
    static unsigned int seed = SEED;
    seed = 8253729 * seed + 2396403;
    return (seed % MOD_NUM) + MIN_VAL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    bool flag = true;
    string filePath = "../../in.in";
    set<pair<int, int > > list;
    // write File
    ofstream writeFile(filePath.data());
    if (writeFile.is_open()) {
        srand(time(NULL));
        if (flag) {
            int n = 10000, q = 5, m = (PRNG_1() * rand() % 10000) + 1;;
            writeFile << n << ' ' << m << ' ' << q << '\n';
            int a = 1, b = 1, e = 0;
            a = (PRNG_1() * rand() % 10000) + 1;
            while (b == a)
                b = (PRNG_1() * rand() % 10000) + 1;
            for (int i = 1; i <= n; i++) {
                pair<int, int > temp = { a,b };
                while (list.find(temp) != list.end()) {
                    a = (PRNG_1() * rand() % 10000) + 1;
                    b = (PRNG_1() * rand() % 10000) + 1;
                    while (b == a)
                        b = (PRNG_1() * rand() % 10000) + 1;
                    temp = { a,b };
                }
                list.insert({ a, b });
                e = (PRNG_1() * rand() % 10000) + 1;
                writeFile << a << ' ' << b << ' ' << e << '\n';
            }
            for (int i = 1; i <= m; i++) {
                    a = (PRNG_1() * rand() % 10000) + 1;
                    b = (PRNG_1() * rand() % 10000) + 1;
                writeFile << a << ' ' << b << '\n';
            }
            cout << "end";
        }
        else {
            int n = 10000, q = 5, m = 10000;
            writeFile << n << ' ' << m << ' ' << q << '\n';
            int a = 1, b = 1, e = 0;
            a = (PRNG_1() * rand() % 10000) + 1;
            while (b == a)
                b = (PRNG_1() * rand() % 10000) + 1;
            for (int i = 1; i <= 10000; i++) {
                pair<int, int > temp = { a,b };
                while (list.find(temp) != list.end() || list.find(temp) != list.end()) {
                    a = (PRNG_1() * rand() % 10000) + 1;
                    b = (PRNG_1() * rand() % 10000) + 1;
                    while (b == a)
                        b = (PRNG_1() * rand() % 10000) + 1;
                    temp = { a,b };
                }
                list.insert({ a, b });
                e = (PRNG_1() * rand() % 10000) + 1;
                writeFile << a << ' ' << b << ' ' << e << '\n';
            }
            int counter = 0;
            for (auto iter = list.begin(); iter != list.end() && counter <= 6; iter++, counter++)
                if ((PRNG_1() * rand() % 10001) % 2)
                    writeFile << 'P' << ' ' << (*iter).second << '\n';
            cout << "end";
        }
        writeFile.close();
    }

    return 0;
}
