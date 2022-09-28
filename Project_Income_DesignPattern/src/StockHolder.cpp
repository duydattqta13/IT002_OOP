#include "StockHolder.h"
#include "../ExternTaxRateTable.h"

StockHolder::StockHolder()
{
    taxRateTable.addObserver(this, TaxRateTable::STOCK_TAX_RATE_MESSAGE);
}

StockHolder::~StockHolder()
{
    //dtor
}

double StockHolder::getNetIncome() const{
    return incomeFromStock - incomeFromStock * stockTaxRate;
}

void StockHolder::update(Subject *subject, int type){
    TaxRateTable* taxRateTable1 = (TaxRateTable*)subject;
    stockTaxRate = taxRateTable1->getStockTaxRate();
    cout<< *this << endl;
}

ostream & operator << (ostream &out, const StockHolder &c)
{
    out << c.getNetIncome();
    return out;
}

istream & operator >> (istream &in,  StockHolder &c)
{
    cout << "Enter income from stock: ";
    in >> c.incomeFromStock;
    return in;
}
