// Prog.cc
// This Program is

#include "Main.h"
#include <fstream>

int main (int par_exec1, char* pars_exec[])
{    
   
//Objects creation
	Mathematics * Math = new Mathematics();
    Physics * Phys = new Physics();
    Atmosphere * Atm = new Atmosphere(); 
    Shower * Eas = new Shower();
	    
    printf("*******COSMIC RAYS*******\n\n");

    
//Calls Atmosphere and print its data
/*	Atm->Init(altitude,temperature,pressure,density);
	for(i=0;i<=1480;i++){
		double alt=Atm->GetAltitude(i,altitude);
		double temp=Atm->GetTemperature(i,temperature);
		double press=Atm->GetPressure(i,pressure);
		double dens=Atm->GetDensity(i,density);
		printf("i= %d, h= %.3f km, T= %.3f oC, P= %.3f hPa, dens= %.3f kg/m3\n",i,alt,temp,press,dens);
	} */

//Variaveis locais
    double A[3] = {1, 2, 5};
    double b[3] = {2, 0, -1};
    double C[3];
    double c = 299792458.0;
    
    double q = 1.6e-19;
    double B[3] = {0, 1e-4, 0};
    double v[3] = {0.5*c, 0.7*c, 0.3*c};
    double F[3];
    
    double module, modv, modB; 
	double a[3]; 
	double rl, T, t, W; 
	double m = 1.672e-27;
	
	double V[3];
	double vo[3];
	double r[3];
	double ro[3] = {0,0,0};
	double tempo_total = 0.0;
	
//Produto Vetorial
    Math->ProdVec(C, A, b);
    printf("Cx = %.3f\nCy = %.3f\nCz = %.3f\n", C[0], C[1], C[2]);
    printf("(%.3f,%.3f,%.3f)\n", C[0], C[1], C[2]);
    
    
//Força de Lorentz
    Phys->FLorentz(F,q,v,B);
    printf("\nFx = %g\nFy = %g\nFz = %g\n", F[0], F[1], F[2]);
    printf("(%g,%g,%g)\n", F[0], F[1], F[2]);
	
	
//Modulos 
    Math->Modules(A);
    modv = Math->Modules(v);
    modB = Math->Modules(B);
    printf("\nModulos: V = %.4g, B = %.4g \n", modv, modB);
    
    
//Passos
    for (int i = 0; i < 3; i++) a[i] = F[i]/m;
         printf("\nax = %.4g \nay = %.4g \naz = %.4f \n", a[0], a[1], a[2]);
    
    rl = m * modv / (q * modB);  //raio
    T = 2*pi * m / (q * modB);  //periodo
    W = 2*pi/T; //Freq
    t = T/1000;  //passo
    
    std::ofstream arquivo("trajetoria.txt");
    printf("\nrl = %.4g | T = %.4g | W = $.4g\n", rl, T, W);
    
   //Loop
    for (int k=1; k!=10002; k++)
	{
		 tempo_total += t;
		 Phys->varloop(V, v, a, r, ro, t);
		 //if (k % 1 == 0)
         printf("\nV = (%.4g; %.4g; %.4g) | a = (%.4g; %.4g; %.4g) | Fl = (%.4g; %.4g; %.4g) | rl = (%.4g; %.4g; %.4g) | t = %.4g\n", V[0],V[1],V[2], a[0],a[1],a[2],
		 F[0],F[1],F[2], ro[0],ro[1],ro[2], tempo_total);
		 for (int i = 0; i < 3; i++) v[i] = V[i];
         for (int i = 0; i < 3; i++) ro[i] = r[i];
		 Phys->FLorentz(F,q,v,B);
		 for (int i = 0; i < 3; i++) a[i] = F[i]/m;
		 rl = m * modv / q * modB;	
		  arquivo << r[0] << " " << r[1] << " " << r[2] << "\n";
	}
	arquivo.close();

    
    
    system("pause");
	return 0;
}
