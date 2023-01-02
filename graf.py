class WierzcholekGrafu:
    etykieta: str
    krawedzie: list

    def __init__(self, etykieta: str):
        self.etykieta = etykieta
        self.krawedzie = []

    def __str__(self):
        return self.etykieta

    def polacz_wierzcholek(self, laczony_wierzcholek):
        krawedz = Krawedz(self, laczony_wierzcholek)
        self.krawedzie.append(krawedz)
        laczony_wierzcholek.krawedzie.append(krawedz)


class Krawedz:
    wierzcholek1: WierzcholekGrafu
    wierzcholek2: WierzcholekGrafu

    def __init__(self, wierzcholek1: WierzcholekGrafu, wierzcholek2: WierzcholekGrafu):
        self.wierzcholek1 = wierzcholek1
        self.wierzcholek2 = wierzcholek2

    def __str__(self):
        return f"{self.wierzcholek1} <---> {self.wierzcholek2}"


wierzcholki = []

for i in range(10):
    wierzcholek = WierzcholekGrafu(str(i + 1))
    wierzcholki.append(wierzcholek)

wierzcholki[0].polacz_wierzcholek(wierzcholki[1])
wierzcholki[0].polacz_wierzcholek(wierzcholki[2])
wierzcholki[0].polacz_wierzcholek(wierzcholki[3])
wierzcholki[0].polacz_wierzcholek(wierzcholki[4])
wierzcholki[1].polacz_wierzcholek(wierzcholki[2])
wierzcholki[1].polacz_wierzcholek(wierzcholki[3])
wierzcholki[1].polacz_wierzcholek(wierzcholki[4])
wierzcholki[2].polacz_wierzcholek(wierzcholki[3])
wierzcholki[2].polacz_wierzcholek(wierzcholki[4])
wierzcholki[3].polacz_wierzcholek(wierzcholki[4])









