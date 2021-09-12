#include<iostream>

#include <string>
#include <vector>

#define bigNum 100000001
class primes {
public:
	bool primeNumber[bigNum];
	void setPrime() {
		for (int i = 2; i < bigNum; i++) {
			primeNumber[i] = true;
		}

		for (int i = 2; i < bigNum; i++) {
			if (!primeNumber[i]) continue;

			for (int j = 2 * i; j < bigNum; j += i) {
				primeNumber[j] = false;
			}
		}
	}
	primes() {
		setPrime();
	}
};

primes primeNumbers;

using ull = unsigned long long;
vector<ull> alist = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
inline ull addmod(ull x, ull y, ull m) {
	x %= m;
	y %= m;
	return (x >= m - y ? x - (m - y) : x + y);
}

// calculate (x * y) % m; overlow-safe
inline ull mulmod(ull x, ull y, ull m) {
	x %= m;
	y %= m;
	ull r = 0;
	while (y > 0) {
		if (y % 2 == 1)
			r = addmod(r, x, m);
		x = addmod(x, x, m);
		y /= 2;
	}
	return r;
}

ull powmod(ull x, ull y, ull m) {
	x %= m;
	ull r = 1ULL;
	while (y > 0) {
		if (y % 2 == 1)
			r = mulmod(r, x, m);
		x = mulmod(x, x, m);
		y /= 2;
	}
	return r;
}

// true for probable prime, false for composite
inline bool miller_rabin(ull n, ull a) {
	ull d = n - 1;
	while (d % 2 == 0) {
		if (powmod(a, d, n) == n - 1)
			return true;
		d /= 2;
	}
	ull tmp = powmod(a, d, n);
	return tmp == n - 1 || tmp == 1;
}

bool is_prime(ull n) {
	if (n <= 1)
		return false;
	if (n <= 10000000000ULL) {
		for (ull i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	for (ull a : alist)
		if (!miller_rabin(n, a))
			return false;
	return true;
}
long long power(long long x, long long y, long long mod) {
	long long res = 1;
	x %= mod;
	while (y) {
		if (y % 2) res = (res * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return res;
}
//if n is prime, return true
bool miller(long long n, long long a) {
	if (a % n == 0) return false;
	long long k = n - 1;
	while (1) {
		long long temp = power(a, k, n);
		if (temp == n - 1) return true; //a^k = -1 (mod n)
		if (k % 2) return (temp == 1 || temp == n - 1);
		k /= 2;
	}
}

using namespace std;

int solution(int n, int k) {
	int answer = 0;
	vector<short> trans;
	vector<unsigned long long> numbers;
	while (n != 0) {
		short i = n % k;
		trans.push_back(i);
		n /= k;
	}
	ull num = 0;
	for (auto i = trans.rbegin(); i != trans.rend(); i++) {
		if (*i == 0) { numbers.push_back(num); num = 0; }
		else {
			int m = 0;
			for (unsigned long long s = bigNum - 1; s >= 0; s++)
				if (primeNumbers.primeNumber[s]) {
					m = s;
					break;
				}
			num = addmod(mulmod(num, 10, m), *i, m);
		}
	}
	if (num != 0)
		numbers.push_back(num);
	for (auto i = 0; i < numbers.size(); i++) {
		if (numbers[i] >= bigNum - 1) {
			if (is_prime(numbers[i]))
				answer++;
		}
		else if (primeNumbers.primeNumber[numbers[i]])
			answer++;
	}
	return answer;
}

int main() {
    int n = 437674, k = 3;
    cout << solution(n, k) << endl;
    n = 110011, k = 10;
    cout << solution(n, k)<<endl;
    return 0;
}