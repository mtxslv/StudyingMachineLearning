#ifndef KMEANS_H_INCLUDED
#define KMEANS_H_INCLUDED

class Kmeans{
private:
    float * clusters;
    int dim_clusters;
    int qtd_clusters;
    float metric(float *cluster, float *feat);
    float metric_M(float *cluster, float *feat);

public:
    Kmeans(float * _clusters,int _dim, int _qtd);
    float * get_centroid(float * features);
};


#endif // KMEANS_H_INCLUDED
