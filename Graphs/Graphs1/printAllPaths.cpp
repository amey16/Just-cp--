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
void getALLpath(vector<vector<Edge>> graph,int sr,int dt,vector<bool> visted,string pathsf){
    
    if(sr == dt){
        cout<<pathsf<<endl;
        return;
    }
    
    visted[sr] = true;
    vector<Edge> edges = graph[sr];
    for(int i = 0;i<edges.size();i++){
        Edge e = edges[i];
        if(visted[e.nbr] == false){
            getALLpath(graph,e.nbr,dt,visted,pathsf+to_string(e.nbr));
        }
    }
    visted[sr] = false;
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
    int sv,ev;
    cin>>sv;
    cin>>ev;
    
    vector<bool> visted(nvertices,false);
    getALLpath(graph,sv,ev,visted,""+to_string(sv));

    return 0;
}
