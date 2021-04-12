import java.util.*;

public class graphs
{
    public edge
    {
        int nbr;
        int wght;
    }
    static ArrayList<ArrayList<edge>> graph=new ArrayList<>();

    public static void display()
    {
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                edge ne=graph[i][j];
                System.out.print("the neighbour is ["+ne.nbr+"->"+ne.weight);
            }
        }
    }

    public static void addedge(int v1,int v2,int weight)
    {
        edge e1;
        e1.nbr=v2;
        e2.wght=weight;
        graph[v1].add(e1);
        edge e2;
        e1.nbr=v1;
        e2.wght=weight;
        graph[v2].add(e2);
    }

    public static void main(String[] args)
    {
       graph.add(0,new ArrayList<edge>());
       graph.add(1,new ArrayList<edge>());
       graph.add(2,new ArrayList<edge>());
       graph.add(3,new ArrayList<edge>());
       graph.add(4,new ArrayList<edge>());
       graph.add(5,new ArrayList<edge>());
       graph.add(6,new ArrayList<edge>());

       addedge(0,1,10);
       addedge(1,2,10);
       addedge(2,3,10);
       addedge(0,3,40);
       addedge(3,4,2);
       addedge(4,5,3);
       addedge(5,6,3);
       addedge(4,6,8);

    }
}