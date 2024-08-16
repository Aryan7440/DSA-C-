#include <iostream>
#include <string>
using namespace std;

int book_count = 0; // change

class books
{
private:
    double *price;
    int *stock;
    static int succesfull_transaction;
    static int failed_transaction;

    friend void change_price(books &b, double new_price)
    {
        *(b.price) = new_price;
        cout << "Price of the book has been succesfully updatated" << endl;
    }

public:
    string author;
    string tittle;
    string publisher;

    books()
    {
        price = new double(0);
        stock = new int(0);
        author = "None";
        tittle = "None";
        publisher = "None";
    }
    books(string Tittle, string Author, string Publisher, double Price, int Stock)
    {
        tittle = Tittle;
        author = Author;
        publisher = Publisher;
        price = new double(Price);
        stock = new int(Stock);
        book_count++;
    }

    void enter_bookDetails(string Tittle, string Author, string Publisher, double Price, int Stock)
    {
        tittle = Tittle;
        author = Author;
        publisher = Publisher;
        *price = Price;
        *stock = Stock;
        book_count++;
    }

    void display()
    {
        cout << "Books name         " << tittle << endl;
        cout << "Author's name      " << author << endl;
        cout << "Publisher's name   " << publisher << endl;
        cout << "Price:             " << *price << "Rs" << endl;
        cout << "Quantity:          " << *stock << endl;
    }

    void display2()
    {
        cout << tittle << "\t\t" << author << "\t\t" << publisher << "\t\t" << *stock << "\t\t" << *price << "\n";
    }
    void transaction()
    {
        display();
        int qty;
        cout << "Enter the number of copies you wanna buy" << endl;
        cin >> qty;
        if (qty <= *stock)
        {
            cout << "Transaction complete" << endl;
            cout << "Total cost:" << qty * (*price);
            *stock = *stock - qty;
            succesfull_transaction++;
        }
        else
        {
            cout << "Required copies are not in stock" << endl;
            failed_transaction++;
        }
    }
    int search(string Tittle, string Author)
    {
        if (tittle == Tittle && author == Author && *stock > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void display_tranactions()
    {
        cout << "Successful transactions: " << succesfull_transaction << endl;
        cout << "Failed transactions: " << failed_transaction << endl;
    }
    ~books()
    {
        cout << "Objects destroyed" << endl;
        delete price;
        delete stock;
    }
};
int books::succesfull_transaction = 0;
int books::failed_transaction = 0;

void Search(string book, string ath, books obj[])
{
    int found = 0, i = 0;
    for (; i < book_count; i++)
    {
        if (obj[i].search(book, ath) == 1)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "BOOK is available" << endl;
        obj[i].transaction();
    }
    else
    {
        cout << "Sorry this book is currently not available" << endl;
    }
}

void update(string book, double prc, books b[])
{
    int i = 0, flag = 0;
    for (; i < book_count; i++)
    {
        if (b[i].tittle == book)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        change_price(b[i], prc);
    }
    else
    {
        cout << "Incorrect details" << endl;
    }
}

void inventory(books b[])
{
    cout << "\n###LIST OF BOOKS###\nSrNo.\t\tTitle\t\tAuthor\t\tPublish\t\tStock\t\tPrice\n";
    for (int i = 0; i < book_count; i++)
    {
        cout << "[" << i + 1 << "]\t\t";
        b[i].display2();
    }
}

int main()
{

    books b[10];
    books b1 = books("Cosmos", "Sagan", "SK", 500, 5);
    b[0] = b1;
    int flag = 0;
    string book_name, author_name, pub;
    int stk, choice;
    double prc;

    while (flag == 0)
    {
        cout << "\n\n\t\tMENU"
             << "\n1. Buy a book"
             << "\n2. Edit price of Book"
             << "\n3. Show transaction details"
             << "\n4. Inventory"
             << "\n5. Add new books"
             << "\n6. Exit\n\n";
        cout << "ENTER CHOICE:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the name of the book: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, book_name);
            cout << "Enter the name of the author:" << endl;
            cin.clear();
            cin.sync();
            getline(cin, author_name);
            Search(book_name, author_name, b);
            break;
        }

        case 2:
        {
            cout << "Enter the name of the book: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, book_name);
            cout << "Enter price" << endl;
            cin >> prc;
            update(book_name, prc, b);
            break;
        }
        case 3:
        {
            b[0].display_tranactions();
            break;
        }
        case 4:
            inventory(b);
            break;
        case 5:
        {
            cout << "Enter the name of the book: " << endl;
            cin.clear();
            cin.sync();
            getline(cin, book_name);
            cout << "Enter the name of the author:" << endl;
            cin.clear();
            cin.sync();
            getline(cin, author_name);
            cout << "Enter the name of the publisher:" << endl;
            cin.clear();
            cin.sync();
            getline(cin, pub);
            cout << "Enter the price of book:" << endl;
            cin >> prc;
            cout << "Enter the number of books to be added" << endl;
            cin >> stk;
            b[book_count].enter_bookDetails(book_name, author_name, pub, prc, stk);
            cout << "BOOK has been succesfully added" << endl;
            break;
        }
        case 6:
            flag = 1;
            break;
        }
    }
}