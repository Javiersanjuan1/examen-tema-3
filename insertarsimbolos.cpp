#include <map>
#include <string>
#include <iostream>

class Environment {
private:
    // La tabla de símbolos u
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

    // Método para insertar un símbolo en la tabla de símbolos
    void insert(const std::string& symbol, int value) {
        // Verifica si el símbolo ya existe en la tabla
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            // El símbolo ya existe, puedes manejarlo según tus necesidades
            std::cout << "El símbolo '" << symbol << "' ya existe en la tabla de símbolos." << std::endl;
        } else {
            // El símbolo no existe, agrégalo a la tabla
            addSymbol(symbol, value);
            std::cout << "Se añadió el símbolo '" << symbol << "' con el valor " << value << "." << std::endl;
        }
    }

    // Puedes agregar más funciones según sea necesario para manipular la tabla de símbolos
};

int main() {
    // Crea una instancia de la clase Environment
    Environment myEnvironment;

    // Prueba el método insert
    myEnvironment.insert("x", 10);
    myEnvironment.insert("y", 20);
    myEnvironment.insert("x", 30); // Intenta agregar un símbolo existente

    // Prueba obtener el valor de un símbolo
    std::cout << "El valor de x es: " << myEnvironment.getSymbolValue("x") << std::endl;
    std::cout << "El valor de y es: " << myEnvironment.getSymbolValue("y") << std::endl;

    return 0;
}
