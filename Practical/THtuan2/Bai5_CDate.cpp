#include <iostream>
using namespace std;

class CDate{
    private:
        int day,month,year;
    public:
        CDate(int=0,int=0,int=0);
        ~CDate();
        bool check();
        CDate operator+(int);
        CDate operator-(int);
        CDate operator ++();
        CDate operator --();
        long long operator-(const CDate&);
        friend ostream &operator<<(ostream &out,const CDate &a);
        friend istream &operator>>(istream &in,CDate &a);
};

CDate::CDate(int a,int b,int c){
    day=a;
    month=b;
    year=c;
}

CDate::~CDate(){
};
bool CDate::check(){
    if (month>12||month<1)
        return false;
    switch(month){
    case 1:case 3:case 5: case 7: case 8: case 10: case 12:
        if(day<=0 ||day>31) return false;
        break;
    case 4: case 6: case 9: case 11:
        if(day<=0 || day>30) return false;
        break;
    case 2:
        if(year%4==0)
        {
            if(day<=0 || day>29) return false;
        }
        else if(day<=0 ||day>28) return false;
        break;
    default: return false;
    }
    return true;
};
CDate CDate::operator+(int k){
    CDate tempt;
    tempt.day=this->day+k;
    tempt.month=this->month;
    tempt.year=this->year;
	do{
        switch(tempt.month){
            case 1:case 3:case 5: case 7: case 8: case 10: case 12:
            if ((tempt.day)>31){
                (tempt.day)-=31;
                (tempt.month)++;
                if (tempt.month>12)
                    (tempt.year)++;
       		    }
                else{
            	    k=0;
                    }
            break;
            case 4: case 6: case 9: case 11:
                if ((tempt.day)>30){
                    (tempt.day)-=30;
                    (tempt.month)++;
                if (tempt.month>12)
                    (tempt.year)++;
                }
                else{
            	    k=0;	
			    }            
            break;
            case 2:
                if(year%4==0) {
                    if ((tempt.day)>29){
                        (tempt.day)-=29;
                        (tempt.month)++;
                    if (tempt.month>12)
                        (tempt.year)++;
            	}
                else{
            		k=0;
				}
            }
            else {
            	if((tempt.day)>28){
                	(tempt.day)-=28;
                	(tempt.month)++;
                if (tempt.month>12)
                    (tempt.year)++;
                }
                else{
            		k=0;
				}
            };
            break;
        }
	}
    while(k!=0);
    return tempt;
};

CDate CDate::operator-(int k){
    CDate tempt;
    tempt.day=this->day;
    tempt.month=this->month;
    tempt.year=this->year;
    do{
        if(tempt.day>k)
        {
            tempt.day-=k;
            k=0;
        }
        else
        {
            k-=tempt.day;
            tempt.month--;
            switch(tempt.month)
            {
            case 1:case 3: case 5: case 7: case 8: case 10:
                tempt.day=31;
                break;
            case 4: case 6: case 9: case 11:
                tempt.day=30;
                break;
            case 2:
                if(tempt.year%4==0) tempt.day=29;
                else tempt.day=28;
                break;
            case 0:
                tempt.month=12;
                tempt.year--;
                tempt.day=31;
                break;
            }
        }
    }
    while(k>0);
    return tempt;
;}

CDate CDate::operator++(){
	(this->day)+=1;
    switch(month){
        case 1:case 3:case 5: case 7: case 8: case 10: case 12:
            if ((this->day)>31)
            {
                (this->day)-=31;
                (this->month)++;
                if (this->month>12)
                    (this->year)++;
            }
            break;
        case 4: case 6: case 9: case 11:
            if ((this->day)>30)
            {
                (this->day)-=30;
                (this->month)++;
                if (this->month>12)
                    (this->year)++;
            }
            break;
        case 2:
            if(year%4==0) {
                if ((this->day)>29){
                    (this->day)-=29;
                    (this->month)++;
                    if (this->month>12)
                    	(this->year)++;
                }
            }
            else {
                if ((this->day)>28)
            {
                (this->day)-=28;
                (this->month)++;
                if (this->month>12)
                    (this->year)++;
            }
            };
            break;
    }
    return *this;
}

CDate CDate::operator--()
{
    this->day--;
    if(this->day==0)
    {
        this->month--;
        switch(this->month)
        {
        case 1: case 3: case 5: case 7: case 8: case 10:
            this->day=31;
            break;
        case 0:
            this->day=31;
            this->month=12;
            this->year--;
            break;
        case 4: case 6: case 9: case 11:
            this->day=30;
            break;
        case 2:
            if((this->year)%4==0 ) this->day=29;
            else this->day=28;
            break;
        }
    }
    return *this-1;
}

long long CDate::operator-(const CDate& temp){
    long long a,b,check_month;
    a=((this->year)-1)*365+((this->year)-1)/4+this->day;
    (this->month)-=1;
    while(this->month>0){
        switch(this->month){
            case 1: case 3: case 5: case 7: case 8: case 10:
                a+=31;
                this->month--;
                break;
            case 4: case 6: case 9: case 11:
            	a+=30;
            	this->month--;
            	break;
            case 2:
            	if(this->year%4==0)
            	{
                	a+=29;
                this->month--;
            	}
            	else
            	{
                	a+=28;
                	this->month--;
            	}
            case 0:
            	break;
        }
    }
    b=(temp.year-1)*365+(temp.year-1)/4+temp.day;
    check_month=temp.month-1;
    while(check_month>0){
        switch(check_month){
            case 1: case 3: case 5: case 7: case 8: case 10:
                b+=31;
                check_month--;
                break;
            case 4: case 6: case 9: case 11:
            	b+=30;
            	check_month--;
            	break;
            case 2:
            	if((this->year)%4==0){
                b+=29;
                check_month--;
            	}
				else{
                b+=28;
                check_month--;
           		}
           		break;
            case 0:
            	break;	
        }
    }
    if (a-b < 0)
    {
        throw runtime_error("Khong hop le!\n");
    }
    return a-b;
}
    

istream &operator>>(istream &in,CDate &a){
    in>>a.day>>a.month>>a.year;
    while(a.check()==false)
    {
        cout<<"Khong hop le! Vui long nhap lai:";
        in>>a.day>>a.month>>a.year;
    }
    return in;
};

ostream &operator<<(ostream &out,const CDate &a){
    out<<"ngay "<<a.day<<" thang "<<a.month<<" nam "<<a.year;
    return out;
};

int main(){
    CDate a,b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    cout<<a-12<<endl;
    cout<<++a<<endl;
    cout<<--a<<endl;
    try{
        cout<<"Hieu 2 ngay: "<<a-b;;
    }
    catch (runtime_error &e){
        cout<<e.what();
    }
    return 0;
};
