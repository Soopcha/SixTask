#include <iostream>
#include <string>
using namespace std;

const int MAX_DESSERTS = 100;

struct Dessert {
    string name;
    double price;
    int calories;
};

void addDessert(Dessert desserts[], int& count) {
    if (count == MAX_DESSERTS) {
        cout << "Error: database is full." << endl;
        return;
    }

    Dessert dessert;
    cout << "Enter dessert name: ";
    cin >> dessert.name;
    cout << "Enter dessert price: ";
    cin >> dessert.price;
    cout << "Enter dessert calories: ";
    cin >> dessert.calories;

    desserts[count] = dessert;
    count++;

    cout << "Dessert added to database." << endl;
}

void removeDessert(Dessert desserts[], int& count) { // если есть функции, которые относятся к нескольким структурам, 
    //то лучше определить их вне структур.
    if (count == 0) {
        cout << "Error: database is empty." << endl;
        return;
    }

    string name;
    cout << "Enter dessert name to remove: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (desserts[i].name == name) {
            desserts[i] = desserts[count - 1];
            count--;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Dessert removed from database." << endl;
    }
    else {
        cout << "Error: dessert not found in database." << endl;
    }
}

void printDesserts(Dessert desserts[], int count) {
    if (count == 0) {
        cout << "Database is empty." << endl;
        return;
    }

    cout << "Name  Price  Calories" << endl;
    for (int i = 0; i < count; i++) {
        cout << desserts[i].name << "  " << desserts[i].price << "  " << desserts[i].calories << endl;
    }
}

int main() {
    Dessert desserts[MAX_DESSERTS];
    int count = 0;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add dessert" << endl;
        cout << "2. Remove dessert" << endl;
        cout << "3. Print desserts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addDessert(desserts, count);
            cout << endl;
            break;
        case 2:
            removeDessert(desserts, count);
            cout << endl;
            break;
        case 3:
            printDesserts(desserts, count);
            cout << endl;
            break;
        case 4:
            cout << "Exiting program." << endl;
            cout << endl;
            break;
        default:
            cout << "Error: invalid choice." << endl;
            cout << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
