#include "SavingsAccount.h"
#include <iomanip>

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ) : Account( initialBalance ) 
{
	if (rate >= 0.0)
	{
		interestRate = rate*100;
	}
	else
	{
		interestRate = 0.0;
	}
}

double SavingsAccount::calculateInterest() 
{
	
} 
void SavingsAccount::display(ostream & os) const
{
	cout << fixed << setprecision(2);
	os << "Account type: Saving\nBalance: $" << getBalance() << "\nInterest Rate (%): " << interestRate << endl;
}