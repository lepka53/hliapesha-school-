#include <iostream> // Używamy tego, żeby gadać z komputerem (cin, cout)
using namespace std; // Dzięki temu nie trzeba pisać std::cin i std::cout

int szukaj(int tab[], int szukana) {
    int l = 0;            // Lewa granica
    int p = 10;           // Prawa granica
    int sr = (l + p) / 2; // Środek tablicy
    
    while (l <= p) {
        if (tab[sr] == szukana) { // znaleziona liczbę
            return sr;            // oddajemy pozycję liczby
        } else if (tab[sr] > szukana) { // Szukana jest mniejsza, w lewo
            p = sr - 1; // Zmniejszamy prawą granicę
        } else { // Szukana jest większa, w prawo
            l = sr + 1;
        }
        sr = (l + p) / 2; // licze nowy środek
    }

    return -1; // jak nie znaleźliśmy liczby, zwracamy -1 
}

int main() {
    int szukana; // Liczba, którą chce podać użytkownik
    int tab[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // tablica

    // prosimy użytkownika żeby podał co chce znaleźć
    cout << "Podaj liczbe ktora chcesz znalezc: \n";
    cin >> szukana; // zapisujemy liczbę od użytkownika

    // szukamy liczby w tablicy:
    if (szukaj(tab, szukana) == -1) {
        cout << "Nie ma liczby.\n"; // jak jej nie ma, to informujemy o tym
    } else {
        cout << "Szukana liczba " << szukana << " znajduje sie na pozycji " 
             << szukaj(tab, szukana); // jak jest, podajemy jej miejsce
    }

    return 0; // koniec
}
