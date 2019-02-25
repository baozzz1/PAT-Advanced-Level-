#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class BST {
public:
	void insert(const int &val) {
		root = insert(val, root);
	}
	TreeNode *insert(const int &val, TreeNode *node) {
		if (node == NULL) {
			return new TreeNode(val);
		}
		if (val <= node->val)
			node->left = insert(val, node->left);
		else
			node->right = insert(val, node->right);
		return node;
	}
private:
	TreeNode *root = NULL;

};
//START 2019Äê2ÔÂ24ÈÕ23:04:34
int main() {
	int N; cin >> N;
	vector<int> vec(N);
	BST bst;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &vec[i]);
		bst.insert(vec[i]);
	}

	return 0;
}