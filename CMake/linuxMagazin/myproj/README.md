# Introduction
This is the second example of the article from Linux-Magazin. This is example is a little bit more complex, than the first one. 
It consists of an application and a library that is used by the application. 
From the files in directory lib a shared library should be built, whereas the library should be build with different files, 
depending on the used operating system. 
Furthermore an executable should be built from the files in app directory.

# Text from the article

Nach diesem recht einfachen Einstieg folgt nun ein komplexeres Projekt, das weitere Fähigkeiten von Cmake vorstellt. Es besteht aus einer Library und einem Programm, das diese Library benutzt. Die Quellen sind wie in Abbildung 1 organisiert. Im Verzeichnis »myproj/lib/« soll aus den Dateien »core.c«, »util.c« und ? je nach Plattform ? »unixtool.c« oder »wintool.c« eine Shared Library »libmyutils.so« entstehen, im Verzeichnis »myproj/app/« außerdem ein Programm »fooapp« aus den Dateien »main.cpp« und »process.cpp«.
Dieses Programm benutzt Funktionen aus »libmyutils.so«, das heißt, dass der Compiler beim Übersetzen von »fooapp« die Header »core.h« und »util.h« finden und der Linker »myapp« zu »libmyutil.so« linken muss. Nach dem Buildvorgang soll Cmake das Programm und die Library installieren. Die Inhalte der einzelnen »CMakeLists.txt« zeigen die Listings 3a bis 3c.

### Listing 3a: »myproj/CMakeLists.txt«
```cmake
01 project(FooProject)
02 add_subdirectory(lib)
03 add_subdirectory(app)
```
### Listing 3b: »myproj/lib/CMakeLists.txt«
```cmake
01 set(libSrcs core.c util.c)
02 
03 if (UNIX)
04    set(libSrcs ${libSrcs} unixtool.c)
05 else (UNIX)
06    set(libSrcs ${libSrcs} wintool.c)
07 endif (UNIX)
08 
09 add_library(util SHARED ${libSrcs})
10 
11 install(TARGETS util DESTINATION lib)
```
### Listing 3c: »myproj/app/CMakeLists.txt«
```cmake
01 include_directories(${CMAKE_SOURCE_DIR}/lib)
02 
03 set(fooappSrcs main.cpp process.cpp)
04 add_executable(fooapp ${fooappSrcs})
05 
06 target_link_libraries(fooapp util)
07 
08 install(TARGETS fooapp DESTINATION bin)
```
Die Datei »myproj/CMakeLists.txt« verzweigt mit »add_subdirectory« in die Unterverzeichnisse »lib« und »app«. Cmake erwartet daraufhin in beiden Verzeichnissen jeweils eine »CMakeLists.txt«, die es verarbeitet. Alle anderen eventuell vorhandenen Unterverzeichnisse ignoriert Cmake.
## Achtung: Schreibweise
In Zeile 1 von »myproj/lib/CMakeLists.txt« (Listing 3b) kommt mit »set()« einer der wichtigsten Cmake-Befehle vor. Er weist einer Variablen einen Wert oder eine Liste von Werten zu. Im Beispiel ist »libSrcs« eine Liste mit den beiden Elementen »core.c« und »util.c«. Bei Befehlen spielt die Groß- undKleinschreibung keine Rolle, bei Variablennamen und Argumente jedoch schon. Argumente können sich auch über mehrere Zeilen erstrecken. So sind die beiden folgenden Beispiele äquivalent:
```cmake
SET(libSrcs core.c util.c)
set (libSrcs
   core.c
   util.c
   )
```
Wie Zeile 3 von Listing 3b zeigt, gibt es auch in Cmake ein »if«. Die nach dem Schlüsselwort folgende Bedingung ist als Argument für das zugehörige optionale »else()« und das zwingend erforderliche »endif()« zu wiederholen. Dadurch ist bei »else()« und »endif()« leicht zu erkennen, zu welchem »if()« sie gehören. Zeile 4 fügt beim Kompilieren auf einem Unix-System die Datei »unixtool.c« zur Liste »libSrcs« hinzu:
```cmake
set(libSrcs ${libSrcs} unixtool.c)
```
Der Ausdruck »${libSrcs}« liefert den Wert der Variablen, sodass Zeile 4 aufgelöst wird zu:
```cmake
set(libSrcs core.c util.c unixtool.c)
```
Entsprechend verwendet Cmake unter Windows die Datei »wintool.c«. In Zeile 9 von Listing 3b fügt »add_library()« dem Projekt eine Shared Library hinzu. Die Syntax entspricht der von »add_executable()«: erst der (logische) Name der Library, dann die Quelldateien, hier mit Hilfe der Variablen »libSrcs«. Das Argument »SHARED« legt fest, dass es sich um eine Shared Library handelt, andernfalls erzeugt Cmake eine statische.

Wie bei »add_executable()« passt Cmake auch hier den Name an die Plattform an, also unter Linux »libutil.so«, unter Mac OS X »libutil.dylib« und unter Windows »util.dll«. Die jeweiligen Prä- und Suffixe fügt es automatisch hinzu, in den Cmake-Dateien steht immer nur der logische Name der Library.

## Libraries
Der »install()«-Befehl in Zeile 11 von Listing 3b weist Cmake dazu an, Installationsroutinen für das Target »util« zu erzeugen. Die Libutil wandert so in das Verzeichnis »lib« relativ zum Standardinstallationspfad, hier also »/usr/local/lib«. Nach Abarbeitung dieser Datei geht Cmake zurück zu »myproj/CMakeLists.txt« und verzweigt von dort in »myproj/app/CMakeLists.txt« (Listing 3c).

Hier erzeugt in Zeile 4 das schon bekannte »add_executable()« die Applikation »fooapp«. Anders als bei den Autotools dürfen Entwickler bei Cmake die Namen der Variablen frei wählen. Das ist ein Grundprinzip von Cmake: Nichts geschieht automatisch hinter dem Rücken des Anwenders, es gibt keine magischen Datei- oder Variablennamen.

Der »target_link_libraries()«-Befehl in Zeile 6 legt fest, welche Libraries das Target »fooapp« verwendet. In diesem Beispiel soll es die Library »util« sein, die in »myproj/lib« erzeugt wird. Cmake weiß, dass es sich um diese Library handelt, und kümmert sich automatisch um Folgendes:

* »util« vor »fooapp« kompilieren;
* »fooapp« zu »util« »linken«;
* »RPATH« so setzen, dass »fooapp« beim Starten die uninstallierte Library »util« benutzt;
* »RPATH« beim Installieren den Wünschen des Nutzers anpassen.

## In- und Out-of-Source
In dem ersten einfachen Beispiel wurde Cmake im Wurzelverzeichnis des Quelltextbaums ausgeführt, dort startete auch »make« zum Kompilieren der Software. Das ist die herkömmliche Vorgehensweise, die bei Cmake In-Source-Build heißt. Zusätzlich unterstützt Cmake auch Out-of-Source-Builds, bei denen die Software nicht im Quelltextbaum kompiliert wird, sondern in einem beliebigen anderen Verzeichnis.

Out-of-Source- besitzen gegenüber den In-Source-Builds mehrere Vorteile: Der Quelltextbaum bleibt sauber und übersichtlich, er wird nicht durch Objektdateien oder andere Zwischendateien aufgebläht. Soll der Entwickler das Projekt komplett neu erzeugen, kann er einfach das ganze Buildverzeichnis löschen. Zu einem Quelltextverzeichnis darf er beliebig viele Buildverzeichnisse angelegen, etwa für ein Release- und ein Debug-Build. Um das obige Beispiel Out-of-Source zu kompilieren, legt er ein Buildverzeichnis an und startet Cmake dort. Wie beim ersten Beispiel ist der Pfad zum Quelltextverzeichnis das Argument. Listing 4 zeigt den Ablauf des Cmake- und Buildvorgangs.

### Listing 4: Out-of-Source-Build (1)
```
01 ~/src $ mkdir myproj-build
02 ~/src/ $ cd myproj-build
03 ~/src/myproj-build $ cmake ~/src/myproj
04 -- Check for working C compiler: /usr/bin/gcc
05 -- Check for working C compiler: /usr/bin/gcc -- works
06 -- Check size of void*
07 -- Check size of void* - done
08 -- Check for working CXX compiler: /usr/bin/c++
09 -- Check for working CXX compiler: /usr/bin/c++ -- works
10 -- Configuring done
11 -- Generating done
12 -- Build files have been written to: ~/src/myproj-build
13 ~/src/myproj-build $ make
14 [ 20%] Building C object lib/CMakeFiles/util.dir/core.o
15 [ 40%] Building C object lib/CMakeFiles/util.dir/util.o
16 [ 60%] Building C object lib/CMakeFiles/util.dir/unixtool.o
17 Linking C shared library libutil.so
18 [ 60%] Built target util
19 Scanning dependencies of target fooapp
20 [ 80%] Building CXX object app/CMakeFiles/fooapp.dir/main.o
21 [100%] Building CXX object app/CMakeFiles/fooapp.dir/process.o
22 Linking CXX executable fooapp
23 [100%] Built target fooapp
```

Nach dem Kompilieren installiert das Kommando »make install« die Software. Die von Cmake erzeugten Makefiles stellen noch einige weitere Make-Targets zur Verfügung, eine Übersicht gibt »make help«. Ein weiteres Buildverzeichnis »myproj-build-2« soll im Folgenden dazu dienen, die Erzeugung von Kdevelop-Projektdateien zu demonstrieren, die Cmake ebenfalls beherrscht:

```
$ cd myproj-build-2
$ cmake ~/src/myproj -GKDevelop3
-- Check for working C compiler: /usr/bin/gcc
...
-- Build files have been written to: ~/src/myproj-build-2
```

Im Buildverzeichnis findet sich nun untere anderem die Kdevelop-Projektdatei »FooProject.kdevelop«, die sich mit Kdevelop öffnen lässt (Abbildung 2). Den Projektnamen bezieht Cmake vom »project()«-Befehl in Zeile 1 von »myproj/CMakeLists.txt«.

Bei Out-of-Source-Builds sind ein paar Dinge zu beachten. Im vorigen Beispiel nutzt die Anwendung Funktionen aus der Library »util« und verwendet dazu Header aus dem Verzeichnis »~/src/myproj/lib/«. Deshalb wird dieses Verzeichnis zum Include-Pfad des Compilers hinzugefügt. Dies geschieht in Zeile 1 von Listing 3c durch das Kommando »include_directories(${CMAKE_SOURCE_DIR}/lib)«.



# Source
https://www.linux-magazin.de/ausgaben/2007/02/mal-ausspannen/2/
