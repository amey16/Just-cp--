import java.io.*;
import java.util.*;

public class perfectFriends {
    static class Edge {
        int v;
        int n;
      
        Edge(int v,int n){
            this.v = v;
            this.n = n;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        for(int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList<>();
        }

        int edges = Integer.parseInt(br.readLine());
        for (int i = 0; i < edges; i++) {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            graph[v1].add(new Edge(v1, v2));
            graph[v2].add(new Edge(v2, v1));
        }

        boolean[] visited = new boolean[vtces];
        ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
        for(int v = 0; v < vtces; v++){
            if(visited[v] == false){
                ArrayList<Integer> comp = new ArrayList<>();
                gcc(graph, v, visited, comp);
                comps.add(comp);
            }
        }
        int sum=0;
        for(int i=0;i<comps.size();i++){
            for(int j=i+1;j<comps.size();j++){
                int t = comps.get(i).size() * comps.get(j).size();
                sum +=t;
            }
        }
        System.out.println(sum);
    }

    public static void gcc(ArrayList<Edge>[] graph, int src, boolean[] visited, ArrayList<Integer> comp) {
        comp.add(src);
        visited[src] = true;
        for (Edge e : graph[src]) {
            if (!visited[e.n]) {
                gcc(graph, e.n, visited, comp);
            }
        }
    }

}


                        