#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph2D.h>
#include <TAxis.h>

using namespace std;

int macroParticle(){

    gStyle->SetOptFit(111);

    TCanvas *c = new TCanvas("c", "Trajetoria", 800, 600);
    c->SetGrid();
    
    ifstream fpi("trajetoria");
    if (!fpi.is_open()) {
        cout << "? Erro: Arquivo 'trajetoria' nao pôde ser aberto!" << endl;
        return 1;
    }

    const Int_t nlines = 1001;
    Int_t n = 0; 
    Float_t x[nlines]; 
    Float_t y[nlines];
    Float_t z[nlines];
    
    string linha;
    cout << "--- PROCESSANDO LINHAS ---" << endl;

    // Lendo linha por linha como texto puro para não travar o ponteiro do arquivo
    while (n < nlines && getline(fpi, linha)) {
        if (linha.empty()) continue; // Ignora linhas vazias

        stringstream ss(linha);
        Float_t c1 = 0, c2 = 0, c3 = 0;
        
        // Extrai os números separados por qualquer quantidade de espaços ou abas (\t)
        if (ss >> c1 >> c2 >> c3) {
            x[n] = c1;
            y[n] = c2;
            z[n] = c3;
            n++;
        }
    }
    fpi.close();

    cout << "--- FIM DA LEITURA. TOTAL DE PONTOS VALIDOS: " << n << " ---" << endl;

    if (n < 3) {
        cout << "? Erro: Pontos insuficientes lidos!" << endl;
        return 1;
    }

    // --- CORREÇÃO DE SEGURANÇA PARA O CANVAS ---
    // Se todos os Y ou Z forem zero, o ROOT quebra. Colocamos um limite infinitesimal para o gráfico plotar
    bool todosYZero = true;
    bool todosZZero = true;
    for(int i=0; i<n; i++) {
        if(y[i] != 0.0) todosYZero = false;
        if(z[i] != 0.0) todosZZero = false;
    }
    if(todosYZero) { 
        cout << "?? Aviso: Todos os valores de Y vieram zerados. Ajustando escala para plotar." << endl;
        y[0] = 0.00001; 
    }
    if(todosZZero) { 
        cout << "?? Aviso: Todos os valores de Z vieram zerados. Ajustando escala para plotar." << endl;
        z[0] = 0.00001; 
    }
    // -------------------------------------------

    TGraph2D *gr = new TGraph2D(n, x, y, z);
    gr->SetTitle("Trajetoria Particula;X;Y;Z");

    gr->GetXaxis()->SetTitleSize(0.050);
    gr->GetYaxis()->SetTitleSize(0.050);
    gr->GetZaxis()->SetTitleSize(0.050);

    gr->SetLineColor(kBlue);
    gr->SetLineWidth(2);
    gr->SetMarkerStyle(20); // Adiciona pontinhos na trajetória para facilitar visualização
    gr->SetMarkerSize(0.6);

    // Mudado para "LINE P" -> Desenha a linha conectando E os pontos no espaço 3D
    gr->Draw("LINE P"); 

    return 0;
}

