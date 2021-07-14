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
void partition(vector<int>& arr,int pivot){
    int i=0,j=0;
    while(j<arr.size()){
        if(pivot >= arr[j]){
            swap(arr,j,i);
            i++;
            j++;
        }
        else
            j++;
    }
}
int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];

    int pivot;
    cin>>pivot;
    
    partition(arr,pivot);
    print(arr);
    return 0;
}