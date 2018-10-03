#include "perceptron.h"
#include <iostream>
#include <stdlib.h>     /* rand, exit, EXIT_FAILURE */
#include <time.h>       /* time */

using namespace std;

int sgn(float soma){ // a funcao sinal possui acesso ao estado da classe, e retorna um inteiro
    if(soma>=0)
        return 1;
    else
        return -1;
}

float produtoEscalar(float* weight, float* input, int qtd){
    float escalar = 0;
    for(int j = 0; j<qtd ; j++){
        escalar += weight[j]*input[j];
    }
    return escalar;
}

void Perceptron::atualizarPesosEVies(float* wght, float* pttrn, int errr, float d){ //pesos, padrao, erro
    // falta passar o learning rate pra cá!!!!!!!aaAAARRRGGhhhh
    for(int j = 0; j<qtd_entradas; j++){
        wght[j] += errr*taxa_de_aprendizagem*pttrn[j];
    }
    vies+=errr*taxa_de_aprendizagem*d;
}


Perceptron::Perceptron(int inputs, float* data, float* d_o, float l_r, int patterns): saida_desejada(d_o){ // quantidade de entradas, dados, saidas desejadas e taxa de aprendizagem
    // configurando o que foi inserido pelo usuário
    qtd_entradas = inputs;
    dados = data;
    qtd_padroes = patterns;
    if(l_r<0){
        cout<<"A taxa de aprendizagem deve ser um valor positivo!";
        exit(EXIT_FAILURE);
    }
    taxa_de_aprendizagem = l_r;

    // agora preciso gerar o vetor de pesos
    pesos = new float [qtd_entradas];
    srand(time(NULL));
    for(int i = 0; i<qtd_entradas ; i++){
        pesos[i] =  (rand()%11-5)*0.1; // inicializa-se com valores entre -0.5 e 0.5 randomicamente;
    }

    //inicializando o limiar
    vies = 0.5 ; //para o teste feito, sua performance é melhor quando é iniciado em 0.5
}


// você pára de atualizar se terminar um batch e nenhum peso foi atualizado ou depois de acabar as épocas(???)
void Perceptron::treinarNeuronio(){ // não retorna nada, e já possui acesso aos dados fornecidos
    int err = 0;
    float u; //variável que recebe o que o perceptron gera
    int epoca = 0;
    bool flag = false; // os pesos foram alterados?
    do{
        for(int i=0; i<qtd_padroes*qtd_entradas; i++){ //percorrendo o batch, isto é, todos os padroes a serem aprendidos
            if(i%qtd_entradas == 0){ // achei o inicio de um padrao!
                //Passo 1: qual a saída da rede?
                u = produtoEscalar(pesos, &dados[i],qtd_entradas);
                u = sgn(u-vies);
                //Passo 2: atualizar pesos e limiar (vies)
                err = saida_desejada[i/qtd_entradas] - u;
                atualizarPesosEVies(pesos,&dados[i], err,saida_desejada[i/qtd_entradas]);
                if(err != 0)
                    flag = true;
                err = 0;

                // a fim de testes, remover depois:
                exibirAprendizado();
                cout<<"Saida do perceptron = "<<u<<endl;
                cout<<"Saida desejada = "<<saida_desejada[i/qtd_entradas]<<endl;
                cout<<"Erro = "<<err<<endl;
                cout<<"Epoca = "<<epoca<<endl;
                cout<<"flag = "<<flag<<endl<<endl;
            }
        }
        epoca++;
        flag = false;
    }while(epoca<=5 || flag==true);
}

void Perceptron::exibirAprendizado(){ //após o treino, exibir os pesos
    cout<<"\nPesos ajustados: [ ";
    for(int i=0; i<qtd_entradas; i++){
        cout<<pesos[i]<<" ";
    }
    cout<<"]"<<endl;
    cout<<"Vies: [ "<<vies<<" ]"<<endl;
}
