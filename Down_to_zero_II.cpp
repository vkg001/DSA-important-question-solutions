#include<bits/stdc++.h>

using namespace std ;

queue<pair<int, int>>  Num_Q ;

const int N = 1e6 + 1;

int  table[N] = {0};

int DownToZero()
{
    pair<int, int>  n;

    while(!Num_Q.empty())
    {
        n = Num_Q.front() ;
        Num_Q.pop() ;

        if((n.first) == 0)
        {
            break;
        }

        if(table[(n.first)-1] == 0)
        {
            table[(n.first)-1] = 1 ;
            Num_Q.push(make_pair((n.first)-1,  (n.second)+1));    
        }


        for(int i = sqrt(n.first);   i >= 2;   i--)
        {
            if( ((n.first) % i == 0)       &&      (table[(n.first)/i] == 0) )
            {
                table[(n.first)/i] = 1 ;
                Num_Q.push(make_pair((n.first)/i, (n.second)+1)) ;
            }
        }
    }

    return (n.second);
}


int main()
{
    int testCases, num ;
    cin >> testCases ;
    while(testCases--)
    {
        cin >> num; 
        Num_Q.push(make_pair(num, 0));
        table[num] = 1 ;
        cout << DownToZero() << endl ;
        while(!Num_Q.empty())
        {
            Num_Q.pop();
        }
        int x = N; 
        while (x--)
        {
            table[x] = 0 ;
        }
        
    }
    return 0;
}