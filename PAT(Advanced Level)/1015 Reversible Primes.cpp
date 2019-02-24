#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(const int &n) {
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 6 != 1 && n % 6 != 5)
		return false;
	for (int i = 5; i <= sqrt((float)n); i += 6)
		if (n%i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

int transform(int N, int D) {
	int temp;
	int res = 0;
	while (N) {
		temp = N % D;
		res *= D;
		res += temp;
		N /= D;
	}
	return res;
}
// 2019年2月19日22:45:50		START
// 2019年2月19日23:14:14		18分
// 2019年2月19日23:17:39		满分
// 最后得分点：1不是素数
int P1015() {
	int N, D;
	cin >> N;
	while (N > 0) {
		cin >> D;
		if (!isPrime(N)) {
			cout << "No" << endl;
		}
		else if(!isPrime(transform(N, D)))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		cin >> N;
	}
	return 0;
}