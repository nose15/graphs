# graphs
CS project for school


Działanie algorytmu Fleury'a:
  - Wybieramy dowolny wierzchołek, oznaczamy go jako 𝒗 i zapisujemy jako wierzchołek wejściowy.
  - Dopóki wszystkie krawędzie nie zostaną wykorzystane oraz nie znajdujemy się w wierzchołku wejściowym:
    - Przechodzimy z wierzchołka 𝒗 po dowolnej krawędzi do następnego wierzchołka 𝑤
    - Oznaczamy krawędź 𝒗−𝒘 jako wykorzystaną, a wierzchołek 𝒘 jako nowy wierzchołek 𝒗
  - Jeśli po wykorzystaniu wszystkich krawędzi, nie znajdujemy się w wierzchołku wejściowym, to graf nie posiada cyklu Eulera, w przeciwnym wypadku, posiada go.


Działanie algorytmu Dijkstry:
  - Definiujemy Q jako zbiór wierzchołków, których jeszcze nie przejrzeliśmy i umieszczamy tam wszystkie wierzchołki.
  - Dla każdego wierzchołka wyznaczamy 2 wartości: koszt dotarcia oraz poprzedni wierzchołek w ścieżce
  - Określamy wierzchołek z którego zaczynamy. Nadajemy mu koszt dotarcia 0. Każdemu innemu wierzchołkowi ze zbioru Q przypisujemy koszt równy nieskończoności.
  - Dopóki zbiór Q nie jest pusty:
    - Wybieramy ze zbioru Q wierzchołek v o najmniejszym koszcie dotarcia i usuwamy ze zbioru Q.
    - Dla każdej krawędzi k wychodzącej z wierzchołka v:
       - Oznaczamy wierzchołek na drugim końcu krawędzi k jako u
       - Jeśli koszt dotarcia z wierzchołka v do wierzchołka u przez krawędź k jest mniejszy niż dotychczasowy koszt dotarcia do wierzchołka u:
          - Koszt dotarcia do wierzchołka u = koszt dotarcia do v + waga krawędzi k 
          - Poprzedni wierzchołek w ścieżce wierzchołka u = wierzchołek v	
