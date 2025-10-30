#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
protected:
    int id;
    string login;
public:
    Utilisateur(int i, string l) : id(i), login(l) {}
    void afficherUtilisateur() {
        cout << "votre identifiant est : " << id << ", login : " << login << endl;
    }
};

class Administrateur : virtual public Utilisateur {
protected:
    string droits;
public:
    Administrateur(int i, string l, string d) : Utilisateur(i, l), droits(d) {}
    void gererSysteme() {
        cout << "L'administrateur a les  droits : " << droits << endl;
    }
};

class Moderateur : virtual public Utilisateur {
protected:
    int niveau;
public:
    Moderateur(int i, string l, int n) : Utilisateur(i, l), niveau(n) {}
    void modererContenu() {
        cout << "ce modérateur a le  niveau : " << niveau << endl;
    }
};

class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int i, string l, string d, int n)
        : Utilisateur(i, l), Administrateur(i, l, d), Moderateur(i, l, n) {}

    void afficherSuperUtilisateur() {
        afficherUtilisateur();
        gererSysteme();
        modererContenu();
    }
};

int main() {
    int choix, id, niveau;
    string login, droits;

    cout << "Création d'un SuperUtilisateur"<<endl;
    cout << "ID : "; cin >> id;
    cout << "Login : "; cin >> login;
    cout << "Droits d'administrateur : "; cin >> droits;
    cout << "Niveau de modération : "; cin >> niveau;

    SuperUtilisateur su(id, login, droits, niveau);

    su.afficherSuperUtilisateur();

    su.Administrateur::gererSysteme();
    su.Moderateur::modererContenu();
}
