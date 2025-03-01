#include <iostream>
using namespace std;

/*
struct :
un nom, prénom, identifiant, tel, mail
manipulation d'une liste de membres :
afficher, ajouter un membre, identifier, supprimer, supprimer tous les membres
essayer avec un vecteur pour la liste de membres
*/

struct Member
{
    char fname[32];
    char lname[32];
    int id;
    char num[13];
    char mail[32];
};


void print_mem(Member mem)
{
    cout << "This is you member :" << endl;
    cout << mem.fname << endl;
    cout << mem.lname << endl;
    cout << mem.id << endl;
    cout << mem.num << endl;
    cout << mem.mail << "\n" << endl;
}

void print_list(Member* list, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Member number " << i << " :" << endl;
        cout << "Name : " << list[i].fname << endl;
        cout << "Last name : " << list[i].lname << endl;
        cout << "Id : " << list[i].id << endl;
        cout << "Phone : " << list[i].num << endl;
        cout << "Mail : " << list[i].mail << "\n" << endl;
    }
}

void add_mem(Member* list, int size)
{
    Member new_mem;
    cout << "Enter the first name of your member" << endl;
    cin >> new_mem.fname;
    cout << "Enter the last name of your member" << endl;
    cin >> new_mem.lname;
    cout << "Enter the id of your member" << endl;
    cin >> new_mem.id;
    cout << "Enter the phone number of your member" << endl;
    cin >> new_mem.num;
    cout << "Enter the mail of your member" << endl;
    cin >> new_mem.mail;
    list[size] = new_mem;
    cout << "\n" << new_mem.fname << " " << new_mem.lname << " has been added to the club.\n" << endl;
}

void del_mem(Member* list, int& size, int id) 
{
    for (int a = 0; a < 2; a++)
    {
        for (int i = 0; i < size; i++)
        {
            if (list[i].id == id)
            {
                size--; 
                for (int j = i; j < size; j++)
                {
                    list[j] = list[j + 1];
                }
            }
        }
    }
    cout << "The member with id " << id << " got deleted from the list." << endl;
}

void del_list(Member* list, int& size) 
{
    for (int i = 0; i < size; i++)
    {
        size--; 
        for (int j = i; j < size; j++)
        {
            list[j] = list[j + 1];
        }
    }
    cout << "List cleared." << endl;
}

int main()
{
    Member directory[10];
    int actual_size = 0;

    /*--------------------- Menu ---------------------*/
    int choice = -1;
    while (choice != 0)
    {
        cout << "What do you want to do ?" << endl;
        cout << "1 - Print member" << endl;
        cout << "2 - Print list of members" << endl;
        cout << "3 - Add member" << endl;
        cout << "4 - Delete member" << endl;
        cout << "5 - Delete list" << endl;
        cout << "0 - Quit" << endl;
        cin >> choice;
        while (choice < 0 && choice > 4)
        {
            cout << "Invalid choice, please retry with a valid one : " << endl;
            cout << "1 - Print member" << endl;
            cout << "2 - Print list of members" << endl;
            cout << "3 - Add member" << endl;
            cout << "4 - Delete member" << endl;
            cout << "5 - Delete list" << endl;
            cout << "0 - Quit" << endl;
            cin >> choice;
        }
        switch (choice)
        {
        case 0:
            cout << "You have left this code." << endl;
            break;

        case 1:
            int number;
            cout << "Enter the index of the member (from 0)." << endl;
            cin >> number;
            print_mem(directory[number]);
            break;

        case 2:
            print_list(directory, actual_size);
            break;

        case 3:
            add_mem(directory, actual_size);
            actual_size++;
            break;

        case 4:
            int id;
            cout << "Enter the id of the member you want to errase : ";
            cin >> id;
            del_mem(directory, actual_size, id);
            break;

        case 5:
            bool sure;
            cout << "Are you sure to delete this list (0/1) : ";
            cin >> sure;
            if (sure)
            {
                del_list(directory, actual_size);
            }
            break;

        default:
            break;
        }
    }
}