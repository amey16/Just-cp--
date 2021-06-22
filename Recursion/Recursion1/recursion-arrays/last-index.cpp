#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    // write your code here
    if(idx == n)
        return -1;
    int val = lastIndex(arr,idx+1,x,n);
    if(val == -1 && arr[idx] == x)
        return idx;
    else
        return val;
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}