#include <iostream>
#include <fstream>
#include <conio.h>
#include "auth.h"

using namespace std;

void Auth::reg_pass()
{
    cout << "No password info found. Please Register. \n";
    cout << "Enter a Manager Password: ";
    cin >> reg_manager_pass;
    cout << "Confirm Manager Password: ";
    cin >> confirm_manager_pass;

    if (reg_manager_pass != confirm_manager_pass)
    {
        cout << "Error, confirm password does not match.\n Terminating the program now.";
        exit (1);
    }

    cout << endl;
    cout << "Enter a Cashier Password: ";
    cin >> reg_cashier_pass;
    cout << "Confirm Manager Password: ";
    cin >> confirm_cashier_pass;

    if (reg_cashier_pass != confirm_cashier_pass)
    {
        cout << "Error, confirm password does not match.\n Terminating the program now.";
        exit (1);
    }

    file.open("password.txt", ios::app);
    file << reg_manager_pass << "\n" << reg_cashier_pass;
    file.close();

    cout << "Register process complete! Press any key to go to login page... ";
    getch ();

}

int Auth::login()
{
    system ("cls");
    file.open("password.txt");
    while (!file.eof())
    {
        getline (file, manager_pass, '\n');
        getline (file, cashier_pass, '\n');
    }

    while (1)
    {
        cout << "Enter Password: ";
        cin >> entered_pass;

        if (entered_pass == manager_pass)
        {
            return 1;
        }

        else if (entered_pass == cashier_pass)
        {
            return 2;
        }

        else {
            system ("cls");
            cout << "Error, wrong password try again.. \n";
        }
    }
    file.close();
}
