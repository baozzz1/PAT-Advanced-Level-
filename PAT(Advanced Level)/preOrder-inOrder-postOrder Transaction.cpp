#include<iostream>
#include<vector>
using namespace std;
//class TreeNode {
//public:
//	int val;
//	TreeNode *left, *right;
//	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
//};

typedef vector<int>::iterator index;

// 已知前序，中序，求后序（唯一）的迭代方法
vector<int> postRes;
void getPostOrder(const index &preBeg, const index &inBeg, const int &length) {
	if (length == 0) return;
	int rootIndex = 0;
	while (rootIndex < length && *(inBeg + rootIndex) != *preBeg) rootIndex++;
	//Left
	getPostOrder(preBeg + 1, inBeg, rootIndex);
	//Right
	getPostOrder(preBeg + rootIndex + 1, inBeg + rootIndex + 1, length - rootIndex - 1);
	postRes.push_back(*preBeg);
}

//已知后序，中序，求前序（唯一）的迭代方法
vector<int> preRes;
void getPreOrder(const index &inBeg, const index &postBeg, const int &length) {
	if (length == 0) return;
	int rootIndex = 0;
	while (rootIndex < length && *(inBeg + rootIndex) != *(postBeg + length - 1)) rootIndex++;
	preRes.push_back(*(postBeg + length - 1));
	//Left
	getPreOrder(inBeg, postBeg, rootIndex);
	//Right
	getPreOrder(inBeg + rootIndex + 1, postBeg + rootIndex, length - rootIndex - 1);
}

//已知前序、后序，求中序（可能不唯一）的迭代方法
vector<int> inRes;
bool unique = true;
void getInOrder(const index &preBeg, const index &postBeg, const int &length) {
	if (length == 0) return;
	if (*preBeg == *(postBeg + length - 1)) {
		int rightIndex = 1;
		while (rightIndex < length && *(preBeg + rightIndex) != *(postBeg + length - 2)) rightIndex++;
		if (rightIndex > 1) {
			//Left
			getInOrder(preBeg + 1, postBeg, rightIndex - 1);
		}
		else
			unique = false;
		inRes.push_back(*preBeg);
		//Right
		getInOrder(preBeg + rightIndex, postBeg + rightIndex - 1, length - rightIndex);
	}
}

int test() {
	vector<int> pre = { 4,2,1,3,6,5,7 };
	vector<int> in = { 1,2,3,4,5,6,7 };
	vector<int> post = { 1,3,2,5,7,6,4 };

	getPostOrder(pre.begin(), in.begin(), 7);
	getPreOrder(in.begin(), post.begin(), 7);
	getInOrder(pre.begin(), post.begin(), 7);
	return 0;
}
