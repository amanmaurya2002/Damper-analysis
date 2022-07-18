// Online C compiler to run C program online
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

int main() {
    
    // Unit of length is mm and unit of current is Ampere (A)
    
    // Define given variables
    double R = 21;
    double Rc = 10;
    double Lp = 8;
    double t = 8;
    double L = 50;
    double Wc = 10;
    double g = 1.3;
    
    // Calculating length of links
    double L1 = R - Rc/2;
    double L2 = g;
    double L3 = t/2;
    double L4 = L - Lp;
    double L5 = L3;
    double L6 = L2;
    double L7 = L1;
    double L8 = L4;
    
    // Calculating cross-sectional area of links
    double A1 = 2 * M_PI * Lp * (R - Rc/4);
    double A2 = 2 * M_PI * Lp * (R + g/2);
    double A3 = 2 * M_PI * Lp * (R + g + t/4);
    double A4 = M_PI * (pow((R + g + t), 2) - pow((R + g + t/2), 2));
    double A5 = A3;
    double A6 = A2;
    double A7 = A1;
    double A8 = M_PI * pow(Rc, 2);
    
    // Value of no. of turns and current
    int N = 350;
    double I = 1;

    printf("I = %f\n", I);
    
    double M_t = 0;
    double length[] = {L1, L2, L3, L4, L5, L6, L7, L8};
    double area[] = {A1, A2, A3, A4, A5, A6, A7, A8};
    double mu[] = {1600, 5.5, 1600, 1600, 1600, 5.5, 1600, 1600};
    for(int i = 0; i < 8; i++){
        M_t = M_t + (length[i] / (mu[i] * area[i]));
    }

    double phi = N * I / M_t;

    // Defining magnetic flux density
    double mu_naught = 4 * M_PI * pow(10, -4);;
    double B = mu_naught * (phi / A2);
    
    printf("B = %f\n", B);

    // Defining yield stress
    double tau_y = (52.96 * pow(B, 4)) - (176.51 * pow(B, 3)) + (158.79 * pow(B, 2)) +  (13.708 * B) + 0.1442;
    
    printf("tau_y = %f\n", tau_y);
    
    return 0;
}