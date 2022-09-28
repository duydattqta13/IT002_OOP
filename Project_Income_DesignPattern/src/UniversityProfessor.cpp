#include "UniversityProfessor.h"
#include "../ExternTaxRateTable.h"

UniversityProfessor::UniversityProfessor()
{
    taxRateTable.addObserver(this, TaxRateTable::INCOME_TAX_RATE_MESSAGE);
}

UniversityProfessor::~UniversityProfessor()
{
    //dtor
}

double UniversityProfessor::getTotalSalary() const{
    return fixedSalary + teachingSalary;
}

double UniversityProfessor::getNetIncome() const{
    return getTotalSalary() - getTotalSalary() * incomeTaxRate;
}

void UniversityProfessor::update(Subject *subject, int type){
    TaxRateTable* taxRateTable1 = (TaxRateTable*)subject;
    incomeTaxRate = taxRateTable1->getIncomeTaxRate();
    cout<< *this << endl;
}

ostream & operator << (ostream &out, const UniversityProfessor &c)
{
    out << c.fixedSalary << "\t | \t" << c.teachingSalary << "\t | \t"  << c.getNetIncome();
    return out;
}

istream & operator >> (istream &in,  UniversityProfessor &c)
{
    cout << "Enter fixed salary: ";
    in >> c.fixedSalary;
    cout << "Enter teaching salary: ";
    in >> c.teachingSalary;
    return in;
}
