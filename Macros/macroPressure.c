int macroPressure(){

gStyle -> SetOptFit (0111);

TCanvas *c = new TCanvas();
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
	y[n]= Pressure;
	n++;

}

TGraph *gr = new TGraph (n, x, y);
gr->SetTitle("Pressure x Altitude");
gr->GetXaxis()-> SetTitle("Altitude(km)");
gr->GetXaxis()-> SetTitleSize(0.050);
gr->GetYaxis()-> SetTitle("Pressure(mbar)");
gr->GetYaxis()-> SetTitleSize(0.050);

gr->Draw();

TF1 *f1 = new TF1 ("f1", "[0]*TMath::Exp(-x/[1])", 0.,40.);
f1-> SetParameter (0,1.2);
f1-> SetParameter (1,8.);
f1->SetParNames ("p0","H");
gr->Fit("f1");

}
