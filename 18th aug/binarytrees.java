import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class binarytrees
{

    public static class node
    {
        int data;
        node left;
        node right;
    }

    public static node construct(int[] arr)
    {
        node root=null;
       Stack<node> st=new Stack<>();
       for(int i:arr)
       {
           if(i==-1)
           {
               st.pop();
           }
           else
           {
               node n=new node();
               n.data=i;
               if(st.size()==0)
               {
                   root=n;
               }
               else
               {
                   if(st.peek().left==null)
                   {
                       st.peek().left=n;
                   }
                   else
                   {
                       st.peek().right=n;
                   }
               }
               st.push(n);
           }
       }
       return root;
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

    public static int size(node root)
    {
        if(root==null)
        {
            return Integer.MIN_VALUE;
        }
        int l=size(root.left);
        int r=size(root.right);
        int t=l+r+1;
        return t;

    }

    public static int max(node root)
    {
        if(root==null)
        {
            return 0;
        }
        int ml=max(root.left);
        int mr=max(root.right);
        int max=Math.max(mr,ml);
        max=Math.max(max,root.data);
        return max;
    }

    public static int height(node root)
    {
        if(root==null)
        {
            return 0;
        }

        int lh=height(root.left);
        int rh=height(root.right);
        int th=Math.max(rh,lh)+1;
        return th;

    }

    public static boolean find(node root,int t)
    {
        if(root==null)
        {
            return false;
        }
        if(root.data==t)
        {
            return true;
        }
        else
        {
            boolean fl=find(root.left,t);
            if(fl)
             return true;
            boolean fr=find(root.right,t);
            if (fr)
             return true;
        }
        return false;
        
    }

    public static ArrayList<Integer> ntrp(node root,int t)
    {
        if(root==null)
        {
            return new ArrayList<>();
        }
        if(root.data==t)
        {
            ArrayList<Integer> list=new ArrayList<>();
            list.add(root.data);
            return list;

        }
        else
        {
            ArrayList<Integer> fl=ntrp(root.left,t);
            if(fl.size()>0)
            {
              fl.add(root.data);
              return fl;
            }
            ArrayList<Integer> fr=ntrp(root.right,t);
            if (fr.size()>0)
            {
             fr.add(root.data);
             return fr;
            }
        }
        return new ArrayList<>();
        
    }

    public static void rl(node root) //remove_leaves
    {
        if(root.left!=null)
        {
            if(root.left.left==null && root.left.right==null)
            {
                root.left=null;
            }
            else 
             rl(root.left);

        }
        if(root.right!=null)
        {
            if(root.right.left==null && root.right.right==null)
             root.right=null;
            else
             rl(root.right);
        }
        
    }

    public static node rl2(node root)
    {
        if(root.left!=null && root.right!=null)
        {
            root.left=rl2(root.left);
            root.right=rl2(root.right);
            return root;

        }
        else if(root.left!=null)
        {
            root.left=rl2(root.left);
            return root;
        }
        else if(root.right!=null)
        {
            root.right=rl2(root.right);
            return root;
        }
        else
        {
            return null;

        }
    }

    public static void ntsc(node root) //print_parent_with_single_child
    {
        if(root.left==null && root.right==null)
        {
            return;
        }
        else if(root.left!=null && root.right==null)
        {
            System.out.println(root.left.data);
            ntsc(root.left);
        }
        else if(root.left==null && root.right!=null)
        {
            System.out.println(root.right.data);
            ntsc(root.right);
        }
        else
        {
            ntsc(root.right);
            ntsc(root.left);

        }
    }

    //sum of node to root should be in the range

    public static void pir(node root,int lo,int hi,int ssf,String psf)
    //print in range(sum)
    {
        if(root.left==null && root.right==null)
        {
            ssf+=root.data;
            psf+=root.data+" ";

            if(ssf>=lo && ssf<=hi)
             System.out.println(psf);
            return;
        }
        pir(root.left,lo,hi,ssf+root.data,psf+root.data+" ");
        pir(root.right,lo,hi,ssf+root.data,psf+root.data+" ");



    }

    //transforming linkedlist by making a copy and adding to the left

    public static node tld(node root) 
    {
        if(root==null)
        {
            return null;
        }
        root.left=tld(root.left);
        root.right=tld(root.right);
        node n=new node();
        n.data=root.data;
        n.left=root.left;
        n.right=null;
        root.left=n;

        return root;

    }
    
    //getting the tree back

    public static node tbld(node root)
    {
        if(root==null)
        {
            return null;
        }

        root.left=tbld(root.left.left);
        root.right=tbld(root.right);

        return root;
    }

    public static node con2(int[] pre,int psi,int pei,int[] in,int isi,int iei)
    {
        if(psi>pei || isi>iei)
        {
            return null;
        }
        node n=new node();
        n.data=pre[psi];
        int x=0;

        for(int i=isi;i<=iei;i++)
        {
            if(in[i]==pre[psi])
            {
                x=i;
                break;
            }
             
        }
        int lhs=x-isi;
    
         n.left=con2(pre,psi+1,psi+lhs,in,isi,x-1);
         n.right=con2(pre,psi+lhs+1,pei,in,x+1,iei);
        return n;



    }

    public static node con3(int[] post,int psi,int pei,int[] in,int isi,int iei)
    {
        if(psi>pei || isi>iei)
        {
            return null;
        }
        node root=new node();
        root.data=post[pei];
        int x=0;

        for(int i=isi;i<=iei;i++)
        {
            if(in[i]==post[pei])
            { 
                x=i;
                break;
            }
             
        }
        // int rhs=iei-x;

        // root.left=cons( post,psi,pei-rhs-1,in,isi,x-1);
        // root.right=cons( post,pei-rhs,pei-1, in,x+1,iei);
        int lhs=x-isi;
        root.left=con3( post,psi,psi+lhs-1,in,isi,x-1);
        root.right=con3( post,psi+lhs,pei-1, in,x+1,iei);

        return root;
        
        
    }

    public static node con4(int[] pre,int prsi,int prei,int[] post,int psi,int pei)
    {
        if(prsi>prei || psi>pei )
        {
            return null;
        }
        node n=new node();
        n.data=pre[prsi];

        int x=0;
        for(int i=psi;i<=pei;i++)
        {
            if(prsi+1<=prei)
            {
                if(pre[prsi+1]==post[i])
                {
                    x=i;
                    break;
                }
            }
            else
            {
                node b=new node();
                b.data=pre[prsi];
                return b;
            }
        }

        int lhs=x-psi+1;
        n.left=con4(pre,prsi+1,prsi+lhs,post,psi,psi+lhs-1);
        n.right=con4(pre,prsi+lhs+1,prei,post,psi+lhs,pei-1);

        return n;
    }

    public static class pair
    {
        node n;
        int state=0;
    }

    public static void iterativeDFtraversal(node root)
    {
        ArrayList<Integer> pre=new ArrayList<>();
        ArrayList<Integer> in=new ArrayList<>();
        ArrayList<Integer> post=new ArrayList<>();

        Stack<pair> st=new Stack();
        pair p=new pair();
        p.n=root;
        st.push(p);
        
        while(st.size()>0)
        {
            
            pair rem=st.peek();
            if(rem.n==null)
            {
                st.pop();
                continue;
            }
            else if(rem.state==0)
            {
                pre.add(rem.n.data);
                pair lc=new pair();
                lc.n=rem.n.left;
                st.push(lc);
                rem.state=1;
            }
            else if(rem.state==1)
            {
                in.add(rem.n.data);
                pair rc=new pair();
                rc.n=rem.n.right;
                st.push(rc);
                rem.state=2;
            }
            else if(rem.state==2)
            {
                post.add(rem.n.data);
                rem.state=3;
            }
            else if(rem.state==3)
            {
                st.pop();
            }
            
        }

        System.out.println("pre ->"+pre);
        System.out.println("in ->"+in);
        System.out.println("post ->"+post);




    }

    public static int diameter1(node root)
    {
        if(root==null)
        {
            return 0;
        }

        int lh=height(root.left);
        int rh=height(root.right);
        int f=lh+rh+1;

        int d1=diameter1(root.left);
        int d2=diameter1(root.right);

        return Math.max(f,Math.max(d1,d2));

    }

    public static class diapair
    {
        int dia;
        int ht;
    }

    public static diapair diameter2(node root)
    {
        if(root==null)
        {
            diapair d=new diapair();
            d.dia=0;
            d.ht=0;
            return d;

        }
        diapair ld=diameter2(root.left);
        diapair rd=diameter2(root.right);
        diapair nd=new diapair();

        nd.dia=Math.max(ld.ht+rd.ht+1,Math.max(ld.dia,rd.dia));
        nd.ht=Math.max(ld.ht,rd.ht)+1;

        return nd;
    }

    public static class balpair
    {
        boolean isbal;
        int ht;
    }

    public static balpair isbalanced(node root)
    {
        if(root==null)
        {
            balpair b=new balpair();
            b.isbal=true;
            b.ht=0;
            return b;
        }
        balpair lbp=isbalanced(root.left);
        balpair rbp=isbalanced(root.right);
        balpair nbp=new balpair();
        if(lbp.isbal&&rbp.isbal)
        {
            if(lbp.ht-rbp.ht<=1 && lbp.ht-rbp.ht>=-1 )
             nbp.isbal=true;
        }
        nbp.ht=Math.max(lbp.ht,rbp.ht)+1;

        return nbp;


    }

    static boolean isbal=true;

    public static int isbalanced2(node root)
    {
        if(root==null)
        {
            return 0;
        }
        int lh=isbalanced2(root.left);
        int rh=isbalanced2(root.right);

        if(Math.abs(lh-rh)>1)
        {
            isbal=false;
        }

        return Math.max(lh,rh)+1;


    }

    public static class bstpair
    {
        int max;
        int min;
        boolean isbst;
        node longroot;
        int size;


    }

    public static bstpair bst(node root)
    {
        if(root==null)
        {
            bstpair bp=new bstpair();
            bp.max=Integer.MIN_VALUE;
            bp.min=Integer.MAX_VALUE;
            bp.isbst=true;
            bp.longroot=null;
            bp.size=0;
            return bp;
        }
        bstpair lbstp=bst(root.left);
        bstpair rbstp=bst(root.right);

        bstpair nbstp=new bstpair();

        if(root.data>lbstp.max && root.data<rbstp.min)
        {
            if(lbstp.isbst&&rbstp.isbst)
            {
             nbstp.isbst=true;
             nbstp.longroot=root;
             nbstp.size=rbstp.size+lbstp.size+1;
            }

        }
        else
        {
           nbstp.size=Math.max(rbstp.size,lbstp.size);
           nbstp.longroot=rbstp.size>lbstp.size?rbstp.longroot:lbstp.longroot; 
        }
        nbstp.max=Math.max(rbstp.max,root.data);
        nbstp.min=Math.min(lbstp.min,root.data);

        return nbstp;



    }

    public static void printkdown(node root,node blocker,int k)
    {
        if(root==null || root==blocker || k<0)
        {
            return ;
        }
        if(k==0)
        {
            System.out.println(root.data);
            return;
        }
         printkdown(root.left,blocker,k-1);
         printkdown(root.right,blocker,k-1);
    


    }

    public static ArrayList<node> ntrp2(node root,int t)
    {
        if(root==null)
        {
            return new ArrayList<>();
        }
        if(root.data==t)
        {
            ArrayList<node> list=new ArrayList<>();
            list.add(root);
            return list;

        }
        else
        {
            ArrayList<node> fl=ntrp2(root.left,t);
            if(fl.size()>0)
            {
              fl.add(root);
              return fl;
            }
            ArrayList<node> fr=ntrp2(root.right,t);
            if (fr.size()>0)
            {
             fr.add(root);
             return fr;
            }
        }
        return new ArrayList<>();
        
    }

    public static void printkfar(node root,int data,int k)
    {
        ArrayList<node> path= ntrp2(root,data);
        printkdown(path.get(0),null,k);
        for(int i=1;i<path.size();i++)
        {
            printkdown(path.get(i),path.get(i-1),k-i);
        }
    }



    public static void main(String[] args)
    {
        int[] arr={50,25,12,-1,37,30,-1,51,-1,-1,-1,75,62,60,-1,70,-1,-1,87,80,-1,90,-1,-1,-1,-1};
        node ans=construct(arr);
        //display(ans);
        // int s= size(ans);
        // System.out.println(s);
        // int m=max(ans);
        // System.out.println(m);
        // int h=height(ans);
        // System.out.println(h);
        // int t=70;
        // boolean f=find(ans,t);
        // System.out.println(f);
        // ArrayList<Integer> al=ntrp(ans,t);
        // System.out.println(al);
        // rl(ans);
        // display(ans);
        // node n=rl2(ans);
        // display(n);
        // ntsc(ans);
        // pir(ans,150,250,0,"");
        //node res=tld(ans);
        //node res2=tbld(res);
        //display(res);

        // int[] pre={50,25,12,37,30,75,62,70,87};
        // int[] in={12,25,30,37,50,62,70,75,87};
        // int[] post={12,30,37,25,70,62,87,75,50};
        // node n=con2(pre,0,pre.length-1,in,0,in.length-1);
        //node n=con3(post,0,post.length-1,in,0,in.length-1);
    //     display(n);

        int[] pre={50,25,12,37,75,62,87};
        int[] in={12,25,30,37,50,62,70,75,87};
        int[] post={12,37,25,62,87,75,50};
        node n=con4(pre,0,pre.length-1,post,0,post.length-1);
        display(n);

        //iterativeDFtraversal(ans);

        //int d=diameter1(ans);
        //diapair d=diameter2(ans);

       // System.out.println(d.dia);
       isbalanced2(ans);
       //System.out.println(b.isbal);
       System.out.println(isbal);

       bstpair b=bst(ans);
       System.out.println(b.isbst);
       System.out.println(b.longroot.data);
       System.out.println(b.size);
       printkfar(n,25,3);

       










    }
}
