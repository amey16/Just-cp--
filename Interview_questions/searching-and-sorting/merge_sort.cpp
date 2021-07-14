#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// inplace merge code
void merge(vector<int>& arr, int start, int mid, int end){
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) {
        return;
    }
    while(start <= mid && start2 <= end){
        if (arr[start] <= arr[start2]) {
            start++;
        }
        else{
            int value = arr[start2];
            int index = start2;
 
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
 
            start++;
            mid++;
            start2++;
        }
    }
}
void mergeSortInplace(vector<int>& arr, int l, int r){
    if(l<r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B){
    if (A.size() == 0 || B.size() == 0)
        return A.size() == 0 ? B : A;

    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    cout << ("Merging these two arrays ") << endl;
    cout << ("left array -> ");
    print(A);
    cout << ("right array -> ");
    print(B);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m){
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}
vector<int> mergeSort(vector<int>& arr,int s,int e){
    if(s==e){
        vector<int> temp;
        temp.push_back(arr[s]);
        return temp;
    }
    int mid = s + (e-s)/2;
    vector<int> sa1 = mergeSort(arr,s,mid);
    vector<int> sa2 = mergeSort(arr,mid+1,e);
    vector<int> ans = mergeTwoSortedArrays(sa1,sa2);
    return ans;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];

    vector<int> ans = mergeSort(arr,0,arr.size()-1);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}