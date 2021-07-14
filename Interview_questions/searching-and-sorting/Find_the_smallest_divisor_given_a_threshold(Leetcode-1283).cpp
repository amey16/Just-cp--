// binary search

class Solution {
public:
    // sum of all ceils
    int computeSum(vector<int> nums, int x) {
        long s = 0;
        for (int n : nums) {
            s+=n/x+(n%x==0?0:1); 
        }
        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold){
        
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            int sum = computeSum(nums,mid);
            if(sum > threshold){
                lo = mid+1;
            }
            else{
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};