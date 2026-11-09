int macroTemperature(){
    
gStyle -> SetOptFit (0111);

TCanvas* c=new TCanvas();
c->SetGrid();
FILE *fpi = fopen ("Atmosphere.dat", "r");

const Int_t nlines = 1481;
Int_t n = 0; 
Float_t x[nlines]; 
Float_t y[nlines];
Float_t Altitude, Temperature, Pressure, Density;

while (n<nlines){
	fscanf(fpi, "%f %f %f %f", &Altitude, &Temperature, &Pressure, &Density);
	cout << Altitude << " " << Temperature << " " << Pressure << " " << Density << " " << endl;
	x[n]= Altitude;
	y[n]= Temperature;
	n++;

}

TGraph *gr = new TGraph (n, x, y);
gr->SetTitle("Temperature x Altitude");
gr->GetXaxis()-> SetTitle("Altitude(km)");
gr->GetXaxis()-> SetTitleSize(0.050);
gr->GetYaxis()-> SetTitle("Temperature(°C)");
gr->GetYaxis()-> SetTitleSize(0.050);

gr->Draw();

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

TF1 *f5 = new TF1("f5", "[0]*x + [1]",0.,11.);
f5->SetParameter(0,-50);
f5->SetParameter(1,1);
f5->SetParameter(2,15);
f5->SetLineColor(kGreen +2);
gr->Fit("f5","R+");

TF1 *f6 = new TF1("f6", "[2]",11.,20.);
f6->SetParameter(0,-50);
f6->SetParameter(1,1);
f6->SetParameter(2,15);
f6->SetLineColor(kGreen +2);
gr->Fit("f6","R+");

TF1 *f7 = new TF1("f7", "[0]*x + [1]",20.,32.);
f7->SetParameter(0,-50);
f7->SetParameter(1,1);
f7->SetParameter(2,15);
f7->SetLineColor(kGreen +2);
gr->Fit("f7","R+");

TF1 *f8 = new TF1("f8", "[0]*x + [1]",32.,37.);
f8->SetParameter(0,-50);
f8->SetParameter(1,1);
f8->SetParameter(2,15);
f8->SetLineColor(kGreen +2);
gr->Fit("f8","R+");
}
