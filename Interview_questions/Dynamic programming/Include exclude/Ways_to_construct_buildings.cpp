//https://www.geeksforgeeks.org/count-possible-ways-to-construct-buildings/

#include<iostream>
using namespace std;

int countBuildings(int n){
    int a=1,b=1;
    for(int i=1;i<n;i++){
        int temp = a;
        a = a+b;
        b = temp;
    }
    return a+b;
}
 
int main(){
    cout<<countBuildings(3) * countBuildings(3)<<endl;
    return 0;
}