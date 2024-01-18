#include <iostream>
#include <stdio.h>

using namespace std;

#define rows 20
#define col 21

struct posicaojogador{
	int x,y;
};

void defEspaco(char espaco[][col]);
struct posicaojogador posicao_inicial_jogador(int inicio);
int main(){
	char espaco[rows][col];
	struct posicaojogador jogador[4];

	//Posicao inicial dos jogadores
	jogador[0] = posicao_inicial_jogador(0);
	jogador[1] = posicao_inicial_jogador(0);
	jogador[2] = posicao_inicial_jogador(0);
	jogador[3] = posicao_inicial_jogador(0);
	
	//limpando e definindo o espaco
	defEspaco(espaco);
	
return 0;
}
void defEspaco(char espaco[][col]){
	
	for(int x=0;x<rows;x++)
		for(int y=0;y<col;y++)
			espaco[x][y] = '0';
	for(int x=0;x<rows;x+=2)
			for(int y=0;y<col;y++)
				espaco[x][y] = '-';
	for(int y=0;y<col;y+=2)
		for(int x=0;x<rows;x++)
			espaco[x][y] = '|';	
	//Os proximos comandos podem ser removidos
	for(int x=0;x<rows;x++){
		for(int y=0;y<col;y++)
			if(espaco[x][y] == '0')
				cout << " ";
			else
				cout << espaco[x][y];		
		printf("\n");
	}
}
struct posicaojogador posicao_inicial_jogador(int inicio){
	struct posicaojogador jogador;
	
		jogador.x = inicio;
		jogador.y = inicio;

	return jogador;
}
