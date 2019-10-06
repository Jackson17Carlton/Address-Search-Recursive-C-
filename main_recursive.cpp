//
//  main.cpp
//  GeographicIS
//
//  Created by Jackson Carlton on 2/25/19.
//  Copyright © 2019 Jackson Carlton. All rights reserved.
//

#include <vector>
#include <fstream>
#include "Address.h"
bool binarySearch(long low, long high, string search_street, int search_num, vector<Address> archive)
{
    //Finding the middle value between high and low
    long mid = (low + high) / 2;
    
    //Variable for searching
    Address target;
    target = archive.at(mid);
    
    //Terminating Condition
    if (low > high)
    {
        cout << "This address is not in the archive" << endl;
        return false;
    }
    
    //Street name are the same
    else if (target.getStreetName() == search_street)
    {
        //FOUND ADDRESS
        if (target.getHouseNum() == search_num)
        {
            cout << "Found the address:" << endl;
            target.print();
            return true;
        }
        
        //Search left
        else if (target.getHouseNum() > search_num)
        {
            //Recursively call search with low = 0, high = mid - 1
            return binarySearch(low, mid - 1, search_street, search_num, archive);
        }
        
        //Search right
        else
        {
            //Recursively call search with low = mid + 1, high = archive.size()
            return binarySearch(mid + 1, high, search_street, search_num, archive);
        }
    }
    
    //Search Left
    else if (target.getStreetName() > search_street)
    {
        //Recursively call search with low = 0, high = mid - 1
        return binarySearch(low, mid - 1, search_street, search_num, archive);
    }
    
    //Search Right
    else
    {
        //Recursively call search with low = mid + 1, high = archive.size()
        return binarySearch(mid + 1, high, search_street, search_num, archive);
    }
    return true;
}

int main() {
    //Vector Variable Declaration
    vector<Address> archive;
    float lat = 0;
    float lon = 0;
    int num = 0; //house num
    string addr = ""; // street address
    char ch = ' '; // used to get rid of whitespace error
    
    //File Opening
    ifstream din; //used to handle data from file
    din.open("input1.txt");

    while (din >> lat >> lon >> num)
    {
        din.get(ch);
        getline(din, addr);
        Address position(lat, lon, num, addr);
        archive.push_back(position);
    }
    
    //User Interface
    string choice;
    cout << "Enter 'search' or 'exit' (case sensitive)" << endl;
    cin >> choice;
    while (choice != "exit")
    {
        if (choice == "search")
        {
            //Variables for searching conditions
            bool found = false;
            string search; //streetname
            int num; //house number
            
            cout << "Enter Street Name (case sensitive): ";
            cin.ignore();
            getline(cin, search);
            cout << "Enter a House Number: ";
            cin >> num;
            cout << "Searching...\n\n";
            found = binarySearch(0, archive.size(), search, num, archive);
            if (found == true)
            {
                cout << "\nSearch was successful" << endl;
            }
            else
            {
                cout << "\nSearch was unsuccessful" << endl;
            }
            
            cout << "\nEnter 'search' or 'exit' (case sensitive)" << endl;
            cin >> choice;
        }
        else
        {
            cout << "Enter a valid menu command: " << endl;
            cin >> choice;
        }
    }
    cout << "\nexitting..." << endl;
    return 0;
}
