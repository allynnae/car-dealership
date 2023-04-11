/**
 *   @file: car-dealer.cc
 * @author: Allison McKee
 *   @date: 04-05-2023
 *  @brief: Bobcats Auto Dealership
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// functions
void carModel(double &price, char &model, string option);
void displayOptions(ifstream &inStream, double &price, char model, string &option);
void addOption(double &price, char model, string &option);
void removeOption(double &price, char model, string &option);
void cancelOrder(double &price, char model, string &option);

// main function
int main(int argc, char const *argv[])
{
    ifstream inStream;
    int choice;
    double price = 0;
    char model = ' ';
    string option = "";
    inStream.open("options.txt");
    if (inStream.fail())
    {
        cout << "Error: File did not open." << endl;
        exit(0);
    }
    cout << "NO MODEL SELECTED\n" << endl;
    do 
    {
        // initial menu
        cout << "1. Select a model (E, L, X)" << endl;
        cout << "2. Display available options and prices" << endl;
        cout << "3. Add an option" << endl;
        cout << "4. Remove an option" << endl;
        cout << "5. Cancel order" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // call functions
        if (choice == 1)
        {
            carModel(price, model, option);
        }
        else if (choice == 2)
        {
            displayOptions(inStream, price, model, option);
        }
        else if (choice == 3)
        {
            addOption(price, model, option);
        }
        else if (choice == 4)
        {
            removeOption(price, model, option);
        }
        else if (choice == 5)
        {
            cancelOrder(price, model, option);
        }
        else if (choice == 6)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice >= 1 && choice <= 5);

    inStream.close();
    return 0;
}

// Select a model function
void carModel(double &price, char &model, string option)
{
    bool validInput = false;
    do
    {
        cout << "Enter the model (E, L, X): ";
        cin >> model;
        model = toupper(model);
        if (model != 'E' && model != 'L' && model != 'X')
        {
            cout << "Invalid model. Please enter E, L, or X." << endl;
        }
        else
        {
            validInput = true;
        }
    } 
    while (!validInput);

    cout << fixed << setprecision(2);

    if (model == 'E')
    {
        price = 10000.00;
    }
    if (model == 'L')
    {
        price = 12000.00;
    }
    if (model == 'X')
    {
        price = 18000.00;
    }

    cout << "\nModel: " << model << ", $" << price << ", Options: " << option << endl << endl;
}

// display available options and prices function
void displayOptions(ifstream &inStream, double &price, char model, string &option)
{
    cout << "\nPrices for model E, L, & X: $1000.00, $12000.00, $18000.00" << endl;
    cout << "Available Options\n" << endl;
    cout << "------------------" << endl;
    string line;
    int option_price;
    string car_option;
    bool modelSelected = false; 

    // read the file line by line
    while (getline(inStream, line)) 
    {
        // find option price
        istringstream iss(line);
        iss >> option_price;
        
        // find option name
        getline(iss, car_option);
        
        car_option.erase(0, car_option.find_first_not_of(" \t"));
        
        // print results
        cout << car_option << endl;
        cout << "($" << option_price << ")" << endl;
        cout << "------------------" << endl;
    }
    if (model != ' ') // check if model is not empty
    {
        cout << "\nModel: " << model << ", $" << price << ", Options: " << option << endl;
        modelSelected = true;
    }

    if (!modelSelected) // if model is not selected, display "NO MODEL SELECTED"
    {
        cout << "\nNO MODEL SELECTED" << endl;
    }
    cout << endl;
}


// add an option function
void addOption(double &price, char model, string &option)
{
    bool optionAdded = false;
    if (model != 'E' && model != 'L' && model != 'X')
    {
        cout << "\nNo model selected, select a model first to add options.\n" << endl;
        return;
    }
    cout << "Enter option: ";
    cin.ignore(); // ignore any remaining characters in input stream
    getline(cin, option); // read complete line
    for (size_t i = 0; i < option.length(); ++i)
    {
        option[i] = tolower(option[i]);
    }
    if (option == "leather seats")
    {
        price += 5000;
        optionAdded = true;
    }
    else if (option == "dvd system")
    {
        price += 1000;
        optionAdded = true;
    }
    else if (option == "10 speakers")
    {
        price += 800;
        optionAdded = true;
    }
    else if (option == "navigation system")
    {
        price += 1400;
        optionAdded = true;
    }
    else if (option == "carplay")
    {
        price += 500;
        optionAdded = true;
    }
    else if (option == "android auto")
    {
        price += 500;
        optionAdded = true;
    }
    else if (option == "lane monitoring")
    {
        price += 2000;
        optionAdded = true;
    }
    else if (option == "3/36 warranty")
    {
        price += 800;
        optionAdded = true;
    }
    else if (option == "6/72 warranty")
    {
        price += 999;
        optionAdded = true;
    }
    else if (option == "dual climate")
    {
        price += 1500;
        optionAdded = true;
    }
    else if (option == "body side molding")
    {
        price += 225;
        optionAdded = true;
    }
    else if (option == "cargo net")
    {
        price += 49;
        optionAdded = true;
    }
    else if (option == "cargo organizer")
    {
        price += 87;
        optionAdded = true;
    }
    else if (option == "450w audio")
    {
        price += 700;
        optionAdded = true;
    }
    else if (option == "heated seats")
    {
        price += 1000;
        optionAdded = true;
    }
    if (optionAdded)
    {
        cout << "\nModel: " << model << ", $" << price << ", Options: " << option << endl << endl;
    }
    else
    {
        cout << "\nInvalid option. Enter 'cancel' to go back and try again: ";
        option.clear();
        getline(cin, option);
        if (option == "cancel")
        {
            option.clear();
            cout << "\nModel: " << model << ", $" << price << ", Options: " << option << endl << endl;
            return;
        }
    }
}

// remove an option function
void removeOption(double &price, char model, string &option)
{
    if (model != 'E' && model != 'L' && model != 'X')
    {
        cout << "\nNo model selected, select a model first to remove options.\n" << endl;
        return;
    }
    string previousOption = option;
    cout << "Enter option to remove: ";
    cin.ignore(); // ignore any remaining characters in input stream
    getline(cin, option); // read complete line
    for (size_t i = 0; i < option.length(); ++i)
    {
        option[i] = tolower(option[i]);
    }
    bool optionRemoved = false;
    if (option == "leather seats")
    {
        price -= 5000;
        optionRemoved = true;
    }
    else if (option == "dvd system")
    {
        price -= 1000;
        optionRemoved = true;
    }
    else if (option == "10 speakers")
    {
        price -= 800;
        optionRemoved = true;
    }
    else if (option == "navigation system")
    {
        price -= 1400;
        optionRemoved = true;
    }
    else if (option == "carplay")
    {
        price -= 500;
        optionRemoved = true;
    }
    else if (option == "android auto")
    {
        price -= 500;
        optionRemoved = true;
    }
    else if (option == "lane monitoring")
    {
        price -= 2000;
        optionRemoved = true;
    }
    else if (option == "3/36 warranty")
    {
        price -= 800;
        optionRemoved = true;
    }
    else if (option == "6/72 warranty")
    {
        price -= 999;
        optionRemoved = true;
    }
    else if (option == "dual climate")
    {
        price -= 1500;
        optionRemoved = true;
    }
    else if (option == "body side molding")
    {
        price -= 225;
        optionRemoved = true;
    }
    else if (option == "cargo net")
    {
        price -= 49;
        optionRemoved = true;
    }
    else if (option == "cargo organizer")
    {
        price -= 87;
        optionRemoved = true;
    }
    else if (option == "450w audio")
    {
        price -= 700;
        optionRemoved = true;
    }
    else if (option == "heated seats")
    {
        price -= 1000;
        optionRemoved = true;
    }
    if (optionRemoved)
    {
        cout << "\nModel: " << model << ", $" << price << ", Options: " << option << endl << endl;
    }
    else
    {
        cout << "\nInvalid option. Please try again." << endl;
        cout << "\nModel: " << model << ", $" << price << ", Options: " << previousOption << endl << endl;
    }
}

// cancel order function
void cancelOrder(double &price, char model, string &option)
{
    price = 0;
    model = '\0';
    option = "";
    cout << "\nNO MODEL SELECTED\n" << endl;
}