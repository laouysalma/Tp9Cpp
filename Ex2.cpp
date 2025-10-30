#include<iostream>
using namespace std ;

class Technicien{
    private:
       double salaireT;
    public:
        int getSalaire(){return salaireT;}
        void setSalaire(int salaire){ salaire =salaire;}
        Technicien (int s):salaireT(s){};
        virtual void afficherSalaire(){
            cout<<" bonjour technicien votre salaire est : "<<salaireT<<" dh"<<endl;
        }
};
class Comptable{
    private:
       double salaireC;
    public:
        int getSalaire(){return salaireC;}
        void setSalaire(int salaire){ salaire =salaire;}
        Comptable (int s):salaireC(s){};
        virtual void afficherSalaire(){
            cout<<" bonjour comptable votre salaire est : "<<salaireC<<" dh"<<endl;
        }
};
class EmployePolyvalent : public Technicien,public Comptable{
    public :
        EmployePolyvalent(double st,double sc):Technicien(sc),Comptable(st){};  
         
        void afficherTousSalaires(){
            Technicien::afficherSalaire();
            Comptable::afficherSalaire();
        }
        
};
int main(){
    EmployePolyvalent e(130.33,12300.40);
    e.afficherTousSalaires();
    e.Comptable::afficherSalaire();
    e.Technicien::afficherSalaire();

}