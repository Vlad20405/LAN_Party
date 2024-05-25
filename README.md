# Tema 1: LAN Party - din cadrul disciplinei Proiectarea Algoritmilor


## Cerință: [O poți găsi aici](https://ocw.cs.pub.ro/courses/sda-ab/tema1)

## Rulare & Verificare:
Pentru a rula și verifica funcționalitatea programului, trebuie să descărcați codul sursă atașat și să rulați comanda:
```shell
./checker.sh
```

## Informații generale:
* Pentru viitoarele persoane care doresc să îmbunătățească programul, se poate modifica orice în acesta, cu excepția fișierului `checker.sh` și a folderelor care conțin fișierele de `date`, `out` și `rezultate`;
* Fișierul `main.c` este cel principal, în care s-a realizat fiecare cerință din temă prin apeluri către funcțiile aferente;
* În fișierul `main.h` se regăsesc toate structurile necesare pentru rezolvarea cerințelor, dar și legăturile dintre funcțiile necesare acestora;
* Am creat fișiere `.c` separate pentru funcțiile generice, de exemplu pentru liste, cozi, stive, arbori;
* De asemenea, am creat fișierul `cerinte.c`, în care se regăsesc funcțiile pentru fiecare cerință în parte, și fișierul `functii.c`, care conține toate funcțiile create de mine pentru a putea rezolva sarcinile din temă.

## Rezolvarea cerințelor:

### Cerința 1:
* Am făcut citirea din fișiere în funcția `main()` care se află în fișierul `main.c`. Astfel, datele citite (nr. echipe, nr. persoane, nume echipe, nume și prenume persoane, și punctaje) au fost prelucrate și introduse într-o listă cu ajutorul funcției `addAtBeginning()`. 

### Cerința 2:
* Pentru această sarcină am creat funcția `numarEchipeMultipluDe_2()`, care determină numărul total de echipe ce trebuie să rămână, acesta fiind un număr putere a lui 2. Astfel, pe baza acestui număr generat, am început să elimin echipele cu cel mai mic punctaj;
* Ștergerea echipelor am realizat-o cu ajutorul funcției `eliminaEchipaPunctajMinim()`, care, la rândul ei, apelează funcția `punctajMinim()` ce returnează cel mai mic punctaj din listă. Pe baza acestuia, parcurg lista, iar când punctajul transmis de funcție corespunde cu punctajul unei echipe, aceasta va fi ștearsă. Ulterior, reiau algoritmul și determin următoarea echipă cu cel mai mic punctaj dintre cele rămase anterior și așa mai departe până ajung la numărul generat de funcția `numarEchipeMultipluDe_2()`.
* Pentru cazul în care două echipe au același scor, am eliminat pur și simplu prima echipă care mi-a ieșit în cale, conform cerinței.

### Cerința 3:
