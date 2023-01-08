#include <vector>
#include <string>

class WierzcholekGrafu;

class Krawedz
{
private:
    WierzcholekGrafu * wierzcholek1;
    WierzcholekGrafu * wierzcholek2;
    std::string etykieta;
    int waga;
public:
    Krawedz(WierzcholekGrafu *, WierzcholekGrafu *, std::string, int);
    std::string getEtykieta();
    int getWaga();
};

Krawedz::Krawedz(WierzcholekGrafu * wierzcholek1, WierzcholekGrafu * wierzcholek2, std::string etykieta, int waga)
{
    this->wierzcholek1 = wierzcholek1;
    this->wierzcholek2 = wierzcholek2;
    this->etykieta = etykieta;
    this->waga = waga;
}

std::string Krawedz::getEtykieta()
{
    return this->etykieta;
}

int Krawedz::getWaga()
{
    return this->waga;
}


class WierzcholekGrafu
{
private:
    std::string etykieta;
    std::vector<Krawedz> krawedzie;
public:
    WierzcholekGrafu(std::string);
    std::string getEtykieta();
    std::vector<Krawedz> getKrawedzie();
    void polaczWierzcholek(WierzcholekGrafu *, int);
};

WierzcholekGrafu::WierzcholekGrafu(std::string etykieta)
{
    this->etykieta = etykieta;
}

std::string WierzcholekGrafu::getEtykieta()
{
    return this->etykieta;
}

std::vector<Krawedz> WierzcholekGrafu::getKrawedzie()
{
    return this->krawedzie;
}

void WierzcholekGrafu::polaczWierzcholek(WierzcholekGrafu * laczonyWierzcholek, int waga)
{
    std::string etykietaKrawedzi = this->getEtykieta() + " <-(" + std::to_string(waga) + ")-> " + laczonyWierzcholek->getEtykieta();
    Krawedz krawedz = Krawedz(this, laczonyWierzcholek, etykietaKrawedzi, waga);

    this->krawedzie.push_back(krawedz);
    (*laczonyWierzcholek).krawedzie.push_back(krawedz);
}


std::vector<WierzcholekGrafu> przykladowyGraf()
{
    std::vector<std::string> miasta = {"Radom", "Sosnowiec", "Lodz", "Gliwice", "Bytom"};

    std::vector<WierzcholekGrafu> graf;

    for (int i = 0; i < miasta.size(); i++)
    {
        WierzcholekGrafu nowyWierzcholek = WierzcholekGrafu(miasta[i]);
        graf.push_back(nowyWierzcholek);
    }

    graf[0].polaczWierzcholek(&graf[1], 200);
    graf[1].polaczWierzcholek(&graf[4], 10);
    graf[4].polaczWierzcholek(&graf[3], 20);
    graf[1].polaczWierzcholek(&graf[2], 250);
    graf[0].polaczWierzcholek(&graf[2], 100);

    return graf;
}

bool znajdzwWektorze(std::string wartosc, std::vector<std::string> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        if (wartosc == wektor[i])
        {
            return true;
        }
    }
    return false;
}

void wyswietlGraf(std::vector<WierzcholekGrafu> grafDoWyswietlenia)
{
    std::vector<std::string> uzyteKrawedzie;

    for (int i = 0; i < grafDoWyswietlenia.size(); i++)
    {
        std::vector<Krawedz> krawedzieGrafu = grafDoWyswietlenia[i].getKrawedzie();
    
        for (int j = 0; j < krawedzieGrafu.size(); j++)
        {
            if (!znajdzwWektorze(krawedzieGrafu[j].getEtykieta(), uzyteKrawedzie))
            {
                std::cout << krawedzieGrafu[j].getEtykieta() << std::endl;
                uzyteKrawedzie.push_back(krawedzieGrafu[j].getEtykieta());
            }
        }
    }
}
