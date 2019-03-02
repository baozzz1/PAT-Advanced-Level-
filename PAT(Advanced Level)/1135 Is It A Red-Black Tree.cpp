#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct Node1135 {
	int val;
	Node1135 *left, *right;
	bool isRED;
	Node1135(int x) :left(NULL), right(NULL){
		if (x < 0) {
			val = -x;
			isRED = true;
		}
		else {
			val = x;
			isRED = false;
		}
	}
};

struct RBT {
	typedef vector<Node1135*>::iterator index;
	RBT(int N) :root(NULL), N(N) {
		//blackNum = -1;
	}
	void getTree() {
		int num;
		for (int j = 0; j < N; j++) {
			cin >> num;
			insert(root,num);
		}
	}

	void insert(Node1135 * &node, int num) {
		if (node == NULL) node = new Node1135(num);
		else if (abs(num) < abs(node->val)) insert(node->left, num);
		else	insert(node->right, num);
	}

	//void getInOrder() {
	//	inOrder = preOrder;
	//	sort(inOrder.begin(), inOrder.end(), [](const Node *n1, const Node *n2) {return n1->val < n2->val; });
	//}

	bool check() {
		return check1() && check2();
	}

	bool check1() {
		if (root->isRED)
			return false;
		return checkDown1(root);
	}

	bool checkDown1(Node1135 *parent) {
		if (parent->isRED)
			if ((parent->left != NULL && parent->left->isRED) || (parent->right != NULL && parent->right->isRED))
				return false;

		bool isTrue = true;
		if (parent->left != NULL)
			isTrue &= checkDown1(parent->left);
		if (parent->right != NULL)
			isTrue &= checkDown1(parent->right);
		return isTrue;
	}

	//bool check() {
	//	if (root->isRED)
	//		return false;
	//	return checkDown(root, 0);
	//}

	//bool checkDown(Node *parent, int count) {
	//	if (!parent->isRED)
	//		count++;
	//	else
	//		if ((parent->left != NULL && parent->left->isRED) || (parent->right != NULL && parent->right->isRED))
	//			return false;

	//	bool isTrue = true;
	//	if (parent->left != NULL)
	//		isTrue &= checkDown(parent->left, count);
	//	if (parent->right != NULL)
	//		isTrue &= checkDown(parent->right, count);

	//	if (parent->left == NULL && parent->right == NULL) {
	//		//无孩
	//		if (blackNum == -1) {
	//			blackNum = count;
	//		}
	//		else {
	//			if (blackNum != count)
	//				return false;
	//		}
	//	}
	//	return isTrue;
	//}

	int getNum(Node1135 *node) {
		if (node == NULL) return 0;
		int leftNum = getNum(node->left);
		int rightNum = getNum(node->right);
		return (node->isRED ? 0 : 1) + max(leftNum, rightNum);
	}

	bool check2() {
		return checkDown2(root);
	}

	bool checkDown2(Node1135 *node) {
		if (node == NULL) return true;
		int leftNum = getNum(node->left);
		int rightNum = getNum(node->right);
		if (leftNum != rightNum) return false;
		return checkDown2(node->left) && checkDown2(node->right);

	}

	//void precuRoot() {
	//	//root = preOrder[0];
	//	precu(preOrder.begin(), inOrder.begin(), N, root);
	//	//root = preOrder[0];

	//}

	//void precu(const index &preBeg, const index &inBeg, const int &length, Node * &parent) {
	//	if (length == 0) return;
	//	parent = *preBeg;
	//	int rootIndex = 0;
	//	while (rootIndex < length && *preBeg != *(inBeg + rootIndex))	rootIndex++;
	//	precu(preBeg + 1, inBeg, rootIndex, parent->left);
	//	precu(preBeg + rootIndex + 1, inBeg + rootIndex + 1, length - rootIndex - 1, parent->right);
	//}

	Node1135 *root;
	int N;
	//vector<Node*> preOrder, inOrder;
	//int blackNum;
};

//START 2019年3月1日15:16:55
//PAUSE 2019年3月1日15:33:19
//GO ON 2019年3月1日15:38:03
//PAUSE 2019年3月1日15:48:41
//GO ON 2019年3月1日17:15:45
//END 2019年3月1日20:16:19	WRONG
//END FINISH 为防止“超限”，不使用数组
int P1135() {
	int K, N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N;
		RBT rbt(N);
		rbt.getTree();
		//rbt.getInOrder();
		//rbt.precuRoot();
		if (rbt.check())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}