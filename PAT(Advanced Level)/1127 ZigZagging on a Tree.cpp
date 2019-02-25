#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Tree {
public:
	Tree(int N) :N(N) {
		inOrder = vector<int>(N);
		postOrder = vector<int>(N);
		levelOrder = vector<vector<int>>(30);
	}
	void read() {
		for (int i = 0; i < N; i++)
			scanf_s("%d", &inOrder[i]);
		for (int i = 0; i < N; i++)
			scanf_s("%d", &postOrder[i]);
	}
	void getPreOrder() {
		root = getPreOrder(inOrder.begin(), postOrder.begin(), N, root);
	}
	TreeNode* getPreOrder(const vector<int>::iterator &inBeg, const vector<int>::iterator &postBeg, const int &length, TreeNode *node) {
		if (length == 0) return NULL;
		int rootIndex = 0;
		while (rootIndex < length && *(inBeg + rootIndex) != *(postBeg + length - 1)) rootIndex++;
		node = new TreeNode(*(postBeg + length - 1));
		node->left = getPreOrder(inBeg, postBeg, rootIndex, node->left);
		node->right = getPreOrder(inBeg + rootIndex + 1, postBeg + rootIndex, length - rootIndex - 1, node->right);
		return node;
	}
	void DFS() {
		int depth = 1;
		DFS(root, depth);
	}
	void DFS(TreeNode *node,const int &depth) {
		if (node == NULL)return;
		DFS(node->left, depth + 1);
		DFS(node->right, depth + 1);
		levelOrder[depth].push_back(node->val);
		return;
	}
	void print() {
		bool flag = true;
		if (levelOrder[1].size() == 1)
			cout << levelOrder[1][0];
		for (int i = 2; i < 30; i++) {
			if (levelOrder[i].size() == 0)
				break;
			if (flag) {
				for (auto iter = levelOrder[i].begin(); iter != levelOrder[i].end(); ++iter)
					cout << " " << *iter;
				flag = false;
			}
			else {
				for (auto iter = levelOrder[i].rbegin(); iter != levelOrder[i].rend(); ++iter)
					cout << " " << *iter;
				flag = true;
			}
		}
	}
	int N;
	vector<int> inOrder, postOrder;
	TreeNode *root = NULL;
	vector<vector<int>> levelOrder;
};
// START 2019年2月25日22:53:21
//END 2019年2月25日23:44:45
int P1127() {
	int N; cin >> N;
	Tree trees(N);
	trees.read();
	trees.getPreOrder();
	trees.DFS();
	trees.print();

	return 0;
}