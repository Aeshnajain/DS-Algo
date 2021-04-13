import java.util.*;

public class avl
{

    public static class node
    {
        int data;
        node left;
        node right;
        int ht=1;
        int bal=0;
    }

    public static void display(node root)
    {
        if(root==null)
        {
            return;
        }
        String str="";
        str+=root.left==null?". ->":root.left.data+" ->";
        str+=root.ht+"_"+root.data+"_"+root.bal;
        str+=root.right==null?"<- .":"<- "+root.right.data;
        System.out.println(str);
        display(root.left);
        display(root.right);

    }

    public static int getht(node root)
    {
        int lh=root.left==null?0:root.left.ht;
        int rh=root.right==null?0:root.right.ht;
        return Math.max(lh,rh)+1;
    }

    public static int getbal(node root)
    {
        int lh=root.left==null?0:root.left.ht;
        int rh=root.right==null?0:root.right.ht;
        return lh-rh;
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

        root.ht=getht(root);
        root.bal=getbal(root);

        return root;

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

        root.ht=getht(root);
        root.bal=getbal(root);

        if(root.bal>1)
        {
            if(root.left.bal>=0)
            {
                root=rightrot(root);
            }
            else
            {
                root.left=leftrot(root.left);
                root=rightrot(root);
            }
        }
        else if(root.bal<-1)
        {
            if(root.right.bal<=0)
            {
                root=leftrot(root);
            }
            else
            {
                root.right=rightrot(root.right);
                root=leftrot(root);
            }

        }
        
        return root;
    }

    public static node rightrot(node x)
    {
        node y=x.left;
        node t3=y.right;
        x.left=t3;
        y.right=x;

        x.ht=getht(x);
        x.bal=getbal(x);
        y.ht=getht(y);
        y.bal=getbal(y);

        return y;
    }

    public static node leftrot(node x)
    {
        node y=x.right;
        node t2=y.left;
        x.right=t2;
        y.left=x;

        x.ht=getht(x);
        x.bal=getbal(x);
        y.ht=getht(y);
        y.bal=getbal(y);

        return y;
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
                root= root.left;
            }
            else if(root.right!=null && root.left==null)
            {
                root= root.right;
            }
            else
            {
                int m=max(root.left);
                node n=new node();
                n.data=m;
                n.left=sub(root.left,m);
                n.right=root.right;

                root=n;
                
            }
        }
        root.ht=getht(root);
        root.bal=getbal(root);

        if(root!=null)
        {
            if(root.bal>1)
            {
                if(root.left.bal>=0)
                {
                    root=rightrot(root);
                }
                else
                {
                    root.left=leftrot(root.left);
                    root=rightrot(root);
                }
            }
            else if(root.bal<-1)
            {
                if(root.right.bal<=0)
                {
                    root=leftrot(root);
                }
                else
                {
                    root.right=rightrot(root.right);
                    root=leftrot(root);
                }
    
            }

        }
        return root;
    

    }


    public static void main(String[] args)
    {
        int[] sa={12,25,37,50,62,75,87};
        node root=construct(sa, 0, sa.length-1);
        node ans=add(root,30);
        ans=add(root,28);
        ans=add(root,29);
        ans=sub(root,28);
        display(ans);

    }
}

