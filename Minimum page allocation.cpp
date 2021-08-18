#include<iostream>
#include<climits>
using namespace std;

int allocation(int *arr, int n, int students)
{
    int res[students],i,j,f=0,x=0,t;
    for(i=0;i<students;i++)
        res[i]=0;
    i=n-1;
    while(i>=0)
    {
        if(f==0)
        {
            for(j=0;j<students  && i>=0;j++,i--)
                res[j]+=arr[i];
            f=1;
        }
        else
        {
            f=0;
            j=students-1;
            while(i>=0  &&  j>=0)
            {
                res[j]+=arr[i];
                i--;
                j--;
            }
        }
    }
    j=0;
    for(i=0;i<students;i++)
        if(j<res[i])  j=res[i];
    return j;
}


int main()
{
    int n,*arr,st;
    cout<<"Enter number of books : ";
    cin>>n;
    arr=new int [n];
    cout<<"Enter pages for each book \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter number of students: ";
    cin>>st;
    n=allocation(arr,n,st);
    cout<<"Minimum number of pages are "<<n<<endl;
    return 0;
}
