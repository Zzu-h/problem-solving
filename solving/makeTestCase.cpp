#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
#define endl '\n'

#define MAX_VAL 1000000 
#define MIN_VAL 1
#define SEED 154164 

unsigned int id, space, price, tempSize, cmdSize;
string name;

#define MOD_NUM (MAX_VAL + 1 - MIN_VAL)
char cmds[] = { 'I','I','I','I','I','I','I','I','I','I','I','I', 'F', 'R', 'D' };
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

    string filePath = "../../in.in";

    // write File
    ofstream writeFile(filePath.data());
    if (writeFile.is_open()) {
        srand(time(NULL));
        char cmd;
        unsigned int temp = sizeof(cmds) / sizeof(char);
        cmdSize = PRNG_1()*rand() % 100000;
        cout << cmdSize << '\n';
        writeFile << cmdSize << '\n';
        for (int i = 1; i <= cmdSize; i++) {
            cmd = cmds[PRNG_1() % temp];
            writeFile << cmd << ' ';
            switch (cmd) {
            case 'I':	// insert app
                id = 1000000 + (PRNG_1() * rand() % 1000000);
                space = 1 + (PRNG_1() * rand() % 10000);
                price = (PRNG_1() * rand() % 1000);
                name = "";
                tempSize = PRNG_1() * rand() % 15+1;
                for (size_t k = 0; k < tempSize; k++)
                    name.push_back('a' + (PRNG_1() * rand() % 26));
                writeFile << id << ' ' << name << ' ' << space << ' ' << price << '\n';
                break;
            case 'F':	// find app
                id = 1000000 + (PRNG_1() * rand() % 1000000);
                writeFile << id << '\n';
                break;
            case 'R':	// update app
                id = 1000000 + (PRNG_1() * rand() % 1000000);
                space = 1 + (PRNG_1() * rand() % 10000);
                price = (PRNG_1() * rand() % 1000);
                name = "";
                tempSize = PRNG_1() * rand() % 15 + 1;
                for (size_t k = 0; k < tempSize; k++)
                    name.push_back('a' + (PRNG_1() * rand() % 26));
                writeFile << id << ' ' << name << ' ' << space << ' ' << price << '\n';
                break;
            case 'D':	// discount
                id = 1000000 + (PRNG_1() * rand() % 1000000);
                space = 1000000 + (PRNG_1() * rand() % 1000000);
                while (space == id) space = 1000000 + (PRNG_1() * rand() % 1000000);
                price = (PRNG_1() * rand() % 100);
                if (id > space) swap(id, space);
                writeFile << id << ' ' << space << ' ' << price << '\n';
                break;
            default:
                break;
            }
        }
        writeFile.close();
    }

    return 0;
}
