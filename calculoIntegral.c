#include <stdio.h>
#include <math.h>

typedef double tipo_func(double x);

int integer,a,b; // Não recomendado;

// Para Logaritmos de outras bases
double logbase(double a, double base)
{
    return log(a) / log(base);
}

// Logₐ(x)
double log1(double x)
{
    return logbase(x, integer);
}

// Log(cx)
double log2(double x)
{
    return log(integer) + log(x);
}

// Log²(x)
double log3(double x)
{
    return pow(log(x), 2);
}

// Log(ax+b)
double log4(double x)
{
    return log(a * x + b);
}

// Somatório de integração
double somatorio(double n, double a, double b, double (*func)(double))
{

    double area = 0;
    double delta = (b - a) / n; // delta x

    while (n-- > 0)
    {
        area += func((2 * a + delta) / 2); // Calcula o ponto médio e passa para a função
        a += delta;                        // passa para a próxima extremidade do retângulo
    }
    return area * delta; // Calcula base x altura e retorna o resultado
}

void menu(){
    printf("«««««««««««« Funções logarítmicas »»»»»»»»»»\n");
    printf("[1] - f(x) = logₐ(x)\n");
    printf("[2] - f(x) = log(k.x)\n");
    printf("[3] - f(x) = log²(x)\n");
    printf("[4] - f(x) = log(a.x + b)\n");
    printf("[0] - Exit\n");
    printf("Escolha uma função: ");
}

void main()
{
    double n, x1, x2;
    int choose;
    tipo_func *vetor_func[4]; // Array de função
    vetor_func[0] = log1;
    vetor_func[1] = log2;
    vetor_func[2] = log3;
    vetor_func[3] = log4;

    do
    {
        system("clear"); // Windows → cls
        menu();
        scanf("%d",&choose);
        system("clear");

        switch (--choose){
        case 0:
            printf("«««««««««««« f(x) = logₐ(x) »»»»»»»»»»\n");
            printf("Base → ");
            scanf("%d",&integer);
            break;
        case 1:
            printf("«««««««««««« f(x) = log(k.x) »»»»»»»»»»\n");
            printf("Constante(k) → ");
            scanf("%d",&integer);
            break;
        case 2:
            printf("«««««««««««« f(x) = log²(x) »»»»»»»»»»\n");
            break;
        case 3:
            printf("«««««««««««« f(x) = log(a.x + b) »»»»»»»»»»\n");
            printf("A - B → ");
            scanf("%d %d",&a,&b);
            break;
        }
        if(choose != -1){
            printf("Número de retângulos→ ");
            scanf("%lf", &n);
            printf("Intervalo[a-b]→ ");
            scanf("%lf %lf", &x1, &x2);
            printf("\nIntegral = %f", somatorio(n,x1,x2,vetor_func[choose]));
            getchar();getchar();
        }
    } while (choose != -1);
}