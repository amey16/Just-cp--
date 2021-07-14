#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
void swap(vector<int>& arr, int i, int j) {
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(vector<int>& arr,int pivot,int lo,int hi){
    cout<<"pivot -> "<<pivot<<endl;
    int i=lo,j=lo;
    while(i<=hi) {
        if(arr[i] <= pivot) {
            swap(arr, i, j);
            i++;
            j++;
        } 
        else
            i++;
    }
    cout<<"pivot index -> "<<(j - 1)<<endl;
    return (j - 1);
}
void quickSort(vector<int>& arr,int lo,int hi){
    if(lo>hi)
        return;
    int pivot = arr[hi];
    int pi= partition(arr,pivot,lo,hi);
    quickSort(arr,lo,pi-1);
    quickSort(arr,pi+1,hi);
}
int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    
    quickSort(arr,0,n-1);
    print(arr);
    return 0;
}