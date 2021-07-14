#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(vector<string>& arr) {
    for (int i=0; i<arr.size(); i++)
        cout<<arr[i]<<endl;
}

void countSort(vector<string>& arr,int div, int mod, int range) {
    vector<string> ans(arr.size());
    vector<int> farr(range);
    for(int i=0;i<arr.size();i++) {
        farr[stoi(arr[i]) / div % mod]++;
    }
    for(int i=1;i<farr.size();i++)
        farr[i] += farr[i-1];
    for(int i=arr.size()-1; i>=0;i--) {
        int pos = farr[stoi(arr[i]) / div % mod] - 1;
        ans[pos] = arr[i];
        farr[stoi(arr[i]) / div % mod]--;
    }
    for (int i=0; i<arr.size(); i++)
      arr[i]=ans[i];
}
void sortDates(vector<string>& arr) {
    countSort(arr, 1000000, 100, 32);
    countSort(arr, 10000, 100, 13);
    countSort(arr, 1, 10000, 2501);
}

    
int main(){
    int n;
    cin>>n;
    
    vector<string> arr(n);
    string str;
    for(int i=0; i<n; i++) {
        cin>>str;
        arr[i]=str;
    }
    sortDates(arr);
    print(arr);
}