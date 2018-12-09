#include <iostream>
#include "kmeans.h"
using namespace std;

int main(){
    float centroides[9] = {122.5,76.167, 156.667,    66.222, 273.667, 153.944,       22.222, 48.278, 39.056};
    int dim = 3, qtd = 3;
    Kmeans my_kmns(centroides,dim,qtd);
    float obj_red[3] = { 76., 272.,  48.};
    float obj_blue[3] = {157, 154, 39};
    float obj_green[3] = {127, 64, 23};
    cout<< "parte do centroide de um objeto vermelho "<<*my_kmns.get_centroid(obj_red)<<endl;
    cout<<"parte do centroide de um objeto azul "<<*my_kmns.get_centroid(obj_blue)<<endl;
    cout<<"parte do centroide de um objeto verde "<<*my_kmns.get_centroid(obj_green)<<endl;
    cout << "Hello world!" << endl;
    return 0;

}
