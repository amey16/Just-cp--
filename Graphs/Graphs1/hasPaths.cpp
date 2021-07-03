#include<iostream>
#include<vector>
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
bool haspath(vector<vector<Edge>> graph,int sr,int dt,vector<bool> visted){
    
    if(sr == dt){
        return true;
    }
    
    visted[sr] = true;
    vector<Edge> edges = graph[sr];
    for(int i = 0;i<edges.size();i++){
        Edge e = edges[i];
        if(visted[e.nbr] == false){
            bool hp = haspath(graph,e.nbr,dt,visted);
            if(hp == true){
                return true;
            }
        }
    }
    return false;
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
    bool ans = haspath(graph,sv,ev,visted);
    // display();
    if(ans)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
