#ifndef REALESTATEAGENCY_H
#define REALESTATEAGENCY_H

#include "Observer.h"
#include "TaxRateTable.h"
#include "Company.h"

class RealEstateAgency :
    public Company,
    public Observer
{
    public:
        RealEstateAgency();
        virtual ~RealEstateAgency();

        double getNetIncome() const;

        void update(Subject *subject, int more);

        friend ostream & operator << (ostream &out, const RealEstateAgency &c);
        friend istream & operator >> (istream &in,  RealEstateAgency &c);

    protected:

    private:
        double incomeFromStock = 0, incomeFromRealEstate = 0, stockTaxRate, realEstateTaxRate;
};

#endif // REALESTATEAGENCY_H
