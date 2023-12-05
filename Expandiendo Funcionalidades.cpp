#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include <variant>

class Variant {
public:
    std::variant<int, std::string> value;

    Variant(int val) : value(val) {}
    Variant(const std::string& val) : value(val) {}
};

class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    Environment() {}

    void addSymbol(const std::string& symbol, const Variant& value) {

        symbolTable.emplace(symbol, value);
    }

    Variant getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::out_of_range("El símbolo '" + symbol + "' no existe en la tabla de símbolos.");
        }
    }

    void removeSymbol(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            symbolTable.erase(it);
        } else {
            throw std::out_of_range("El símbolo '" + symbol + "' no existe en la tabla de símbolos.");
        }
    }

    bool symbolExists(const std::string& symbol) const {
        return symbolTable.find(symbol) != symbolTable.end();
    }
};

int main() {
    try {
        Environment myEnvironment;


        myEnvironment.addSymbol("x", Variant(10));
        myEnvironment.addSymbol("y", Variant("Hola, Mundo"));

        // Verificar si un símbolo existe y most
        std::string symbolToCheck = "x";
        if (myEnvironment.symbolExists(symbolToCheck)) {
            Variant value = myEnvironment.getSymbolValue(symbolToCheck);
            std::cout << "El valor de '" << symbolToCheck << "' es: ";
            if (std::holds_alternative<int>(value.value)) {
                std::cout << std::get<int>(value.value) << std::endl;
            } else if (std::holds_alternative<std::string>(value.value)) {
                std::cout << std::get<std::string>(value.value) << std::endl;
            }
        } else {
            std::cout << "El símbolo '" << symbolToCheck << "' no existe en la tabla de símbolos." << std::endl;
        }

        // Eliminar un símbolo
        std::string symbolToRemove = "y";
        myEnvironment.removeSymbol(symbolToRemove);
        std::cout << "Se eliminó el símbolo '" << symbolToRemove << "' de la tabla de símbolos." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}
