#include <iostream>
#include <cmath>

// Classe base abstrata para Figuras Geométricas Espaciais
class FiguraEspacial {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularVolume() const = 0;
    virtual ~FiguraEspacial() {}
};

// Classe para Pirâmide
class Piramide : public FiguraEspacial {
    double base, altura, arestaBase;
public:
    Piramide(double b, double h, double a) : base(b), altura(h), arestaBase(a) {}

    double calcularArea() const override {
        double apotema = std::sqrt((altura * altura) + ((arestaBase / 2) * (arestaBase / 2)));
        return (base * base) + 2 * base * apotema;
    }

    double calcularVolume() const override {
        return (base * base * altura) / 3;
    }
};

// Classe para Cubo
class Cubo : public FiguraEspacial {
    double aresta;
public:
    Cubo(double a) : aresta(a) {}

    double calcularArea() const override {
        return 6 * aresta * aresta;
    }

    double calcularVolume() const override {
        return std::pow(aresta, 3);
    }
};

// Classe para Paralelepípedo
class Paralelepipedo : public FiguraEspacial {
    double aresta1, aresta2, aresta3;
public:
    Paralelepipedo(double a1, double a2, double a3) : aresta1(a1), aresta2(a2), aresta3(a3) {}

    double calcularArea() const override {
        return 2 * (aresta1 * aresta2 + aresta1 * aresta3 + aresta2 * aresta3);
    }

    double calcularVolume() const override {
        return aresta1 * aresta2 * aresta3;
    }
};

// Classe para Esfera
class Esfera : public FiguraEspacial {
    double raio;
public:
    Esfera(double r) : raio(r) {}

    double calcularArea() const override {
        return 4 * M_PI * raio * raio;
    }

    double calcularVolume() const override {
        return (4.0 / 3.0) * M_PI * std::pow(raio, 3);
    }
};

int main() {
    FiguraEspacial* figuras[4];
    
    // Criando os objetos
    figuras[0] = new Piramide(3, 4, 5); // Base = 3, Altura = 4, Aresta da Base = 5
    figuras[1] = new Cubo(3);           // Aresta = 3
    figuras[2] = new Paralelepipedo(3, 4, 5); // Arestas = 3, 4, 5
    figuras[3] = new Esfera(3);         // Raio = 3
    
    // Calculando e exibindo as áreas e volumes
    for (int i = 0; i < 4; i++) {
        std::cout << "Figura " << i + 1 << ":\n";
        std::cout << "Área: " << figuras[i]->calcularArea() << "\n";
        std::cout << "Volume: " << figuras[i]->calcularVolume() << "\n\n";
    }

    // Limpando a memória
    for (int i = 0; i < 4; i++) {
        delete figuras[i];
    }

    return 0;
}
