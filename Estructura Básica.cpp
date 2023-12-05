#include <map>
#include <string>
#include <Windows.h>

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {
    }

    void addSymbol(const std::string& symbol, int value) {
        symbolTable[symbol] = value;
    }

    // Función para obtener el valor de un sí
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


};

// Función
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Crea una instancia de la clase Environment
    Environment myEnvironment;

    return 0;
}
