#include <iostream>
using namespace std;

class Bank
{
private:
    float bankBalance = 0;
    string password;

public:
    string bankName = "BOI";
    string branch = "Vijay Nagar";
    string ifscCode = "BOI123";
    string name;
    int accNo;
    int cId;

    Bank(string inputName, int inputCId, int inputAccNo, string inputPassword)
    {
        name = inputName;
        cId = inputCId;
        accNo = inputAccNo;
        password = inputPassword;
    }

    void bankInfo()
    {
        cout << "Bank Name: " << bankName << endl;
        cout << "Branch: " << branch << endl;
        cout << "Name: " << name << endl;
        cout << "C Id: " << cId << endl;
        cout << "Account Number: " << accNo << endl;
        cout << "IFSC Code: " << ifscCode << endl;
    }

    void balanceEnquiry()
    {
        cout << "Your current balance is: " << bankBalance << endl;
    }

    void deposit()
    {
        int amount;

        cout << "Enter the amount: ";
        cin >> amount;

        if (amount > 0)
        {
            bankBalance += amount;
            balanceEnquiry();
        }
        else
        {
            cout << "Enter valid amount" << endl;
        }
    }

    void withdraw()
    {
        int amount;

        cout << "Enter the amount: ";
        cin >> amount;

        if (amount > 0 && amount <= bankBalance)
        {
            bankBalance -= amount;
        }
        else if (amount <= 0)
        {
            cout << "Enter valid amount" << endl;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }

        balanceEnquiry();
    }

    friend void checkPassword(Bank obj);
};

// =====================================================

void Methods(Bank obj)
{
    int option;

    do
    {
        cout << "Select -" << endl;
        cout << "1. Bank Info." << endl;
        cout << "2. Balance Enquiry" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;

        cin >> option;

        cout << "===========================" << endl;
        switch (option)
        {
            case 1:
            obj.bankInfo();
            break;
            case 2:
            obj.balanceEnquiry();
            break;
            case 3:
            obj.deposit();
            break;
            case 4:
            obj.withdraw();
            break;
            case 5:
            cout << "ThankYou for banking with us." << endl;
            break;
            default:
            cout << "Enter valid option" << endl;
            break;
        }
        cout << "===========================" << endl;
    } while (option != 5);
}

// =====================================================

void checkPassword(Bank obj){
    string inputPassword;
    
    do {

        cout << "Enter your password: " << endl;
        cin >> inputPassword;

    } while (obj.password != inputPassword);

    cout << "Login Successfully." << endl;

}

// =====================================================

void login(Bank arr[], int len)
{
    int id;
    int match = 0;

    do
    {
        cout << "Enter your id: " << endl;
        cin >> id;

        for (int i = 0; i < len; i++)
        {
            if (id == arr[i].cId)
            {
                checkPassword(arr[i]);
                cout << "=======================" << endl;
                Methods(arr[i]);
                match = 1;
            }
        }

    } while (match != 1);
}

// =====================================================

Bank signup(){
    string inputName;
    int inputCId;
    int inputAccNo;
    string inputPassword;

    cout << "Enter your name: ";
    cin >> inputName;

    cout << "Enter your cID: ";
    cin >> inputCId;

    cout << "Enter your Account number: ";
    cin >> inputAccNo;

    cout << "Create Password: ";
    cin >> inputPassword;

    Bank obj(inputName, inputCId, inputAccNo, inputPassword);

    return obj;

}

// =====================================================

void Display(Bank *arr, int size, int count = 1){
    int option;
    
    cout << "Select - " << endl;
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    
    cin >> option;

    switch(option){
        case 1:
            cout << "login" << endl;
            cout << "===================" << endl;
            login(arr, size);
            cout << "===================" << endl;
            break;
        case 2:
            cout << "===================" << endl;
            arr[size] = signup();
            cout << "===================" << endl;
            ++size;
            Display(arr, size, 1);
            break;
        default :
            cout << "Select valid option." << endl;
            if(count < 3){
                Display(arr, size, count + 1);
            }
            else{
                cout << "Limits over" << endl;
            }
    }
}

// =====================================================

int main()
{

    Bank c1("Aman Soni", 1, 123, "Aman@123");
    Bank c2("Anuj Yadav", 2, 124, "Anuj@123");

    Bank allCustomer[] = {c1, c2};
    //                    0   1

    int length = sizeof(allCustomer) / sizeof(allCustomer[0]);

    Display(allCustomer, length, 1);

    return 0;
}