#include<iostream>
#include<string>
using namespace std;

class student
{
    private:   //by default
        string name;

    public:
        int age;
        bool gender;

    void print()
    {
        cout<<"Name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
        cout<<"Gender is ";
        if(gender==0)
            cout<<"male"<<endl;
        else
            cout<<"female"<<endl;
    }

    void setName(string s)
    {
        name=s;
    }
};


int main()
{
    student brr[3];
    int i;
    string str;
    for(i=0;i<3;i++)
    {
        cout<<"Name: ";
        cin>>str;
        brr[i].setName(str);
        str.clear();
        cout<<"Age: ";
        cin>>brr[i].age;
        cout<<"Gender (0 for male & 1 for female): ";
        cin>>brr[i].gender;
        cout<<flush;
    }

    for(i=0;i<3;i++)
        brr[i].print();
    return 0;
}
