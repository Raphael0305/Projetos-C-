#include <iostream>
#include <locale.h>

using namespace std;

// Global auxiliar
struct gerenciaPastel {
    string tipo[9]; // Alterado para string �nica por pastel
};

struct listaPedido {
    int senha;
    string status;
    gerenciaPastel pastel; // Alterado para permitir at� 9 past�is
};

// Auxiliares
void limparTela();
void pausarPrograma();

// Fun��es principais
void menu();
void cadastrarPedido(listaPedido& pedido);
void mostrarPedido(listaPedido& pedido);

int main(int argc, char** argv) {
    setlocale(LC_ALL, "portuguese");
    int escolha;

    listaPedido pedido;

    while (true) {
        limparTela();
        menu();
        cin >> escolha;

        switch (escolha) {
            case 1:
                cadastrarPedido(pedido);
                pausarPrograma();
                break;
            case 2:
                // Implementar a fun��o de editar pedido aqui
                pausarPrograma();
                break;
        	case 3:
        		mostrarPedido(pedido);
        		pausarPrograma();
        		break;
        		
            default:
                cout << "Essa op��o n�o existe\n";
                pausarPrograma();
                break;
        }
    }


    return 0;
}

void menu() {
    cout << "+-----------------------+\n";
    cout << "| 1 - Cadastrar Pedido  |\n";
    cout << "| 2 - Editar Pedido     |\n";
    cout << "| 3 - Mostrar Pedidos   |\n";
    cout << "+-----------------------+\n";
    cout << "Escolha uma op��o\n";
}

void cadastrarPedido(listaPedido& pedido) {
    bool voltar = false;
    int quantidade;
    int escolha;

    cout << "+-----------------------+\n";
    cout << "|  Cadastro de Pedido   |\n";
    cout << "+-----------------------+\n";
    cout << "\n";

    do {
        cout << "Digite a senha do pedido (maior que 0): ";
        cin >> pedido.senha;
        if (pedido.senha <= 0) {
            cout << "Escolha um valor maior que 0\n";
            voltar = true;
        } else {
            voltar = false;
        }
    } while (voltar);

    cout << "Quantos past�is? ";
    cin >> quantidade;

    // Verifique se a quantidade n�o excede o limite
    if (quantidade > 9) {
        cout << "O n�mero m�ximo de past�is � 9. Ajustando quantidade para 9.\n";
        quantidade = 9;
    }

    
        cout << "\nQual o sabor do pastel?\n";
        cout << "+------------+\n";
        cout << "| 1 - Pizza  |\n";
        cout << "| 2 - Queijo |\n";
        cout << "| 3 - Frango |\n";
        cout << "| 4 - Vento  |\n";
        cout << "+------------+\n";
        cin >> escolha;
	for (int i = 0; i < quantidade; i++) {
        switch (escolha) {
            case 1:
                pedido.pastel.tipo[i] = "Pizza";
                break;
            case 2:
                pedido.pastel.tipo[i] = "Queijo";
                break;
            case 3:
                pedido.pastel.tipo[i] = "Frango";
                break;
            case 4:
                pedido.pastel.tipo[i] = "Vento";
                break;
            default:
                cout << "Op��o inv�lida. Escolhendo 'Vento' como padr�o.\n";
                break;
        }
    }
}


void mostrarPedido(listaPedido& pedido){
	for(int i = 0; i < 3; i++){
		cout << "peidido\n";
		cout << "\n";
		
		cout << "Senha: " << pedido.senha << "\n";
		for(int j = 0; j < 3; j++){
			cout << "Sabores: " << pedido.pastel.tipo[j] << "\n";	
		} 
		cout << "---------------------------------------------------------------\n";
	}
}

// Auxiliares para apagar a tela e pausar
void limparTela() {
    #ifdef _WIN32
        system("cls"); // Comando para Windows
    #else
        system("clear"); // Comando para Linux/Unix
    #endif
}

void pausarPrograma() {
    #ifdef _WIN32
        system("pause"); // Comando para Windows
    #else
        cout << "Pressione Enter para continuar...";
        cin.ignore();
        cin.get(); // Comando para Linux/Unix
    #endif
}

