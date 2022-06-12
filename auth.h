#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <fstream>
using namespace std;

fstream file;
class Auth
{
public:
    void reg_pass ();
    int login ();

private:
    string manager_pass;
    string reg_manager_pass;
    string confirm_manager_pass;

    string cashier_pass;
    string reg_cashier_pass;
    string confirm_cashier_pass;

    string entered_pass;
};


#endif // AUTH_H
