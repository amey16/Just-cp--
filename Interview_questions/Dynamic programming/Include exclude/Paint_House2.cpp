// https://www.lintcode.com/problem/516/

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0)
            return 0;
        if(costs[0].size() == 1){
            if(costs.size() == 1)
                return costs[0][0];
            else
                return 0;
        }
        int min1 = costs[0][0];
        int min2 = costs[0][1];
        if(min2 < min1){
            min1 = costs[0][1];
            min2 = costs[0][0];
        }
        for(int i=2;i<costs[0].size();i++){
            if(costs[0][i]<min1){
                min2 = min1;
                min1 = costs[0][i];
            }
            else if(costs[0][i]<min2)
                min2 = costs[0][i];
        }
        for(int i=1;i<costs.size();i++){
            for(int j=0;j<costs[0].size();j++){
                if(costs[i-1][j] == min1)
                    costs[i][j] += min2;
                else
                    costs[i][j] += min1;
            }
            min1 = costs[i][0];
            min2 = costs[i][1];
            if(min2 < min1){
                min1 = costs[i][1];
                min2 = costs[i][0];
            }
            for(int k=2;k<costs[i].size();k++){
                if(costs[i][k]<min1){
                    min2 = min1;
                    min1 = costs[i][k];
                }
                else if(costs[i][k]<min2)
                    min2 = costs[i][k];
            }  
        }
        // for(int i=0;i<costs.size();i++){
        //     for(int j=0;j<costs[0].size();j++){
        //         cout<<costs[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return min1;
    }
};