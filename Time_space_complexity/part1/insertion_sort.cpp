#include<iostream>
#include<vector>
using namespace std;

// return true if ith element is smaller than jth element
bool isSmaller(vector<int> arr, int i, int j) {
    cout<<"Comparing "<<arr[i]<<" and "<<arr[j]<<endl;
    if(arr[i] < arr[j])
        return true;
    else
        return false;
}

// used for swapping ith and jth elements of array
void swap(vector<int>& arr, int i, int j) {
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void print(vector<int> arr){
    for(int i=0; i<arr.size() ; i++)
        cout<<arr[i]<<endl;
}

void insertionSort(vector<int>& arr) {
    //write your code here
    for(int i=1;i<arr.size();i++){
        int k = i;
        for(int j=i-1;j>=0;j--){
            if(isSmaller(arr,k,j)){
                swap(arr,j,k);
                k = j;
            }
            else
                break;
        }
        // swap(arr,k,i);
    }    
}
int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    insertionSort(arr);
    print(arr);
}