class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.length()==k)
            return "0";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            while(st.size()>0 && k>0 && st.top() > s[i]){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        
        vector<char>v;
        string ans="";
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        bool flag =false;
        int count=0;

        for(auto x:v){
            if(x=='0' && flag==false)
                continue;
            else{
                flag=true;
                ans.push_back(x);
            }
        }
        if(flag==false)
            return "0";
        return ans;
    }
};