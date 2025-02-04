#include <iostream>
#include <vector>
#include <sys/time.h>
#include <cmath>
using namespace std;

// Los números triangulares son aquellos resultantes de sumar los primeros 'n' números naturales.
// El '3' es el único número triangular primo. Por lo tanto, podemos descartar el resto.
void triangular(vector<bool>* list, int end){
   int total = 3;
   for(int i=3; total<end; i++){
		(*list)[total] = false;
		// cout << total << endl;
		total += i;
   }
}

// Eliminar todos los múltiplos de cada primo encontrado.
void multiples(vector<bool>* list, int end, int prime){
	
	for(int i=2; i<end/prime; i++){
		if((*list)[i*prime] == true){
			(*list)[i*prime] = false;
		}
	}
}

// Para comprobar que un número N es primo mediante 'módulos' (%), solo es necesario iterar hasta sqrt(N).
// Verificar si 'pos' es divisible entre 'i', con 2 <= i < sqrt(pos).
void primeTest(vector<bool> *list, int end, int pos){
	for(int i = 2; i <= sqrt(pos); i++){
		if((*list)[i] == true && pos%i == 0){
			(*list)[pos] = false;
		}
	}
}

double seconds(){
	struct timeval tmp;
	double sec;
	gettimeofday( &tmp, (struct timezone *)0 );
	sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;

	return sec;
}


// --- Main function ---
int main(int argc, char* argv[]){

   if(argc != 2){
      cerr << "Usage: " << argv[0] << " [int 'end']" << endl;
		exit(1);
   }
	
// Recorrer todos los valores desde '3' hasta el número 'N', para cada N < end.
	int end = atoi(argv[1]);
	double time1 = seconds();
	vector<bool>* numList = new vector<bool>(end, true);

	// Eliminar los números triangulares.
	triangular(numList, end);

	// Ciclo hasta 'end'.
	(*numList)[4] = false;
	for(int N = 6; N<end; N++){
		primeTest(numList, end, N);
		if((*numList)[N] == true){
			multiples(numList, end, N);
		}
	}
	//Imprimir primos resultantes.
	int count = 0;
	//cout << " -|--|| Primos encontrados ||--|- " << endl;
	for(int N =2; N<end; N++){
		if((*numList)[N] == true){
			count += 1;
			// cout << N << endl;
		}
	}

	delete numList;
	double time2 = seconds();

	cout << "Límite superior: " << end << endl;
	cout << "Tiempo: " << time2-time1 << " (s)" << endl;
	cout << "Números primos encontrados: " << count << endl;
}
