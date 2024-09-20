#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;
class salary;
class hospital2;
class opening
{
public:
    opening()
    {
        cout << "Hello and welcome to Amity Speciality Hospital" << endl
             << "you are now entering the main menu of our website" << endl
             << "please fill the needfull" << endl;
    }
};
class hospital // class & object
{
private: // int allotno,roomno,bedno;//static
    int age, totalpay, nodays, dd1, mm1, yy1, dd2, mm2, yy2;
    char name[20], bloodt[4], alergies[30], fathern[20], Gender[10], reason[20], dname[20];
    float money, mpay;

public:
    hospital() // default constructor
    {
        age = 0;
        // roomno=101;
        // allotno=3349;
        // bedno=4;
        nodays = 0;
    }
    void insert()
    {
        cout << "Enter the required information:\n1.name\n2.father name\n3.blood type\n4.prior allergies or disease\n5.gender\n6.reason\n7.admission date dd|mm|yy\n";
        cin >> name >> fathern >> bloodt >> alergies >> Gender >> reason >> dd1 >> mm1 >> yy1;
    }
    void allot()
    {
        static int allotno = 3349, roomno = 101, bedno = 4; // static member function
        cout << "your alloted no is" << allotno << "\n";
        allotno++;
        cout << "your room no is" << roomno << "\n";
        roomno++; // static variable use
        cout << "your bed no is" << bedno << "\n";
        bedno++;
    }
    inline int input(int, int, int, int, float); // inline
    inline void output();
    ~hospital() // destructor
    {
        cout << "\nThanks for visiting";
    }

protected:
    string companyName;
    int duration;
    int cgpa;
    string dn;
    string speciality;
    string polly;

public:
    void Insert()
    {

        cout << "Enter the doctor you would prefer working under:";
        cin >> dn;
        cout << "In which field do you want your specialistaion in:";
        cin >> speciality;
    }
    void Input()
    {
        cout << "enter your name:";
        cin >> polly;
        cout << "Enter university Name: ";
        cin >> companyName;
        cout << "Enter Duration (in months): ";
        cin >> duration;
        cout << "enter cgpa";
        cin >> cgpa;
        int aggee;
        cout << "Enter the Experience you have in the surgical room: ";
        cin >> aggee;
        try // exeption handelling checing if eligible for surgery
        {
            if (aggee < 3)
            {
                throw aggee;
            }
            else
            {
                cout << "Experience sholud be 3 so you are legally take part in surgeries during internship.";
            }
        }
        catch (int aggee)
        {
            cout << "Experience is less than 3 years so you cannot take part in surgeries during internship." << endl;
        }
    }
    void show()
    {
        cout << "The doctor has accepted to work with you" << endl;
        cout << "Now youll work under:"
             << " Dr " << dn << endl;
        cout << "your specialisation would be in :" << speciality << endl;
    }

    virtual void displayInfo()
    { // virtual
        cout << "Name: " << polly << endl
             << "University Name: " << companyName << endl;
        cout << "Duration: " << duration << " months"
             << "&cgpa" << cgpa << endl;
    }

private:
    string nn;
    string authority;

public:
    void Show()
    {
        cout << "your information will be stored" << endl;
        cout << "please donot share this information" << endl;
        cout << "enter your name and authority" << endl;
        cin >> nn;
        cin >> authority;
    }
    void dipict()
    {
        cout << "your name is :" << nn << endl;
        cout << "your authority is:" << authority << endl;
        cout << "your info has been stored and will be shared with higher ups" << endl;
    }
};
int hospital::input(int dd2, int mm2, int yy2, int nodays = 2, float money = 2000.42) // scope resolution& default and constructor overloading
{
    this->money = money; // 2000.42;
    this->dd2 = dd2;     // this
    this->mm2 = mm2;
    this->yy2 = yy2;
    this->nodays = nodays;
    cout << "enter the medical expense";
    cin >> mpay;
    totalpay = int(nodays * money + mpay); // type casting
}
void hospital::output()
{
    cout << "Your submitted information is:\n";
    cout << name << "\n";
    cout << fathern << "\n";
    cout << bloodt << "\n";
    cout << alergies << "\n";
    cout << Gender << "\n";
    cout << reason << "\n";
    cout << dd1 << "|" << mm1 << "|" << yy1 << "\n";
    cout << dd2 << "|" << mm2 << "|" << yy2 << "\n";
    cout << "the total payment to be paid is:" << totalpay << "\n";
}
class hospital2 : public hospital // global class
{
public:
    int idno, nyearact, yyhospital;
    char name[20], speciality[20];

public:
    int sh = 0;
    hospital2()
    {
        cout << " Docter if you are ready to attend the patient \n then please enter your name:" << endl;
        cin >> name;
        cout << "enter your id:" << endl;
        cin >> idno;
        cout << "enter your speciality:";
        cin >> speciality;
    };

    float workt()
    {
        cout << "please enter the no of shifts you have worked:" << endl;
        cin >> sh;
        return sh; // Return the number of shifts
    }

    friend float total(salary, hospital2);

    void output() const // constant
    {
        cout << "The doctor attending you:" << name << endl;
        cout << "his speciality:" << speciality << endl;
    }
    hospital2(const hospital2 &p) // copy condtructor,constant object
    {
        idno = p.idno;
        cout << "the id is:" << idno << endl;
    };
};
class salary
{
public:
    float salarys = 0;
    float money()
    {
        cout << "enter your salary:";
        cin >> salarys;
    }
    friend float total(salary, hospital2); // friend function
};
float total(salary a, hospital2 b)
{
    int finalsal;
    cout << "b.sh" << b.sh << endl;
    finalsal = a.salarys + b.sh;
    cout << "final salary is:" << finalsal << endl;
}
// Derived class inheriting from hospital through inheritance
class Stipend : public hospital
{
private:
    double stipendAmount;

public:
    Stipend()
    {
        cout << "Enter Stipend Amount: $";
        cin >> stipendAmount;
        hospital::Insert();
    }

    void displayInfo()
    {
        hospital::show();
        cout << "Stipend Amount: Rs" << stipendAmount << endl;
    }
};
class hospitalExpensis : public hospital
{ // operator overloading and inheriting
private:
    double totalExpenses;

public:
    void deco()
    {
        hospital::Show();
    }
    hospitalExpensis operator+(hospitalExpensis &other)
    {
        hospitalExpensis result;
        result.totalExpenses = totalExpenses + other.totalExpenses;
        return result;
    }

    void addExpense(double expense)
    {
        totalExpenses += expense;
    }

    void displayExpenses()
    {
        cout << "Total Expenses:" << totalExpenses << endl;
    }
    void dsa()
    {
        hospital::dipict();
    }
};

template <typename T>//genric and this template can be used for taking the ratings of any services in hospital
class Rating
{
private:
    T rating;

public:
    Rating()
    {
        rating=0;
    }

    void collectRating(const string &a)
    {
        cout << "Please rate " << setw(10) << a << " (1 - Poor, 5 - Excellent): ";
        cin >> rating;
    }

    void displayRating(const string &a)
    {
        cout << left << setw(12) << a << " Rating: " << right << setw(2) << rating << "/5" << endl;//setw is the manuplater used here field width
    }
};

opening e; // global object
int main()
{
    int dd2, mm2, yy2, nodays = 2, i, n;
    float money = 2000.42;
    // array of object
    int valid = 0;
    cout << "Enter weather you are doctor or patient to enter respective databasis:\n";
    cout << "1.Patient details:\n2.Doctor details:\n3.Job/internship:\n4.Hospital expensis:\n5.Hospital rating:";
    cin >> valid;
    switch (valid)
    {
    case 1:
    {
        cout << "Enter the number of patients:";
        cin >> n;
        hospital *h = new hospital[n];
        for (i = 0; i < n; i++)
        {
            h[i].insert();
            h[i].allot();
            cout << "enter the exit date in the format dd|mm|yy,no of days&money";
            cin >> dd2 >> mm2 >> yy2 >> nodays >> money;
            h[i].input(dd2, mm2, yy2, nodays, money);
            h[i].output();
            delete[] h; // new and delete
        }
    }
    break;
    case 2:
    {
        hospital2 p;
        salary s;
        p.workt();
        s.money();      // Call the money() function to input salary
        total(s, p);    // Pass the salary object and the hospital2 object to the total function
        hospital2 z(p); // copy constructor
        p.output();
        // local
        class opinion
        {
            int income;

        public:
            void category()
            {
                cout << "enter your patients income:";
                cin >> income;
                if (income >= 100000)
                    cout << "you can not avail any discount as you are from genral category";
                else if (income >= 50000)
                    cout << "you can avail any discount upto 10% you are from ewc category";
                else if (income >= 20000)
                    cout << "you can avail any discount upto 60% you are from obc or sc or st category";
                else if (income <= 10000)
                    cout << "you can avail any discount upto 100% through goverment scheme";
            }
        };
        opinion o;
        o.category(); // local objects
    }
    break;
    case 3:
    {
        Stipend myStipend;
        hospital p1;
        hospital *ptr; // virtual function applied with pointer
        p1.Input();
        cout << "\nInternship Information:\n";
        ptr = &myStipend;
        ptr->displayInfo();
        ptr = &p1;
        ptr->displayInfo();
        // myStipend.displayInfo();
    }
    break;
    case 4:
    {
        cout << "Hospital expenses:" << endl;
        hospitalExpensis h1, h2, totalExpenses;
        int n3, j3;
        h1.deco();
        cout << "enter the hospital expenses and medicine expensis:";
        cin >> n3 >> j3;
        h1.addExpense(n3);
        h2.addExpense(j3);
        totalExpenses = h1 + h2;
        cout << "Hospital 1 Expenses: ";
        h1.displayExpenses();
        cout << "Hospital 2 Expenses: ";
        h2.displayExpenses();
        cout << "Combined Expenses: ";
        totalExpenses.displayExpenses();
        h1.dsa();
    }
    break;
    case 5:
    {
        Rating<int> staffRating, doctorsRating, serviceRating, websiteRating;

        staffRating.collectRating("Staff");
        doctorsRating.collectRating("Doctors");
        serviceRating.collectRating("Service");
        websiteRating.collectRating("Website");
        cout << "\nHospital Ratings:" << endl;
        staffRating.displayRating("Staff");
        doctorsRating.displayRating("Doctors");
        serviceRating.displayRating("Service");
        websiteRating.displayRating("Website");
    }
    break;
    }
    return 0;
}