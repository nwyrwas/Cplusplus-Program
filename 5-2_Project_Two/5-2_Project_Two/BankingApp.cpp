#include <iostream>
#include <iomanip>
using namespace std;

void calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double annualInterest, int years) {
	double totalAmount;
	double interestAmount;
	int i;

	totalAmount = initialInvestment;

	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	for (i = 0; i < years; i++) {
		interestAmount = totalAmount * (annualInterest / 100);

		totalAmount += interestAmount;

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << setw(12) << totalAmount << "\t\t\t$" << setw(12) << interestAmount << "\n";
	}
}

void calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int years) {
	double totalAmount;
	double interestAmount;
	double yearEarnedInterest;
	int i;
	int j;

	totalAmount = initialInvestment;
	cout << endl;

	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	for (i = 0; i < years; i++) {
		yearEarnedInterest = 0;

		for (j = 0; j < 12; j++) {
			interestAmount = (totalAmount + monthlyDeposit) * (annualInterest / 100 / 12);
			yearEarnedInterest += interestAmount;
			totalAmount += monthlyDeposit + interestAmount;
		}

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << setw(12) << totalAmount << "\t\t\t$" << setw(12) << yearEarnedInterest << "\n";
	}
}

int main()
{
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int years;

	cout << "********************************\n";
	cout << "********** Data Input **********\n";
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> years;

	calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, years);
	calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, years);



	return 0;
}