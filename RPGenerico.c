/* Jogo feito por Gabriel Monteiro Ferracioli com o intuito de praticar funcoes aprendidas em ICC
  Se tiver alguma duvida do codigo,sugestao ou critica,por favor,envie um e-mail para 
  ferracioligabriel@usp.br  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linhas{
	int vida_atual;
	int vida_MAX;
	int ataque;
	int defesa;
	int nivel;
	int xp;
	int pocoes;
	int ouro;
	int tx_critico;
	//Cada pocao aumenta 12 pontos de vida;
}dados;

//Funcoes:
char combate(dados *voce, dados *inimigo);
char printa_goblin(dados *jogador);
char printa_passaro(dados *jogador);
char printa_rato(dados *jogador);
char printa_slime(dados *jogador);
char printa_boss(dados *jogador);
char printa_lutador(dados *jogador);
char printa_tanque1(dados *jogador);
char printa_tanque2(dados *jogador);
void printa_jogador(dados *jogador);

int main (){
	int cont = 0;
	char letra;
	dados *voce;
	//Alocacao da struct com dados do jogador
	voce = (dados*)malloc(1*sizeof(dados));
	voce->ataque = 0;
	voce->nivel = 1;
	voce->vida_MAX = 19;
	voce->vida_atual = 19;
	voce->xp = voce->pocoes = 0;
	voce->defesa = 0;
	voce->ouro = 0;
	voce->tx_critico = 0;
	printf("\n\n\n");
	printf("          #####   #####    #####                       #\n");
	printf("          ##  ##  ##  ##  ###  ##   ####   #####     ####   #####   ##   ####    ####\n");
	printf("          ## ##   ##  ##  ##       ##  ##  #######  ##  ##  ##  ##      ##      ##  ##\n");
	printf("          ####    #####   ##  ###  ######  ##   ##  ######  ##      ##  ##      #    #\n");
	printf("          ## ##   ##      ##   ##  ##      ##   ##  ##      ##      ##  ##      ##  ##\n");
	printf("          ##  ##  ##       #####    ####   ##   ##   ####   ##      ##   ####    ####\n\n\n");
	printf("Feito por Gabriel Monteiro Ferracioli\n");
	printf("Digite algo para iniciar");
	getch();
	system("cls");
	//Deixei esta observacao pois getch tem um funcionamento diferente de scanf
	printf("\n\n\n\n               OBS:NAO E NECESSARIO PRESSIONAR A TECLA ENTER PARA CONFIRMAR AS ESCOLHAS");
	printf("\n                       Apenas pressione uma letra por vez");
	getch();
	system("cls");
	
	//INICIO
	printf("  Voce acorda em seu sofa,parece que dormiu demais depois do almoco.Voce nao e muito higienico,ha sujeira\npor toda parte...");
	printf("Ao levantar,voce fica com uma sensacao estranha,e vai ate o quintal para tomar um ar.\n  A partir dai que a historia fica mais");
	printf("estranha,pois onde devia ser seu quintal agora e um campo aberto,\nnao ha vizinho algum alem das distantes arvores.\n");
	printf("          ______________________________________________________________________\n");
	printf("          |                                                                    |\n");
	printf("          |  Escolha sua acao:'c' para caminhar ou 'v' para voltar para casa   |\n");
	printf("          |____________________________________________________________________|\n");
	letra = getch();
	switch(letra){
		case 'c':{
			system("cls");
			printf("  Apos alguns passos,voce percebe que ate a cor da grama mudou,de um verde seco se tornou um roxo\nbem escuro.");
			printf("  Sua casa ja estava bem distante da vista quando voce encontra um andarilho que te diz:\n");
			printf(" -Esta regiao e muito perigosa para voce caminhar assim,pegue essa espada.\n");
			printf("  (Nao e uma espada muito bonita,mas com seus 3 pontos de dano,voce podera se defender)\n\n");
			printf("                   _____\n");
			printf("           /\\     |     |\n");
			printf("          /  \\   _|_____|_ \n");
			printf("          |  |    |%c  %c |\n", 167, 167);
			printf("          |  |    \\_ o  /\n");
			printf("          |  |    __|  |__\n");
			printf("          |__|  /   \\  /  \\\n");
			printf("          (_ )\\/ /| |  | | \\\n");
			printf("           ||\\__/ | |  | | |\n");
			voce->ataque = 3;
			getch();
			break;
		}
		case 'v':{
			printf("Voce volta para a sala,devia ser so uma miragem !Entao voce pega no sono de novo e a historia se encerra !\n");
			getch();
			return 0;
			break;
		}
		default:{
			printf("  Cuidado para nao apertar teclas nao cadastradas,desta vez tudo bem...\n");
			printf("  Voce ganhou uma espada com 3 pontos de dano !");
			voce->ataque = 3;
			getch();
			break;
		}
	}
	system("cls");
	
	//PRIMEIRO COMBATE
	printf("  Ao continuar sua trilha,um passaro com um machado(algo nada comum)te ataca.\n  E hora do duelo!!!");
	getch();
	letra = printa_passaro(voce);
	switch(letra){
		case ('g'):{
			system("cls");
			printf("  Voce conseguiu o machado do passaro,agora pode ficar com ele(3 de dano e 15%% de critico ou vender por 3 de ouro)\n");
			printf("  OBS: danos criticos aqui causam 2x o dano normal\n");
			printf("           __________________________________________________________\n");
			printf("          |                                                          |\n");
			printf("          |  Digite 'v' para vender o machado ou 'e' para equipa-lo  |\n");
			printf("          |__________________________________________________________|\n");
			letra = getch();
			switch(letra){
				case 'v':{
					voce->ouro += 3;
					printf("  Ouro : %d\n", voce->ouro);
					break;
				}
				case 'e':{
					voce->tx_critico = 15;
					printf("  TX de critico : %d%%\n", voce->tx_critico);
					break;
				}
				default:{
					printf("  Puts,botao errado,agora o machado ja era\n");
					break;
				}
			}
			break;
		}
		case ('p'):{
			return 0;
			break;
		}
		default :{
			printf("  Voce segue seu caminho adiante\n");
			break;
		}		
	}
	printf("  Digite algo para continuar\n");
	getch();
	system("cls");
	
	//COGUMELOS
	printf("  Uau,voce encontrou alguns cogumelos,o que fara com eles ?\n");
	printf("          ___________________________________________________________\n");
	printf("          |                                                          |\n");
	printf("          |  Digite 'o' para observar melhor ou 'i' para ignora-los  |\n");
	printf("          |__________________________________________________________|\n\n");
	letra = getch();
	system("cls");
	switch(letra){
		case 'o':{
			printf("  Parece que ha dois tipos de cogumelos,os vermelhos e os azuis,vai querer comer algum ?\n");
			printf("          ___________________________________________________________________________\n");
			printf("          |                                                                          |\n");
			printf("          |  Digite 'a' para azul, 'v' para vermelho ou outra tecla para ignora-los  |\n");
			printf("          |__________________________________________________________________________|\n");
			letra = getch();
			switch(letra){
				case 'a':{
					printf("  Os cogumelos eram toxicos :(\n");
					printf("  Agora o jogo ficara levemente mais duro com voce,pois perdeu todo seu XP(Nao que seja muito)\n");
					voce->xp = 0;
					break;
				}
				case 'v':{
					printf("  Deu sorte,escolheu os cogumelos beneficos\n");
					printf("  Sua vida foi recuperada !!!\n");
					printf("  Vida: %d\n", voce->vida_atual);
					voce->vida_atual = voce->vida_MAX;
					break;
				}
				default:{
					printf("  Com medo de uma escolha errada,voce deixa de lado a ideia de comer cogumelos\n");
					break;
				}
			}
			break;
		}
		case 'i':{
			printf("  Seguiu o caminho sem nem olhar para tras.\n");
			break;
		}
		default:{
			printf("  Parece que voce ficou indeciso,mesmo assim deixou os cogumelos de lado.\n");
			break;
		}
	}
	printf("  Aperte algo para prosseguir na historia.\n");
	getch();
	system("cls");
	
	//SLIME
	printf("  No trajeto voce encontra uma carroca destruida,e ao verificar de perto,um slime pula\nem voce !\n");
	getch();
	letra = printa_slime(voce);
		switch(letra){
		case ('p'):{
			return 0;
			break;
		}
		default :{
			printf("  Voce segue seu caminho adiante.\n");
			break;
		}		
	}
	system("cls");
	
	//FAZENDEIRO
	printf("  Agora,voce encontra uma fazenda que aparenta estar em decadencia,olhando mais de perto voce ve\n");
	printf("que onde deveriam estar dezenas de vacas agora ha apenas o chao seco.O que resta do celeiro\n");
	printf("parece nao durar muito.\n");
	printf("  Voce bate na porta e um fazendeiro de aproximadamente 40 anos te atende.Com um olhar sem emocao\nele diz:\n");
	printf("  --Voce provavelmente viu o estado da minha fazenda,esses malditos goblins nao me deixam em paz.Ate minha\n");
	printf("amada se foi por causa dos diabretes.Por favor,mate todos e te recompensarei.Alias,se quiser comprar pocoes,\n");
	printf("eu as vendo por 5 moedas de ouro,elas recuperam 12 pontos de vida\n\n");
	printf("         ------        ^  ^  ^     \\_\n");
	printf("      __/______\\__    ||_||_||       \\__|  |_/\n");
	printf("     \\__|O--O |___/    \\_   _/          |  |\n");
	printf("        \\_ x _/          | |            |  |\n");
	printf("       ___| |_____       | |  _________/    \\_\n");
	printf("     /  | |__| |_  \\_____| |  \n");
	printf("    /  /|       |\\_______(  )\n");
	printf("   |  | |       |        | |\n");
	getch();
	system("cls");
	do{
		printf("           __________________________________________________________________________\n");
		printf("          |                                                                          |\n");
		printf("          |  Digite 'f' para ajudar o fazendeiro, 'c' para continuar seu caminho ou  |\n");
		printf("          |        'p' para comprar uma pocao (voce tem %2d de ouro)                  |\n", voce->ouro);
		printf("          |__________________________________________________________________________|\n");
		letra = getch();
		switch(letra){
			case ('f'):{
				    printf("  Voce encontrou um goblin\n");
				    getch();
				    letra = printa_goblin(voce);
					switch(letra){
						case ('g'):{
			                cont++;
			                if(cont == 5){
			                	system("cls");
			                	printf("  Voce matou todos os goblins,e o fazendeiro te deu uma recompensa:\n");
			                	printf("  Ganhou 3 pocoes e 10 de ouro\n");
			                	voce->pocoes+=3;
			                	voce->ouro+=10;
			                	printa_jogador(voce);
							}
			                break;
						}
						case ('p'):{
							return 0;
							break;
						}
						default :{
							printf("  Escapou da luta\n");
							break;
						}		
					}
				letra = 'f';
				if(cont == 5)
				     letra = 'c';	
				break;
			}
			case ('p'):{
				system("cls");
				if(voce->ouro >=5){
					voce->ouro -=5;
					voce->pocoes++;
					printa_jogador(voce);
				}
				else{
					printf("  Parece que voce nao possui dinheiro suficiente\n");
				}
				break;
			}
			case ('c'):{
				printf("  Agora a fazenda esta bem distante de voce\n");
				break;
			}
		}
	}while(letra == ('f') || letra == ('p'));
	
	
	//VILA
	do{
		getch();
		system("cls");
		printf("  Voce encontrou uma vila,nao e muito grande,porem o clima urbano\n");
		printf("alivia os varios ataques que voce sofreu ate aqui.\n");
		printf("  Ha uma loja aqui,e ao leste parece haver uma agitacao.\n\n");
		printf("          _____________________________________________________\n");
		printf("          |                                                    |\n");
		printf("          |  Digite 'l' para ir a loja ou 'v' para ver o rolo  |\n");
		printf("          |____________________________________________________|\n");
		letra = getch();
		switch(letra){
			case ('l'):{
					system("cls");
					
					//LOJINHA
					printf("  -Seja bem vindo a minha loja,voce deseja comprar ou vender ?\n\n");
					printf("           ______________________________________________\n");
					printf("          |                                              |\n");
					printf("          |  Digite 'c' para comprar ou 'v' para vender  |\n");
					printf("          |______________________________________________|\n");
					letra = getch();
				    system("cls");
				    switch(letra){
				    	case 'c':{
				    		printf("  -Esses sao meus produtos:\n\n");
				    		printf("  Escudo com 1 de defesa : 8 de ouro  ('a')\n");
				    		printf("  Escudo com 2 de defesa: 15 de ouro  ('s')\n");
				    		printf("  Espada com 5 de ataque: 10 de ouro  ('d')\n");
				    		printf("  Machado com 4 de dano e 50%% de critico: 20 de ouro  ('f')\n");
				    		printf("  Espadao com 12 de dano: 44 de ouro   ('g')\n");
				    		printf("  Aumento de 5 pontos de vida: 10 de ouro  ('h')\n");
				    		printf("  Voce tem %d moedas\n\n", voce->ouro);
				    		printf("             ____                      ____    ______  \n");
				    		printf("            |o  o|                    /    \\  [      ]\n");
				    		printf("            |  | |           /\\       \\    /  |      |\n");
				    		printf("     /\\     |_  _|       ___/  \\       \\__/   [      ]\n");
				    		printf("     ||   ____||____    |___    \\              \\____/\n");
				    		printf("     ||  / | |__| | \\    || \\   / \n");
				    		printf("     || / /|      |\\ \\__ || |  /\n");
				    		printf("     ||/ / |      | \\___(  )| / \n");
				    		printf("   ==##==__|______|______||_|/______||_____\n");
				    		printf("    ( )/                 ||        /__\\   /|\n");
				    		printf("     ||                 <__>       \\__/  //\n");
				    		printf("   _____________________________________//\n");
				    		printf("   ____________________________________|/\n");
				    		printf("           ____________________________________________________\n");
				    		printf("          |                                                    |\n");
				    		printf("          |  Escolha a letra que te agrade ou outra para sair  |\n");
				    		printf("          |____________________________________________________|\n");
				    		letra = getch();
				    		system("cls");
				    		switch(letra){
				    			case 'a':{
				    				if(voce->ouro >= 8){
				    					voce->defesa = 1;
					    				voce->ouro-=8;
					    				printa_jogador(voce);
									}
									else
										printf("  Tentando me sabotar nao e ?\n");
									break;
								}
								case 's':{
									if(voce->ouro >= 15){
										voce->defesa = 2;
										voce->ouro-=15;
										printa_jogador(voce);
									}
									else
										printf("  Ladrao\n");
									break;
								}
								case 'd':{
									if(voce->ouro >=10){
										voce->ataque = 5;
										voce->tx_critico = 0;
										voce->ouro-=10;
										printa_jogador(voce);
									}
									else
										printf("  Acha que eu nasci ontem ?\n");
									break;
								}
								case 'f':{
									if(voce->ouro >= 20){
										voce->ataque = 4;
										voce->tx_critico = 50;
										voce->ouro-=20;
										printa_jogador(voce);
									}
									else
										printf("  Money que e good nois nao have\n");
									break;
								}
								case 'g':{
									if(voce->ouro >=44){
										voce->ouro-=44;
										voce->ataque = 12;
										voce->tx_critico = 0;;
									}
									else
										printf("  Tu acha que eu tenho cara de saco de pao ?\n");
									break;
								}
								case 'h':{
									if(voce->ouro >=10){
										voce->vida_atual = voce->vida_MAX+=5;
										voce->ouro-=10;
										printa_jogador(voce);
								   }
									else
										printf("  O crime nao compensa\n");	
								    break;		
								}
								default:{
									printf("  Aperte algo para retornar ao menu\n");
									break;
								}
							}
							break;
						}
					    case 'v':{
					    	printf("  -Pago 3 moedas de ouro em cada pocao sua\n");
					    	printf("  -Tambem posso comprar cada ponto de vida maxima por 1 moeda\n");
					    	printf("  OBS: voce tem %d pocoes\n", voce->pocoes);
					    	printf("  OBS2: voce tem %d pontos de vida\n\n", voce->vida_MAX);
					    	printf("              _____________\n");
					    	printf("             |             |\n");
					    	printf("             |             |\n");
					    	printf("             | (o)    (o)  |\n");
					    	printf("             |       |     |      _\n");
					    	printf("             |       |     |     (_) \n");
					    	printf("             |             |    // \\\\__\n");
					    	printf("             |____     ____|    \\\\ ////\\\n");
					    	printf("             ____|    |_____     \\ ||||/\n");
					    	printf("            /  \\ \\_____\\ \\  \\    /\\__ /\n");
					    	printf("           /   |         |   \\  /\\__ /\n");
					    	printf("          /    /         |    \\/    /\n");
					    	printf("        _|____|__________|\\________/______      \n");
					    	printf("            _____                        /\n");
					    	printf("           /     \\      _               /\n");
					    	printf("          |       \\__  (_)  _          /\n");
					    	printf("           \\_______|_|     (_)        /\n");
					    	printf("   __________________________________________________________________________________\n");
					    	printf("  |                                                                                  |\n");
					    	printf("  |  aperte 'p' para vender uma pocao, 'v' para um ponto de vida ou outro para sair  |\n");
					    	printf("  |__________________________________________________________________________________|\n");
					    	letra = getch();
					    	system("cls");
					    	switch(letra){
					    		case 'p':{
									if(voce->pocoes > 0){
							    		printf("  Pocao vendida\n\n");
							    		voce->pocoes--;
							    		voce->ouro+=3;
							    		printa_jogador(voce);
								   }
								    else{
								    	printf("  Puts,voce nao tem pocoes disponiveis\n");
									}
									break;
								}
								case 'v':{
										system("cls");
										printf("  Corajoso,nao ?\n\n");
										voce->vida_MAX--;
										if(voce->vida_atual > voce->vida_MAX)
											voce->vida_atual--;
										voce->ouro++;
										printa_jogador(voce);
										break;
									}
							}
							break;
						}
				   }
				
				letra = 'l';
				break;
			}
			case ('v'):{
				system("cls");
				
				//PODREX
				printf("  Ao se aproximar,voce percebe que um rato gigante esta brigando com dois guardas.\n");
				printf("  O rato bombado diz:\n  -Nao vamos deixar isso barato,meu chefe dara um fim em voces.\n");
				printf("  Apos um tempo,a multidao comecou a diminuir quando o guarda te chamou em um canto:\n");
				printf("  -Voce parece ter bastante experiencia,venha comigo\n");
				printf("  Voces vao ate a taberna,conhecida na regiao como podrex,e o guarda te diz que uma\nquadrilha ");
				printf("anda saqueando vila por vila,e ele te ordena a ajuda-los.\n");
				printf("  (Voce tentou evita-lo,mas o brasao amarelo real te pressionou muito)\n");
				printf("  Sua vida foi recuperada apos uma rodada de comidas oleosas !\n");
				printf("                             ______\n");
				printf("                           //      \\\\\n");
				printf("            _____//\\\\_____//  %c%c%c%c  \\\\  \n", 177, 177, 177, 177);
				printf("           /    //__\\\\   //          \\\\       __\n");
				printf("          /_____|_%c%c_|__//    ____    \\\\     /\n", 177, 177);
				printf("          ||            ||   |____|   ||    /___\n");
				printf("          ||     %c%c%c    ||  __        ||    ||\n", 177, 177, 177);
				printf("          ||     %c%c%c    || |%c%c|       ||    ||\n", 177, 177, 177, 219, 219);
				printf("      ____||____________||_|%c%c|_______||____||__\n", 219, 219);
				voce->vida_atual = voce->vida_MAX;
				break;
			}
		}
	}while(letra != ('v'));
	getch();
	system("cls");
	printf("  Ao sair do podrex,o rato viu voce ao lado do guarda,e partiu para a briga\n");
	getch();
	do{
		letra = printa_rato(voce);
	    if(letra == 'p')
	         return 0;
	    if(letra == 'f')
		    printf("  Voce estava quase fugindo,mas o rato te alcancou\n");     
	}while(letra == 'f');
	system("cls");
	printf("  Com sua vitoria,conseguiu uma pocao e uma quadrilha de assassinos na sua cola\n");
	voce->pocoes++;
	printf("           ______________________________________________________________\n");
	printf("          |                                                              |\n");
	printf("          |  Aperte 'p' para usar a pocao ou outra coisa para guarda-la  |\n");
	printf("          |______________________________________________________________|\n\n");
	printf("  OBS:Sua vida esta em %d/%d\n", voce->vida_atual, voce->vida_MAX);
	printa_jogador(voce);
	letra = getch();
	system("cls");
	if(letra == 'p'){
		voce->pocoes--;
		if(voce->vida_atual+12>voce->vida_MAX)
		    voce->vida_atual = voce->vida_MAX;
		else
		    voce->vida_atual+=12;    
	}
	
	//ESTRADA
	printf("  Voce deixou o vilarejo, e nao foi  dificil encontrar o local de sua missao,\n");
	printf("pois de longe e possivel ver o ceu vermelho e a gigante nuvem de fumaca a alguns\n");
	printf("quilometros de distancia.Durante a trilha,as arvores a sua esquerda revelam outro\n");
	printf("rato.Ele avanca em voce sem pena :\n");
	getch();
	system("cls");
	letra = printa_rato(voce);
	if(letra == 'p')
	     return 0;
	system("cls");     
	printf("  Dois ratos seguidos te atacando,com certeza nao e um bom sinal.Continuando a trilha\n");
	printf("voce encontra uma cabana de descanso.A placa diz que um descanso custa 4 moedas.\n");
	printf("  OBS:Voce tem %d moedas\n\n", voce->ouro);     
	printf("           ____________________________________________________________\n");
	printf("          |                                                            |\n");
	printf("          |  Aperte 'd' para descansar ou outro botao para prosseguir  |\n");
	printf("          |____________________________________________________________|\n");
	letra = getch();
	system("cls");
	if(letra == 'd'){
		printf("  Finalmente um pouco de descanso\n");
		voce->ouro-=4;
		voce->vida_atual = voce->vida_MAX;
		printa_jogador(voce);
		getch();
		system("cls");
	}
	
	//CIDADE
	printf("  Caminhando mais um pouco,voce encontrou a provavel cidade na qual\n");
	printf("a quadrilha esta.E impossivel nao reparar no clima pessimista e o enorme\n");
	printf("incendio no centro da cidade.\n");
	printf("  Antes que voce pudesse tomar qualquer atitude,voce e atacado novamente:\n");
	printf("  -O cla Jooj nao admite novas pessoas na cidade !!!\n");
	getch();
	system("cls");
	if(letra == 'p')
	    return 0;
	    do{
	    	letra = printa_lutador(voce);
	    	if(letra == 'p')
	    	   return 0;
	    	if(letra == 'f'){
	    		printf("  Fugir sera em vao desta vez,ele corre mais que voce\n");
	    		getch();
			}   
		}while(letra != 'g');
	    system("cls");
	    printf("  Apos sua vitoria,o clima da cidade mudou.Pode-se ouvir gritos de\n");
	    printf("esperanca ao mesmo tempo em que algo suspeito acontece,um rato sai\n");
	    printf("de uma casa e te fala:\n");
	    printf("  -Ta na hora de darmos um fim em voce,o chefe esta furioso\n");
	    printf("  Antes que voce pudesse agir,um morador te da uma pocao de cura completa\n");
	    printf("  Voce e a esperanca dos moradores agora\n");
	    voce->vida_atual = voce->vida_MAX;
	    getch();
	    system("cls");
	    letra = printa_rato(voce);
	    if(letra == 'p')
	        return 0;
		system("cls");
		printf("  Um rato gigante ja e algo estranho,mas 3 sao o cumulo\n");
		printf("  Aquele morador que recebeu tua ajuda disse :\n");
		printf("  -Muito obrigado por nos ajudar,os Jooj nao nos dao paz ha meses.Por\n");
		printf("favor,visite minha loja,acho que vai gostar do que tenho nela\n");
		do{
		    printf("     ____________________________________________________\n");	
			printf("    |                                                    |\n");	
			printf("    |  Digite 'l' para loja ou 'c' para salvar a cidade  |\n");	
			printf("    |____________________________________________________|\n");	
			letra = getch();
			system("cls");
			if(letra == 'l'){
				printf("  -Tenho os seguintes equipamentos:\n");
				printf("  Aumento de vida maxima em 6: 11 de ouro  ('a')\n");
				printf("  Escudo com 3 de defesa: 23 de ouro   ('s')\n");
				printf("  Escudo com 4 de defesa: 31 de ouro   ('d')\n");
				printf("  Pocao que restaura 12 de vida: 5 de ouro   ('f')\n");
				printa_jogador(voce);
				printf("     ______________________________________________________\n");	
				printf("    |                                                      |\n");	
				printf("    |  Escolha a letra que voce quiser ou outra para sair  |\n");	
				printf("    |______________________________________________________|\n");
				letra = getch();
				system("cls");
				switch(letra){
					case('a'):{
						if(voce->ouro >=11){
							voce->ouro-=11;
							voce->vida_MAX+=6;
							voce->vida_atual+=6;
							break;
						}
						else{
							printf("  Ta pensando que eu nasci ontem ?\n");
							break;
						}
					}
					case('s'):{
						if(voce->ouro >=23){
							voce->ouro-=23;
							voce->defesa=3;
							break;
						}
						else{
							printf("  Te jooj\n");
							break;
						}
					}
					case('d'):{
						if(voce->ouro >=31){
							voce->defesa = 4;
							voce->ouro-=31;
							break;
						}
						else{
							printf("  To de olho nessa sua zoeira\n");
							break;
						}
					}
					case('f'):{
						if(voce->ouro >=5){
							voce->ouro-=5;
							voce->pocoes++;
							printf("  Quer usar a pocao ?Sua vida esta em %d/%d\n", voce->vida_atual, voce->vida_MAX);
							printf("       ________________________________________________________\n");
							printf("      |                                                        |\n");
							printf("      |  Digite 's' para usar a pocao ou 'n' para continuar    |\n");
							printf("      |________________________________________________________|\n");
							letra = getch();
							system("cls");
							switch(letra){
								case('s'):{
									voce->pocoes--;
									if(voce->vida_atual+12>voce->vida_MAX)
									    voce->vida_atual = voce->vida_MAX;
									else
									   voce->vida_atual+=12;    
									break;
								}
								default:{
									letra = 'n';
									break;
								}
							}
							break;
						}
						else{
							printf("  So nao chamo a policia porque aqui nao tem\n");
							break;
						}
					}
				}
					
			}
		} while(letra != 'c');  
		
		//BOSS 
	    printf("  Seu objetivo agora esta muito proximo,a prefeitura destruida.\n");
		printf("  E dela sai alguem muito bem equipado,aponta para longe,e diz:\n");
		printf("  -Voces dois,destruam esse idiota que esta nos incomodando\n");
		printf("  Entao o primeiro tanque te ataca,com suas flechas do tamanho de\n");
		printf("pequenos troncos\n"); 
		printf("               |\\   /|\n"); 
		printf("                \\\\_//\n"); 
		printf("                  \\\\___\n"); 
		printf("                  /____ \\_ \n"); 
		printf("                 |#  # |  \\ _  \n"); 
		printf("                 /\\    /___\\/\n"); 
		printf("        (  )  _____|__|___//___\n"); 
		printf("         \\  \\/\\      (  )  /_\\/\n"); 
		printf("          \\  \\ \\      \\  \\/  )\n"); 
		printf("           \\__/ |__/  \\\\  \\ )\n"); 
		printf("                |       \\__/\n");   
		getch();
		system("cls");    
	    do{
	    	letra = printa_tanque1(voce);
	        if(letra == ('p'))
	            return 0;
	        if(letra == ('f')){
			    printf("  Nao da para fugir de um tanque desses\n"); 
				getch();
			}
		}while(letra != ('g'));
		system("cls");
	    printf("  Agora que passou pelo primeiro,e hora de enfrentar o segundo tanque.\n");
		printf("  O segundo nao aparenta ser nada agressivo,porem aparenta maior resistencia\n");
		getch();
		do{
			letra = printa_tanque2(voce);
			if(letra == ('p'))
			    return 0;
			if(letra == ('f'))
			    printf("  O tanque te alcancou\n");    
			    getch();
		}while(letra !='g');    
		system("cls");
	    printf("  Depois de passar por tudo isso,voce consegue finalmente entrar na prefeitura.\n");
	    printf("  E notavel como tudo em seu redor esta destruido,nao restou nada.Voce entao\n");
	    printf("ouve um barulho proximo,vem da sala do prefeito.Ao entrar,voce acha o lider do\n");
	    printf("grupo pronto para te esfarelar.Cuidado agora !\n");
	    getch();
	    system("cls");
	    do{
	    	if(letra == ('p'))
	    	    return 0;
	    	if(letra == ('f'))
			    printf("  Essa tentativa foi inutil\n");    
	    	letra = printa_boss(voce);
		}while(letra != ('g'));
		system("cls");
	   printf("  O ultimo golpe que voce deu foi tao forte que jogou o lider da quadrilha para fora\n");
	   printf("da sala,e apos um curto silencio,todos gritam de alegria pelo fim do terror na cidade.\n");
	   printf("  Voce passou foi carregado como se fosse um astro do rock,e finalmente teve um momento\n");
	   printf("em paz quando os soldados chegaram.Aquele que falou com voce no podrex te chamou em um\n");
	   printf("canto para falar:\n");
	   printf("  -Muito obrigado por nos ajudar com este problema,como recompensa nos te daremos o caminho\n");
	   printf("de volta.\n  Ele entao te mostra uma pedra estranha que solta fagulhas escarlates.Apos duas batidas na\n");
	   printf("pedra,um portal se abre em pleno beco.Ele fala finalmente:\n");
	   printf("  -Nao vou dar uma de Mestre dos Magos,alguem abriu o portal entre nossos mundos e estou encarregado\n");
	   printf("de retornar quem veio parar aqui.Agora corra,ele dura pouco.\n");
	   printf("  Voce corre entao e retorna para casa,na sua cama.Apos a teoria de ser um sonho,voce ve algumas marcas\n");
	   printf("de porrada que tomou,certamente foi real...\n");
	   getch();
	   system("cls");
	   printf(" Obrigado a voce,que chegou ate aqui !Espero que tenha gostado ou nao da experiencia!\n");
	   getch(); 
	free(voce);
	return 0;
	//Jogo feito por Gabriel Monteiro Ferracioi
}

char combate(dados *voce, dados *inimigo){
	char acao;
	int i;
	srand(time(NULL));
		do{
			printf("           ____________________________________________________________________________\n");
			printf("          |                                                                            |\n");
			printf("          |  Digite 'a' para atacar, 'p' para usar uma pocao ou 'f' para tentar fugir  |\n");
			printf("          |____________________________________________________________________________|\n");
			fflush(stdin);
			acao = getch();
			system("cls");
		}while((acao != 'a') && (acao != 'p') && (acao != 'f'));
		
		switch(acao){
			case ('a'):{
				switch(voce->tx_critico){
					case 0:{
						printf("  Voce causou %d de dano\n", voce->ataque - inimigo->defesa);
				        inimigo->vida_atual-=voce->ataque - inimigo->defesa;
						break;
					}
					default:{
						srand(time(NULL));
						if(rand()%100 <= voce->tx_critico){
							printf("  Causou dano critico de %d pontos\n", (2*voce->ataque)-inimigo->defesa);
							inimigo->vida_atual-=(2*voce->ataque)-inimigo->defesa;
						}
						else{
							printf("  Voce causou %d de dano\n", voce->ataque - inimigo->defesa);
				            inimigo->vida_atual-=voce->ataque - inimigo->defesa;
						}
						break;
					}
				}
				break;
			}
				
			case 'p':{
					if(voce->pocoes > 0){
					     voce->pocoes--;
					     if(voce->vida_atual+12 > voce->vida_MAX){
					          voce->vida_atual = voce->vida_MAX;
					          printf("  Vida totalmente recuperada\n");
					    }else{
						      voce->vida_atual+=12;
							  printf("  12 pontos de vida recuperados\n");    
					    }
			        }
			        else{
			        	printf("  Puts,voce ta sem pocoes\n");
					}
			        break;
			}	
				
			case'f':{
						  //srand(time(NULL));
						  if(rand()%100 <= 40){
						  	    printf("  Voce conseguiu cair fora !\n");
						  	    return ('f');
						  }
						  else{
						  	    printf("  Hoje nao e o seu dia,a fuga deu ruim\n");
						  }
						  break;
			}
	   }
		if(inimigo->vida_atual <=0){
			//Se voce venceu
			printf("  Voce venceu a batalha\n");
			voce->ouro+=inimigo->ouro;
			printf("  Voce recebeu %d de ouro\n", inimigo->ouro);
			printf("  A experiencia ganha foi de %d pontos\n", inimigo->xp);
			voce->xp+=inimigo->xp;
			if(voce->xp >= 10*voce->nivel){
				printf("  Voce passou de nivel e sua vida aumentou em 3 (saude recuperada!)\n");
				voce->xp-=voce->nivel*10;
				voce->nivel++;
				voce->vida_atual = voce->vida_MAX+=3;
			}
			printf("\n");
			printa_jogador(voce);
			printf("  Digite qualquer coisa para atualizar a tela\n");
			getch();
			return ('g');
		}
		if(inimigo->ataque - voce->defesa>0){
			voce->vida_atual-=inimigo->ataque - voce->defesa;
		printf("  Voce recebeu %d de dano\n\n\n", inimigo->ataque - voce->defesa);
		}
		else{
			printf("  Sua defesa esta muito alta,voce nao recebeu dano\n\n\n");
		}
		if(voce->vida_atual <=0){
			printf("  Voce perdeu a batalha :(\n");
			printf("  GAME OVER\n");
			getch();
			return ('p');
		}
	return ('c');
}

char printa_goblin(dados *jogador){
	char letra;
	dados *goblin;
	goblin = (dados*)malloc(1*sizeof(dados));
	goblin->ataque = 2;
	goblin->vida_atual = goblin->vida_MAX = 15;
	goblin->xp = 6;
	goblin->ouro = 2;
	goblin->defesa = 0;
	do{
	system("cls");
	printf("\n\n\n\n");	
	printf("\n                            -^-----^       GOBLIN\n");
	printf("                           |  ;  ; |/      vida:%3d/%3d\n", goblin->vida_atual, goblin->vida_MAX);
	printf("                        ^  \\   -  /\n");
	printf("                       / \\ / /    \\\n");
	printf("                       | |/ /__/ / \\\n");
	printf("                       ( )_______/__|\n");
	printf("                         /   __    /\n");
	printf("                        /   /  \\   \\\n\n");
	printa_jogador(jogador);	
		
	letra = combate(jogador, goblin);
	
	if(letra == ('c')){
		printf("\n                            -^-----^       GOBLIN\n");
		printf("                           |  ;  ; |/      vida:%3d/%3d\n", goblin->vida_atual, goblin->vida_MAX);
		printf("                        ^  \\   -  /\n");
		printf("                       | \\  / /    \\ \n");
		printf("                        \\_\\/|/ /    \\  \n");
		printf("			 ( )/ /_____| \n");
		printf("			  ( )/  _   \\ \n");
		printf("			   /   / \\   \\  \n\n");
		printa_jogador(jogador);
		printf("  Digite algo para atualizar a tela\n");
		getch();
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   
   free(goblin);
	return (letra);
}
//Jogo feito por Gabriel Monteiro Ferracioli
char printa_passaro(dados *jogador){
	char letra;
	dados *passaro;
	passaro = (dados*)malloc(1*sizeof(dados));
	passaro->ataque = 2;
	passaro->vida_atual = passaro->vida_MAX = 15;
	passaro->xp = 6;
	passaro->ouro = 2;
	passaro->defesa = 0;
	do{
	system("cls");	
	printf("\n\n\n\n");
	printf("\n                                       ^       PASSARO COM MACHADO\n");
	printf("                         \\\\\\\\         / \\\\      vida:%3d/%3d\n", passaro->vida_atual, passaro->vida_MAX);
	printf("                   _____/  ^  \\     _/   ||\n");
	printf("                  /_____ \\ o   |   | |___||\n");
	printf("                       /_/    /    | |   \\/\n");
	printf("                         __| |_____|( )\n");
	printf("                        /       _____/\n");
	printf("                       / /|    |\n");
	printf("                       \\ \\|    |\n\n");	
	printa_jogador(jogador);	
		
	letra = combate(jogador, passaro);
	
	if(letra == ('c')){
		printf("\n                                       ^       PASSARO COM MACHADO\n");
		printf("                         \\\\\\\\         / \\\\      vida:%3d/%3d\n", passaro->vida_atual, passaro->vida_MAX);
		printf("                   _____/  ^  \\     _/   ||\n");
		printf("                  /_____ \\ o   |   | |___||\n");
		printf("                       /_/    /    | |   \\/\n");
		printf("                         __| |_____|( )\n");
		printf("                        /       _____/\n");
		printf("                       / /|    |\n");
		printf("                       \\ \\|    |\n\n");	
		printa_jogador(jogador);
		printf("  Digite algo para atualizar a tela\n");
		getch();
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   
   free(passaro);
	return (letra);
}

char printa_rato(dados *jogador){
	char letra;
	dados *rato;
	rato = (dados*)malloc(1*sizeof(dados));
	rato->ataque = 4;
	rato->vida_atual = rato->vida_MAX = 21;
	rato->xp = 10;
	rato->ouro = 8;
	rato->defesa = 1;
	do{
	system("cls");	
	printf("\n\n\n\n");
	printf("\n                               __   __      RATO BOMBADO\n");
	printf("                              ( ))_( ))     vida:%3d/%3d\n", rato->vida_atual, rato->vida_MAX);
	printf("                            __/ *  * |  _       \n");
	printf("                          (O         / //      \n");
	printf("                           UU---___/\\_//_     \n");
	printf("                          ( \\      //    )     \n");
	printf("                          (  |    //|(   )      \n");
	printf("                         /  /\\___//_/ \\  \\     \n");
	printf("                        ( )/ /_______\\ \\( )     \n\n");	
	printa_jogador(jogador);		
	letra = combate(jogador, rato);
	
	if(letra == ('c')){
		printf("\n                               __   __      RATO BOMBADO\n");
		printf("                              ( ))_( ))     vida:%3d/%3d\n", rato->vida_atual, rato->vida_MAX);
		printf("                            __/ *  * |  _\n");
		printf("                          (O         / //\n");
		printf("                           UU---___/\\_//_\n");
		printf("                          ( \\      //    )\n");
		printf("                        __(  |    // (   )__\n");
		printf("                     (  )____/\\__//__/\\____(  )\n");
		printf("                              |______|\n\n");
		printa_jogador(jogador);
		printf("  Digite algo para atualizar a tela\n");
		getch();	
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   
   free(rato);
	return (letra);
}

char printa_slime(dados *jogador){
	char letra;
	dados *slime;
	slime = (dados*)malloc(1*sizeof(dados));
	slime->ataque = 2;
	slime->vida_atual = slime->vida_MAX = 11;
	slime->xp = 4;
	slime->ouro = 3;
	slime->defesa = 0;
	do{
	system("cls");	
	printf("\n\n\n\n");
	printf("\n                                  ____       SLIME\n");
	printf("                            _____/    \\_      vida:%3d/%3d\n", slime->vida_atual, slime->vida_MAX);
	printf("                          _/             \\_\n");
	printf("                         /   O   O         \\\n");
	printf("                         |  _____          |\n");
	printf("                         \\  |____|       _/\n");
	printf("                          \\_____________/\n\n");	
	printa_jogador(jogador);		
	letra = combate(jogador, slime);
	
	if(letra == 'c'){
		printf("\n                                  ____       SLIME\n");
		printf("                            _____/    \\_      vida:%3d/%3d\n", slime->vida_atual, slime->vida_MAX);
		printf("                          _/             \\_\n");
		printf("                         /   O   O         \\\n");
		printf("                         |  _____          |\n");
		printf("                         \\  |____|       _/\n");
		printf("                          \\_____________/\n\n");
		printa_jogador(jogador);
		printf("  Digite algo para atualizar a tela\n");
		getch();	
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   free(slime);
	return (letra);
}

char printa_boss(dados *jogador){
	char letra;
	dados *boss;
	boss = (dados*)malloc(1*sizeof(dados));
	boss->ataque = 5;
	boss->vida_atual = boss->vida_MAX = 32;
	boss->xp = 60;
	boss->ouro = 1000;
	boss->defesa = 3;
	do{
		system("cls");	
		printf("\n\n\n\n\n");
		printf("                                    _       CHEFAO SEM NOME\n");
		printf("                                   /||      vida:%3d/%3d\n", boss->vida_atual, boss->vida_MAX);
		printf("                        |\\   /|   / ||\n");
		printf("                         \\\\_//   /  ||\n");
		printf("                           \\\\___/   //\n");
		printf("                          /____/   //\n");
		printf("                         |#  #/   //\n");
		printf("                         \\_  /   //\n");
		printf("                      _____|/   //______\n");
		printf("                     /\\    /   //   /_\\/\n");
		printf("                    (  \\  /\\  //   /   )\n");
		printf("                    |  ||//_\\//___/   /\n");
		printf("                    \\  \\(  )_________/\n");
		printf("                     \\(  )       |\n\n");	
		printa_jogador(jogador);		
		letra = combate(jogador, boss);
	
	if(letra == 'c'){
		printf("\n");
		printf("                                    _       CHEFAO SEM NOME\n");
		printf("                                   /||      vida:%3d/%3d\n", boss->vida_atual, boss->vida_MAX);
		printf("                        |\\   /|   / ||\n");
		printf("                         \\\\_//   /  ||\n");
		printf("                           \\\\___/   //\n");
		printf("                          /____/   //\n");
		printf("                         |#  #/   //\n");
		printf("                         \\_  /   //\n");
		printf("                      _____|/   //______\n");
		printf("                     /\\    /   //   /_\\/\n");
		printf("                    (  \\  /\\  //   /   )\n");
		printf("                    |  ||//_\\//___/   /\n");
		printf("                    \\  \\(  )_________/\n");
		printf("                     \\(  )       |\n\n");
		printa_jogador(jogador);
		printf("  Digite algo para atualizar a tela\n");
		getch();	
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   free(boss);
	return (letra);
}

char printa_lutador(dados *jogador){
	char letra;
	dados *lutador;
	lutador = (dados*)malloc(1*sizeof(dados));
	lutador->ataque = 3;
	lutador->vida_atual = lutador->vida_MAX = 29;
	lutador->xp = 8;
	lutador->ouro = 10;
	lutador->defesa = 1;
	do{
		system("cls");	
		printf("\n\n\n\n");
		printf("\n                 _____       LUTADOR\n");
	    printf("                /  ^ ^\\      vida:%3d/%3d\n", lutador->vida_atual, lutador->vida_MAX);
		printf("               (   -\\-|\n");
		printf("             ___\\  ~ _/__\n");	
		printf("            /      __    \\ __\n");	
		printf("            \\  \\ _/ _)/\\  (_ \\ \n");	
		printf("             \\  \\/_/\\_| \\  / / \n");	
		printf("             |\\___/ \\_|  \\/_/\n");	
		printf("             |========|\n\n");		
		printa_jogador(jogador);	
			
		letra = combate(jogador, lutador);
		
		if(letra == ('c')){
			printf("\n                 _____       LUTADOR\n");
		    printf("                /  ^ ^\\      vida:%3d/%3d\n", lutador->vida_atual, lutador->vida_MAX);
			printf("               (   -\\-|\n");
			printf("             ___\\  ~ _/__\n");	
			printf("            /      __    \\ __\n");	
			printf("            \\  \\ _/ _)/\\  (_ \\ \n");	
			printf("             \\  \\/_/\\_| \\  / / \n");	
			printf("             |\\___/ \\_|  \\/_/\n");	
			printf("             |========|\n\n");	
			printa_jogador(jogador);
			printf("  Digite algo para atualizar a tela\n");
			getch();
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   
   free(lutador);
	return (letra);
}

char printa_tanque1(dados *jogador){
	char letra;
	dados *tanque1;
	tanque1 = (dados*)malloc(1*sizeof(dados));
	tanque1->ataque = 9;
	tanque1->vida_atual = tanque1->vida_MAX = 10;
	tanque1->xp = 0;
	tanque1->ouro = 10;
	tanque1->defesa = 0;
	do{
	system("cls");	
	printf("\n\n\n\n");
	printf("\n              _ _ ___       V3SP-4\n");
	printf("             / \\ \\   \\      vida:%3d/%3d\n", tanque1->vida_atual, tanque1->vida_MAX);
	printf("            / \\ \\ \\ O \\___\n");
	printf("           |\\ <==\\_\\___\\  \\\n");
	printf("            \\\\  \\/     |___\\\n");
	printf("             \\\\ /      /____| \n");
	printf("              \\|_ ____/   \\_/\n");
	printf("                \\_/\n\n");
	
	printa_jogador(jogador);	
		
	letra = combate(jogador, tanque1);
	
	if(letra == ('c')){
		printf("\n              _ _ ___       V3SP-4\n");
	printf("             / \\ \\   \\      vida:%3d/%3d\n", tanque1->vida_atual, tanque1->vida_MAX);
	printf("            / \\ \\ \\ O \\___\n");
	printf("           |\\ <==\\_\\___\\  \\\n");
	printf("            \\\\  \\/     |___\\\n");
	printf("             \\\\ /      /____| \n");
	printf("              \\|_ ____/   \\_/\n");
	printf("                \\_/\n\n");
		printa_jogador(jogador);
		printf("  Digite algo para atualizar a tela\n");
		getch();
	}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   
   free(tanque1);
	return (letra);
}

char printa_tanque2(dados *jogador){
	char letra;
	dados *tanque2;
	tanque2 = (dados*)malloc(1*sizeof(dados));
    tanque2->ataque = 2;
	tanque2->vida_atual = tanque2->vida_MAX = 60;
	tanque2->xp = 50;
	tanque2->ouro = 10;
	tanque2->defesa = 0;
	do{
		system("cls");	
		printf("\n\n\n\n");
		printf("\n              _________ __ ___       J4B-T1\n");
		printf("             / \\       /\\_\\   \\      vida:%3d/%3d\n", tanque2->vida_atual, tanque2->vida_MAX);
		printf("           <|   \\      \\/__\\   \\\n");
		printf("             \\   \\______________\\ \n");
		printf("              \\  /               \\ \n");
		printf("               <|_________________|\n");
		printf("                 \\_/           \\_/\n\n");
		printa_jogador(jogador);	
			
		letra = combate(jogador, tanque2);
		
		if(letra == ('c')){
			printf("\n              _________ __ ___       J4B-T1\n");
			printf("             / \\       /\\_\\   \\      vida:%3d/%3d\n", tanque2->vida_atual, tanque2->vida_MAX);
			printf("           <|   \\      \\/__\\   \\\n");
			printf("             \\   \\______________\\ \n");
			printf("              \\  /               \\ \n");
			printf("               <|_________________|\n");
			printf("                 \\_/           \\_/\n\n");	
			printa_jogador(jogador);
			printf("  Digite algo para atualizar a tela\n");
			getch();
		}
   }while((letra != 'g') && (letra != 'p')  && (letra != 'f'));
   
   free(tanque2);
	return (letra);
}
//Jogo feito por gabriel Monteiro Ferracioli
void printa_jogador(dados *jogador){
	if(jogador->defesa == 0){
		//personagem sem escudo
		if(jogador->tx_critico==0){
			if(jogador->ataque != 12){
				printf("VOCE               ^^^^^^^^         ^ \n");
				printf("LV:%2d  XP:%3d/%3d  |     ' |       / | \n", jogador->nivel, jogador->xp, jogador->nivel*10);
				printf("Vida: %3d/%3d      C    o  \\      / / \n", jogador->vida_atual, jogador->vida_MAX);
				printf("Ataque: %2d         |    ~  |     / / \n", jogador->ataque);
				printf("Defesa:%1d           |_ _____/    / / \n", jogador->defesa);
				printf("Ouro: %3d           |_     \\   / / \n", jogador->ouro);
				printf("Pocoes: %1d           | \\____/  ~%%~\n", jogador->pocoes);
				printf("critico: %2d%%        \\_______|(  ) \n", jogador->tx_critico);
				printf("                    |     |  \n\n");
			}
			else{
				printf("VOCE               ^^^^^^^^        /espadao/ \n");
				printf("LV:%2d  XP:%3d/%3d  |     ' |      / muito / \n", jogador->nivel, jogador->xp, jogador->nivel*10);
				printf("Vida: %3d/%3d      C    o  \\     /grande / \n", jogador->vida_atual, jogador->vida_MAX);
				printf("Ataque: %2d         |    ~  |    /  nao  / \n", jogador->ataque);
				printf("Defesa:%1d           |_ _____/   / cabe  / \n", jogador->defesa);
				printf("Ouro: %3d           |_     \\  /  _____/ \n", jogador->ouro);
				printf("Pocoes: %1d           | \\____/  ~%%~\n", jogador->pocoes);
				printf("critico: %2d%%        \\_______|(  ) \n", jogador->tx_critico);
				printf("                    |     |  \n\n");
			}	
	    }
       else{
       	    printf("VOCE               ^^^^^^^^          \n");
			printf("LV:%2d  XP:%3d/%3d  |     ' |           \n", jogador->nivel, jogador->xp, jogador->nivel*10);
			printf("Vida: %3d/%3d      C    o  \\  ___/\\         \n", jogador->vida_atual, jogador->vida_MAX);
			printf("Ataque: %2d         |    ~  | |___  \\    \n", jogador->ataque);
			printf("Defesa:%1d           |_ _____/  || \\ /   \n", jogador->defesa);
			printf("Ouro: %3d           |_     \\  || |/   \n", jogador->ouro);
			printf("Pocoes: %1d           | \\____/  ||\n", jogador->pocoes);
			printf("critico: %2d%%        \\_______|(  ) \n", jogador->tx_critico);
			printf("                    |     |  \n\n");
	   }
	}
	else{
		//personagem usando escudo
		if(jogador->tx_critico==0){
			if(jogador->ataque != 12){
				printf("VOCE               ^^^^^^^^      ^ \n");
				printf("LV:%2d  XP:%3d/%3d  | ~  ^ |     / | \n", jogador->nivel, jogador->xp, jogador->nivel*10);
				printf("Vida: %3d/%3d      | o/ o |    / / \n", jogador->vida_atual, jogador->vida_MAX);
				printf("Ataque: %2d     ____\\  O  /_   / / \n", jogador->ataque);
				printf("Defesa:%1d      [     ]    \\ \\ / / \n", jogador->defesa);
				printf("Ouro: %3d     |     |    |\\ ~%%~ \n", jogador->ouro);
				printf("Pocoes: %1d     [     ]    | ( )\n", jogador->pocoes);
				printf("critico: %2d%%   \\___/     \\ \n", jogador->tx_critico);
			}
			else{
				printf("VOCE               ^^^^^^^^      /   O   / \n");
				printf("LV:%2d  XP:%3d/%3d  | ~  ^ |     /ESPADAO/ \n", jogador->nivel, jogador->xp, jogador->nivel*10);
				printf("Vida: %3d/%3d      | o/ o |    /   EH  / \n", jogador->vida_atual, jogador->vida_MAX);
				printf("Ataque: %2d     ____\\  O  /_   /  OP   / \n", jogador->ataque);
				printf("Defesa:%1d      [     ]    \\ \\ / ______/ \n", jogador->defesa);
				printf("Ouro: %3d     |     |    |\\ ~%%~ \n", jogador->ouro);
				printf("Pocoes: %1d     [     ]    | ( )\n", jogador->pocoes);
				printf("critico: %2d%%   \\___/     \\ \n", jogador->tx_critico);
			}
	    }
	    else{
	    	printf("VOCE               ^^^^^^^^\n");
			printf("LV:%2d  XP:%3d/%3d  | ~  ^ |     _/\\\n", jogador->nivel, jogador->xp, jogador->nivel*10);
			printf("Vida: %3d/%3d      | o/ o |    |   \\\n", jogador->vida_atual, jogador->vida_MAX);
			printf("Ataque: %2d     ____\\  O  /_    //\\ /\n", jogador->ataque);
			printf("Defesa:%1d      [     ]    \\ \\  // |/\n", jogador->defesa);
			printf("Ouro: %3d     |     |    |\\ \\// \n", jogador->ouro);
			printf("Pocoes: %1d     [     ]    | ( )\n", jogador->pocoes);
			printf("critico: %2d%%   \\___/     \\ \n", jogador->tx_critico);
		}
	}
	return;
}
