#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>& arr) {
    int lo = 0;
    int hi = arr.size()-1;
    
    while(lo<hi) {
        int mid =(lo+hi)/2;
        if(arr[mid]<arr[hi])
            hi = mid;
        else if (arr[mid] > arr[hi])
            lo = mid + 1;
    }
    return arr[hi];
}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n; i++)
        cin>>arr[i];
        
    int pivot=findPivot(arr);
    cout<<pivot<<endl;
}