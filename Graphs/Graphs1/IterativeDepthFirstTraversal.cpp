#include<iostream>
#include<vector>
#include<stack>
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

class Pair{
  public:
      int v;
      string psf;
      Pair(int v,string psf){
        this->v = v;
        this->psf = psf;
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
    
    int src;
    cin>>src;
    
    vector<bool> visited(nedges,false);
    stack<Pair> s;
    s.push(Pair(src,to_string(src)));
    
    // cout<<"1"<<endl;
    while(!s.empty()){
        
        Pair node = s.top();
        s.pop();
        
        if(visited[node.v] == true)
            continue;
        visited[node.v] = true;
        
        cout<<node.v<<"@"<<node.psf<<endl;
        for(int i=0;i<graph[node.v].size();i++){
            Edge e = graph[node.v][i];
            if(visited[e.nbr] == false)
                s.push(Pair(e.nbr,node.psf + to_string(e.nbr)));
        }
    }
}