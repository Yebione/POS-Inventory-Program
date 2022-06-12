#include <iostream>
#include <fstream>
#include <conio.h>
#include "auth.h"
#include "auth.cpp"

using namespace std;

int main ()
{
    Auth auth;
    int decider=0;

    file.open("password.txt");
    if(file.fail())
    {
        auth.reg_pass();
    }
    file.close();

    decider=auth.login();

    switch (decider)
    {
    case 1:
        cout << "Hi Manager"; // Manager function
        break;

    case 2:
        cout << "Hi Cashier" ; // Cashier Funtion

    default:
        cout << "Error, terminating now" ; // Error
        exit (1);
    }
}


