#include<iostream>
#include<vector>
using namespace std;

struct term
{
    float pow;
    float num;
    term(float x, float y)
    {
        pow=x;
        num=y;
    }
};


vector<term> equation;
int iterations=0;


void Insert(float pow, float num)
{
    term x(pow,num);
    equation.push_back(x);
}


float POW(float num, float pow)
{
    float ans=1;
    for(int i=0;i<pow;i++)
        ans*=num;
    return ans;
}


float funValue(float a)
{
    float val=0;
    for(auto var:equation)
    {
            val+=((POW(a,var.pow))*var.num);
    }
    return val;
}

float Approximation(float a, float b, int iter=1)
{
    cout<<"\n\n-----------------------------------\n\nApproximation "<<iter<<endl;
    int x;
    float c,fa,fb,fc,recpos,recneg;
    fa=funValue(a);
    if(fa<0)  recneg=a;
    else   recpos=a;
    fb=funValue(b);
    if(fb<0)  recneg=b;
    else   recpos=b;
    c=((a*fb)-(b*fa))/(fb-fa);
    cout<<"a | "<<recpos<<"\nb | "<<recneg<<"\nc | "<<c<<endl;
    //cin>>x;
    fc=funValue(c);
    if(fc<0.005   &&  fc>(-0.005))
        return c;
    if(fc<0)
        return Approximation(recpos,c,iter+1);
    return Approximation(c,recneg,iter+1);
}



int main()
{
    int n;
    float a1,a2;
    cout<<"Enter number of terms in your equation\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        float Pow,Num;
        cout<<"Enter power for term "<<i+1<<"   ";
        cin>>Pow;
        cout<<"Enter coefficient of term "<<i+1<<"   ";
        cin>>Num;
        Insert(Pow,Num);
    }
    cout<<"Enter an integer at which equation is -ve: ";
    cin>>a1;
    cout<<"Enter an integer at which equation is +ve: ";
    cin>>a2;
    cout<<"\n\n-----------------------------------\n\nAnswer | "<<Approximation(a2,a1)<<"\n\n-----------------------------------\n"<<endl;
    return 0;
}
