#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> Snakes, Ladders;
    int n, x, y;
    cin >> n; // Number of ladders
    while(n--)
    {
        cin >> x >> y;
        Ladders[x] = y;
    }
    cin >> n;   // Number of snakes
    while(n--)
    {
        cin >> x >> y;
        Snakes[x] = y;
    }
    x = 0;  // Minimum moves
    y = 1; // Token position
    int nxtSlot[3];
    queue<int> possible_moves;
    possible_moves.push(1);
    map<int, bool> visited;
    visited[1] = true;
    bool brk = false;
    while(!possible_moves.empty())
    {
        for(int i=0; i<6; i++)
        {
            y = possible_moves.front();
            possible_moves.pop();
            for(n=1;  n<=6;  n++)
            {
                if(!visited[y+n]    &&  !visited[Ladders[y+n]]  &&  !visited[Snakes[y+n]])
                {
                    nxtSlot[0] = y+n;
                    if(Ladders[y+n])
                        nxtSlot[0] = Ladders[y+n];
                    if(Snakes[y+n])
                        nxtSlot[0] = Snakes[y+n];
                    if(nxtSlot[0] == 100)
                    {
                        brk = true;
                        x++;
                        break;
                    }
                    visited[nxtSlot[0]] = true;
                    possible_moves.push(nxtSlot[0]);
                }
            }
            if(possible_moves.empty()   ||  brk)
                break;
        }
        //cout << nxtSlot[0] << " ";
        if(brk)
            break;
        x++;
    }
    //cout << endl;
    cout << x+1 << endl ;
}