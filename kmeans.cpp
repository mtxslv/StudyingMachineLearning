#include<iostream>
#include<cmath>

using namespace std;

// o dataset pois os dados tridimensionais a serem clusterizados
// a classe é o vetor que recebe 1 para a primeira classe e 2 para a segunda classe.
float dataset[8][3] = {{1,4,1}, {1,2,2}, {1,4,2}, {2,1,2}, {1,1,1}, {2,4,2}, {1,1,2}, {2,1,1}};
int classe[8];
float centroide[2][3];
//
float distance(float ponto[3],float centroide[3]);
void escolherCentroide(float dataset[8][3], int classe[2][3],float centroide[2][3]);
bool ehIgual(float classe[8],float classe_auxiliar[8]);
int main(){

}

float distance(float ponto[3],float centroide[3]){
    float soma = 0;
    for(int i = 0; i < 3; i++){
        soma += abs(ponto[i]-centroide[i]);
    }
    return soma;
}

bool ehIgual(float classe[8],float classe_auxiliar[8]){
    bool flag = true;
    for(int j = 0; j<8;j++){
        if(classe[i] != classe_auxiliar[i]){
            flag = false;
        }
    }
    return flag;
}

void escolherCentroide(float dataset[8][3], int classe[2][3],float centroide[2][3]){

}

