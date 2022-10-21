#include <stdio.h>


// Função x² -> só de teste ainda
double fun(double num){
    return num * num * num;
}

// Somatório de integração
double somatorio(double n, double a,double b){
    double area = 0;
    double delta = (b - a) / n; // delta x

    for(int i = 0; i < n; i++){
        area += fun((2*a+delta)/2); // Calcula o ponto médio e passa para a função
        a+= delta; // passa para o proxima estremidade do retângulo 
    }
    return area * delta; // Calcula base x altura e retorna o resultado
}

void main(){
    double n, a, b;

    printf("Digite o número de retângulos e o intervalo[a,b]: ");
    scanf("%lf %lf %lf", &n, &a, &b);
    printf("A área aproximadamente é: %f\n", somatorio(n,a,b));
}
