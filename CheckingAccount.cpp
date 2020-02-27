#include "CheckingAccount.h"
#include <iomanip>

using namespace std;

	
// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee ) : Account( initialBalance ) 
{
	if(fee >= 0.0)
	{
		transactionFee = fee;
	}
	else
	{
		transactionFee = 0.0;
	}
} 

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit( double amount )
{
	double bal = getBalance();
	setBalance((bal+amount));
	chargeFee();
} 

// debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit( double amount )
{
	if( amount > getBalance())
	{
		return false;
	}
	else
	{
		double bal = getBalance();
		setBalance((bal-amount));
		chargeFee();
		return true;
	}
}

// subtract transaction fee
void CheckingAccount::chargeFee()
{
	double bal = getBalance();
	setBalance((bal-transactionFee));
}

void CheckingAccount::display(ostream & os) const
{
	cout << fixed << setprecision(2);
	os << "Account type: Checking\nBalance: $" << getBalance() << "\nTransaction Fee: $" << transactionFee << endl;
}