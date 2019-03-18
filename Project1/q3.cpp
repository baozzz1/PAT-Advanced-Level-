#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;


int outEventNum, inEventNum;
long random(const long &last) {
	return  (last * 21401 + 25301) % 98765;
}

struct position {
	int x, y;
	position() {}
	position(int x, int y) :x(x), y(y) {}
};

int W, H, N, S, T;
vector<vector<int>> graph;
vector<position> players;

void moveProcess(const int &where,const int &playerIndex) {
	graph[players[playerIndex].x][players[playerIndex].y]--;
	int low, high;
	switch (where) {
	case 0:
		if (players[playerIndex].x > 0) {
			low = (players[playerIndex].y - S >= 0) ? players[playerIndex].y - S : 0;
			high = (players[playerIndex].y + S <= H - 1) ? players[playerIndex].y + S : H - 1;
			if (players[playerIndex].x + S <= W - 1)
				for (int k = low; k <= high; k++)
					outEventNum += (graph[players[playerIndex].x + S][k] * 2);
			if(players[playerIndex].x - S - 1 >= 0)
				for (int k = low; k <= high; k++)
					inEventNum += (graph[players[playerIndex].x - S - 1][k] * 2);
			players[playerIndex].x--;
		}
		graph[players[playerIndex].x][players[playerIndex].y]++;
		break;
	case 1:
		if (players[playerIndex].y < H - 1) {
			low = (players[playerIndex].x - S >= 0) ? players[playerIndex].x - S : 0;
			high = (players[playerIndex].x + S <= W - 1) ? players[playerIndex].x + S : W - 1;
			if (players[playerIndex].y + S + 1 <= H - 1)
				for (int k = low; k <= high; k++)
					inEventNum += (graph[k][players[playerIndex].y + S + 1] * 2);
			if (players[playerIndex].y - S >= 0)
				for (int k = low; k <= high; k++)
					outEventNum +=( graph[k][players[playerIndex].y - S] * 2);
			players[playerIndex].y++;
		}
		graph[players[playerIndex].x][players[playerIndex].y]++;
		break;
	case 2:
		if (players[playerIndex].x < W - 1) {
			low = (players[playerIndex].y - S >= 0) ? players[playerIndex].y - S : 0;
			high = (players[playerIndex].y + S <= H - 1) ? players[playerIndex].y + S : H - 1;
			if (players[playerIndex].x + S + 1 <= W - 1)
				for (int k = low; k <= high; k++)
					inEventNum +=( graph[players[playerIndex].x + S + 1][k] * 2);
			if (players[playerIndex].x - S >= 0)
				for (int k = low; k <= high; k++)
					outEventNum += (graph[players[playerIndex].x - S][k] * 2);
			players[playerIndex].x++;
		}
		graph[players[playerIndex].x][players[playerIndex].y]++;
		break;
	case 3:
		if (players[playerIndex].y > 0) {
			low = (players[playerIndex].x - S >= 0) ? players[playerIndex].x - S : 0;
			high = (players[playerIndex].x + S <= W - 1) ? players[playerIndex].x + S : W - 1;
			if (players[playerIndex].y + S <= H - 1)
				for (int k = low; k <= high; k++)
					outEventNum += (graph[k][players[playerIndex].y + S] * 2);
			if (players[playerIndex].y - S - 1 >= 0)
				for (int k = low; k <= high; k++)
					inEventNum += (graph[k][players[playerIndex].y - S - 1] * 2);
			players[playerIndex].y--;
		}
		graph[players[playerIndex].x][players[playerIndex].y]++;
		break;
	default:
		break;
	}
}
int main() {
	long R0;
	cin >> W >> H >> N >> S >> T >> R0;
	int x, y;

	players.resize(N);
	graph = vector<vector<int>>(W, vector<int>(H, 0));
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &x, &y);
		players[i].x = x;
		players[i].y = y;
		graph[x][y]++;
	}

	for (int z = 0; z < T; z++) {
		//第一秒N个玩家运动
		int move;
		outEventNum = 0;
		inEventNum = 0;
		for (int i = 0; i < N; i++) {
			R0 = random(R0);
			move = R0 % 4;
			moveProcess(move, i);
		}
		cout << inEventNum << " " << outEventNum << endl;
	}

	return 0;
}