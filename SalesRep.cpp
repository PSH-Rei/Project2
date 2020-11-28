using namespace std;

#include "SalesRep.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>

SalesRep::SalesRep() {
	repSale.resize(12);
	repFirst = "none";
	repLast = "none";
	repAddress = "none";
	for (int i = 0; i < 12; i++) {
		repSale.at(i) = 0;
	}
}
void SalesRep::SetRepName(string inputFirst, string inputLast) {
	repFirst = inputFirst;
	repLast = inputLast;
}
void SalesRep::SetRepAddress(string inputAddress) {
	repAddress = inputAddress;
}
void SalesRep::SetRepSale(int inputSale, int month) {
	repSale.at(month) = inputSale;
}
string SalesRep::GetRepFirstName() const {
	return repFirst;
}
string SalesRep::GetRepLastName() const {
	return repLast;
}
string SalesRep::GetRepAddress() const {
	return repAddress;
}
int SalesRep::GetRepSale(int month) {
	return repSale.at(month);
}
void SalesRep::GetRepInfo() {
	cout << "Sales Representatives's Name: " << GetRepFirstName() << " " << GetRepLastName() << endl;
	cout << "Sales Representatives's Address: " << GetRepAddress() << endl;
	cout << "Sales Representatives's Sale History for each month: " << endl;
	for (int i = 0; i < 12; i++) {
		string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Semptember", "October", "November", "Demcember" };
		cout << monthName[i] << ": " << GetRepSale(i) << endl;
	}
}
void SalesRep::AddRep(fstream& InputFile) {
	string str1, str2, str3;
	int currSale;
	cout << "ADD NEW REPRESENTATIVES SALE" << endl;
	cout << "Enter first name: ";
	cin >> str1;
	InputFile << str1 << " ";
	cout << "Enter client last name: ";
	cin >> str2;
	InputFile << str2 << " ";
	SetRepName(str1, str2);
	cout << "Enter client's address: ";
	cin >> str3;
	InputFile << str3 << " ";
	SetRepAddress(str3);
	cout << "Enter client's sale for each month:" << endl;
	for (int i = 0; i < 12; i++) {
		string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Semptember", "October", "November", "Demcember" };
		cout << monthName[i] << ": ";
		cin >> currSale;
		if (i != 11) {
			InputFile << currSale << " ";
		}
		else
		{
			InputFile << currSale << endl;
		}
		SetRepSale(currSale, i);
	}
	cout << endl;
	InputFile.close();
}
void SalesRep::ModifyRep(fstream& InputFile, char* textFile, int repNum) {
	string str1, str2, str3, str;
	int currSale, currNum = 0;
	char tempName[] = "TempRep.txt";
	ofstream TempFile{ "TempRep.txt" };
	while (getline(InputFile, str)) {
		if (currNum == repNum) {
			cout << "Enter client's new first name: ";
			cin >> str1;
			TempFile << str1 << " ";
			cout << "Enter client's new last name: ";
			cin >> str2;
			TempFile << str2 << " ";
			SetRepName(str1, str2);
			cout << "Enter client's new address: ";
			cin >> str3;
			TempFile << str3 << " ";
			SetRepAddress(str3);
			cout << "Enter client's new history sale for each month:" << endl;
			for (int i = 0; i < 12; i++) {
				string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Semptember", "October", "November", "Demcember" };
				cout << monthName[i] << ": ";
				cin >> currSale;
				if (i != 11) {
					TempFile << currSale << " ";
				}
				else
				{
					TempFile << currSale << endl;
				}
				SetRepSale(currSale, i);
			}
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