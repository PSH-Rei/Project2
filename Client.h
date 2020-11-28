#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Client {
public:
    Client();
    void SetClientName(string inputFirst, string inputLast);
    void SetClientAddress(string inputAddress);
    void SetClientSale(int inputSale, int month);
    string GetClientFirstName() const;
    string GetClientLastName() const;
    string GetClientAddress() const;
    int GetClientSale(int month);
    void GetClientInfo();
    void AddClient(fstream& InputFile);
    void ModifyClient(fstream& InputFile, char* textFile, int numClient);
private:
    string clientAddress = "none";
    string clientFirst = "none";
    string clientLast = "none";
    vector<int> clientSale = std::vector<int>(12);
};
#endif
#pragma once
