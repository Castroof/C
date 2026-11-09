void graph_from_data() {
   //Draw a simple graph
   // To see the output of this macro, click begin_html <a href="gif/graph.gif">here</a>. end_html
   //Author: Rene Brun
   
   TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

   c1->SetFillColor(42);
   c1->SetGrid();

   FILE *fp1 = fopen("DadosRoot.dat","r");

   Int_t n=0;
   const Int_t nlines = 100;
   Double_t x[nlines],y[nlines];
   Float_t xr,yr,zr,wr;

while (n<nlines) {

    fscanf(fp1,"%f %f %f %f",&xr,&yr,&zr,&wr);
    cout << xr << " " << yr << endl;
    x[n]=xr;
    y[n]=yr;
    n++;
   }

   gr = new TGraph(n,x,y);
   gr->SetLineColor(2);
   gr->SetLineWidth(4);
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->SetTitle("a simple graph");
   gr->GetXaxis()->SetTitle("X title");
   gr->GetYaxis()->SetTitle("Y title");
   gr->Draw("AP");

   // TCanvas::Update() draws the frame, after which one can change it
   c1->Update();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
}
