#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char> str;
char qt[64][64];

bool allColorSame(int n, int x, int y) {

	char first;

	first = qt[x][y];

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (qt[x][y] != qt[j][i])
				return false;
		}
	}

	return true;
}

void quardTree(int n, int x, int y) {
	
	if (n == 1) {
		
		str.push_back(qt[x][y]);
		return;
	}
	else if (allColorSame(n, x, y)) {
		
		str.push_back(qt[x][y]);
		return;
	}
	else {
		str.push_back('(');
		quardTree(n / 2, x, y);
		quardTree(n / 2, x + n / 2, y);
		quardTree(n / 2, x, y + n / 2);
		quardTree(n / 2, x + n / 2, y + n / 2);
		str.push_back(')');
	}
}

int main() {

	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> qt[j][i];

		}
	}

	quardTree(n, 0, 0);

	for (int i = 0; i < str.size(); i++)
		cout << str[i];
}