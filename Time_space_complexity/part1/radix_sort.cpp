#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void countSort(vector<int>& arr, int expval){
    vector<int> count(10,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i]/expval%10] ++; 
    }
    // print(count);
    for(int i=1;i<count.size();i++){
        count[i] += count[i-1]; 
    }
    // print(count);
    vector<int> ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int val = arr[i]/expval%10;
        int pos = count[val];
        int idx = pos-1;
        ans[idx] = arr[i];
        count[val] -- ;
    }
    for(int i=0;i<arr.size();i++)
        arr[i] = ans[i];
    cout<<"After sorting on "<<expval<<" place -> ";
    print(arr);
}

void radixSort(vector<int>& arr){
    int max = INT_MIN;
    for(int val:arr){
        if(val>max)
            max = val;
    }
    int expval = 1;
    while(expval <= max){
        countSort(arr,expval);
        expval *=10;
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    radixSort(arr);
    print(arr);
}