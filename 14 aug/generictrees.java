import java.util.*;

public class generictrees
{
    public static class node
    {
        int data=0;
        ArrayList<node>children=new ArrayList<>();

        node(int data)
        {
            this.data=data;
        }
    }
    public static node constructor(int[] arr)
    {
        LinkedList<node> st=new LinkedList<>();
        node root=arr.length>0?new node(arr[0]):null;
        st.addFirst(root);

        for(int i=1;i<arr.length;i++)
        {
            if(arr[i]==-1)
            {
                st.removeFirst();
            }
            else
            {
                node n=new node(arr[i]);
                st.getFirst().children.add(n);
                st.addFirst(n);
            }
            
        }
        
        return root;
    }

    public static void display(node root)
    {
        System.out.print(root.data+"->");
        for(node child:root.children)
        {
            System.out.print(child.data+" ");
        }
        System.out.println(".");
        for(node child:root.children)
        {
            display(child);
        }
    }

    public static boolean find(node root,int t)
    {
        
        if(root.data==t)
         return true;
        boolean res=false;
        for(node child:root.children)
        {
            res=res||find(child,t);
        }
        return res;
    }

    public static int minval(node root)
    {
        int min1=root.data;
        for(node child:root.children)
        {
            int recmin=minval(child);
            min1=Math.min(min1,recmin);
        }
        return min1;
    }

    public static int height(node root)
    {
        int h=-1;
        for(node child:root.children)
        {
            int recans=height(child);
            h=Math.max(h,recans);
        }
        return h+1;
        
        
    }

     public static int size(node root)
     {
         int size=0;
         for(node child:root.children)
         {
             size+=size(child);
         }
         return size+1;

     }
     public static ArrayList<node> path(node root,int o1)
     {
         if(root.data==o1)
         {
             ArrayList<node> p=new ArrayList<>();
             p.add(root);
             return p;
        
         }
         for(node child:root.children)
         {
             ArrayList<node> recp=path(child,o1);
             if(recp.size()>0)
             {
                 recp.add(root);
                 return recp;
             }
         }

         return new ArrayList<>();

     }

     public static int lca(node root,int o1,int o2)
     {
        if(find(root,o1) && find(root,o2))
        {
            ArrayList<node> p1=path(root,o1);
            ArrayList<node> p2=path(root,o2);
            for(int i=p1.size()-1,j=p2.size()-1;i>=0 && j>=0;i--,j--)
            {
                if(p1.get(i).data!=p2.get(j).data)
                 return p1.get(i+1).data;
                else if(i==0)
                 return p1.get(i).data;
                else if(j==0)
                 return p2.get(j).data;
            }
            return -1;
        }
        else
         return -1;
    }

    public static void bfp(node root)
    {
        LinkedList<node> q=new LinkedList<>();
        q.addFirst(root);
        while(q.size()>0)
        {
            node n=q.getFirst();
            q.pop();
            System.out.print(n.data+" ");
            for(node child:n.children)
            {
                q.addLast(child);
            }
        }
        System.out.println();


    }

    public static void bfp2a(node root)
    {
        LinkedList<node> q1=new LinkedList<>();
        LinkedList<node> q2=new LinkedList<>();
        q1.addFirst(root);
        while(q1.size()>0)
        {
            node n=q1.getFirst();
            q1.pop();
            System.out.print(n.data+" ");
            for(node child:n.children)
            {
                q2.addLast(child);
            }
            if(q1.size()==0)
            {
                System.out.println();
                LinkedList<node> temp=q1;
                q1=q2;
                q2=temp;

            }
        }


    }

    public static void bfp2b(node root)
    {
        LinkedList<node> q1=new LinkedList<>();
        q1.addFirst(root);
        q1.addLast(null);
        while(q1.size()>1)
        {
            node n=q1.getFirst();
            q1.pop();
            if(n==null)
            {
                System.out.println();
                q1.addLast(null);

            }
            else
            {
                System.out.print(n.data+" ");
               for(node child:n.children)
               {
                  q1.addLast(child);
                }
            }
            
            
        }


    }

    public static void bfp2c(node root)
    {
        LinkedList<node> q=new LinkedList<>();
        q.addLast(root);
        while(q.size()>0)
        {
            int s=q.size();
            while(s-->0)
            {
                node n=q.getFirst();
                q.pop();
                System.out.print(n.data+" ");
                for(node child:n.children)
                {
                    q.addLast(child);
                }

            }
            System.out.println();
        }
    }

    public static void bfc3(node root)
    {
        LinkedList<node> s1=new LinkedList<>();
        LinkedList<node> s2=new LinkedList<>();
        s1.addFirst(root);
        boolean flag=true;
        while(s1.size()>0)
        {
            node n=s1.getFirst();
            s1.removeFirst();
            System.out.print(n.data+" ");
            if(flag==true)
            {
                for(node child:n.children)
                {
                    s2.addLast(child);
                }
            }
            else
            {
                for(node child:n.children)
                {
                    s2.addFirst(child);
                }
            }
            if(s1.size()==0)
            {
                System.out.println();
                LinkedList<node> temp=s1;
                s1=s2;
                s2=temp;
                flag=!flag;
            }



        }


    }

    public static class hmpair
    {
        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        boolean find=false;

        int p=-1;
        int s=-1;
        int f=Integer.MIN_VALUE;
        int c=Integer.MAX_VALUE;
    }

    static int prev=0;

    public static void multisolver(node root,int t,hmpair hmp)
    {
    
        if(hmp.find==false && root.data==t)
        {
           hmp.find=true;
           hmp.p=prev;
        }

        if(hmp.find==true && prev==t)
         hmp.s=root.data;
        
        hmp.max=Math.max(root.data,hmp.max);
        hmp.min=Math.min(root.data,hmp.min);

        if(root.data<t && root.data>hmp.f)
        {
            hmp.f=root.data;
        }

        if(root.data>t && root.data<hmp.c)
        {
            hmp.c=root.data;
        }

        prev=root.data;

        for(node child:root.children)
        {
            multisolver(child,t,hmp);
        }



    }

    

    public static void kthlargest(node root,int k)
    {
        hmpair hmp1=new hmpair();
        int l=Integer.MAX_VALUE;
        for(int i=0;i<k;i++)
        {
            multisolver(root,l,hmp1);
            l=hmp1.f;
            hmp1.f=Integer.MIN_VALUE;
        }
        System.out.println(l);

    }

    public static void kthsmallest(node root,int k)
    {
        hmpair hmp1=new hmpair();
        int s=Integer.MIN_VALUE;
        for(int i=0;i<k;i++)
        {
            multisolver(root,s,hmp1);
            s=hmp1.c;
            hmp1.c=Integer.MAX_VALUE;
        }
        System.out.println(s);

    }
    public static void main(String[] args)
    {
        int[] arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
        node ans=constructor(arr);
        System.out.println(ans);
        display(ans);
        int t=80;
        boolean n=find(ans,t);
        System.out.println(n);
        int a=minval(ans);
        System.out.println(a);
        int h=height(ans);
        System.out.println(h);
        int s=size(ans);
        System.out.println(s);
        int o1=120;
        int o2=60;
        int l=lca(ans,o1,o2);
        System.out.println(l);
        bfp(ans);
        bfp2a(ans);
        bfp2b(ans);
        bfp2c(ans);
        bfc3(ans);
        hmpair hmp=new hmpair();
        
        multisolver(ans,t,hmp);

        System.out.println(hmp.max+" "+hmp.min+" "+hmp.find+" "+hmp.p+" "+hmp.s+" "+hmp.f+" "+hmp.c);

        kthlargest(ans,3);
        kthsmallest(ans,3);
        
    

    }
}