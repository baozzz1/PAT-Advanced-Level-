#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct graph {
	graph(int nv, int ne) :Nv(nv), Ne(ne) {
		adj = vector<set<int>>(Nv + 1);
	}
	void insert(const int &c1, const int &c2) {
		adj[c1].insert(c2);
		adj[c2].insert(c1);
	}
	void check(const vector<int> &kNums, const int &K) {
		int i, j;
		set<int> toCheck;
		for (i = 0; i < K; i++) {
			for (j = i + 1; j < K; j++) {
				if (adj[kNums[i]].find(kNums[j]) == adj[kNums[i]].end()) {
					cout << "Not a Clique" << endl;
					return;
				}
			}
			toCheck.insert(kNums[i]);
		}
		temp = vector<int>(Nv + 1, 0);
		for (i = 0; i < K; i++) {
			for (auto iter = adj[kNums[i]].begin(); iter != adj[kNums[i]].end(); ++iter) {
				if (toCheck.find(*iter) != toCheck.end())
					continue;
				temp[*iter]++;
			}
		}
		for (i = 1; i <= Nv; i++) {
			if (temp[i] == K) {
				cout << "Not Maximal" << endl;
				return;
			}
		}
		cout << "Yes" << endl;
		return;
	}
	vector<set<int>> adj;
	vector<int> temp;
	int Nv, Ne;
};

// 可以再建一个vector<int>(Nv+1)表记录它们的邻接元素个数，如果个数等于K个，说明还可以扩增，则不为Max Clique
int P1142() {
	int Nv, Ne;
	cin >> Nv >> Ne;
	graph G(Nv, Ne);
	int v1, v2;
	for (int i = 0; i < Ne; i++) {
		cin >> v1 >> v2;
		G.insert(v1, v2);
	}
	int M; cin >> M;
	int K;
	vector<int> getIn;
	for (int i = 0; i < M; i++) {
		cin >> K;
		getIn = vector<int>(K);
		for (int j = 0; j < K; j++)
			cin >> getIn[j];
		G.check(getIn, K);
	}
	return 0;
}
