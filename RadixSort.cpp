#include <iostream>
using namespace std;

int main(){
	cout << "Hello world..\n";
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

	return 0;
}