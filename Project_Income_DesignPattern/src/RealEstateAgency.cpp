#include "RealEstateAgency.h"
#include "TaxRateTable.h"
#include "../ExternTaxRateTable.h"

RealEstateAgency::RealEstateAgency()
{
    taxRateTable.addObserver(this, TaxRateTable::STOCK_TAX_RATE_MESSAGE);
    taxRateTable.addObserver(this, TaxRateTable::REAL_ESTATE_TAX_RATE_MESSAGE);
}

RealEstateAgency::~RealEstateAgency()
{
    //dtor
}

double RealEstateAgency::getNetIncome() const{
    return (incomeFromStock + incomeFromRealEstate)
        - (incomeFromStock * stockTaxRate)
        - (incomeFromRealEstate * realEstateTaxRate);
}

void RealEstateAgency::update (Subject *subject, int type){
    TaxRateTable* taxRateTable1 = (TaxRateTable*)subject;
    if (type == 1)
        stockTaxRate = taxRateTable1->getStockTaxRate();
    else
        realEstateTaxRate = taxRateTable1->getRealEstateTaxRate();

    cout<< *this << endl;
}

ostream & operator << (ostream &out, const RealEstateAgency &c)
{
    out << c.getNetIncome();
    return out;
}

istream & operator >> (istream &in,  RealEstateAgency &c)
{
    cout << "Enter income from stock: ";
    in >> c.incomeFromStock;

    cout << "Enter income from real estate agency: ";
    in >> c.incomeFromRealEstate;
    return in;
}



