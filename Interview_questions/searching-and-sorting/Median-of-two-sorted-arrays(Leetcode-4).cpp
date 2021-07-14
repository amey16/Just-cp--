// Bonary search

class Solution {
public:
    int getMax(vector<int> nums,int partition){
        if(partition <=0 || partition > nums.size())
            return INT_MIN; 
        else
            return nums[partition-1];
    }
    int getMin(vector<int> nums,int partition){
        if(partition <= -1 || partition >= nums.size())
            return INT_MAX; 
        else
            return nums[partition];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        
        int n = nums1.size();
        int m = nums2.size();
        
        int lo = 0;
        int hi = nums1.size(); //should be = n to cover edge cases
        int length = nums1.size() + nums2.size() + 1;
        int half = length/2; //cover odd even cases (shift more nos to left if odd size)
        while(lo<=hi){
            int mid1 = lo + (hi - lo)/2;
            int mid2 = half - mid1;
            
            int leftX = getMax(nums1,mid1);
            int rightY = getMin(nums2,mid2);
            
            int rightX = getMin(nums1,mid1);
            int leftY = getMax(nums2,mid2);
            
            if(leftX <= rightY && leftY <= rightX){
                if(length%2 == 1)
                    return (max(leftX,leftY) + min(rightX,rightY))/2.0;
                else
                    return max(leftX,leftY);
            }
            if(leftX > rightY)
                hi = mid1 - 1;
            else
                lo = mid1 + 1;
        }
        return 0.0;
    }
};