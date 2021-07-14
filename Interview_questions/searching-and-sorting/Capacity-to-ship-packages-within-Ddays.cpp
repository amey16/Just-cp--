// binary search 
// complexity - log(sum(arr) - max(arr))

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = 0;
        for(int i=0;i<weights.size();i++)
            hi += weights[i];
        // cout<<hi<<" "<<lo<<endl;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            int reqD = 1;
            int w = 0;
            for(int i=0;i<weights.size();i++){
                w += weights[i];
                if(w > mid){
                    w = weights[i];
                    reqD+=1;
                }
            }
            if(reqD <= days){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};