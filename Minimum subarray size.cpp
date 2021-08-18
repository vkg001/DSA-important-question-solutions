 #include<iostream>
 #include<vector>
 using namespace std;

 int MinSum(int *arr, int x, int n)
 {
     int i, sum=0, temp=0,j=n-1,y=0;
     vector<int> res;

     for(i=0;i<=n;i++)
     {
         if(i==n  &&  sum<x)
            break;

         if(sum>x)
         {
             y=0;
             while(sum>x)
             {
             sum-=arr[i-temp+y];
                if(sum>x)
                 y++;
             }
             temp=temp-y;
             j=min(temp,j);
             temp--;
             if(i==n)
                break;
         }
         if(j==1)
            return j;

         if(sum<=x)
         {
             sum+=arr[i];
             temp++;
         }
     }
     return j;
 }


 int main()
 {
     int arr[]={7,5,4,6,8,9},s=0;
     vector<int> res;
     s=MinSum(arr,8,6);
     cout<<"\nMinimum size of sub-array is "<<s<<endl;
     return 0;
 }

