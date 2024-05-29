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
