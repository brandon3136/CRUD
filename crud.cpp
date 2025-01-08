#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// global variable for a file
const string itemFile = "Items.txt";


// structure of the item
struct ItemStructure
{
    string itemId;
    string name;
    int price;
};

// function prototypes
void saveItem(const vector<ItemStructure> &item);
vector<ItemStructure> loadItems();
void createItem();
void readItem();
void deleteItem();
void updateItem();

int main()
{
    cout << "CRUD PROGRAM" << endl;

    int choice = 0;
    do
    {
        cout << "---- Main Menu ----- " << endl;
        cout << "1. Create an Item" << endl;
        cout << "2. Read an Item" << endl;
        cout << "3. Update an Item" << endl;
        cout << "4. Delete an Item" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createItem();
            break;
        case 2:
            readItem();
            break;
        case 3:
            updateItem();
            break;
        case 4:
            deleteItem();
            break;
        case 5:
            cout << "Thank you for using my program" << endl;
            break;
        Default:
            cout << "wrong input" << endl;
            break;
        }

    } while (choice != 5);
}

void createItem()
{
    vector<ItemStructure> item = loadItems();
    ItemStructure i;
    cout << "\n---- Creating an Item -----" << endl;

    cout << "Enter the name of the item: ";
    cin.ignore();
    getline(cin, i.name);

    cout << "Enter the Id of the Item: ";
    getline(cin, i.itemId);

    cout << "Enter the price of the Item: $";
    cin >> i.price;

    item.push_back(i);
    saveItem(item);
}

void saveItem(const vector<ItemStructure> &item)
{
    ofstream file(itemFile, ios::trunc);

    if (file.is_open())
    {
        for (const auto &i : item)
        {
            file << i.name << endl;
            file << i.itemId << endl;
            file << i.price << endl;
            file << "---" << endl; // a delemiter
        }
    }
    file.close();
}

vector<ItemStructure> loadItems()
{
    ifstream file(itemFile);
    vector<ItemStructure> item;
    string line;

    if (file.is_open())
    {
        ItemStructure i;
        while (getline(file, line))
        {
            if (line == "---")
            {
                item.push_back(i);
                i = ItemStructure();
                continue;
            }

            else if (i.name.empty())
            {
                i.name = line;
            }
            else if (i.itemId.empty())
            {
                i.itemId = line;
            }
            else
            {
                i.price = stoi(line);
            }
        }
    }
    return item;
}

void readItem()
{
    vector<ItemStructure> item = loadItems();
    int count = 1;
    if (!item.empty())
    {
        cout << "\n\t\t---- Reading Items ----\n"
             << endl;

        cout << left << setw(5) << "S\\N"
             << setw(15) << "Item name"
             << setw(15) << "Item Price"
             << setw(10) << "Item Id" << endl;
        for (const auto &i : item)
        {
            cout << left << setw(5) << count
                 << setw(15) << i.name << "$"
                 << setw(15) << i.price
                 << setw(10) << i.itemId << endl;
            count += 1;
        }
        cout << "\n\t\t--- End of the Items ---\n\n"
             << endl;
    }
    else
    {
        cout << "Item data not found can't display items\n"
             << endl;
    }
}

void deleteItem()
{
    readItem();
    cout << "\n\t\t--- Deleting an item ---" << endl;
    vector<ItemStructure> item = loadItems();

    if (!item.empty())
    {
        string nameOrId;
        bool found = false;
        cout << "Enter the name or the Id of the item you want to delete: ";
        cin.ignore();
        getline(cin, nameOrId);
        for (auto i = item.begin(); i != item.end(); i++)
        {
            if ((i->name == nameOrId) || (i->itemId == nameOrId))
            {
                found = true;
                item.erase(i);
                saveItem(item);
                cout << "Item deleted" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "The item was not found" << endl;
        }
    }
}

void updateItem()
{
    readItem();
    cout << "\n\t\t--- Updating an item ---" << endl;
    vector<ItemStructure> item = loadItems();

    if (!item.empty())
    {
        string nameOrId;
        bool found = false;
        cout << "Enter the name or the Id of the item you want to update: ";
        cin.ignore();
        getline(cin, nameOrId);
        for (auto i = item.begin(); i != item.end(); i++)
        {
            if ((i->name == nameOrId) || (i->itemId == nameOrId))
            {
                found = true;
                item.erase(i);
                saveItem(item);
                createItem();
                cout << "Item updated" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "The item was not found" << endl;
        }
    }
}