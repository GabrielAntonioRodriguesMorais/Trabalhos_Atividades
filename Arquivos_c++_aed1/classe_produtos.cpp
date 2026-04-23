#include <iostream>
#include <string.h>

using namespace std;

class Produto
{
private:
	float preco;
	int tamanho;
	string nome;

public:
	Produto() : preco(0.0), tamanho(0), nome("") {}

	Produto(float preco, int tamanho, string nome)
	{
		setPreco(preco);
		setTamanho(tamanho);
		setNome(nome);
	}

	// setters
	void setPreco(float preco)
	{
		this->preco = preco;
	}
	void setTamanho(int tamanho)
	{
		this->tamanho = tamanho;
	}
	void setNome(string nome)
	{
		this->nome = nome;
	}

	// getters
	float getPreco()
	{
		return preco;
	}
	int getTamanho()
	{
		return tamanho;
	}
	string getNome()
	{
		return nome;
	}

	void imprimirProduto()
	{
		cout << "Nome: " << nome << endl;
		cout << "\nPreco: " << preco << endl;
		cout << "\nTamanho: " << tamanho << endl;
	}
};

int main()
{
	Produto p1;
	cout << "Produto construtor padrao: \n"
		 << endl;
	p1.imprimirProduto();

	float preco;
	int tamanho;
	string nome;

	cin >> preco;
	cin >> tamanho;
	cin >> nome;

	Produto p2(preco, tamanho, nome);
	p2.setPreco(preco);
	p2.setTamanho(tamanho);
	p2.setNome(nome);
	p2.imprimirProduto();

	cout << "Produto: " << p2.getNome() << "Preco: " << p2.getPreco() << "Tamanho: \n"
		 << p2.getTamanho() << endl;
}