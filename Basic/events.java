import java.util.*;

public class events
{
    public static void main(String[] args)
    {
        int e1s=2;
        int e1e=5;
        int e2s=4;
        int e2e=8;

        if(e1e<=e2s || e2e<=e1s)
        {
            System.out.println("no overlapping");
        }
        if(e1s>=e2s && e1e<=e2e || e2s>=e1s && e2e<=e1e)
        {
            System.out.println("full overlapping");
        }
        else
        {
            System.out.println("partial overlapping");
        }
    }
}

