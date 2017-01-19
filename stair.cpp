#include <iostream>
#include <vector>
using namespace std;

int n;
int stair[301];
int upstair[301][2];

int getMax(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
};

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}
	upstair[0][0] = stair[0];
	upstair[0][1] = 0;
	upstair[1][0] = stair[1];
	upstair[1][1] = stair[0] + stair[1];

	for (int j = 2; j < n; j++) {
		upstair[j][0] = getMax(upstair[j - 2][0], upstair[j - 2][1]) + stair[j];
		upstair[j][1] = upstair[j - 1][0] + stair[j];
	}
	cout << getMax(upstair[n-1][0], upstair[n-1][1]);
}