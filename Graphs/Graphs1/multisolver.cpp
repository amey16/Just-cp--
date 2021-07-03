#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>
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

class Pair{
    int wsf;
    string psf;
    
    Pair(int wsf,string psf){
        this->wsf = wsf;
        this->psf = psf;
    }
    int compareto(Pair o){
        return this->wsf < o.wsf;
    }
};

int lpath = INT_MIN;
int spath = INT_MAX;
int cpath = INT_MAX;
int fpath = INT_MIN;
string spaths,lpaths,cielpath,floorpath;
priority_queue<pair<int,string>> pq;

void multisolver(vector<vector<Edge>> graph,int sr,int dt,vector<bool> visted,int criteria, int k, string psf, int wsf){
    
    if(sr == dt){
        if(wsf > lpath){
            lpath = wsf;
            lpaths = psf;
        }
        if(wsf < spath){
            spath = wsf;
            spaths = psf;
        }
        if(wsf > criteria && wsf < cpath){
            cpath = wsf;
            cielpath = psf;
        }
        if(wsf < criteria && wsf > fpath){
            fpath = wsf;
            floorpath = psf;
        }
        if(pq.size() < k){
            pq.push(make_pair(wsf,psf));
        }    
        else {
            if(wsf > pq.top().first){
                pq.pop();
                pq.push(make_pair(wsf,psf));
            }
        }
        
        return;
    }
    
    visted[sr] = true;
    vector<Edge> edges = graph[sr];
    for(int i = 0;i<edges.size();i++){
        Edge e = edges[i];
        if(visted[e.nbr] == false){
            multisolver(graph,e.nbr,dt,visted,criteria,k,psf+to_string(e.nbr),wsf+e.wt);
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
    
    int criteria;
    cin>>criteria;
    int k;
    cin>>k;
    
    vector<bool> visted(nvertices,false);
    multisolver(graph,sv,ev,visted,criteria,k,""+to_string(sv),0);

    return 0;
}
// NOt working properly solution only available in java
