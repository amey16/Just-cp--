class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        stack<char> st;
        vector<bool> value(26,false);
        
        for(char ch:s)
            freq[(int)(ch-'a')] ++;
        
        for(char ch:s){
            int index = ch-'a';
            freq[index]--;
            
            if(value[index])
                continue;
            while(!st.empty() && ch<st.top() && freq[st.top()-'a'] != 0){ 
                value[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            value[index]=true;
        }
        string ans = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            // cout<<c<<" ";
            ans.insert(0,1,c);
        }
        // cout<<endl;
        return ans;
    }
};