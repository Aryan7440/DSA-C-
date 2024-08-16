#include <iostream>
using namespace std;

class employee
{
private: // not neccesary to explicitly write private in acess specifiers
    // class memebers
    int serial_no;
    string name;
    int age;
    string position;

    // int five()
    // {
    //     return 5;
    // }
    friend int five(employee &x);
    // {
    //     return 5;
    // }

public:
    static int stat;

    /*  constructors are used to assign values to opjects
    they must be defined in public class
    there are three types of constructor(default,parametarized,copy
    constructprs decleration name is the same as class name
     they can be overloaded to form multiple constructors (overloading can be defined as having multiple constructors for different parameters)*/

    employee() // default constructor (neccesary if using user made constructor)
    {
        serial_no = 0;
        name = "none";
        age = 0;
        position = "no postion";
    }
    employee(int Sno, string name, int Age, string Pos = "none") // paramaterized construcotor   with defeult valur
    {
        serial_no = Sno;
        this->name = name; // "this->" is used to point to object instance
        age = Age;
        position = Pos;
    }

    employee(employee &obj) // copy constructor (copies the values of other objects)
    {
        serial_no = obj.serial_no;
        name = obj.name;
        age = obj.age;
        position = obj.position;
    }
    ~employee() // distructor (always with "~"symbol in public with same class name)
    {
        // cout<< "object distroyed"<<endl;                                  //distructor message will show at the end of object scope
    }

    static void change()
    {
        // age=5;
        stat = 0;
    }

    // class functions or methods are group of code used to perform operation on objects
    void display_info() // using public acess specifiers to operate on private members
    {
        cout << "********************" << endl;
        cout << "SERIAL NUMBER:->    " << serial_no << endl;
        cout << "NAME         :->    " << name << endl;
        cout << "AGE          :->    " << age << endl;
        cout << "POSITION     :->    " << position << endl;
        cout << "********************" << endl;
    }
    void display_size()
    {
        cout << sizeof(name) << endl;
        cout << sizeof(position) << endl;
        cout << sizeof(age) << endl;
        cout << sizeof(serial_no) << endl;
    }
};

int employee ::stat = 9;

int five(employee &x)
{
    // return 5;
    int a;
    a=x.age;
}

int main()
{
    employee e1; // a class object (memory gets assigned)
    // e1.display_info();                          //default values
    // employee e2(1,"aryan",20,"SDE");            //paramentrized
    // e2.display_info();                          //copy constructor
    employee e3(3, "ayush", 6); // default argumrnt
    // e3.display_info();
    // cout<<sizeof(employee)<<endl;
    // cout<<sizeof(e1)<<endl;
    // e1.display_size();

    // cout<<e2.serial_no;                    //serial_no is in private will show error

    cout << employee ::stat << endl;
    e3.stat = 4;
    cout << e3.stat << endl;
    e3.stat++;
    cout << e1.stat << endl;
    e1.stat = e1.stat + 6;
    cout << employee ::stat << endl;
    employee ::change();
    cout << employee ::stat << endl;
    e1.change();
    cout << employee ::stat << endl;
    
    

    cout << five(e1);
}
