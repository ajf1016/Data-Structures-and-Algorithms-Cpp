#include <iostream>
using namespace std;

int main(){
	cout<<"Hello WORLD..\n";

	int arr[5] = {1,2,3,4,5};
	int arr2[5] = {6,7,8,9,10};

	int con[5+5];

	for(int i = 0;i<5;i++){
		con[i] = arr[i];
	}

	for(int i = 0;i<5;i++){
		con[5+i] = arr2[i];
	}

	for(int i = 0;i<10;i++){
		cout<<con[i]<<", ";
	}

	return 0;
}