// important code
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
int main(){
    string tokens;
    getline(cin,tokens);
    
    stack <string> pre;
    stack <string> post;
    stack <char> ops;
    
    for(int i=0; i<tokens.length(); i++){
        if(tokens[i] == ' ')
            continue;
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
        else if((tokens[i] >='0' && tokens[i]<='9') || (tokens[i] >='a' && tokens[i]<='z') || (tokens[i] >='A' && tokens[i]<='Z')){
            string s = "";
            s+=tokens[i];
            pre.push(s);
            post.push(s);
        }
        else if(tokens[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                char op = ops.top();
                ops.pop();
                string oper1 = "";
                oper1+=op;
                string oper2 = oper1;

                string val2pre = pre.top();
                pre.pop();
                string val1pre = pre.top();
                pre.pop();
                pre.push(oper1.append(val1pre.append(val2pre)));
                 
                string val2post = post.top();
                post.pop();
                string val1post = post.top();
                post.pop();
                post.push((val1post.append(val2post)).append(oper2));
                
            }
            if(!ops.empty())
               ops.pop();
        }
        else{
            while(!ops.empty() && precedence(ops.top())>= precedence(tokens[i])){
                char op = ops.top();
                ops.pop();
                string oper1 = "";
                oper1+=op;
                string oper2 = oper1;

                string val2pre = pre.top();
                pre.pop();
                string val1pre = pre.top();
                pre.pop();
                pre.push(oper1.append(val1pre.append(val2pre)));
                 
                string val2post = post.top();
                post.pop();
                string val1post = post.top();
                post.pop();
                post.push((val1post.append(val2post)).append(oper2));
            }
            ops.push(tokens[i]);
            
        }
    }
    while(!ops.empty()){
        char op = ops.top();
        ops.pop();
        string oper1 = "";
        oper1+=op;
        string oper2 = oper1;

        string val2pre = pre.top();
        pre.pop();
        string val1pre = pre.top();
        pre.pop();
        pre.push(oper1.append(val1pre.append(val2pre)));
         
        string val2post = post.top();
        post.pop();
        string val1post = post.top();
        post.pop();
        post.push((val1post.append(val2post)).append(oper2));

    }
    cout<<post.top()<<endl;
    cout<<pre.top()<<endl;
}