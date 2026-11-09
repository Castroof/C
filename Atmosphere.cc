//Class to describe and calculate atmospheric parameters

// System Headers:
#include <stdio.h>

// Local Headers:
#include "Atmosphere.h"
//  altitude kilometers
//  temperature degrees celcius
//  pressure mbar
//  density kg/m3

// Constructor
Atmosphere::Atmosphere(){}
// Destructor
Atmosphere::~Atmosphere(){}

//Method for initialization of the atmosphere from file
double Atmosphere::Init(double atm_alt[1481],double atm_temp[1481],double atm_press[1481],double atm_dens[1481]) {

FILE *atm_file;
char ch,line[100];
int i;

atm_file=fopen("Atmosphere.dat","r");
if (atm_file==NULL) {
  (void)printf("Can't open atmosphere file\n");
  return -1;}
i=0;
ch=fgetc(atm_file);
while (ch!=EOF){
//while(i<=1481){
//        (void)printf("%c",ch);
    (void)ungetc(ch,atm_file);
	(void)fgets(line,sizeof(line),atm_file);
	sscanf(line,"%lf %lf %lf %lf",&atm_alt[i],&atm_temp[i],&atm_press[i],&atm_dens[i]);
	//(void)printf("\t\t\t\t\n",atm_alt[i],atm_temp[i],atm_press[i],atm_dens[i]); 
	ch=fgetc(atm_file);
	i++;
}
(void)fclose(atm_file);
return 0;
}


//Methods to get the atmospheric parameters
double Atmosphere::GetAltitude(int i, double atm_alt[1481]) {return atm_alt[i];}
double Atmosphere::GetTemperature(int i, double atm_temp[1481]) {return atm_temp[i];}
double Atmosphere::GetPressure(int i, double atm_press[1481]) {return atm_press[i];}
double Atmosphere::GetDensity(int i, double atm_dens[1481]) {return atm_dens[i];}

//This method returns the index interval of a given altitude
double Atmosphere::GetLevelIndexes(int& low_i, int& up_i, double atm_alt[1481], double alt)
{
int i=0;
while(i<=1480){
	low_i=i;
	up_i=i+1;
	//(void)printf("low_i=%d up_i=%d lower altitude=%.3lf upper altitude=%.3lf test altitude=%.3lf\n",low_i,up_i,atm_alt[low_i],atm_alt[up_i],alt);
 	if((atm_alt[low_i]<=alt)&&(alt<=atm_alt[up_i]))break;	
	i++;
} 
return 0;}

//This method returns the atmospheric depth (g/cm2) from altitude (km asl)
double Atmosphere::GetDepth(double& depth, double atm_alt)
//Based on Linsley parameterization for US standard atmosphere:
{
double a[5]={-186.556,-94.918999,0.612890,0,0.011283};
double b[5]={1222.699951,1144.900024,1305.599976,540.179993,1};
double c[5]={9.9419,8.7815,6.3614,7.7217,10000};
int k;
if ((atm_alt>-5.8)&&(atm_alt<=4)) k=0;
if ((atm_alt>4)&&(atm_alt<=10)) k=1;
if ((atm_alt>10)&&(atm_alt<=40)) k=2;
if ((atm_alt>40)&&(atm_alt<=100)) k=3;
if ((atm_alt>100)&&(atm_alt<=112.8)) k=4;
if ((atm_alt<=-5.8)||(atm_alt>112.8)){
	(void)printf("Atmospheric altitude outside valid interval\n");
	return -1;}
if (k==4){depth=a[k]-atm_alt/c[k];
	 }else{depth=a[k]+b[k]*exp(atm_alt/c[k]);}
return 0;}

/*o algoritmo abaixo faz o contrario para a variavel alt
       if ((depth>0.)&&(depth<=0.001283)) k=5;
       if ((depth>0.001283)&&(depth<=3.039497)) k=4;
       if ((depth>3.039497)&&(depth<=271.696991)) k=3;
       if ((depth>271.696991)&&(depth<=631.130676)) k=2;
       if ((depth>631.130676)&&(depth<=1036.143921)) k=1;
       if (k==5) {
	 alt=-c[5]*(depth-a[5])/b[5];
	 alt2=-c[5]*((depth+step)-a[5])/b[5];
       }else{
	 alt=-c[k]*log((depth-a[k])/b[k]);
	 alt2=-c[k]*log(((depth+step)-a[k])/b[k]);
       }
 */
