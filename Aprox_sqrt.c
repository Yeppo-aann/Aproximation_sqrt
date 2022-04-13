#include<math.h>
#include<stdio.h>
double f1(double x);
double g1(double x);
double f(double x);
double g(double x);


int main()
{
    double x;
    int k=0;
    printf("Entra la x per aproximar sqrt(1+x)\n");
    scanf("%lf",&x);
    double a1,a2,b1,b2,B;
    a1=x;
    b1=f1(x);
    B=1.0;
    printf("\nF(X) POLINOMIS DE PRIMER GRAU:\n");
    while(k<4)
    {
        printf("\nIteracio %d\n",k);
        B=B*b1;
        a2=g1(a1);
        b2=f1(a2);
        printf("B=%.16g\n",B);
        printf("|sqrt(1+x)-B| = %.16g <= %.16g = a/2*sqrt(1+x)\n",fabs(sqrt(1+x)-B),a2/2*sqrt(1+x));

        a1=a2;
        b1=b2;
        k++;
    }

    printf("\nF(X) POLINOMIS DE TERCER GRAU:\n");
    k=0;
    a1=x;
    b1=f(x);
    B=1.0;
    while(k<4)
    {
        printf("\nIteracio %d\n",k);
        B=B*b1;
        a2=g(a1);
        b2=f(a2);
        printf("B=%.16g\n",B);
        printf("|sqrt(1+x)-B| = %.16g <= %.16g = a/2*sqrt(1+x)\n",fabs(sqrt(1+x)-B),a2/2*sqrt(1+x));

        a1=a2;
        b1=b2;
        k++;
    }



    return 0;
}

double f(double x)
{
    return ((7*x*x*x+56*x*x+112*x+64)/(x*x*x+24*x*x+80*x+64));
}

double f1(double x)
{
    return ((3.0*x+4.0)/(x+4.0));
}

double g1(double x)
{
    x=(1.0+x)/(f1(x)*f1(x))-1;
    return x;
}

double g(double x)
{
    x=(1.0+x)/(f(x)*f(x))-1;
    return x;
}
