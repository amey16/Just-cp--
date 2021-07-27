class Solution {
public:
    int maxele(vector<int> arr){
        int m = INT_MIN;
        for(int i=0;i<arr.size();i++)
            if(m<arr[i])
                m = arr[i];
        return m;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> leftMin(n);
        vector<int> rightMin(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty())
                st.push(i);
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    leftMin[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            leftMin[st.top()] = -1;
            st.pop();
        }

        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(i);
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    rightMin[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            rightMin[st.top()] = n;
            st.pop();
        }
        int maxArea = maxele(arr);
        for(int i=0;i<n;i++){
            int area = arr[i]* (rightMin[i] - leftMin[i] - 1);
            if(area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<int> m;
        for(int i=0;i<matrix[0].size();i++){
            int ele = matrix[0][i]-'0';
            m.push_back(ele);
        }
        int area = largestRectangleArea(m);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '0')
                    m[j] = 0;
                else{
                    m[j] += 1;
                }
            }
            if(area < largestRectangleArea(m))
                area = largestRectangleArea(m);
        }
        return area;
    }
};