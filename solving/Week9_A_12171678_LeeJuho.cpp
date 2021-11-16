//#include <iostream>
//#define maxNum 1000
//typedef unsigned int ll;
//using namespace std;
//int T;
//ll X, N, M;
//// °ø½Ä : X(X^(N-1) - 1)/(X-1)
//ll mypow(ll base, ll exp) {
//    ll res = 1;
//    while (exp) {
//        if (exp & 1)
//            res *= base;
//        exp >>= 1;
//        base *= base;
//    }
//    return res;
//}
//ll mypow2(ll b, ll n, ll mod) {
//    ll x = 1, power = b % mod;
//
//    while (n) {
//        if (n%2 == 1) {
//            x = (x * power) % mod;
//        }
//        power = (power * power) % mod;
//        n >>= 1;
//    }
//    return x;
//}
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin >> T;
//    while (T--) {
//        cin >> X >> N >> M;
//        cout << mypow2(X, N, M) << endl;
//        ll ans = (X * (mypow2(X, N + 1, M) - 1) % M) / (X - 1) % M;
//        cout << ans << '\n';
//    }
//    return 0;
//}
#include <cstdio>
typedef long long ll;
int T;
ll aa, r, mod, n;
ll modulo(ll a, ll b) {
	ll sum = 1;

	while (b) {
		if (b % 2) sum = sum * a % mod;
		a = a * a % mod;
		b /= 2;
	}

	return sum;
}

ll go(ll x) {
	if (!x) return 1;
	if (x == 1) return (r + 1) % mod;
	if (x % 2) return go(x / 2) * (1 + modulo(r, x / 2 + 1)) % mod;
	return (go(x / 2 - 1) * (1 + modulo(r, x / 2)) % mod + modulo(r, x) % mod) % mod;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf(" %lld %lld %lld",  &r, &n, &mod);
		if (!mod) return !printf("0");
		printf("%lld\n", r * go(n - 1) % mod);
	}
	return 0;
}