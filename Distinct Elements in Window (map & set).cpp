#include<iostream>
#include<map>
#include<set>

using namespace std;

set<int>  create(int *a, int k)
{
    set<int> s(a,a+k);
    return s;
}


int main()
{
    int n,*arr,i,temp;
    cout<<"Enter number of elements: ";
    cin>>n;
    arr = new int [n];
    cout<<"Enter elements\n";
    for( i=0; i<n; i++)
        cin>>arr[i];


    set<int> Window;
    int WinSize;
    cout<<"Enter size of window: ";
    cin>>WinSize;



    ////////////////////////       Using set            //////////////////////////////


    cout<<"\nUSING SET \n";
    Window=create(arr,WinSize);

    cout<<Window.size()<<endl;

    for( int j=0, i=WinSize  ; i<n; i++, j++)
    {
        Window.erase(arr[j]);
        Window=create(arr+j+1,WinSize);
        cout<<Window.size()<<endl;
    }



    ////////////////////     USING MAP     ////////////////////////////////

    cout<<"\nUSING MAP \n";
    map<int, int> mp;

    map<int, int>::iterator  it;

    for(i=0; i<WinSize; i++)
    {
        it=mp.find(arr[i]);
        /*
        if(it!=mp.end())
        cout<<"it | "<<it->second<<"     ";
        else
            cout<<"  0  ";
        */

        if(it!=mp.end())
            mp[arr[i]]++ ;
        else
            mp.insert(pair<int, int>(arr[i], 1));
    }

    cout<<mp.size()<<endl;


    for(int j=0; i<n; i++, j++)
    {
        it=mp.find(arr[j]);
        if(it!=mp.end())
        {
            if(it->second == 1)
            {
                mp.erase(arr[j]);
            }
            else
            {
                //cout<<it->second<<"-";
                it->second --;
            }

        }

        it=mp.find(arr[i]);
        if(it!=mp.end())
            mp[arr[i]]++ ;
        else
            mp.insert(pair<int, int>(arr[i], 1));
        cout<<mp.size()<<endl;
    }

    return 0;
}
