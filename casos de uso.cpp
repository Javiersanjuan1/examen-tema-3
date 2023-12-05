#include <iostream>
#include <string>
#include <variant>
#include <map>

class Variant {
public:
    std::variant<int, std::string, float> value;

    Variant() : value(0) {} // Default constructor

    Variant(int val) : value(val) {}
    Variant(const std::string& val) : value(val) {}
    Variant(float val) : value(val) {}
};

class Environment {
private:
    std::map<std::string, Variant> gameConfig;

public:
    Environment() {}

    void setGameConfig(const std::string& key, const Variant& value) {
        gameConfig[key] = value;
    }

    Variant getGameConfig(const std::string& key) const {
        auto it = gameConfig.find(key);
        if (it != gameConfig.end()) {
            return it->second;
        } else {
            throw std::out_of_range("La configuración '" + key + "' no existe en el entorno del juego.");
        }
    }
};

int main() {
    try {
        Environment gameEnvironment;

        // Configurar la velocidad del jugador y el título del juego
        gameEnvironment.setGameConfig("PlayerSpeed", Variant(5.0f));
        gameEnvironment.setGameConfig("Title", Variant("Mi Juego Genial"));

        // Obtener la configuración y mostrarla
        std::cout << "Velocidad del jugador: " << std::get<float>(gameEnvironment.getGameConfig("PlayerSpeed").value) << std::endl;
        std::cout << "Título del juego: " << std::get<std::string>(gameEnvironment.getGameConfig("Title").value) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}
