#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
	char nome[13];
	int pontos;
}ficha;

void printa(char casas[3][3], ficha jogador[2]);
void validacao(char casas[3][3], char simbolo);
char verifica(char casas[3][3], int player, ficha jogador[2]);
void limpa_jogo(char casas[3][3]);

int main (){
	char casas[3][3];
	char encerra;
	int rodadas, fim = 0;
	ficha jogador[2];
	
	printf("\n                  JOGO DA VELHA\n\n");
	printf("Jogo feito por Gabriel Monteiro Ferracioli\n\nPressione qualquer tecla para jogar\n");
	getch();
	printf("Jogador 1,digite seu nome com ate 12 caracteres\n");
	scanf("%s", jogador[0].nome);
	printf("Jogador 2,digite seu nome com ate 12 caracteres\n");
	scanf("%s", jogador[1].nome);
	jogador[0].pontos = 0;
	jogador[1].pontos = 0;
		
	do{
		limpa_jogo(casas);
		encerra = '0';
	    printa(casas, jogador);
		for(rodadas = 1;encerra != '1';rodadas++){
			
			if(rodadas == 9){
				printf("Deu velha :(\n");
				encerra = '1';
			}
			else{
				if(rodadas%2 != 0){
					//primeiro jogador
					printf("%s,escolha um numero para colocar X\n", jogador[0].nome);
					validacao(casas, 'X');
					printa(casas, jogador);
					if(rodadas > 4){
						//Ate o quarto turno,e impossivel ter um vencedor,por isso a verificacao
						encerra = verifica(casas, 1, jogador);
					}
				}
				else{
					//segundo jogador
					printf("%s,escolha um numero para colocar O\n", jogador[1].nome);
					validacao(casas, 'O');
					printa(casas, jogador);
					if(rodadas > 4)
						encerra = verifica(casas, 2, jogador);
				}
		    }
			
			if(encerra == '1'){
				printf("Digite 1 se quiser fechar o jogo ou outro numero para continuar jogando\n");
				fflush(stdin);
			    scanf("%d", &fim);
			}
		}
	}while(fim != 1);
	return 0;
}

void printa(char casas[3][3], ficha jogador[2]){
	int i, j;
	
	system("cls");
	printf("%12s (X)%15s(O)\n", jogador[0].nome, jogador[1].nome);
	printf("Pontos:%d                   pontos:%d", jogador[0].pontos, jogador[1].pontos);
	//Tentei deixar uma distancia padrao entre os dados dos jogadores
	printf("\n\n\n");
	for(i = 0;i < 3;i++){
		printf("      ");
		for(j = 0;j < 3;j++){
			if(j < 2)
			   printf("%c|", casas[i][j]);
			else
			   printf("%c\n", casas[i][j]);
		}
		if(i < 2)
		    printf("     -------\n");
	}
	return;
}

void validacao(char casas[3][3], char simbolo){
	int lugar;
	char aviso;
	
	do{
	    aviso = '0';	
	    scanf("%d", &lugar);
	    if(lugar < 10 && lugar > 0){
		    if(lugar >0 && lugar <4){
			    //primeira linha
			    if(casas[0][lugar-1]=='X' || casas[0][lugar-1]=='O')
				    aviso = '1';
				    //o local ja estava ocupado
			    else
			        casas[0][lugar-1] = simbolo;	
			}
		    else{
			    if(lugar >3 && lugar < 7){
				    //segunda linha
				    if(casas[1][lugar-4]=='X' || casas[1][lugar-4]=='O')
				        aviso = '1';
				    else
			            casas[1][lugar-4] = simbolo;     	
			   }
			   else{
				    if(lugar > 6 && lugar < 10){
					    //ultima linha
					    if(casas[2][lugar-7]=='X' || casas[2][lugar-7]=='O')
				            aviso = '1';
				        else
			                casas[2][lugar-7] = simbolo;
				    }
			   }
		   }
       }
   else
        aviso = '1';
   if(aviso == '1')
	    printf("Por favor,digite uma coordenada valida\n");  	
	}while(aviso == '1');
return;
}

char verifica(char casas[3][3], int player, ficha jogador[2]){
	if(casas[0][0]==casas[1][1] && casas[1][1]==casas[2][2]){
		//diagonal
		jogador[player-1].pontos++;
		printa(casas, jogador);
		printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
		return '1';
	}
	else{
		if(casas[0][2]==casas[1][1] && casas[1][1]==casas[2][0]){
		   //outra diagonal
		   jogador[player-1].pontos++;
		   printa(casas, jogador);
		   printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
		   return '1';
	   }
	    else{
	    	if(casas[0][0]==casas[1][0] && casas[1][0]==casas[2][0]){
				//primeira coluna
				jogador[player-1].pontos++;
				printa(casas, jogador);
				printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
				return '1';
		    }
		    else{
		    	if(casas[0][1]==casas[1][1] && casas[1][1]==casas[2][1]){
					//segunda coluna
					jogador[player-1].pontos++;
					printa(casas, jogador);
					printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
					return '1';
			   }
			   else{
			   	  if(casas[0][2]==casas[1][2] && casas[1][2]==casas[2][2]){
						//terceira coluna
						jogador[player-1].pontos++;
						printa(casas, jogador);
						printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
						return '1';
			      }
			      else{
			      	 if(casas[0][0]==casas[0][1] && casas[0][1]==casas[0][2]){
							//primeira linha
							jogador[player-1].pontos++;
							printa(casas, jogador);
							printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
							return '1';
				     }
				     else{
				     	if(casas[1][0]==casas[1][1] && casas[1][1]==casas[1][2]){
							//segunda linha
							jogador[player-1].pontos++;
							printa(casas, jogador);
							printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
							return '1';
					    }
					    else{
					    	if(casas[2][0]==casas[2][1] && casas[2][1]==casas[2][2]){
								//terceira linha
								jogador[player-1].pontos++;
								printa(casas, jogador);
								printf("Parabens %s, voce venceu !!\n", jogador[player-1].nome);
								return '1';
						    }
                        }
                     }
                  }
               }
           }
       }
    }
	return '0';						
}

void limpa_jogo(char casas[3][3]){
	int i, j;
	char cont = '0';
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			cont++;
			casas[i][j] = cont;
		}
	}
	return;
}
