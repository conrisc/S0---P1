# Systemy operacyjne, pracownia nr 1
Repozytorium zawierające rozwiązanie pracowni nr 1 z kursu Systemów operacyjnych realizowanym na Instytucie Informatyki Uniwersytetu Wrocławskiego w semestrze zimowym roku akademickiego 2016/2017. Skład: Konrad Cielecki (conrisc), Damian Górski (dmngrsk).

# Treść zadania
Klasyczny problem synchronizacji wątków. Aktorzy: święty Mikołaj, nieokreślona liczba reniferów, dziesięć skrzatów.

Święty Mikołaj śpi w swojej chatce na biegunie północnym. Może go zbudzić jedynie przybycie dziewięciu reniferów lub trzech spośród dziesięciu skrzatów, chcących poinformować Mikołaja o problemach z produkcją zabawek. Skrzaty i renifery przybywają osobno. Gdy zbiorą się wszystkie renifery, Mikołaj zaprzęga je do sań, dostarcza zabawki grzecznym dzieciom, wyprzęga je i pozwala odejść na spoczynek. Mikołaj zbudzony przez skrzaty wprowadza je do biura, udziela konsultacji a później żegna. Obsługa reniferów ma priorytet nad obsługą skrzatów. Snu Mikołaja nie może przerwać mniej niż dziewięć reniferów ani mniej niż trzy skrzaty.

# Wytyczne techniczne
1. Program powinien znaleźć się w osobnym repozytorium i powinien zawierać plik Makefile w katalogu głównym.
2. Program powinien być obsługiwany z poziomu polecenia make. Uruchomienie polecenia 'make' powinno służyć do kompilacji pod warunkiem zmian w pliku main.c(pp). Uruchomienie polecenia 'make run' powinno służyć do uruchomienia programu.
3. Program powinien być napisany w C lub C++ z użyciem bibilioteki pthreads (podpowiedź: gcc -lpthread).
4. Program powinien uruchamiać się na platformie Linux.
5. Repozytorium powinno zawierać plik .gitignore, za pomocą którego unikniesz umieszczania w repozytorium pliku binarnego.
6. Instrukcja kompilacji powinna zawierać flagi: -Wall, -Werror.

