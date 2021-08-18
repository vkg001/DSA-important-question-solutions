#include<iostream>
#include<vector>
#include<climits>


using namespace std;


bool isPossible(int mid, vector<int> boardLength, int painters)
{
    int sum=0,currPainters=1;
    for(auto var:boardLength)
    {
        if(sum+var>mid)
        {
            sum=var;
            currPainters++;
            if(currPainters>painters)
                return false;
        }
        else
        {
            sum+=var;
        }
        if(var>mid)
        {
            return false;
        }
    }
    return true;
}


int MinimumTime(vector<int> boardLength, int painters)
{
    int start,end,mid,ans=INT_MAX,sum=0;
    for(auto var:boardLength)
        sum+=var;
    start=0;   end=sum;
    //cout<<sum<<endl;
    while(start<=end)
    {
        mid=(start+end)/2;
        //cout<<"MID | "<<mid<<endl;
        if(isPossible(mid,boardLength,painters))
        {
            ans=min(mid,ans);
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}


int main()
{
    int painters,boards,i,x;
    vector<int> boardLength;
    cout<<"Enter number of boards: ";
    cin>>boards;
    cout<<"Enter length of boards\n";
    for(i=0;i<boards;i++)
        {
            cin>>x;
            boardLength.push_back(x);
        }
    cout<<"Enter number of painters available: ";
    cin>>painters;
    x=MinimumTime(boardLength,painters);
    cout<<"Minimum time is "<<x<<endl;
    return  0;
}
