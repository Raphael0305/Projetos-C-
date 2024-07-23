#include <iostream>
#include <locale.h>
#include <string>


using namespace std;
void cadastrarProduto(int &quantCadastrada, double produto[][3], string nomeProduto[]);
void ExibirPordutos (const int quatCadastrada,const double produto[][3], const string nomeProduto[]);
void AtualizarEstoque ( double produto[][3], const int quantCadastrada);
void baixaQuant (const int quantCadastrada, double produto[][3], string nomeProduto[]);
void BuscarCodg (double produto[][3], const int quantCadastrada, string nomeProduto[]);

int main(int argc, char** argv) {
setlocale(LC_ALL, "portuguese");

int quantCadastrada;
double produto[5][3];
string nomeProduto[5];


cout << "Bem vindo ao Projeto Estoque \n";

while(true){
	
system ("cls");
cout << "\n Escolha uma opção\n"; 

int op;
cout << "\n 1 - Cadastrar Produtos\n";
cout << "\n 2 - Exibir Produtos\n";
cout << "\n 3 - Atualizar Estoque\n";
cout << "\n 4 - Produt. Baixa Qunatidade\n";
cout << "\n 5 - Localizar por Código\n";
cout << "\n 6 - Sair do Programa\n";
cin >> op; 

switch (op){
	case 1:
			cadastrarProduto(quantCadastrada,produto,nomeProduto);
		
		break;
	
	case 2:
			ExibirPordutos (quantCadastrada,produto,nomeProduto); // função para exibir os produtos
			system("pause"); // usei para quando o while voltar como verdadeira não ir direto, e dar tempo do usuário verificar 
		break;
	case 3: 
	
			AtualizarEstoque (produto,quantCadastrada);
			system("pause");
		break;
	
	case 4:
			baixaQuant (quantCadastrada,produto,nomeProduto);
			system("pause");
		break;			
	case 5: 
			system("cls");
			BuscarCodg (produto,quantCadastrada,nomeProduto);
			system("pause");
		break;
	case 6:
	
			cout << "voce está saindo do programa";
			system("pause");
			return 0;
	 
		break;
		
	default:
		cout << "Esse código não esta cadastrado";
		break; 	
			
} // Final do Switch
} // final do while
	return 0;
}

bool varificarIgual(int quantCadastrada, double produto[][3], int codigo){

	for(int i = 0; i < quantCadastrada; i ++){
		if(produto[i][0] == codigo){
			return true;
		}
	}
	return false;
}
// Função para Cadastrar os produtos
void cadastrarProduto(int &quantCadastrada, double produto[][3], string nomeProduto[]){ 


	cout << "quantos produtos você vai cadastrar? \n";
	cin >> quantCadastrada;
	
	int codigo;
	
	for (int i = 0; i < quantCadastrada; i ++){
		
		system("cls");
		

 		do{
		 
            cout << "Qual o código do produto? \n";
            cin >> codigo;
            cin.ignore(); // Limpar o buffer de entrada
          if(varificarIgual (quantCadastrada,produto,codigo)){
          	cout << "Esse numero já foi cadastrado\n";
		  }  
		}while(varificarIgual(quantCadastrada,produto,codigo));

		produto[i][0] = codigo;
		
		cout << "Qual o nome do Produto\n ";
		getline(cin, nomeProduto[i]);
		
		cout << "quantidade em estoque \n";
		cin >> produto[i][1];
	
		cout << "Preço do produto \n";
		cin >> produto[i][2];
	}

}
//	Funçção para exibir os produtos
void ExibirPordutos (const int quatCadastrada,const double produto[][3], const string nomeProduto[]){
	
	if(quatCadastrada > 0){
		for (int i = 0; i < quatCadastrada; i ++){ // para varificar todos os cadastrados 
			cout << "\n";
			cout << "Nome Produto: "<< nomeProduto[i];
			cout << "\nCódigo do Produto: " << produto[i][0];
			cout << "\nQuantidade em estoque: " << produto[i][1];
			cout << "\nPreço do produto: " << produto[i][2];
			cout << "\n";
		}
	}else {
		cout << "Não tem nada cadastrado meu chefe!\n";
	}

	
}// final da função Exibir Produtos





void AtualizarEstoque ( double produto[][3], const int quantCadastrada){
	
	int voltar;
	int codigoProduto;
	do{
		
	
	if (quantCadastrada > 0 ){
		cout << "Qual o código do produto que deseja atualizar o estoque ?\n";
		cin >> codigoProduto;
	
	
		for (int i = 0; i < quantCadastrada; i++){
			if(codigoProduto == produto[i][0]){
		
				cout << "Qual é a nova quantidade de produto\n";
				cin >> produto[i][1];
		
			}else {
				cout << "Esse código não esta cadastrado no sistema\n";
				voltar = 2;
			}
		}
	}else {
		cout << " não tem nada cadastrado chefe!\n";
	}
	}while(voltar == 2);
}

void baixaQuant (const int quantCadastrada, double produto[][3], string nomeProduto[]){
	const int baixaQuant = 3;
	
	if (quantCadastrada > 0){
		
		for(int i = 0; i < quantCadastrada; i++){
			if(produto[i][1] <= baixaQuant){
		
				cout << "\n";
				cout << "\n";
				cout << "Nome Produto: " << nomeProduto[i];
				cout << "\nCódigo do Produto: " << produto[i][0];
				cout << "\nQuantidade em estoque: " << produto[i][1];
				cout << "\nPreço do produto: " << produto[i][2];
				cout << "\n";
				cout << "\n";
			}else {
			cout << "não tem produto em baixa quantidade!\n";
			}
		}//Fim do for 	
	}else {
		cout << "Não tem produtos cadastrados chefe \n";
		cout << "\n";
	}	
}

void BuscarCodg (double produto[][3], const int quantCadastrada, string nomeProduto[]){

	int codg;
	
	if(quantCadastrada > 0 ){
		
		cout << "Qual o Código do produto que deseja localizar?\n";
		cin >> codg;
		
		for (int i = 0; i < quantCadastrada; i ++){
			if(codg == produto[i][0]){
				
				cout << "\nNome Produto: " << nomeProduto[i];
				cout << "\nCódigo do Produto: " << produto[i][0];
				cout << "\nQuantidade em estoque: " << produto[i][1];
				cout << "\nPreço do produto: " << produto[i][2];
				cout << "\n";
				cout << "\n";
			}else {
				cout << "Esse código não esta cadastrado!\n";
				cout << "\n";
				cout << "\n";
			}
		}// for
	}else {
		cout << "não tem nada cadastrado no sistema!\n";
		cout << "\n";
			cout << "\n";
	}
	
	
	
}

