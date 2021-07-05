#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<utility>
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
class Pair{
    public:
        int v;
        int va;
        int wt;
        Pair(int v,int va,int wt){
            this->v = v;
            this->va = va;
            this->wt = wt;
        }
};
struct CompareWeight {
    bool operator()(Pair const& p1, Pair const& p2)
    {
        return p1.wt >= p2.wt;
    }
};
int main(){
    int nedges,nvertices;
    cin>>nedges;
    cin>>nvertices;
    
    for(int i=0;i<nedges;i++){
        graph.push_back(vector<Edge>());
    }
    int v1,v2,wt;
    for(int i=0;i<nvertices;i++){
        cin>>v1>>v2>>wt;
        addEdge(v1,v2,wt);
    }
    
    vector<bool> visited(nedges,false);
    priority_queue<Pair,vector<Pair>,CompareWeight> pq;
    
    pq.push(Pair(0,-1,0));
    while(!pq.empty()){
        Pair p = pq.top();
        pq.pop();
        
        if(visited[p.v] == true)
            continue;
        visited[p.v] = true;
        
        if(p.va >=0)
            cout<<"["<<p.v<<"-"<<p.va<<"@"<<p.wt<<"]"<<endl;
        for(int i=0;i<graph[p.v].size();i++){
            Edge e = graph[p.v][i];
            if(visited[e.nbr] == false){
                pq.push(Pair(e.nbr,p.v,e.wt));
            }
        }
    }
}