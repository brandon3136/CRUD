#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string itemFile = "Items.txt";

struct ItemStructure {
    string itemId;
    string name;
    string price;
};

void saveItem(const vector<ItemStructure> &item);
vector<ItemStructure> loadItems();
void createItem();

int main(){
    cout << "CRUD PROGRAM" << endl;

    int choice = 0;
    do{
        cout << "---- Main Menu ----- " << endl;
        cout << "1. Create an Item" << endl;
        cout << "2. Read an Item" << endl;
        cout << "3. Update an Item" << endl;
        cout << "4. Delete an Item" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch(choice){
            case 1:
                createItem();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            Default:
                cout << "wrong input" << endl;
                break;
        }

    } while (choice != 5);
}

void createItem(){
    vector<ItemStructure> item;
    ItemStructure i;
    cout << "\n---- Creating an Item -----" << endl;

    cout << "Enter the name of the item: ";
    getline(cin, i.name);

    cout << "Enter the Id of the Item: ";
    getline(cin, i.itemId);

    cout << "Enter the price of the Item: ";
    getline(cin, i.price);

    item.push_back(i);
    saveItem(item);
    
}