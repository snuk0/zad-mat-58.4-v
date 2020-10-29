#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector <int> v;

int bin(string x)
{
	int ans = 0;
	int licz = 1;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		if (x[i] == '-')
			ans *= -1;
		if (x[i] == '1')
			ans += licz;
		licz *= 2;
	}
	return ans;
}

int oblicz(int x, int y, int Tx, int Ty)
{
	int licznik = (Tx - Ty) * (Tx - Ty);
	int mianownik = abs(x - y);
	float ans = (float)licznik / (float)mianownik;
	ans = ceil(ans);
	return (int)ans;
}

int main()
{
	ifstream file1("dane_systemy1.txt");
	if (file1.good())
	{
		string x;
		bool wczytaj = false;
		while (file1 >> x) {
			if (wczytaj) {
				v.push_back(bin(x));
			}
			wczytaj = !wczytaj;
		}

		int maxx = INT_MIN;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				int ans = oblicz(i, j, v[i], v[j]);
				maxx = max(maxx, ans);
			}
		}
		cout << "Najwiekszy skok temperatury: " << maxx;
	}

	return 0;
}
