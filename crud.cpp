#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string itemFile = "Items.txt";

struct ItemStructure
{
    string itemId;
    string name;
    int price;
};

void saveItem(const vector<ItemStructure> &item);
vector<ItemStructure> loadItems();
void createItem();
void readItem();

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

void createItem()
{
    vector<ItemStructure> item;
    ItemStructure i;
    cout << "\n---- Creating an Item -----" << endl;

    cout << "Enter the name of the item: ";
    getline(cin, i.name);

    cout << "Enter the Id of the Item: ";
    getline(cin, i.itemId);

    cout << "Enter the price of the Item: ";
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
    cout << "Item saved successfully" << endl;
}

vector<ItemStructure> loadItems(){
    ifstream file(itemFile);
    vector<ItemStructure> item;
    string line;

    if(file.is_open()){
        ItemStructure i;
        while(getline(file, line)){
            if(line == "---"){
                item.push_back(i);
                i = ItemStructure();
                continue;
            }

            else if(i.name.empty()){
                i.name = line;
            }
            else if(i.itemId.empty()){
                i.itemId = line;
            }
            else{
                i.price = stoi(line);
            }
            
        }
        
    }
    return item;
}


void readItem(){
    vector<ItemStructure> item = loadItems();
    int count = 1;

    cout << "\n---- Reading Items ----" << endl;

    cout << left << setw(5) << "S\\N"
    << setw(15)<<"Item name"
    <<setw(10)<<"Item Price"
    <<setw(10)<<"Item Id";
    for(const auto &i : item){
        cout << left << setw(5) << count
             << setw(15) << i.name
             << setw(10) << i.price
             << setw(10) << i.itemId;
        count += 1;
    }
    cout << "--- End of the Items ---" << endl;
}