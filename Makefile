# Variables
CXX = g++ #indica el compilador a usar
CXXFLAGS = -std=c++11 -pthread -Wall #especifica que usará el estandar de C++ 11, habilita el uso de hilos, activa todas las advertencias comunes del compilador para detectar errores o malas prácticas
TARGET = carrera#define el nombre del ejecutable que se generará
SRC = main.cpp #archivo de código fuente principal

# Regla principal para compilar
all: $(TARGET) #genera el Target

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
#$(SRC) compila el main.cpp

# Regla para limpiar archivos generados
clean:
rm -f $(TARGET) 
#elimina el ejecutable con mingw32-make clean}
#asegúrase de tener las herramientas Unix instaladas con MinGW o Git Bash.
	
