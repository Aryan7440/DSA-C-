#include <iostream>
#include <string>
using namespace std;

int students = 0;
class student
{
public:
    int roll;
    int semester;
    string name;
};

class department : virtual public student
{
public:
    string prog;
};

class exam_cell : virtual public student
{
public:
    int physics;
    int chemistry;
    int math;
    int history;
    int english;
};

class marksheet : public department, public exam_cell
{
public:
    void addstudent(string n,int rolln,int s,string pr,int p,int c,int h,int m ,int e)
    {
        name=n;
        roll=rolln;
        semester=s;
        prog=pr;
        physics=p;
        chemistry=c;
        history=h;
        english=e;
        math=m;
    }
    void create()
    {
        cin.clear();
        cin.sync();
        cout << "Enter name" << endl;
        getline(cin, name);
        cout << "Enter roll number" << endl;
        cin >> roll;
        cout << "Enter semester" << endl;
        cin >> semester;
        cin.clear();
        cin.sync();
        cout << "Enter Programme" << endl;
        getline(cin, prog);
        cout << "Enter Marks P C M H E" << endl;
        cin >> physics >> chemistry >> math >> history >> english;
    }
    void update()
    {
        int choice;
        cout << "What do you want to update?" << endl;
        cout << "1] Name\n2] Roll Number\n3] Semester\n4] Programme\n5] Marks" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin.clear();
            cin.sync();
            cout << "Enter updated name" << endl;
            getline(cin, name);
            break;
        case 2:
            cout << "Enter updated roll" << endl;
            cin >> roll;
            break;
        case 3:
            cout << "Enter updated semester" << endl;
            cin >> semester;
            break;
        case 4:
            cin.clear();
            cin.sync();
            cout << "Enter updated programme" << endl;
            getline(cin, prog);
            break;
        case 5:
            cout << "Enter updated marks P C M H E" << endl;
            cin >> physics >> chemistry >> math >> history >> english;
            break;
        default:
            cout << "Invalid Choice!";
            break;
        }
    }
    void display()
    {
        cout << "\n\n\n###      MARKSHEET       ###" << endl;
        cout << "----------------------------" << endl;
        cout << name << "\n"
             << roll << "\n"
             << prog << "\nSemester " << semester << endl;
        cout << "----------------------------" << endl;
        cout << "SUBJECT\t\tOBTAINED" << endl;
        cout << "PHY\t\t" << physics << "/100" << endl;
        cout << "CHEM\t\t" << chemistry << "/100" << endl;
        cout << "MATH\t\t" << math << "/100" << endl;
        cout << "HIST\t\t" << history << "/100" << endl;
        cout << "ENG\t\t" << english << "/100" << endl;
        cout << endl;
        cout << "TOTAL\t\t" << physics + chemistry + math + history + english << "/500" << endl;
    }
};

void add(marksheet obj[])
{
    students++;
    obj[students].create();
}
void show(marksheet obj[])
{
    int roll;
    cout << "enter roll number\n";
    cin >> roll;
    int flag = 0;
    for (int i = 0; i <= students; i++)
    {
        if (obj[i].roll == roll)
        {
            obj[i].display();
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Not found" << endl;
    }
}
void update(marksheet obj[])
{
    int roll;
    cout << "enter roll number\n";
    cin >> roll;
    int flag = 0;
    for (int i = 0; i <= students; i++)
    {
        if (obj[i].roll == roll)
        {
            obj[i].update();
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Not found" << endl;
    }
}

int main()
{
    marksheet obj[10];
    obj[0].addstudent("aryan",01,1,"Cse",78,98,65,32,47);
    int ch;
    int flag = 1;
    while (flag)
    {
        cout << "\n\n\t\tMENU"
             << "\n1. ADD STUDENTS"
             << "\n2. UPDATE STUDENT DETAILS"
             << "\n3. SHOW STUDENT MARKSHEET"
             << "\n4. Exit\n\n";
        cout << "ENTER CHOICE:" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            add(obj);
            break;
        case 2:
            update(obj);
            break;
        case 3:
            show(obj);
            break;
        case 4:
            flag = 0;
            break;
        default:
            cout << "Invalid!" << endl;
            break;
        }
    }

    return 0;
}