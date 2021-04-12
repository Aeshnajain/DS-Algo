#include<iostream>
#include<vector>

using namespace std;

class myheap
{
    public:
     vector<int>v{1,2,3,4,5,6,7,8,9,10};
     bool check=true;
     myheap()
     {
        consheap();
     }
     myheap(bool c)
     {
        this->check=c;
        consheap();
     }
     bool compareto(int c1,int c2)
     {
         if(check)
         {
             return c1<c2;
         }
         else 
         {
             return c1>c2;
         }
     }

    void consheap()
    {
        for(int i=v.size()-1;i>=0;i--)
        {
            downheapify(i);
        }
    }

    void myswap(int i,int j)
    {
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }

    void downheapify(int pi)
    {
        int ci1=2*pi+1;
        int ci2=2*pi+2;
        int maxidx=pi;
        if(ci1<v.size() && compareto(v[maxidx],v[ci1]))
        {
            maxidx=ci1;
        }
        if(ci2<v.size() && compareto(v[maxidx],v[ci2]))
        {
             maxidx=ci2;
        }
        if(maxidx!=pi)
        {
            myswap(maxidx,pi);
            downheapify(maxidx);
        }


    }

    void upheapify(int ci)
    {
        int pi=(ci-1)/2;
        int minidx=ci;
        if(pi>=0 && compareto(v[pi],v[minidx]))
        {
            myswap(minidx,pi);
            upheapify(pi);
        }
    }

    bool isempty()
    {
        if(v.size()>0)
        {
            return false;
        }
        return true;
    }

    int top()
    {
        if(v.size()>0)
        {
            return v[0];
        }
        return -1;
    }

    void pop()
    {
        if(v.size()>0)
        {
            myswap(0,v.size()-1);
            v.pop_back();
            downheapify(0);
        }
    }

    void add(int val)
    {
        v.push_back(val);
        upheapify(v.size()-1);
    }


};


 void downheapify(int pi,int size,vector<int>&arr)
    {
        int ci1=2*pi+1;
        int ci2=2*pi+2;
        int maxidx=pi;
        if(ci1<size && arr[maxidx]<arr[ci1])
        {
            maxidx=ci1;
        }
        if(ci2<size && arr[maxidx]<arr[ci2])
        {
             maxidx=ci2;
        }
        if(maxidx!=pi)
        {
            swap(arr[maxidx],arr[pi]);
            downheapify(maxidx,size,arr);
        }


    }


void heapsort(vector<int>&arr)
{
    for(int i=arr.size()-1;i>=0;i--)
    {
        downheapify(i,arr.size()-1,arr);
    }
    int r=arr.size()-1;
    while(r>0)
    {
        swap(arr[0],arr[r]);
        r--;
        downheapify(0,r,arr);
    }

}

int main(int argc,char**argv)
{
   myheap pq(false);
//    for(int val:pq.v)
//    {
//        cout<<val<<" ";
//    }
//    cout<<endl;
   
    // cout<<pq.top()<<" ";
    // pq.pop();
    // cout<<pq.top()<<" ";
    // pq.pop();
    // cout<<pq.top()<<" ";
    // pq.pop();
    // cout<<endl;
    // pq.add(100);
    // pq.add(10);
    // pq.add(0);
    // pq.add(20);
    // pq.add(-4);
    while(!pq.isempty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    // vector<int> arr{10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    // heapsort(arr);
    // for(int val:arr)
    // {
    //     cout<<val<<" ";
    // }
    // cout<<endl;

}


// #include <iostream>
// #include <vector>

// using namespace std;

// void downHeapify(vector<int> &arr, int idx, int n)
// {
//     int lci = 2 * idx + 1;
//     int rci = 2 * idx + 2;
//     int maxIdx = idx;

//     if (lci <= n && arr[lci] > arr[maxIdx])
//         maxIdx = lci;
//     if (rci <= n && arr[rci] > arr[maxIdx])
//         maxIdx = rci;

//     if (maxIdx != idx)
//     {
//         swap(arr[idx], arr[maxIdx]);
//         downHeapify(arr, maxIdx, n);
//     }
// }

// void heapSort(vector<int> &arr)
// {
//     int n = arr.size() - 1;
//     for (int i = n; i >= 0; i--)
//         downHeapify(arr, i, n);

//     int idx = 0;
//     while (n != 0)
//     {
//         swap(arr[0], arr[n--]);
//         downHeapify(arr, 0, n);
//     }

//     for (int ele : arr)
//         cout << ele << " ";
// }

// void solve()
// {
//     vector<int> arr{10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
//     heapSort(arr);
// }

// int main()
// {
//     solve();
//     return 0;
// }