class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0,j=nums.size()-1;
        while(j>0 && nums[j]>=nums[j-1])
            j--;
        return j;
    }
    int binary_search(vector<int>& nums,int lo,int hi,int target){
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > target)
                hi = mid-1;
            else if(nums[mid] < target)
                lo = mid+1;
            else
                return mid;
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
        int p = findMin(nums);
        // cout<<p<<endl;
        if(target < nums[0] && target > nums[nums.size()-1])
            return false;
        int id1 = binary_search(nums, 0, p-1, target);
        int id2 = binary_search(nums, p, nums.size()-1, target);
        // cout<<id1<<" "<<id2<<endl;
        if(id1 == -1 && id2 == -1)
            return false;
        return true;
    }
};