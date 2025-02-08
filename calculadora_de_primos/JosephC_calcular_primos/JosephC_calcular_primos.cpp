#include <iostream> // Para utilizar entrada y salida por consola.
#include <vector> // Para utilizar vectores.
#include <omp.h>  // OpenMP para paralelizar.
#include <chrono>  // Para medir el tiempo.

// Para usar las funciones de la librerías estándar y chrono sin el prefijo std:: y chrono::
using namespace std; 
using namespace chrono;


// Función para utilizar la criba de Eratóstenes.
void Eratosthenes_sieve(int N) {
    if (N < 2) return; // Los números primos son iguale so mayores a 2.

    int size = (N + 1) / 2;  // Tamaño del vector con solo los números impares.

    vector<bool> primos(size, true);  // Crea un vector con todos los elementos verdaderos.

    primos[0] = false;  // El número 1 no es primo.

    // Obtener el número de hilos.
    int num_hilos = omp_get_max_threads();

    // Criba de Eratóstenes optimizada para números impares.
    // Recorre hasta la raíz de N (hatsa que el número al cuadrado sea menor a N).
    for (int i = 1; (2 * i + 1) * (2 * i + 1) <= N; i++) { 
        if (primos[i]) {
            // Paralelizar el ciclo que marca los múltiplos de los primos
            #pragma omp parallel for
            // Recorre los múltiplos impares de los número primos empezando en el número al cuadrado.
            // El incremento es el doble del núemro para saltarse los múltiplos pares.
            for (int j = (2 * i + 1) * (2 * i + 1); j <= N; j += 2 * (2 * i + 1)) { 
                primos[(j - 1) / 2] = false;  // Marca múltiplos impares como no primos, asociándoles un índice del vector.
            }
        }
    }

    // Imprimir los números primos
    cout << "Primos hasta " << N << ": " << endl;
    cout << 2 << endl;  // El número 2 es primo.


    // Se recorre el vector y se imprime el núemro impar asociado a las posiciones marcadas con verdadero.
    for (size_t i = 1; i < primos.size(); ++i) {
        if (primos[i]) {
            cout << 2 * i + 1 << endl;  // Convertir el índice en el número impar.
        }
    }

    cout << "Número de hilos utilizados: " << num_hilos << endl;
}

int main() {
    int N;
    cout << "Introduce el límite: ";
    cin >> N;  // Solicitar el valor de N al usuario

    auto inicio = high_resolution_clock::now();  // Empieza a medir el tiempo.

    Eratosthenes_sieve(N);  // Invocar la función Eratosthenes_sieve con el valor de N

    auto fin = high_resolution_clock::now(); // Termina de medir el tiempo.

    duration<double> duracion = fin - inicio;  // Calcular la duración
    cout << "Tiempo total de ejecución: " << duracion.count() << " segundos." << endl;

    return 0;
}

