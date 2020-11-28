#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Service {
public:
    Service();
    void SetServiceName(string inputName);
    void SetServiceSale(int inputSale, int month);
    string GetServiceName() const;
    int GetServiceSale(int month);
    void GetServiceInfo();
    void AddService(fstream& InputFile);
    void ModifyService(fstream& InputFile, char* textFile, int serviceNum);
private:
    string serviceName;
    vector<int> serviceSale = std::vector<int>(12);
};
#endif
#pragma once

