# Definición del compilador y las banderas
CXX = g++
CXXFLAGS = -fopenmp -std=c++17 -Wall -Wextra -I./include/

# Directorios
BUILD_DIR = build

# Ejecutables
EXECS = main

# Target principal: compila todos los ejecutables
all: $(EXECS)

# Crear el directorio build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)  


# Compilar y ejecutar con el comando make main:
main: JosephC_calcular_primos.cpp $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $<  
	@echo "Ejecutando $@..."
	@$(BUILD_DIR)/$@ | bash -c 'tee >(grep -i -v -E "hilos|ejecutando|límite|Tiempo" > primos.txt)'


# Limpieza de archivos generados con make clean:
clean:
	rm -rf $(BUILD_DIR)   
	rm -f primos.txt

