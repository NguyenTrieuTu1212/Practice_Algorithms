#include <iostream>
#include <vector>
using namespace std;







void main() {

	int n = 4;
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}