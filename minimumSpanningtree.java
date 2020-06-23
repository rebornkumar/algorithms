import java.util.*;
import java.lang.*;
class Node {
    int val;
    int weigth;
    public Node(int val,int weigth) {
        this.val = val;
        this.weigth = weigth;
    }
}
class NodeComparator implements Comparator<Node> {
    public int compare(Node a,Node b) {
        if(a.weigth < b.weigth) {
            return -1;
        }
        else if(a.weigth > b.weigth) {
            return 1;
        }
        else return 0;
    }
}

class Algo {
    
    int N;
    ArrayList<ArrayList<Node>>graph;
    public void initGraph(int[][] matrix,int N,int M) {
        this.N = N;
        graph = new ArrayList<ArrayList<Node>>();
        for(int i = 0;i <= N;i++) {
            graph.add(new ArrayList<Node>());
        }
        for(int i = 0;i < M;i++) {
            Node nodeX = new Node(matrix[i][1],matrix[i][2]);
            Node nodeY = new Node(matrix[i][0],matrix[i][2]);
            //undirected
            graph.get(matrix[i][0]).add(nodeX);
            graph.get(matrix[i][1]).add(nodeY);
        }
    }
    public int getMinCost() {
        boolean[] visited = new boolean[N+1];
        PriorityQueue<Node>priorityQueue = new PriorityQueue<Node>(new NodeComparator());
        priorityQueue.add(new Node(1,0));
        int minCost = 0;
        while(priorityQueue.size() != 0) {
            Node node = priorityQueue.poll();
            if(visited[node.val] == true) continue;
            minCost += node.weigth;
            visited[node.val] = true;

            for(int i = 0;i < graph.get(node.val).size();i++) {
                Node tempNode = graph.get(node.val).get(i);
                if(visited[tempNode.val] == false) {
                    priorityQueue.add(tempNode);
                }
            }
        }
        return minCost;
    }

}
class TestClass {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        int[][] matrix = new int[M][3];
        for(int i = 0;i < M;i++) {
            matrix[i][0] = in.nextInt();
            matrix[i][1] = in.nextInt();
            matrix[i][2] = in.nextInt();
        }
        Algo algo = new Algo();
        algo.initGraph(matrix,N,M);
        int rslt = algo.getMinCost();
        System.out.println(rslt);

    }
}
