# v1.1
Optimizuotas kodas Pridetas CMakeLists.txt failas. 
Galima naudoti CMake kodo paleidimui. 
Pridėtas "run.bat" failas paprastesniam paleidimui.
  

# v1.0
  Atnaujintas kodas, matuotas laikas rodomas po kablelio.
  Optimizuotas kodas.
  Pridetas ***CMakeLists.txt*** failas.
  
  Atlikti rūšiavimo spartos testai:
  ### Naudojant  `vector` konteineri
  | Failai | **1 strategija** | **2 strategija** | **3 strategija** |
  |:---|:-------------:|:-------------:|:-------------:|
  | **stud_1000.txt**     | 0 s | 0 s | 0.000 s|
  | **stud_10000.txt**    | 0 s | 0 s | 0.000 s|
  | **stud_100000.txt**   | 0 s | 18 s | 0.005 s|
  | **stud_1000000.txt**  | 0 s | --* | 0.060 s|
  | **stud_10000000.txt** | 3 s | --* | 0.598 s|
  
  *Testas truko per ilgai

  ### Naudojant  `list` konteineri
  | Failai | **1 strategija** | **2 strategija** | **3 strategija** |
  |:---|:-------------:|:-------------:|:-------------:|
  | **stud_1000.txt**     | 0s | 0s | 0.000 s|
  | **stud_10000.txt**    | 0s | 0s | 0.000 s|
  | **stud_100000.txt**   | 0s | 0s | 0.019 s|
  | **stud_1000000.txt**  | 1s | 0s | 0.167 s|
  | **stud_10000000.txt** | 16s | 7s | 1.889 s|


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



