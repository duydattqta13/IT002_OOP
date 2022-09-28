#ifndef UNIVERSITYPROFESSOR_H
#define UNIVERSITYPROFESSOR_H

#include "Observer.h"
#include "TaxRateTable.h"
#include "Person.h"

class UniversityProfessor: public Person, public Observer
{
    public:
        UniversityProfessor();
        virtual ~UniversityProfessor();

        double getTotalSalary () const;

        double getNetIncome() const;


        void update(Subject *subject, int more);

        friend ostream & operator << (ostream &out, const UniversityProfessor &c);
        friend istream & operator >> (istream &in,  UniversityProfessor &c);

    protected:

    private:
        double fixedSalary = 0, teachingSalary = 0, incomeTaxRate;
};

#endif // UNIVERSITYPROFESSOR_H
