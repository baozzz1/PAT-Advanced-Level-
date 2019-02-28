#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(const string &s) {
	int i = 0; int j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

string getReversed(const string &s) {
	string res = "";
	int i = s.size() - 1;
	while (s[i] == '0' && i>=0)	i--;
	if (i < 0)
		return "0";
	while (i >= 0) {
		res.push_back(s[i]);
		i--;
	}
	return res;
}

string add(const string &s1, const string &s2) {
	string res = "";
	int i = s1.size()-1, j = s2.size() - 1;
	int addNum, carry = 0;
	while (i >=0 && j>=0) {
		addNum = (s1[i] - '0') + (s2[j] - '0') + carry;
		if (addNum >= 10) {
			carry = 1;
			addNum -= 10;
		}
		else
			carry = 0;
		res.push_back(addNum + '0');
		i--; j--;
	}
	while ( i >= 0) {
		addNum = (s1[i] - '0') + carry;
		if (addNum >= 10) {
			carry = 1;
			addNum -= 10;
		}
		else
			carry = 0;
		res.push_back(addNum + '0');
		i--;
	}
	while (j >= 0) {
		addNum = (s2[j] - '0') + carry;
		if (addNum >= 10) {
			carry = 1;
			addNum -= 10;
		}
		else
			carry = 0;
		res.push_back(addNum + '0');
		j--;
	}
	if (carry == 1)
		res.push_back('1');
	return getReversed(res);
}

int P1136() {
	string N; 
	cin >> N;
	if (isPalindrome(N)) {
		cout << N << " is a palindromic number.";
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		string B = getReversed(N);
		string C = add(N, B);
		cout << N << " + " << B << " = " << C << endl;
		if (isPalindrome(C)) {
			cout<< C << " is a palindromic number.";
			return 0;
		}
		N = C;
	}
	cout << "Not found in 10 iterations.";

	return 0;
}