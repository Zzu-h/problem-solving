#include <iostream>
using namespace std;

int N, A, B, X, Y, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> A >> B >> X >> Y;
		int GCD = abs(A - B), minGap, minus, cost, gcds = 0;
		a = min(A, B);
		b = max(A, B);

		cost = (GCD - b % GCD) * X;
		if(min (a,b) >= GCD)
			cost = min(cost, (b%GCD)*Y);
		
		cout << GCD << ' ' << cost << '\n';
	}
	return 0;
}

//#include <iostream>
//#define INT_MAX 2147483647
//using namespace std;
//
//int N, A, B, X, Y;
//int gcd(int a, int b){
//	int c;
//	while (b != 0)
//	{
//		c = a % b;
//		a = b;
//		b = c;
//	}
//	return a;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cin >> N;
//    while (N--) {
//        cin >> A >> B >> X >> Y;
//		int a, b, x = 0, y = 0, curGCD = gcd(A, B) , maxGcd = 0, minPrice, GcdX = 0, GcdY = 0;
//		a = A; b = B;
//		while (1) {
//			//위로
//			x += X;
//			a++; b++;
//			if (curGCD < (GcdX = gcd(a, b))) 
//				break;
//		}
//		a = A; b = B;
//		while (1) {
//			//아래로
//			y += Y;
//			a--; b--;
//			if (a == 0 || b == 0) {
//				//y = INT_MAX;
//				GcdY = INT_MAX;
//				break;
//			}
//			if (curGCD < (GcdY = gcd(a, b)))
//				break;
//		}
//
//		if (GcdX > GcdY) {
//			minPrice = x;
//			maxGcd = GcdX;
//		}
//		else if (GcdX == GcdY) {
//			minPrice = min(x, y);
//			maxGcd = GcdX;
//		}
//		else {
//			minPrice = y;
//			maxGcd = GcdY;
//		}
//		cout << maxGcd << ' ' << minPrice << '\n';
//    }
//    return 0;
//}