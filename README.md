# v1.0
  Atnaujintas kodas, matuotas laikas rodomas po kablelio.
  Optimizuotas kodas.
  Pridetas ***CMakeLists.txt*** failas.
  
  #### Atlikti rūšiavimo spartos testai:
  ***1 strategija***:  
  Bendras studentų konteineris padalinamas į du - ***gerai*** ir ***blogai***.
  Vienas studentas egzistuoja dviejuose konteineriuose: *bendrame* ir ***gerai***/***blogai***, rūšiavimo greitį lemia konteinerio tipas, tačiau atminties sąnaudos didelės.     
  ***2 strategija***:   
  Sukuriamas tik vienas naujas konteineris ***blogai***. Studentai, kurie perkeliami į konteinerį ***blogai*** yra ištrinami iš pirmojo konteinerio.
  Vienas studentas egzistuoja tik viename konteineryje. Atmintis naudojama efektyviau, tačiau trynimai gali būti lėti.   
  ***3 strategija***:  
  Pasirinkta 2 strategija ir naudojamas `partition` greitesniam rūšiavimui. Rūšiavimas vyksta greičiau negu naudojant pirmą arba antrą strategijas.  
  ***4 strategija***:  
  `vector` ir `list` taikomos skirtingos strategijos. `list` naudoja `splice` metodą, o `vector` naudoja `partition`.  
  Naudojami tik 2 konteineriai, o sukuriamas naujai tik vienas. Studentas egzistuoja tik viename. 
  
  ### Naudojant  `vector` konteineri
  | Failai | **1 strategija** | **2 strategija** | **3 strategija**| **4 strategija**** |
  |:---|:-------------:|:-------------:|:-------------:| :--: |
  | **stud_1000.txt**     | 0 s | 0 s | 0.000s |0.000 s|
  | **stud_10000.txt**    | 0 s | 0 s | 0.000s |0.000 s|
  | **stud_100000.txt**   | 0 s | 18 s| 0.002s |0.002 s|
  | **stud_1000000.txt**  | 0 s | --* | 0.033s |0.033 s|
  | **stud_10000000.txt** | 3 s | --* | 0.350s |0.338 s|
  
  ### Naudojant  `list` konteineri
  | Failai | **1 strategija** | **2 strategija** | **3 strategija**| **4 strategija**** |
  |:---|:-------------:|:-------------:|:-------------:| :--: |
  | **stud_1000.txt**     | 0s | 0s | 0.000s |0.000 s|
  | **stud_10000.txt**    | 0s | 0s | 0.001s |0.000 s|
  | **stud_100000.txt**   | 0s | 0s | 0.023s |0.019 s|
  | **stud_1000000.txt**  | 1s | 0s | 0.320s |0.167 s|
  | **stud_10000000.txt** | 16s | 7s| 4.077s |1.889 s|
  
  *Testas truko per ilgai  
  **Vector ir list konteineriams skiriasi (list naudoja `splice`)

  ### Naudojimosi instrukcija
  1. Patikrinkite ar kompiuteryje turite įdiegtus ***C++ kompiliatorių*** bei projekto generavimo įrankius ***CMake***, jei ne - parsisiųskite ir įsidiegite.
  2. Atsisiųskite failus *main.cpp*, *mylib.cpp*, *mylib.h*, *CMakeLists.txt*, *run.bat*.
  3. Apklanke, kuriame bus vykdomas kodas (jūsų pasirinkimas) sukurkite aplankus **"src"** ir **"Include"**, ir į juos perkelkite failus. *main.cpp* ir *mylib.cpp* į aplanką **"src"**, o *mylib.h* į apklanką **"Include"**. *CMakeLists.txt* ir *run.bat* failus palikite aplanke, kur bus vykdomas Jūsų kodas.
  4. Paleiskite *run.bat* failą. Jame yra surašytos visos komandos, reikalingos programos kodo paleidimui.
  5. Norėdami po programos uždarymo vėl paleisti programą, leiskite arba *run.bat*, arba *Work_with_Files.exe* failus.


# v0.3
1. Gerokai pakeistas kodas. Viskas optimizuota.
2. Pridėtas konteineris ***list***.
3. Kodas parašytas naudojant šablonus (***templates***), kad būtų galima lengvai pasirinkti, kokį konteinerį naudoti.
4. Atlikti kodo veikimo spartos testai naudojant abu konteinerius (žiūrėti dalį "veikimo sparta")
  ### Veikimo sparta:
  Testai atlikti naudojant *work* kompiuterį  
  Testai atlikti skaičiuojant vidurkį ir medianą, rūšiuojant pagal vidurkį, mažėjančia tvarka
  | Failai | **Skaitymas** || **Skaičiavimas** || **Rikiavimas** || **Rūšiavimas** || **Rašymas ("gerai")** || **Rašymas ("blogai")** ||
  |:----------------------|:-------------:|:------:|:----------------:|:------:|:--------------:|:------:|:---------------:|:------:|:----------------------:|:------:|:-----------------------:|:------:|
  || `Vector` | `List` | `Vector` | `List` | `Vector` | `List` | `Vector` | `List` | `Vector` | `List` | `Vector` | `List` |
  | **stud_1000.txt**     | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s |
  | **stud_10000.txt**    | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s | 0s |
  | **stud_100000.txt**   | 0s | 0s | 0s | 2s | 0s | 0s | 0s | 0s | 1s | 1s | 1s | 1s |
  | **stud_1000000.txt**  | 0s | 2s | 2s | 2s | 2s | 2s | 0s | 1s | 2s | 2s | 1s | 1s |
  | **stud_10000000.txt** | 2s | 1s | 21s | 29s | 5s | 16s | 3s | 16s | 23s | 32s | 16s | 23s |

  Išvados: 
  Dirbant su nedideliu kiekiu duomenų, naudojamo konteinerio tipas nedaro didelio skirtumo, tačiau dirbant su labai dideliais kiekiais duomenų (pvz. 10 000     000 eilučių) veikimo spartos skirtumai matosi akivaizdziai. 
  Naudojant kontenerį ***vector*** skaičiavimai, rikiavimas, rūšiavimas ir rašymas į failus trunka   gerokai greičiau, negu naudojant konteinerį ***list***.
  
  ### Device spec.:
  1 (*personal*):
  OS - Windows 11 Pro
  Processor - Intel(R) Core(TM) I5-10300H CPU @ 2.50GHz (2.50 GHz)
  RAM - 16.0 GB
  System type - 64-bit operating system, x64-based processor
    
  2 (*work*):
  OS - Windows 11 Home
  Processor - AMD Ryzen 5 7530U with Radeon Graphics (2.00 GHz)
  RAM - 16.0 GB
  System type - 64-bit operating system, x64-based processor 

# v0.2
  1. Labai stipriai pakoreguotas kodas, pridėtas duomenų generavimas, išvedimas 2 failus, rušiavimas. Kodas daug optimalesnis. Pridėtas programos veikimo laiko ir greičio matavimas.
  2. Patvarkytas kodas, pridetas ***header*** failas (*mylib.h*), į kurį perkeltos visos funkcijos. Faile *main.cpp* palikta tik pragrindine funkcija.
  3. Pridėtas pasirinktinas rušiavimas.

# v0.1
  1. Pridėtas rušiavimas išvedant rezultatus (pagal pavardę).
  2. Pridėtas rūšiavimas prieš išvedima (pagal vardą), sutvarkytos minimalios kodo klaidos, pridėtas failu pasirinkimas.
     
# pirma
  1. Parašytas pradinis užduoties kodas.
  2. Parašytas kodas padarantis lentelę, nurodančia studentų vardus, pavardes ir galutinius rezultatus.
  3. Pridėtas medianos skaičiavimas, sutvarkytos kitos smulkios kodo klaidos.
  4. Pridėtas automatinis pažymių generavimas.
  5. Sutvarkytas pažymių įvedimas (nebėra ribojamas jų skaičius), pataisytos kitos smulkios klaidos.
  6. Pridėtas pasirinkimas skaičiuoti mediana, vidurki ar abu.
  7. Pridėtas skaitymas iš failo, šiek tiek optimizuotas kodas.



