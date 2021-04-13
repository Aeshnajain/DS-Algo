import java.util.*;

public class twostack
{
     private int data[];
     private int tos1;
     private int tos2;

     twostack()
     {
         data=new int[5];
         tos1=-1;
         tos2=data.length;
     }

     boolean isempty1()
     {
         if(tos1==-1)
         {
             return true;
         }
         return false;
     }
     boolean isempty2()
     {
        if(tos2==data.length)
        {
            return true;
        }
        return false;

     }

     boolean isfull()
     {
         if(tos1+1==tos2)
         {
             return true;
        }
        return false;
     }

     void push1(int val)
     {
         if(isfull())
         {
             System.out.println("stack overflow");
             return;
         }
         tos1++;
         data[tos1]=val;

     }
     void push2(int val)
     {
         if(isfull())
         {
             System.out.println("stack overflow");
             return;
         }
         tos2--;
         data[tos2]=val;

     }

     void pop1()
     {
         if(isempty1())
         {
             System.out.println("stack underflow");
             return;
         }
         data[tos1]=0;
         tos1--;
     }

     void pop2()
     {
         if(isempty2())
         {
             System.out.println("stack underflow");
             return;
         }
         data[tos2]=0;
         tos2++;
     }

     int top1()
     {
         if(tos1==-1)
         {
            System.out.println("stack underflow");
            return -1;

         }
         return data[tos1];
     }

     int top2()
     {
         if(tos2==data.length)
         {
            System.out.println("stack underflow");
            return -1;

         }
         return data[tos2];
     }
    

     public static void main(String[] args)
     {
         twostack st=new twostack();
         st.push1(10);
         st.push1(20);
         st.push1(30);
         st.push2(40);
         st.push2(50);
         st.push2(60);

         while(!st.isempty1())
         {
             System.out.println(st.top1());
             st.pop1();
         }

         st.pop1();
         System.out.println(st.top1());
         


     }


     

}