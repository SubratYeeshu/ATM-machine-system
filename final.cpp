#include <bits/stdc++.h>
using namespace std;

class
{
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    //setData function is setting the data into the private member variables
    void setData(long int account_No_a, string name_a, int Pin_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;
        name = name_a;
        PIN = Pin_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    //setter funtion to get the value of account NO-
    long int getAccountNo()
    {
        return account_No;
    }
    //get the  user's name
    string getname()
    {
        return name;
    }

    //getPIN funtion is returning the user's PIN
    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()

    {
        return mobile_No;
    }

    //setMobile function is updating the user mobile no
    void setmobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No) //it will check old mobile no
        {
            mobile_No = mob_new; //and update with new, if old matches
            cout << "\n"
                 << "Sucessfully Update Mobile no.";
            _getch(); //getch ids to hold the screen{untill user press any key
        }

        else //does not update if old mobile no does not matches
        {
            cout << endl
                 << "Incorrect!!! Old Mobile no";
            _getch();
        }
    }

    //cashWithDraw funtion is used to withdraw money from ATM

    void cashWithDraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance)
        {
            balance -= amount_a;
            cout << endl
                 << "please Collect Your Cash";
            cout << endl
                 << "Available Balance :" << balance;
            _getch(); //getch is to hold the screen(until user press any key)
        }

        else
        {
            cout << endl
                 << "Invalid Input or Insufficient Balance";
            _getch(); //getch is  to hold the screen (until user press any key)
        }
    }
};

int main()
{
    int choice = 0, enterPIN; //enterPIN and enterAccountNo.--->user Authenticcation
    long int enterAccountNo;
    system("cls");

    cout << endl
         << "\t\t\t\t*****WELCOME TO BANK ATM******" << endl;
    //created user(object)

    atm user1;
    //set default name of the account holder
    cout << "***Enter your name of account holder which u want to link your account in this ATM branch***\n\n";

    string names;
    getline(cin, names);
    cout << "Enter your account No. which u want to link in this ATM\n\n";
    long long int ac_n;

    cin >> ac_n;
    cout << "ENTER YOUR SECRET PIN NUMBER WE KEEP IT CONFIDENTAL\n\n";
    long long int pins;
    cout << "Secret Code: ";
    cin >> pins;

    //set user details (into object)
    user1.setData(ac_n, names, pins, 45000.90, "7905158689"); //set default data siince we are not using file handling here.

    do
    {
        system("cls");
        cout << "\n\t\t\t\tCongratulations!!! Your Account Succesfully linked to the ATM \n\n\t\t\t\t************Enter Your Details to proceed further*****************\n";
        cout << endl
             << "\t\t\t\tEnter your Account NO "; //asking to enter account No

        cin >> enterAccountNo;

        cout << endl
             << "\t\t\t\tEnter PIN";
        cin >> enterPIN;

        //check whether enter values matches with user details
        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                //user interface
                cout << endl
                     << "******Welcome to ATM********" << endl;
                cout << endl
                     << "select Options";
                cout << endl
                     << "1.check Balance";
                cout << endl
                     << "2.cash withdraw";
                cout << endl
                     << "3.show User deatils";
                cout << endl
                     << "4.update Mobile no: ";
                cout << endl
                     << "5. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << endl
                         << " Your Bank Balance is: " << user1.getBalance();
                    _getch();
                    break;

                case 2:
                    cout << endl
                         << "Enter the Amount :";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;

                case 3:
                    cout << endl
                         << "*****User details are:- ";
                    cout << endl
                         << "-> Account no " << user1.getAccountNo();
                    cout << endl
                         << "-> Name       " << user1.getname();
                    cout << endl
                         << "-> Balance    " << user1.getBalance();
                    cout << endl
                         << "-> Mobile NO. " << user1.getMobileNo();

                    _getch();
                    break;

                case 4:
                    cout << endl
                         << "Enter old Mobile No .";
                    cin >> oldMobileNo;

                    cout << endl
                         << "Enter New Mobile NO. ";
                    cin >> newMobileNo;

                    user1.setmobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    exit(0);

                default:
                    cout << endl
                         << "Enter valid data !!!";
                }

            } while (1);
        }

        else
        {
            cout << endl
                 << "\t\t\t\t sorry!!User details are invalid!!! try Next time";
            _getch();
        }

    } while (1);
    return 0;
}
