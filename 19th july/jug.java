import java.util.*;

public class jug
{
    static int j1=3;
    static int j2=5;

    static class jugs
    {
        int c1;
        int c2;
        String asf;
    }
    public static void solve(boolean[][] arr,int limit)
    {
        ArrayDeque<jugs> q=new ArrayDeque<>();
        jugs j=new jugs();
        j.c1=0;
        j.c2=0;
        j.asf="";
        q.addLast(j);
        while(q.size()>0)
        {
           jugs rem=q.getFirst();
           q.removeFirst();
           if(arr[rem.c1][rem.c2]==true)
           {
               continue;
           }
           arr[rem.c1][rem.c2]=true;
           if(rem.c1==limit || rem.c2==limit)
           {
               System.out.println(rem.asf);
               break;
           }
           if( rem.c1==0)
           {
              jugs jug1=new jugs();
              jug1.c1=rem.c1+j1;
              jug1.c2=rem.c2;
              jug1.asf=rem.asf+"f"+j1+"  ";

               if(arr[jug1.c1][jug1.c2]==false)
               { 
                 q.addLast(jug1);
               }

           }
            if( rem.c2==0)
           {
              jugs jug1=new jugs();
              jug1.c1=rem.c1;
              jug1.c2=rem.c2+j2;
              jug1.asf=rem.asf+"f"+j2+"  ";
              if(arr[jug1.c1][jug1.c2]==false)
               { 
                 q.addLast(jug1);
               }

           }
            if(rem.c1==j1)
           {
              jugs jug1=new jugs();
              jug1.c1=rem.c1-j1;
              jug1.c2=rem.c2;
              jug1.asf=rem.asf+"e"+j1+"  ";
              if(arr[jug1.c1][jug1.c2]==false)
               { 
                 q.addLast(jug1);
               }

           }
           if( rem.c2==j2)
           {
              jugs jug1=new jugs();
              jug1.c1=rem.c1;
              jug1.c2=rem.c2-j2;
              jug1.asf=rem.asf+"e"+j2+"  ";
              if(arr[jug1.c1][jug1.c2]==false)
               { 
                 q.addLast(jug1);
               }

           }
           if( rem.c1>0 && rem.c2<j2)
           {
               int space=j2-rem.c2;
               if(space>=rem.c1)
              { 
                 jugs jug1=new jugs();
                 jug1.c1=0;
                 jug1.c2=rem.c2+rem.c1;
                 jug1.asf=rem.asf+"m"+j1+"@"+j2+"  ";
                 if(arr[jug1.c1][jug1.c2]==false)
                 {
                     q.addLast(jug1);
                 }
              }
              else
              {
                  jugs jug1=new jugs();
                  jug1.c1=rem.c1-space;
                  jug1.c2=j2;
                  jug1.asf=rem.asf+"m"+j1+"@"+j2+"  ";
                  if(arr[jug1.c1][jug1.c2]==false)
                  {
                      q.addLast(jug1);
                  }
              }
            }
              if( rem.c2>0 && rem.c1<j1)
           {
               int space=j1-rem.c1;
               if(space>=rem.c2)
              { 
                jugs jug1=new jugs();
                jug1.c2=0;
                jug1.c1=rem.c2+rem.c1;
                jug1.asf=rem.asf+"m"+j2+"@"+j1+"  ";
                if(arr[jug1.c1][jug1.c2]==false)
                {
                   q.addLast(jug1);
                }
              }
              else
              {
                  jugs jug1=new jugs();
                  jug1.c2=rem.c2-space;
                  jug1.c1=j1;
                  jug1.asf=rem.asf+"m"+j2+"@"+j1+"  ";
                  if(arr[jug1.c1][jug1.c2]==false)
                  {
                      q.addLast(jug1);
                  }
                }

           }

        }
    }

    public static void main(String[] args)
    {
        boolean[][] arr=new boolean[j1+1][j2+1];
        solve(arr,4);

    }
}