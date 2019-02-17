#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int P1011() {
	double maxN[3] = { 0 };
	int order[3];
	double temp;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j < 4; j++) {
			cin >> temp;
			if (temp > maxN[i]) {
				maxN[i] = temp;
				order[i] = j;
			}
		}
	double sum = (double)(maxN[0] * maxN[1] * maxN[2] * 0.65 - 1) * 2;
	for (int i = 0; i < 3; i++)
		switch (order[i]) {
		case 1:
			cout << "W "; break;
		case 2:
			cout << "T "; break;
		case 3:
			cout << "L "; break;
		}
	printf("%.2f", sum);

	return 0;
}