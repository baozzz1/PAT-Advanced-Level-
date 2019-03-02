#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;
//typedef unordered_map<int, unordered_map<int, bool>> chessMap;


//START 2019年3月1日23:42:49
//FINISH 2019年3月2日00:35:04
int P1128() {
	int K, N;
	//int num;
	cin >> K;
	//vector<vector<int>> chessboard;
	//vector<int> chessboard;
	//chessMap chessboard;
	vector<int> board;
	for (int i = 0; i < K; i++) {
		cin >> N;
		//chessboard = vector<vector<int>>(N, vector<int>(N, 0));
		//chessboard.clear();
		bool isQueen = true;
		board = vector<int>(N + 1, 0);
		vector<bool> LeftLeft(N + 1);
		vector<bool> LeftRight(N);
		vector<bool> RightBelow(N);
		vector<bool> RightUpper(N + 1);
		set<int> row;
		for (int j = 1; j <= N; j++) {
			cin >> board[j];
			row.insert(board[j]);
		}
		if (row.size() < N)
			isQueen = false;
		else
		for (int j = 1; j <= N; j++) {
			if (board[j] >= j) {//左斜左边情况
				if(LeftLeft[board[j]]){
					isQueen = false;
					break;
				}
				LeftLeft[board[j]] = true;
			}
			else {
				if (LeftRight[N - (j - board[j])]) {
					isQueen = false;
					break;
				}
				LeftRight[N - (j - board[j])]=true;//左斜右边情况
			}
			if (board[j] < N - j) {
				if (RightBelow[board[j] + j - 1]) {
					isQueen = true;
					break;
				}
				RightBelow[board[j] + j - 1]=true;//右斜下边情况
			}
			else {
				if (RightUpper[board[j] + j - N]) {
					isQueen = false;
					break;
				}
				RightUpper[board[j] + j - N] =true;
			}
		}
		if(isQueen)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}