//#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxN = 1000;
vector<bool> isfound(maxN, false);
vector<vector<int>> G(maxN);
int N, M, K;
void DFS(int start) {
	isfound[start] = true;
	int t;
	for (int i = 0; i < G[start].size(); i++) {
		t = G[start][i];
		if (!isfound[t])
			DFS(t);
	}
}
int DFScount(const int &target) {
	isfound[target] = true;
	int count = -1;
	for (int i = 1; i <= N; i++) {
		if (!isfound[i]) {
			DFS(i);
			count++;
		}
	}
	return count;
}

//START	2019��2��17��23:53:48
//END	2019��2��18��01:15:39
//TIME	1h20min
//���˷��֣���������϶�������ʹ��<cstdio>��scanf�����Ա�ʹ��iostream��cin��ܶ࣬��200ms��ʱ������160ms
int P1013() {
	//N is the total number of cities,
	//M is the number of remaining highways,
	//K is the number of cities to be checked.
	//cin >> N >> M >> K;
	scanf_s("%d %d %d", &N, &M, &K);
	int i;
	int city1, city2, city_TOBEchecked;
	for (i = 0; i < M; i++) {
		scanf_s("%d %d", &city1, &city2);
		//cin >> city1 >> city2;
		G[city1].push_back(city2);
		G[city2].push_back(city1);
	}
	for (i = 0; i < K; i++) {
		//cin >> city_TOBEchecked;
		scanf_s("%d", &city_TOBEchecked);
		//OUTPUT
		//cout << DFScount(city_TOBEchecked) << endl;
		printf("%d\n", DFScount(city_TOBEchecked));
		fill(isfound.begin(), isfound.end(), false);
	}

	return 0;
}