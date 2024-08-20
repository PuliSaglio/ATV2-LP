#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class Sapo {
private:
    std::string nome;
    int id;
    int distanciaPercorrida;
    int qntdPulosDados;
    int qntdProvasDisputadas;
    int vitorias;
    int empates;
    int qntdTotalPulos;
    int quantidade;

public:
    static int distanciaTotalCorrida;

    Sapo(std::string nome, int id) 
        : nome(nome), id(id), distanciaPercorrida(0), qntdPulosDados(0), 
          qntdProvasDisputadas(0), vitorias(0), empates(0), qntdTotalPulos(0), 
          quantidade(0) {}

    void pular(int maxDistanciaPulo) {
        int pulo = rand() % maxDistanciaPulo + 1;
        distanciaPercorrida += pulo;
        qntdPulosDados++;
        qntdTotalPulos++;
        quantidade++;  
    }

    bool terminouCorrida() const {
        return distanciaPercorrida >= distanciaTotalCorrida;
    }

    static void setDistanciaTotalCorrida(int distancia) {
        distanciaTotalCorrida = distancia;
    }

    std::string getNome() const { return nome; }
    int getId() const { return id; }
    int getDistanciaPercorrida() const { return distanciaPercorrida; }
    int getQntdPulosDados() const { return qntdPulosDados; }
    int getQntdProvasDisputadas() const { return qntdProvasDisputadas; }
    int getVitorias() const { return vitorias; }
    int getEmpates() const { return empates; }

    void incrementarProvasDisputadas() { qntdProvasDisputadas++; }
    void incrementarVitorias() { vitorias++; }
    void incrementarEmpates() { empates++; }
    void resetDistanciaPercorrida() { distanciaPercorrida = 0; }
    void resetQuantidadePulosDados() { qntdPulosDados = 0; }

    static int getDistanciaTotalCorrida() {
        return distanciaTotalCorrida;
    }
};

int Sapo::distanciaTotalCorrida = 0;

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    int numProvas;
    std::cout << "Digite o número de provas: ";
    std::cin >> numProvas;

    Sapo::setDistanciaTotalCorrida(100); 

    std::vector<Sapo> sapos;
    sapos.emplace_back("Sapo 1", 1);
    sapos.emplace_back("Sapo 2", 2);
    sapos.emplace_back("Sapo 3", 3);

    std::vector<Sapo*> vencedores;

    for (int prova = 0; prova < numProvas; ++prova) {
        std::cout << "Prova " << prova + 1 << ":\n";

        for (auto& sapo : sapos) {
            sapo.pular(10);
            if (sapo.terminouCorrida()) {
                vencedores.push_back(&sapo);
            }
        }

        if (vencedores.size() > 0) {
            int maxDistancia = 0;
            for (const auto& sapo : vencedores) {
                if (sapo->getDistanciaPercorrida() > maxDistancia) {
                    maxDistancia = sapo->getDistanciaPercorrida();
                }
            }

            std::vector<Sapo*> vencedoresDaProva;
            for (auto& sapo : sapos) {
                if (sapo.getDistanciaPercorrida() == maxDistancia) {
                    vencedoresDaProva.push_back(&sapo);
                }
            }

            if (vencedoresDaProva.size() > 1) {
                for (auto& sapo : vencedoresDaProva) {
                    sapo->incrementarEmpates();
                }
            } else if (vencedoresDaProva.size() == 1) {
                vencedoresDaProva[0]->incrementarVitorias();
            }

            for (auto& sapo : sapos) {
                sapo.incrementarProvasDisputadas();
                sapo.resetDistanciaPercorrida();
            }
        }

        vencedores.clear();
    }

    std::cout << "\nResultados finais:\n";
    for (const auto& sapo : sapos) {
        std::cout << sapo.getNome() << " percorreu " << sapo.getDistanciaPercorrida() << " metros, "
                  << "vitórias: " << sapo.getVitorias() << ", "
                  << "empates: " << sapo.getEmpates() << ", "
                  << "provas disputadas: " << sapo.getQntdProvasDisputadas() << ".\n";
    }

    return 0;
}
