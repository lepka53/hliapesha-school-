#include <iostream>
using namespace std;

int czynniki(int n);

int main() {
	int n;
	
	cout << "Wpisz liczbe ktora chcesz rozlozyc na czynniki" << endl;
	cin >> n;
	cout << "Wpisana liczba: " << n << endl;
	cout << "Rozklad liczby na czynniki pierwsze: " << czynniki(n);
	
	return 0;
}

int czynniki(int n) {
	int k = 2;
	
	while (n > 1) {
		while (n % k == 0) {
			cout << k << " ";
			n = n / k;
		}
		k++;
	}
}