//#include<iostream>
//#include<vector>
//#include<set>
//#include<unordered_set>
//#include<map>
//#include<unordered_map>
//#include<string>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
////vector<vector<int>> maps(20000, vector<int>(20000,0));
////struct Point {
////	int i, j;
////};
////int getPoint(Point &p,/* const int &currI, const int &currJ,*/ const int &where, const int &num) {
////	if (p.i <= 0 || p.j >= 20000)return -1;
////	maps[p.i][p.j] = num;
////	switch (where) {
////	case 0://向右,若y+1有数，继续向右；否则向上
////		if (maps[p.i][p.j + 1] != 0)
////			//getPoint(currI + 1, currJ, 0, num + 1);
////		{
////			p.i++;
////			return 0;
////		}
////		else {
////			p.j++;
////			return 1;
////		}
////			//getPoint(currI, currJ + 1, 1, num + 1);
////		break;
////	case 1://向上，若x-1有数，继续向上；否则向左
////		if (maps[p.i - 1][p.j] != 0) {
////			p.j++;
////			return 1;
////		}
////			//getPoint(currI, currJ + 1, 1, num + 1);
////		else {
////			p.i--;
////			return 2;
////		}
////			//getPoint(currI - 1, currJ, 2, num + 1);
////		break;
////	case 2://向左，若y-1有数，继续向左；否则向下
////		if (maps[p.i][p.j - 1] != 0) {
////			p.i--;
////			return 2;
////		}
////			//getPoint(currI - 1, currJ, 2, num + 1);
////		else {
////			p.j--;
////			return 3;
////		}
////			//getPoint(currI, currJ - 1, 3, num + 1);
////		break;
////	case 3://向下，若x+1有数，继续；否则向左
////		if (maps[p.i + 1][p.j] != 0) {
////			p.j--;
////			return 3;
////		}
////			//getPoint(currI, currJ - 1, 3, num + 1);
////		else {
////			p.i++;
////			return 0;
////		}
////			//getPoint(currI + 1, currJ, 0, num + 1);
////		break;
////	case -1:
////		return -1;
////		break;
////	}
////	return -1;
////}
////void start() {
////	maps[10000][10000] = 0;
////	maps[10001][10000] = 1;
////	maps[10001][10001] = 2;
////	maps[10000][10001] = 3;
////	maps[9999][10001] = 4;
////	maps[9999][10000] = 5;
////	maps[9999][9999] = 6;
////	maps[10000][9999] = 7;
////	maps[10001][9999] = 8;
////	int num = 9;
////	int where = 1;
////	Point p;
////	p.i = 10002;
////	p.j = 9999;
////	while(where != -1) {
////		where = getPoint(p, where, num);
////		num++;
////	}
////	//getPoint(10002, 9999, where, num);
////	return;
////}
//
int main() {
	//start();
	int x, y;
	int absX, absY;
	long res;
	while (cin >> x) {
		cin >> y;
		//cout << maps[x + 10000][y + 10000] << endl;
		//res = 0;
		absX = abs(x); absY = abs(y);
		bool isXmax = absX > absY;
		int doubleNum = isXmax ? absX : absY;
		int length = (doubleNum * 2 - 1);
		res = length * length - 1;
		if (absX >= absY)
			if (x > 0)
				res += (y + absX);
			else
				res += 2 * length + 2 + (doubleNum - y);
		else {
			if (y > 0)
				res += length + 1 + (doubleNum - x);
			else
				res += 3 * length + 3 + (x + doubleNum);
		}
		cout << res << endl;
	}

	return 0;
}