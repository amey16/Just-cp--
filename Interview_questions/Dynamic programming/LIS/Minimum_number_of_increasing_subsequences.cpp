// https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLDS(vector<int>& nums){
    int n=nums.size();
    vector<int> lis(n);
    lis[0] = 1;
    for(int i=1;i<n;i++){
        lis[i]=1;
        for(int j=0;j<i;j++){
            if(nums[i]<nums[j]){
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    int res = lis[0];
    for(int i=1;i<n;i++){
        res = max(res,lis[i]);
    }
    
    return res; 
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lengthOfLDS(arr);
}