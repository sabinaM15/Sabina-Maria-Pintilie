#include <iostream>
#include <math.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Nod
{
private:
	int info;
	Nod *prev;
	Nod *next;
public:
	Nod(int, Nod*, Nod*);
  ~Nod();
	void set_info(int);
	void set_prev(Nod *);
	void set_next(Nod *);
	int get_info(){ return this->info; }
	Nod *get_prev(){ return this->prev; }
	Nod *get_next(){ return this->next; }
	void citire(istream &in);
	void afisare(ostream &out);
	friend istream& operator>>(istream &in, Nod& n);
  friend ostream& operator<<(ostream &out, Nod& n);
	friend class Lista;
};
Nod::Nod(int info = 0, Nod*prev = NULL, Nod*next = NULL){
  this->info = info;
  this->prev = prev;
  this->next = next;
}
Nod::~Nod(){
this->info = 0;
this->prev = NULL;
this->next = NULL;
}
void Nod::set_info(int x){
  info=x;
  }
void Nod::set_prev(Nod *x){
  prev=x;
}
void Nod::set_next(Nod *x){
  next=x;
}/*
void Nod::citire(istream &in){
  in>>info;
  next = NULL;
  prev = NULL;
}
istream& operator>>(istream& in,Nod& prim){
    prim.citire(in);
    return in;
}*/
///=================================================================
class Lista
{
private:
	Nod *prim = new Nod;
	Nod *ultim = new Nod;
public:
	Lista();
	Lista(Lista&);
	~Lista();
	void citire(istream &in);
	void afisare(ostream &out);
	friend istream& operator>>(istream &in, Lista& l);
  friend ostream& operator<<(ostream &out, Lista& l);
	void inserare(int x);
	void printare();
	void stergere(int);
	void stergere_final();
	void stergere_inceput();
	void inserare_noua(int, int);
};
Lista::Lista(){
  prim->set_info(0);
  prim->set_prev(NULL);
  prim->set_next(NULL);

  ultim->set_info(0);
  ultim->set_prev(NULL);
  ultim->set_next(NULL);
}
Lista::Lista(Lista &l){
  l.prim->set_info(prim->get_info());
  l.prim->set_prev(prim->get_prev());
  l.prim->set_next(prim->get_next());
}
Lista::~Lista(){
  prim->set_info(0);
  prim->set_prev(NULL);
  prim->set_next(NULL);

  ultim->set_info(0);
  ultim->set_prev(NULL);
  ultim->set_next(NULL);
}
void Lista::citire(istream &in){
  Nod *n = new Nod;
  in>>n->info;
}
istream& operator>>(istream& in,Lista& l){
    l.citire(in);
    return in;
}
void Lista::afisare(ostream &out){
  Nod *n = new Nod;
  out<<n->info;
}
ostream& operator<<(ostream& out, Lista&l){
    l.afisare(out);
    return out;
}

void Lista::inserare(int x){
		Nod *n=new Nod;
		n->set_info(x);
		n->set_next(NULL);
		n->set_prev(NULL);
    if(prim->get_info()==NULL){
      prim = n;
      ultim = prim;
    }
    else{
      ultim->set_next(n);
      n->set_prev(ultim);
      ultim = n;
    }
}
void Lista::printare(){
  cout<<"Lista de la stanga la dreapta:"<<endl;
		Nod *x=prim;
		while(x!=NULL)
		{
			cout<<x->get_info()<<" ";
			x=x->get_next();
		}
		cout<<endl;
		cout<<"Lista de la dreapta la stanga:"<<endl;
		Nod *y=ultim;
		while(y!=NULL){
      cout<<y->info<<" ";
      y = y->get_prev();
    }
}
void Lista::inserare_noua(int k, int x){
  Nod *r = prim;
  for(int i=0; i<k-1; k++)
    r=r->get_next();
  Nod *p = new Nod;
  p->set_info(x);
  p->set_next(r->get_prev());
  (r->get_next())->set_prev(p);
  p->set_prev(r);
  r->set_next(p);
}
void Lista::stergere(int k){
  Nod*r=prim;
  for(int i=0; i<k-2; i++)
    r=r->get_next();
  Nod *t= r->get_next();
  ((r->get_next())->get_next())->set_prev(r);
  r->set_next((r->get_next())->get_next());
  delete t;
}
void Lista::stergere_inceput(){
   Nod *t=prim;
    prim = prim->get_next();
    prim->set_prev(NULL);
    delete t;
  }

void Lista::stergere_final(){
  ultim = ultim->get_prev();
  Nod *t= ultim->get_next();
  ultim->set_next(NULL);
  delete t;
}

void menu_output()
{
    printf("\n PINTILIE SABINA, grupa 211 - Proiect nr. 7: Lista dublu inlantuita \n");
    printf("\n\t MENIU:");
    printf("\n===========================================\n");
    printf("\n");
    printf("1. Actiune 1: construirea listei."); printf("\n");
    printf("2. Actiune 2: afisarea listei."); printf("\n");
    printf("3. Actiune 3: inserare unui nod pe o anumita pozitie."); printf("\n");
    printf("4. Actiune 4: stergerea unui nod de pe o anumita pozitie."); printf("\n");
    printf("5. Actiune 5: concatenarea a doua liste."); printf("\n");
    printf("0. Iesire."); printf("\n");
}
void menu()
{
    int nr,k;
    int x;
    Lista l1;
    int option, ok=0;///optiunea aleasa din meniu
    option=0;

    do{
        menu_output();
        printf("\nIntroduceti numarul actiunii: ");
        scanf("%d", &option);
        if (option==1){
          printf("Introduceti numarul de noduri:");printf("\n");
          cin>>nr;
          printf("Introduceti fiecare nod:");
          for(int i=0; i<nr; i++){
              cin>>x;
              l1.inserare(x);
              ok=1;
           }
        }
        if (option==2){
          if(ok==0){
            printf("\nPentru a selecta aceasta optiune trebuie sa selectati, mai intai, optiunea 1.");
          }
          else
            //cout<<n;
            l1.printare();
        }
        if (option==3){
            if(ok==0){
              printf("\nPentru a selecta aceasta optiune trebuie sa selectati, mai intai, optiunea 1.");
              }
            else{
              cout<<"Introduceti pozitia:";
              cin>>k;
              cout<"Introduceti elementul:";
              cin>>x;
              l1.inserare_noua(k,x);
            }
        }

        if (option==4){
            if(ok==0){
              printf("\nPentru a selecta aceasta optiune trebuie sa selectati, mai intai, optiunea 1.");
            }
            else{
              printf("Introduceti pozitia de pe care doriti sa stergeti elementul:");
              cin>>k;
              if(k==1)
                l1.stergere_inceput();
              if(k==nr)
                  l1.stergere_final();
              else
                l1.stergere(k);

            }
        }
        if (option==5)
        {
            Lista l2(l1);
            l2.printare();
        }
        if (option==0)
        {
            printf("\nEXIT!\n");
        }
        if (option<0||option>5)
        {
            printf("\nSelectie invalida\n");
        }
        printf("\n");
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main()
{
    menu();
    return 0;
}

