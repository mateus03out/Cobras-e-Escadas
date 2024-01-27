#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define rows 22
#define col 52

struct coordenadas{
	int x,y;
};
void def_espaco(char espaco[][col]);
void posicao_inicial_jogador(char espaco[][col],coordenadas jogador[]);
void gera_cobras_escadas(char espaco[][col]);
void mostra_matriz(char espaco[][col]);
void game(char espaco[][col],coordenadas jogador[]);

int main(){
	
	srand(time(NULL));

	char espaco[rows][col];
	struct coordenadas jogador[4];
    
    //limpando e definindo o espaco
	def_espaco(espaco);
	//gera escadas e cobras
	gera_cobras_escadas(espaco);
	//Posicao inicial dos jogadores
	posicao_inicial_jogador(espaco,jogador);
	
    //comeca o game
    game(espaco, jogador);
    //mostra a matriz espaco
	mostra_matriz(espaco);
	
return 0;
}
void def_espaco(char espaco[][col]){
	int codeASCII = 49;

	//'Limpando' a matriz
	for(int i=0;i<rows;i++)
		for(int j=0;j<col;j++)
			espaco[i][j] = 'M';
	//Definindo os espacos
	for(int i=1;i<rows;i+=2)
		for(int j=0;j<col;j++)
			espaco[i][j] = '-';
	for(int i=1;i<rows;i++)
		for(int j=1;j<col;j+=5)
			espaco[i][j] = '|';
	//Numerando as casas
	for(int i=2;i<rows;i+=2){
		codeASCII = 48;
		for(int j=5;j<col;j+=5){
			espaco[i][j] = codeASCII;
			codeASCII++;
		}
	}
	codeASCII = 49;
	for(int i=18;i>0;i-=2){
		for(int j=4;j<col;j+=5)
			espaco[i][j] = codeASCII;
		codeASCII++;
	}
}

void gera_cobras_escadas(char espaco[][col]){
    //escada, 1 para 23
    espaco[20][7] = 'E';
    espaco[16][17] = 'E';
    //escada, 10 para 21
    espaco[18][2] = 'E';
    espaco[16][7] = 'E';
    //escada, 26 para 59
    espaco[16][32] = 'E';
    espaco[10][47] = 'E';
    //escada, 43 para 87
    espaco[12][17] = 'E';
    espaco[4][37] = 'E';
    //escada, 61 para 94
    espaco[8][7] = 'E';
    espaco[2][22] = 'E';

    //Cobra, 33 para 3
    espaco[14][17] = 'C';
    espaco[20][17] = 'C'; 
}
void posicao_inicial_jogador(char espaco[][col],coordenadas jogador[]){
        int quant;
        do{
            cout << "Quantas pessoas irao jogar o jogo?<max 4><min 2>";
            cin >> quant;
        }while(quant < 2 || quant > 4);

		for(int i=0;i<quant;i++){
            jogador[i].x = 21;
            jogador[i].y = i+2;
        }
        int codeASCII = 49;
        for(int i=0;i<quant;i++){
            espaco[jogador[i].x][jogador[i].y] = codeASCII;
            codeASCII++;
        }
}
void game(char espaco[][col], coordenadas jogador[]){
    
}
void mostra_matriz(char espaco[][col]){	
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++)
			if(espaco[i][j] == 'M')
				printf(" ");
			else
				printf("%c",espaco[i][j]);
		printf("\n");
	}
}
