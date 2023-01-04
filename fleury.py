def fleury(wierzcholki: list) -> str:
    dostepne_krawedzie = []

    for wierzcholek in wierzcholki:
        for krawedz in wierzcholek.krawedzie:
            if krawedz not in dostepne_krawedzie:
                dostepne_krawedzie.append(krawedz)

    wierzcholek_wejsciowy = wierzcholki[0]
    wierzcholek1 = wierzcholki[0]
    wierzcholek2 = ""

    sciezka = str(wierzcholek_wejsciowy)

    while len(dostepne_krawedzie) > 0 or wierzcholek2 != wierzcholek_wejsciowy:
        operowana_krawedz = None

        for krawedz in wierzcholek1.krawedzie:
            if krawedz in dostepne_krawedzie:
                operowana_krawedz = krawedz
                break

        if not operowana_krawedz:
            sciezka += " -> X, brak cyklu eulera"
            break

        if operowana_krawedz.wierzcholek1 == wierzcholek1:
            wierzcholek2 = operowana_krawedz.wierzcholek2
        elif operowana_krawedz.wierzcholek2 == wierzcholek1:
            wierzcholek2 = operowana_krawedz.wierzcholek1

        wierzcholek1 = wierzcholek2
        dostepne_krawedzie.remove(operowana_krawedz)
        sciezka += " -> {}".format(wierzcholek2)

    return sciezka

