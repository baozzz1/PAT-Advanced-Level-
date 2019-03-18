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
//
////struct position {
////	int i, j;
////	position() {}
////	position(int i, int j) :i(i), j(j) {}
////	void move(const int &where){
////		switch (where) {
////		case 0:
////			i++;
////			break;
////		case 1:
////			j++;
////			break;
////		case 2:
////			i--;
////			break;
////		case 3:
////			j--;
////			break;
////		default:
////			break;
////		}
////	}
////};
//unordered_map<pair<int, int>, int> maps;
//void move(pair<int, int> &pos, const int &where) {
//	switch (where) {
//	case 0:
//		pos.first++;
//		break;
//	case 1:
//		pos.second++;
//		break;
//	case 2:
//		pos.first--;
//		break;
//	case 3:
//		pos.second--;
//		break;
//	default:
//		break;
//	}
//}
//
//void board() {
//	int times = 1;
//	int i = 0, j = 0;
//	int num = 0;
//	//position curr(0, 0);
//	auto curr = make_pair(0, 0);
//	int where = 0;
//	maps[curr] = num;
//	num++;
//	/*while (!(curr.i<-10001 || curr.j<-10001|| curr.i>10001 || curr.j>10001)) {
//		for (int k = 0; k < times; k++) {
//			curr.move(where);
//			maps[curr] = num++;
//		}
//		where = (where + 1) % 4;
//		for (int k = 0; k < times; k++){
//			curr.move(where);
//			maps[curr] = num++;
//		}
//		where = (where + 1) % 4;
//		times++;
//	}*/
//	while (!(curr.first < -10001 || curr.second < -10001 || curr.first>10001 || curr.second>10001)) {
//		for (int k = 0; k < times; k++) {
//			//curr.move(where);
//			move(curr, where);
//			maps[curr] = num++;
//		}
//		where = (where + 1) % 4;
//		for (int k = 0; k < times; k++) {
//			//curr.move(where);
//			move(curr, where);
//			maps[curr] = num++;
//		}
//		where = (where + 1) % 4;
//		times++;
//	}
//}
//
//int main() {
//
//	board();
//
//	int x, y;
//	//position curr(0, 0);
//	auto curr = make_pair(0, 0);
//	while (cin >> x) {
//		cin >> y;
//		//curr.i = x;
//		//curr.j = y;
//		//cout << maps[curr] << endl;
//		cout << maps[make_pair(x, y)] << endl;
//	}
//
//	return 0;
//}