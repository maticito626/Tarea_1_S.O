#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>
#include <algorithm>

/*
Para ejecutar el codigo en terminal de windows
1) ingrese a la carpeta del trabajo
2) mingw32-make
3) .\carrera.exe 100 3
*/

// Mutex para asegurar la sincronizacion al imprimir resultados
std::mutex mtx;

// Funcion para simular el avance de cada auto
void correrAuto(int id, int distanciaTotal, std::vector<int>& posiciones, int& lugar) {
    int distanciaRecorrida = 0;

    // Generadores aleatorios independientes por cada hilo
    std::random_device rd;
    std::mt19937 gen(rd() + id);  // Cada hilo tiene una semilla unica (semilla es el valor garantiza que el generador empiece en un estado único y produzca una secuencia diferente de números aleatorios)
    std::uniform_int_distribution<> avanceDist(1, 10);  // Avance aleatorio: 1 a 10 metros
    std::uniform_int_distribution<> pausaDist(100, 500);  // Pausa: 100 a 500 ms

 while (distanciaRecorrida < distanciaTotal) {
        int avance = avanceDist(gen);  // Genera avance aleatorio

        // Verifica si al avanzar supera o alcanza la distancia total
        if (distanciaRecorrida + avance >= distanciaTotal) {
            distanciaRecorrida = distanciaTotal;  // Asegura que no pase del límite

            // Imprime mensaje final del auto (protegido por mutex)
            {
                std::lock_guard<std::mutex> lock(mtx);
                lugar++;
                posiciones[id] = lugar;  // Guarda el lugar de llegada
                std::cout << "Auto" << id << " avanza " << avance 
                          << " metros y termina la carrera en el lugar " 
                          << lugar << "!\n";
            }
            break;  // Salir del bucle ya que el auto terminó
        } else {
            distanciaRecorrida += avance;

            // Imprime el avance del auto (protegido por mutex)
            {
                std::lock_guard<std::mutex> lock(mtx);
                std::cout << "Auto" << id << " avanza " << avance 
                          << " metros (total: " << distanciaRecorrida << " metros)\n";
            }
        }

        // Espera un tiempo aleatorio
        std::this_thread::sleep_for(std::chrono::milliseconds(pausaDist(gen)));
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Número de argumentos incorrectos. Uso: <distancia_total> <num_autos>\n";
        return 1;
    }

    // Obtiene argumentos de entrada
    int distanciaTotal = std::stoi(argv[1]);
    int numAutos = std::stoi(argv[2]);

    // Vectores para los hilos y posiciones de llegada
    std::vector<std::thread> autos;
    std::vector<int> posiciones(numAutos);
    int lugar = 0;  // Control del orden de llegada

    // Crea un hilo para cada auto
    for (int i = 0; i < numAutos; ++i) {
        autos.emplace_back(correrAuto, i, distanciaTotal, std::ref(posiciones), std::ref(lugar));
    }

    // Espera que todos los hilos terminen
    for (auto& autoHilo : autos) {
        autoHilo.join();
    }

 // Vector con los indices de los autos
    std::vector<int> indices(numAutos);
    for (int i = 0; i < numAutos; ++i) {
        indices[i] = i;
    }

    // Ordena los indices en segun el lugar de llegada
    std::sort(indices.begin(), indices.end(), [&posiciones](int a, int b) {
        return posiciones[a] < posiciones[b];
    });

    // Imprime los resultados finales en orden
    std::cout << "\nResultados Finales:\n";
    for (int i : indices) {
        std::cout << "Lugar " << posiciones[i] << ": Auto" << i << "\n";
    }

    return 0;
}