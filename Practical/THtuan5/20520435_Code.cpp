#include <iostream>
using namespace std;

class NhomMau
{
    protected:
        bool Rh;
    public:
        NhomMau() {};
        ~NhomMau() {};
        void nhap();
        bool getRh();
        virtual bool checkDiTruyen(char, char) = 0;
        virtual char getTen() = 0;
        virtual bool tuongThich(char nm,bool) = 0;
};   

void NhomMau::nhap()
{
    char t;
    cout << "Nhap Rhesus: ";
    cin >> t;
    if (t == '+')
        Rh = true;
    else
        Rh = false;
}

bool NhomMau::getRh()
{
    return Rh;
}
// ------------------------------------------------------
class NhomA : public NhomMau
{
    public:
        NhomA() {};
        ~NhomA() {};
        bool checkDiTruyen(char, char);
        char getTen();
        bool tuongThich(char nm, bool b);
};

char NhomA::getTen()
{
    return 'A';
}
bool NhomA::tuongThich(char nm, bool b)
{
    if (this->getRh() == false)
        if(nm=='B'||nm=='C')
            return true;
    if (this->getRh() == true)
        if (b == true)
            if(nm=='A'||nm=='C')
                return true;
    return false;
}

bool NhomA::checkDiTruyen(char me, char con)
{
    switch (me) {
        case 'A': if (con == 'A' || con == 'O')
            return true;
            break;
        case 'B': if (con == 'A' || con == 'O' || con == 'B' || con == 'C')
            return true;
            break;
        case 'C': if (con == 'A' || con == 'B' || con == 'C')
            return true;
            break;
        case 'O': if (con == 'A' || con == 'O')
            return true;
            break;
    }
    return false;
}
// ------------------------------------------------------
class NhomB : public NhomMau
{
    public:
        NhomB() {};
        ~NhomB() {};
        bool checkDiTruyen(char, char);
        char getTen();
        bool tuongThich(char nm, bool b);
};

char NhomB::getTen()
{
    return 'B';
}

bool NhomB::tuongThich(char nm, bool b)
{
    if (this->getRh() == false)
        if (nm == 'B' || nm == 'C')
            return true;
    if (this->getRh() == true)
        if (b == true)
            if (nm == 'A' || nm == 'C')
                return true;
    return false;
}

bool NhomB::checkDiTruyen(char me, char con)
{
    switch (me) {
        case 'A': if (con == 'A' || con == 'O' || con == 'B' || con == 'C')
            return true;
            break;
        case 'B': if(con == 'B' || con == 'O')
            return true;
            break;
        case 'C': if (con == 'A' || con == 'B' || con == 'C')
            return true;
            break;
        case 'O': if (con == 'B' || con == 'O')
            return true;
            break;
    }
    return false;
}
// ------------------------------------------------------
class NhomAB : public NhomMau
{
    public:
        NhomAB() {};
        ~NhomAB() {};
        bool checkDiTruyen(char, char);
        char getTen();
        bool tuongThich(char nm, bool b);
};

char NhomAB::getTen()
{
    return 'C';
}

bool NhomAB::tuongThich(char nm, bool b)
{
    if (this->getRh() == false)
        if (nm == 'C')
            return true;
    if (this->getRh() == true)
        if (b == true)
            if (nm == 'C')
                return true;
    return false;
}
bool NhomAB::checkDiTruyen(char me, char con)
{
    switch (me) {
        case 'A': if (con == 'A' || con == 'B' || con == 'C')
            return true;
            break;
        case 'B': if (con == 'A' || con == 'B' || con == 'C')
            return true;
            break;
        case 'C': if (con == 'A' || con == 'B' || con == 'C')
            return true;
            break;
        case 'O': if (con == 'A' || con == 'B')
            return true;
            break;
    }
    return false;
}
// ------------------------------------------------------
class NhomO : public NhomMau
{
    public:
        NhomO() {};
        ~NhomO() {};
        bool checkDiTruyen(char, char);
        char getTen();
        bool tuongThich(char nm, bool b);
};

char NhomO::getTen()
{
    return 'O';
}

bool NhomO::tuongThich(char nm, bool b)
{
    if (this->getRh() == false)
        return true;
    if (b == true)
        return true;
    return false;
}

bool NhomO::checkDiTruyen(char me, char con)
{
    switch (me) {
        case 'A': if (con == 'A' || con == 'O' )
            return true;
            break;
        case 'B': if (con == 'B' || con == 'O' )
            return true;
            break;
        case 'C': if (con == 'A' || con == 'B' )
            return true;
            break;
        case 'O': if (con == 'O' )
            return true;
            break;
    }
    return false;
}

int main()
{
    //Nhập danh sách nhóm máu (1.5đ)
    int n,chon;
    NhomMau *DS[50];
    cout << "Nhap so nguoi: ";
    cin >> n;
    cout<<"-------------------------";
    for (int i = 0; i < n; i++)
    {
        cout << "\nHay chon 1 cho nguoi nhom mau O";
        cout << "\nHay chon 2 cho nguoi nhom mau A";
        cout << "\nHay chon 3 cho nguoi nhom mau B";
        cout << "\nHay chon 4 cho nguoi nhom mau AB\n";
        cin >> chon;
        switch (chon) {
            case 1: DS[i] = new NhomO();
                break;
            case 2: DS[i] = new NhomA();
                break;
            case 3: DS[i] = new NhomB();
                break;
            case 4: DS[i] = new NhomAB();
                break;
        }
        DS[i]->nhap();
    }
    
    // Kiểm tra quy luật di truyền (1đ)
    int cha, me, con;
    cout << "Hay nhap theo thu tu cha, me, con: ";
    cin >> cha >> me >> con;
    bool KQ = DS[cha]->checkDiTruyen(DS[me]->getTen(), DS[con]->getTen());
   
    //Danh sách người có thể cho máu người X (1đ)
    int x;
    cout << "Nhap x";
    cin >> x;
    for (int i = 0; i < n; i++)
        if ((i != x) && (DS[x]->tuongThich(DS[i]->getTen(), DS[i]->getRh())))
            cout << "\t"<<i;
    return 0;
}