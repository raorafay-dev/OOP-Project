#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// class Information
class Information
{
    // private:
    string Name;
    string Address;
    string ContactNo;

public:
    // setters
    void setName(string);
    void setAdress(string);
    void setContactNo(string);

    // getters
    string getName();
    string getAdress();
    string getContactNo();
};
// functions of Information
// setters
void Information ::setName(string name)
{
    Name = name;
}
void Information ::setAdress(string address)
{
    Address = address;
}
void Information ::setContactNo(string contact)
{
    ContactNo = contact;
}
// getters
string Information ::getName()
{
    return Name;
}
string Information ::getAdress()
{
    return Address;
}
string Information ::getContactNo()
{
    return ContactNo;
}

// class PostalWorker
class PostalWorker
{
protected:
    int IdOfPostalWorker;
    string Username;
    int Password;
    Information InfoOfPostalWorker; // Association
    bool Postman;
    bool Clerk;
    bool AccountOfficer;

public:
    // default constructor
    PostalWorker();
    // setters
    void setIdOfPotalWorker(int);
    void setUsername(string);
    void setPassword(int);
    void setInfoOfPostalWorker(Information);
    void setasPostman();
    void setasClerk();
    void setasAccountOfficer();

    // getters
    int getIdOfPostalWorker();
    string getUsername();
    int getPassword();
    Information getInfoOfPostalWorker();
    bool checkPostman();
    bool checkClerk();
    bool checkAccountOfficer();

    // functions
    void showDetails();
    void setRecord();
    bool check(string, int);
    void addRecord();
};
// functions of PostalWorker
// default constructor
PostalWorker ::PostalWorker()
{
    IdOfPostalWorker = rand() % 10000;
}
// setters
void PostalWorker ::setIdOfPotalWorker(int id)
{
    IdOfPostalWorker = id;
}
void PostalWorker ::setInfoOfPostalWorker(Information info)
{
    InfoOfPostalWorker = info;
}
void PostalWorker ::setasPostman()
{
    Postman = true;
}
void PostalWorker ::setasClerk()
{
    Clerk = true;
}
void PostalWorker ::setasAccountOfficer()
{
    AccountOfficer = true;
}
void PostalWorker::setUsername(string uname)
{
    Username = uname;
}
void PostalWorker ::setPassword(int pass)
{
    Password = pass;
}
// getters
int PostalWorker ::getIdOfPostalWorker()
{
    return IdOfPostalWorker;
}

Information PostalWorker ::getInfoOfPostalWorker()
{
    return InfoOfPostalWorker;
}
bool PostalWorker ::checkPostman()
{
    return Postman;
}
bool PostalWorker ::checkClerk()
{
    return Clerk;
}
bool PostalWorker ::checkAccountOfficer()
{
    return AccountOfficer;
}
string PostalWorker ::getUsername()
{
    return Username;
}
int PostalWorker ::getPassword()
{
    return Password;
}
// functions
void PostalWorker ::showDetails()
{
    cout << "Details of Postal Worker:" << endl;
    cout << "Designation: Postman" << endl;
    cout << "ID: " << getIdOfPostalWorker() << endl;
    cout << "Name: " << getInfoOfPostalWorker().getName() << endl;
    cout << "Contact No: " << getInfoOfPostalWorker().getContactNo() << endl;
    cout << "Address: " << getInfoOfPostalWorker().getAdress() << endl;
}
// functions
void PostalWorker ::setRecord()
{
    ifstream fin;
    fin.open("EmployeesSignupRecord.txt");

    // making record
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("EmployeesSignupRecord.txt", ios ::app);

        fout << endl;
        fout << Username << " " << Password;

        fout.close();
    }

    else
    {
        ofstream fout;
        fout.open("EmployeesSignupRecord.txt");

        fout << Username << " " << Password;

        fout.close();
    }

    fin.close();
}
bool PostalWorker ::check(string Name, int password)
{
    bool chk;
    chk = false;
    ifstream fin;
    fin.open("EmployeesSignupRecord.txt");
    while (fin)
    {
        string name;
        int pass;
        fin >> name >> pass;

        if (Name == name && password == pass)
        {
            chk = true;
        }
    }

    fin.close();

    return chk;
}
void PostalWorker ::addRecord()
{
    PostalWorker Employee;

    cout << "\nEnter your details: " << endl;
    cout << "Enter ID: ";
    int id;
    cin >> id;
    Employee.setIdOfPotalWorker(id); // Id

    Information info; // association
    string name;
    cout << "Enter Name: ";
    cin >> name;
    string add;
    cout << "Enter Address: ";
    cin >> add;
    string cont;
    cout << "Enter Contact: ";
    cin >> cont;

    info.setName(name);
    info.setAdress(add);
    info.setContactNo(cont);

    Employee.setInfoOfPostalWorker(info); // info

    int chk;
    cout << "Press: " << endl; // Employee Type
    cout << "1: For Postman." << endl;
    cout << "2: For Clerk." << endl;
    cout << "3: For Account Officer." << endl;
    cout << "Enter: ";
    cin >> chk;
    if (chk == 1)
    {
        Employee.setasPostman();
    }
    else if (chk == 2)
    {
        Employee.setasClerk();
    }
    else if (chk == 3)
    {
        Employee.setasAccountOfficer();
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }

    // storing added employees into file
    ifstream fin;
    fin.open("EmployeesRecord.txt");

    // for existing file
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("EmployeesRecord.txt", ios::app);

        fout << endl;
        // storing records of added employees  by iterations
        fout << Employee.getIdOfPostalWorker() << " " // Id

             << Employee.getInfoOfPostalWorker().getName() << " " // Info
             << Employee.getInfoOfPostalWorker().getAdress() << " "
             << Employee.getInfoOfPostalWorker().getContactNo() << " ";
        if (Employee.checkPostman() == true)
        {
            fout << "Postman";
        }
        else if (Employee.checkClerk() == true)
        {
            fout << "Clerk";
        }
        else if (Employee.checkAccountOfficer() == true)
        {
            fout << "AccountOfficer";
        }

        fout.close();
    }

    // for new file
    else
    {
        ofstream fout;
        fout.open("EmployeesRecord.txt");

        // storing records of added employees  by iterations
        fout << Employee.getIdOfPostalWorker() << " " // Id

             << Employee.getInfoOfPostalWorker().getName() << " " // Info
             << Employee.getInfoOfPostalWorker().getAdress() << " "
             << Employee.getInfoOfPostalWorker().getContactNo() << " ";
        if (Employee.checkPostman() == true)
        {
            fout << "Postman";
        }
        else if (Employee.checkClerk() == true)
        {
            fout << "Clerk";
        }
        else if (Employee.checkAccountOfficer() == true)
        {
            fout << "AccountOfficer";
        }

        fout << endl;

        fout.close();
    }

    fin.close();
}

// class Postman
class Postman : public PostalWorker
{
public:
    // functions
    void showDetails();
};
// functions
void Postman ::showDetails()
{
    cout << "Details of Postal Worker:" << endl;
    cout << "Designation: Postman" << endl;
    cout << "ID: " << getIdOfPostalWorker() << endl;
    cout << "Name: " << getInfoOfPostalWorker().getName() << endl;
    cout << "Contact No: " << getInfoOfPostalWorker().getContactNo() << endl;
    cout << "Address: " << getInfoOfPostalWorker().getAdress() << endl;
}

// class Clerk
class Clerk : public PostalWorker
{
    // private
    int Payment;

public:
    // setter
    void setPayment(int);
    // getter
    int getPayment();
    // functions
    void showDetails();
};
// setter
void Clerk ::setPayment(int pay)
{
    Payment = pay;
}
// getter
int Clerk ::getPayment()
{
    return Payment;
}
// functions
void Clerk ::showDetails()
{
    cout << "Details of Postal Worker:" << endl;
    cout << "Designation: Clerk" << endl;
    cout << "ID: " << getIdOfPostalWorker() << endl;
    cout << "Name: " << getInfoOfPostalWorker().getName() << endl;
    cout << "Contact No: " << getInfoOfPostalWorker().getContactNo() << endl;
    cout << "Address: " << getInfoOfPostalWorker().getAdress() << endl;
}

// class AccountOfficer
class AccountOfficer : public PostalWorker
{
    // private:
    int Sales;

public:
    // setter
    void addPayment(int);
    // getter
    int getSales();
    // functions
    void showDetails();
};
// setter
void AccountOfficer ::addPayment(int pay)
{
    Sales += pay;
}
// getter
int AccountOfficer ::getSales()
{
    return Sales;
}
// functions
void AccountOfficer ::showDetails()
{
    cout << "Details of Postal Worker:" << endl;
    cout << "Designation: Account Officer" << endl;
    cout << "ID: " << getIdOfPostalWorker() << endl;
    cout << "Name: " << getInfoOfPostalWorker().getName() << endl;
    cout << "Contact No: " << getInfoOfPostalWorker().getContactNo() << endl;
    cout << "Address: " << getInfoOfPostalWorker().getAdress() << endl;
}

// class PostOffice
class PostOffice
{
    // private:
    int IdOfPostOffice;
    string CityOfPostOffice;
    string AddressOfPostOffice;
    PostalWorker *employees;

public:
    // setters
    void setIdOfPostOffice(int);
    void setAddressOfPostOffice(string);
    void setCityOfPostOffice(string);

    // getters
    int getIdOfPostOffice();
    string getAddressOfPostOffice();
    string getCityOfPostOffice();

    // function
    void addEmployees();
};
// functions of PostOffice
// setters
void PostOffice ::setIdOfPostOffice(int id)
{
    IdOfPostOffice = id;
}
void PostOffice ::setAddressOfPostOffice(string address)
{
    AddressOfPostOffice = address;
}
void PostOffice ::setCityOfPostOffice(string city)
{
    CityOfPostOffice = city;
}
// getters
int PostOffice ::getIdOfPostOffice()
{
    return IdOfPostOffice;
}
string PostOffice ::getAddressOfPostOffice()
{
    return AddressOfPostOffice;
}
string PostOffice ::getCityOfPostOffice()
{
    return CityOfPostOffice;
}
void PostOffice ::addEmployees()
{
    cout << "\nHow many Employees you want to add: ";
    int chk;
    cin >> chk;

    // dynamic allocating desired no of objects for PostalWorker
    employees = new PostalWorker[chk];

    // taking all nessasary information employee
    for (int i = 0; i < chk; i++)
    {
        cout << "\nFor "
             << "Employee # " << i + 1 << endl;

        Information info; // association
        string name;
        cout << "Enter Name: ";
        cin >> name;
        string cont;
        cout << "Enter Contact: ";
        cin >> cont;

        info.setName(name);
        info.setAdress(CityOfPostOffice);
        info.setContactNo(cont);

        employees[i].setInfoOfPostalWorker(info); // info

        int chk;
        cout << "Select Type of Employee: " << endl; // Employee Type
        cout << "1: for Postman." << endl;
        cout << "2: for Clerk." << endl;
        cout << "3: for Account Officer." << endl;
        cout << "Enter: ";
        cin >> chk;
        if (chk == 1)
        {
            employees[i].setasPostman();
        }
        else if (chk == 2)
        {
            employees[i].setasClerk();
        }
        else if (chk == 3)
        {
            employees[i].setasAccountOfficer();
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
        cout << "Id of Employee is: " << employees[i].getIdOfPostalWorker() << endl;
    }

    // storing added employees into file
    ifstream fin;
    fin.open("EmployeesRecord.txt");

    // for existing file
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("EmployeesRecord.txt", ios::app);

        for (int i = 0; i < chk; i++)
        {
            if (i == 0)
            {
                fout << endl;
            }
            // storing records of added employees  by iterations
            fout << employees[i].getIdOfPostalWorker() << " " // Id

                 << employees[i].getInfoOfPostalWorker().getName() << " " // Info
                 << employees[i].getInfoOfPostalWorker().getAdress() << " "
                 << employees[i].getInfoOfPostalWorker().getContactNo() << " ";
            if (employees[i].checkPostman() == true)
            {
                fout << "Postman";
            }
            else if (employees[i].checkClerk() == true)
            {
                fout << "Clerk";
            }
            else if (employees[i].checkAccountOfficer() == true)
            {
                fout << "AccountOfficer";
            }

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }
        fout.close();
    }

    // for new file
    else
    {
        ofstream fout;
        fout.open("EmployeesRecord.txt");

        for (int i = 0; i < chk; i++)
        {
            // storing records of added employees  by iterations
            fout << employees[i].getIdOfPostalWorker() << " " // Id

                 << employees[i].getInfoOfPostalWorker().getName() << " " // Info
                 << employees[i].getInfoOfPostalWorker().getAdress() << " "
                 << employees[i].getInfoOfPostalWorker().getContactNo() << " ";
            if (employees[i].checkPostman() == true)
            {
                fout << "Postman";
            }
            else if (employees[i].checkClerk() == true)
            {
                fout << "Clerk";
            }
            else if (employees[i].checkAccountOfficer() == true)
            {
                fout << "AccountOfficer";
            }

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }

        fout.close();
    }

    fin.close();
}

// class GPO
class GPO
{
    // private
    int IdOfGPO;
    string CityOfGPO;
    PostOffice *OfficesOfGPO;

public:
    // setters
    void setIdOfGPO(int);
    void setCityOfGPO(string);
    void setOfficesOfGPO(PostOffice *);

    // getters
    int getIdOfGPO();
    string getCityOfGPO();
    PostOffice *getOfficesOfGPO();

    // funtions
    void addPostOffices();
};
// functions of GPO
// setters
void GPO ::setIdOfGPO(int id)
{
    IdOfGPO = id;
}
void GPO ::setCityOfGPO(string city)
{
    CityOfGPO = city;
}
void GPO ::setOfficesOfGPO(PostOffice *offc)
{
    OfficesOfGPO = offc;
}
// getters
int GPO ::getIdOfGPO()
{
    return IdOfGPO;
}
string GPO ::getCityOfGPO()
{
    return CityOfGPO;
}
PostOffice *GPO ::getOfficesOfGPO()
{
    return OfficesOfGPO;
}
// functions
void GPO ::addPostOffices()
{
    cout << "How many Post Offices you want to add: ";
    int chk;
    cin >> chk;

    // dynamic allocating desired no of objects for PostalWorker
    OfficesOfGPO = new PostOffice[chk];

    // taking all nessasary information employee
    for (int i = 0; i < chk; i++)
    {
        cout << "\nFor " << i + 1 << " PostOffice: " << endl;
        cout << "Enter ID: ";
        int id;
        cin >> id;
        OfficesOfGPO[i].setIdOfPostOffice(id); // Id

        string add;
        cout << "Enter Address: ";
        cin >> add;
        OfficesOfGPO[i].setAddressOfPostOffice(add); // Address

        OfficesOfGPO[i].setCityOfPostOffice(CityOfGPO); // City

        cout << "\nEnter details of Employees Working in this Post Office:" << endl;
        OfficesOfGPO[i].addEmployees();
    }

    // storing added PostOffices into file
    ifstream fin;
    fin.open("PostOfficesRecord.txt");

    // for existing file
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("PostOfficesRecord.txt", ios::app);

        // chk = 2
        for (int i = 0; i < chk; i++)
        {

            string postoffcfile = OfficesOfGPO[i].getCityOfPostOffice() + ".txt";
            ifstream fin1;
            fin1.open(postoffcfile);
            if (fin1.is_open() != true)
            {
                ofstream fout1;
                fout1.open(postoffcfile); // making seperate files of post offices acc to city
                fout1.close();
            }

            if (i == 0)
            {
                fout << endl;
            }
            // storing records of added employees  by iterations
            fout << OfficesOfGPO[i].getIdOfPostOffice() << " "      // Id
                 << OfficesOfGPO[i].getAddressOfPostOffice() << " " // Adress
                 << OfficesOfGPO[i].getCityOfPostOffice() << " ";   // City

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
            fin1.close();
        }

        fout.close();
    }

    // for new file
    else
    {
        ofstream fout;
        fout.open("PostOfficesRecord.txt");

        // chk = 2
        for (int i = 0; i < chk; i++)
        {
            string postoffcfile = OfficesOfGPO[i].getCityOfPostOffice() + ".txt";
            ifstream fin1;
            fin1.open(postoffcfile);
            if (fin1.is_open() != true)
            {
                ofstream fout1;
                fout1.open(postoffcfile); // making seperate files of post offices acc to city
                fout1.close();
            }
            // storing records of added employees  by iterations
            fout << OfficesOfGPO[i].getIdOfPostOffice() << " "      // Id
                 << OfficesOfGPO[i].getAddressOfPostOffice() << " " // Adress
                 << OfficesOfGPO[i].getCityOfPostOffice() << " ";   // City

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }

        fout.close();
    }

    fin.close();
}

// class Admin
class Admin
{
    // private
    int Id;
    string Username;
    string Name;
    int Password;
    PostOffice *Offices;
    GPO *gpos;
    AccountOfficer accofcr; // Accociation

public:
    // default constructor
    Admin();
    // setters
    void setUsername(string);
    void setName(string);
    void setPassword(int);

    // getters
    int getId();
    string getUsername();
    string getName();
    int getPassword();

    // functions
    void setRecord();
    bool check(string, int);
    void addEmployees();
    void updateEmployee();
    void deleteEmployee();
    void addGPO();
    void search();
    void getTotalSales();
};
// functions of Admin
// default constructor
Admin ::Admin()
{
    Id = rand() % 10000;
}
// setters
void Admin ::setUsername(string uname)
{
    Username = uname;
}
void Admin ::setName(string name)
{
    Name = name;
}
void Admin ::setPassword(int passw)
{
    Password = passw;
}
// getters
int Admin ::getId()
{
    return Id;
}
string Admin ::getUsername()
{
    return Username;
}
string Admin ::getName()
{
    return Name;
}
int Admin ::getPassword()
{
    return Password;
}
// functions
void Admin ::setRecord()
{
    ifstream fin;
    fin.open("AdminRecord.txt");

    // making record
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("AdminRecord.txt", ios ::app);

        fout << endl;
        fout << Id << " " << Name << " " << Username << " " << Password;

        fout.close();
    }

    else
    {
        ofstream fout;
        fout.open("AdminRecord.txt");

        fout << Id << " " << Name << " " << Username << " " << Password;

        fout.close();
    }
    cout << "\nYour Id is: " << Id << endl;
    fin.close();
}
bool Admin ::check(string Name, int password)
{
    bool chk;
    chk = false;
    ifstream fin;
    fin.open("AdminRecord.txt");
    while (fin)
    {
        int id;
        string uname;
        string name;
        int pass;
        fin >> id >> name >> uname >> pass;

        if (Name == uname && password == pass)
        {
            chk = true;
        }
    }

    fin.close();

    return chk;
}
void Admin ::addEmployees()
{
    PostalWorker *employees;
    cout << "\nHow many Employees you want to add: ";
    int chk;
    cin >> chk;

    // dynamic allocating desired no of objects for PostalWorker
    employees = new PostalWorker[chk];

    // taking all nessasary information employee
    for (int i = 0; i < chk; i++)
    {
        cout << "\nFor "
             << "Employee # " << i + 1 << endl;

        Information info; // association
        string name;
        cout << "Enter Name: ";
        cin >> name;
        string add;
        cout << "Enter Address: ";
        cin >> add;
        string cont;
        cout << "Enter Contact: ";
        cin >> cont;

        info.setName(name);
        info.setAdress(add);
        info.setContactNo(cont);

        employees[i].setInfoOfPostalWorker(info); // info

        int chk;
        cout << "Select Type of Employee: " << endl; // Employee Type
        cout << "1: for Postman." << endl;
        cout << "2: for Clerk." << endl;
        cout << "3: for Account Officer." << endl;
        cout << "Enter: ";
        cin >> chk;
        if (chk == 1)
        {
            employees[i].setasPostman();
        }
        else if (chk == 2)
        {
            employees[i].setasClerk();
        }
        else if (chk == 3)
        {
            employees[i].setasAccountOfficer();
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
        cout << "Id of Employee is: " << employees[i].getIdOfPostalWorker() << endl;
    }

    // storing added employees into file
    ifstream fin;
    fin.open("EmployeesRecord.txt");

    // for existing file
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("EmployeesRecord.txt", ios::app);

        for (int i = 0; i < chk; i++)
        {
            if (i == 0)
            {
                fout << endl;
            }
            // storing records of added employees  by iterations
            fout << employees[i].getIdOfPostalWorker() << " " // Id

                 << employees[i].getInfoOfPostalWorker().getName() << " " // Info
                 << employees[i].getInfoOfPostalWorker().getAdress() << " "
                 << employees[i].getInfoOfPostalWorker().getContactNo() << " ";
            if (employees[i].checkPostman() == true)
            {
                fout << "Postman";
            }
            else if (employees[i].checkClerk() == true)
            {
                fout << "Clerk";
            }
            else if (employees[i].checkAccountOfficer() == true)
            {
                fout << "AccountOfficer";
            }

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }
        fout.close();
    }

    // for new file
    else
    {
        ofstream fout;
        fout.open("EmployeesRecord.txt");

        for (int i = 0; i < chk; i++)
        {
            // storing records of added employees  by iterations
            fout << employees[i].getIdOfPostalWorker() << " " // Id

                 << employees[i].getInfoOfPostalWorker().getName() << " " // Info
                 << employees[i].getInfoOfPostalWorker().getAdress() << " "
                 << employees[i].getInfoOfPostalWorker().getContactNo() << " ";
            if (employees[i].checkPostman() == true)
            {
                fout << "Postman";
            }
            else if (employees[i].checkClerk() == true)
            {
                fout << "Clerk";
            }
            else if (employees[i].checkAccountOfficer() == true)
            {
                fout << "AccountOfficer";
            }

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }

        fout.close();
    }

    fin.close();
}

void Admin ::updateEmployee()
{
    int gid;
    cout << "Enter the Employee ID which you want update: " << endl;
    cin >> gid;

    cout << "\nEnter Details of new Employee: " << endl;
    // variables for taking details of new Employee
    int nid;
    string nname;
    string nadd;
    string ncont;
    string nidofc;
    string naddofc;

    cout << "Enter ID: " << endl;
    cin >> nid;
    cout << "Enter Name: " << endl;
    cin >> nname;
    cout << "Enter Address: " << endl;
    cin >> nadd;
    cout << "Enter Contact: " << endl;
    cin >> ncont;
    cout << "Give information about current post office of Employee: " << endl;
    cout << "Enter Id of Post Office: " << endl;
    cin >> nidofc;
    cout << "Enter Address of Post Office: " << endl;
    cin >> naddofc;

    ifstream fin;
    fin.open("EmployeesRecord.txt");
    // variables for reading contents of file
    int id;
    string name;
    string add;
    string cont;
    string idofc;
    string addofc;

    // making a temp file for storing updated data
    ofstream fout;
    fout.open("Temp.txt");
    while (fin)
    {

        fin >> id >> name >> add >> cont >> idofc >> addofc;
        if (id == gid)
        {
            fout << nid << " " << nname << " " << nadd << " " << ncont << " " << nidofc << " " << naddofc << endl;
        }

        else
        {
            fout << id << " " << name << " " << add << " " << cont << " " << idofc << " " << addofc << endl;
        }
    }
    // for clearing data in "EmployeeDirectory"
    ofstream clear;
    clear.open("EmployeesRecord.txt", ofstream::out | ofstream::trunc);
    clear.close();

    // reading temp and storing updated data in Origional file
    ifstream fin1;
    fin1.open("Temp.txt");

    ofstream fout1;
    fout1.open("EmployeesRecord.txt");
    while (fin1)
    {
        int id;
        string name;
        string add;
        string cont;
        string idofc;
        string addofc;

        // reading
        fin1 >> id >> name >> add >> cont >> idofc >> addofc;

        // writing
        fout1 << id << " " << name << " " << add << " " << idofc << " " << addofc << endl;
    }
    fin1.close();
    fout1.close();

    // deleting temp file
    remove("Temp.txt");
    fin.close();
    fout.close();
}

void Admin ::deleteEmployee()
{
    int gid;
    cout << "Enter the Employee ID which you want to delete: " << endl;
    cin >> gid;

    ifstream fin;
    fin.open("EmployeesRecord.txt");
    // variables for reading contents of file
    int id;
    string name;
    string add;
    string cont;
    string idofc;
    string addofc;

    // making a temp file for storing updated data
    ofstream fout;
    fout.open("Temp.txt");
    while (fin)
    {

        fin >> id >> name >> add >> cont >> idofc >> addofc;
        if (id == gid)
        {
            continue;
        }

        else
        {
            fout << id << " " << name << " " << add << " " << cont << " " << idofc << " " << addofc << endl;
        }
    }
    // for clearing data in "EmployeeDirectory"
    ofstream clear;
    clear.open("EmployeesRecord.txt", ofstream::out | ofstream::trunc);
    clear.close();

    // reading temp and storing updated data in Origional file
    ifstream fin1;
    fin1.open("Temp.txt");

    ofstream fout1;
    fout1.open("EmployeesRecord.txt");
    while (fin1)
    {
        int id;
        string name;
        string add;
        string cont;
        string idofc;
        string addofc;

        // reading
        fin1 >> id >> name >> add >> cont >> idofc >> addofc;

        // writing
        fout1 << id << " " << name << " " << add << " " << idofc << " " << addofc << endl;
    }
    fin1.close();
    fout1.close();

    // deleting temp file
    remove("Temp.txt");
    fin.close();
    fout.close();
}
void Admin ::addGPO()
{
    cout << "\nHow many GPOs you want to add: ";
    int chk;
    cin >> chk;

    // dynamic allocating desired no of objects for PostalWorker
    gpos = new GPO[chk];

    // taking all nessasary information employee
    for (int i = 0; i < chk; i++)
    {
        cout << "For "
             << "GPO # " << i + 1 << "\n"
             << endl;
        cout << "Enter ID: ";
        int id;
        cin >> id;
        gpos[i].setIdOfGPO(id); // Id

        string city;
        cout << "Enter City: ";
        cin >> city;
        gpos[i].setCityOfGPO(city); // Address

        cout << "\nEnter Post Offices Under this GPO: " << endl;
        gpos[i].addPostOffices();
    }

    // storing added employees into file
    ifstream fin;
    fin.open("GPORecord.txt");

    // for existing file
    if (fin.is_open() == true)
    {
        ofstream fout;
        fout.open("GPORecord.txt", ios::app);

        // chk = 2
        for (int i = 0; i < chk; i++)
        {
            if (i == 0)
            {
                fout << endl;
            }
            // storing records of added employees  by iterations
            fout << gpos[i].getIdOfGPO() << " "    // Id
                 << gpos[i].getCityOfGPO() << " "; // City

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }

        fout.close();
    }

    // for new file
    else
    {
        ofstream fout;
        fout.open("GPORecord.txt");

        // chk = 2
        for (int i = 0; i < chk; i++)
        {
            // storing records of added employees  by iterations
            fout << gpos[i].getIdOfGPO() << " "    // Id
                 << gpos[i].getCityOfGPO() << " "; // City

            if (i == chk - 1)
            {
                continue;
            }
            else
            {
                fout << endl;
            }
        }

        fout.close();
    }

    fin.close();
}
void Admin ::search()
{
    cout << "\nPress: " << endl;
    cout << "1: For Admins" << endl;
    cout << "2: For Employees" << endl;
    cout << "Enter: ";
    int chk;
    cin >> chk;
    ifstream fin;
    ifstream fin1;

    if (chk == 1)
    {
        cout << "\nEnter Id of Admin: ";
        int gid;
        cin >> gid;
        ifstream fin;
        fin.open("AdminRecord.txt");

        while (fin)
        {
            int id;
            string name;
            string username;
            int pass;

            fin >> id >> name >> username >> pass;
            if (gid == id)
            {
                cout << "Username: " << username << endl;
                cout << "Name: " << name << endl;
                break;
            }
        }
    }
    else if (chk == 2)
    {
        cout << "\nEnter Id of Postal Worker: ";
        int gid;
        cin >> gid;
        ifstream fin;
        fin.open("EmployeesRecord.txt");

        while (fin)
        {
            int id;
            string name;
            string add;
            string cont;
            string desig;

            fin >> id >> name >> add >> cont >> desig;
            if (gid == id)
            {
                cout << "Name: " << name << endl;
                cout << "Address: " << add << endl;
                cout << "Contact: " << cont << endl;
                cout << "Designation: " << desig << endl;
                break;
            }
        }
    }
}
void Admin ::getTotalSales()
{
    ifstream fin;
    fin.open("SalesRecord.txt");

    int sales;
    while (fin)
    {
        int pay;
        fin >> pay;

        sales += pay;
    }

    cout << "\nThe Total Sales are: " << sales << endl;
}
// class shipment
class Shipment
{
    // private:
    int Id;
    float Weight;
    string Time;
    int Stamp;
    bool SameDay;
    bool OneDay;
    bool Urgent;
    string sendingPOCity;
    string recievingPOCity;
    string sendingPOAddress;
    string recievingPOAddress;
    AccountOfficer AccOfficer; // Association
    Clerk clerk;               // Association

public:
    // default constructor
    Shipment();
    // setters
    void setWeight(float);
    void setStamp(int);
    void setasSameDay();
    void setasOneDay();
    void setasUrgent();
    void setsendingPOCity(string);
    void setrecievingPOCity(string);
    void setsendingPOAddress(string);
    void setrecievingPOAddress(string);
    void setAccOfficer(AccountOfficer);
    void setclerk(Clerk);

    // getters
    int getId();
    float getWeight();
    string getTime();
    int getStamp();
    bool getSameDay();
    bool getOneDay();
    bool getUrgent();
    string getsendingPOCity();
    string getrecievingPOCity();
    string getsendingPOAddress();
    string getrecievingPOAddress();
    AccountOfficer getAccOfficer();
    Clerk getclerk();
};
// functions for Shipment
// default constructor
Shipment ::Shipment()
{

    Id = rand() % 10000; // generate a random id

    time_t now = time(0);
    Time = ctime(&now); // generating current time based on system time
}
// setters
void Shipment ::setWeight(float weight)
{
    Weight = weight;
}
void Shipment ::setStamp(int st)
{
    Stamp = st;
}
void Shipment ::setasSameDay()
{
    SameDay = true;
}
void Shipment ::setasOneDay()
{
    OneDay = true;
}
void Shipment ::setasUrgent()
{
    Urgent = true;
}
void Shipment ::setsendingPOCity(string spoc)
{
    sendingPOCity = spoc;
}
void Shipment ::setrecievingPOCity(string rpoc)
{
    recievingPOCity = rpoc;
}
void Shipment ::setsendingPOAddress(string spoa)
{
    sendingPOAddress = spoa;
}
void Shipment ::setrecievingPOAddress(string rpoa)
{
    recievingPOAddress = rpoa;
}
void Shipment ::setAccOfficer(AccountOfficer accofc)
{
    AccOfficer = accofc;
}
void Shipment ::setclerk(Clerk clk)
{
    clerk = clk;
}
// getters
int Shipment ::getId()
{
    return Id;
}
float Shipment ::getWeight()
{
    return Weight;
}
string Shipment ::getTime()
{
    return Time;
}
int Shipment ::getStamp()
{
    return Stamp;
}
bool Shipment ::getSameDay()
{
    return SameDay;
}
bool Shipment ::getOneDay()
{
    return OneDay;
}
bool Shipment ::getUrgent()
{
    return Urgent;
}
string Shipment ::getsendingPOCity()
{
    return sendingPOCity;
}
string Shipment ::getrecievingPOCity()
{
    return recievingPOCity;
}
string Shipment ::getsendingPOAddress()
{
    return sendingPOAddress;
}
string Shipment ::getrecievingPOAddress()
{
    return recievingPOAddress;
}
AccountOfficer Shipment ::getAccOfficer()
{
    return AccOfficer;
}
Clerk Shipment ::getclerk()
{
    return clerk;
}

// class Customer
class Customer
{
    // private:
    int Id;
    string Username;
    int Password;
    string Email;
    string City;
    int RecieverId;
    int OrderId;
    Information InfoOfCustomer; // Association
    Shipment shipment;          // Association
public:
    // default constructor
    Customer();

    // setters
    void setUsername(string);
    void setPassword(int);
    void setEmail(string);
    void setCity(string);
    void setRecieverId(int);
    void setInfoOfCustomer(Information);

    // getters
    int getId();
    string getUsername();
    int getPassword();
    string getEmail();
    string getCity();
    int getRecieverId();
    int getOrderId();
    Information getInfoOfCustomer();

    // funtions
    void Register();
    bool check(string, int);
    void DoOrder();
    void PrintInvoice();
    void TrackOrder();
};
// functions of Customer
// default constructor
Customer ::Customer()
{
    Id = rand() % 10000;
    OrderId = rand() % 10000;
}
// setters
void Customer ::setUsername(string uname)
{
    Username = uname;
}
void Customer ::setPassword(int passw)
{
    Password = passw;
}
void Customer ::setEmail(string email)
{
    Email = email;
}
void Customer ::setCity(string city)
{
    City = city;
}
void Customer ::setRecieverId(int rid)
{
    RecieverId = rid;
}
void Customer ::setInfoOfCustomer(Information info)
{
    InfoOfCustomer = info;
}
// getters
int Customer ::getId()
{
    return Id;
}
string Customer ::getUsername()
{
    return Username;
}
int Customer ::getPassword()
{
    return Password;
}
string Customer ::getEmail()
{
    return Email;
}
string Customer ::getCity()
{
    return City;
}
int Customer ::getRecieverId()
{
    return RecieverId;
}
int Customer ::getOrderId()
{
    return OrderId;
}
Information Customer ::getInfoOfCustomer()
{
    return InfoOfCustomer;
}
// functions
void Customer ::Register()
{
    Customer customer;

    cout << "\nEnter Username: ";
    string uname;
    cin >> uname;
    cout << "Choose 4 digit Password: ";
    int password;
    cin >> password;
    cout << "Retype Password: ";
    int rpassword;
    cin >> rpassword;

    customer.setUsername(uname); // username

    if (password == rpassword)
    {
        customer.setPassword(password); // password

        Information info; // association
        cout << "\nEnter Name: ";
        string name;
        cin >> name;
        cout << "Enter City: ";
        string city;
        cin >> city;
        cout << "Enter Address: ";
        string add;
        cin >> add;
        cout << "Enter Contact: ";
        string cont;
        cin >> cont;

        info.setName(name);
        info.setAdress(add);
        customer.setCity(city);
        info.setContactNo(cont);
        customer.setInfoOfCustomer(info); // info

        cout << "Enter Email: ";
        string email;
        cin >> email;
        customer.setEmail(email);

        // storing added employees into file
        ifstream fin;
        fin.open("CustomerRecord.txt");

        // for existing file
        if (fin.is_open() == true)
        {
            ofstream fout;
            fout.open("CustomerRecord.txt", ios::app);

            fout << endl;
            // storing records of added employees  by iterations
            fout << customer.getId() << " "       // id
                 << customer.getUsername() << " " // username
                 << customer.getPassword() << " " // password

                 << customer.getInfoOfCustomer().getName() << " " // Info
                 << customer.getInfoOfCustomer().getAdress() << " "
                 << customer.getCity() << " "
                 << customer.getInfoOfCustomer().getContactNo() << " "

                 << customer.getEmail() << " ";

            fout.close();
        }

        // for new file
        else
        {
            ofstream fout;
            fout.open("CustomerRecord.txt");

            // storing records of added employees  by iterations
            fout << customer.getId() << " "       // id
                 << customer.getUsername() << " " // username
                 << customer.getPassword() << " " // password

                 << customer.getInfoOfCustomer().getName() << " " // Info
                 << customer.getInfoOfCustomer().getAdress() << " "
                 << customer.getCity() << " "
                 << customer.getInfoOfCustomer().getContactNo() << " "

                 << customer.getEmail() << " ";

            fout.close();
        }
        cout << "\nYour Id is: " << customer.getId() << endl;
        cout << "Registered Successfully!" << endl;
        fin.close();
    }
    else
    {
        cout << "Error! Password doesn't match." << endl;
    }
}
bool Customer ::check(string Name, int password)
{
    bool chk;
    chk = false;
    ifstream fin;
    fin.open("CustomerRecord.txt");
    while (fin)
    {
        int id;
        string uname;
        int pass;
        string name;
        string add;
        string cont;
        string email;

        fin >> id >> uname >> pass >> name >> add >> cont >> email;

        if (Name == uname && password == pass)
        {
            chk = true;
        }
    }
    fin.close();
    return chk;
}

void Customer ::DoOrder()
{
    cout << "\nBuy Stamp: " << endl;
    cout << "Press: " << endl;
    cout << "1: Rs 5" << endl;
    cout << "2: Rs 10" << endl;
    cout << "3: Rs 20" << endl;
    cout << "4: Rs 50" << endl;
    cout << "5: Rs 100" << endl;
    cout << "Enter: ";
    int chk;
    cin >> chk;
    if (chk == 1)
    {
        shipment.setStamp(5);
    }
    else if (chk == 2)
    {
        shipment.setStamp(10);
    }
    else if (chk == 3)
    {
        shipment.setStamp(20);
    }
    else if (chk == 4)
    {
        shipment.setStamp(50);
    }
    else if (chk == 5)
    {
        shipment.setStamp(100);
    }

    if (chk == 1 || chk == 2 || chk == 3 || chk == 4 || chk == 5)
    {
        cout << "\nEnter Details about Shipment: " << endl;

        cout << "Enter Weight (Kgs): ";
        float weight;
        cin >> weight;
        shipment.setWeight(weight);

        cout << "\nSelect Mail Service: " << endl;
        cout << "Press: " << endl;
        cout << "1: For Same Day" << endl;
        cout << "2: For One Day" << endl;
        cout << "Enter: ";
        int chk;
        cin >> chk;

        if (chk == 1)
        {
            shipment.setasSameDay();
        }
        else if (chk == 2)
        {
            shipment.setasOneDay();
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }

        cout << "\nPress: " << endl;
        cout << "1: For Urgent Mail Service" << endl;
        cout << "2: For Normal Mail Service" << endl;
        cout << "Enter: ";
        int chk1;
        cin >> chk1;

        if (chk1 == 1)
        {
            shipment.setasUrgent();
        }
        else if (chk1 == 2)
        {
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }

        // calculating charges of service
        int charges;
        if (weight >= 0.25 && weight < 0.5)
        {
            if (shipment.getSameDay() == true) // local
            {
                charges = 51;
            }
            else if (shipment.getOneDay() == true) // city to city
            {
                charges = 86;
            }
        }
        else if (weight >= 0.5 && weight < 1)
        {
            if (shipment.getSameDay() == true) // local
            {
                charges = 64;
            }
            else if (shipment.getOneDay() == true) // city to city
            {
                charges = 132;
            }
        }
        else if (weight == 1)
        {
            if (shipment.getSameDay() == true) // local
            {
                charges = 90;
            }
            else if (shipment.getOneDay() == true) // city to city
            {
                charges = 175;
            }
        }
        else if (weight > 1 && weight <= 3)
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 100;
            }
            else // Urgent
            {
                charges = 120;
            }
        }
        else if (weight > 3 && weight <= 5) // upto 3
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 175;
            }
            else // Urgent
            {
                charges = 210;
            }
        }
        else if (weight > 5 && weight <= 10) // upto 5
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 250;
            }
            else // Urgent
            {
                charges = 300;
            }
        }
        else if (weight > 10 && weight <= 15) // upto 10
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 375;
            }
            else // Urgent
            {
                charges = 450;
            }
        }
        else if (weight > 15 && weight <= 20) // upto 15
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 500;
            }
            else // Urgent
            {
                charges = 600;
            }
        }
        else if (weight > 20 && weight <= 25) // upto 20
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 625;
            }
            else // Urgent
            {
                charges = 750;
            }
        }
        else if (weight > 25 && weight <= 30) // upto 25
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 750;
            }
            else // Urgent
            {
                charges = 900;
            }
        }
        else if (weight > 30) // upto 25
        {
            if (shipment.getUrgent() == false) // Regular
            {
                charges = 875;
            }
            else // Urgent
            {
                charges = 1050;
            }
        }
        charges += 75; // registration fee

        Clerk clrk;
        shipment.getAccOfficer().addPayment(charges + shipment.getStamp());
        clrk.setPayment(charges + shipment.getStamp());
        shipment.setclerk(clrk);

        cout << "\nEnter Sender's and Reciever's Post Office Details (respectively) from below : " << endl;
        ifstream fin;
        fin.open("PostOfficesRecord.txt");

        while (fin)
        {
            int id;
            string add;
            string city;
            fin >> id >> add >> city;

            if (shipment.getSameDay() == true)
            {
                cout << add << endl; // showing added post offices in the system
            }
            else if (shipment.getOneDay() == true)
            {
                cout << city << endl; // showing added post offices in the system
            }
        }
        fin.close();

        cout << "Enter Sending PO Address: ";
        string sendingPOAddress;
        cin >> sendingPOAddress;
        shipment.setsendingPOAddress(sendingPOAddress);
        cout << "Enter Recieving PO Address: ";
        string recievingPOAddress;
        cin >> recievingPOAddress;
        shipment.setrecievingPOAddress(recievingPOAddress);

        cout << "Enter your City: ";
        string sendercity;
        cin >> sendercity;
        shipment.setsendingPOCity(sendercity);

        while (true)
        {
            cout << "Enter Reciever's Id: ";
            cin >> RecieverId;
            ifstream fin2;
            fin2.open("CustomerRecord.txt");

            bool chk;
            while (fin2)
            {
                int id;
                string uname;
                int pass;
                string name;
                string add;
                string city;
                string cont;
                string email;

                fin2 >> id >> uname >> pass >> name >> add >> city >> cont >> email;
                if (id == RecieverId)
                {
                    cout << "\nReciver's Name: " << name << endl;
                    chk = true;
                    shipment.setrecievingPOCity(city);
                    break;
                }
            }
            fin2.close();
            if (chk == true)
            {
                cout << "\nPress 1 to confirm order, 2 to retype Id: ";
                int chk;
                cin >> chk;

                if (chk == 1)
                {
                    cout << "Order Confirmed" << endl;
                    cout << "Order Id is: " << OrderId << endl;
                    break;
                }
                else if (chk == 2)
                {
                    continue;
                }
                else
                {
                    cout << "\nError! Invalid Input" << endl;
                    continue;
                }
            }
        }

        ifstream fin1;
        fin1.open(shipment.getsendingPOCity() + ".txt");

        // id SendingPO recievingpO type service weight charges
        // for existing file
        if (fin1.is_open() == true)
        {
            ofstream fout;
            fout.open(shipment.getsendingPOCity() + ".txt", ios ::app); // opening sending PO file

            fout << endl;
            fout << getOrderId() << " ";
            fout << shipment.getsendingPOAddress() << " ";
            fout << shipment.getrecievingPOAddress() << " ";
            if (shipment.getSameDay() == true)
            {
                fout << "SameDay"
                     << " ";
            }
            else if (shipment.getOneDay() == true)
            {
                fout << "OneDay"
                     << " ";
            }
            if (shipment.getUrgent() == true)
            {
                fout << "Urgent"
                     << " ";
            }
            else if (shipment.getUrgent() == false)
            {
                fout << "Normal"
                     << " ";
            }
            fout << shipment.getWeight() << "kg"
                 << " " << shipment.getclerk().getPayment() << "Rs"
                 << " " << shipment.getStamp() << "Rs"
                 << " ";

            if (shipment.getSameDay() == true)
            {
                fout << "Today";
            }
            else if (shipment.getSameDay() == false)
            {
                fout << "NextDay";
            }

            fout << endl;
            fout.close();
        }

        // for new file
        else
        {
            ofstream fout;
            fout.open(shipment.getsendingPOCity() + ".txt"); // opening sending PO file

            fout << getOrderId() << " "; // id
            fout << shipment.getsendingPOAddress() << " ";
            fout << shipment.getrecievingPOAddress() << " ";
            if (shipment.getSameDay() == true)
            {
                fout << "SameDay"
                     << " ";
            }
            else if (shipment.getOneDay() == true)
            {
                fout << "OneDay"
                     << " ";
            }
            if (shipment.getUrgent() == true)
            {
                fout << "Urgent"
                     << " ";
            }
            else if (shipment.getUrgent() == false)
            {
                fout << "Normal"
                     << " ";
            }
            fout << shipment.getWeight() << "kg"
                 << " " << shipment.getclerk().getPayment() << "Rs"
                 << " "
                 << "Stamp:" << shipment.getStamp() << "Rs"
                 << " ";

            if (shipment.getSameDay() == true)
            {
                fout << "Today";
            }
            else if (shipment.getSameDay() == false)
            {
                fout << "NextDay";
            }

            fout.close();
        }
        fin1.close();

        ifstream fin2;
        fin2.open("SalesRecord.txt");

        // for existing file
        if (fin2.is_open() == true)
        {
            ofstream fout;
            fout.open("SalesRecord.txt", ios ::app);

            fout << shipment.getclerk().getPayment() << " ";

            fout.close();
        }

        // for new file
        else
        {
            ofstream fout;
            fout.open("SalesRecord.txt");

            fout << shipment.getclerk().getPayment() << " ";

            fout.close();
        }
        fin2.close();
    }
    else
    {
        cout << "\nError! Invalid Input" << endl;
    }
}
void Customer ::TrackOrder()
{

    cout << "\nEnter Sending City: ";
    string sendingPOCity;
    cin >> sendingPOCity;
    cout << "Enter Order ID: ";
    int OrderId;
    cin >> OrderId;

    ifstream fin;
    fin.open(sendingPOCity + ".txt");

    int chk = 0;
    while (fin)
    {
        int id;
        string sendingAdd;
        string recievingAdd;
        string type;
        string service;
        string weight;
        string charges;
        string stamp;
        string reachingtime;

        fin >> id >> sendingAdd >> recievingAdd >> type >> service >> weight >> charges >> stamp >> reachingtime;

        // id SendingPO recievingpO type service weight charges

        if (OrderId == id)
        {
            cout << "\n\n--- ORDER DETAILS ---" << endl;
            cout << "\nId: " << id << endl;
            cout << "Sending Address: " << sendingAdd << endl;
            cout << "Recieving Address: " << recievingAdd << endl;
            cout << "Type: " << type << endl;
            cout << "Service: " << service << endl;
            cout << "Weight: " << weight << endl;
            cout << "Charges: " << charges << endl;
            cout << "\nYour Order will be delivered: " << reachingtime << endl;
            cout << "___________________________________" << endl;

            chk++;
            break;
        }

        fin.close();
    }
    if (chk == 0)
    {
        cout << "Order not found!" << endl;
    }
}
void Customer ::PrintInvoice()
{
    cout << "\n\n--- INVOICE ---\n\n";
    cout << shipment.getTime() << endl;
    cout << "\nID: " << OrderId << endl;
    cout << "Weight: " << shipment.getWeight() << endl;
    cout << "Type: ";
    if (shipment.getSameDay() == true)
    {
        cout << "Same Day" << endl;
    }
    else if (shipment.getOneDay() == true)
    {
        cout << "One Day" << endl;
    }
    cout << "Service: ";
    if (shipment.getUrgent() == true)
    {
        cout << "Urgent" << endl;
    }

    else if (shipment.getUrgent() != true)
    {
        cout << "Normal" << endl;
    }
    cout << "Sending PO: " << shipment.getsendingPOCity() + " " + shipment.getsendingPOAddress() << endl;
    cout << "Recieving PO: " << shipment.getrecievingPOCity() + " " + shipment.getrecievingPOAddress() << endl;
    cout << "Sender's City: " << shipment.getsendingPOCity() << endl;
    cout << "Reciever's City: " << shipment.getrecievingPOCity() << endl;
    cout << "Sender ID: " << Id << endl;
    cout << "Reciever ID: " << RecieverId << endl;

    cout << "\nRegistration Fee: " << 75 << endl;
    if (shipment.getUrgent() == true)
    {
        cout << "Shipment charges(Urgent): " << shipment.getclerk().getPayment() - 75 << endl;
    }
    else if (shipment.getUrgent() != true)
    {
        cout << "Shipment charges: " << shipment.getclerk().getPayment() - 75 << endl;
    }

    cout << "\nTotal Charges: " << shipment.getclerk().getPayment() << endl;

    cout << "\n_________________________" << endl;
}

// main
int main()
{
    cout << "\n\t\t\t\t\t\t\t\t\t_________________________________" << endl;
    cout << "\t\t\t\t\t\t\t\t\t---------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t      PAKISTAN POST SERVICE" << endl;
    cout << "\t\t\t\t\t\t\t\t\t---------------------------------" << endl;

    int chk;
    while (true)
    {
        cout << "\n\nPress 1 to Proceed and 2 for Exit: " << endl;
        cout << "Enter: ";
        cin >> chk;

        if (chk == 1)
        {
            int chk;
            cout << "\nPress:" << endl;
            cout << "1: If you are Admin" << endl;
            cout << "2: If you are Customer" << endl;
            cout << "3: If you are Employee" << endl;
            cout << "4: To Exit" << endl;
            cout << "Enter: ";
            cin >> chk;

            // for Admin
            if (chk == 1)
            {
                cout << "\n------------------" << endl;
                cout << "ADMIN Login System" << endl;
                cout << "-------------------" << endl;
                cout << "\nPress: " << endl;
                cout << "1: For SignUp" << endl;
                cout << "2: For LogIn" << endl;
                cout << "3: For Exit" << endl;
                cout << "Enter: ";
                int chk;
                cin >> chk;

                Admin Rafay;

                // signup
                if (chk == 1)
                {
                    while (true)
                    {
                        string username;
                        cout << "\nEnter Username: ";
                        cin >> username;
                        Rafay.setUsername(username); // username
                        string name;
                        cout << "Enter Name: ";
                        cin >> name;
                        Rafay.setName(name); // name

                        int password;
                        cout << "Choose 4 digit Password: ";
                        cin >> password;
                        int repassword;
                        cout << "Retype Password: ";
                        cin >> repassword;
                        if (password == repassword)
                        {
                            Rafay.setPassword(password); // password
                            Rafay.setRecord();

                            cout << "Succesfully SingnedUp!" << endl;
                            break;
                        }
                        else
                        {
                            cout << "Error! Password doesn't match." << endl;
                        }
                    }
                }
                // login
                else if (chk == 2)
                {
                    string username;
                    cout << "\nEnter Username: ";
                    cin >> username;
                    Rafay.setUsername(username); // username

                    int password;
                    cout << "Enter Password: ";
                    cin >> password;
                    Rafay.setPassword(password); // password

                    bool pass;
                    pass = Rafay.check(username, password);

                    if (pass == true)
                    {
                        cout << "Password Matched!" << endl;

                        while (true)
                        {
                            int chk;
                            cout << "\nPress:" << endl;
                            cout << "1: For Adding GPO" << endl;
                            cout << "2: For Adding Employee" << endl;
                            cout << "3: For Updating Employee" << endl;
                            cout << "4: For Deleting Employee" << endl;
                            cout << "5: To Search" << endl;
                            cout << "6: To Get Sales Report" << endl;
                            cout << "7: To LogOut" << endl;
                            cout << "Enter: ";
                            cin >> chk;

                            if (chk == 1)
                            {
                                Rafay.addGPO();
                            }
                            else if (chk == 2)
                            {
                                Rafay.addEmployees();
                            }
                            else if (chk == 3)
                            {
                                Rafay.updateEmployee();
                            }
                            else if (chk == 4)
                            {
                                Rafay.deleteEmployee();
                            }
                            else if (chk == 5)
                            {
                                Rafay.search();
                            }
                            else if (chk == 6)
                            {
                                Rafay.getTotalSales();
                            }
                            else if (chk == 7)
                            {
                                cout << "\nLoggedOut!" << endl;
                                break;
                            }
                            else
                            {
                                cout << "\nError! Invalid Input" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Incorrect Password or Username!" << endl;
                    }
                }
                else if (chk == 3)
                {
                    cout << "\nExited!" << endl;
                }
                else
                {
                    cout << "\nError! Invalid Input." << endl;
                }
            }

            // for Costumer
            else if (chk == 2)
            {
                cout << "\n---------------------" << endl;
                cout << "COSTOMER Login System" << endl;
                cout << "---------------------" << endl;

                cout << "\nPress: " << endl;
                cout << "1: For SignUp" << endl;
                cout << "2: For LogIn" << endl;
                cout << "Enter: ";
                int chk;
                cin >> chk;

                Customer customer;

                // signup
                if (chk == 1)
                {
                    customer.Register();
                }
                // login
                else if (chk == 2)
                {
                    string username;
                    cout << "\nEnter Username: ";
                    cin >> username;
                    customer.setUsername(username);

                    int password;
                    cout << "Enter Password: ";
                    cin >> password;
                    customer.setPassword(password);

                    bool pass;
                    pass = customer.check(username, password);

                    if (pass == true)
                    {
                        cout << "Password Matched!" << endl;
                        while (true)
                        {
                            cout << "\nPress: " << endl;
                            cout << "1: For Doing Order" << endl;
                            cout << "2: For Tracking Order" << endl;
                            cout << "3: To LogOut" << endl;
                            cout << "Enter: ";
                            int chk;
                            cin >> chk;
                            if (chk == 1)
                            {
                                customer.DoOrder();

                                cout << "\n\nPress: " << endl;
                                cout << "1: To Print Invoice" << endl;
                                cout << "2: To Continue" << endl;
                                cout << "Enter: ";

                                int chk1;
                                cin >> chk1;
                                if (chk1 == 1)
                                {
                                    customer.PrintInvoice();
                                }
                                else if (chk1 == 2)
                                {
                                    cout << "\nYour Order Recieved Successfully!" << endl;
                                }
                                else
                                {
                                    cout << "\nError! Invalid Input" << endl;
                                }
                            }
                            else if (chk == 2)
                            {
                                customer.TrackOrder();
                            }
                            else if (chk == 3)
                            {
                                cout << "\nLpggedOut." << endl;
                                break;
                            }
                            else
                            {
                                cout << "\nError! Invalid Input" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Incorrect Password or Username!" << endl;
                    }
                }
                else
                {
                    cout << "\nError! Invalid Input." << endl;
                }
            }

            // for Employee
            else if (chk == 3)
            {
                cout << "\n---------------------" << endl;
                cout << "EMPLOYEE Login System" << endl;
                cout << "---------------------" << endl;

                cout << "\nPress: " << endl;
                cout << "1: For SignUp" << endl;
                cout << "2: For LogIn" << endl;
                cout << "Enter: ";

                int chk;
                cin >> chk;

                PostalWorker Employee;

                // signup
                if (chk == 1)
                {
                    string username;
                    cout << "\nEnter Username: ";
                    cin >> username;
                    Employee.setUsername(username); // username

                    int password;
                    cout << "Choose 4 digit Password: ";
                    cin >> password;
                    int repassword;
                    cout << "Rewrite Password: ";
                    cin >> repassword;
                    if (password == repassword)
                    {
                        Employee.setPassword(password); // password
                        Employee.setRecord();

                        cout << "Succesfully SingnedUp!" << endl;
                    }
                    else
                    {
                        cout << "Error! Password doesn't match." << endl;
                    }

                    // as employee is new so taking aditional information and storing it into the file
                    Employee.addRecord();
                }
                // login
                else if (chk == 2)
                {
                    string username;
                    cout << "Enter Username: ";
                    cin >> username;
                    Employee.setUsername(username);

                    int password;
                    cout << "Enter Password: ";
                    cin >> password;
                    Employee.setPassword(password);

                    bool pass;
                    pass = Employee.check(username, password);

                    if (pass == true)
                    {
                        cout << "Password Matched!" << endl;
                    }
                    else
                    {
                        cout << "Incorrect Password or Username!" << endl;
                    }
                }
                else
                {
                    cout << "\nError! Invalid Input." << endl;
                }
            }
            else if (chk == 4)
            {
                cout << "\nExited!" << endl;
            }

            else
            {
                cout << "Invalid Input" << endl;
            }
        }
        else if (chk == 2)
        {

            cout << "\n\t\t\t\t\t\t\t\t\t_______________________________________" << endl;
            cout << "\n\t\t\t\t\t\t\t\t\tTHANKS for using PAKISTAN POST SERVICE!\n"
                 << endl;
            break;
        }
        else
        {
            cout << "\nInvalid Input, press again: " << endl;
        }
    }
    return 0;
}