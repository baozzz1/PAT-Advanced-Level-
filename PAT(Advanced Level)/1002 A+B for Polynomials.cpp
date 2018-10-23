#include<iostream>
#include<string>
#include<vector>
using namespace std;

int P1002() {
	// the first is the exponents, the second is coefficients
	vector<double> polynormials(1001,0);
	string res = "";
	for (int i = 0; i < 2; i++) {
		int K;
		cin >> K;
		int N;
		double aN;
		for (int j = 0; j < K; j++) {
			cin >> N >> aN;
			polynormials[N] += aN;
		}
	}
	int count = 0;
	for(int i=1000;i>=0;i--){
		if (polynormials[i] != 0) {
			count++;
		}
	}
	cout << count;
	if (count != 0) {
		for (int i = 1000; i >= 0; i--) {
			if (polynormials[i] != 0) {
				printf(" %d %.1f", i, polynormials[i]);
			}
		}
	}
	return 0;
}