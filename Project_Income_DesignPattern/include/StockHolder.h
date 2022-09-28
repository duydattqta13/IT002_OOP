#ifndef STOCKHOLDER_H
#define STOCKHOLDER_H

#include "Observer.h"
#include "TaxRateTable.h"
#include "Person.h"

class StockHolder : public Person, public Observer
{
    public:
        StockHolder();
        virtual ~StockHolder();

        double getNetIncome() const;

        void update(Subject *subject, int more);

        friend ostream & operator << (ostream &out, const StockHolder &c);
        friend istream & operator >> (istream &in,  StockHolder &c);

    protected:

    private:
        double incomeFromStock = 0, stockTaxRate;
};

#endif // STOCKHOLDER_H
