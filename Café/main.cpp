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
//funçôes do menu
void menu (); //menu
void addParcipante (vector<pessoa>& turma,string& nomeArquivo);// adicionar participante
void editarDados(vector<pessoa>& turma, string& nomeArquivo); // editar dados dos participantes
void mostrarParticipantes(const vector<pessoa>& turma); // Para mostrar participantes
void MenssagemExcluir (vector<pessoa>& turma, string& nomeArquivo); // Excluir um participante
void novaContribu (vector<pessoa>& turma, string &novoArquivo);
void relatorio(vector<pessoa>& turma, string& nomeArquivo);
///FIM FUNÇÃO MENU

//função para arquivos
void salvar(const pessoa& particip, string& nomeArquivo); // Salva arquivos .app
void salvarEditado(const vector<pessoa>& turma, string& nomeArquivo); // salva arquivos .out
void salvarContribuicao (const pagante& contri, string& nomeArquivo,vector<pessoa>& turma);
// FIM FUNÇÃO ARQUIVOS
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
				cout <<"Não existe essa opção\n";
				break;
		}
	}
	

	

	return 0;
}

void menu (){
	cout << "       +--------------+\n";
	cout << "       |Turma do Café |\n";
	cout << "       +--------------+\n";
	cout << "\n";
	
	cout << "+---------------------------------+\n";
	cout << "| 1 - Adicionar Participantes     |\n";
	cout << "| 2 - Editar dados de particpante |\n";
	cout << "| 3 - Ver participantes           |\n";
	cout << "| 4 - Remover participante        |\n";
	cout << "| 5 - Cadastrar Contribuição      |\n";
	cout << "| 6 - Gerar Relatório             |\n";
	cout << "| 7 - Sair                        |\n";
	cout << "+---------------------------------+\n";
	cout << "Escolha uma opção\n";
}


void addParcipante (vector<pessoa>& turma,string& nomeArquivo){
	bool verificando = true; // 
	pessoa oi; // adicionando uma variavel tipo pessoa
	
	while(verificando){
		system("cls");
		cout << "ID do participante\n";
		cin >> oi.id;
		
		verificando = false; // atribuindo false para o programa não entrar em loop
		
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
	cout << "Escolha um opção (1,2,3)\n";
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
	cout << "|PARTICIPANTES DO GRUPOR DO CAFÉ|\n";
	cout << "+-------------------------------+\n";
	
	if(turma.empty()){
		cout << "\n";
		cout << "Não tem pessoas no grupo do café ainda ;-; \n";
		cout << "\n";
	}
	
	for(auto& partic : turma){
		cout << "=============================================\n";
		cout << "ID: " << partic.id << "\n";
		cout << "Nome: " << partic.nome << "\n";
		cout << "Semestre: " << partic.semestre << "° Semestre \n";
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
		cout << "\nNão foi adicionado particiapando na Turma do café\n";
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
			cout << "escolha uma opção\n";
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
					cout << "Escolha um opção (1,2,3)\n";
					cin >> curso;
	
					if(curso == 1){
						verif.curso = "Desenvolvimento de Software\n";
					}else if( curso == 2){
						verif.curso = "SI \n";
					}else if(curso == 3){
						verif.curso = "GE\n";
					}else if(curso <=0 ||curso >=4){
						cout << "Essa opção não existe\n";
					}
					salvarEditado(turma,nomeArquivo);
					cout << "Mudançã feita com sucesso!\n";
					break;
				default:
					cout << "Não ta podendo essa opção\n";
					break;
			}
		}else {
			cout << "Esse não existe\n";
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
				cout << "Ação canceladas \n";
				return;
			}
		}
	}
	
	cout << "ID não encontrado\n";
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
				
				cout << "Mês da contribuição(número inteiro entre 1 e 12)\n";
				cin >> pega.mes;
				if(pega.mes <= 0 || pega.mes > 12){
					cout << "Esse valores não são validos\n";
					system("pause");
					erroMes = true;
				}
			}//fim while controle mes	
			
			erroMes = true;
			
			while(erroMes){//while de verificação
				erroMes = false;
				
				cout << "Ano \n";
				cin >> pega.ano;
				
				if(pega.ano < 2024){
					cout << "Tem que ser maior ou igual a 2024\n";
					system("pause");
					erroMes = true;
				}
			} //fim while verificação
			
			cout << "Valor da contribuição\n";
			cin >> pega.contr;
			
			
			contr.contrib.push_back(pega);
			salvarContribuicao (pega,nomeArquivo,turma);
			cout << "Contribuição salva\n";
		}
	}
	
	
}

void relatorio(vector<pessoa>& turma, string& nomeArquivo){
	int op;
	
	cout << "+--------------+\n";
	cout << "|   RELATÓRIO  |\n";
	cout << "+--------------+\n";
	
	cout << "1 - Contribuição DSM \n";
	cout << "2 - Contribuição SI \n";
	cout << "3 - Contribuição GE \n";
	cout << "De qual vai ser gerado relatório\n";
	cin >> op;
	
	switch(op){
		case 1:
			cout << "Relatório Desenvolvimento de Software \n";
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
			cout << "Relatório SI\n";
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
			cout << "Não tem essa opção dog\n";
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
		cout << "Não foi possivel abrir o arquivo." << endl;
	}
	
}

void salvarContribuicao (const pagante& contri, string& nomeArquivo,vector<pessoa>& turma){
	
	ofstream arquivo(nomeArquivo, ios::app);
	
	if(arquivo.is_open()){
		for(auto& teste : turma){
			arquivo << "==============================\n";
			arquivo << "Nome: " << teste.nome << "\n";
			arquivo << "Data:  Mês " << contri.mes << "/" << contri.ano << "\n";;
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
