#include <iostream>
#include <fstream> // IMPORTANTE: Adicione este include no topo do arquivo
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph2D.h>
#include <TAxis.h>

using namespace std;

int macroParticle(){

    gStyle->SetOptFit(111);

    TCanvas *c = new TCanvas("c", "Trajetoria", 800, 600);
    c->SetGrid();
    
    ifstream fpi("trajetoria.txt");
    if (!fpi.is_open()) {
        cout << "? Erro: Arquivo 'trajetoria' nao pôde ser aberto!" << endl;
        return 1;
    }
    
    const Int_t nlines = 1;
    Int_t n = 0; 
    Float_t rl[nlines]; 
    Float_t T[nlines];
    Float_t W[nlines];
    
    Float_t a1, a2, a3, a4;
    
    cout << "--- INICIANDO LEITURA DO ARQUIVO ---" << endl;
    while (n < nlines) {
        rl[n] = a1;
        T[n] = a2;
        W[n] = a3;
        
        cout << "Lido do arquivo -> Ponto " << n << ": X=" << c1 << " | Y=" << c2 << " | Z=" << c3 << endl;
        
        n++;
    }
    cout << "--- FIM DA LEITURA. TOTAL DE PONTOS: " << n << " ---" << endl;

    const Int_t nlines = 5002;
    Int_t n = 1; 
    Float_t x[nlines]; 
    Float_t y[nlines];
    Float_t z[nlines];
    
    Float_t c1, c2, c3, c4;

    cout << "--- INICIANDO LEITURA DO ARQUIVO ---" << endl;
    while (n < nlines && fpi >> c1 >> c2 >> c3) {
        if (fpi.peek() != '\n' && fpi.peek() != EOF) {
            fpi >> c4;
        }

        x[n] = c1;
        y[n] = c2;
        z[n] = c3;
        
        cout << "Lido do arquivo -> Ponto " << n << ": X=" << c1 << " | Y=" << c2 << " | Z=" << c3 << endl;
        
        n++;
    }
    cout << "--- FIM DA LEITURA. TOTAL DE PONTOS: " << n << " ---" << endl;

    fpi.close();

    if (n < 3) {
        cout << "? Erro: Pontos insuficientes lidos para gerar um grafico 3D. Total: " << n << endl;
        return 1;
    }

    TGraph2D *gr = new TGraph2D(n, x, y, z);
    gr->SetTitle("Trajetoria Particula;X;Y;Z");

    gr->GetXaxis()->SetTitleSize(0.050);
    gr->GetYaxis()->SetTitleSize(0.050);
    gr->GetZaxis()->SetTitleSize(0.050);

    gr->SetLineColor(kRed);
    gr->SetLineWidth(2);
    
    gr->Draw("LINE"); 
    
    // 1. Criar a caixa da legenda (Coordenadas: X1, Y1, X2, Y2 entre 0.0 e 1.0 na Canvas)
    // Ajuste esses valores se a legenda ficar em cima da sua curva
    TLegend *leg = new TLegend(0.60, 0.70, 0.88, 0.88);
    leg->SetHeader("Parametros da Particula", "C"); // "C" centraliza o cabeçalho
    leg->SetTextSize(0.035); // Tamanho da fonte

    // 2. Suas variáveis do código principal (substitua pelos seus valores reais ou variáveis)
    double raio_larmor = rl; // Exemplo
    double W = W;            // Exemplo
    double T = T;            // Exemplo

    // 3. Adicionar as linhas na legenda formatando o texto com os números
    // %g ou %.2f servem para formatar o número de casas decimais
    leg->AddEntry((TObject*)0, Form("Raio Larmor: %.2f m", raio_larmor), "");
    leg->AddEntry((TObject*)0, Form("Ferquencia (W): %g eV", W), "");
    leg->AddEntry((TObject*)0, Form("Periodo (T): %.4f s", T), "");

    // Adiciona também uma linha indicando o que é a curva azul/vermelha
    leg->AddEntry(gr, "Trajetoria Calculada", "lp"); // "lp" significa linha (l) e ponto (p)

    // 4. Desenhar a legenda na tela
    leg->Draw();


    return 0;
}

