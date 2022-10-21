#include <stdio.h>
#include <math.h>


// Função x² -> só de teste ainda
typedef double tipo_func(double x );

double log1(double x){
    return sqrt(log10(x));
}

// Somatório de integração
double somatorio(double n, double a,double b, double (*func)(double)){
    double area = 0;
    double delta = (b - a) / n; // delta x

    for(int i = 0; i < n; i++){
        area += func((2*a+delta)/2); // Calcula o ponto médio e passa para a função
        a+= delta; // passa para a próxima extremidade do retângulo 
    }
    return area * delta; // Calcula base x altura e retorna o resultado
}


void main(){
    double n,a,b;
    tipo_func * vetor_func[4];
    vetor_func[0] = log1;
    vetor_func[1] = log2;


    printf("Digite o número de retângulos e o intervalo[a,b]: ");
    scanf("%lf %lf %lf", &n, &a, &b);
    printf("A área aproximadamente para log1: %f\n", somatorio(n,a,b,vetor_func[0]));
    printf("A área aproximadamente para log2: %f\n", somatorio(n,a,b,vetor_func[1]));
}