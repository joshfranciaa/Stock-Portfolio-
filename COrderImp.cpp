/*
Name: Joshua Francia, 2002157323, Section 1006, Assignment #6
Description: Stock Portfolio
Input: Files and user inputed values
Output: See sample output
*/

// HEADER FILES INCLUDED 
#include "COrder.h"
#include <iostream> 
#include <iomanip>
using namespace std; 

// Default constructor
COrder::COrder() {
    // Setting members to default values
    stockName = " "; // Default stock name
    Price = 0.0; // Default price
    sQuantity = 0; // Default stock quantity
    totalPrice = 0.0; // Default total price
    User = " "; // Default username
}

// Parameterized constructor 
COrder::COrder(const string& sName, double price, int quantity, const string& user) {
    // Parameters assigned to the class members
    stockName = sName; // parameter = class member
    Price = price; // parameter = class member
    sQuantity = quantity; // parameter = class member
    User = user; // parameter = class member
    // Initializing total price
    totalPrice = Price * sQuantity; 
}

// Accessor function
double COrder::getPrice() const {
    // Accesses price private member 
    return Price; 
}

// Accessor function
int COrder::getQuantity() const {
    // Accesses stock quantity private member
    return sQuantity; 
}

// Non-type returning function
void COrder::orderDisplay() {
    // Outputs to the console
    cout << "Stock Name: " << stockName << endl;
    cout << "Price: $ " << Price << endl; 
    cout << "Quantity: " << sQuantity << endl; 
    cout << "Total Price: $ " << totalPrice << endl;  
}

// Unary operator overloading 
COrder COrder::operator+() {
    // Local variables that will serve as parameters for constructor
    double newPrice = Price + (Price * .1); // Adding 10% to price
    int newQuantity = sQuantity + 10; // Increases number by 10 

    // Returns a new object
    return COrder(stockName, newPrice, newQuantity, User); 
}

// Overloading the insertion operator
istream& operator>>(istream& is, COrder& order) {
    // This is the format
    cout << "COrder extraction operator (stockName >> Price >> Quantity >> User)" << endl; 
    is >> order.stockName >> order.Price >> order.sQuantity >> order.User; 
    // Returns the istream variable
    return is; 
}

// Insertion operator overload
ostream& operator<<(ostream& os, COrder& order) {
    // This is the format
    os << "COrder insertion operator" << endl; 
    os << "User Name: " << order.User << endl; 
    os << "Stock Name: " << order.stockName << endl; 
    os << "Price: $ " << order.Price << endl; 
    os << "Quantity: " << order.sQuantity << endl; 
    os << "Total Price: $" << order.Price * order.sQuantity; 
    // Returns the ostream variable
    return os; 
}


