#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int thresold = 60;
int eachLineThresold = 2;

struct Point {
	int i, j;
	int gray;
	bool binary;
	Point() {}
	Point(int i, int j, int g) :i(i), j(j), gray(g) {
		if (gray > thresold)
			binary = true;
		else binary = false;
	}
};
// Ðý×ªºóµÄmap
vector<vector<bool>> isMarked;
void closeAreaDetect(const vector<vector<Point>> &maps) {
	int m = maps.size(), n = maps[0].size();
	vector<Point> oneArea;
	int randI =rand() % m, randJ= rand() % n;
	while (maps[randI][randJ].binary) {
		randI = rand() % m;
		randJ = rand() % n;
	}
	queue<Point> points; points.push(maps[randI][randJ]);
	isMarked[randI][randJ] = true;
	oneArea.push_back(maps[randI][randJ]);
	while (!points.empty()) {
		int size = points.size();
		for (int i = 0; i < size; i++) {
			Point temp = points.front();
			points.pop();

			if (temp.i + 1 <= n - 1 && !maps[temp.j][temp.i + 1].binary && !isMarked[temp.j][temp.i + 1]) {
				points.push(maps[temp.j][temp.i + 1]);
				isMarked[temp.j][temp.i + 1] = true;
				oneArea.push_back(maps[temp.j][temp.i + 1]);
			}
		}
	}
}

int dfs(const vector<vector<Point>> &maps, const int &i, const int &j) {
	if (isMarked[i][j] || !maps[i][j].binary)
}

int main() {
	vector<vector<Point>> maps(28, vector<Point>(28));
	//vector<vector<bool>> binary(28, vector<bool>(28, false));
	//vector<vector<bool>> hasInclude(28, vector<bool>(28, false));
	vector<vector<Point>> noUpDownMaps;
	Point p;
	int num;
	int lineCount = 0;
	for (int i = 0; i < 28; i++) {
		lineCount = 0;
		for (int j = 0; j < 28; j++) {
			scanf_s("%d", &num);
			p = Point(i, j, num);
			maps[i][j] = Point(p);
			if (p.binary)
				lineCount++;
		}
		if (lineCount >= eachLineThresold)
			noUpDownMaps.push_back(maps[i]);
	}
	vector<vector<Point>> noLeftRightMaps;
	vector<Point> tempLine;
	for (int j = 0; j < noUpDownMaps.size(); j++) {
		lineCount = 0;
		tempLine.clear();
		for (int i = 0; i < noUpDownMaps.size(); i++) {
			if (noUpDownMaps[i][j].binary)
				lineCount++;
		}
		if (lineCount >= eachLineThresold) {
			for (int i = 0; i < noUpDownMaps.size(); i++)
				tempLine.push_back(noUpDownMaps[i][j]);
			noLeftRightMaps.push_back(tempLine);
		}
	}

	isMarked = vector<vector<bool>>(noLeftRightMaps.size(), vector<bool>(noLeftRightMaps[0].size()));



	return 0;
}

