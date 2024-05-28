Acest program se ocupa cu crearea unui lanParty in functie de anumite cerinte specificate dintr-un fisier c.in - sunt 5 cerinte care trebuie indeplinite pentru a se afla castigatorul si clasamentul ultimilor 8 echipe;

Initial se citesc 3 fisiere = ftask = c.in , fin = d.in , fout = r.out

taskInit - se ocupa cu initializare unui vector care sa memorereze cerinta care trebuie indeplinita

Se creaza o lista cu informatii despre fiecare echipa si se calcuaza punctajul fiecareia
Informatii despre lista sunt citite dintr-un fisier;
Se scrie apoi numele si punctajul intr-un fisier de iesire r.out

Se trece la task-ul 2;
Se elimina echipele cu punctaj mic astfel incat sa ramana un numar de echipe de o putere maxima a lui 2;
Se scriu iarasi datele din lista in r.out;

Se trece la task-ul 3;
Aici se creeaza meciurile intr-o coada;
Se pun invingatorii intr-o stiva si invinsii in alta;
Se afiseaza fiecare meci si invinagorii in r.out;
Ultimile 8 echipe sunt pusa intr-o lista;
Se sterge lista initiala;

Se trece la task-ul 4;
Aici se creaza un BST cu datele din lista cu ultimile 8 echipe;
Se afiseaza echipele ordonat dupa punctaj;
Se copiaza intr-o lista datele ordonate;

Se trece la task-ul 5;
Se creaza un arbore AVL cu lista de la task-ul 4;
Se printeaza echipele de pe nivelul 2 al arborelui;
