// https://www.lintcode.com/problem/515/description

class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minimum(vector<vector<int>> costs,int i,int j){
        if(j == 0)
            return min(costs[i-1][1],costs[i-1][2]);
        else if(j == 1)
            return min(costs[i-1][0],costs[i-1][2]);
        else
            return min(costs[i-1][0],costs[i-1][1]);
        return 0;
    }
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0)
            return 0;
        int r = costs[0][0],g = costs[0][1],b = costs[0][2];
        for(int i=1;i<costs.size();i++){
            cout<<r<<" "<<g<<" "<<b<<endl;
            int temp = b;
            b = costs[i][2] + min(r,g);
            int temp1 = g;
            g = costs[i][1] + min(r,temp);
            r = costs[i][0] + min(temp1,temp);
        }
        // for(int i=0;i<costs.size();i++){
        //     for(int j=0;j<costs[0].size();j++)
        //         cout<<costs[i][j]<<" ";
        //     cout<<endl;
        // }
        return min(r,min(g,b));
    }
};