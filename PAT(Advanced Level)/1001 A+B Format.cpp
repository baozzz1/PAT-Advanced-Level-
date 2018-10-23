#include<iostream>
#include<vector>
using namespace std;

int P1001() {
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	if (c < 0) {
		cout << '-';
		c = abs(c);
	}
	vector<char> res;
	int temp = 0;
	while (c) {
		res.push_back(c % 10 + '0');
		c /= 10;
		temp++;
		if (temp == 3 && c != 0) {
			res.push_back(',');
			temp = 0;
		}
	}
	if (res.size())
		for (int i = res.size() - 1; i >= 0; i--)
			cout << res[i];
	else
		cout << '0';
	return 0;
}