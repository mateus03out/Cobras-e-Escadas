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
void posicao_inicial_jogador(coordenadas jogador[4]);
void gera_cobras_escadas(char espaco[][col]);
void mostra_matriz(char espaco[][col]);

int main(){
	
	srand(time(NULL));

	char espaco[rows][col];
	struct coordenadas jogador[4];

	//Posicao inicial dos jogadores
	posicao_inicial_jogador(jogador);
	//limpando e definindo o espaco
	def_espaco(espaco);
	//gera escadas e cobras
	gera_cobras_escadas(espaco);
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
void posicao_inicial_jogador(coordenadas jogador[4]){
	
	for(int i=0;i<4;i++){
		jogador[i].x = 21;
		jogador[i].y = 2;
	}
}
void gera_cobras_escadas(char espaco[][col]){
	struct coordenadas cobras[10], escadas[6];

	for(int i=0;i<10;i++){
		do{
			cobras[i].x = 2*(rand() % 10 + 1);
			cobras[i].y = (5*(rand() % 10+1))+2;
		}while(cobras[i].x == cobras[i].y);

}	for(int i=0;i<10;i++)
		espaco[cobras[i].x][cobras[i].y] = 'E';
	
}
void mostra_matriz(char espaco[][col]){
	int cont=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<col;j++){
			if(espaco[i][j] == 'M')
				printf(" ");
			else
				printf("%c",espaco[i][j]);
		if(espaco[i][j] == 'E')
			cont++;
		}
		printf("\n");
	}
	printf("\n%d\n",cont);
}
