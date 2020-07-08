# Introduction

This is a very easy hello world example. 

In a CMake project there has to be a CMakeLists.txt file in every level/directory of the project. 
Because this is a very easy example with just one directory, sources and CMake file are directly placed here. 

By calling the cmake command cmake will read the cmake list files and will generate makefiles to build the project.
The files will be generated in the directory you are currently in terminal (or in the directory you specified if you work with
GUI tool). It is common practice to make a seperate build directory in the project root directory.
```bash
cd PATH/TO/PROJECT/CppCodingDojo/cmake/linuxMagazin/helloWorld/
mkdir ./build
cd ./build
cmake ..
```
Now the make files have been generated inside the build directory and you can build the project.
```bash
make
```
The project has been build now and there should be an executable available, with the correct ending, 
depending on your OS.

# Text from article

Als Linux-Nutzer hat man sich über die Jahre an die Schritte »./configure; make; make install« zum Kompilieren von Softwarepaketen gewöhnt. Hinter ihnen verbergen sich die Autotools, eine Sammlung von Shell-, M4- und Perl-Skripten, die dabei hilft, Software zu schreiben, die sich portabel auf verschiedenen Unix-Derivaten kompilieren lässt. Für viele Entwickler sind die Autotools aber wegen der Vielzahl ineinander greifender Programme eine große Hürde.

Ein alternatives Buildsystem namens Cmake [1] schickt sich nun an, “die Art und Weise, wie alle Software-Entwickler arbeiten, zu ändern”, wie Bill Hoffman, einer der Cmake-Entwickler, es ausdrückt. Inzwischen setzt eine ganze Reihe kommerzieller und freier Projekte Cmake ein. Das größte und bekannteste ist derzeit KDE 4, das aus Millionen Zeilen Code besteht [2] und sich heute auf allen Plattformen (Linux, *BSD, Mac OS X, Windows mit Mingw wie auch den MS-Compilern) kompilieren lässt. Weitere Projekte sind Scribus, der Chicken Scheme Interpreter, das Strategiespiel Boson, Plplot und der Debian-Fork der CDR-Tools. Ethereal, Lyx, Open Wengo und Libgphoto sind gerade dabei, Cmake für ihre Zwecke zu evaluieren.

Cross-Plattform
Das Cross-Plattform-Make steht unter der BSD-Lizenz und wird von der amerikanischen Firma Kitware Inc. [3] entwickelt, die sich auf Visualisierungssoftware für medizinische Anwendungen spezialisiert hat. Cmake entstand im Rahmen des Insight Segmentation and Registration Toolkit [4] zur Visualisierung des menschlichen Körpers. Das Tool vereint die Funktionalität der verschiedenen Bestandteile der Autotools in sich:

Erzeugung von Makefiles
Unterstützung verschiedener Compiler und Linker auf unterschiedlichen Plattformen
Unterstützung von System-Introspection
Erweiterbarkeit durch Makros
Einzige Voraussetzung für den Einsatz von Cmake ist ein C++-Compiler. Daher funktioniert Cmake zum Beispiel auch unter Windows mit MS Visual Studio problemlos. Cmake ist aber nicht nur ein Makefile-Generator, es erzeugt auch Eingangsdateien für das native Buildsystem der jeweiligen Plattform.

So kann es unter Unix Makefiles und Projekte für Kdevelop 3 erzeugen, bei Mac OS X zusätzlich Projektdateien für Xcode und unter Windows Makefiles für Cygwin, Mingw, Msys, Borland und Microsoft Make sowie die IDEs von Microsoft ab Visual Studio 6. Unter Windows und Mac OS X dürfen Entwickler also auch mit Cmake weiter mit ihren gewohnten Entwicklungsumgebungen arbeiten und müssen nicht zurück auf die Kommandozeile.

Für die Qualitätssicherung unterstützt Cmake die Einbindung von Unit-Tests, Nightly Builds und weiteren Tools wie Valgrind [5] oder KWStyle [6]. Die Ergebnisse sammelt ein zentraler Dart-Dashboard-Server [7].

Hallo Welt
Alle Beispiele in diesem Artikel setzen Cmake 2.4.3 oder neuer voraus. Das Tool liest Dateien mit dem Namen »CMakeLists.txt« (Groß- undKleinschreibung beachten) ein und generiert daraus die gewünschten Makefiles beziehungsweise Projektdateien. Im folgenden Hallo-Welt-Beispiel die Datei »main.c« soll zu einem Programm kompiliert und dann gelinkt werden:

```c
#include <stdio.h>
int main()
{
   printf("Hallo Welt!n");
   return 0;
}
```

Die zugehörige »CMakeLists.txt« sieht wie folgt aus:

```cmake
add_executable(hallowelt main.c)
```

Der Cmake-Befehl »add_executable()« bedeutet, dass aus der Quelldatei »main.c« ein ausführbares Programm namens »hallowelt« entstehen soll. Cmake beachtet dabei die plattformspezifischen Eigenschaften, das Executable wird also unter typischen Unix-Systemen den Namen »hallowelt« bekommen, unter Windows dagegen »hallowelt.exe«.

Cmake erwartet (Listing 1) als Argument jenes Verzeichnis, in dem der Quelltext und die »CMakeLists.txt« liegen. Hat Cmake die »CMakeLists.txt« im aktuellen Verzeichnis gelesen, einen Compiler gesucht und Makefiles erzeugt, kann der Entwickler sein Projekt schließlich übersetzen (Listing 2).

Listing 1: Konfigurieren
```bash
01 ~/src/hallo/ $ cmake .
02 -- Check for working C compiler: /usr/bin/gcc
03 -- Check for working C compiler: /usr/bin/gcc -- works
04 -- Check size of void*
05 -- Check size of void* - done
06 -- Check for working CXX compiler: /usr/bin/c++
07 -- Check for working CXX compiler: /usr/bin/c++ -- works
08 -- Configuring done
09 -- Generating done
10 -- Build files have been written to: ~/src/tests/hallo
```

Listing 2: Übersetzen
```bash
01 ~/src/hallo $ make
02 Scanning dependencies of target hallowelt
03 [100%] Building C object CMakeFiles/hallo.dir/main.o
04 Linking C executable hallowelt
05 [100%] Built target hallowelt
06 ~/src/hallo $ ./hallowelt
07 Hallo Welt!
```

# Source
https://www.linux-magazin.de/ausgaben/2007/02/mal-ausspannen/
