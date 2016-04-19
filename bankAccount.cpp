#include <iostream>
#include <windows.h>
#include <sstream>
#include <time.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "main.h"
using namespace std;
ifstream fin;
ofstream fout;

//Methods Defination
void BankAccount::createAccount()
{
	//code//
	char any;
	char accountNumber2[10];
		cout<<"Kindly provide your details below \n";
		cout<<"**********************************\n";
		cout<<"First Name: ";
		cin>>firstName;
		cout<<"Last name: ";
		cin>>lName;
		cout<<"Id number: ";
		cin>>idNo;
		do{
			cout<<"First deposit: ";
			cin>>accountBal;
			if(!cin>>accountBal)
			{
				cerr<<"Deposited amount should be an interger"<<endl;
				cout<<"Try again"<<endl;
				cin.clear();
			}
		}while(!cin>>accountBal);
	do
	{
		int account;
		srand(time(NULL));
		account= rand()%10000000+99999;
		string strAccount = static_cast<ostringstream*>(&(ostringstream()<<account))->str();
		strcpy(accountNumber,strAccount.c_str());
		strcpy(accountNumber2,accountNumber);
		strcat(accountNumber,".txt");
		fin.open(accountNumber);
		}while(!fin.fail());
		system("cls");
		cout<<"Request succesful\n Your account number is: "<<accountNumber2<<endl;
		fout.open(accountNumber);
		fout<<"Account Number: "<<accountNumber2<<endl;
		fout<<"Name: "<<lName<<" "<<firstName<<endl;
		fout<<"Id Number: "<<idNo<<endl;
		fout<<"Current Balance: "<<accountBal;
		fout.close();
		fin.close();
		fflush(stdin);
		cout<<"Press any key to continue ....";
		getchar();
		fflush(stdin);
		system("cls");
		login(accountNumber);

}
void BankAccount::login(char accountNum[])
{
	system("cls");
	cout<<"**********MENU*********"<<endl;
	cout<<"************************\n";
	cout<<"1. Withdraw\n";
	cout<<"2. Deposit\n";
	cout<<"3. Show account details"<<endl<<"4. Logout"<<endl;
	int choice;
	cout<<"Enter a menu option: ";
	cin>>choice;
	system("cls");
	switch (choice)
	{
		case 1:
		withdraw(accountNum);
		break;
		case 2:
		deposit(accountNum);
		break;
		case 3:
		showAccount(accountNum);
		break;
		case 4:
		logout();
		default:
		cout<<"Enter 1, 2 or 3"<<endl;
	}


}
void BankAccount::withdraw(char accNo[])
{
	string newline;
	fin.open(accNo);
	char line[50];
	fin.seekg(ios::beg);
	while(!fin.eof())
	{
		fin.getline(line,50);
	}
	 //cout<<line<<endl;
	int bal=0, nbal,valuein;
	newline=string(line);
	newline.erase(0,17);
	stringstream convert(newline);
	convert>>bal;
	cout<<bal<<endl;
	cout<<"Amount to withdraw: ";
	cin>>nbal;
	valuein=nbal;
	system("cls");
	fout.open(accNo, ios::app);
	if(nbal>=bal)
	{
		cout<<"You do not have sufficient funds to withdraw such an amount"<<endl;
		Sleep(2000);
	}
	else{
		nbal=bal-nbal;
		fout<<endl;
		fout<<"Withdrew: "<<valuein<<" \n";
		fout<<"Current Balance: "<<nbal;
		cout<<"Confirmed! Withdrew "<<valuein<<endl;
		cout<<"Your new account balance is: "<<nbal<<endl;
		fout.close();
	}
	
	fin.close();
	cout<<"Press any key to continue";
	fflush(stdin);
	getchar();
	fflush(stdin);
	system("cls");
	login(accNo);


}
void BankAccount::deposit(char accNo[])
{
	string newline;
	//strcat(accNo,".txt");
	fin.open(accNo);
	char line[50];
	fin.seekg(ios::beg);
	while(!fin.eof())
	{
		fin.getline(line,50);
	}
	 //cout<<line<<endl;
	int bal=0, nbal;
	newline=string(line);
	newline.erase(0,17);
	stringstream convert(newline);
	convert>>bal;
	//cout<<bal<<endl;
	cout<<"Amount to deposit: ";
	cin>> nbal;
	system("cls");
	bal=bal+nbal;
	fout.open(accNo, ios::app);
	fout<<endl;
	fout<<"Deposited: "<<nbal<<endl;
	fout<<"Current Balance: "<<bal;
	cout<<"Confirmed! Deposited: "<<nbal<<endl;
	cout<<"Your new account balance is: "<<bal<<endl;
	fout.close();

	fin.close();
	cout<<"Press any key to continue";
	fflush(stdin);
	getchar();
	fflush(stdin);
	system("cls");
	login(accNo);


}
void BankAccount::showAccount(char accNo[])
{

	char line[25];
	fin.open(accNo);
	while(!fin.eof())
	{
		fin.getline(line,25);
		cout<<line<<endl;

	}
	fin.close();
	cout<<"Press any key to continue";
	fflush(stdin);
	getchar();
	fflush(stdin);
	system("cls");
	login(accNo);

}
void BankAccount::logout()
{
	sysStart();
	
}
void BankAccount::stopSys()
{
	cout<<"Thank you for banking with us\n";
	Sleep(1500);
	system("color 7");
	Sleep(1500);
	system("cls");
	exit(0);

}
void BankAccount::sysStart()
{
	int count=3;
	ifstream file;
	char accountNum[12];
	system("color 20");
	system("cls");
	cout<<"Welcome to the Jammii Bora bank System!\n";
	int option;
	do{
	cout<<"1. Create an account"<<endl<<"2. login"<<endl<<"3. shutdown"<<endl<<"Enter an option (1,2,3):";
	cin>>option;
	fflush(stdin);
	system("cls");
	switch (option)
	{
		case 1:
			system("cls");
			createAccount();
			break;
		case 2:
			do
			{
				system("cls");
				cout<<"Account number: ";
				cin>>accountNum;
				strcat(accountNum,".txt");
				file.open(accountNum);
				if(file.fail())
				{
					if(count)
					{
						cerr<<"Error! Confirm your account number and try again. You have "<<count<<" more chances\n";
						cout<<"Press any key to continue";
						fflush(stdin);
						getchar();
						fflush(stdin);
						system("cls");
						count--;

					}
					else
					{
						cerr<<"Too many Inavalid attempts. Kindly contact the bank manager\n";
						logout();
					}
					
				}
			}while(file.fail());
			file.close();
			
			login(accountNum);
			break;
		case 3:
			stopSys();
		default:
			cout<<"Invalid option!"<<endl;
		}
	}while(option!=1||option!=2||option!=3);
}