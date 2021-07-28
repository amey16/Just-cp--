class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int i=0;i<asteroids.size();i++){
            int a = asteroids[i];
            if(st.empty())
                st.push(a);
            else{
                if(a >= 0)
                    st.push(a);
                else{
                    if(st.top()<0)
                        st.push(a);
                    else{
                        if(st.top() == -a)
                            st.pop();
                        else{
                            while(!st.empty() && st.top()>0 && st.top() < -a){
                                st.pop();
                            }
                            if(!st.empty() && st.top() == -a)
                                st.pop();
                            else if(st.empty() || st.top()<0)
                                st.push(a);
                        }
                    }
                }
            }
        }
        vector<int> answer(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            answer[i] = st.top();
            i--;
            st.pop();
        }
        return answer;
    }
};