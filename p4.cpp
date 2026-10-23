#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//================ COMPANY =================

void addCompany()
{
    ofstream file("companies.txt",ios::app);

    int id;
    string name,phone,city;

    cout<<"\nCompany ID : ";
    cin>>id;

    cin.ignore();

    cout<<"Company Name : ";
    getline(cin,name);

    cout<<"Phone : ";
    getline(cin,phone);

    cout<<"City : ";
    getline(cin,city);

    file<<id<<"|"<<name<<"|"<<phone<<"|"<<city<<endl;

    file.close();

    cout<<"\nCompany Added Successfully!\n";
}

void viewCompanies()
{
    ifstream file("companies.txt");

    string line;

    cout<<"\n===== COMPANY LIST =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

void searchCompany()
{
    ifstream file("companies.txt");

    string search;
    string line;

    cin.ignore();

    cout<<"Enter Company Name : ";
    getline(cin,search);

    bool found=false;

    while(getline(file,line))
    {
        if(line.find(search)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    if(!found)
    {
        cout<<"Company Not Found\n";
    }

    file.close();
}

//================ WORKER =================

void addWorker()
{
    ofstream file("workers.txt",ios::app);

    int id;
    string name;
    string phone;
    double salary;

    cout<<"\nWorker ID : ";
    cin>>id;

    cin.ignore();

    cout<<"Worker Name : ";
    getline(cin,name);

    cout<<"Phone : ";
    getline(cin,phone);

    cout<<"Salary : ";
    cin>>salary;

    file<<id<<"|"
        <<name<<"|"
        <<phone<<"|"
        <<salary<<endl;

    file.close();

    cout<<"\nWorker Added Successfully!\n";
}

void viewWorkers()
{
    ifstream file("workers.txt");

    string line;

    cout<<"\n===== WORKER LIST =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

void searchWorker()
{
    ifstream file("workers.txt");

    string search;
    string line;

    cin.ignore();

    cout<<"Enter Worker Name : ";
    getline(cin,search);

    bool found=false;

    while(getline(file,line))
    {
        if(line.find(search)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    if(!found)
    {
        cout<<"Worker Not Found\n";
    }

    file.close();
}
//================ LOT MANAGEMENT =================

void addLot()
{
    ofstream file("lots.txt",ios::app);

    string lotNo;
    string company;
    string date;
    string diamondType;

    int pieces;

    double weight;
    double rate;
    double totalValue;

    cin.ignore();

    cout<<"\nLot Number : ";
    getline(cin,lotNo);

    cout<<"Company Name : ";
    getline(cin,company);

    cout<<"Date Received : ";
    getline(cin,date);

    cout<<"Diamond Type : ";
    getline(cin,diamondType);

    cout<<"Number Of Pieces : ";
    cin>>pieces;

    cout<<"Weight (Carat) : ";
    cin>>weight;

    cout<<"Rate Per Carat : ";
    cin>>rate;

    totalValue = weight * rate;

    file<<lotNo<<"|"
        <<company<<"|"
        <<date<<"|"
        <<diamondType<<"|"
        <<pieces<<"|"
        <<weight<<"|"
        <<rate<<"|"
        <<totalValue
        <<endl;

    file.close();

    cout<<"\nLot Added Successfully!\n";
}

void viewLots()
{
    ifstream file("lots.txt");

    string line;

    cout<<"\n===== LOT RECORDS =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

void searchLot()
{
    ifstream file("lots.txt");

    string search;
    string line;

    cin.ignore();

    cout<<"Enter Lot Number : ";
    getline(cin,search);

    bool found=false;

    while(getline(file,line))
    {
        if(line.find(search)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    if(!found)
    {
        cout<<"Lot Not Found\n";
    }

    file.close();
}

void companyLots()
{
    ifstream file("lots.txt");

    string company;
    string line;

    cin.ignore();

    cout<<"Enter Company Name : ";
    getline(cin,company);

    bool found=false;

    cout<<"\nLots Of "<<company<<"\n\n";

    while(getline(file,line))
    {
        if(line.find(company)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    if(!found)
    {
        cout<<"No Lots Found\n";
    }

    file.close();
}
//================ ASSIGNMENT MANAGEMENT =================

void assignLot()
{
    ofstream file("assignments.txt", ios::app);

    string lotNo;
    string workerName;
    string date;

    double workerRate;

    cin.ignore();

    cout<<"\nLot Number : ";
    getline(cin, lotNo);

    cout<<"Worker Name : ";
    getline(cin, workerName);

    cout<<"Assignment Date : ";
    getline(cin, date);

    cout<<"Worker Rate Per Carat : ";
    cin>>workerRate;

    file<<lotNo<<"|"
        <<workerName<<"|"
        <<date<<"|"
        <<workerRate
        <<endl;

    file.close();

    cout<<"\nLot Assigned Successfully!\n";
}

void viewAssignments()
{
    ifstream file("assignments.txt");

    string line;

    cout<<"\n===== ASSIGNMENTS =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

//================ COMPLETION =================

void completeLot()
{
    ofstream file("completed.txt", ios::app);

    string lotNo;
    string date;

    double originalWeight;
    double finalWeight;
    double loss;

    cin.ignore();

    cout<<"\nLot Number : ";
    getline(cin, lotNo);

    cout<<"Original Weight : ";
    cin>>originalWeight;

    cout<<"Final Weight : ";
    cin>>finalWeight;

    cin.ignore();

    cout<<"Completion Date : ";
    getline(cin,date);

    loss = originalWeight - finalWeight;

    file<<lotNo<<"|"
        <<originalWeight<<"|"
        <<finalWeight<<"|"
        <<loss<<"|"
        <<date
        <<endl;

    file.close();

    cout<<"\nWeight Loss = "
        <<loss
        <<" Carat\n";

    cout<<"Work Completed Successfully!\n";
}

void viewCompletedLots()
{
    ifstream file("completed.txt");

    string line;

    cout<<"\n===== COMPLETED LOTS =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

void searchAssignment()
{
    ifstream file("assignments.txt");

    string lotNo;
    string line;

    cin.ignore();

    cout<<"Enter Lot Number : ";
    getline(cin,lotNo);

    bool found=false;

    while(getline(file,line))
    {
        if(line.find(lotNo)!=string::npos)
        {
            cout<<line<<endl;
            found=true;
        }
    }

    if(!found)
    {
        cout<<"Assignment Not Found\n";
    }

    file.close();
}
//================ EXPENSE MANAGEMENT =================

void addExpense()
{
    ofstream file("expenses.txt", ios::app);

    string date;
    string type;
    double amount;

    cin.ignore();

    cout<<"\nDate : ";
    getline(cin,date);

    cout<<"Expense Type : ";
    getline(cin,type);

    cout<<"Amount : ";
    cin>>amount;

    file<<date<<"|"
        <<type<<"|"
        <<amount
        <<endl;

    file.close();

    cout<<"\nExpense Added Successfully!\n";
}

void viewExpenses()
{
    ifstream file("expenses.txt");

    string line;

    cout<<"\n===== EXPENSE RECORDS =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}

//================ DAILY PROFIT =================

void dailyProfit()
{
    double income;
    double workerCost;
    double lossCost;
    double expenses;

    cout<<"\nToday's Income : ";
    cin>>income;

    cout<<"Worker Charges : ";
    cin>>workerCost;

    cout<<"Loss Cost : ";
    cin>>lossCost;

    cout<<"Other Expenses : ";
    cin>>expenses;

    double profit;

    profit=
    income
    -workerCost
    -lossCost
    -expenses;

    cout<<"\n====================";
    cout<<"\nDAILY PROFIT";
    cout<<"\n====================";

    cout<<"\nIncome : "<<income;
    cout<<"\nWorker Cost : "<<workerCost;
    cout<<"\nLoss Cost : "<<lossCost;
    cout<<"\nExpenses : "<<expenses;

    cout<<"\n\nPROFIT = "<<profit<<endl;

    ofstream report("reports.txt",ios::app);

    report<<"DAILY|"
          <<income<<"|"
          <<workerCost<<"|"
          <<lossCost<<"|"
          <<expenses<<"|"
          <<profit
          <<endl;

    report.close();
}

//================ MONTHLY PROFIT =================

void monthlyProfit()
{
    double income;
    double salary;
    double electricity;
    double loss;
    double other;

    cout<<"\nMonthly Income : ";
    cin>>income;

    cout<<"Salary Expense : ";
    cin>>salary;

    cout<<"Electricity Bill : ";
    cin>>electricity;

    cout<<"Diamond Loss Cost : ";
    cin>>loss;

    cout<<"Other Expenses : ";
    cin>>other;

    double profit;

    profit=
    income
    -salary
    -electricity
    -loss
    -other;

    cout<<"\n====================";
    cout<<"\nMONTHLY PROFIT";
    cout<<"\n====================";

    cout<<"\nProfit = "<<profit<<endl;

    ofstream report("reports.txt",ios::app);

    report<<"MONTHLY|"
          <<income<<"|"
          <<salary<<"|"
          <<electricity<<"|"
          <<loss<<"|"
          <<other<<"|"
          <<profit
          <<endl;

    report.close();
}

//================ REPORTS =================

void viewReports()
{
    ifstream file("reports.txt");

    string line;

    cout<<"\n===== REPORTS =====\n";

    while(getline(file,line))
    {
        cout<<line<<endl;
    }

    file.close();
}
//================ LOGIN SYSTEM =================

bool login()
{
    string username;
    string password;

    cout<<"\n===== LOGIN =====\n";

    cout<<"Username : ";
    cin>>username;

    cout<<"Password : ";
    cin>>password;

    if(username=="admin" && password=="1234")
    {
        cout<<"\nLogin Successful!\n";
        return true;
    }

    cout<<"\nWrong Username or Password!\n";
    return false;
}

//================ BACKUP =================

void backupData()
{
    ofstream backup("backup.txt");

    ifstream company("companies.txt");
    ifstream worker("workers.txt");
    ifstream lot("lots.txt");

    string line;

    backup<<"\n===== COMPANIES =====\n";

    while(getline(company,line))
    {
        backup<<line<<endl;
    }

    backup<<"\n===== WORKERS =====\n";

    while(getline(worker,line))
    {
        backup<<line<<endl;
    }

    backup<<"\n===== LOTS =====\n";

    while(getline(lot,line))
    {
        backup<<line<<endl;
    }

    company.close();
    worker.close();
    lot.close();
    backup.close();

    cout<<"\nBackup Created Successfully!\n";
}

//================ DASHBOARD =================

void dashboard()
{
    ifstream company("companies.txt");
    ifstream worker("workers.txt");
    ifstream lot("lots.txt");

    string line;

    int companyCount=0;
    int workerCount=0;
    int lotCount=0;

    while(getline(company,line))
    {
        companyCount++;
    }

    while(getline(worker,line))
    {
        workerCount++;
    }

    while(getline(lot,line))
    {
        lotCount++;
    }

    company.close();
    worker.close();
    lot.close();

    cout<<"\n========================";
    cout<<"\nWORKSHOP DASHBOARD";
    cout<<"\n========================";

    cout<<"\nTotal Companies : "<<companyCount;
    cout<<"\nTotal Workers   : "<<workerCount;
    cout<<"\nTotal Lots      : "<<lotCount;
    cout<<"\n";
}

//================ SEARCH ALL =================

void searchAll()
{
    string search;
    string line;

    cin.ignore();

    cout<<"\nEnter Keyword : ";
    getline(cin,search);

    cout<<"\n===== RESULTS =====\n";

    ifstream company("companies.txt");

    while(getline(company,line))
    {
        if(line.find(search)!=string::npos)
        {
            cout<<line<<endl;
        }
    }

    company.close();

    ifstream worker("workers.txt");

    while(getline(worker,line))
    {
        if(line.find(search)!=string::npos)
        {
            cout<<line<<endl;
        }
    }

    worker.close();

    ifstream lot("lots.txt");

    while(getline(lot,line))
    {
        if(line.find(search)!=string::npos)
        {
            cout<<line<<endl;
        }
    }

    lot.close();
}

//================ DELETE COMPANY =================

void deleteCompany()
{
    string search;
    string line;

    cin.ignore();

    cout<<"\nEnter Company Name To Delete : ";
    getline(cin,search);

    ifstream file("companies.txt");
    ofstream temp("temp.txt");

    while(getline(file,line))
    {
        if(line.find(search)==string::npos)
        {
            temp<<line<<endl;
        }
    }

    file.close();
    temp.close();

    remove("companies.txt");
    rename("temp.txt","companies.txt");

    cout<<"\nCompany Deleted Successfully!\n";
}
int main()
{
    if(!login())
    {
        return 0;
    }
    int choice;

    do
    {
        cout<<"\n";
        cout<<"=====================================\n";
        cout<<" DIAMOND WORKSHOP MANAGEMENT SYSTEM\n";
        cout<<"=====================================\n";

        cout<<"1. Add Company\n";
        cout<<"2. View Companies\n";
        cout<<"3. Search Company\n";

        cout<<"4. Add Worker\n";
        cout<<"5. View Workers\n";
        cout<<"6. Search Worker\n";
        cout<<"7. Add Lot\n";
cout<<"8. View Lots\n";
cout<<"9. Search Lot\n";
cout<<"10. Company Lots\n";
cout<<"11. Assign Lot\n";
cout<<"12. View Assignments\n";
cout<<"13. Search Assignment\n";
cout<<"14. Complete Lot\n";
cout<<"15. View Completed Lots\n";
cout<<"16. Add Expense\n";
cout<<"17. View Expenses\n";
cout<<"18. Daily Profit\n";
cout<<"19. Monthly Profit\n";
cout<<"20. View Reports\n";
cout<<"21. Dashboard\n";
cout<<"22. Search All Records\n";
cout<<"23. Backup Data\n";
cout<<"24. Delete Company\n";
        cout<<"0. Exit\n";

        cout<<"\nEnter Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                addCompany();
                break;

            case 2:
                viewCompanies();
                break;

            case 3:
                searchCompany();
                break;

            case 4:
                addWorker();
                break;

            case 5:
                viewWorkers();
                break;

            case 6:
                searchWorker();
                break;
            case 7:
    addLot();
    break;

case 8:
    viewLots();
    break;

case 9:
    searchLot();
    break;

case 10:
    companyLots();
    break;
case 11:
    assignLot();
    break;

case 12:
    viewAssignments();
    break;

case 13:
    searchAssignment();
    break;

case 14:
    completeLot();
    break;

case 15:
    viewCompletedLots();
    break;
case 16:
    addExpense();
    break;

case 17:
    viewExpenses();
    break;

case 18:
    dailyProfit();
    break;

case 19:
    monthlyProfit();
    break;

case 20:
    viewReports();
    break;
case 21:
    dashboard();
    break;

case 22:
    searchAll();
    break;

case 23:
    backupData();
    break;

case 24:
    deleteCompany();
    break;
            case 0:
                cout<<"Program Closed\n";
                break;

            default:
                cout<<"Invalid Choice\n";
        }

    }while(choice!=0);

    return 0;
}
