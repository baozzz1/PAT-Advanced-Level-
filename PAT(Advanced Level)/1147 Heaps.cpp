#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void getPostOrderR(int index, const vector<int> &trees) {
	if (index >= trees.size()) return;
	getPostOrderR(index * 2, trees);
	getPostOrderR(index * 2 + 1, trees);
	cout << trees[index] << ((index == 1) ? "\n" : " ");
}

void getPostOrder(const vector<int> &trees) {
	getPostOrderR(1, trees);
}

int P1147() {
	int M, N; cin >> M >> N;

	for (int i = 0; i < M; i++) {
		// 2: Max Heap
		// 1: Min Heap
		// 0: Nothing
		// -1:don't konw so far
		int answer = -1;
		//LevelOrder
		vector<int> trees(N + 1);
		for (int j = 1; j <= N; j++)
			cin >> trees[j];
		if (trees[1] > trees[2])// maybe Max Heap
			answer = 2;
		else if (trees[1] < trees[2])
			answer = 1;

		for (int k = 2; k <= N; k++) {
			if (answer == -1) {
				if (trees[k/2] > trees[k])// maybe Max Heap
					answer = 2;
				else if (trees[k/2] < trees[k])
					answer = 1;
			}
			else if (answer == 1) {
				if (trees[k / 2] > trees[k])
					answer = 0;
			}
			else if (answer == 2) {
				if (trees[k / 2] < trees[k])
					answer = 0;
			}
			else
				break;
		}
		if (answer == 0)
			cout << "Not Heap";
		else if (answer == 1)
			cout << "Min Heap";
		else if (answer == 2)
			cout << "Max Heap";
		cout << endl;
		getPostOrder(trees);
	}
	return 0;
}