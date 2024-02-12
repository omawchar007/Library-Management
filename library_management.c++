#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Book {
    std::string name;
    std::string author;
    std::string genre;
    int quantity;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Info {
    std::string name;
    int age;
    Book book; 
    Date date;
};

void CheckOutBook(int index, Book Books[], vector<Info> &customers) {
    cout << endl;
    cout << "================================== Check Out Book ==================================" << endl;

    Info customer;
    cout << "Enter the name: ";
    cin >> customer.name;
    cout << "Enter the age: ";
    cin >> customer.age;

    cout << "Enter Today's Date" << endl;
    do {
        cout << "Day - ";
        cin >> customer.date.day;
        cout << "Month - ";
        cin >> customer.date.month;
        cout << "Year - ";
        cin >> customer.date.year;

        if (cin.fail() || customer.date.day < 1 || customer.date.day > 31 ||
            customer.date.month < 1 || customer.date.month > 12 || customer.date.year < 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid date. Please enter a valid date." << endl;
        } else {
            break;
        }
    } while (true);

    cout << "Select a book to check out:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << " -> " << endl;
        cout << "Title - " << Books[i].name << endl;
        cout << "Author - " << Books[i].author << endl;
        cout << "Genre - " << Books[i].genre << endl;
        cout << "Quantity - " << Books[i].quantity << endl;
        cout << "----------------------------------------------------------------------------" << endl;
    }

    int bookIndex;
    do {
        cout << "Enter the book index: ";
        cin >> bookIndex;

        if (cin.fail() || bookIndex < 0 || bookIndex >= 10 || Books[bookIndex].quantity <= 0) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid book selection. Please enter a valid index." << endl;
        } else {
            break;
        }
    } while (true);

    Books[bookIndex].quantity--;
    customer.book = Books[bookIndex];
    customers.push_back(customer);

    cout << "Book checked out successfully!" << endl;
    cout << "Note: Please return this book before " << customer.date.day + 10 << "-" << customer.date.month << "-"
         << customer.date.year << endl;
}

void CheckInBook(int index, Book Books[], vector<Info> &customers) {
    string name;
    cout << endl;
    cout << "================================== Check In Book ==================================" << endl;
    cout << "Enter The Name : ";
    cin >> name;

    bool found = false;

    transform(name.begin(), name.end(), name.begin(), ::tolower);

    // Iterate over all customers in the vector
    for (size_t i = 0; i < customers.size(); i++) {
        string customerNameLower = customers[i].name;
        transform(customerNameLower.begin(), customerNameLower.end(), customerNameLower.begin(), ::tolower);

        if (name == customerNameLower) {
            found = true;
            cout << endl;
            cout << "Hi " << customers[i].name << ", Your Allotted Books is -> " << endl;
            cout << "===============================================================================" << endl;
            cout << "Title - " << customers[i].book.name << endl;
            cout << "Author - " << customers[i].book.author << endl;
            cout << "Genre - " << customers[i].book.genre << endl;
            cout << "Quantity - " << customers[i].book.quantity << endl;
            cout << "----------------------------------------------------------------------------" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Error: Name Not Found!" << endl;
    }
}


void Pending(int index, Book Books[], vector<Info> &customers) {
    cout << endl;
    cout << "================================== All Pending Returning ==================================" << endl;
    if (!customers.empty()) {
        // Iterate over all customers in the vector
        for (int i = 0; i < customers.size(); i++) {
            cout << "Customer Name -> " << customers[i].name << endl;
            cout << "Book Title    -> " << customers[i].book.name << endl;
            cout << "Date          -> " << customers[i].date.day << "-" << customers[i].date.month << "-"
                 << customers[i].date.year << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
        }
    } else {
        cout << "No pending returns." << endl;
    }
}


int main(){
    int index = 0;
    const int numOfBooks = 10;
    Book Books[numOfBooks] = {
        {"Rich Dad Poor Dad", "Robert Kiyosaki", "Personal Finance", 5},
        {"The Immortals of Meluha", "Amish Tripathi", "Mythological Fiction", 3},
        {"The God of Small Things", "Arundhati Roy", "Fiction", 8},
        {"The White Tiger", "Aravind Adiga", "Contemporary Fiction", 6},
        {"My Experiments with Truth", "Mahatma Gandhi", "Autobiography", 10},
        {"Wings of Fire", "A.P.J. Abdul Kalam", "Autobiography", 4},
        {"Train to Pakistan", "Khushwant Singh", "Historical Fiction", 7},
        {"The Guide", "R.K. Narayan", "Fiction", 2},
        {"Five Point Someone", "Chetan Bhagat", "Contemporary Fiction", 9},
        {"The Discovery of India", "Jawaharlal Nehru", "History", 5}
    };

    Date Date;
    vector<Info> customers;
    
    int choice;

    do {
        cout << endl;
        cout << "================================== Library Management ==================================" << endl;
        cout << "1 -> Check Out Book" << endl;
        cout << "2 -> Check In Book" << endl;
        cout << "3 -> All Pending Returning" << endl;
        cout << "4 -> Book's Menu" << endl;
        cout << "5 -> Exit" << endl;
        cout << "Enter Your Choice = ";
        cin >> choice;

        switch (choice) {
            case 1:
                CheckOutBook(index, Books, customers);
                break;

            case 2:
                CheckInBook(index , Books , customers);
                break;

            case 3:
                Pending(index , Books , customers);
                break;

            case 4:
                cout << endl;
                cout << "================================== Book's Menu ==================================" << endl;
                for (int i = 0; i < 10; i++) {
                    cout << endl;
                    cout << "=====================     " << i+1 << "     ================="<<endl;
           cout<<endl;
            cout<<"Book Title    : "<<Books[i].name<<endl;
            cout<<"Book Author   : "<<Books[i].author<<endl;
            cout<<"Book Genre    : "<<Books[i].genre<<endl;
            cout<<"Book Quantity : "<<Books[i].quantity<<endl;
        }
        cout << "----------------------------------------------------------------------------------" << endl;
        
        break;

        default:
        cout<<endl;
        cout<<"Wrong Opction Selected"<<endl;
            break;
        }

        

    } while (choice != 5);
}
