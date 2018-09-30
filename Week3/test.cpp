#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int k = 0; k < n; k++) {
		cin >> a[k];
		if (a[k] % 2 == 1) {
			cout << a[k];
		}
	}

	return 0;
}