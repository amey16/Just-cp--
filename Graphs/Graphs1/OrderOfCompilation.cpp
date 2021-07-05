#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Edge{
    public:
        int nbr;
};
vector<vector<Edge>> graph;
void addEdgeDirected(int v1,int v2){
    Edge e1;
    e1.nbr = v2;
    graph[v1].push_back(e1);
}
void topologicalSort(int src,vector<bool>& visited,stack<int>& s){
    
    visited[src] = true;
    for(int i=0;i<graph[src].size();i++){
        Edge e = graph[src][i];
        if(visited[e.nbr] == false)
            topologicalSort(e.nbr,visited,s);
    }
    s.push(src);
}
int main(){
    int nedges,nvertices;
    cin>>nedges;
    cin>>nvertices;
    
    for(int i=0;i<nedges;i++){
        graph.push_back(vector<Edge>());
    }
    int v1,v2,wt;
    for(int i=0;i<nvertices;i++){
        cin>>v1>>v2;
        addEdgeDirected(v1,v2);
    }
    
    vector<bool> visited(nedges,false);
    stack<int> s;
    for(int i = 0 ; i < nedges ; i++){
        if(visited[i] == false){
            topologicalSort(i,visited,s);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
