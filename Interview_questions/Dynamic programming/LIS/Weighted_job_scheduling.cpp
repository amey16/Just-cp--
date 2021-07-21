// https://www.geeksforgeeks.org/weighted-job-scheduling-set-2-using-lis/?ref=rp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job{
    int start, finish, profit;
};
int findSum(vector<Job> arr){
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum +=  arr[i].profit;
    return sum;
}
int compare(Job x, Job y){
    return x.start < y.start;
}
void findMaxProfit(vector<Job> &arr){
    sort(arr.begin(), arr.end(), compare);
    vector<vector<Job>> L(arr.size());
    
    L[0].push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        for(int j=0; j<i;j++){
            if((arr[j].finish<=arr[i].start) && (findSum(L[j])>findSum(L[i])))
                L[i] = L[j];
        }
        L[i].push_back(arr[i]);
    }
    vector<Job> maxChain;
    for(int i=0;i<L.size();i++)
        if(findSum(L[i])>findSum(maxChain))
            maxChain = L[i];
 
    for(int i=0;i<maxChain.size();i++)
        cout<<"("<<maxChain[i].start<<", "<<maxChain[i].finish<<", "<<maxChain[i].profit<<") ";
}
int main(){
    int n;
    cin>>n;
    
    vector<Job> arr(n);
    int start,finish,profit;
    for(int i=0;i<n;i++){
        cin>>start>>finish>>profit;
        Job j;
        j.start = start;
        j.finish = finish;
        j.profit = profit;
        arr[i] = j;
    }
    findMaxProfit(arr);
 
    return 0;
}