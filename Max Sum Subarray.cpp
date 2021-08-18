 #include<iostream>
 #include<vector>
 using namespace std;

 vector<int> MaxSum(int *arr, int k, int x, int n)
 {
     int i, sum=0, temp,j,y;
     vector<int> res;
     for(i=0;i<k;i++)
     {
        sum+=arr[i];
        res.push_back(arr[i]);
     }
     if(sum==x-1)
        return  res;

     temp=sum;
     for(;i<n;i++)
     {
         temp-=arr[i-k];
         temp+=arr[i];

         if(temp>sum  &&  temp<x)
         {
             sum=temp;
             res.clear();
             for(j=i-k+1;j<=i;j++)
                res.push_back(arr[j]);
         }
         if(temp==x-1)
            return res;
     }
     return res;
 }


 int main()
 {
     int arr[]={7,5,4,6,8,9},s=0;
     vector<int> res;
     res=MaxSum(arr,3,20,6);
     cout<<"Sub-array is { ";
     for(auto var:res)
     {
         cout<<var<<" ";
         s+=var;
     }
     cout<<"}\nSum is "<<s<<endl;
     return 0;
 }
