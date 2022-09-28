#include "UniversityStaff.h"
#include "../ExternTaxRateTable.h"

UniversityStaff::UniversityStaff()
{
    taxRateTable.addObserver(this, TaxRateTable::INCOME_TAX_RATE_MESSAGE);
}

UniversityStaff::~UniversityStaff()
{
    //dtor
}

double UniversityStaff::getNetIncome() const{
    return fixedSalary - fixedSalary * incomeTaxRate;
}

void UniversityStaff::update(Subject *subject, int more){
    TaxRateTable* taxRateTable1 = (TaxRateTable*)subject;
    incomeTaxRate = taxRateTable1->getIncomeTaxRate();
    cout<< *this << endl;
}

ostream & operator << (ostream &out, const UniversityStaff &c)
{
    out << c.fixedSalary << "\t | \t" << c.getNetIncome();
    return out;
}

istream & operator >> (istream &in,  UniversityStaff &c)
{
    cout << "Enter fixed salary: ";
    in >> c.fixedSalary;
    return in;
}
