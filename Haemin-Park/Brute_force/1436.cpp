#include <iostream>
#include <string>
using namespace std;
int six = 665;

int main() {

	int n, p, cnt=0;
	string ssix;

	cin >> n;

	while (cnt != n)
	{
		six++;
		ssix = to_string(six);
		if (ssix.find("666") != string::npos) { // ���ڿ��� ���� �� string::npos ��ȯ
			cnt++;
		}
		
	} 

	cout << six;

}