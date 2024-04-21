#ifndef ZS
#define ZS

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Produkty
{
private:
    int cena;
public:
    Produkty(int cena) : cena(cena) {}
    virtual ~Produkty() = default;
    virtual void print(ostream& os) = 0;
    int getcena() {return cena;}
};

class Chemia : public Produkty
{
private:
    int waga;
public:
    Chemia(int cena, int waga) : Produkty(cena), waga(waga) {}
    ~Chemia() {cout<<"\n~Chemia";}
    void print(ostream& os)
    {
        os<<"\nChemia: cena - "<<getcena()<<"\nWaga produktu: "<<waga<<endl;
    }
};

class Sportowe : public Produkty
{
private:
    string producent;
public:
    Sportowe(int cena, string producent) : Produkty(cena), producent(producent) {}
    ~Sportowe() {cout<<"\n~Sportowe";}
    void print(ostream& os)
    {
        os<<"\nSportowe: cena - "<<getcena()<<"\nProducent: "<<producent<<endl;
    }
};

///KOSZYK

class Koszyk
{
private:
    int id;
    vector<Produkty*>kosz;
public:
    Koszyk(int id) : id(id) {}
    ~Koszyk() = default;
    void operator+=(Produkty* p)
    {
        kosz.push_back(p);
    }

    void operator-=(int index)
    {
        kosz.erase(kosz.begin()+index);
    }

    friend ostream& operator<<(ostream& os, const Koszyk& k)
    {
        cout<<"\nID klienta: "<<k.id<<endl;

        for(auto* p : k.kosz)
        {
            p->print(os);
            os<<endl;
        }
        return os;
    }

    void suma()
    {
        int wynik=0;

        for(auto* p : kosz)
        {
            wynik+=p->getcena();
        }
        cout<<"\nWartosc zakupow: "<<wynik<<" zlotych"<<endl;
    }
};

#endif // ZS
