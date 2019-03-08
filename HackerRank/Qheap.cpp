#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void insert(int heap[100000],int x,int &heap_size)
{
    heap_size++;
    heap[heap_size-1]=x;
    int i = heap_size-1;
    while(i!=0 && heap[i]<heap[(i-1)/2])
    {
        swap(heap[i],heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
void printheap(int heap[100000],int heap_size)
{
    for(int i =0;i<heap_size;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void Delete(int heap[100000],int x,int &heap_size)
{
    int i =0;
    for(i =0;i<heap_size;i++)
    {
        if(heap[i]==x)
        {
            swap(heap[i],heap[heap_size-1]);
            heap_size--;

            break;
        }
    }
    //heapifying
     i =0;
    while(2*i+2<heap_size)
    {
        if(heap[i]>heap[2*i+1])
        {
            if(heap[2*i+1]<heap[2*i+2])
            {   swap(heap[i],heap[2*i+1]);
                i=2*i+1;
            }
            else{
                swap(heap[i],heap[2*i+2]);
                i = 2*i+2;
            }
        }
        else if(heap[i]>heap[2*i+2])
        {
            swap(heap[i],heap[2*i+2]);
            i = 2*i+2;
        }
        else{
            break;
        }
    }
}
void print_min(int heap[100000])
{
    cout<<heap[0]<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int heap[100000];
    int heap_size=0;
    //vector<vector<int>> queries(n);
    int query,x;
    int n;//no of queries
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>query;
        //cout<<query;
        if(query==1)
        {
            cin>>x;
            insert(heap,x,heap_size);
            cout<<endl;
            cout<<"arra after inserting "<<x<<endl<<endl;
            printheap(heap,heap_size);
            //cout<<heap_size<<endl;
        }
        else if(query==2)
        {
            cin>>x;

            Delete(heap,x,heap_size);
            cout<<endl;
            cout << "arra after deleting " << x << endl<<endl;
            printheap(heap,heap_size);
            //cout<<"heap_size after deletion : "<<heap_size<<endl;
        }
        else
        {
            print_min(heap);
        }
    }
    //cout<<heap_size;
    return 0;
}
