#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <conio.h>

using namespace std;
void verificaJogo(); // DECIDE QUEM GANHOU A RODADA
void escolhaCarta(); // DECIDE QUAL CARTA O JOGADOR IRÁ UTILIZAR NA RODADA
void jogadaPC(); // SELECIONA CARTAS PARA O JOGADOR
void jogadaJogador(); // SELECIONA CARTAS PARA O PC
void exibeCartasJogador(); // MOSTRA AS CARTAS QUE O JOGADOR IRÁ UTILIZAR
void decidiGanhador(int a, int b);  // DECIDE QUEM GANHOU O JOGO

string cartasPC[3];
string cartasJogador[3];
int pontosPC = 0; 
int pontosJogador = 0;
int controlador = 0; // Controla a quantidade de jogadas por partida.
int carta; // Carta do jogador.
int posicao; // Posicao da carta selecionada pelo jogador.
int checked1 = 0;//
int checked2 = 0;//
int checked3 = 0;//Verifica se o jogador já escolheu uma determinada carta.

int main()
{
	srand((int)time(NULL));
	jogadaPC();
	jogadaJogador();
	exibeCartasJogador();
	escolhaCarta();
	decidiGanhador(pontosJogador, pontosPC);
	
	system("pause");
	return 0;
}
void decidiGanhador(int pontosJogador, int pontosPC)
{
	if (pontosJogador > pontosPC)
	{
		system("color 20");
		cout << "\n|||| VOCE VENCEU! PARABENS! ||||" << endl;
	}
	else if (pontosJogador == pontosPC)
	{
		system("color 0f");
		cout << "\n|||| EMPATE. JOGUE OUTRA VEZ! ||||" << endl;
	}
	else
	{
		system("color 40");
		cout << "\n|||| PC ganhou! BOA TENTATIVA HAHA! ||||" << endl;
	}
}
void verificaJogo()
{
		if (checked1 == 1 || checked2 == 1 || checked3 == 1) // Se alguma posição de carta foi selecionada apenas uma vez
		{
			if (cartasPC[posicao - 1] > cartasJogador[posicao - 1])
			{
				pontosPC++;
				cout << "\n\t\t\t| PC ganhou |" << endl;
			}
			else if (cartasPC[posicao - 1] == cartasJogador[posicao - 1])
			{
				cout << "\n\t\t\t  | Empate |" << endl;
			}
			else
			{
				pontosJogador++;
				cout << "\n\t\t\t| Voce ganhou |" << endl;				
			}
		}
		else
		{
			cout << "Essa posicao de carta ja foi escolhida! Selecione outra!\n";
			controlador--;
		}
	escolhaCarta();
}
void escolhaCarta()
{
	if (controlador == 3)
	{
		system("pause");
		return;
	}

		cout << "\tEscolha a posicao da carta que voce quer jogar!\n\t\t\t      -> ";
		cin >> posicao;
		switch (posicao)
		{
		case 1:
			cout << "\t\t\t   _________" << endl;
			cout << "\t\t\t     " << cartasJogador[0] << " X " + cartasPC[0] << endl;
			cout << "\t\t\t   _________" << endl;
			checked1++;
			controlador++;
			verificaJogo();
			break;
		case 2:
			cout << "\t\t\t   _________" << endl;
			cout << "\t\t\t     " << cartasJogador[1] << " X " + cartasPC[1] << endl;
			cout << "\t\t\t   _________" << endl;
			controlador++;
			checked2++;
			verificaJogo();
			break;
		case 3:
			cout << "\t\t\t   _________"<<endl;
			cout <<"\t\t\t     "<< cartasJogador[2] << " X " + cartasPC[2] <<endl ;
			cout << "\t\t\t   _________" << endl;
			controlador++;
			checked3++;
			verificaJogo();
			break;
		default:
			cout << "Posicao de carta nao existente!" << endl;
			escolhaCarta();
			break;
	}
}
void jogadaPC()
{
	for (int i = 0; i < 3; i++)
	{
		carta = 1 + (rand() % 13);
		if (carta == 1)
			cartasPC[i] = "A";
		else if (carta == 11)
			cartasPC[i] = "Q";
		else if (carta == 12)
			cartasPC[i] = "J";
		else if (carta == 13)
			cartasPC[i] = "K";
		else
			cartasPC[i] = to_string(carta);
	}
}
void jogadaJogador()
{
	for (int i = 0; i < 3; i++)
	{
		carta = 1 + (rand() % 13);
		if (carta == 1)
			cartasJogador[i] = "A";
		else if (carta == 11)
			cartasJogador[i] = "Q";
		else if (carta == 12)
			cartasJogador[i] = "J";
		else if (carta == 13)
			cartasJogador[i] = "K";
		else
			cartasJogador[i] = to_string(carta);
	}
}
void exibeCartasJogador()
{
	/*EXIBE AS CARTAS DO JOGADOR*/
	cout << "\n";
	for (int i = 0; i < 3; i++)
		cout << "\t\t" << cartasJogador[i];
	cout << "\n\n";
}