int qtd_clusters = 3;
int dim_clusters = 3;
float clusters[9] = {122.5, 76.16666667,156.66666667,
             66.22222222, 273.66666667, 153.94444444,
             22.22222222, 48.27777778, 39.05555556};
             
float metric(float *cluster, float *feat)
{
    float metric = 0;
    for(int i = 0;i < 2; i++){
       metric += pow(*(cluster + i) - *(feat + i), 2);
    }
    return sqrt(metric);
}
           
float * get_centroid(float * features)
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
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  float test[3] = {76, 272, 48};
  float * ct = get_centroid(test);
  Serial.print(*ct);
  Serial.print(*(ct + 1));
  Serial.print(*(ct + 2));
  // put your main code here, to run repeatedly:

}

