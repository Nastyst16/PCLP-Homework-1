# PCLP-Homework-1

    Copyright 2022
    Nastase Cristian-Gabriel Grupa 315CA
    Tema 1
    PCLP


    Problema 1 - Un produs infinit

        Modularizam problema cu ajutorul headerului intitulat "function1.h"

        Incepem prin citirea primei valori din cei doi vectori
    deoarece avem nevoie sa stocam aceste doua numere in variabilele maxa si maxb,
    ca ulterior sa ne ajute in determinarea celui de al doilea maxim.

    Folosim un "for" care ne calculeaza simultan cerintele problemei:
        a) produsul scalar in variabila "ps"
        b) al doilea maxim din fiecare vector in variabilele "a_max" si "b_max"
        c) norma 2 pentru fiecare vector (utilizand formula atasata)

        Prin acest "for" evitam folosirea vectorilor care presupun o optimizare 
    deficitara din punct de vedere al memoriei utilizate si al timpului de executare.

    Am avut grija sa observ daca al doilea maxim nu exista, iar variabilele 
    a1_ok si b1_ok imi comunica acest lucru.

    La final tratam separat cazul in care n == 0 si afisam cerintele cerute.



    Problema 2 - Simple query pe litere

        Modularizam problema cu ajutorul headerului intitulat "function2.h"

        Citim litere introduse de la tastatura pana in momentul in care
    una dintre valori nu mai respecta conditia din do{ }while();
    (daca 'n', nu este litera mica a alfabetului sau 'Q','T','E','X')

        Prin intermediul structurii de decizie "switch" avem posibilitatea
    sa tratam fiecare caz special in parte:
        a) In cazul aparitiei literi 'Q' programul interogheaza numarul de aparitii
    a unui caracter 'L' citit de la tastatura;
        b) In cazul aparititei literei 'T' programul interogheaza Topul literelor,
    in functie de numarul de aparitii al fiecaruia. Parcurgem vectorul de frecventa,
    observam cel mai mare numar de aparitii si il memoram in variabila "max".
    Dupa ce am aflat maximul, mai parcurgem inca odata vectorul de frecventa si afisam
    literele cu numarul de aparitii == max. Totodata stergem numarul de aparitii al literei,
    deoarece urmeaza sa aflam urmatorul maxim. Vectorul "vf2" reprezinta o copie a vectorului
    initial "vf". Nu vrem sa l modificam pe "vf", deoarece vom avea nevoie de el ulterior.
        c) In cazul aparitiei literei 'E' se elimina numarul de aparitie 
    a unei litere 'L' citite de la tastatura;
        d) In cazul in care se introduc litere mici ale alfabetului, programul
    intra in 'default' si numara aparitiile literei respective. Totodata functia
    "alerta(f,u_a,vf)" afiseaza alerte in cazul in care este nevoie. Aceasta verifica fiecare
    conditie pusa in problema, iar daca una dintre acestea nu este respectata se va afisa 
    o alerta.

        Fiecare caz al problemei este modularizat prin functiile:
            numarul_de_aparitii
            topul_literelor
            eliminare_litera



    Problema 3 - Gigel si tabla de sah

        Modularizam problema cu ajutorul headerului intitulat "function3.h"

        Incepem prin citirea dimensiunii tablei de sah si a elementelor acesteia.
        In cazul in care piesa se afla pe un patrat cu coordonatele de acceasi paritate
    inseamna ca se afla pe un patrat de culoare alba. Astfel, trebuie sa ne deplasam
    la stanga daca numarul e negativ, iar la dreapta daca e pozitiv. Iesirea din
    tabla de sah duce la teleportarea pe partea opusa. Prin utilizarea 
    unui while, scadem succesiv valoarea patratului cu dimensiunea tablei de sah
    pana cand aceasta este mai mica decat dimensiunea. Ulterior adunam valoarea ramasa
    cu coordonata "y_coord".

        In cazul in care piesa se afla pe un patrat cu coordonatele de paritate diferita
    inseamna ca se afla pe un patrat de culoare neagra. Folosim analog acelasi algoritm
    doar ca de data aceasta piesa de sah se deplaseaza in sus (daca numarul e negativ) 
    sau in jos (daca numarul e pozitiv).

        De a lungul deplasarii piesei de sah am monitorizat distanta parcursa de aceasta
    in variabila "distanta". care urmeaza apoi a fi afisata.
        In momentul in care piesa de sah a ajuns pe un patrat cu valoarea 0 sau a ajuns
    pe pozitia initiala, ne oprim. Stim coordonatele in care am ajuns prin intermediul
    variabilelor "x_coord" si "y_coord".
        Afisarea liniei: scadem dimensiunea tablei de sah cu x_coord,
    deoarece asa este numerotata tabla de sah (de jos in sus)
        Afisarea coloanei: trebuie sa afisam coordonatele asemenea unui tabel din excel.
    Astfel ne folosim de variabilele "sute" si "zeci". Cele doua while-uri (liniile 49-58)
    calculeaza astfel:  numarul de litere de la A la Z este de 26, iar daca y_coord
    depaseste 26*26, inseamna ca o sa avem afisare de 3 litere (exp ABW). Analog in continuare.



    Problema 4 - Queries again...

        Modularizam problema cu ajutorul headerului intitulat "function4.h"

        Incepem prin citirea dimensiunii a unui careu si citirea numarului de operatii
    pe care urmeaza sa le facem. Citim si continutul sudokului.
        Operatiile sunt numerotate de la 1 la 6 si structura de decizie "switch" ne permite
    sa le accesam intr un mod elegant. Totodata fiecare operatie in parte este modularizata
    prin functiile:
        -posibilitati_linie (operatia 1)
        -posibilitati_coloana (operatia 2)
        -posibilitati_careu (operatia 3)
        -posibilitati_coordonate (operatia 4) Trebuie sa verificam ce numere exista atat pe 
    linia, coloana si careul corespunzatoare coordonatelor introduse de la tastatura.
    Astfel ne putem da seama ce numere putem pune.
        -adaugare_numar (operatia 5)
        -stare_curenta (operatia 6) Pentru a stabili daca tabla de Sudoku se afla intr o pozitie
    invalida, am luat fiecare linie, coloana si careu in parte, iar intr un vector de frecventa
    am memorat aparitiile fiecarui numar. Daca frecventa >= 2 inseamna ca este o configuratie
    invalida. (daca gasim acelasi numar de doua ori pe o linie / coloana / careu, inseamna ca nu e ok)
        Pentru a stabili daca configuratia tablei mai poate fi continuata, verificam daca exista
    patrate egale cu 0 (adica goale). Daca aceasta conditie se indeplineste si tabela nu e invalida
    inseamna ca mai poate fi continuata.
        Daca tabla nu e invalida si nu se poate continua, inseamna ca jocul este castigat.
