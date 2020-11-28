using namespace std;

#include "Sales.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>

void Sales::AddSale(fstream& InputFile) {
	string str, str1, str2, str3, str4;
	int currSale;
	cout << "ADD NEW SALE" << endl;
	cout << "Enter sale's code: ";
	cin >> str;
	SetSaleCode(str);
	InputFile << str << " ";
	cout << "Enter service's name: ";
	cin >> str1;
	InputFile << str1 << " ";
	SetServiceName(str1);
	cout << "Enter client's first name: ";
	cin >> str2;
	InputFile << str2 << " ";
	cout << "Enter client's last name: ";
	cin >> str3;
	InputFile << str3 << " ";
	SetClientName(str2, str3);
	cout << "Enter client's address: ";
	cin >> str4;
	InputFile << str4 << endl;
	SetSaleAddress(str4);
	cout << endl;
	InputFile.close();
}
void Sales::SetSaleCode(string inputCode) {
	saleCode = inputCode;
}
void Sales::SetClientName(string inputFirst, string inputLast) {
	saleFirst = inputFirst;
	saleLast = inputLast;
}
void Sales::SetServiceName(string inputName) {
	serviceName = inputName;
}
string Sales::GetSaleLast() const {
	return saleLast;
}
void Sales::SetSaleAddress(string inputAddress) {
	saleAddress = inputAddress;
}
string Sales::GetSaleCode() const {
	return saleCode;
}
string Sales::GetSaleFirst() const {
	return saleFirst;
}
string Sales::GetSaleAddress() const {
	return saleAddress;
}
string Sales::GetService() const {
	return serviceName;
}
void Sales::ModifySale(fstream& InputFile, char* textFile, int saleNum) {
	string str1, str2, str3, str4, str5, str;
	int currSale, currNum = 0;
	char tempName[] = "TempSale.txt";
	ofstream TempFile{ "TempSale.txt" };
	while (getline(InputFile, str)) {
		if (currNum == saleNum) {
			cout << "Enter the new sale's code: ";
			cin >> str1;
			TempFile << str1 << " ";
			cout << "Enter the service's name: ";
			cin >> str2;
			TempFile << str2 << " ";
			cout << "Enter client's new first name: ";
			cin >> str3;
			TempFile << str3 << " ";
			cout << "Enter client's new last name: ";
			cin >> str4;
			TempFile << str4 << " ";
			SetClientName(str3, str4);
			cout << "Enter client's new address: ";
			cin >> str5;
			SetSaleAddress(str5);
			TempFile << str5 << endl;
			cout << endl;
			currNum++;
		}
		else
		{
			TempFile << str << endl;
			currNum++;
		}
	}
	InputFile.close();
	TempFile.close();
	remove(textFile);
	rename(tempName, textFile);
}