#include <string>
#include <vector>

class WierzcholekGrafu;


class Krawedz
{
private:
    WierzcholekGrafu * wierzcholek1;
    WierzcholekGrafu * wierzcholek2;
public:
    Krawedz(WierzcholekGrafu * wierzcholek1, WierzcholekGrafu * wierzcholek2);
    WierzcholekGrafu * getWierzcholek(int index);
};

Krawedz::Krawedz(WierzcholekGrafu * wierzcholek1, WierzcholekGrafu * wierzcholek2)
{
    this->wierzcholek1 = wierzcholek1;
    this->wierzcholek2 = wierzcholek2;
}

WierzcholekGrafu * Krawedz::getWierzcholek(int index)
{
    return index == 0 ? wierzcholek1 : wierzcholek2;
}


class WierzcholekGrafu
{
private:
    std::string etykieta;
    std::vector<Krawedz> krawedzie;
public:
    WierzcholekGrafu(std::string);
    Krawedz polaczWierzcholek(WierzcholekGrafu);
};

WierzcholekGrafu::WierzcholekGrafu(std::string etykieta)
{
    this->etykieta = etykieta;
}

Krawedz WierzcholekGrafu::polaczWierzcholek(WierzcholekGrafu  laczonyWierzcholek)
{
    Krawedz nowaKrawedz = Krawedz(this, &laczonyWierzcholek);
    this->krawedzie.push_back(nowaKrawedz);
    laczonyWierzcholek.krawedzie.push_back(nowaKrawedz);
}

