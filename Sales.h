#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Sales {
public:
    void AddSale(fstream& InputFile);
    void SetServiceName(string inputName);
    void SetClientName(string inputFirst, string inputLast);
    void SetSaleAddress(string inputAddress);
    void SetSaleCode(string inputCode);
    string GetSaleFirst() const;
    string GetSaleLast() const;
    string GetSaleAddress() const;
    string GetSaleCode () const;
    string GetService() const;
    void ModifySale(fstream& InputFile, char* textFile, int numSale);
private:
    string serviceName;
    string saleFirst;
    string saleLast;
    string saleAddress;
    string saleCode;
};
#endif
#pragma once
