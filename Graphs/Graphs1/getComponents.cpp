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
void getComponents(vector<vector<Edge>> graph,int src,vector<int>& comp,vector<bool>& visted){
    visted[src] = true;
    comp.push_back(src);
    for(int i = 0;i<graph[src].size();i++){
        Edge eb = graph[src][i];
        if(visted[eb.nbr] == false){
            getComponents(graph,eb.nbr,comp,visted);
        }
    }
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
    
    vector<bool> visted(nvertices,false);
    vector<vector<int>> components;
    for(int i =0 ;i<visted.size();i++){
        if(visted[i] == false){
            
            vector<int> comp;
            getComponents(graph,i,comp,visted);
            components.push_back(comp);
        }
    }
    // display();
    cout<<components.size()<<" ";
    cout<<"[";
    for(int i =0 ;i < components.size();i++){
        // cout<<"[";
        for(int j=0;j<components[i].size();j++){
            if(j==0){
                cout<<"["<<components[i][j]<<",";
            }
            else if(j == components[i].size()-1){
                cout<<" "<<components[i][j]<<"]";
            }
            else{
                cout<<" "<<components[i][j]<<",";
            }
        }
        if(i!=components.size()-1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    // for(int i=0;i<components)
    cout<<endl;

    return 0;
}
