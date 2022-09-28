#include "TaxRateTable.h"

TaxRateTable::TaxRateTable()
{

}

TaxRateTable::TaxRateTable(int more): Subject(more)
{
    //ctor
}

TaxRateTable::~TaxRateTable()
{
    //dtor
}

double TaxRateTable::getIncomeTaxRate (){
    return incomeTaxRate;
}

void TaxRateTable::setIncomeTaxRate(double newIncomeTaxRate){
    incomeTaxRate = newIncomeTaxRate;
    this->notify(INCOME_TAX_RATE_MESSAGE);
}

double TaxRateTable::getStockTaxRate() {
    return stockTaxRate;
}

void TaxRateTable::setStockTaxRate (double newStockTaxRate){
    stockTaxRate = newStockTaxRate;
    this->notify(STOCK_TAX_RATE_MESSAGE);
}

double TaxRateTable::getRealEstateTaxRate(){
    return realEstateTaxRate;
}

void TaxRateTable::setRealEstateTaxRate (double newRealEstateTaxRate){
    realEstateTaxRate = newRealEstateTaxRate;
    this->notify(REAL_ESTATE_TAX_RATE_MESSAGE);
}
