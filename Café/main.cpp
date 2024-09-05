#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct pagante{
	int mes;
	int ano;
	float contr;
};
struct pessoa{
	int id;
	string nome;
	int semestre;
	int anoIngress;
	string curso;
	vector<pagante> contrib;	
};
//fun��es do menu
void menu (); //menu
void addParcipante (vector<pessoa>& turma,string& nomeArquivo);// adicionar participante
void editarDados(vector<pessoa>& turma, string& nomeArquivo); // editar dados dos participantes
void mostrarParticipantes(const vector<pessoa>& turma); // Para mostrar participantes
void MenssagemExcluir (vector<pessoa>& turma, string& nomeArquivo); // Excluir um participante
void novaContribu (vector<pessoa>& turma, string &novoArquivo);
void relatorio(vector<pessoa>& turma, string& nomeArquivo);
///FIM FUN��O MENU

//fun��o para arquivos
void salvar(const pessoa& particip, string& nomeArquivo); // Salva arquivos .app
void salvarEditado(const vector<pessoa>& turma, string& nomeArquivo); // salva arquivos .out
void salvarContribuicao (const pagante& contri, string& nomeArquivo,vector<pessoa>& turma);
// FIM FUN��O ARQUIVOS
int main(int argc, char** argv) {
	setlocale(LC_ALL, "portuguese");
	int op, vezesContrib;
	int idRemover;
	vector<pessoa> turma;
	string nomeArquivo = "participantes.txt";	
	string contrArquivo = "contribuintes.txt", DSM = "contribuintes_DSM.txt", SI = "contribuintes_SI.txt", GE = "contribuintes_GE.txt";  ;
	
	while(true){
		
		system("cls");
		menu ();
		cin >> op;
		
		switch(op){
			case 1:
				
				system("cls");
				addParcipante (turma,nomeArquivo);
				system("pause");
				break;
			case 2:
				system("cls");
				editarDados(turma, nomeArquivo);
				system("pause");
				break;
			case 3:
				system("cls");
				mostrarParticipantes(turma);
				system("pause");
				break;
			case 4:
				system("cls");
				MenssagemExcluir(turma, nomeArquivo);
				system("pause");
				break;
			case 5:
				system("cls");
				novaContribu (turma,contrArquivo);
				system("pause");
				break;
			case 6:
				system("cls");
				relatorio(turma,DSM);
				system("pause");
				break;
			case 7:
				return 0;
				break;
			default:
				cout <<"N�o existe essa op��o\n";
				break;
		}
	}
	

	

	return 0;
}

void menu (){
	cout << "       +--------------+\n";
	cout << "       |Turma do Caf� |\n";
	cout << "       +--------------+\n";
	cout << "\n";
	
	cout << "+---------------------------------+\n";
	cout << "| 1 - Adicionar Participantes     |\n";
	cout << "| 2 - Editar dados de particpante |\n";
	cout << "| 3 - Ver participantes           |\n";
	cout << "| 4 - Remover participante        |\n";
	cout << "| 5 - Cadastrar Contribui��o      |\n";
	cout << "| 6 - Gerar Relat�rio             |\n";
	cout << "| 7 - Sair                        |\n";
	cout << "+---------------------------------+\n";
	cout << "Escolha uma op��o\n";
}


void addParcipante (vector<pessoa>& turma,string& nomeArquivo){
	bool verificando = true; // 
	pessoa oi; // adicionando uma variavel tipo pessoa
	
	while(verificando){
		system("cls");
		cout << "ID do participante\n";
		cin >> oi.id;
		
		verificando = false; // atribuindo false para o programa n�o entrar em loop
		
		for(auto& verif : turma){
			if(oi.id == verif.id){
				cout << "Esse id ja foi alocado\n";
				system("pause");
				verificando = true;//somente se o entrar nesse if vai repetir o loop
			}
		}
	}
	
	cout << "Nome do participante \n";
	cin >> oi.nome;
	
	cout << "Semestre \n";
	cin >> oi.semestre;
	
	cout << "Ano de infresso na FATEC\n";
	cin >> oi.anoIngress;
	
	cout << "\nQual curso esta fazendo ? \n";
	cout << "1 - DMS\n";
	cout << "2 - SI \n";
	cout << "3 - GE \n";
	int curso;
	cout << "Escolha um op��o (1,2,3)\n";
	cin >> curso;
	
	if(curso == 1){
		oi.curso = "Desenvolvimento de Software";
	}else if( curso == 2){
		oi.curso = "SI";
	}else if(curso == 3){
		oi.curso = "GE";
	}
	
	turma.push_back(oi); // adicionando dados que foram alocados em oi para o fim do vector;
	
	salvar(oi,nomeArquivo);
	
	cout << "\nParticipante cadastrado\n";
	cout << "\n";
	
}

void mostrarParticipantes(const vector<pessoa>& turma){
	cout << "+-------------------------------+\n";
	cout << "|PARTICIPANTES DO GRUPOR DO CAF�|\n";
	cout << "+-------------------------------+\n";
	
	if(turma.empty()){
		cout << "\n";
		cout << "N�o tem pessoas no grupo do caf� ainda ;-; \n";
		cout << "\n";
	}
	
	for(auto& partic : turma){
		cout << "=============================================\n";
		cout << "ID: " << partic.id << "\n";
		cout << "Nome: " << partic.nome << "\n";
		cout << "Semestre: " << partic.semestre << "� Semestre \n";
		cout << "Ano de ingresso na FATEC: " << partic.anoIngress << "\n";
		cout << "Curso : " << partic.curso << "\n";
		cout << "=============================================\n";
	}
}

void editarDados(vector<pessoa>& turma, string& nomeArquivo){
	int ope;
	cout << "  +----------------+\n";
	cout << "  | EDITANDO DADOS |\n";
	cout << "  +----------------+\n";
	
	if(turma.empty()){
		cout << "\nN�o foi adicionado particiapando na Turma do caf�\n";
		cout << "\n";
		return;
	}	
	
	int novoID;
	
	cout << "Qual o ID do participante?\n";
	cin >> novoID;
	
	for(auto& verif : turma){
		if(novoID == verif.id){
			
			cout << "1 - Mudar nome\n";
			cout << "2 - Mudar Semestre\n";
			cout << "3 - Mudar Ano Ingressado\n";
			cout << "4 - Mudar Curso\n";
			cout << "escolha uma op��o\n";
			cin >> ope;
		
			switch(ope){
				case 1:
					cout << "Nome\n";
					cin >> verif.nome;
					salvarEditado(turma,nomeArquivo);
					break;
				case 2:
					cout << "Semestre\n";
					cin >> verif.semestre;
					salvarEditado(turma,nomeArquivo);
					break;
				case 3:
					cout << "Ano ingressado\n";
					cin >> verif.anoIngress;
					salvarEditado(turma,nomeArquivo);
					break;
				case 4:
					cout << "Qual curso esta fazendo ? \n";
					cout << "1 - DMS\n";
					cout << "2 - SI \n";
					cout << "3 - GE \n";
					int curso;
					cout << "Escolha um op��o (1,2,3)\n";
					cin >> curso;
	
					if(curso == 1){
						verif.curso = "Desenvolvimento de Software\n";
					}else if( curso == 2){
						verif.curso = "SI \n";
					}else if(curso == 3){
						verif.curso = "GE\n";
					}else if(curso <=0 ||curso >=4){
						cout << "Essa op��o n�o existe\n";
					}
					salvarEditado(turma,nomeArquivo);
					cout << "Mudan�� feita com sucesso!\n";
					break;
				default:
					cout << "N�o ta podendo essa op��o\n";
					break;
			}
		}else {
			cout << "Esse n�o existe\n";
		}
	}
}

void MenssagemExcluir (vector<pessoa>& turma, string& nomeArquivo){
	
	char escolha;
	int idRemover;
	
	cout << "+-------------------------+\n";
	cout << "| REMOVENDO PARTICIPANTE  |\n";
	cout << "+-------------------------+\n";
	
	cout << "Qual o ID do participante que deseja remover?\n";
	cin >> idRemover;
	
	for(auto& remov : turma){
		if (idRemover == remov.id){
			cout << "Deseja mesmo excluir " << remov.nome << "?\n(S/N)";
			cin >> escolha;
			
			if(escolha == 's' || escolha == 'S'){
				auto lixeira = remove_if(turma.begin(), turma.end(), [&idRemover](pessoa p){
					return p.id == idRemover;
				});
				turma.erase(lixeira, turma.end());
				salvarEditado(turma,nomeArquivo);
				cout << "Removido com sucesso!\n";
				return;
			}else {
				cout << "A��o canceladas \n";
				return;
			}
		}
	}
	
	cout << "ID n�o encontrado\n";
}

void novaContribu (vector<pessoa>& turma, string &nomeArquivo){
	
	int idContr;
	bool erroMes = true;
	cout << "+-----------------+\n";
	cout << "|   CONTRIBUITES  |\n";
	cout << "+-----------------+\n";
	

	cout << "Qual o ID do contribuinte?\n";
	cin >> idContr;
		
	for(auto& contr : turma){
		if(idContr == contr.id){
			pagante pega;
			
			cout << "ID: " << contr.id << "  Nome: " << contr.nome;
			cout << "\n";
			//controle de mes
			while(erroMes){
				erroMes = false;
				
				cout << "M�s da contribui��o(n�mero inteiro entre 1 e 12)\n";
				cin >> pega.mes;
				if(pega.mes <= 0 || pega.mes > 12){
					cout << "Esse valores n�o s�o validos\n";
					system("pause");
					erroMes = true;
				}
			}//fim while controle mes	
			
			erroMes = true;
			
			while(erroMes){//while de verifica��o
				erroMes = false;
				
				cout << "Ano \n";
				cin >> pega.ano;
				
				if(pega.ano < 2024){
					cout << "Tem que ser maior ou igual a 2024\n";
					system("pause");
					erroMes = true;
				}
			} //fim while verifica��o
			
			cout << "Valor da contribui��o\n";
			cin >> pega.contr;
			
			
			contr.contrib.push_back(pega);
			salvarContribuicao (pega,nomeArquivo,turma);
			cout << "Contribui��o salva\n";
		}
	}
	
	
}

void relatorio(vector<pessoa>& turma, string& nomeArquivo){
	int op;
	
	cout << "+--------------+\n";
	cout << "|   RELAT�RIO  |\n";
	cout << "+--------------+\n";
	
	cout << "1 - Contribui��o DSM \n";
	cout << "2 - Contribui��o SI \n";
	cout << "3 - Contribui��o GE \n";
	cout << "De qual vai ser gerado relat�rio\n";
	cin >> op;
	
	switch(op){
		case 1:
			cout << "Relat�rio Desenvolvimento de Software \n";
			cout << "\n";
			for(auto& relat : turma){
				if(relat.curso == "Desenvolvimento de Software"){
					if(relat.contrib.empty()){
						cout << "Esta vazio";
					}else{
						float totalContribui = 0;
						cout << "==============================================\n";
						cout << "Nome: " << relat.nome << "\n";
						for(auto pagant : relat.contrib){
							totalContribui += pagant.contr;
						}
						cout << "total contribuido: " << totalContribui << "\n";
						cout << "==============================================\n";
						
						ofstream arquivo(nomeArquivo , ios::out);
						
						if(arquivo.is_open()){
							arquivo << "==========================================\n";
							arquivo << "nome " << relat.nome << "\n";
							arquivo << "total contribuido: " << totalContribui << "\n";
							arquivo << "==========================================\n";
							arquivo.close();
						}
					}
				}
			}
			break;
		case 2:
			cout << "Relat�rio SI\n";
			cout << "\n";
			for (auto& relat : turma){
				if(relat.curso == "SI"){
					if(relat.contrib.empty()){
						cout << "Esta vazio\n";
					}else{
						float totalContribui = 0;
						cout << "=============================================\n";
						cout << "Nome: " << relat.nome << "\n";
						for(auto pagant : relat.contrib){
							totalContribui += pagant.contr;
						}
						cout << "total contribuido: " << totalContribui << "\n";
						cout << "=============================================\n";
					}
				}
			}
			break;
		case 3:
			break;
		default:
			cout << "N�o tem essa op��o dog\n";
			break;
	}
}

void salvar(const pessoa& particip, string& nomeArquivo){
	
	ofstream arquivo(nomeArquivo, ios::app);
	
	if(arquivo.is_open()){
		arquivo << "=============================\n";
		arquivo << "ID: " << particip.id << "\n";;
		arquivo << "Nome: " << particip.nome << "\n";;
		arquivo << "Nome: " << particip.semestre << "\n";;
		arquivo << "Ano de ingresso: " << particip.anoIngress << "\n";
		arquivo << "Curso: " << particip.curso << "\n";
		arquivo << "=============================\n";
		arquivo.close();
		}else {
		cout << "N�o foi possivel abrir o arquivo." << endl;
	}
	
}

void salvarContribuicao (const pagante& contri, string& nomeArquivo,vector<pessoa>& turma){
	
	ofstream arquivo(nomeArquivo, ios::app);
	
	if(arquivo.is_open()){
		for(auto& teste : turma){
			arquivo << "==============================\n";
			arquivo << "Nome: " << teste.nome << "\n";
			arquivo << "Data:  M�s " << contri.mes << "/" << contri.ano << "\n";;
			arquivo << "Valor: " << contri.contr << "\n";
			arquivo << "==============================\n";
			arquivo.close();
		}
	}
	
}

void salvarEditado(const vector<pessoa>& turma, string& nomeArquivo){
	
	ofstream arquivo(nomeArquivo);
	
	if(arquivo.is_open()){
		for(const auto& aluno : turma){
			arquivo << "=============================\n";
			arquivo << "ID: " << aluno.id << "\n";;
			arquivo << "Nome: " << aluno.nome << "\n";;
			arquivo << "Nome: " << aluno.semestre << "\n";;
			arquivo << "Ano de ingresso: " << aluno.anoIngress << "\n";
			arquivo << "Curso: " << aluno.curso << "\n";
			arquivo << "=============================\n";
			
		}
	}
}
