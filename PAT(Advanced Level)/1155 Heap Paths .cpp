#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

extern int N;
vector<int> tree;
vector<int> arr(1001);
bool isMin = true, isMax = true;
void dfs(int index) {
	if (index * 2 > N && index * 2 + 1 > N) {
		if (index <= N) {
			for (int i = 0; i < tree.size(); i++)
				printf("%d%s", tree[i], i != tree.size() - 1 ? " " : "\n");
		}
	}
	else {
		tree.push_back(arr[index * 2 + 1]);
		dfs(index * 2 + 1);
		tree.pop_back();
		tree.push_back(arr[index * 2]);
		dfs(index * 2);
		tree.pop_back();
	}
}

//START 2019年2月24日20:44:34
//END 2019年2月24日21:46:08
int P1155() {
	cin >> N;
	for (int i =1; i <= N; i++)
		scanf_s("%d", &arr[i]);
	tree.push_back(arr[1]);
	dfs(1);
	for (int i = 2; i <= N; i++) {
		if (arr[i / 2] > arr[i])	isMin = false;
		if (arr[i / 2] < arr[i])	isMax = false;
	}
	if (isMin)
		cout << "Min Heap";
	else if (isMax)
		cout << "Max Heap";
	else
		cout << "Not Heap";
	return 0;
}