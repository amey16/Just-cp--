// geeks for geeks
// https://www.geeksforgeeks.org/counting-inversions/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int merge(vector<int>& arr,int lo,int hi,int mid){
//     int i = lo;
//     int j = mid + 1;
//     int inv_cnt = 0;
//     vector<int> temp(arr.size());
//     while((i<=mid) && (j<=hi)) {
//         if(arr[i] <= arr[j]){
//             temp.push_back(arr[i++]);
//         }
//         else{
//             temp.push_back(arr[j++]);
//             inv_cnt += (mid + 1 - i);
//         }
//     }
//     while(i <= mid)
//         temp.push_back(arr[i++]);
//     while(j <= hi)
//         temp.push_back(arr[j++]);
//     for(i = lo; i <= hi; i++)
//         arr[i] = temp[i];
    
//     // for(int i=lo;i<=hi;i++)
//         // cout<<arr[i]<<" ";
//     // cout<<endl;
//     cout<<inv_cnt<<" ";
//     return inv_cnt;
// }
// int mergesort(vector<int>& arr,int lo,int hi){
//     int inv_cnt = 0;
//     if(lo<hi){
//         int mid = lo + (hi - lo)/2;
//         inv_cnt += mergesort(arr,lo,mid);
//         inv_cnt += mergesort(arr,mid+1,hi);
        
//         inv_cnt += merge(arr,lo,hi,mid);
//     }
//     return inv_cnt;
// }
int merge(vector<int>& arr,vector<int>& temp, int left, int mid, int right){
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while((i<=mid-1)&&(j<=right)){
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while(i<= mid-1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for(i=left;i<=right;i++)
        arr[i] = temp[i];
    
    // for(i=left;i<=right;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    return inv_count;
}
int mergeSort(vector<int>& arr,vector<int>& temp, int left, int right){
    int mid, inv_count = 0;
    if(right>left){
        mid=(right+left)/2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp(arr.size());
    cout<<"No of inversions: "<<mergeSort(arr,temp,0,arr.size()-1)<<endl;
}