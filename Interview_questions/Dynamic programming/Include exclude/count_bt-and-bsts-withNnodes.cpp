// https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-with-n-keys/

#include<iostream>
#include<vector>
using namespace std;

int facc(int n){
    if(n==0 || n==1)
        return 1;
    int f = facc(n-1)*n;
    return f;
}

// catlan numbers(can use recursive approach also)
int binary_count(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++)
            dp[i] += (dp[j]*dp[i-1-j]);
    }
    for(int i=0;i<n+1;i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return dp[n];
}
// Cn = 2nCn/(n+1) // O(n)
int catlan(int n){
    return facc(2*n)/(facc(n)*facc(n)*(n+1));
}
int binary_search_count(int n){
    // structure of binary tree remains the same 
    return binary_count(n)*facc(n);
}
int main(){
    int n;
    cin>>n;

    int bt = binary_count(n);
    // int bt = catlan(n);
    int bst = binary_search_count(n);
    cout<<"No of BTress = "<< bt <<endl;
    cout<<"No of BSTrees = "<< bst <<endl;
}