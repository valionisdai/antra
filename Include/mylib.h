#include "globals.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include <execution>
#include <filesystem>
#include <list>

using namespace std;
namespace fs = filesystem;

template <template<typename> class Container>
class Studentas {
    private:
        string vard;
        string pav;
        Container<int> paz;
        int egzas;
        float rez;
        float med;
    public:
        Studentas() : vard(""), pav(""), egzas(0), rez(0.0f), med(0.0f) {}
        
        ~Studentas() {}

        static int mode;

        Studentas(const Studentas& other)
                : vard(other.vard),
        pav(other.pav),
        paz(other.paz),
        egzas(other.egzas),
        rez(other.rez),
        med(other.med)
        {}

        Studentas& operator=(const Studentas& other)
        {
            if (this != &other) {
            vard = other.vard;
            pav = other.pav;
            paz = other.paz;
            egzas = other.egzas;
            rez = other.rez;
            med = other.med;
            }
            return *this;
        }

        Studentas(Studentas&& other) noexcept
            : vard(std::move(other.vard)),
            pav(std::move(other.pav)),
            paz(std::move(other.paz)),
            egzas(std::move(other.egzas)),
            rez(std::move(other.rez)),
            med(std::move(other.med))
            {}

        Studentas& operator=(Studentas&& other) noexcept
        {
            if (this != &other) {
            vard = std::move(other.vard);
            pav = std::move(other.pav);
            paz = std::move(other.paz);
            egzas = std::move(other.egzas);
            rez = std::move(other.rez);
            med = std::move(other.med);
            }
        return *this;
        }

        void setVardas(const string& v) {vard = v;}
        void setVardas(string&& v) {vard = std::move(v);}
        void setPavarde(const string& p) {pav = p;}
        void setPavarde(string&& p) {pav = std::move(p);}
        void addPazymys(int p) {paz.push_back(p);}
        void setEgz(int e) {egzas = e;}
        void setRez(float r) {rez = r;}
        void setMed(float m) {med = m;}

        const string& getVardas() const {return vard;}
        const string& getPavarde() const {return pav;} 
        Container<int>& getPaz() {return paz;}
        const Container<int>& getPaz() const {return paz;}
        int getEgz() const {return egzas;}
        float getRez() const {return rez;}
        float getMed() const {return med;}

        friend ostream& operator<<(ostream& out, const Studentas& temp) {
            out << temp.getVardas() << " " << temp.getPavarde();
            return out;
        }

        friend ifstream& operator>>(ifstream& in, Studentas& temp) {
            in >> temp.vard >> temp.pav;
            return in;
        }
};

template<template<typename> class Container>
Studentas<Container> skaiciuojam(int a);

template<template<typename> class Container>
Container<Studentas<Container>> failas(string failvardas);

template<template<typename> class Container>
void vidurkis(Studentas<Container>& laik, int sum);

template<template<typename> class Container>
void skmediana(Studentas<Container>& laik);

int pazym_gen();
int generuojame();

template <template<typename> class Container>
int Studentas <Container>::mode = 1;

template<template<typename> class Container>
void isvedimas(const Container<Studentas<Container>>& Grupe, string failovardas);

stringstream skaitymas(string failvar);

template <template<typename> class Container>
void rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas);

template<template<typename> class Container>
void dirbam(string nfailas);

template<template<typename> class Container>
void kaip_rusiuojam(Container<Studentas<Container>>& Grupe, string failovardas);

template <template<typename> class Container>
void rikiavimas(Container<Studentas<Container>>& Grupe, string failovardas);
    
template <template<typename> class Container>
void trecia_strat_rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas);

template <template<typename> class Container>
void antra_strat_rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas);

template <template<typename> class Container>
void pirma_strat_rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas);

template<template<typename> class Container>
Studentas<Container> skaiciuojam(int a)
{
    Studentas<Container> laik;
    int sum=0, m, j=0, e;
    string v, p;
    cout << "Iveskite varda:" << endl; cin >> v;
    cout << "Iveskite pavarde:" << endl; cin >> p;
    laik.setVardas(v);
    laik.setPavarde(p);
    if(a==1)
    {
        int kiek;
        cout << "Iveskite pazymiu skaiciu (max 20):" << endl;
        while(true){if(cin >> kiek && kiek>=1 && kiek<=20) break; cout << "Neteisinga ivestis, maksimalus pazym. sk. 20, minimalus 1:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        for(int i=0; i<kiek; i++)
            {
                int pazymiai = pazym_gen();
                laik.addPazymys(pazymiai);
                sum+=pazymiai;
            }

        laik.setEgz(pazym_gen());
        cout << "Issaugota" << endl;
    }
    else
    {
        cout << "Iveskite studento pazymius (iveskite 0, jei baigiate vesti pazymius): " << endl;
        while(true)
            {
                while(true){if(cin >> m && m>=0 && m<=10) break; cout << "Neteisinga ivestis, maksimalus galimas paz. - 10, minimalus 1 (0 jei norite uzbaigti):" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
                if(m==0) break;
                laik.addPazymys(m);
                sum+=m;
                j++;
            }
    cout << "Studento pazymiu skaicius: " << j << endl;
    cout << "Iveskite studento egzamino rezultata: " << endl; cin >> e;
    laik.setEgz(e);
    }
    if(b==1)
        vidurkis(laik, sum);
    if(b==2)
        skmediana(laik);
    if(b==3)
    {
        vidurkis(laik, sum);
        skmediana(laik);
    }
    return laik;
}

template<template<typename> class Container>
void vidurkis(Studentas<Container>& laik, int sum)
{
    size_t n = laik.getPaz().size();
    laik.setRez(laik.getEgz()*0.6 + (n > 0 ? (float)sum/n : 0.0f )*0.4);
}

template<template<typename> class Container>
void skmediana(Studentas<Container>& laik)
{
    int paz_sk = laik.getPaz().size();
    float mediana;
    if(paz_sk == 0)
    {
        mediana = 0.0;
        laik.setMed(laik.getEgz() * 0.6 + mediana * 0.4);
        return;
    }
    auto& paz = laik.getPaz();
    if constexpr (is_same_v<Container<int>,list<int>>)
    {
        paz.sort();
        if (paz_sk == 0)
            mediana = 0.0;
        else
        {
            auto it = paz.begin();
            std::advance(it, paz_sk / 2);
            if (paz_sk % 2 == 0)
            {
                auto it2 = paz.begin();
                std::advance(it2, paz_sk / 2 - 1);
                mediana = (*it + *it2) / 2.0;
            }
            else
                mediana = *it;
        }
    }
    else
    {
        if (paz_sk % 2 == 0)
        {
            nth_element(paz.begin(), paz.begin() + paz_sk / 2 - 1, paz.end());
            int left = paz[paz_sk / 2 - 1];
            nth_element(paz.begin(), paz.begin() + paz_sk / 2, paz.end());
            int right = paz[paz_sk / 2];
            mediana = (left + right) / 2.0;
        }
        else
        {
            nth_element(paz.begin(), paz.begin() + paz_sk / 2, paz.end());
            mediana = paz[paz_sk / 2];
        }
        laik.setMed(laik.getEgz() * 0.6 + mediana * 0.4);
    }
}

template<template<typename> class Container>
Container<Studentas<Container>> failas(string failvardas)
{
    string failvar;
    Container<Studentas<Container>> Grupe;
    failvar = failvardas;
    stringstream buffer = skaitymas("./src/"+failvar);
    string line, z, v, p;
    int k = 0;
    getline(buffer, line);
    istringstream header(line);
    string word;
    while (header >> word) {
        if (word == "Egz.") break;
        k++;
    }
    k -= 2;
    auto startas = chrono::high_resolution_clock::now();
    while (getline(buffer, line))
    {
        if (line.empty()) continue;
        istringstream iss(line);
        Studentas<Container> laik;
        int paz, sum = 0, e;
        iss >> v >> p;
        laik.setVardas(std::move(v));
        laik.setPavarde(std::move(p));
        auto& pazymiai = laik.getPaz();
        if constexpr (std::is_same_v<std::remove_cv_t<std::remove_reference_t<decltype(Grupe)>>,std::vector<Studentas<Container>>>) 
            pazymiai.reserve(k);
        for (int i = 0; i < k; i++) {
            if (!(iss >> paz)) break;
            pazymiai.push_back(paz);
            sum += paz;
        }
        iss >> e;
        laik.setEgz(e);
        if (b == 1) laik.setRez(0.4*(sum/k) + 0.6*e);
        else if (b == 2) skmediana(laik);
        else if (b == 3)
        { laik.setRez(0.4*(sum/k) + 0.6*e); skmediana(laik); }
        Grupe.emplace_back(std::move(laik));
    }
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    cout << "Rezultatu skaiciavimo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;

    return Grupe;
}


template <template<typename> class Container>
void rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas)
{
    Container<Studentas<Container>> blogai;
    if constexpr (std::is_same_v<std::remove_cv_t<std::remove_reference_t<decltype(Grupe)>>,std::list<Studentas<Container>>>)
    {
        auto startas = chrono::high_resolution_clock::now();
        for(auto it=Grupe.begin(); it!=Grupe.end();)
        {
            if(it->getRez() >= 5)
                blogai.splice(blogai.end(), Grupe, it++);
            else ++it;
        }

        auto endas = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = endas - startas;
        cout << "Rusiavimo laikas naudojant list: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;
    }
    else
    {
        auto startas = chrono::high_resolution_clock::now();

        
        auto it = partition(Grupe.begin(), Grupe.end(), [](const auto& s) {return s.getRez() >= 5;});
        blogai.reserve(Grupe.end() - it);
        blogai.insert(blogai.end(), std::make_move_iterator(it), std::make_move_iterator(Grupe.end()));
        Grupe.erase(it, Grupe.end());


        auto endas = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = endas - startas;
        cout << "Rusiavimo laikas naudojant vector: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;
    }

    rikiavimas<Container>(Grupe, "gerai_"+failovardas);
    rikiavimas<Container>(blogai, "blogai_"+failovardas);
}


template<template<typename> class Container>
void isvedimas(const Container<Studentas<Container>>& Grupe, string failovardas)
{
    Studentas<Container>::mode = b;
    bool arfailas = false;
    int kiek = 0;
    
    if(renkames==1) 
        arfailas = true;
    else if(arfailas==false)
        {
            size_t pos = failovardas.find('_');
            std::string result = (pos != std::string::npos) ? failovardas.substr(0, pos) : failovardas;
            cout << "Studentu " << result << " 20 pirmu rezultatu" << endl;
        }
    
    ofstream wr;
    ostringstream oss;
    ostream& isved = arfailas ? static_cast<ostream&>(oss) : cout;

    auto startas = chrono::high_resolution_clock::now();
    isved << setw(21) << right << "Vardas | " << setw(21) << right << "Pavarde | " << setw(21) << right;
    if(b==1) {isved << "Galutinis (Vid.)"  << " | Adresas atmintyje\n" << string(64, '-') << endl;}
            else if(b==2) {isved << "Galutinis (Med.) "  << " | Adresas atmintyje\n" << string(55, '-') << endl;}
            else if(b==3) {isved << "Galutinis (Vid.) | " << setw(21) << right << "Galutinis (Med.)"  << setw(21) << right<<  " | Adresas atmintyje\n" << string(105, '-') << endl;}    
    for(const auto& temp:Grupe) {
        if(!arfailas && kiek++ >=20) break;
        isved << temp << " | " << &temp << endl;
    }

    if(arfailas)
    {
        if(failovardas.find("txt") == std::string::npos)
            failovardas += ".txt";
        failovardas = "rez_"+failovardas;
        wr.open(failovardas);
        wr << oss.str();
        wr.close();
    }
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    if(arfailas)
    cout << "Failo " << failovardas << " rasymo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;
}

template<template<typename> class Container>
void dirbam(string nfailas)
{
    Container<Studentas<Container>> Grupe = failas<Container>(nfailas);
    kaip_rusiuojam<Container>(Grupe, nfailas);
}

template<template<typename> class Container>
void kaip_rusiuojam(Container<Studentas<Container>>& Grupe, string failovardas)
{
    if(f==1)
        pirma_strat_rusiavimas(Grupe, failovardas);
    else if(f==2)
        antra_strat_rusiavimas(Grupe, failovardas);
    else if(f==3)
        trecia_strat_rusiavimas(Grupe, failovardas);
    else if(f==4)
        rusiavimas(Grupe, failovardas);
}

template <template<typename> class Container>
void rikiavimas(Container<Studentas<Container>>& Grupe, string failovardas)
{
        if constexpr (std::is_same_v<std::remove_cv_t<std::remove_reference_t<decltype(Grupe)>>,std::list<Studentas<Container>>>) 
    {
    auto start = chrono::high_resolution_clock::now();
    Grupe.sort([=](const Studentas<Container>& a, const Studentas<Container>& b)
    {switch (g)
         {
          case 1: return h==1 ? a.getVardas() < b.getVardas() : a.getVardas() > b.getVardas();
          case 2: return h==1 ? a.getPavarde() < b.getPavarde() : a.getPavarde() > b.getPavarde();
          case 3: return h==1 ? a.getRez() < b.getRez() : a.getRez() > b.getRez();
          case 4: return h==1 ? a.getMed() < b.getMed() : a.getMed() > b.getMed();
          default: return false;
         }});
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elaps = end - start;
    cout << "Rikiavimo laikas naudojant konteineri list: " << setprecision(3) << elaps.count() << " s\n";
    isvedimas(Grupe, failovardas);
    }
    else
    {   
        auto start = chrono::high_resolution_clock::now();
        vector<Studentas<Container>*> ptrs;
        ptrs.reserve(Grupe.size());
        for(auto& stud : Grupe) ptrs.push_back(&stud);
        sort(std::execution::par, ptrs.begin(), ptrs.end(), [=](const Studentas<Container>* a, const Studentas<Container>* b) {
            switch (g)
             {
              case 1: return h==1 ? a->getVardas() < b->getVardas() : a->getVardas() > b->getVardas();
              case 2: return h==1 ? a->getPavarde() < b->getPavarde() : a->getPavarde() > b->getPavarde();
              case 3: return h==1 ? a->getRez() < b->getRez() : a->getRez() > b->getRez();
              case 4: return h==1 ? a->getMed() < b->getMed() : a->getMed() > b->getMed();
              default: return false;
             }          
        });
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elaps = end - start;
        cout << "Rikiavimo laikas naudojant konteineri vector: " << fixed << setprecision(3) << elaps.count() << " s\n";
        isvedimas_vector(ptrs, failovardas);
    }
}


template<template<typename> class Container>
void isvedimas_vector(const vector<Studentas<Container>*>& prts, string failovardas)
{
    Studentas<Container>::mode = b;
    bool arfailas = false;
    int kiek = 0;
    
    if(renkames==1) 
        arfailas = true;
    else if(arfailas==false)
        {
            size_t pos = failovardas.find('_');
            std::string result = (pos != std::string::npos) ? failovardas.substr(0, pos) : failovardas;
            cout << "Studentu " << result << " 20 pirmu rezultatu" << endl;
        }
    
    ofstream wr;
    ostringstream oss;
    ostream& isved = arfailas ? static_cast<ostream&>(oss) : cout;

    auto startas = chrono::high_resolution_clock::now();
    isved << setw(21) << right << "Vardas | " << setw(21) << right << "Pavarde | " << setw(21) << right;
    if(b==1) {isved << "Galutinis (Vid.)"  << " | Adresas atmintyje\n" << string(64, '-') << endl;}
            else if(b==2) {isved << "Galutinis (Med.) "  << " | Adresas atmintyje\n" << string(55, '-') << endl;}
            else if(b==3) {isved << "Galutinis (Vid.) | " << setw(21) << right << "Galutinis (Med.)"  << setw(21) << right<<  " | Adresas atmintyje\n" << string(105, '-') << endl;}    
    for(const auto* p : prts) {
        if(!arfailas && kiek++ >=20) break;
        isved << setw(18) << right << p->getVardas() << " | " << setw(18) << p->getPavarde() << " | " << setw(18) << fixed << right << setprecision(2);
        if(b==1) isved << p->getRez() << " | " << setw(17) << p << endl;
        else if(b==2) isved << p->getMed() << " | " << setw(17) << p << endl;
        else if (b==3) isved << p->getRez() << " | " << setw(22) <<  right << p->getMed() << " | " << setw(17) << fixed << right << p << endl;
    }

    if(arfailas)
    {
        if(failovardas.find("txt") == std::string::npos)
            failovardas += ".txt";
        failovardas = "rez_"+failovardas;
        wr.open(failovardas);
        wr << oss.str();
        wr.close();
    }
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    if(arfailas)
        cout << "Failo " << failovardas << " rasymo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;
}




template <template<typename> class Container>
void pirma_strat_rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas)
{
    Container<Studentas<Container>> gerai, blogai;
    auto startas = chrono::high_resolution_clock::now();
    for(const auto& temp : Grupe)
    {
        if(temp.getRez()>=5)
            gerai.push_back(temp);
        else
            blogai.push_back(temp);
    }
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    cout << "Rusiavimo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;

    rikiavimas<Container>(gerai, "gerai_"+failovardas);
    rikiavimas<Container>(blogai, "blogai_"+failovardas);
}

template <template<typename> class Container>
void antra_strat_rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas)
{
    Container<Studentas<Container>> blogai, temp = Grupe;
    auto startas = chrono::high_resolution_clock::now(); 
    for(auto it = Grupe.begin(); it != Grupe.end();)
    {
        if(it->getRez() < 5)
        {
            blogai.push_back(*it);
            it = Grupe.erase(it);
        }
        else ++it;
    }
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    cout << "Rusiavimo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;

    rikiavimas<Container>(Grupe, "gerai_"+failovardas);
    rikiavimas<Container>(blogai, "blogai_"+failovardas);
}

template <template<typename> class Container>
void trecia_strat_rusiavimas(Container<Studentas<Container>>& Grupe, string failovardas)
{
    Container<Studentas<Container>> blogai;
    auto startas = chrono::high_resolution_clock::now();
    auto centras = partition(Grupe.begin(), Grupe.end(), [](const Studentas<Container>& temp) { return temp.getRez() < 5; });
    blogai.insert(blogai.end(), make_move_iterator(centras), make_move_iterator(Grupe.end()));
    Grupe.erase(centras, Grupe.end());
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    cout << "Rusiavimo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;

    rikiavimas<Container>(Grupe, "gerai_"+failovardas);
    rikiavimas<Container>(blogai, "blogai_"+failovardas);
}
