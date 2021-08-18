#include<iostream>
using namespace std;
class OperOver
{
private:

public:
    int real,imag;
    OperOver(int r=0, int i=0)
    {
        real=r;
        imag=i;
    }


    //OPERATOR OVERLOADING EX. 1
    OperOver operator + (OperOver h)
    {
        OperOver res;
        res.real=real+h.real;
        res.imag=imag+h.imag;
        return res;
    }



    //OPERATOR OVERLOADING EX. 2
    bool operator == (OperOver h)
    {
        if(real==h.real  &&  imag==h.imag)
            return true;
        return false;
    }

    void print()
    {
        cout<<real<<"+i"<<imag<<endl;
    }


};

int main()
{
    OperOver v(6,7),u(6,7),s;
    s=v+u;
    s.print();
    if(v==u)
        cout<<"v=u";
    else
        cout<<"v is not equal u";
    return 0;
}
