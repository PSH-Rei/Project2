using namespace std;

#include "Client.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>

Client::Client() {
	clientSale.resize(12);
	clientFirst = "none";
	clientLast = "none";
	clientAddress = "none";
	for (int i = 0; i < 12; i++) {
		clientSale.at(i) = 0;
	}
}
void Client::SetClientName(string inputFirst, string inputLast) {
	clientFirst = inputFirst;
	clientLast = inputLast;
}
void Client::SetClientAddress(string inputAddress) {
	clientAddress = inputAddress;
}
void Client::SetClientSale(int inputSale, int month) {
	clientSale.at(month) = inputSale;
}
string Client::GetClientFirstName() const{
	return clientFirst;
}
string Client::GetClientLastName() const{
	return clientLast;
}
string Client::GetClientAddress() const{
	return clientAddress;
}
int Client::GetClientSale(int month) {
	return clientSale.at(month);
}
void Client::GetClientInfo() {
	cout << "Client's Name: " << GetClientFirstName() << " " << GetClientLastName() << endl;
	cout << "Client's Address: " << GetClientAddress() << endl;
	cout << "Client's Sale History for each month: " << endl;
	for (int i = 0; i < 12; i++) {
		string monthName[] = { "January", "February", "March", "April", "May", "June", "July", "August", "Semptember", "October", "November", "Demcember" };
		cout << monthName[i] << ": " << GetClientSale(i) << endl;
	}
}
void Client::AddClient(fstream& InputFile) {
	string str1, str2, str3;
	int currSale;
	cout << "ADD NEW CLIENT" << endl;
	cout << "Enter client's first name: ";
	cin >> str1;
	InputFile << str1 << " ";
	cout << "Enter client's last name: ";
	cin >> str2;
	InputFile << str2 << " ";
	SetClientName(str1, str2);
	cout << "Enter client's address: ";
	cin >> str3;
	InputFile << str3 << " ";
	SetClientAddress(str3);
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
		SetClientSale(currSale, i);
	}
	cout << endl;
	InputFile.close();
}
void Client::ModifyClient(fstream& InputFile, char* textFile, int clientNum) {
	string str1, str2, str3, str;
	int currSale, currNum=0;
	char tempName[] = "TempClient.txt";
	ofstream TempFile { "TempClient.txt" };
	while (getline(InputFile, str)) {
		if (currNum == clientNum) {
			cout << "Enter client's new first name: ";
			cin >> str1;
			TempFile << str1 << " ";
			cout << "Enter client's new last name: ";
			cin >> str2;
			TempFile << str2 << " ";
			SetClientName(str1, str2);
			cout << "Enter client's new address: ";
			cin >> str3;
			TempFile << str3 << " ";
			SetClientAddress(str3);
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
				SetClientSale(currSale, i);
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