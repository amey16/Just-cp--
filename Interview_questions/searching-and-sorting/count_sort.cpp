#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<endl;
    // cout<<endl;
}

vector<int> countSort(vector<int>& arr, int mine, int maxe) {
    vector<int> count(maxe-mine+1,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i]-mine] ++; 
    }
    // print(count);
    for(int i=1;i<count.size();i++){
        count[i] += count[i-1]; 
    }
    // print(count);
    vector<int> ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int val = arr[i];
        int pos = count[val - mine];
        int idx = pos-1;
        ans[idx] = val;
        count[val - mine] -- ;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    int maxe = INT_MIN;
    int mine = INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxe = max(maxe, arr[i]);
        mine = min(mine, arr[i]);
    }
    vector<int> ans = countSort(arr,mine,maxe);
    print(ans);
}