#include<iostream>

//#define loop(a,b)   for(int i=a;i>=b;i--)

using namespace std;


class heap
{
public:
    int *arr;
    int element;
    int size;
    heap(int x)
    {
        arr= new int[x];
        element=-1;
        size=x;
    }

    int parent(int x)
    {
        return ((x-1)/2);
    }

    int child(int x)
    {

    }
    int retElement()
    {
        return element;
    }
    void Insert(int x);
    void Display(heap obj);

};

void heap::Insert(int x)
{
    int k;
    element++;
    int i=element;
    //cout<<"Element | "<<element<<endl;
    arr[i]=x;
    //cout<<arr[parent(i)]<<" | "<<arr[i]<<endl;
    while(arr[parent(i)]<arr[i]  &&  i>0)
    {
        //cout<<arr[parent(i)]<<" | "<<arr[i]<<endl;
        int t=arr[parent(i)];
        arr[parent(i)]=arr[i];
        arr[i]=t;
        //cout<<arr[parent(i)]<<" | "<<arr[i]<<endl;
        i=parent(i);
    }
    /*for(i=0;i<element;i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    */
}


void heap::Display(heap obj)
{
    for(int i=0; i<=obj.element; i++)
    {
        cout<<obj.arr[i]<<"  ";
    }
    cout<<endl;
}



int main()
{
    int n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    heap obj(n);
    cout<<"Enter elements\n";
    for(i=0; i<n; i++)
    {
        int x;
        cin>>x;
        obj.Insert(x);
    }
    cout<<"Inserted heap\n";
    obj.Display(obj);
    return 0;
}
