import java.util.*;
public class repal
{
    public static void main(String[] args)
    {
        ArrayList<Integer> list=new ArrayList<>();
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

        int temp=list.get(0);
        for(int i=1;i<list.size();i++)
        {
            if(list.get(i)==temp)
            {
                list.remove(i);
                i--;
            }
            else
            {
                temp=list.get(i);
            }
        }
        System.out.print(list);
    }
}