int macroVirtualTemperature(){
    
gStyle -> SetOptFit (0111);

TCanvas* c=new TCanvas();
c->SetGrid();
FILE *fpi = fopen ("Atmosphere.dat", "r");

const Int_t nlines = 1481;
Int_t n = 0; 
Float_t x[nlines]; 
Float_t y[nlines];
//Float_t tv1[nlines]; //criando 1 temperatura virtual
Float_t Altitude, Temperature, Pressure, Density;

while (n<nlines){
	fscanf(fpi, "%f %f %f %f", &Altitude, &Temperature, &Pressure, &Density);
	cout << Altitude << " " << Temperature << " " << Pressure << " " << Density << " " << endl;
	x[n]= Altitude;
	y[n]= Temperature;
//	tv1[n]= Temperature-3; //mudar a fórmula
	n++;

}

TGraph *gr = new TGraph (n, x, y);
gr->SetTitle("Temperature x Altitude");
gr->GetXaxis()-> SetTitle("Altitude(km)");
gr->GetXaxis()-> SetTitleSize(0.050);
gr->GetYaxis()-> SetTitle("Temperature(°C)");
gr->GetYaxis()-> SetTitleSize(0.050);
gr->Draw();

//TGraph *vt1 = new TGraph (n, x, tv1); //criando o objeto vt1 da classe TGraph
//vt1->Draw("Same"); //desenha sobre o mesmo gráfico

TF1 *f1 = new TF1("f1", "[0]+[1]*(x-[2])", 0.,11.);
f1->SetParameter (0,15);
f1->SetParameter (1,-6.5);
f1->SetParameter (2,0);
gr->Fit("f1","R");

TF1 *f2 = new TF1("f2", "[0]+[1]*(x-[2])", 11.,20.);
f1->SetParameter (0,-56.5);
f1->SetParameter (1,0);
f1->SetParameter (2,11);
gr->Fit("f2","R+");

TF1 *f3 = new TF1("f3", "[0]+[1]*(x-[2])", 20.,32.);
f1->SetParameter (0,-56.5);
f1->SetParameter (1,1);
f1->SetParameter (2,20);
gr->Fit("f3","R+");

TF1 *f4 = new TF1("f4", "[0]+[1]*(x-[2])", 32.,37.);
f1->SetParameter (0,-44.5);
f1->SetParameter (1,2.8);
f1->SetParameter (2,32);
gr->Fit("f4","R+");


}
