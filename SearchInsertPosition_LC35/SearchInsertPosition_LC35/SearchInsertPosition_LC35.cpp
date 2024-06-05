#include<iostream>
#include <vector>
using namespace std;




int InsertPos(vector<int> &v,int val) {

	int left = 0;
	int right = v.size() - 1;
	int mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (v[mid] == val) return mid;
		if (val < v[mid]) right = mid - 1;
		if (val > v[mid]) left = mid + 1;
	}
	return left;
}



void main() {
	vector<int> v = {1,2,3,4,5};
	cout << "Vi tri can chen la : " << InsertPos(v, 6) << endl;

}