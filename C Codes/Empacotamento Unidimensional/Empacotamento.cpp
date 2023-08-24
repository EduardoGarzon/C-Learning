#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

// classe do recipiente
class Recipiente
{
private:
    int tamanho_recipiente;

public:
    // inicia capacidade 0
    Recipiente();
    // configura peso
    void setCapacidade(int capacidade);
    // retorna peso
    int getCapacidade();
};

// classe do item
class Objeto
{
private:
    int volume;

public:
    // construtor default objeto
    Objeto();
    // configura volume do item
    void setVolume(int peso);
    // retorna peso do item
    int getVolume();
};

std::vector<Objeto> itens;   // vetor que armazena cada item
std::vector<Recipiente> rec; // vetor para cada recipiente
int cont_rec = 0;

// construtor default, capacidade inicia em 0;
Recipiente::Recipiente()
{
    this->tamanho_recipiente = 0;
}

// construtor default, capacidade inicia em 0;
Objeto::Objeto()
{
    this->volume = 0;
}
// configura peso
void Recipiente::setCapacidade(int capacidade)
{
    cin >> capacidade;
    this->tamanho_recipiente = capacidade;
}

// retorna peso
int Recipiente::getCapacidade()
{
    return this->tamanho_recipiente;
}

// configura peso de cada item
void Objeto::setVolume(int peso)
{
    cin >> peso;
    this->volume = peso;
}

// retorna peso de cada item
int Objeto::getVolume()
{
    return this->volume;
}

void criar_Objetos()
{
    int quantidade_itens = 0; // quantidade de itens a serem empacotados
    int peso = 0; // peso de cada item
    int i = 0;

    cout << "Informe o numero de itens a serem empacotados: ";
    cin >> quantidade_itens; // leitura qtd de itens

    for (i = 0; i < quantidade_itens; i++)
    {
        itens.push_back(Objeto()); // adiciona novo item ao final do vetor de itens
        cout << "Informe o peso do item " << i << ": ";
        itens[i].setVolume(peso); // leitura do volume
    }

    for (i = 0; i < quantidade_itens; i++)
    {
        cout << "Peso do item " << i << ": " << itens[i].getVolume() << endl;
    }
}

void criar_Recipiente()
{
    int capacidade = 0; // capacidade do recipiente

    rec.push_back(Recipiente()); // adiciona novo recipiente ao final do vetor de recipientes
    cout << "Informe a capacidade do novo recipiente " << cont_rec << ": ";
    rec[cont_rec].setCapacidade(capacidade); // leitura da capacidade
    cout << "Capacidade atual do recipiente " << cont_rec << ": " << rec[cont_rec].getCapacidade() << endl;
    cont_rec++; // incrementa para o proximo recipiente
}

void gulosa()
{

}

int main()
{

    criar_Recipiente();
    criar_Objetos();
    gulosa();
    //tabu();
    //empacotar();
    return 0;
}