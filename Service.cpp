using namespace std;

#include "Service.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>

Service::Service() {
	serviceSale.resize(12);
	serviceName = "none";
	for (int i = 0; i < 12; i++) {
		serviceSale.at(i) = 0;
	}
}
void Service::SetServiceName(string inputName) {
	serviceName = inputName;
}
void Service::SetServiceSale(int inputSale, int month) {
	serviceSale.at(month) = inputSale;
}
string Service::GetServiceName() const {
	return serviceName;
}
int Service::GetServiceSale(int month) {
	return serviceSale.at(month);
}
void Service::GetServiceInfo() {
	cout << "Service's Name: " << GetServiceName() << endl;
	cout << "Service's Sale History for each month: " << endl;
	for (int i = 0; i < 12; i++) {
		string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Semptember", "October", "November", "Demcember" };
		cout << monthName[i] << ": " << GetServiceSale(i) << endl;
	}
	cout << endl;
}
void Service::AddService(fstream& InputFile) {
	string str1;
	int currSale;
	cout << "ADD NEW SERVICE" << endl;
	cout << "Enter service's name: ";
	cin >> str1;
	InputFile << str1 << " ";
	SetServiceName(str1);
	cout << "Enter service's sale history for each month:" << endl;
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
		SetServiceSale(currSale, i);
	}
	cout << endl;
	InputFile.close();
}
void Service::ModifyService(fstream& InputFile, char* textFile, int serviceNum) {
	
	string str1, str;
	int currSale, currNum = 0;
	char tempName[] = "TempService.txt";
	ofstream TempFile { "TempService.txt" };
	while (getline(InputFile, str)) {
		if (currNum == serviceNum) {
			cout << "Enter service's new name: ";
			cin >> str1;
			TempFile << str1 << " ";
			SetServiceName(str1);
			cout << "Enter service's new history sale for each month:" << endl;
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
				SetServiceSale(currSale, i);
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