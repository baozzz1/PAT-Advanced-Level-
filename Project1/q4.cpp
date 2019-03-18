#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, H;
vector<int> x, y, z;
int maxE;
void dfs(const int &index,const int &blood,const int &exp) {
	if (index >= N || blood<=0) {
		if (exp > maxE) {
			maxE = exp;
		}
		return;
	}
	dfs(index + 1, blood - z[index], exp);
	dfs(index + 1, blood - x[index], exp + y[index]);
}


int main() {
	cin >> N >> H;
	x = vector<int>(N);
	y = vector<int>(N);
	z = vector<int>(N);
	int exp = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &x[i], &y[i], &z[i]);
	}
	maxE = 0;
	dfs(0, H, 0);
	cout << maxE;
	return 0;
}