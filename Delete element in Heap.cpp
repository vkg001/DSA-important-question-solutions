#include<iostream>

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
        int k=(2*x)+1;
        if(k<=element)
            return k;
        return (2*x+1);
    }


    int retElement()
    {
        return element;
    }

    void operator = (heap y)
    {
        element=y.element;
        size=y.size;
        for(int i=0;i<=y.element;i++)
        {
            arr[i]=y.arr[i];
        }
    }


    void Insert(int x);
    void Display(heap obj);
    int Delete(int x, heap *obj);
    void heapyfy(heap *obj);

};

void heap::heapyfy(heap *obj)
{
    int i;
    heap obj2(element);
    for(i=0;i<=element;i++)
        {
            obj2.Insert(arr[i]);
        }
    *obj=obj2;
}


int heap::Delete(int x, heap *obj)
{
    int i,k;
    if(element<0)
    {
        cout<<"Heap is underflow."<<endl;
        return -1;
    }
    if(element==0  &&  arr[0]==x)
    {
        k=arr[0];
        element--;
        return k;
    }
    for(i=0;i<=element;i++)
    {
        if(arr[i]==x)
            break;
    }
    if(i>element)
    {
        cout<<"Element not found!\n";
        return -1;
    }
    k=arr[i];
    arr[i]=arr[element];
    element--;
    heapyfy(obj);
    return k;
}


void heap::Insert(int x)
{
    int k;
    element++;
    int i=element;
    arr[i]=x;
    while(arr[parent(i)]<arr[i]  &&  i>0)
    {
        int t=arr[parent(i)];
        arr[parent(i)]=arr[i];
        arr[i]=t;
        i=parent(i);
    }
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
    do
    {
    cout<<"Enter element to delete or 0 to exit: ";
    cin>>i;
    if(i!=0)
    {
        n=obj.Delete(i,&obj);
    if(n!=-1)
        cout<<n<<" is deleted.\n";
    cout<<endl;
    obj.Display(obj);
    }
    }while(i!=0);
    return 0;
}
