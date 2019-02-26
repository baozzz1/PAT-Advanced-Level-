#include<iostream>
#include<vector>
using namespace std;

class solution {
public:
	typedef vector<int>::const_iterator index;
	solution(int N) :N(N) {
		preOrder = vector<int>(N);
		inOrder = vector<int>(N);
	}
	void read() {
		for (int i = 0; i < N; i++)
			cin >> preOrder[i];
		for (int i = 0; i < N; i++)
			cin >> inOrder[i];
	}
	void transform() {
		transform(preOrder.cbegin(), inOrder.cbegin(), N);
	}
	void answer() {
		cout << postOrder[0];
	}
private:
	void transform(const index &preBeg,const index &inBeg, const int &length){
		if (postOrder.size() != 0) return;
		if (length == 0) return;
		int rootIndex = 0;
		while (rootIndex < length && *preBeg != *(inBeg + rootIndex)) rootIndex++;
		transform(preBeg + 1, inBeg, rootIndex);
		transform(preBeg + rootIndex + 1, inBeg + rootIndex + 1, length - rootIndex - 1);
		postOrder.push_back(*preBeg);
	}

	int N;
	vector<int> preOrder, inOrder;
	vector<int> postOrder;
};

int P1138() {
	int N; cin >> N;
	solution solut(N);
	solut.read();
	solut.transform();
	solut.answer();
	return 0;
}