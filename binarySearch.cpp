#include <iostream>
using namespace std;


int binarySearch(int arr[],int n,int t){
    int left = 0;
    int right = n - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == t){
            return mid;
        }else if(arr[mid] < t){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    cout<<"Hello world..\n";
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int t = 4;

    int res = binarySearch(arr,n,t);

    if(res != -1){
        cout<<"Element "<<t<<" found at "<<res<<" position.\n";
    }else{
        cout<<"Element not found.\n";
    }
}