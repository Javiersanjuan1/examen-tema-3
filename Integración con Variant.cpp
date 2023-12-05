#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    using Value = std::variant<int, double, std::string>;

    Variant(const Value& val) : value(val) {}

    Value getValue() const {
        return value;
    }

    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }

private:
    Value value;
};

class Environment {
public:
    void addSymbol(const std::string& symbol, const Variant::Value& value) {
        symbolTable[symbol] = value;
    }

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

    myEnvironment.addSymbol("x", 10);
    myEnvironment.addSymbol("y", 3.14);
    myEnvironment.addSymbol("name", "John");

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