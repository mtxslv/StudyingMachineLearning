#include "kmeans.h"
#include <cmath>

Kmeans::Kmeans(float *_clusters, int _dim, int _qtd)
{
    clusters = _clusters;
    dim_clusters = _dim;
    qtd_clusters = _qtd;
}
float metric(float *cluster, float *feat)
{
    float metric = 0;
    for(int i = 0;i < 2; i++){
       metric += pow(*(cluster + i) - *(feat + i), 2);
    }
    return sqrt(metric);
}

float *Kmeans::get_centroid(float *features)
{
    float menor_medida = metric(clusters, features);
    float medida;
    float * cls = clusters;
    for(int i = 1; i < qtd_clusters; i++){
        medida = metric(clusters + i*dim_clusters, features);
        if(medida < menor_medida){
            cls = clusters + i*dim_clusters;
            menor_medida = medida;
        }
    }
    return cls;
}
