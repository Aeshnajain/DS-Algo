import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class kruskals
{
    public static class edge
    {
        int nbr;
        int wt;
        edge(int nbr,int wt)
        {
            this.nbr=nbr;
            this.wt=wt;
        }
    }

    public static class kruskaledge implements Comparable<kruskaledge>
    {
        int v1;
        int v2;
        int wt;

        kruskaledge(int v1,int v2,int wt)
        {
            this.v1=v1;
            this.v2=v2;
            this.wt=wt;
        }
        public int compareTo(kruskaledge other)
        {
            return this.wt-other.wt;
        }
    }
    static ArrayList<ArrayList<edge> > graph=new ArrayList<>();

    public static void addedge(ArrayList<ArrayList<edge> > g,int v1,int v2,int wt)
    {
        edge e1=new edge(v2,wt);
        g.get(v1).add(e1);

        edge e2=new edge(v1,wt);
        g.get(v2).add(e2);
    }

    public static void display(ArrayList<ArrayList<edge> > g)
    {
        for(int i=0;i<g.size();i++)
        {
            System.out.print(i+"->");
            for(int j=0;j<g.get(i).size();j++)
            {
                edge ne=g.get(i).get(j);
                System.out.print("["+ne.nbr+"->"+ne.wt+"]");
            }
            System.out.println();
        }
    }

    public static void merge(int v1sl,int v2sl,int[] pa,int[] ra)
    {
        if(ra[v1sl]<ra[v2sl])
        {
            pa[v1sl]=v2sl;
        }
        else if(ra[v2sl]<ra[v1sl])
        {
            pa[v2sl]=v1sl;
        }
        else
        {
            pa[v1sl]=v2sl;
            ra[v2sl]++;
        }
    }

    public static int find(int[] pa,int v)
    {
        //return pa[v];cant do this because this will give wrong ans on merging of parent trees
        if(pa[v]==v)
        {
            return v;
        }
        else
        {
            return find(pa,pa[v]);
        }
    }

    public static void krus(ArrayList<ArrayList<edge> > g)
    {
        ArrayList<ArrayList<edge> > mst =new ArrayList<>();
        int[] pa=new int[g.size()];
        int[] ra=new int[g.size()];
        for(int i=0;i<g.size();i++)
        {
            pa[i]=i;
            ra[i]=1;
            mst.add(new ArrayList<edge>());
        }
        PriorityQueue<kruskaledge> pq=new PriorityQueue<>();


        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g.get(i).size();j++)
            {
                edge ne=g.get(i).get(j);
                if(i<ne.nbr)
                {
                    kruskaledge ke=new kruskaledge(i,ne.nbr,ne.wt);
                    pq.add(ke);
                }

            }

        }
        while(pq.size()>0)
        {
            kruskaledge ke=pq.remove();
            int v1=ke.v1;
            int v2=ke.v2;

            int v1sl=find(pa,v1);
            int v2sl=find(pa,v2);

            if(v1sl!=v2sl)
            {
                addedge(mst,v1,v2,ke.wt);
                merge(v1sl,v2sl,pa,ra);
            }


        }
        display(mst);

    }
    public static void main(String[] args)
    {
        graph.add(new ArrayList<edge>());
        graph.add(new ArrayList<edge>());
        graph.add(new ArrayList<edge>());
        graph.add(new ArrayList<edge>());
        graph.add(new ArrayList<edge>());
        graph.add(new ArrayList<edge>());
        graph.add(new ArrayList<edge>());

        addedge(graph,0,1,20);
        addedge(graph,1,2,10);
        addedge(graph,2,3,20);
        addedge(graph,0,3,40);
        addedge(graph,2,5,5);
        addedge(graph,3,4,2);
        addedge(graph,4,5,3);
        addedge(graph,5,6,8);
        addedge(graph,4,6,8);

        //display(graph);

        krus(graph);
    }
}