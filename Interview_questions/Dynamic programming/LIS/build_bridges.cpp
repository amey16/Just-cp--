// https://www.geeksforgeeks.org/dynamic-programming-building-bridges/

#include<iostream>
#include<vector>
#include<algorithm>
// #include<pair>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr1(n);
    vector<int> arr2(n);
    
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++)
        temp.push_back(make_pair(arr1[i],arr2[i]));
    
    sort(temp.begin(),temp.end());
    
    // for(int i=0;i<n;i++)
    //     cout<<temp[i].first<<" "<<temp[i].second<<"    ";
    // cout<<endl;
    
    vector<int> dp(n,0);
    int ans = 0;
    for(auto val:temp){
        int i=0;
        int j=ans;
        while(i<j){
            int mid = i + (j-i)/2;
            if(dp[mid] <= val.second)
                i = mid+1;
            else
                j= mid;
        }
        dp[i] = val.second;
        if(i==ans)
            ans++;
    }
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<"  ";
    // cout<<endl;
    cout<<ans<<endl;
}