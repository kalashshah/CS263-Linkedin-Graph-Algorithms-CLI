import java.util.*;

public class jay_algo {
    static void DFS(int s, Vector<Integer> [] g, int[] v)
    {
        for (int i : g[s]) {

            // If current vertex is not visited yet
            if (v[i] == 0) {
                v[i] = 1;

                // Recursive call for dfs function
                DFS(i, g, v);
            }
        }
    }
    // Function to find the out the minimum number of edges that must be removed to remove all the existing path between nodes
    static int deleteEdges(int n, int m, int a, int b, int[][] edges)
    {

        // Creating Adjacency Matrix
        Vector<Integer> vectors[] = new Vector[n];
        for (int i = 0; i < vectors.length; i++){
            vectors[i] = new Vector<Integer>();
        }
        for (int i = 0; i < m; i++) {
            vectors[edges[i][0] - 1].add(edges[i][1] - 1);
            vectors[edges[i][1] - 1].add(edges[i][0] - 1);
        }

        // Vector for marking visited array
        int v[] = new int[n];
        v[a - 1] = 1;

        // Calling dfs function
        DFS(a - 1, vectors, v);

        int count = 0;

        for (int i = 0; i < n; i++) {

            // If current node can not be visited from node A
            if (v[i] == 0)
                continue;
            for (int j = 0; j < vectors[i].size(); j++) {

                // If a node between current node and node b exist
                if (vectors[i].get(j) == b - 1) {
                    count++;
                }
            }
        }
        // Return Answer count
        return count;
    }
    public static void main(String[] args) {
        int N = 5;
//        M is no of Edges in Graph
        int M = 6;
//        vertices A and B from where we are supposed to remove all the existing path
        int A = 3;
        int B = 2;
        int[][] Edges ={
                {3,1},{3,4},{1,2},{4,2},{3,5},{5,4}
        };

        System.out.print(deleteEdges(N, M, A, B, Edges));
    }
}