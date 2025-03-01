/*#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> rep;
    element : pair<string, int> contact;
    while(1)
    {
        cout << "Tapez le nom : ";
        cin >> element;
    }
}*/

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    map<string, int> rep =
    {
        {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6}
    };
    string nom;
    int numero;
    while (true)
    {
        cout << "Tapez le nom (ou 'fin' pour quitter) : ";
        cin >> nom;

        if (nom == "fin") 
        {
            break;
        }
        else if (nom == "/recherchenom")
        {
            string search;
            int tkt = 0;
            cout << "Tapez le nom : ";
            cin >> search;
            for (const auto &entry : rep)
            {
                if (entry.first == search)
                {
                    cout << "Nom : " << entry.first << ", Numéro : " << entry.second << endl;
                    tkt++;
                }
            }
            if (!tkt)
            {
                cout << "Non trouvé" << endl;
            }
        }
        else if (nom == "/recherchenum")
        {
            int search;
            int tkt2 = 0;
            cout << "Tapez le num : ";
            cin >> search;
            for (const auto &entry : rep)
            {
                if (entry.second == search)
                {
                    cout << "Nom : " << entry.first << ", Numéro : " << entry.second << endl;
                    tkt2++;
                }
            }
            if (!tkt2)
            {
                cout << "Non trouvé" << endl;
            }
        }
        else if (nom == "/suppr")
        {
            string suppr;
            cout << "Tapez le nom : ";
            cin >> suppr;
            rep.erase[suppr];
        }
        else
        {
            cout << "Tapez le numéro : ";
            cin >> numero;
            rep[nom] = numero;
            // à faire avec insert aussi
            cout << "Contact ajouté : " << nom << " -> " << numero << endl;
            cout << "Il y a maintenant " << rep.size() << " enregistrement(s)" << endl;
        }
    }

    cout << "\nRépertoire :\n";
    for (const auto &entry : rep)
    {
        cout << "Nom : " << entry.first << ", Numéro : " << entry.second << endl;
    }
    return 0;
}
