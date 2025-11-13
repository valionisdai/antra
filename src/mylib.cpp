#include "mylib.h"

stringstream skaitymas(string failvar)
{
    ifstream rd(failvar);
    stringstream buffer;
    if (!rd.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return buffer;
    }
    auto startas = chrono::high_resolution_clock::now();
    buffer << rd.rdbuf();
    auto endas = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endas - startas;
    cout << "Failo skaitymo laikas: " << fixed << setprecision(3) << elapsed.count() << " s" << endl;
    rd.close();
    return buffer;
}


int pazym_gen()
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> distrib(1, 10);
    return distrib(gen);
}

int generuojame()
{
    int a=1000, n;
    cout << "Iveskite skaiciu pazymiu, kuriuos norite sugeneruoti (ne daugiau 20, be egz.): " << endl;
        while(true)
        {
            if(cin >> n && n>0 && n<21) break; cout << "Neteisinga ivestis, pasirinkite skaiciu nuo 1 iki 20." << endl; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    auto start = chrono::high_resolution_clock::now();
    for(int i=1;i<=5;i++)
    {
        string failovardas = "stud_"+to_string(a)+".txt";
        ofstream wr(failovardas);
        ostringstream oss;
        oss << "Vardas" << " " << "Pavarde" << " " << right;
        for(int i=0; i<n;i++)
        {
            oss << "ND" << i+1 << " ";
        }
        oss << "Egz.\n";
        for(int i=0;i<a;i++)
        {
            oss << "Vardas" << i+1 << " Pavarde" << i+1 << " ";
            for(int j=0;j<n+1;j++)
                oss << pazym_gen() << " ";
            oss << "\n";
        }
        wr << oss.str();
        oss.str("");
        cout << failovardas << endl;
        wr.close();

        a=a*10;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elaps = end - start;
    cout << "Failu generavimo laikas: " <<  fixed << setprecision(3) << elaps.count() << " s" << endl;
    return 0;

}


