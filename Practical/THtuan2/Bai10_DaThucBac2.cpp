#include <bits/stdc++.h>
using namespace std;
class DaThuc
{
private:
    int a,b,c;   
public:
    DaThuc();
    DaThuc(int, int, int);
    ~DaThuc();
    double getValueDT(int);
    friend DaThuc operator+(const DaThuc & DT1, const DaThuc & DT2);
    friend ostream & operator<<(ostream& os, const DaThuc & DT);
    friend istream & operator>>(istream& is, DaThuc & DT);
};

DaThuc::DaThuc()
{
    a = 1;
    b = 0;
    c = 0;
}

DaThuc::DaThuc(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
};

double DaThuc::getValueDT(int x)
{
    return a*x*x + b*x + c;
};

DaThuc operator+(const DaThuc & DT1,const DaThuc & DT2)
{
    DaThuc DT3(DT1.a + DT2.a, DT1.b + DT2.b, DT1.c + DT2.c);
    return DT3;
};

ostream & operator<<(ostream& os,const DaThuc & DT){
    if (DT.b == 0 && DT.c == 0) {os<<DT.a<<"x^2";}
    else if (DT.b == 0) {os<<DT.a<<"x^2 + "<<DT.c;}
    else if (DT.c == 0) {os<<DT.a<<"x^2 + "<<DT.b<<"x";}
    else
        {os<<DT.a<<"x^2 + "<<DT.b<<"x + "<<DT.c;}
    return os;
};

istream & operator>>(istream& is, DaThuc & DT)
{
    is>>DT.a>>DT.b>>DT.c;
    return is;
};

DaThuc::~DaThuc()
{
};

int main()
{
    DaThuc d1, d2;
    cout<<"Nhap dathuc 1: "<<endl;
    cin>>d1;
    cout<<"Nhap dathuc 2: "<<endl;
    cin>>d2;
    int x0;
    cout<<"Nhap x0: ";
    cin>>x0;
    cout<<"Gia tri da thuc 1 va da thuc 2 tai x0 lan luot la: "<<d1.getValueDT(x0)<<", "<<d2.getValueDT(x0)<<endl;
    cout<<"Tong 2 da thuc vua nhap: "<<d1 + d2<<endl;
    return 0;
}
