#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <sys/time.h>

double seconds(){
	struct timeval tmp;
	double sec;
	gettimeofday(&tmp, nullptr);
	sec = tmp.tv_sec + ((double)tmp.tv_usec) / 1000000.0;
	return sec;
}

int main(int argc, char* argv[]){
	int lim = atoi(argv[1]); //atoi = ASCII to Integer
	double sqrt_lim = sqrt(lim);
	double time1 = seconds();

	int max_set = std::round(sqrt_lim); //Round number of the maximun number of elements of the set
	std::vector<int> multiples; //Stablishment of a vector for storage of all the multiples of the naturals <max_conj, is maxtrix in continue memory
	std::vector<int> naturals(lim - 1); //Set of naturals numbers
	
	for(int i = 1; i <= lim; ++i){
		naturals[i - 1] = i; //For loop to put all the naturals until lim
	}
	
	for(int i = 2; i <= max_set; ++i){ //Goes over the posible primes
		for(int j = 1;  j <= lim;  ++j){ //Generates multiples of i
			int num_mult = i * naturals[j];
			if(1 < num_mult && num_mult < lim){ //This interpretation give the primes numbers lower than lim, it doesn't count the lim
				multiples.push_back(num_mult);
			}
		}
	}

	//The multiples matrix is sorted, the repeated numbers get eliminated, for after get the intersection between the naturals and the multiples
	std::sort(multiples.begin(), multiples.end());
	std::set <int> mult_nrep(multiples.begin(), multiples.end()); //A set cannot have repeted elements
	std::set <int> set_natur(naturals.begin(), naturals.end());
	
	std::vector<int> primes;
	std::set_symmetric_difference(mult_nrep.begin(), mult_nrep.end(), //Gets the interjection between the multiples set and the naturals set
						 		 set_natur.begin(), set_natur.end(),
								 std::back_inserter(primes));

	for(int i = 1; i < primes.size(); ++i){
			  std::cout << primes[i] << " ";
	}
	std::cout << std::endl;
	
	double time2 = seconds();
	double time_dif = time2 - time1;
	std::cout << "Time requiered:"  << time_dif << std::endl;

	return 0;
}
