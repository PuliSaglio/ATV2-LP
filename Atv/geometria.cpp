#include <iostream>
using namespace std;

//uso de polimorfismo na classe geometria_espacial atraves do virtual
class geometria_espacial{
    protected:
        double area_base;
        double area_lateral;
        double aresta1;
        double aresta2;
        double aresta3;
        double altura;
        double pi = 3.14;
        double r;

    public:
       virtual void set()=0;
       virtual double area()=0;
       virtual double volume()=0;

};

// classes separadas para cada figura geometrica, pois assim conseguimos passar apenas os valores necessarios para o calculo 
class piramide: public geometria_espacial{
    public:
     void set(){
        cout<<"Digite o valor da aresta da base:";
        cin >> aresta1;
        cout<<"Digite a altura:";
        cin >> altura;
        area_base = aresta1 * aresta1;
        area_lateral = (aresta1 * altura)/2;

     }

    double area(){
        return area_base + (4 * area_lateral);

    }

    double volume(){
        return (1.0/3) * area_base * altura;
    }
};

class cubo: public geometria_espacial{
    public:
    void set(){
        cout<<"Digite o valor da base:";
        cin>> aresta1;
    }   

    double area(){
        return 6*(aresta1 * aresta1);

    }

    double volume(){
        return aresta1 * aresta1 * aresta1;

    }
};

class paralelepipedo: public geometria_espacial{
    public:
    void set(){
        cout<<"Digite o valor da base:";
        cin>> aresta1;
        cout<<"Digite o valor da altura:";
        cin>> aresta2;
        cout<<"Digite o valor da largura:";
        cin>> aresta3;
    } 
    double area(){
        return (2* aresta1 * aresta2)+ (2 * aresta2 * aresta3) + (2 * aresta3 * aresta1);

    }

    double volume(){
        return aresta1 * aresta2 * aresta3;
    }
};

class esfera: public geometria_espacial{
    public:
    void set(){
        cout<<"Digite o valor do raio:";
        cin>> r;
    }
    double area(){
        return 4 * pi * (r*r);

    }

    double volume(){
        return (4.0/3) * pi * (r*r*r);
    }
};

int main()
{
    int num;
    geometria_espacial* figura = nullptr;

    //ponteiro de função para as classes criadas
    double (geometria_espacial::*func_area)() = &geometria_espacial::area;
    double (geometria_espacial::*func_volume)() = &geometria_espacial::volume;

    //laço de repetição para que o usario possa repetir quantas vezes quiser.
    do{
    std::cout<<"Escolha a figura geometrica:\n";
    std::cout<<"1 - Piramide\n";
    std::cout<<"2 - Cubo\n";
    std::cout<<"3 - Paralelepipedo\n";
    std::cout<<"4 - Esfera\n";
     
    std::cin >> num;

    //uso do switch case para que o usuario possa escolher qual figura geometrica quer calcular
    switch (num){
    case 1:
        figura = new piramide();
        break;
    
    case 2:
        figura = new cubo();
        break;
        
    case 3:
        figura = new paralelepipedo();
        break;
    
    case 4:
        figura = new esfera();
        break;

    default:
        cout<<" Escolha inválida\n";
        break;
    }

        figura -> set();
        cout<<" Area:" << (figura->*func_area)() << endl;
        cout<<" volume: " << (figura->*func_volume)() << endl;
        delete figura; 

    } while(num != 0);
    
    return 0;
}