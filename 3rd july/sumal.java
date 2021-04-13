import java.util.*;
public class sumal
{
    public static void sum(ArrayList<Integer> list)
    {
      int sum=0;
        for(int i=list.size()-2;i>=0;i--)
        {
            if(list.get(i)==list.get(i+1))
            {
                sum=sum+list.get(i+1);
                list.remove(i+1);
            }
            else
            {
               int temp=list.get(i+1);
               sum=sum+temp;
               list.set(i+1,sum);
               sum=0;
            }
            
        }
        int temp=list.get(0);
        sum=sum+temp;
        list.set(0,sum);
    }
    public static void main(String[] args)
    {
        ArrayList<Integer> list=new ArrayList<>();
        list.add(3);
        list.add(2);
        list.add(2);
        list.add(2);
        list.add(3);
        list.add(3);
        list.add(2);
        list.add(2);
        list.add(2);
        list.add(5);
        list.add(5);
        list.add(6);
        list.add(6);
        list.add(7);
        list.add(7);
        list.add(8);
        list.add(8);
        sum(list);

        //int temp=list.get(0);
        //int sum=list.get(0);
        //for(int i=1;i<list.size();i++)
        //{
          //  if(list.get(i)==temp)
            //{
              //  sum=sum*(i+1);
                //list.remove(i);
                //i--;
            //}
            //else
            //{
              //  temp=list.get(i);
                //sum=list.get(i);
            //}
        //}
        System.out.print(list);
    }
}