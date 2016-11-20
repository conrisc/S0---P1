# Systemy operacyjne, pracownia nr 1
Repozytorium zawierające rozwiązanie pracowni nr 1 z kursu Systemów operacyjnych realizowanym na Instytucie Informatyki Uniwersytetu Wrocławskiego w semestrze zimowym roku akademickiego 2016/2017. 

Skład zespołu: 
- Konrad Cielecki (<a href="https://github.com/conrisc/">conrisc</a>), 
- Damian Górski (<a href="https://github.com/dmngrsk/">dmngrsk</a>).

# Treść zadania
Klasyczny problem synchronizacji wątków - rozszerzenie problemu producenta i konsumenta.

Aktorzy: 
- święty Mikołaj,
- skrzaty S1, S2, S3.

Zasoby:
- liczba zabawek rodzajów Z1, Z2, Z3.

Święty Mikołaj odpoczywa w swojej chatce na biegunie północnym. Jego odpoczynek kończy się, gdy trzeba wysłać zabawki do dzieci - wtedy zaprzęga swoje renifery w zabawki, które potem zostaną rozesłane. Mikołaj chciałby, aby żadne dziecko nie było smutne z powodu otrzymanego prezentu, dlatego wysyła zabawki z biegunu tylko w zestawach po tyle samo zabawek z każdego rodzaju. Ponadto, żeby ułatwić sobie życie, czeka, aż zbierze się odpowiednio dużo zabawek z każdego rodzaju, i dopiero wtedy je wysyła hurtowo. Inaczej mówiąc, czeka, aż zbiorą się przynajmniej po 3 zabawki z Z1, Z2 i Z3 - wtedy wysyła zestaw 3 Z1, 3 Z2 i 3 Z3 (bez nadwyżek, które mogły się wówczas zebrać).

Pracownicy świętego Mikołaja, skrzaty, zajmują się produkcją zabawek. Dobierają się w pary i wspólnymi siłami tworzą zabawki, odpowiednio: S1 i S2 tworzą Z1, S1 i S3 tworzą Z2, a S2 i S3 tworzą Z3. Jeden skrzat może pracować jednocześnie tylko nad jedną zabawką. Skrzaty dobierają się w pary losowo.

# Wytyczne techniczne
1. Program powinien znaleźć się w osobnym repozytorium i powinien zawierać plik Makefile w katalogu głównym.
2. Program powinien być obsługiwany z poziomu polecenia make. Uruchomienie polecenia 'make' powinno służyć do kompilacji pod warunkiem zmian w pliku main.c(pp). Uruchomienie polecenia 'make run' powinno służyć do uruchomienia programu.
3. Program powinien być napisany w C lub C++ z użyciem biblioteki pthreads (podpowiedź: gcc -lpthread).
4. Program powinien uruchamiać się na platformie Linux.
5. Repozytorium powinno zawierać plik .gitignore, za pomocą którego unikniesz umieszczania w repozytorium pliku binarnego.
6. Instrukcja kompilacji powinna zawierać flagi: -Wall, -Werror.