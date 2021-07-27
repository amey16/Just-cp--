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
};