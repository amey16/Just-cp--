// very good question
// binary search
// https://leetcode.com/problems/k-th-smallest-prime-fraction/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double lo = 0;
        double hi = 1;
        while(lo<hi){
            double mid = lo + (double)(hi-lo)/2;
            int i = 0;
            int j = arr.size() - 1;
            int count = 0,indexi = 0,indexj = 0;
            double maxV = 0;
            while(i< arr.size()){
                while(j>0 && arr[i] > mid*arr[arr.size() - j]){
                    j--;
                }
                if(j == 0) break;
                count += j;
                double curr = ((double)(arr[i]))/(arr[arr.size()-j]);
                if(maxV < curr){
                    maxV = curr;
                    indexi = i;
                    indexj = arr.size()-j;
                }
                i++;
            }
            if(count<k)
                lo = mid;
            else if(count>k)
                hi = mid;
            else return {arr[indexi],arr[indexj]};
        }
        return {};
    }
};