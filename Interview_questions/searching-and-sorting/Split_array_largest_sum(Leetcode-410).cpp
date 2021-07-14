//binary search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = 0;
        for(int i=0;i<nums.size();i++)
            hi += nums[i];
        int ans = -1;
        // cout<<lo<<" "<<hi<<endl;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int rm = 1;
            int tsum = 0; 
            for(int i=0;i<nums.size();i++){
                tsum += nums[i];
                if(tsum > mid){
                    rm += 1;
                    tsum = nums[i];
                }
            }
            if(rm > m)
                lo = mid+1;
            else{
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};