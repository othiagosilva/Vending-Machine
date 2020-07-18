/*----------------------------------- ATENÇÃO ----------------------------------------
PARA ACESSAR A INTERFACE DE ADM, DIGITE "a/A" QUANDO PERGUNTAR SE DESEJA COMPRAR ALGO.
--------------------------------------------------------------------------------------*/

#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

int quantidade_produto[12] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
float preco[12] = {5, 4.9, 1, 3.5, 3.5, 2.5, 4.5, 1.5, 1.5, 1, 1.5, 3.4};
float troco_disponivel = 100;

void interface_usuario() {

	cout << "                      	      Vending Machine" << endl;
	cout << "                                 Bem-Vindo" << endl;
	cout << "" << endl;
	cout << "--------------------------- Produtos na máquina ---------------------------" << endl;
	cout << "" << endl;
	cout << "  1- Doritos              R$5,00		  " << "7- Cebolitos     R$4,50" << endl;
	cout << "  2- Ruffles              R$4,90		  " << "8- Prestígio     R$1,50" << endl;
	cout << "  3- Barrinha de Cereal   R$1,00                  " << "9- Água Mineral  R$1,50" << endl;
	cout << "  4- Coca-Cola            R$3,50		  " << "10- Amendoim     R$1,00" << endl;
	cout << "  5- Maçã Don             R$3,50		  " << "11- Toddynho     R$1,50" << endl;
	cout << "  6- Gatorade             R$2,50		  " << "12- Fandangos    R$3,40" << endl;
	cout << "" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "" << endl;

}

void interface_adm(float lucro) {
	system ("cls");
	float lucro_individual[12], lucro_possivel;

	for(int i = 0; i < 12; i++) {
		lucro_individual[i] = (quantidade_produto[i] * preco[i]);
	}
	
	for (int i = 0; i <12; i++){
		lucro_possivel += lucro_individual[i];
	}
	
	cout << "                                  Administrador" << endl;
	cout << "                                    Bem-Vindo!" << endl;
	cout << " " << endl;
	cout << "-------------------------------- Itens em estoque ------------------------------- " << endl;
	cout << "" << endl;
	cout << "1- Doritos: 		" << quantidade_produto[0] << "				7- Cebolitos: 		" << quantidade_produto[6] << endl;
	cout << "2- Ruffles: 		" << quantidade_produto[1] << "				8- Prestígio: 		" << quantidade_produto[7] << endl;
	cout << "3- Barrinha de cereal:  " << quantidade_produto[2] << "		   		9- Água Mineral: 	" << quantidade_produto[8] << endl;
	cout << "4- Coca-Cola: 		" << quantidade_produto[3] << "				10- Amendoim: 		" << quantidade_produto[9] << endl;
	cout << "5- Maçã Don: 		" << quantidade_produto[4] << "				11- Toddynho: 		" << quantidade_produto[10] << endl;
	cout << "6- Gatorade: 		" << quantidade_produto[5] << "				12- Fandangos: 		" << quantidade_produto[11] << endl;
	cout << " " << endl;
	cout << "--------------------------------------------------------------------------------- " << endl;
	cout << "" << endl;
	cout << "Lucro até o momento: R$" << lucro << "    Lucro possível: R$" << lucro_possivel << endl; /*Lucro até o momento, e o possível lucro*/
	cout << "Troco disponível: R$" << troco_disponivel << endl;
	cout << "" << endl;
}

void escolhacliente() {

	float valor_inserido;
	float troco = 0;
	int resposta2;

	cout << "Insira o número do produto: ";
	cin >> resposta2;
	cout << " " << endl;

	if (resposta2 < 1 || resposta2 > 12) {
		cout << "Código inválido, digite um número entre 1 e 12.";
		cout << "" << endl;
	}

	int produto = resposta2;

	while (1) {
		if (quantidade_produto[produto - 1] <= 0) {
			cout << "Produto indisponível";
			cout << "" << endl;
			break;
		} else if(quantidade_produto[produto - 1] > 0) {
			cout << "Digite o valor a ser colocado na máquina: ";
			cin >> valor_inserido;
			cout << "" << endl;
			
			troco = valor_inserido - preco[produto - 1];
			
			cout << "Troco de R$" << troco << endl;
			cout << endl;
			quantidade_produto[produto - 1] -= 1;
			break;
		}

		if (valor_inserido < preco[0]) {
			cout << "Valor Insuficiente" << endl;
			break;
		}


		if (troco_disponivel < troco) {
			cout << "Não temos troco, operação cancelada (troco disponível: R$" << troco_disponivel << ")." << endl;
			cout << "Valor de: R$" << valor_inserido << " devolvido." << endl;
			cout << "" << endl;
			break;
		}
	}
}

void escolhaadm() {

	float lucro = 0;
	char resposta3;
	int reestoque;
	int produto;

	interface_adm(lucro);

	while (1) {
		cout << "Gostaria de repor o estoque? (S/N): ";
		cin >> resposta3;

		if (resposta3 == 'n' || resposta3 == 'N') {
			cout << " " << endl;
			cout << "Obrigado!";
			break;
		}
		cout << " " << endl;

		if (resposta3 == 's' || resposta3 == 'S') {
			cout << "Insira o número do item que deseja reestocar: ";
			cin >> produto;
			cout << " " << endl;

			if (produto < 1 || produto > 12) {
				cout << "Não temos mais do que 12 produtos.";
				cout << "" << endl;
				break;
			}

			cout << "Insira a quantidade que foi reestocada: ";
			cin >> reestoque;
			quantidade_produto[produto - 1] += reestoque;
			system("cls");
			interface_adm(lucro);
			break;;
		}
	}
}

int main() {
	
	setlocale (LC_ALL, "Portuguese");
	int continuar;
	char resposta1;

	continuar = 1;

	interface_usuario();

	while (continuar == 1) {

		cout << "Deseja comprar algo? (S/N): ";
		cin >> resposta1;

		system("cls");

		interface_usuario();

		if(resposta1 == 'S' || resposta1 == 's') {
			escolhacliente();
		}

		if(resposta1 == 'N' || resposta1 == 'n') {
			cout << "Obrigado, volte sempre.";
			cout << "" << endl;
			continuar = 0;
		}

		if(resposta1 == 'a' || resposta1 == 'A') {
			escolhaadm();
		}
	}
	return 0;
}