//
//  Header.h
//  GeographicIS
//
//  Created by Jackson Carlton on 2/25/19.
//  Copyright © 2019 Jackson Carlton. All rights reserved.
//

#ifndef Address_h
#define Address_h

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Address
{
public:
    Address(); //Default Constructor
    Address(float lati, float longi, int hNum, string sName); //Non-Default Constructor
    Address(const Address& copy); //Copy Constructor
    ~Address(); //Destructor
    
    //Get/Set Methods
    float getLatitude();
    float getLongitude();
    int getHouseNum();
    string getStreetName();
    void setLatitude(float lati);
    void setLongitude(float longi);
    void setHouseNum(int hNum);
    void setStreetName(string sName);
    
    //Print method
    void print();
    
private:
    float latitude;
    float longitude;
    int houseNum;
    string streetName;
};

#endif /* Address_h */
