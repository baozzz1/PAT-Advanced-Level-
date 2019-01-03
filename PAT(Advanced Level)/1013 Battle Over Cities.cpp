//2019Äê1ÔÂ3ÈÕ15:50:29
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class graph {
public:
	graph(int n) :V(n) {
		adj.resize(n);
	}

	void addEdge(const int &c1, const int &c2) {
		adj[c1].push_back(c2);
		adj[c2].push_back(c1);
		E++;
	}
	int V;
	int E;
	vector<vector<int>> adj;
	
};
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int i;
	int c1, c2;
	graph cities = graph(N);
	for (i = 0; i < M; i++) {
		cin >> c1 >> c2;
		cities.addEdge(c1 - 1, c2 - 1);
	}
	int target;
	for (i = 0; i < K; i++) {
		cin >> target;
		vector<bool> marked(N-1, false);
		auto *p = &cities.adj[target - 1];
		for (auto iter = p->cbegin(); iter != p->cend(); iter++) {

		}
	}
}