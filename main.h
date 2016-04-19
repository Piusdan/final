#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

class BankAccount{
	public:
		void createAccount();
		void deposit(char[]);
		void withdraw(char[]);
		void login(char[]);
		void stopSys();
		void sysStart();
		void logout();
		void showAccount(char[]);

	private:
		char accountNumber[12];
		int accountBal;
		char firstName[12];
		char lName[12];
		char idNo[10];
		
};
#endif
