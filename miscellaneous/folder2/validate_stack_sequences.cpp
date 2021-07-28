class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pointer = 0;
        for(int i=0;i<pushed.size();i++){
            if(st.empty()){
                st.push(pushed[i]);
                if(st.top() == popped[pointer]){
                    st.pop();
                    pointer++;
                }
            }
            else{
                st.push(pushed[i]);
                while(!st.empty() && pointer<popped.size() && st.top() == popped[pointer]){
                    st.pop();
                    pointer++;
                }
            }
        }
        if(pointer == popped.size())
            return true;
        return false;
    }
};