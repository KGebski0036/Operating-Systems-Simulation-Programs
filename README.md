# Programy Symulacyjne - Sprawozdanie

Program symulacyjny ma na celu symulację działania wybranych algorytmów planowania czasu procesora oraz algorytmów zastępowania stron. Program ten pozwala użytkownikowi na porównanie wydajności i efektywności różnych podejść do zarządzania zasobami w systemach operacyjnych.

## Użyte technologie

<div align="center">
	<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="30" alt="cplusplus  logo"  />
	<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cmake/cmake-original.svg" height="30" alt="cmake logo"  />
</div>

## Uruchomienie programu

Program został napisany w języku C++17 i do jego kompilacji wymaga użycia narzędzia CMake. Został przetestowany wyłącznie na systemach operacyjnych z Linuxem.

### Kompilacja

Aby skompilować program należy wprowadzić następujące komendy z poziomu katalogu projektu:

```bash
	mkdir build
	cd build
	cmake ..
	make
```

### Start symulacji

Po kompilacji projektu należy uruchomić program utwożony w katalogu `build` o nazwie `simulations`.

## Dokumentacja kodu

### Main

Plik `main.cpp` jest wykorzystywany do przekazania klasą `TaskAlgorithmTester` i `PageAlgorithmTester` odpowiednich parametrów, które można zmienić na potrzeby symulacji.
Plik ten implementuje też wybór odpowiedniego algorytmu.
11

### Tasks
---
<div align="center">
	<img src="./assets/Tasks.drawio.png" alt="Task diagram"  />
</div>

---

1. *Task Algorithm* - jest to klasa czysto wirtualna po której dziedziczą wszystkie algorytmy przydzielania pracy procesora do zadań.
2. *Task* - klasa mająca reprezentowć zadanie przydzielonw procesorowi.
3. *Task Algorithm Tester* - klasa odpowiedzialna za wytworzenie losowych lub wczytanie z pliku zadań przekazywanych do odpowiedniego algorytmu.
4. **Algorytmy** - wszystkie algorytmy są zaimplementowane w klasie o takiej samej nazwie i dziedziczą po interfejsie *TaskAlgorithm*. Implementacja algorytmu znajduje się w funkcji `startAlgorithm()`.
	- **SJF** (*Shortest-Jobtime-First*) - algorytm wykonujący najpierw zadania o najkrótszym czasie wykonywania.
	- **FCFS** (*First-Come, First-Served*) - algorytm wykonujący najpierw zadania, które dotarły do procesora najwcześniej.
	- **LCSF** (*Last-Come, Served-First*) - algorytm wykonujący najpierw zadania, które dotarły do procesora najpóźniej.
	- **Round Robin** - algorytm przydzielający kolejno określony czas (`quantum_`) każdemu zadaniu, a jeśli zadanie nie zostanie wykonane w tym czasie, zostaje przesunięte na koniec kolejki.



### Pages
---
<div align="center">
	<img src="./assets/Pages.drawio.png" alt="Page diagram"  />
</div>

---

1. *Page Algorithm* - jest to klasa czysto wirtualna po której dziedziczą wszystkie algorytmy wczytywania stron do pamięci.
2. *Page* - klasa mająca reprezentowć stronę w pamięci komputera.
3. *Page Algorithm Tester* - klasa odpowiedzialna za wytworzenie losowych lub wczytanie z pliku stron przekazywanych do odpowiedniego algorytmu.
4. **Algorytmy** - wszystkie algorytmy są zaimplementowane w klasie o takiej samej nazwie i dziedziczą po interfejsie *PageAlgorithm*. Implementacja algorytmu znajduje się w funkcji `startAlgorithm()`.
	- **MFU** (*Most Frequently Used*) - zastępuje stronę w pamięci do której było najwięcej odsłon.
	- **LFU** (*Least Frequently Used*) - zastępuje stronę w pamięci do której było najmniej odsłon.
	- **LRU** (*Least Recently Used*) - zastępuje stronę w pamięci która była używana najdawniej.
	- **FIFO** (*First In First Out*) - zastępuje stronę w pamięci która była dodana najdawniej.
