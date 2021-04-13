import java.util.*;

public class stack
{
     private int data[];
     private int tos;

     stack()
     {
         data=new int[5];
         tos=-1;
     }

     void push(int val)
     {
         if(tos==data.length-1)
         {
             System.out.println("stack overflow");
             return;
         }
         tos++;
         data[tos]=val;

     }

     void pop()
     {
         if(tos==-1)
         {
             System.out.println("stack underflow");
             return;
         }
         data[tos]=0;
         tos--;
     }

     int top()
     {
         if(tos==-1)
         {
            System.out.println("stack underflow");
            return -1;

         }
         return data[tos];
     }

     int size()
     {
         return tos+1;
     }
    

     public static void main(String[] args)
     {
         stack st=new stack();
         st.push(10);
         st.push(20);
         st.push(30);
         st.push(40);
         st.push(50);
         st.push(60);

         while(st.size()>0)
         {
             System.out.println(st.top());
             st.pop();
         }

         st.pop();
         System.out.println(st.top());
         


     }


     

}