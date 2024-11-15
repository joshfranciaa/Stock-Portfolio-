/*
Name: Joshua Francia, 2002157323, Section 1006, Assignment #6
Description: Stock Portfolio
Input: Files and user inputed values
Output: See sample output
*/

// HEADER FILES INCLUDED
#include "CFile.h"
#include <iostream> 
#include "CUser.h"
#include "COrder.h"
#include <fstream>
using namespace std; 

// Writes firm data into a file
void CFile::WriteToFirmFile(const CFirm& firm, const string& fileName) {
    // Output stream
    ofstream oFile;
    // Opens file that is in the parameter
    oFile.open(fileName);

    // Iterates through every User, iterating through their Orders before moving to the next User
    for(int i = 0; i < firm.Users.size(); i++) {
        // Name of each user
        oFile << "User: " << firm.Users[i].UserName << " Order details" << endl;
        // Sets the portfolio value at zero before iterating through orders
        double userPortfolioValue = 0.0;
        // Iterating through orders of the specific User
        for(int j = 0; j < firm.Users[i].Orders.size(); j++) {
            // So you don't have to type a long code to represent each Orders class member
            const COrder& order = firm.Users[i].Orders[j]; 
            oFile << "   Stock Name: " << order.stockName // Name of stock
            << ", Price: " << order.getPrice() // Stock Price
            << ", Stock Quantity: " << order.getQuantity() // Stock Quantity
            << ", Total Price: " << order.totalPrice // Total Price of Stocks
            << ", User: " << order.User << endl; // User name
            userPortfolioValue += order.totalPrice;
        }
        oFile << "Portifolio Value: " << userPortfolioValue << "\n\n"; // Portfolio Value
    }
    // Close file when done using it 
    oFile.close(); 
}

// Reads the output file, parses it, and outputs it to console
void CFile::ReadAndDisplayFirmFile(const string& fileName) {
    // Input file stream
    ifstream iFile;
    // Opens the output file passed as parameter
    iFile.open(fileName);

    // Reads each line and outputs it into the console
    string line; 
    while(getline(iFile, line)) {
        cout << line << endl;
    }

    // Close file when done using it 
    iFile.close(); 
}

