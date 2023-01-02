from graf import wierzcholki

dostepne_krawedzie = []

for wierzcholek in wierzcholki:
    for krawedz in wierzcholek.krawedzie:
        if krawedz not in dostepne_krawedzie:
            dostepne_krawedzie.append(krawedz)

wierzcholek_wejsciowy = wierzcholki[0]
wierzcholek1 = wierzcholki[0]
wierzcholek2 = ""

path = str(wierzcholek_wejsciowy)

while len(dostepne_krawedzie) > 0 or wierzcholek2 != wierzcholek_wejsciowy:
    operowana_krawedz = None

    for krawedz in wierzcholek1.krawedzie:
        if krawedz in dostepne_krawedzie:
            operowana_krawedz = krawedz
            break

    if not operowana_krawedz:
        print(path)
        print("brak cyklu eulera")
        print("pozostale krawedzie (", len(dostepne_krawedzie), "):")
        for krwdz in dostepne_krawedzie:
            print(krwdz.wierzcholek1, "---", krwdz.wierzcholek2)
        break

    if operowana_krawedz.wierzcholek1 == wierzcholek1:
        wierzcholek2 = operowana_krawedz.wierzcholek2
    elif operowana_krawedz.wierzcholek2 == wierzcholek1:
        wierzcholek2 = operowana_krawedz.wierzcholek1

    wierzcholek1 = wierzcholek2
    dostepne_krawedzie.remove(operowana_krawedz)
    path += " -> {}".format(wierzcholek2)
