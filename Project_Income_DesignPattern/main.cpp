#include <iostream>

#include "ExternTaxRateTable.h"

#include "UniversityProfessor.h"
#include "UniversityStaff.h"

#include "StockHolder.h"

#include "RealEstateAgency.h"

using namespace std;

TaxRateTable taxRateTable;

void printTaxMenu()
{
    cout << "0 - Print tax rate info\n"
         << "1 - Create a professor\n"
         << "2 - Create a staff\n"
         << "3 - Create a stock holder\n"
         << "4 - Create a real estate agency\n"
         << "5 - Change incomeTaxRate\n"
         << "6 - Change stockTaxRate\n"
         << "7 - Change realEstateTaxRate\n"
         << "Other - Quit\n"
         << "Please enter your selection: ";
}

int main() {
    cout << "Hello, World!" << endl;

    while(true)
    {
        printTaxMenu();
        int choice;
        cin >> choice;

        if(choice == 0)
        {
            cout << "Income tax rate: " << taxRateTable.getIncomeTaxRate() << '\n';
            cout << "Stock tax rate: " << taxRateTable.getStockTaxRate() << '\n';
            cout << "Real estate tax rate: " << taxRateTable.getRealEstateTaxRate() << '\n';
            continue;
        }
        if(choice == 1)
        {
            UniversityProfessor* universityProfessor = new UniversityProfessor();
            cin >> *universityProfessor;
            cout << *universityProfessor << endl;
            continue;
        }
        if(choice == 2)
        {
            UniversityStaff* universityStaff = new UniversityStaff();
            cin >> *universityStaff;
            cout << *universityStaff << endl;
            continue;
        }
        if(choice == 3)
        {
            StockHolder *stockHolder = new StockHolder();
            cin >> *stockHolder;
            cout << *stockHolder << endl;
            continue;
        }
        if(choice == 4)
        {
            RealEstateAgency* realEstateAgency = new RealEstateAgency();
            cin >> *realEstateAgency;
            cout << *realEstateAgency << endl;
            continue;
        }
        if(choice == 5)
        {
            double newIncomeTaxRate;
            cout << "Enter new income tax rate: ";
            cin >> newIncomeTaxRate;

            taxRateTable.setIncomeTaxRate(newIncomeTaxRate);
            continue;
        }
        if(choice == 6)
        {
            double newStockTaxRate;
            cout << "Enter new stock tax rate: ";
            cin >> newStockTaxRate;
            taxRateTable.setStockTaxRate(newStockTaxRate);
            continue;
        }
        if(choice == 7)
        {
            double newRealEstateTaxRate;
            cout << "Enter new real estate tax rate: ";
            cin >> newRealEstateTaxRate;
            taxRateTable.setRealEstateTaxRate(newRealEstateTaxRate);
            continue;
        }
        break;
    }
    return 0;
}
