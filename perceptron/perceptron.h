#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

class Perceptron{
private:
    int qtd_entradas; // a ser fornecido pelo usuario
    int qtd_padroes; // quantos padroes existem?
    float* dados;// a ser fornecido pelo usuario, aqui estao os dados de treino
    float* saida_desejada;// a ser fornecido pelo usuario
    float taxa_de_aprendizagem;// a ser fornecido pelo usuario
    float vies; //gerado
    float* pesos;//gerado
    friend int sgn(float); // a funcao sinal recebe uma entrada, e retorna um inteiro
    friend float produtoEscalar(float* , float* , int ); // vetores de pesos e entradas, e sua quantidade
    void atualizarPesosEVies(float*, float*, int, float); // dois ponteiros: um para os pesos e outro para o padrao a ser aprendido. inteiro de erro
public:
    Perceptron(int , float*, float*, float, int ); // quantidade de entradas no perceptron,vetor de dados, vetor de saidas desejadas, taxa de aprendizagem e quantidade de padroes nos dados
    void exibirAprendizado(); //após o treino, exibir os pesos
    void treinarNeuronio(); // não retorna nada, e já possui acesso aos dados fornecidos

};

#endif // PERCEPTRON_H_INCLUDED
