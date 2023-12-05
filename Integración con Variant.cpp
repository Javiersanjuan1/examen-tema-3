#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    // Definir un tipo para representar valores flexibles
    using Value = std::variant<int, double, std::string>;

    // Constructor que acepta un valor inicial
    Variant(const Value& val) : value(val) {}

    // Obtener el valor almacenado en Variant
    Value getValue() const {
        return value;
    }

    // Imprimir el valor almacenado
    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }

private:
    Value value;
};

class Environment {
public:
    // Método para agregar un símbolo y su valor a la tabla de símbolos
    void addSymbol(const std::string& symbol, const Variant::Value& value) {
        symbolTable[symbol] = value;
    }

    // Método para obtener el valor asociado a un símbolo en la tabla de símbolos
    Variant::Value getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second; // Devuelve el valor asociado al símbolo
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' no está definido." << std::endl;
            return Variant::Value{}; // Devuelve un valor predeterminado
        }
    }

private:
    std::map<std::string, Variant::Value> symbolTable;
};

int main() {
    Environment myEnvironment;

    // Agregar símbolos con valores de diferentes tipos
    myEnvironment.addSymbol("x", 10);
    myEnvironment.addSymbol("y", 3.14);
    myEnvironment.addSymbol("name", "John");

    // Obtener y mostrar los valores de los símbolos
    Variant::Value valueX = myEnvironment.getSymbolValue("x");
    Variant::Value valueY = myEnvironment.getSymbolValue("y");
    Variant::Value valueName = myEnvironment.getSymbolValue("name");

    Variant variantX(valueX);
    Variant variantY(valueY);
    Variant variantName(valueName);

    std::cout << "Valor de x: ";
    variantX.printValue();

    std::cout << "Valor de y: ";
    variantY.printValue();

    std::cout << "Valor de name: ";
    variantName.printValue();

    return 0;
}