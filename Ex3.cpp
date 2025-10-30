#include<iostream>
using namespace std;

class Vehicul 
{
private:
    string marque;
    string model;
public:
    Vehicul(string mr,string mo):marque(mr),model(mo){}
    virtual void afficherCaracteristiques(){
        cout <<" cette vehicul est  de la marque : "<<marque<<" model "<<model<<endl;
    }
};
class Thermique
{
 private:
   double conso_carburant;
 public:
    Thermique(double t):conso_carburant(t){}
    virtual void afficherCaracteristiques(){
    cout <<"vehicul thermique  avec consommation de  carburant = "<<conso_carburant<<endl;
    }  
};
class Electrique
{
 private:
   double batterie;
 public:
 Electrique(double b):batterie(b){}
    virtual void afficherCaracteristiques(){
    cout <<"vehicul Electrique  avec etat de  batterie = "<<batterie<<" heure"<<endl;
    } 
};
class Hybride  : public Thermique,public Electrique,public Vehicul
{
public:
  Hybride(string mar ,string md,double th,double el):Vehicul(mar,md),Thermique(th),Electrique(el){}
};
int main (){
    Hybride h("Totoya","2015",1500,17);
    h.Vehicul::afficherCaracteristiques();
    h.Thermique::afficherCaracteristiques();
    h.Electrique::afficherCaracteristiques();
}
