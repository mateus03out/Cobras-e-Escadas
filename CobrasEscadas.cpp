#include <iostream>
#include <stdio.h>

using namespace std;

#define rows 22
#define col 52

struct posicaojogador{
	int x,y;
};

void def_espaco(char espaco[][col]);
struct posicaojogador posicao_inicial_jogador();
void def_cobras_escadas(char espaco[][col]);

int main(){
	char espaco[rows][col];
	struct posicaojogador jogador[4];

	//Posicao inicial dos jogadores
	jogador[0] = posicao_inicial_jogador();
	jogador[1] = posicao_inicial_jogador();
	jogador[2] = posicao_inicial_jogador();
	jogador[3] = posicao_inicial_jogador();	
	//limpando e definindo o espaco
	def_espaco(espaco);
	def_cobras_escadas(espaco);
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++)
			if(espaco[i][j] == 'M')
				printf(" ");
			else{
				if(espaco[i][j] == 'E')
					printf("\033[1;32m%c\033[1;32m",espaco[i][j]);
				if(espaco[i][j] != 'E')
					printf("\033[0m%c\033[0m",espaco[i][j]);
			}
		printf("\n");
	}
	
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
	//Numerando as linhas
	for(int i=20;i>2;i-=2){
		espaco[i][0] = codeASCII;
		codeASCII++;
	}
	espaco[2][0] = 'D';
	//Numerando as colunas
	codeASCII = 49;
	for(int j=47;j>2;j-=5){
		espaco[0][j] = codeASCII;
		codeASCII++;
	}
	espaco[0][2] = 'D';
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
struct posicaojogador posicao_inicial_jogador(){
	struct posicaojogador jogador;
	
		jogador.x = 21;
		jogador.y = 2;

	return jogador;
}
void def_cobras_escadas(char espaco[][col]){
	//Escada 2 para 25
	espaco[20][12] = 'E';
	espaco[16][27] = 'E';
	//Escada 4 par	a 14
	espaco[20][22] = 'E';
	espaco[18][22] = 'E';
	//Escada 19 para 46
	espaco[18][47] = 'E';
	espaco[12][32] = 'E';
}
