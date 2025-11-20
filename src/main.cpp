#include "mylib.h"


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> failai_txt;
    int a, b, c, d, e, g, h;

    cout << "Ar turite duomenis? (1 - taip, 2 - ne)" << endl;
    while(true) {if(cin >> d && d>=1 && d<=2) break; cout << "Neteisinga ivestis, pasirinkite 1 arba 2" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    if(d==2)
    {
        cout << "Ar norite sugeneruoti duomenis (1 - taip; 2 - ne)" << endl;
        while(true) {if(cin >> c && c>=1 && c<=2) break; cout << "Neteisinga ivestis, pasirinkite 1 arba 2" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        if(d==2 && c==2)
        {
            cout << "Be duomenu negalite atlikti skaiciavimu. Iveskite 1, kad generuotumete duomenis" << endl;
            while(true) {if(cin >> c && c==1) break; cout << "Be duomenu negalite atlikti skaiciavimu. Iveskite 1, kad generuotumete duomenis" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        }
        if(c==1)
        {
            cout << "Generuojami duomenys..." << endl;
            generuojame();
            cout << "Generavimas baigtas!" << endl;
        }
    }
    string folder = "./src", nfailas;
        for(const auto& entry : fs::directory_iterator(folder))
        {
            if(entry.path().extension() == ".txt" && entry.path().filename().string().find("rez") == string::npos)
            {
                failai_txt.push_back(entry.path().filename().string());
            }
        }
    while(true){
    cout << "Kokius konteinerius naudojant norite atlikti skaiciavimus?\n(1) Vektorius\n(2) Sarasus" << endl;
    while(true) {if(cin >> e && e>=1 && e<=2) break; cout << "Neteisinga ivestis, pasirinkite viena is skaiciu 1 ar 2:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}

    cout << "Norite apskaiciuoti:\n(1) Vidurki\n(2) Mediana\n(3) Abu" << endl;
    while(true) {if(cin >> b && b>=1 && b<=3) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 3:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}

    if(d==1)
    {
        cout << "Norite:\n(1) Generuoti tik rezultatus automatiskai\n(2) Ranka suvesti rezultatus\n(3) Skaityti rezultatus is failo" << endl;
        while(true) {if(cin >> a && a>=1 && a<=3) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 3:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    }
    else if(d==2) a=3;
    if(a==3)
    {
        cout << "Turimi failai:" << endl;
        for(const auto& temp:failai_txt)
            cout << temp << endl;
        cout << "Pasirinkite faila ivesdami jo pavadinima (su .txt)" << endl;
        int tst = 1;
        while(tst!=0)
        {
            cin >> nfailas;
            for(const auto&temp:failai_txt)
                if(temp==nfailas) tst=0;
            if(tst!=0)
                cout << "Tokio failo nera, bandykite dar karta" << endl;
        }

        cout << "Norite rusiuoti pagal:\n(1) Varda, (2) Pavarde, (3) Gal. Vid., (4) Gal. Med." << endl;
        while(true) {if(cin >> g && g>=1 && g<=4) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 4:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}

        cout << "Pasirinkite krypti:\n(1) Didejancia tvarka\n(2) Mazejancia tvarka" << endl;
        while(true) {if(cin >> h && 0<h && h<3) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 2:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}

        if(e==1)
            dirbam<vector>(b, nfailas, g, h);
        else if(e==2)
            dirbam<list>(b, nfailas, g, h);
    }
    else
    {
        int n;
        cout << "Iveskite studentu skaiciu:" << endl;
        while(true) {if(cin >> n && n>=1) break; cout << "Neteisinga ivestis, iveskite skaiciu" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        if(e==1)
        {
            vector<Studentas<vector>> Grupe;
            for(int i=1; i<=n; i++)
                Grupe.push_back(skaiciuojam<vector>(a, b));
            cout << "Norite rusiuoti pagal:\n(1) Varda, (2) Pavarde, (3) Gal. Vid., (4) Gal. Med." << endl;
            while(true) {if(cin >> g && g>=1 && g<=4) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 4:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            cout << "Pasirinkite krypti:\n(1) Didejancia tvarka\n(2) Mazejancia tvarka" << endl;
            while(true) {if(cin >> h && 0<h && h<3) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 2:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            rusiavimas<vector>(b, Grupe, "1", g, h);
        }
        else
        {
            auto start = chrono::high_resolution_clock::now();
            list<Studentas<list>> Grupe;
            for(int i=1; i<=n; i++)
                Grupe.push_back(skaiciuojam<list>(a, b));
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elaps = end - start;
            cout << "Skaiciavimo laikas: " << fixed << setprecision(3) << elaps.count() << " s" << endl;
            cout << "Norite rusiuoti pagal:\n(1) Varda, (2) Pavarde, (3) Gal. Vid., (4) Gal. Med." << endl;
            while(true) {if(cin >> g && g>=1 && g<=4) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 4:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            cout << "Pasirinkite krypti:\n(1) Didejancia tvarka\n(2) Mazejancia tvarka" << endl;
            while(true) {if(cin >> h && 0<h && h<3) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 2:" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            rusiavimas<list>(b, Grupe, "1", g, h);
        }
    }
    int kl;
    cout << "Ar norite testi skaiciavimus?\n(1) Taip\n(2) Ne" << endl;
    while(true) {if(cin >> kl && kl>=1 && kl<=2) break; cout << "Neteisinga ivestis, pasirinkite taip (1) arba ne (2):" << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    if(kl==2) break;
    }
}


