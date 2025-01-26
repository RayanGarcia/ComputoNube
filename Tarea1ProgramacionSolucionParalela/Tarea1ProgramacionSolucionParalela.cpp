// Tarea1ProgramacionSolucionParalela.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <omp.h>
#include <vector>
#include <cstdlib> // Para manejo de aleatorios rand()
#include <ctime> // para la semilla del aleatorio

int main()
{
	// Definimos la longitud del arrayn en 1000
	const int size = 1000;

	// Iniciaiuzamos los arrays
	std::vector<int> arrayA(size);
	std::vector<int> arrayB(size);
	std::vector<int> arrayR(size);

	// Si queremos que sea reproducible, establecemos la semilla
    //const unsigned int seed = 24;
    //std::srand(seed);

    // Establecemos una semilla basada en el tiempo actual
    // de esta manera cada vez que se corra el codigo se establece una semilla nueva
    // por lo que los numeros a sumar de los arreglos van a ser distintos
    std::srand(static_cast<unsigned int>(std::time(0)));

	

	// Llenamos los arrays con los valores aleatorios
	for (int i = 0; i < size; i++) {
		// Usamos valores aleatorios entre 0 y 99
		arrayA[i] = std::rand() % 100;  
		arrayB[i] = std::rand() % 100;
	}

    // Loop con paralelo para calcular la suma
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        arrayR[i] = arrayA[i] + arrayB[i];
    }

    // Imprimimos los primeros 20 elementos de A para validar
    std::cout << "Array A: ";
    for (int i = 0; i < 20; i++) {  
        std::cout << arrayA[i] << " ";
    }
    std::cout << "\n";

    // Imprimimos los primeros 20  elementos de B para validar
    std::cout << "Array B: ";
    for (int i = 0; i < 20; i++) {  
        std::cout << arrayB[i] << " ";
    }
    std::cout << "\n";

    // Imprimimos los primeros 20  elementos de R para validar
    std::cout << "Array R (Result): ";
    for (int i = 0; i < 20; i++) {  // Print first 10 elements
        std::cout << arrayR[i] << " ";
    }
    std::cout << "\n";

    return 0;

}
