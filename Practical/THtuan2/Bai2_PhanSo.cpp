#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo();
    PhanSo(int a, int b);
    PhanSo(int a);
    ~PhanSo();
    void set(int , int);
    PhanSo rutgon();
    void chuanhoa();
    friend PhanSo operator+(PhanSo a, PhanSo b);
    friend PhanSo operator-(PhanSo a, PhanSo b);
    friend PhanSo operator*(PhanSo a, PhanSo b);
    friend PhanSo operator/(PhanSo a, PhanSo b);
 
    friend bool operator == (PhanSo a, PhanSo b);
    friend bool operator != (PhanSo a, PhanSo b);
    friend bool operator > (PhanSo a, PhanSo b);
    friend bool operator >= (PhanSo a, PhanSo b);
    friend bool operator < (PhanSo a, PhanSo b);
    friend bool operator <= (PhanSo a, PhanSo b);

    friend ostream& operator << (ostream &os, PhanSo a);
    friend istream& operator >> (istream &is, PhanSo &a);
};
void PhanSo::set(int a, int b)
{
    this->tu = a;
    this->mau = b;
}
PhanSo PhanSo::rutgon()
{
    int k = __gcd(tu, mau);
    return PhanSo(tu/k, mau/k);
}
void PhanSo::chuanhoa()
{
    this->rutgon();
    if (this->tu < 0 && this->mau < 0)
    {
        this->tu = abs(this->tu);
        this->mau = abs(this->mau);
    }
    else
        if (this->mau < 0)
        {
            this->tu =  -abs(this->tu);
            this->mau = abs(this->mau);
        }    
}
PhanSo::PhanSo()
{
    tu = 0;
    mau = 1;
}
PhanSo::PhanSo(int a, int b)
{
    set(a,b);
}
PhanSo::PhanSo(int a)
{
    set(a,1);
}
PhanSo::~PhanSo()
{
}
PhanSo operator+(PhanSo a, PhanSo b)
{
    a = a.rutgon();
    b = b.rutgon();
    PhanSo res(a.tu*b.mau + a.mau*b.tu, a.mau*b.mau);
    res = res.rutgon();
    return res;
}
 
PhanSo operator-(PhanSo a, PhanSo b)
{
    return PhanSo(a.rutgon()+b.rutgon()*-1).rutgon();
}
 
PhanSo operator*(PhanSo a, PhanSo b)
{
    a = a.rutgon();
    b = b.rutgon();
    PhanSo res(a.tu*b.tu, a.mau*b.mau);
    res = res.rutgon();
    return res;
}
 
PhanSo operator/(PhanSo a, PhanSo b)
{
    if (b.tu == 0)
    {
        throw runtime_error("Loi chia cho 0!\n");
    }
    b = b.rutgon();
    return PhanSo(a.rutgon() * PhanSo(b.mau, b.tu)).rutgon();
}
 
bool operator==(PhanSo a, PhanSo b)
{
    return (a.tu*b.mau == a.mau*b.tu);
}
 
bool operator!=(PhanSo a, PhanSo b)
{
    return !(a == b);
}
 
bool operator>(PhanSo a, PhanSo b)
{
    return (a.tu*b.mau>a.mau*b.tu);
}
 
bool operator>=(PhanSo a, PhanSo b)
{
    return (a > b || a == b);
}
 
bool operator<(PhanSo a, PhanSo b)
{
    return (a.tu*b.mau<a.mau*b.tu);
}
bool operator<=(PhanSo a, PhanSo b)
{
    return (a < b || a == b);
}
ostream& operator << (ostream &os, PhanSo a)
{
    a.chuanhoa();
    if (a.mau == 1)
        os << a.tu << endl;
    else
        os << a.tu << "/" << a.mau << "\n";
    return os;
}
 
istream& operator >> (istream &is, PhanSo &a)
{
    do
    {
        cout<<"Nhap Tu So: ";
        cin>>a.tu;
        cout<<"Nhap Mau So: ";
        cin>>a.mau;
        if (a.mau == 0)
            cout<<"Khong hop le, vui long nhap lai!\n";
    } while (a.mau == 0);
    return is;
}
 
int main()
{
    PhanSo a,b;
    cin >> a >> b;
    cout << "Cong = " << a + b;
    cout << "Tru = " << a - b;
    cout << "Nhan = " << a*b;
    try{
        cout << "Chia = " << a / b;
    }
    catch (runtime_error& e){
        cout<<e.what();
    }
    return 0;
}