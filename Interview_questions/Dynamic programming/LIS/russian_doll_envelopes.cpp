// https://leetcode.com/problems/russian-doll-envelopes/

struct pairenv{
    int width,height;  
};
bool compare(struct pairenv a, struct pairenv b){
    if (a.width == b.width)
        return a.height > b.height;
    return a.width < b.width;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pairenv> values(n);
        for(int i=0;i<envelopes.size();i++){
            pairenv e;
            e.width = envelopes[i][0];
            e.height = envelopes[i][1];
            values[i] = e;
        }

        sort(values.begin(),values.end(),compare);

//         for(int i=0;i<values.size();i++){
//             cout<<values[i].width<<" "<<values[i].height<<endl;
//         }
        
        
        vector<int> dp(n,0);
        int ans = 0;
        for(auto val:values){
            int i=0;
            int j=ans;
            while(i<j){
                int mid = i + (j-i)/2;
                if(dp[mid] < val.height)
                    i = mid+1;
                else
                    j= mid;
            }
            dp[i] = val.height;
            if(i==ans)
                ans++;
        }
        // for(int i=0;i<n;i++)
        //     cout<<dp[i]<<"  ";
        // cout<<endl;
        // cout<<ans<<endl;
        return ans;
    }
};