// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1 ;
        while(lo < hi){
            int mid = lo + (hi-lo )/2;
            if(nums[mid] < nums[hi]){
                hi = mid;
            }
            else if(nums[mid] == nums[hi]){
                hi = hi - 1;
            }
            else{
                lo = mid +1;
            }
        }
        return nums[hi];
    }
};