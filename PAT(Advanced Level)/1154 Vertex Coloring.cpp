#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;

struct graph {
	typedef map<int, set<int>> bag;
	graph(int E, int V) :E(E), V(V) {
	}
	int E, V;
	bag adj;
};

struct severalColor {
	severalColor(int N) {
		marks.resize(N);
		colors.resize(N);
	}
	bool dector(graph &G) {
		for (int s = 0; s < G.V; s++) {
			if (!marks[s])
				dfs(s, G);
			if (!isSevealColors)
				return false;
		}
		return true;
	}
	void dfs(int s, graph &G);

	vector<int> colors;
	vector<bool> marks;
	bool isSevealColors = true;
};


void severalColor::dfs(int s, graph &G) {
	if (!isSevealColors)
		return;
	marks[s] = true;
	for (auto w : G.adj[s]) {
		if (!marks[s])
			dfs(w, G);
		if (colors[w] == colors[s])
			isSevealColors = false;
	}
}

int P1154() {
	int N, M;
	cin >> N >> M;
	int v1, v2;
	graph G(M, N);
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		G.adj[v1].insert(v2);
		G.adj[v2].insert(v1);
	}
	int K;
	cin >> K;
	set<int> counts;
	severalColor sc(N);
	for (int i = 0; i < K; i++) {
		counts.clear();
		sc.isSevealColors = true;
		for (int j = 0; j < N; j++) {
			cin >> sc.colors[j];
			sc.marks[j] = false;
			counts.insert(sc.colors[j]);
		}
		//detect
		if (sc.dector(G))
			cout << counts.size() <<"-coloring"<< endl;
		else
			cout << "No" << endl;
	}

	return 0;
}