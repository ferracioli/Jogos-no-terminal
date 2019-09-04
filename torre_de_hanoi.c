//TORRE DE HANOI,Codigo feito por Gabriel Monteiro Ferracioli
#include <stdio.h>
#include <stdlib.h>
	
typedef struct haste_{
	int vetor[8];
	//Struct para cada haste do jogo
	//E possivel tambem criar uma matriz 3x8 para as tres hastes e declarar apenas uma variavel assim
}haste;

//Funcoes:
haste *gera_haste(haste *pino, int tamanho);
void printa_trio(haste *base, haste *temporario, haste *fim, int segurando, int movimentos, int dificuldade);
void printa_um(haste *pino, int linha);
int verifica_pegar(haste *pino, int segura);
int verifica_colocar(haste *pino, int segura);
int confere(haste *fim, int dificuldade);

int main(){
	haste *base, *temporario, *fim;
	int dificuldade, movimentos, segura = 0;
	char verifica, acao;
	
	printf("TORRE DE HANOI\n");
	printf("  Regras:\n1:Voce deve colocar um disco de cada vez\n2:Um disco maior nunca fica acima de um menor\n3:Voce precisa levar todos os discos para FIM\n\n");
	do{
		//Laco de repeticao que forca o jogador a escolher um numero entre 3 e 8
		printf("Escolha uma quantidade de discos de 3 a 8\n");
		scanf("%d", &dificuldade);
		system("cls");
	}while(dificuldade < 3 || dificuldade > 8);
	
	do{
		//Repete enquanto o jogador quiser jogar e nao tiver passado do nivel 8
		//Faz a geracao das hastes e zera o numero de movimentos
		base = gera_haste(base, dificuldade);
		temporario = gera_haste(temporario, 0);
		fim = gera_haste(temporario, 0);
		movimentos=0;
		
		while(confere(fim, dificuldade )!= 1){
			//Cada nivel ocorre dentro deste laco
			if(segura == 0){
				//O jogador precisa pegar o disco de uma das bases
				system("cls");
				printf("Pegue um disco da haste: 'b' para base, 't' para temporaria, 'f' para fim\n\n");
				printa_trio(base, temporario, fim, segura, movimentos, dificuldade);
				fflush(stdin);
				scanf(" %c", &acao);
				switch(acao){
					case 'b':segura = verifica_pegar(base, segura);break;
					case 't':segura = verifica_pegar(temporario, segura);break;
					case 'f':segura = verifica_pegar(fim, segura);break;	
				}
			}
			else{
				//O jogador vai colocar o disco
				system("cls");
				printf("Coloque um disco na haste: 'b' para base, 't' para temporaria, 'f' para fim\n\n");
				printa_trio(base, temporario, fim, segura, movimentos, dificuldade);
				fflush(stdin);
				scanf(" %c", &acao);
				switch(acao){
					case 'b':segura = verifica_colocar(base, segura);break;
					case 't':segura = verifica_colocar(temporario, segura);break;
					case 'f':segura = verifica_colocar(fim, segura);break;	
				}
				movimentos++;
			}
		}
		system("cls");
		printf("\n");
		printa_trio(base, temporario, fim, segura, movimentos, dificuldade);
		printf("Parabens, voce terminou este nivel !\n");
		
		free(base);
		free(temporario);
		free(fim);
		if(dificuldade < 8){
			printf("Digite 'p' para jogar o proximo nivel e 's' para sair\n");
			scanf(" %c", &verifica);
			dificuldade++;
		}
	}while(verifica != 's' && dificuldade <= 8);
	printf("Muito bem,voce terminou o jogo !\n");
	scanf(" %c", &verifica);
	return 0;
}

haste *gera_haste(haste *pino, int tamanho){
	int i;
	//Gera uma haste com todos os elementos como 0
	haste *temp = (haste*)calloc(1, sizeof(haste));
	pino = temp;
	if(pino==NULL)
		exit(1);
	for(i = 7;tamanho > 0;i--){
		//Cria a sequencia hierarquica de discos
		//OBS:essa sequencia so ocorre para a base
		pino->vetor[i] = tamanho;
		tamanho--;
	}
	return pino;	
}

void printa_trio(haste *base, haste *temporario, haste *fim, int segurando, int movimentos, int dificuldade){
	//Imprime as tres torres
	int i;
	for(i = 0;i < 8;i++){
		printa_um(base, i);
		printa_um(temporario, i);
		printa_um(fim, i);
		printf("\n");
	}
	printf("       BASE            TEMPORARIO             FIM       \n\n");
	printf("                     SEGURANDO : %d ( ", segurando);
	for(i = 0;i < segurando;i++){
		printf("%c", 219);
	}
	printf(" )\n");
	printf("                     MOVIMENTOS : %d\n", movimentos);
	printf("                     NIVEL : %d\n", dificuldade);
	return;
}

void printa_um(haste *pino, int linha){
		//Imprime cada posicao da torre
		switch(pino->vetor[linha]){
			case 0:printf("         %c         ", 186);break;
			case 1:printf("         %c         ", 219);break;
			case 2:printf("        %c%c%c        ", 219, 219, 219);break;
			case 3:printf("       %c%c%c%c%c       ", 219, 219, 219, 219, 219);break;
			case 4:printf("      %c%c%c%c%c%c%c      ", 219, 219, 219, 219, 219, 219, 219);break;
			case 5:printf("     %c%c%c%c%c%c%c%c%c     ", 219, 219, 219, 219, 219, 219, 219, 219, 219);break;
			case 6:printf("    %c%c%c%c%c%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);break;
			case 7:printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);break;
			case 8:printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);break;
		}
		return;
}

int verifica_pegar(haste *pino, int segura){
	//Verifica se o jogador consegue pegar um disco do pino escolhido
	int i;
	for(i = 0;i < 8;i++){
		if(pino->vetor[i]!= 0){
			segura = pino->vetor[i];
			pino->vetor[i] = 0;
			return(segura);
		}
	}
	printf("  Nao tem pinos disponiveis para serem pegos\n");
	return 0;
}

int verifica_colocar(haste *pino, int segura){
	//Verifica se o jogador pode colocar o disco no pino escolhido
	int i;
	if(pino->vetor[7]==0){
		//pino vazio
		pino->vetor[7] = segura;
		return(0);
	}
	if(pino->vetor[0]!=0){
		//pino cheio
		return(segura);
	}
	for(i = 0;i < 8;i++){
		if(pino->vetor[i+1] != 0){
			//O proximo slot tem um disco
			if(pino->vetor[i+1] < segura){
				printf("O pino maior nao pode ficar em cima\n");
				return(segura);
			}
			pino->vetor[i] = segura;
			return(0);
		}
	}
}

int confere(haste *fim, int dificuldade){
	//Verifica se o jogador passou de nivel
	int i, cont = 1;
	for(i = 8-dificuldade;i < 8;i++){
		if(fim->vetor[i]==cont)
			cont++;
		else
			return 0;
	}
	return 1;
}
