import java.util.*;

public class trie
{
    static class node
    {
        char data;
        HashMap<Character,node> children;
        boolean end;

        node(char d)
        {
            this.data=d;
            this.children=new HashMap<>();
            this.end=false;

        }
    }

    public static void add(node n,String word)
    {
        if(word.length()==0)
        {
            n.end=true;
            return;
        }
        char c=word.charAt(0);
        String ros=word.substring(1,word.length());
        if(n.children.containsKey(c))
        {
            add(n.children.get(c),ros);
        }
        else
        {
            node cn=new node(c);
            n.children.put(c,cn);
            add(cn,ros);
        }

    }

    public static boolean search(node n,String word)
    {
        if(word.length()==0)
        {
            return n.end;
        }
        char c=word.charAt(0);
        String ros=word.substring(1);
        node child=n.children.get(c);
        if(child==null)
        {
            return false;
        }
        else
        {
            return search(child,ros);
        }
    


    } 

    public static void remove(node n,String s)
    {
        if(s.length()==0)
        {
            n.end=false;
            return;
        }
        char c=s.charAt(0);
        String ros=s.substring(1);
        node child=n.children.get(c);
        if(child==null)
        {
            return;
        }
        remove(child,ros);
        if(child.end==false && child.children.size()==0 )
        {
            n.children.remove(c);
        }


    }

    public static void display(node n)
    {
        ArrayList<Character> keys=new ArrayList<>(n.children.keySet());
        int i=0;
        String s=n.data+"-->";
        while(i<keys.size())
        {
            char c=keys.get(i);
            node child=n.children.get(c);
            s+=c+(child.end? "*": " ")+",";
            i++;
            
        }
        s+=".";
        System.out.println(s);
        int j=0;
        while(j<keys.size())
        {
            char c=keys.get(j);
            node child=n.children.get(c);
            display(child);
        
            j++;
            
        }




    }

    public static void displayallwords(node n,String wsf)
    {
        if(n.end==true)
        {
            System.out.println(wsf+" ");

        }
        ArrayList<Character> keys=new ArrayList<>(n.children.keySet());
        int i=0;
        while(i<keys.size())
        {
            char c=keys.get(i);
            displayallwords(n.children.get(c),wsf+c);
            i++;
        
        }

    }
    public static void main(String[] args)
    {
        node trie=new node('$');
        add(trie,"art");
        add(trie,"are");
        add(trie,"and");
        add(trie,"start");
        add(trie,"strike");
        add(trie,"artist");
        System.out.println(search(trie,"art"));
        System.out.println(search(trie,"are"));
        System.out.println(search(trie,"artist"));
        System.out.println(search(trie,"ar"));
        remove(trie,"art");
        System.out.println(search(trie,"art"));
        System.out.println(search(trie,"artist"));
        displayallwords(trie,"");
        display(trie);

        


    }
}