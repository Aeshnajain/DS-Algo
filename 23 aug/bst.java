import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class bst
{

    public static class node
    {
        int data;
        node left;
        node right;
    }

    public static void display(node root)
    {
        if(root==null)
        {
            return;
        }
        String str="";
        str+=root.left==null?". ->":root.left.data+" ->";
        str+=root.data;
        str+=root.right==null?"<- .":"<- "+root.right.data;
        System.out.println(str);
        display(root.left);
        display(root.right);

    }

    public static node construct(int[] arr,int l,int h)
    {
        if(l>h)
        {
            return null;
        }
        node root=new node();
        int mid=(l+h)/2;
        root.data=arr[mid];

        root.left=construct(arr,l,mid-1);
        root.right=construct(arr,mid+1,h);

        return root;

    }

    public static boolean find(node root,int d)
    {
        if(root==null)
        {
            return false;
        }
        if(root.data==d)
        {
            return true;
        }
        if(d<root.data)
        {
            boolean l=find(root.left,d);
            if(l==true)
             return true;
            
        }
        if(d>root.data)
        {
            boolean r=find(root.right,d);
            if(r==true)
             return true;
            
        }
        return false;
    }

    public static int max(node root)
    {
        if(root.right==null)
        {
            return root.data;
        }
        else
        {
            return max(root.right);
        }
    }

    public static int min(node root)
    {
        if(root.left==null)
        {
            return root.data;
        }
        else
        {
            return min(root.left);
        }
    }

    public static node add(node root,int d)
    {
        if(root==null)
        {
            node b=new node();
            b.data=d;
            return b;
        }
        if(d<root.data)
         root.left=add(root.left,d);
        else
         root.right=add(root.right,d);
        
        return root;
    }

    public static node sub(node root,int d)
    {
        if(root==null)
        {
            return null;
            
        }
        if(d<root.data)
         root.left=sub(root.left,d);
        else if(d>root.data)
         root.right=sub(root.right,d);
        else
        {
            if(root.left==null && root.right==null)
            {
                return null;
            }
            else if(root.left!=null && root.right==null)
            {
                return root.left;
            }
            else if(root.right!=null && root.left==null)
            {
                return root.right;
            }
            else
            {
                int m=max(root.left);
                node n=new node();
                n.data=m;
                n.left=sub(root.left,m);
                n.right=root.right;

                return n;
                
            }
        }
        return root;
    

    }
    static ArrayList<Integer> al=new ArrayList<>();

    public static node sog(node root)
    {
        if(root==null)
        {
            return null;
        }
        root.right=sog(root.right);
        int sum=0;
        for(int i=0;i<al.size();i++)
        {
            sum=sum+al.get(i);
        }
        al.add(root.data);
        root.data=sum;
        root.left=sog(root.left);

        return root;


    }

    // public static int find2(node root,int d)
    // {
    //     if(root==null)
    //     {
    //         return 0;
    //     }
    //     if(root.data==d)
    //     {
    //         return d;
    //     }
    //     if(d<root.data)
    //     {
    //         int l=find2(root.left,d);
    //         if(l==d)
    //          return d;
            
    //     }
    //     if(d>root.data)
    //     {
    //         int r=find2(root.right,d);
    //         if(r==d)
    //          return d;
            
    //     }
    //     return 0;
    // }

    public static void printp(node root,int t,node r)
    {
        if(root==null)
        {
            return;
        }
         boolean l=find(r,t-root.data);
         if(l && root.data>t-root.data)
        {
            System.out.println(root.data+" "+
            (t-root.data));

        }
         


       printp(root.left,t,r);
       printp(root.right,t,r);
        
    }

    public static void printp2(node root,ArrayList<Integer> al1)
    {
        if(root==null)
        {
            return;
        }
        printp2(root.left,al1);
        al1.add(root.data);
        printp2(root.right,al1);

        
    }

    public static class pair
    {
        node n;
        int state=0;
    }


    public static void iterativeDFtraversal(node root,int t)
    {
        

        Stack<pair> ls=new Stack();
        pair p1=new pair();
        p1.n=root;
        ls.push(p1);

        Stack<pair> rs=new Stack();
        pair p2=new pair();
        p2.n=root;
        rs.push(p2);

        int lv=0;
        int rv=0;
        boolean lm=true;
        boolean rm=true;
        
        //preorder
        while(true){
        
        while(lm && ls.size()>0)
        {
            
            pair rem=ls.peek();
            if(rem.n==null)
            {
                ls.pop();
                continue;
            }
            else if(rem.state==0)
            {
                pair lc=new pair();
                lc.n=rem.n.left;
                ls.push(lc);
                rem.state=1;
            }
            else if(rem.state==1)
            {
            
                pair rc=new pair();
                lv=rem.n.data;
                rc.n=rem.n.right;
                ls.push(rc);
                rem.state=2;
                break;
            }
            else if(rem.state==2)
            {
                ls.pop();
            }
        }
            


        //postorder
        while(rm&&rs.size()>0)
        {
            
            pair rem=rs.peek();
            if(rem.n==null)
            {
                rs.pop();
                continue;
            }
            else if(rem.state==0)
            {
                pair lc=new pair();
                lc.n=rem.n.right;
                rs.push(lc);
                rem.state=1;
            }
            else if(rem.state==1)
            {
                rv=rem.n.data;
                pair rc=new pair();
                rc.n=rem.n.left;
                rs.push(rc);
                rem.state=2;
                break;
            }
            else if(rem.state==2)
            {
                rs.pop();
            }
            
            
        }

        if(lv>rv)
        {
            break;
        }
        else if(lv+rv<t)
        {
            lm=true;
            rm=false;
        }
        else if(lv+rv>t)
        {
            lm=false;
            rm=true;
        }
        else
        {
            System.out.println(lv+" "+rv);
            lm=true;
            rm=true;
        }
    }
}
    

        







    public static void main(String[] args)
    {
        int[] arr={12,25,37,50,62,75,87};
        node ans=construct(arr,0,arr.length-1);
        // display(ans);
        // boolean b=find(ans,2);
        // System.out.println(b);
        // int m=min(ans);
        // System.out.println(m);
        // node n=add(ans,89);
        // display(n);
        //node n=sub(ans,75);
        //display(n);
        // node n=sog(ans);
        // display(n);
        // al.add(0);
        int t=37;
        //printp(ans,t,ans);
        //ArrayList<Integer> al1=new ArrayList<>();
        //printp2(ans,al1);
        //int l=0;
        //int r=al1.size()-1;
        // while(l<r)
        // {
        //     int sum=al1.get(l)+al1.get(r);
        //     if(sum>t)
        //       r--;
        //     else if(sum<t)
        //       l++;
        //     else
        //     {
        //         //System.out.println(al1.get(l)+" "+al1.get(r));
        //         l++;
        //         r--;
        //     }
        // }

        iterativeDFtraversal(ans, t);


    }
}
    