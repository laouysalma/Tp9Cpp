#include <iostream>
using namespace std;

class Vehicul {
protected:
    string marque;
    string model;
public:
    Vehicul(string mr, string mo) : marque(mr), model(mo) {}
    virtual void afficherCaracteristiques() {
        cout << "Vehicule de la marque : " << marque << ", modele : " << model << endl;
    }
};

class Thermique : virtual public Vehicul {
protected:
    double conso_carburant;
public:
    Thermique(double t) : Vehicul("", ""), conso_carburant(t) {}
    void afficherCaracteristiques() override {
        cout << "Vehicule thermique avec consommation carburant = " << conso_carburant << " L/100km" << endl;
    }
};

class Electrique : virtual public Vehicul {
protected:
    double batterie;
public:
    Electrique(double b) : Vehicul("", ""), batterie(b) {}
    void afficherCaracteristiques() override {
        cout << "Vehicule electrique avec autonomie batterie = " << batterie << " heures" << endl;
    }
};

class Hybride : public Thermique, public Electrique {
public:
    Hybride(string mar, string md, double th, double el)
        : Vehicul(mar, md), Thermique(th), Electrique(el) {}

    void afficherCaracteristiques() override {
        Vehicul::afficherCaracteristiques();
        Thermique::afficherCaracteristiques();
        Electrique::afficherCaracteristiques();
    }
};

int main() {
    Hybride h("Toyota", "2015", 7.5, 10);
    h.afficherCaracteristiques();
    return 0;
}
