#include<iostream> 
using namespace std;

class Personne{
  private:
      string nom ;
      string prenom;
  public :
      Personne(string fname,string lname){
        nom=fname;
        prenom= lname;
      }
      string getNom(){ return nom; }
      void setNom(string n){ nom=n;}
      string getPrenom(){ return prenom; }
      void setPrenom(string pn){ prenom=pn;}
      
      virtual void  affiche(){
        cout<<"bonjour "<< nom <<" "<< prenom <<endl;
      }

};
class Chercheur{
  private:
      string domaineRecherche;
  public :
      Chercheur(string d):domaineRecherche(d){};
      string getDomaineRechereche(){return  domaineRecherche;}
      void setDomaineRecherche(string dr){domaineRecherche=dr;}
      virtual void  afficher(){
             cout<<"Votre domaine de recherche est : "<<domaineRecherche<<endl;

  }
};
class  Enseignantchercheur : public Personne,public Chercheur{
  public:
  Enseignantchercheur(string n,string pn ,string d):Personne(n,pn),Chercheur(d){
    cout<<"constructeur de  EnseignantChercheur appele"<<endl;
  }
    
};

int main(){
  Enseignantchercheur e ("Salma","laouy","informatique ");
  e.Chercheur::afficher();
  e.Personne::affiche();
  return 0;
}