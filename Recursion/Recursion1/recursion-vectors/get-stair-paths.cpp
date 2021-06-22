# include<iostream>
# include<vector>
# include<string>
using namespace std;

vector<string> paths(int num){
    if(num < 0){
        return {};
    }
    if(num == 0){
        return {""};
    }
    vector<string> temp1 = paths(num - 1);
    vector<string> temp2 = paths(num - 2);
    vector<string> temp3 = paths(num - 3);
    vector<string> ans;
    for (string s: temp1){
        ans.push_back("1"+s);
    }
    for (string s: temp2){
        ans.push_back("2"+s);
    }
    for (string s: temp3){
        ans.push_back("3"+s);
    }
    return ans;
}

int main(){
    int num;
    cin>>num;
    vector<string> ans = paths(num);
    cout<<"[";
    for (int i = 0; i < ans.size();i++){
        cout<<ans[i];
        if(i != ans.size()-1)
            cout<<", ";
    }
    cout<<"]";
}