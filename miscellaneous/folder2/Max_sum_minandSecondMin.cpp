#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pairWithMaxSum(vector<int> arr, int N){
    if(N<2)
        return -1;

    int res = arr[0]+arr[1];
    for(int i=1;i<N-1;i++)
        res = max(res, arr[i]+arr[i+1]);

    return res;
}
int main(){
    int N;
    cin>>N;
 
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];

    cout<<pairWithMaxSum(arr, N)<< endl;
    return 0;
}