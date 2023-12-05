#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {}

    void addSymbol(const std::string& symbol, int value) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            throw std::invalid_argument("El simbolo ya existe en la tabla de simbolos.");
        }
        symbolTable[symbol] = value;
    }

    int getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::out_of_range("El simbolo no existe en la tabla de simbolos.");
        }
    }

    void insert(const std::string& symbol, int value) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            if (it->second != value) {
                throw std::invalid_argument("Intento de insertar un simbolo ya existente con un valor diferente.");
            }
        } else {
            symbolTable[symbol] = value;
        }
    }

    int lookup(const std::string& symbol, int defaultValue = 0) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            return defaultValue;
        }
    }
};

int main() {
    try {
        Environment myEnvironment;

        myEnvironment.addSymbol("x", 10);
        myEnvironment.addSymbol("y", 20);

        std::cout << "El valor de z es: " << myEnvironment.lookup("z") << std::endl;

        myEnvironment.insert("x", 30);

    } catch (const std::exception& e) {
        std::cerr << "Excepcion: " << e.what() << std::endl;
    }

    return 0;
}
