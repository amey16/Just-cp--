class Solution {
public:
    int pivot(vector<int>& nums){
        int i=0,j=nums.size()-1;
        while(nums[i] > nums[j])
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
    int search(vector<int>& nums, int target) {
        int p = pivot(nums);
        int pos;
        if(target < nums[0] && target > nums[nums.size()-1])
            pos = -1;
        else if(target >= nums[0])
            pos = binary_search(nums, 0, p, target);
        else
            pos = binary_search(nums, p+1, nums.size()-1, target);
        return pos;
    }
};

// 2nd solution (lil better)

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int lo = 0, hi = nums.size() - 1;
        if(nums[hi]>nums[0])
            return 0;
        while(hi >= lo){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid]>nums[mid + 1])
                return mid + 1;
            if(nums[mid-1] > nums[mid])
                return mid;
            if(nums[mid] > nums[0])
                lo = mid+1;
            else
                hi = mid-1;
        }
        return -1;
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
    int search(vector<int>& nums, int target) {
        int p = findMin(nums);
        if(target < nums[0] && target > nums[nums.size()-1])
            return -1;
        int id1 = binary_search(nums, 0, p-1, target);
        int id2 = binary_search(nums, p, nums.size()-1, target);
        if(id1 == -1 && id2 == -1)
            return -1;
        if(id1 == -1)
            return id2;
        return id1;
    }
};