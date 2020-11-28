#include "Sales.h"
#include "SalesRep.h"
#include "Service.h"
#include "Client.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int countNum(fstream& InputFile, string& str) {
    int i = 0;
    while (getline(InputFile, str)) {
        i++;
    }
    return i;
}
char PrintMenu() {
    char c;
    cout << "MENU:" << endl;
    cout << "w: list all client." << endl;
    cout << "e: list info of specific client." << endl;
    cout << "r: add new client." << endl;
    cout << "t: update client info." << endl;
    cout << "y: list all representatives sale." << endl;
    cout << "u: list info of specific representative sale." << endl;
    cout << "i: add new representative sale." << endl;
    cout << "o: update representative info." << endl;
    cout << "p: list all servive." << endl;
    cout << "a: list info of specific service." << endl;
    cout << "s: add new service." << endl;
    cout << "d: update service info." << endl;
    cout << "f: purchase a service(add new sale)." << endl;
    cout << "g: list all sale for the year." << endl;
    cout << "h: list all sale for a specific client." << endl;
    cout << "j: update a specific sale." << endl;
    cout << "q: quit." << endl << endl;
    cout << "Choice your option: ";
    cin >> c;
    char arr[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j' };
    for (int i = 0; i < 18; i++) {
        if (c == arr[i]) {
            cout << endl;
            return c;
        }
    }
    PrintMenu();
}
int main() {
    string clientFile, repFile, serviceFile, saleFile, str;
    vector<Client> clientList;
    vector<SalesRep> repList;
    vector<Service> serviceList;
    vector<Sales> saleList;
    int numClient = 0, numRep = 0, numService = 0, numSale = 0;
    char c;
    
    cout << "Input client's info file: ";
    cin >> clientFile;
    clientFile = clientFile + ".txt";
    fstream ClientInfo(clientFile, std::fstream::in | std::fstream::out | std::fstream::app);
    numClient = countNum(ClientInfo, str);
    
    ClientInfo.close();
    clientList.resize(numClient);
    ClientInfo.open(clientFile);
    
    if (ClientInfo.is_open())  //check if it the file can open or not.
    {
        for (int i = 0; i < numClient; i++) {
            string firstName, lastName, address;
            int num;
            ClientInfo >> firstName;
            ClientInfo >> lastName;
            ClientInfo >> address;
            clientList.at(i).SetClientName(firstName, lastName);
            clientList.at(i).SetClientAddress(address);
            for (int j = 0; j < 12; j++) {
                ClientInfo >> num;
                clientList.at(i).SetClientSale(num, j);
            }
            
        }
        ClientInfo.close();
    }
    else cout << "Cannot open the file" << endl;
    

    cout << "Input Representatives Sale's info file: ";
    cin >> repFile;
    repFile = repFile + ".txt";
    fstream RepInfo(repFile, std::fstream::in | std::fstream::out | std::fstream::app);
    numRep = countNum(RepInfo, str);

    RepInfo.close();
    repList.resize(numRep);
    RepInfo.open(repFile);

    if (RepInfo.is_open()) {
        for (int i = 0; i < numRep; i++) {
            string firstName, lastName, address;
            int num;
            RepInfo >> firstName;
            RepInfo >> lastName;
            RepInfo >> address;
            repList.at(i).SetRepName(firstName, lastName);
            repList.at(i).SetRepAddress(address);
            for (int j = 0; j < 12; j++) {
                RepInfo >> num;
                repList.at(i).SetRepSale(num, j);
            }
        }
        RepInfo.close();
    }
    else cout << "Cannot open the file." << endl;

    cout << "Input Service's info file: ";
    cin >> serviceFile;
    serviceFile = serviceFile + ".txt";
    fstream ServiceInfo(serviceFile, std::fstream::in | std::fstream::out | std::fstream::app);
    numService = countNum(ServiceInfo, str);

    ServiceInfo.close();
    serviceList.resize(numService);
    ServiceInfo.open(serviceFile);

    if (ServiceInfo.is_open()) {
        for (int i = 0; i < serviceList.size(); i++) {
            string name;
            int num;
            ServiceInfo >> name;
            serviceList.at(i).SetServiceName(name);
            for (int j = 0; j < 12; j++) {
                ServiceInfo >> num;
                serviceList.at(i).SetServiceSale(num, j);
            }
        }
        ServiceInfo.close();
    }
    else cout << "Cannot open the file." << endl;

    cout << "Input Sale's info file: ";
    cin >> saleFile;
    saleFile = saleFile + ".txt";
    fstream SaleInfo(saleFile, std::fstream::in | std::fstream::out | std::fstream::app);
    numSale = countNum(SaleInfo, str);

    SaleInfo.close();
    saleList.resize(numSale);
    SaleInfo.open(saleFile);

    if (SaleInfo.is_open()) {
        for (int i = 0; i < saleList.size(); i++) {
            string code, serviceName, firstName, lastName, address;
            SaleInfo >> code;
            SaleInfo >> serviceName;
            SaleInfo >> firstName;
            SaleInfo >> lastName;
            SaleInfo >> address;
            saleList.at(i).SetSaleCode(code);
            saleList.at(i).SetServiceName(serviceName);
            saleList.at(i).SetClientName(firstName, lastName);
            saleList.at(i).SetSaleAddress(address);
        }
        SaleInfo.close();
    }
    else cout << "Cannot open the file." << endl;

    c = PrintMenu();
    while (c != 'q') {
        switch (c) {
        case 'w':
        {
            cout << "LIST ALL CLIENT" << endl;
            for (int i = 0; i < clientList.size(); i++) {
                cout << "Client number " << i + 1 << ": " << clientList.at(i).GetClientFirstName() << " " << clientList.at(i).GetClientLastName() << endl;
            }
            break;
        }
        case 'e':
        {
            bool isFound = false;
            cout << "LIST INFO OF SPECIFIC CLIENT" << endl;
            cout << "Enter the client first name: ";
            string firstName, lastName;
            cin >> firstName;
            cout << "Enter the client last name: ";
            cin >> lastName;
            for (int i = 0; i < clientList.size(); i++) {
                if (firstName == clientList.at(i).GetClientFirstName() && lastName == clientList.at(i).GetClientLastName()) {
                    clientList.at(i).GetClientInfo();
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the client name." << endl;
            }
            break;
        }
        case 'r':
        {
            Client newClient;
            fstream AddClient(clientFile, std::fstream::in | std::fstream::out | std::fstream::app);
            newClient.AddClient(AddClient);
            break;
        }
        case 't':
        {
            cout << "UPDATE CLIENT INFO" << endl;
            cout << "Enter the client first name: ";
            string firstName, lastName;
            bool isFound = false;
            cin >> firstName;
            cout << "Enter the client last name: ";
            cin >> lastName;
            for (int i = 0; i < clientList.size(); i++) {
                if (firstName == clientList.at(i).GetClientFirstName() && lastName == clientList.at(i).GetClientLastName()) {
                    char* clientText = &clientFile[0];
                    ClientInfo.open(clientFile);
                    clientList.at(i).ModifyClient(ClientInfo, clientText, i);
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the client name." << endl;
            }
            break;
        }
        case 'y':
        {
            cout << "LIST ALL REPRESENTATIVES SALE" << endl;
            for (int i = 0; i < repList.size(); i++) {
                cout << "Representatives sale number " << i + 1 << ": " << repList.at(i).GetRepFirstName() << " " << repList.at(i).GetRepLastName() << endl;
            }
            break;
        }
        case 'u':
        {
            bool isFound = false;
            cout << "LIST INFO OF SPECIFIC REPRESENTATIVES SALE" << endl;
            cout << "Enter the first name: ";
            string firstName, lastName;
            cin >> firstName;
            cout << "Enter the last name: ";
            cin >> lastName;
            for (int i = 0; i < repList.size(); i++) {
                if (firstName == repList.at(i).GetRepFirstName() && lastName == repList.at(i).GetRepLastName()) {
                    repList.at(i).GetRepInfo();
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the representatives sale name." << endl;
            }
            break;
        }
        case 'i':
        {
            SalesRep newRep;
            fstream AddRep(repFile, std::fstream::in | std::fstream::out | std::fstream::app);
            newRep.AddRep(AddRep);
            break;
        }
        case 'o':
        {
            cout << "UPDATE REPRESENTATIVES SALE INFO" << endl;
            cout << "Enter the first name: ";
            string firstName, lastName;
            bool isFound = false;
            cin >> firstName;
            cout << "Enter the last name: ";
            cin >> lastName;
            for (int i = 0; i < repList.size(); i++) {
                if (firstName == repList.at(i).GetRepFirstName() && lastName == repList.at(i).GetRepLastName()) {
                    char* repText = &repFile[0];
                    RepInfo.open(repFile);
                    repList.at(i).ModifyRep(RepInfo, repText, i);
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the client name." << endl;
            }
            break;
        }
        case 'p':
        {
            cout << "LIST ALL SERVICE" << endl;
            for (int i = 0; i < serviceList.size(); i++) {
                cout << "Service number " << i + 1 << ": " << serviceList.at(i).GetServiceName() << endl;
            }
            break;
        }
        case 'a':
        {
            bool isFound = false;
            cout << "LIST INFO OF SPECIFIC SERVICE" << endl;
            cout << "Enter the service name: ";
            string name;
            cin >> name;
            for (int i = 0; i < serviceList.size(); i++) {
                if (name == serviceList.at(i).GetServiceName()) {
                    serviceList.at(i).GetServiceInfo();
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the client name." << endl;
            }
            break;
        }
        case 's':
        {
            Service newService;
            fstream AddService(serviceFile, std::fstream::in | std::fstream::out | std::fstream::app);
            newService.AddService(AddService);
            break;
        }
        case 'd':
        {
            cout << "UPDATE SERVICE INFO" << endl;
            cout << "Enter the service name: ";
            string nameSer;
            bool isFound = false;
            cin >> nameSer;
            for (int i = 0; i < serviceList.size(); i++) {
                if (nameSer == serviceList.at(i).GetServiceName()) {
                    char* serviceText = &serviceFile[0];
                    ServiceInfo.open(serviceFile);
                    serviceList.at(i).ModifyService(ServiceInfo, serviceText, i);
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the client name." << endl;
            }
            break;
        }
        case 'f':
        {
            Sales newSale;
            fstream AddSale(saleFile, std::fstream::in | std::fstream::out | std::fstream::app);
            newSale.AddSale(AddSale);
            break;
        }
        case 'g':
        {
            cout << "LIST ALL SALE" << endl;
            for (int i = 0; i < saleList.size(); i++) {
                cout << "Sale number " << i + 1 << ": " << saleList.at(i).GetSaleCode() << " " << saleList.at(i).GetService() << endl;
            }
            break;
        }
        case 'h':
        {
            bool isFound = false;
            cout << "LIST ALL SALE OF SPECIFIC CLIENT" << endl;
            cout << "Enter the client first name: ";
            string firstName, lastName;
            int num = 1;
            cin >> firstName;
            cout << "Enter the client last name: ";
            cin >> lastName;
            for (int i = 0; i < saleList.size(); i++) {
                if (firstName == saleList.at(i).GetSaleFirst() && lastName == saleList.at(i).GetSaleLast()) {
                    cout << "Sale number " << num << ": " << saleList.at(i).GetSaleCode() << " " << saleList.at(i).GetService() << " " << saleList.at(i).GetSaleFirst() << " " << saleList.at(i).GetSaleLast() << " " << saleList.at(i).GetSaleAddress() << endl;
                    isFound = true;
                    num++;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the client name." << endl;
            }
            break;
        }
        case 'j':
        {
            cout << "UPDATE SPECIFIC SALE" << endl;
            cout << "Enter the sale's code: ";
            string code;
            bool isFound = false;
            cin >> code;
            for (int i = 0; i < saleList.size(); i++) {
                if (code == saleList.at(i).GetSaleCode()) {
                    char* saleText = &saleFile[0];
                    SaleInfo.open(saleFile);
                    saleList.at(i).ModifySale(SaleInfo, saleText, i);
                    isFound = true;
                    break;
                }
            }
            if (isFound == false) {
                cout << "Cannot find the sale's code." << endl;
            }
            break;
        }
        default:
            cout << "Invalid grade" << endl;
        }
        cout << endl;
        c = PrintMenu();
    }

    return 0;
}

   