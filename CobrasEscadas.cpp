#include <iostream>

using namespace std;
#define rows 20
#define col 21

void defEspaco(char espaco[][col]);
void jogadores(char espaco[][col], int player);

int main(){
	char espaco[rows][col];
	int player1=1, 
	    player2, 
	    player3, 
	    player4;

	defEspaco(espaco);
	jogadores(espaco, player1);

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
	for(int x=0;x<rows;x++){
		for(int y=0;y<col;y++)
			if(espaco[x][y] == '0')
				cout << " ";
			else
				cout << espaco[x][y];		
		printf("\n");
	}
}
void jogadores(char espaco[][col], int jogador){
return;	
}
