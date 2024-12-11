#include <iostream>
using namespace std;

int potegowanie(int a, int n);

int main()
{
    int a, n;

    cout << "Podaj liczbe ktora chcesz podniesc do potegi \n";
    cin >> a;
    cout << "Podaj wykladnik \n";
    cin >> n;
    
    int wynik = potegowanie(a, n);
    cout << "Wynik " << wynik;
}

int potegowanie(int a, int n) {
	int wynik = 1;
	
    while (n > 0) {
    	if (n % 2 == 1) {
    		wynik = wynik * a;
		} 
		a = a * a;
		n = n / 2;
	}
	
	return wynik;
}