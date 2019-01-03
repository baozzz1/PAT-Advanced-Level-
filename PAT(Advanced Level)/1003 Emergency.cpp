#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class Graph {
	typedef vector<vector<int>> bag;
public:
	Graph(int V);


private:
	int E, V;
	bag adj;
};

Graph::Graph(int V) {
	if (V < 0)
		return;
	this->V = V;
	this->E = 0;
	adj = bag(V);
	for (int v = 0; v < V; v++)
		adj[v] = vector<int>();
}

//Graph
int main() {
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	vector<int> rescueTeams(N);
	for (int i = 0; i < N; i++)
		cin >> rescueTeams[i];
	int c1, c2, L;
	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2 >> L;

	}
	return 0;
}