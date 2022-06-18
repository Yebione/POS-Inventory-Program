#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;
fstream file;

class Item
{
public:
    Item();
    void register_item_to_database ();
    void purchase ();
    void database_reader ();
    int populator();
    void database_updater(int[], int size);
    void display_database ();
    void search_database();

private:
    string item_id[100];
    string item_name[100];
    string item_price[100];
    string item_stocks[100];
};

int main( )
{
    Item item;
    //item.register_item_to_database();

    int choice;

    while (1)
    {
        cin >> choice;
        switch (choice)
        {
            case 1:
                system ("cls");
                Item();
                item.database_reader();
                item.purchase();
                break;


            case 2:
                system ("cls");
                Item();
                item.database_reader();
                item.display_database();
                break;

            case 3:
                system ("cls");
                Item();
                item.database_reader();
                item.search_database();
                break;
        }
    }
}

Item::Item ()
{
    string item_id[100] ={};
    string item_name[100] ={};
    string item_price[100] ={};
    string item_stocks[100] ={};
}

void Item::register_item_to_database ()
{
    int num;
    cout << "How manu items do you wish to register in the database? \n -";
    cin >> num;

    string x[num][4];
    file.open("inventory.txt", ios::app | ios::out);

    for(int i = 0; i < num; i++)
    {
        cout << "Please Enter Item ID: ";
        cin >> x[i][0];
        file << x [i][0] << ",";

        cout << "Please Enter Item Name: ";
        cin.ignore();
        getline (cin, x[i][1]);
        file << x [i][1] << ",";

        cout << "Please Enter Item Price: ";
        cin >> x[i][2];
        file << x [i][2] << ",";

        cout << "Please Enter Item Stocks: ";
        cin >> x[i][3];
        file << x [i][3] << "\n";
    }

    file.close();
}

void Item::database_reader ()
{
    int num=0;

    file.open("inventory.txt", ios::in);
    while (file.good())
    {
        getline (file,item_id[num], ',');
        getline (file,item_name[num], ',');
        getline (file,item_price[num], ',');
        getline (file,item_stocks[num], '\n');
        num=num+1;
    }
    file.close();
}

int Item::populator ()
{
    int population;
    string temp;
    file.open("inventory.txt", ios::in);
    while (file.good())
    {
        getline (file,temp, '\n');
        population=population+1;
    }
    file.close();

    return population;
}

void Item::purchase ()
{

    int database_qnty = populator();

    string item_id_purchase;
    int quantity, total_price=0, num_pur =0;
    double price1;
    int temp[database_qnty] = {};

    cout << "Enter ID then Quantity of item to be purchased. When done, press 'x' or 'X'. \n\n";

    while (1)
    {
        cout << "ID: ";
        cin >> item_id_purchase;

        if (item_id_purchase == "x" || item_id_purchase == "X")
        {
            cout << "\nTotal Price: " << total_price << endl;
            cout << "Total Items purchased: " << num_pur << endl;
            database_updater(temp,database_qnty);
            break;
        }

        for (int j = 0; j<database_qnty; j++)
        {

            if (item_id_purchase == item_id[j])
            {
                cout <<"Item Name: "<< item_name[j] <<"\n";

                cout << "Qnty: ";
                cin >> quantity;

                price1 = stod(item_price[j]);
                total_price = total_price + (quantity * price1);
                num_pur = num_pur+ quantity;
                temp[j] = temp[j] + quantity;

                cout <<"Current Total: "<< total_price << endl <<endl;

                break;
            }

            else {
                if (j == database_qnty-1)
                {
                    cout << "Product does not exist in the database! Enter ID again.\n\n";
                    break;
                }
            }
        }
    }
}

void Item::database_updater(int updated_stocks[], int size)
{
    int database_stock =0;
    int temp[size];
    remove ("inventory.txt");

    for (int j = 0; j<(size-1); j++)
    {
        database_stock = stoi(item_stocks[j]);
        temp[j] = database_stock - updated_stocks[j];

        file.open("inventory.txt", ios::app | ios::out);
        file << item_id[j] << "," << item_name [j] << "," << item_price [j] << "," << temp[j] << "\n";
        file.close();
    }
}

void Item::display_database()
{
    int pop=populator();

    cout << setw(0) << "Item ID"
         << setw(20) << "Item Name"
         << setw(23) << "Item Price"
         << setw(27) << "Available Stocks" <<"\n\n";

    for (int j = 0; j<(pop-1); j++)
    {
        float price = stof(item_price[j]);

         cout << setw(0) << item_id[j]
              << setw(24) << item_name [j]
              << setw(15) <<"Php "
              << setw(8)<< fixed << setprecision(2) <<  price
              << setw(26) << item_stocks[j] <<"\n";
    }
}

void Item::search_database()
{
    string id_search;
    int database_qnty = populator();

    cout << "Enter Item ID you wish to see: ";
    cin >> id_search;

     for (int j = 0; j<database_qnty; j++)
    {

        if (id_search == item_id[j])
        {
            cout <<"Item ID: "<< item_id[j] <<"\n";
            cout <<"Item Name: "<< item_name[j] <<"\n";
            cout <<"Item Price: "<< item_price[j] <<"\n";
            cout <<"Item Stock: "<< item_stocks[j] <<"\n";
            break;
        }

        else {
            if (j == database_qnty-1)
            {
                cout << "Product does not exist in the database! \n\n";
                break;
            }
        }
    }

}


