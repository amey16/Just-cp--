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
// class Pair{
//     public:
//         int v;
//         string psf;
//         Pair(int v,string psf){
//             this->v = v;
//             this->psf = psf;
//         }
// };
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
    int src;
    cin>>src;
    
    // Pair()
    queue<pair<int,string>> q;
    
    string psf = ""+to_string(src);
    q.push(make_pair(src,psf));
    vector<bool> visted(nedges,false);
    
    while(!q.empty()){
        pair<int,string> e = q.front();
        q.pop();
        
        // int vert = e.v
        if(visted[e.first] == true){
            continue;
        }
        visted[e.first] = true;
        cout<<e.first<<"@"<<e.second<<endl;
        
        for(int i=0;i<graph[e.first].size();i++){
            Edge vi = graph[e.first][i];
            if(visted[vi.nbr] == false){
                q.push(make_pair(vi.nbr,e.second+to_string(vi.nbr)));
            }
        }
        
    }
}