#include <iostream>
using namespace std;

// void print(int arr[], int index, int n) {
//     if (index == n)
//         return;

//     cout << arr[index] << " ";
//     print(arr, index + 1, n);
// }


// if size is passed
// void print(int arr[], int n) {
//     if (n == 0)
//         return;

//     print(arr,  n-1);
//     cout << arr[n-1] << " ";
    
// }

//sum of array
int sum(int arr[],int index,int n){
    if(index == n) return 0;
    return arr[index] + sum(arr,index+1,n);
}

// minimum of array
int mini(int arr[],int index,int n){
    if(index == n-1) return arr[index];
    return min(arr[index] , mini(arr,index+1,n));
}
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<sum(arr,0,n);
    cout<<mini(arr,0,n);
    // print(arr, 0, n);
    // print(arr, n);
}



