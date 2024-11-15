/*
Name: Joshua Francia, 2002157323, Section 1006, Assignment #6
Description: Stock Portfolio
Input: Files and user inputed values
Output: See sample output
*/

// All of the included libraries
#include "CUser.h"
#include <iostream>
// Using namespace std
using namespace std;

// Default constructor
CUser::CUser() {
    UserName = " "; // Default string assignment 
}

// Copy constructor 
CUser::CUser(const string& userName) {
    UserName = userName; 
}

// Accesses the Orders vector since it's private
const vector<COrder>& CUser::getOrders() const { 
    return Orders; 
}

// Adding an element to an Order vector 
void CUser::AddOrder(const COrder& order) {
    Orders.push_back(order);
}  