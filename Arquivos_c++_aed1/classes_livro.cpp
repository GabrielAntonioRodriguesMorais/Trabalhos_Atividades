#include <iostream>
#include <string.h>

using namespace std;

class Aviao
{
private:
    float consumo;
    int tanque;
    int tipo;
    string nome;

public:
    Aviao() : consumo(0.0), tanque(0), tipo(0), nome("") {}

    void setAviao(int tipo)
    {
        if (tipo == 1)
        {
            this->nome = "Jato";
            this->consumo = 1.5;
            this->tanque = 800;
        }
        else if (tipo == 2)
        {
            this->nome = "Aviao Domestico";
            this->consumo = 1.2;
            this->tanque = 500;
        }
        else if (tipo == 3)
        {
            this->nome = "Jato Particular";
            this->consumo = 1.4;
            this->tanque = 350;
        }
    }
    Aviao(int tipo)
    {
        setAviao(tipo);
    }
    float distanciaMaxima()
    {
        float distanciaMax = 0.0;
        distanciaMax = consumo * tanque;
        return distanciaMax;
    }

    void exibirAviao()
    {
        cout << "Nome: " << nome << endl;
        cout << "Consumo: " << consumo << " litros/km" << endl;
        cout << "Tanque: " << tanque << " litros" << endl;
    }
};

int main()
{
    Aviao A;
    int tipo;
    float DistanciaMax;

    cout << "Digite o tipode aviao: ";
    cin >> tipo;

    A.setAviao(tipo);

    A.exibirAviao();

    DistanciaMax = A.distanciaMaxima();
    cout << "Distancia Maxima = " << DistanciaMax << "Km " << endl;

    return 0;
}
