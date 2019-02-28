#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;
class book1022 {
public:
	book1022() :id(""), bookName(""), author(""), publisher(""), publishedYear(""){}
	string id;
	string bookName;
	string author;
	string publisher;
	string publishedYear;
	vector<string> keyWord;
};

// 40min
int P1022() {
	int N; cin >> N;
	getchar();
	vector<book1022> books(N+1);
	vector<unordered_map<string, set<string>>> searchWay(6);	//searchWay,key word,index at books
	string id_in, bookName_in, author_in, keyWords_in, publisher_in, publishedYear_in;
	//vector<string> keyWord(6);
	string temp;
	for (int i = 1; i <= N; i++) {
		getline(cin, id_in);
		getline(cin, bookName_in);
		getline(cin, author_in);
		getline(cin, keyWords_in);
		getline(cin, publisher_in);
		getline(cin, publishedYear_in);
		books[i].id = id_in;
		books[i].bookName = bookName_in;
		books[i].author = author_in;
		books[i].publisher = publisher_in;
		books[i].publishedYear = publishedYear_in;
		searchWay[1][bookName_in].insert(id_in);
		searchWay[2][author_in].insert(id_in);
		searchWay[4][publisher_in].insert(id_in);
		searchWay[5][publishedYear_in].insert(id_in);
		temp.clear();
		for (int j = 0; j < keyWords_in.size(); j++) {
			if (keyWords_in[j] != ' ')
				temp.push_back(keyWords_in[j]);
			else {
				books[i].keyWord.push_back(temp);
				searchWay[3][temp].insert(id_in);
				temp.clear();
			}
		}
		books[i].keyWord.push_back(temp);
		searchWay[3][temp].insert(id_in);
	}

	int M; cin >> M;
	getchar();
	string getIn;
	int searchNum = 0;
	for (int i = 0; i < M; i++) {
		getline(cin, getIn);

		cout << getIn << endl;
		searchNum = getIn[0] - '0';
		temp = string(getIn.begin() + 3, getIn.end());
		if (searchWay[searchNum][temp].size() == 0)
			cout << "Not Found" << endl;
		else {
			for (auto iter = searchWay[searchNum][temp].begin(); iter != searchWay[searchNum][temp].end(); ++iter)
				cout << *iter << endl;
		}
	}
	return 0;
}