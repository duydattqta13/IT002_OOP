#ifndef TAXRATETABLE_H
#define TAXRATETABLE_H

#include "Subject.h"

class TaxRateTable: public Subject
{
    public:

        static const int INCOME_TAX_RATE_MESSAGE = 0;
        static const int STOCK_TAX_RATE_MESSAGE = 1;
        static const int REAL_ESTATE_TAX_RATE_MESSAGE = 2;

        TaxRateTable();
        TaxRateTable(int More);
        virtual ~TaxRateTable();

        double getTaxRate ();
        void setTaxRate (double newTaxRate);

        double getIncomeTaxRate ();
        void setIncomeTaxRate (double newIncomeTaxRate);

        double getStockTaxRate ();
        void setStockTaxRate (double newStockTaxRate);

        double getRealEstateTaxRate ();
        void setRealEstateTaxRate (double newRealEstateTaxRate);

    protected:

    private:
        double
        incomeTaxRate = 0.1, //type == 0
        stockTaxRate = 0.2, //type == 1
        realEstateTaxRate = 0.3; //type == 2

};
#endif // TAXRATETABLE_H
