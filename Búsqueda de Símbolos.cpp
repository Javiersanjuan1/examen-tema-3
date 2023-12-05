#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {
    }

    void addSymbol(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }

    int getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);

        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return 0;
        }
    }

    int lookup(const std::string& symbol, int defaultValue = 0) const {
        auto it = symbolTable.find(symbol);

        // Verifica si el símbolo está en la tabla y devuelve su valor
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return defaultValue;
        }
    }

};

int main() {
    Environment myEnvironment;

    myEnvironment.addSymbol("x", 33);
    myEnvironment.addSymbol("y", 69);

    std::cout << "El valor de x es: " << myEnvironment.lookup("x") << std::endl;
    std::cout << "El valor de y es: " << myEnvironment.lookup("y") << std::endl;

    std::cout << "El valor de z es: " << myEnvironment.lookup("z") << std::endl;  // Devuelve el valor predeterminado (0)

    std::cout << "El valor de z es: " << myEnvironment.lookup("z", 100) << std::endl;  // Devuelve 100

    return 0;
}
