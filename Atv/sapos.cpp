#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Sapo {
private:
    std::string nome;
    int identificador;
    int distanciaPercorrida;
    int quantidadePulosDados;
    int quantidadeProvasDisputadas;
    int vitorias;
    int empates;
    int quantidadeTotalPulos;
    
    static int distanciaTotalCorrida; // Atributo estático público

public:
    // Construtor
    Sapo(std::string n, int id) : nome(n), identificador(id), distanciaPercorrida(0), quantidadePulosDados(0),
                                  quantidadeProvasDisputadas(0), vitorias(0), empates(0), quantidadeTotalPulos(0) {}

    // Getters e Setters
    std::string getNome() const { return nome; }
    int getIdentificador() const { return identificador; }
    int getDistanciaPercorrida() const { return distanciaPercorrida; }
    int getQuantidadePulosDados() const { return quantidadePulosDados; }
    int getQuantidadeProvasDisputadas() const { return quantidadeProvasDisputadas; }
    int getVitorias() const { return vitorias; }
    int getEmpates() const { return empates; }
    int getQuantidadeTotalPulos() const { return quantidadeTotalPulos; }

    void setDistanciaTotalCorrida(int distancia) { distanciaTotalCorrida = distancia; }

    // Método Pular
    void pular(int maximoSalto) {
        int salto = rand() % maximoSalto + 1; // Salto aleatório entre 1 e maximoSalto
        distanciaPercorrida += salto;
        quantidadePulosDados++;
        quantidadeTotalPulos++;
    }

    // Incrementa uma vitória
    void incrementarVitoria() { vitorias++; }

    // Incrementa um empate
    void incrementarEmpate() { empates++; }

    // Incrementa a quantidade de provas disputadas
    void incrementarProva() { quantidadeProvasDisputadas++; }

    // Verifica se o sapo chegou ao final da corrida
    bool chegouAoFim() const {
        return distanciaPercorrida >= distanciaTotalCorrida;
    }

    // Método estático para definir a distância total da corrida
    static void definirDistanciaTotalCorrida(int distancia) {
        distanciaTotalCorrida = distancia;
    }
};

// Inicialização do atributo estático
int Sapo::distanciaTotalCorrida = 0;

int main() {
    srand(time(0)); // Inicializa a semente para números aleatórios

    Sapo sapo1("Sapo1", 1);
    Sapo sapo2("Sapo2", 2);

    // Definindo a distância total da corrida
    Sapo::definirDistanciaTotalCorrida(100);

    // Simulação da corrida
    while (!sapo1.chegouAoFim() && !sapo2.chegouAoFim()) {
        sapo1.pular(10); // Maximo salto é 10 unidades
        sapo2.pular(10);

        std::cout << sapo1.getNome() << " percorreu " << sapo1.getDistanciaPercorrida() << " metros." << std::endl;
        std::cout << sapo2.getNome() << " percorreu " << sapo2.getDistanciaPercorrida() << " metros." << std::endl;
    }

    // Determinação do vencedor
    if (sapo1.chegouAoFim() && sapo2.chegouAoFim()) {
        //se os dois passarem a linha de chegada no mesmo pulo dá empate, independente de se um pulou mais que o outro
        std::cout << "Empate!" << std::endl;
        sapo1.incrementarEmpate();
        sapo2.incrementarEmpate();
    } else if (sapo1.chegouAoFim()) {
        std::cout << sapo1.getNome() << " venceu!" << std::endl;
        sapo1.incrementarVitoria();
    } else {
        std::cout << sapo2.getNome() << " venceu!" << std::endl;
        sapo2.incrementarVitoria();
    }

    return 0;
}
