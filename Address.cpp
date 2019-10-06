//
//  Address.cpp
//  GeographicIS
//
//  Created by Jackson Carlton on 2/25/19.
//  Copyright © 2019 Jackson Carlton. All rights reserved.
//

#include "Address.h"

//Constructors -> Destructor
Address::Address()
{
    latitude = 0.0;
    longitude = 0.0;
    houseNum = 0;
    streetName = "";
}
Address::Address(float lati, float longi, int hNum, string sName)
{
    latitude = lati;
    longitude = longi;
    houseNum = hNum;
    streetName = sName;
}
Address::Address(const Address& copy)
{
    latitude = copy.latitude;
    longitude = copy.longitude;
    houseNum = copy.houseNum;
    streetName = copy.streetName;
}
Address::~Address()
{
}

//Getters 'n Setters
float Address::getLatitude()
{
    return latitude;
}
float Address::getLongitude()
{
    return longitude;
}
int Address::getHouseNum()
{
    return houseNum;
}
string Address::getStreetName()
{
    return streetName;
}
void Address::setLatitude(float lati)
{
    latitude = lati;
}
void Address::setLongitude(float longi)
{
    longitude = longi;
}
void Address::setHouseNum(int hNum)
{
    houseNum = hNum;
}
void Address::setStreetName(string sName)
{
    streetName = sName;
}

//Print
void Address::print()
{
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "House Number: " << houseNum << endl;
    cout << "Street Name: " << streetName << endl;
}

