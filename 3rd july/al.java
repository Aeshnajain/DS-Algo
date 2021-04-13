import java.util.*;

public class al
{
    public static void printrotations(ArrayList<Integer> list,int r)
    {
        int i=0;
        while(i<r)
        {
         
         int temp=list.get(list.size()-1);
         list.remove(list.size()-1);
         list.add(i,temp);
         i++;
        }
        if(i==r)
        {
            return;
        }
    }
    public static void main(String[] args)
    {
        ArrayList<Integer> list=new ArrayList<>();
         list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);
        list.add(60);
        list.add(70);
        list.add(80);
        printrotations(list,3);
        System.out.print(list);
    }

}