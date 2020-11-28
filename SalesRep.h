#ifndef SALE_REP_H
#define SALE_REP_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class SalesRep {
public:
    SalesRep();
    void SetRepName(string inputFirst, string inputLast);
    void SetRepAddress(string inputAddress);
    void SetRepSale(int inputSale, int month);
    string GetRepFirstName() const;
    string GetRepLastName() const;
    string GetRepAddress() const;
    int GetRepSale(int month);
    void GetRepInfo();
    void AddRep(fstream& InputFile);
    void ModifyRep(fstream& InputFile, char* textFile, int repNum);
private:
    string repFirst;
    string repLast;
    string repAddress;
    vector<int> repSale = std::vector<int>(12);
};
#endif
#pragma once

