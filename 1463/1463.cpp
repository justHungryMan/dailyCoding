#include <iostream>
using namespace std;

int main() {
	int n;
	const int MAX = 1000001;
	int arr[MAX];
	
	cin >> n;
	
	fill_n(arr, MAX, MAX);
	arr[n] = 0;
	
	for(int i = n; i > 1; i -= 1) {
		if (i % 3 == 0 && arr[i / 3] > arr[i] + 1) {
			arr[i / 3] = arr[i] + 1;
		}
		if (i % 2 == 0 && arr[i / 2] > arr[i] + 1) {
			arr[i / 2] = arr[i] + 1;
		}
		if (i - 1 >= 1 && arr[i - 1] > arr[i] + 1) {
			arr[i - 1] = arr[i] + 1;
		}
	}
	printf("%d\n",arr[1]);
}
