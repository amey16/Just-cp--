class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> nextGreater(nums.size(),-1);
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(nums[i]);
                nextGreater[i] = -1;
            }
            else{
                if(st.top() > nums[i]){
                    nextGreater[i]  = st.top();
                    st.push(nums[i]);
                }
                else{
                    while(!st.empty() && st.top()<=nums[i])
                        st.pop();
                    st.push(nums[i]);
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(st.top() > nums[i]){
                nextGreater[i] = st.top();
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(!st.empty())
                    nextGreater[i] = st.top();
                st.push(nums[i]);
            }
        }
        return nextGreater;
    }
};