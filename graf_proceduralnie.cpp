#include <iostream>
#include <vector>

using namespace std;

void polaczWierzcholki(int * wierzcholek1, int * wierzcholek2, vector<vector<int>> * krawedzie)
{
    vector<int> krawedz = {*wierzcholek1, *wierzcholek2};

    for (int i = 0; i < (*krawedzie).size(); i++)
    {
        if (krawedz == (*krawedzie)[i])
        {
            cout << "Istnieje juz taka krawedz" << endl;
            return;
        }
    }

    (*krawedzie).push_back(krawedz);
}

void dodajWierzcholek(int etykieta, vector<int> * wierzcholki)
{
    for (int i = 0; i < (*wierzcholki).size(); i++)
    {
        if (etykieta == (*wierzcholki)[i])
        {
            cout << "Istnieje juz taki wierzcholek" << endl;
            return;
        }
    }

    (*wierzcholki).push_back(etykieta);
}


int main()
{
    vector<int> wierzcholki;
    vector<vector<int>> krawedzie;
    
    dodajWierzcholek(1, &wierzcholki);
    dodajWierzcholek(2, &wierzcholki);
    dodajWierzcholek(3, &wierzcholki);

    polaczWierzcholki(&wierzcholki[0], &wierzcholki[2], &krawedzie);
}




