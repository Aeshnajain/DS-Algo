import java.util.*;

public class hashmapd
{
    public static void demo()
    {
        creatinghm<String,Integer> dhmap=new creatinghm<>();
        dhmap.put("india",133);
        dhmap.put("aus",33);
        dhmap.put("paris",15);
        dhmap.put("eng",54);
        dhmap.put("pak",13);
        dhmap.put("nig",133);
        dhmap.put("auck",33);
        dhmap.put("us",15);
        dhmap.put("uk",54);
        dhmap.put("afg",13);
        dhmap.display();
        System.out.println(dhmap.keyset());
    }

    // public static void highfreqchar(String s)
    // {
    //     HashMap<Character,Integer> fmap=new HashMap<>();
    //     int val=0;
    //     for(int i=1;i<s.length();i++)
    //     {
    //         char p=s.charAt(i);
    //         char c=s.charAt(i-1);
    //         if(p==c)
    //         {
    //            val++;
    //            fmap.put(c,val);
    //         }
    //         else
    //         {
    //             val=0;
    //             fmap.put(c,val);
    //         }
    //     }
    //     System.out.println(fmap);
    // }

    public static void highfreqchar(String s)
    {
        HashMap<Character,Integer> fmap=new HashMap<>();
        for(char c:s.toCharArray())
        {
            if(fmap.containsKey(c)==false)
            {
                fmap.put(c,0);
            }
            else
            {
                fmap.put(c,fmap.get(c)+1);
            }

        }

        char mfc=s.charAt(0);
        for(char c:fmap.keySet())
        {
            if(fmap.get(c)>fmap.get(mfc))
            {
                mfc=c;
            }

        }
        System.out.println(mfc);
    }

    public static void gce1(int[] arr1,int[] arr2)
    {
        HashMap<Integer,Integer> fmap=new HashMap<>();
        for(int i:arr1)
        {
            if(fmap.containsKey(i)==false)
            {
                fmap.put(i,0);
            }
        }

        for(int i:arr2)
        {
            if(fmap.containsKey(i))
            {
                System.out.print(i);
                fmap.remove(i);
            }

        }

    }

    public static void gce2(int[] arr1,int[] arr2)
    {
        HashMap<Integer,Integer> fmap=new HashMap<>();
        for(int i:arr1)
        {
            fmap.put(i,fmap.containsKey(i)==false?0:fmap.get(i)+1);
        }

        for(int i:arr2)
        {
            if(fmap.containsKey(i) && fmap.get(i)>0)
            {
                System.out.print(i);
                fmap.put(i,fmap.get(i)-1);
            }

        }


    }

    public static void getlongseqofconsnum(int[] arr)
    {
        HashMap<Integer,Boolean> fmap=new HashMap<>();
        for(int i:arr)
        {
            fmap.put(i,true);
        }

        for(int i:arr)
        {
            if(fmap.containsKey(i-1)==true)
            {
                fmap.put(i,false);
            }
        }

        int bestval=0;
        int bestlen=0;

        for(int i:arr)
        {
            if(fmap.get(i)==true)
            {
                int templen=1;
                int tempval=i;

                while(fmap.containsKey(i+templen)==true)
                {
                    templen++;
                }

                if(templen>bestlen)
                {
                    bestlen=templen;
                    bestval=tempval;
                }
            }
        }

        for(int i=bestval;i<bestval+bestlen;i++)
        {
            System.out.println(i);
        }

    }

    public static void tarsumofsubarr(int[] arr,int t)
    {
        HashMap<Integer,Integer> fmap=new HashMap<>();
        fmap.put(0,1);
        int ps=0;
        int bsum=0;
        int count=0;
        for(int val:arr)
        {
            ps+=val;
            bsum=ps-t;
            if(fmap.containsKey(bsum))
            {
                count+=fmap.get(bsum);
            }
            
            fmap.put(ps,fmap.containsKey(ps)==false?1:fmap.get(ps)+1);
            
            
        }

        System.out.println(count);

    }

    public static void lengthoflongtsubarr(int[] arr,int t)
    {
        HashMap<Integer,Integer> fmap=new HashMap<>();
        fmap.put(0,-1);
        int ps=0;
        int bsum=0;
        int bestlen=0;
        for(int i=0;i<arr.length;i++)
        {
            ps+=arr[i];
            if(fmap.containsKey(ps)==false)
             fmap.put(ps,i);
            bsum=ps-t;
            if(fmap.containsKey(bsum))
            {
                int templen=i-fmap.get(bsum);
                if(templen>bestlen)
                {
                    bestlen=templen;
                }
            }
            
        }

        System.out.println(bestlen);

    }

    public static void getmultsubarr(int[] arr,int t)
    {
        HashMap<Integer,Integer> fmap=new HashMap<>();
        fmap.put(0,1);
        int ps=0;
        int count=0;
        for(int val:arr)
        {
            ps+=val;
            int f=ps%t>=0?ps%t:(ps%t)+t;
            if(fmap.containsKey(f))
            {
                count+=fmap.get(f);
            }
            
            fmap.put(f,fmap.containsKey(f)==false?1:fmap.get(f)+1);
            
            
        }

        System.out.println(count);

    }

    public static void getmultsubarrlen(int[] arr,int t)
    {
        HashMap<Integer,Integer> fmap=new HashMap<>();
        fmap.put(0,-1);
        int ps=0;
        int bestlen=0;
        for(int i=0;i<arr.length;i++)
        {
            ps+=arr[i];
            int f=ps%t>=0?ps%t:(ps%t)+t;
            if(fmap.containsKey(f))
            {
                int templen=i-fmap.get(f);
                if(templen>bestlen)
                {
                    bestlen=templen;
                }
            }
            if(fmap.containsKey(f)==false)
             fmap.put(f,i);
        
            
            
        }

        System.out.println(bestlen);

    }


    public static void main(String[] args)
    {
        demo();
        //highfreqchar("aabbccccd");

        // int[] arr1={1,2,4,2,1,2,2};
        // int[] arr2={2,1,3,2,2,2,2};
        //gce1(arr1,arr2);
        //gce2(arr1,arr2);

        //int[] arr={2,12,9,16,10,5,3,20,25,11,1,8,6};
        //getlongseqofconsnum(arr);

        // int[] arr={7,5,3,4,18,9,1,7,-2,4,-15,3};
        //tarsumofsubarr(arr,3);
        //lengthoflongtsubarr(arr,5);

        // getmultsubarr(arr,5);
        // getmultsubarrlen(arr,5);

    }
}