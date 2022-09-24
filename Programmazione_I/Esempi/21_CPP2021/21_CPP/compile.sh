#- File *.o: a relocatable file holds code and data suitable for linking 
#with other object files to create an executable or a shared object file.
#- An executable file (EX: a.out) holds a program suitable for execution; the file specifies how exec(BA_OS) creates a program's process image.

g++ -g  -c dado.cpp #genera un file dado.o
g++ -g -c moneta.cpp
g++ -g  -c serbatoio.cpp
g++ -g  -c conto_corrente.cpp
g++ -g -c bersaglio.cpp
g++ -g -c frazione.cpp

g++  -g -c gestore_monete.cpp
g++  -g -c automobile.cpp
g++  -g -c distributore_bevande.cpp

g++  -g 21_00.cpp -o 21_00 dado.o
g++  -g 21_01.cpp -o 21_01 dado.o

g++  -g 21_02.cpp -o 21_02 moneta.o
g++  -g 21_03.cpp -o 21_03 moneta.o

g++  -g 21_04.cpp -o 21_04 serbatoio.o
g++  -g 21_05.cpp -o 21_05 serbatoio.o
g++  -g 21_06.cpp -o 21_06 serbatoio.o

g++  -g 21_07.cpp -o 21_07 conto_corrente.o
g++  -g 21_08.cpp -o 21_08 bersaglio.o
g++  -g 21_09.cpp -o 21_09 frazione.o

g++  -g -c ruota.cpp

g++ -g  21_10_auto.cpp -o 21_10 automobile.o serbatoio.o
g++ -g  21_11_distributore.cpp -o 21_11 serbatoio.o gestore_monete.o distributore_bevande.o 
g++  -g 21_12_ruota.cpp ruota.o -o 21_ruota
