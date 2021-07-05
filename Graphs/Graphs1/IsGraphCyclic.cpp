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
        string psf;
        int level;
        Pair(int v,string psf,int level){
            this->v = v;
            this->psf = psf;
            this->level = level;
        }
};
bool isBipartite(int src,queue<Pair> q,vector<int>& visited){
    string psf = to_string(src);
    q.push(Pair(src,psf,0));

    while(!q.empty()){
        Pair node = q.front();
        q.pop();
        if(visited[node.v] != -1){
            if(node.level != visited[node.v])
                return false;
            continue;
        }
        visited[node.v] = node.level;
        for(int i=0;i<graph[node.v].size();i++){
            Edge e = graph[node.v][i];
            if(visited[e.nbr] == -1){
                q.push(Pair(e.nbr,node.psf+to_string(e.nbr),node.level+1));
            }
        }
    }
    return true;
}
int main(){
    int nedges;
    cin>>nedges;
    for(int i=0;i<nedges;i++){
        graph.push_back(vector<Edge>());
    }
    int nvertices;
    cin>>nvertices;
    for(int i = 0;i < nvertices; i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        addEdge(v1,v2,wt);
    }
    
    queue<Pair> q;
    vector<int> visited(nedges,-1);

    for(int src=0;src<nedges;src++){    
        if(visited[src] == -1){
            if(isBipartite(src,q,visited) == false){
                cout<<"false"<<endl;
                return 0;
            }
        }
    }
    cout<<"true"<<endl;
}