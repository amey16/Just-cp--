#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void targetSumPair(vector<int>& arr, int target){
    sort(arr.begin(),arr.end());
    int left=0, right=arr.size()-1;
    while(left<right){
        if(arr[left]+arr[right] < target)
            left++;
        else if(arr[left] + arr[right] == target){
            cout<<arr[left]<<", "<<arr[right]<<endl;
            left++;
            right--;
        }
        else
            right--;
    }
}
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0 ;i<n; i++)
        cin>>arr[i];
        
    int target;
    cin>>target;
    targetSumPair(arr,target);
}