 #include<iostream>
 #include<vector>
 using namespace std;

 vector<int> MaxSum(int *arr, int k, int n)
 {
     int i, sum=0, temp,j,y;
     vector<int> res;
     for(i=0;i<k;i++)
     {
        sum+=arr[i];
        res.push_back(arr[i]);
     }

     temp=sum;
     for(;i<n;i++)
     {
         temp-=arr[i-k];
         temp+=arr[i];

         if(temp>sum  &&  temp%3==0)
         {
             sum=temp;
             res.clear();
             for(j=i-k+1;j<=i;j++)
                res.push_back(arr[j]);
         }
     }
     return res;
 }


 int main()
 {
     int arr[]={7,5,4,6,81,9},s=0;
     vector<int> res;
     res=MaxSum(arr,3,6);
     cout<<"Maximum sub-array number divisible by 3 is ";
     for(auto var:res)
     {
         cout<<var;
         s=s*10+var;
     }
     return 0;
 }
