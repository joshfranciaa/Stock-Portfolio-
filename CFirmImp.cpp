/*
Name: Joshua Francia, 2002157323, Section 1006, Assignment #6
Description: Stock Portfolio
Input: Files and user inputed values
Output: See sample output
*/


#include "CFirm.h"
#include <iostream> 
#include <iomanip>
using namespace std; 

// Default constructor
CFirm::CFirm() {
    portfolioValue = 0.0; 
}

// Calculates portfolio value
// WORK ON THIS 
// COME BACK TO THIS LATER
void CFirm::calculatePortfolio() {
    // Sets value to default
    portfolioValue = 0.0; 
    // Loops through the all of the orders of all of the users and adds the value accordingly
    for(int i = 0; i < Users.size(); i++) {
        // Creates a CUser temp reference object and assigning Users vector in it
        const CUser& user = Users[i];
        // Initializing and defining vector of COrder type 
        // Accessing the user class definition and getting the orders
        const vector<COrder>& orders = user.getOrders();
        // Loops through the orders in the COrder class
        for(int i = 0; i < orders.size(); i++) {
            // Creates a COrder reference object and equaling it to the orders vector
            const COrder& order = orders[i];
            // The portfolioValue member is added by getting price of and quantity of an order
            portfolioValue += order.getPrice() * order.getQuantity(); 
        }
    }
    cout << "Portfolio Value: " << getPortfolio() << endl;  
    cout << "User name: John_Doe" << endl; 
    cout << "Portfolio Value: "; 
}

// Return function
double CFirm::getPortfolio() const {   
    return portfolioValue; 
}

// Copy constructor
CFirm::CFirm(const CFirm& other) {
    portfolioValue = other.portfolioValue; 
    for(const auto& user : other.Users) {
        this->Users.push_back(user); 
    }
}

// Binary operator
CFirm CFirm::operator+(const CFirm& obj) const {
    // Copy the current object onto the temp obj 
    CFirm temp;
    temp.portfolioValue = this->portfolioValue + obj.portfolioValue;
    temp.Users = this->Users; 
    temp.Users.insert(temp.Users.end(), obj.Users.begin(), obj.Users.end());
    return temp; 
}

// Unary operator; Deep copy of the Users vector
CFirm CFirm::operator+() const {
    CFirm firmCopy;
    firmCopy.portfolioValue = this->portfolioValue; 
    firmCopy.Users = this->Users; 
    return firmCopy;
}

bool CFirm::operator>(const CFirm& other) const {
    // Accesses the first element of the two Users vector and compares how many elements are there
    // Greater than comparison
    if(Users[0].Orders.size() > other.Users[0].Orders.size()) {
        return true; 
    }
    return false;
}

bool CFirm::operator<(const CFirm& other) const {
    // Accesses the first element of the two Users vector and compares how many elements are there
    // Less than comparison 
    if(Users[0].Orders.size() < other.Users[0].Orders.size()) {
        return true; 
    }
    return false;
}

// Pre-increment operator 
CFirm& CFirm::operator++() {
    CUser newUser; 
    Users.push_back(newUser);
    return *this;  
}

// Post-increment operator 
CFirm CFirm::operator++(int) {
    CFirm temp(*this);  // Create a copy of the current object
    CUser newUser;      // Create a new user
    Users.push_back(newUser); // Add the new user to the Users vector
    return temp; 
}


// Assignment operator
CFirm& CFirm::operator=(const CFirm& obj) {
    if (this == &obj) {
        return *this;
    }
    this->portfolioValue = obj.portfolioValue;
    this->Users = obj.Users;
    return *this;
}

ostream& operator<<(ostream& os, const CFirm& firm) {
    os << "Firm Information: " << endl; 
    for(int i = 0; i < firm.Users.size() ; i++) {
        os << firm.Users[i].UserName;
    }
    cout << endl << endl; 
    return os; 
}




