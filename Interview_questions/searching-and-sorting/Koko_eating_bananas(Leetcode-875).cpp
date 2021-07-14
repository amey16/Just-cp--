//binary search

class Solution {
public:
    int ceil(int num,int den){
        int number = num/den;
        if(num % den != 0)
            number+=1;
        return number;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int ans = -1;
        int hi = *max_element(piles.begin(),piles.end());
        while(lo<= hi){
            int mid = lo + (hi - lo)/2;
            int rh = 0; //required hours
            for(int i=0;i<piles.size();i++){
                rh += ceil(piles[i],mid);
                // cout<<ceil(piles[i],mid)<<" ";
            }
            if(rh > h){
                lo = mid+1;
            }
            else{
                ans = mid;
                hi = mid-1;
            }
            // cout<<mid<<" "<<rh<<endl;
        }
        return ans;
    }
};