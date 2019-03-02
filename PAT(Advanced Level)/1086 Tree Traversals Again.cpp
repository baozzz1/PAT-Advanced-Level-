#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<stack>
using namespace std;
typedef vector<int>::iterator index;
vector<int> postOrder;
void recursive(const index &preBeg, const index &inBeg, const int &length) {
	if (length == 0) return;
	int rootIndex = 0;
	while (rootIndex < length && *preBeg != *(inBeg + rootIndex))	rootIndex++;
	recursive(preBeg + 1, inBeg, rootIndex);
	recursive(preBeg + rootIndex+1, inBeg+rootIndex+1, length -rootIndex - 1);
	postOrder.push_back(*preBeg);
}

int P1086() {
	int N; cin >> N;
	string read;
	stack<int> s;
	vector<int> inOrder;
	vector<int> preOrder;
	postOrder = vector<int>();
	int num;
	for (int i = 0; i < 2 * N; i++){
		cin >> read;
		if (read[1] == 'u') {
			cin >> num;
			s.push(num);
			preOrder.push_back(num);
		}
		else {
			num = s.top();
			inOrder.push_back(num);
			s.pop();
		}
	}
	recursive(preOrder.begin(), inOrder.begin(), N);
	cout << postOrder[0];
	for (int i = 1; i < postOrder.size(); i++)
		cout << " " << postOrder[i];

	return 0;
}