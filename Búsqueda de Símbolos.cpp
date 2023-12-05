#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

class Environment {
private:
    // La tabla de símbolos utilizando std::map
    std::map<std::string, int> symbolTable;

public:
    // Constructor
    Environment() {
        // Puedes inicializar la clase según sea necesario
    }

    // Función para agregar un símbolo con su valor a la tabla de símbolos
    void addSymbol(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }

    // Función para obtener el valor de un símbolo de la tabla de símbolos
    int getSymbolValue(const std::string& symbol) const {
        // Utiliza find() para buscar el símbolo en el std::map
        auto it = symbolTable.find(symbol);

        // Verifica si el símbolo está en la tabla y devuelve su valor
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            // Puedes manejar el caso en que el símbolo no está en la tabla
            // Puedes lanzar una excepción, devolver un valor predeterminado, etc.
            // Por ahora, simplemente devolveremos 0 en caso de que no se encuentre.
            return 0;
        }
    }

    // Método para buscar un símbolo y devolver su valor
    int lookup(const std::string& symbol, int defaultValue = 0) const {
        // Utiliza find() para buscar el símbolo en el std::map
        auto it = symbolTable.find(symbol);

        // Verifica si el símbolo está en la tabla y devuelve su valor
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            // El símbolo no está en la tabla, devuelve el valor predeterminado
            return defaultValue;
        }
    }

    // Puedes agregar más funciones según sea necesario para manipular la tabla de símbolos
};

int main() {
    // Crea una instancia de la clase Environment
    Environment myEnvironment;

    // Agrega algunos símbolos para la prueba
    myEnvironment.addSymbol("x", 33);
    myEnvironment.addSymbol("y", 69);

    // Prueba el método lookup
    std::cout << "El valor de x es: " << myEnvironment.lookup("x") << std::endl;
    std::cout << "El valor de y es: " << myEnvironment.lookup("y") << std::endl;

    // Prueba lookup con un símbolo que no existe
    std::cout << "El valor de z es: " << myEnvironment.lookup("z") << std::endl;  // Devuelve el valor predeterminado (0)

    // Prueba lookup con un símbolo que no existe y proporcionando un valor predeterminado
    std::cout << "El valor de z es: " << myEnvironment.lookup("z", 100) << std::endl;  // Devuelve 100

    return 0;
}
