#ifndef KMEANS_H
#define KMEANS_H

class Kmeans{
private:
    float * clusters;
    int dim_clusters;
    int qtd_clusters;
public:
    Kmeans(float * _clusters,int _dim, int _qtd);
    float * get_centroid(float * features);
    friend float metric(float *cluster, float *feat);
};

#endif // KMEANS_H
