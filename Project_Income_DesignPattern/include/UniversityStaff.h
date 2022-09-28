#ifndef UNIVERSITYSTAFF_H
#define UNIVERSITYSTAFF_H

#include "Observer.h"
#include "TaxRateTable.h"
#include "Person.h"

class UniversityStaff : public Person, public Observer
{
    public:

        UniversityStaff();
        virtual ~UniversityStaff();

        double getNetIncome() const;

        void update(Subject *subject, int more);

        friend ostream & operator << (ostream &out, const UniversityStaff &c);
        friend istream & operator >> (istream &in,  UniversityStaff &c);
    protected:

    private:
        double fixedSalary = 0, incomeTaxRate = 0;
};

#endif // UNIVERSITYSTAFF_H
