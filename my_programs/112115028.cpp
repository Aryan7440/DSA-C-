#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class bank
{
    int acno;
    char nam[100], account_type[100];
    float bal;

public:
    bank(int acc_no, char *name, char *acc_type, float balance) // Parameterized Constructor
    {
        acno = acc_no;
        strcpy(nam, name);
        strcpy(account_type, acc_type);
        bal = balance;
    }
    void deposit();
    void withdraw();
    void display();
};
void bank::deposit() // depositing an amount
{
    int damt1;
    cout << "\n Enter Deposit Amount = ";
    cin >> damt1;
    bal += damt1;
}
void bank::withdraw() // withdrawing an amount
{
    int wamt1;
    cout << "\n Enter Withdraw Amount = ";
    cin >> wamt1;
    if (wamt1 > bal)
        cout << "\n Cannot Withdraw Amount";
    bal -= wamt1;
}
void bank::display() // displaying the details
{
    cout << "\n ----------------------";
    cout << "\n Accout Number. : " << acno;
    cout << "\n Name : " << nam;
    cout << "\n Account Type : " << account_type;
    cout << "\n Balance : " << bal;
}
int main()
{
    int acc_no;
    char name[100], acc_type[100];
    float balance;
    cout << "\n ENTER DETAILS OF BANK ACCOUNT: \n";
    cout << "-----------------------" << endl;
    cout << "***********************";
    cout << "\n Accout No. ";
    cin >> acc_no;
    cout << "\n Name : ";
    cin >> name;
    cout << "\n Account Type : ";
    cin >> acc_type;
    cout << "\n Balance : ";
    cin >> balance;
    cout << "***********************" << endl;
    cout << "-----------------------" << endl;
    

    bank b1(acc_no, name, acc_type, balance);
    b1.deposit();
    b1.withdraw();
    b1.display();
    return 0;
}