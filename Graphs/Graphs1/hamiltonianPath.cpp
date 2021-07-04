#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Edge{
    public:
        int nbr;
        int wt;
};
vector<vector<Edge>> graph;
void addEdge(int v1,int v2,int wt){
    Edge e1;
    e1.nbr = v2;
    e1.wt = wt;
    graph[v1].push_back(e1);

    Edge e2;
    e2.nbr = v1;
    e2.wt = wt;
    graph[v2].push_back(e2);
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<< i << "->";
        for(int j=0;j<graph[i].size();j++){
            Edge e1 = graph[i][j];
            cout<<"["<<e1.nbr<<"-"<<e1.wt<<"]";
        }
        cout<<"."<<endl;
    }
}
bool isvisted(vector<bool>visted){
    for(int i=0;i<visted.size();i++){
        if(visted[i] == false)
            return false;
    }
    return true;
}
void getAllPaths(vector<vector<Edge>> graph,int v1,string bsf,int cnt,int os,vector<bool>& visted){
    if(cnt==graph.size()-1){
        cout<<bsf+to_string(v1);
        for(int i=0;i<graph[v1].size();i++){
            Edge ne=graph[v1][i];
            if(ne.nbr == os){
                cout<<"*"<<endl;
                return;
            }
        }   
        cout<<"."<<endl;
        return;
    }

    visted[v1]=true;    
    for(int i=0;i<graph[v1].size();i++){
        Edge ne =graph[v1][i];
        if(visted[ne.nbr]==false)
            getAllPaths(graph,ne.nbr,bsf+to_string(v1),cnt+1,os,visted);
    }
    visted[v1]=false;

}

int main(){
    int nedges;
    cin>>nedges;
    for(int i=0;i<nedges;i++){
        graph.push_back(vector<Edge>());
    }
    int nvertices;
    cin>>nvertices;
    for(int i=0;i<nvertices;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        addEdge(v1,v2,wt);
    }
    int sv;
    cin>>sv;
    
    vector<bool> visited(nedges,false);
    getAllPaths(graph,sv,"",0,sv,visited);

    return 0;
}