#include <stdio.h>

#define rows 20
#define col 21
void defineEspaco(char espaco[][col]);

int main(){
	char espaco[rows][col];

	defineEspaco(espaco);
return 0;
}
void defineEspaco(char espaco[][col]){
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
				printf(" ");
			else
				printf("%-20c",espaco[x][y]);
			
		printf("\n");
	}
}
