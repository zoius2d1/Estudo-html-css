#include <iostream>
#include <fstream>

using namespace std;

struct ende {
  string rua;
  string numero;
  string cep;
};

struct contato {
  string id;
  string nome;
  string cidade;
  ende endereco;
  string email;
  string telefone;
};

void mostrar(contato p) {
  cout << "Dados do contato " << endl;
  cout << "ID do contato: " << p.id << endl;
  cout << "Nome: " << p.nome << endl;
  cout << "Cidade: " << p.cidade << endl;
  cout << "Endereço: ";
  cout << p.endereco.rua << " " << p.endereco.rua << " " << p.endereco.cep << endl;
  cout << "Email: " << p.email << endl;
  cout << "Telefone: " << p.telefone << endl;
}

void ler(contato *p) {
  cout << "Digite o ID: ";
  cin >> p->id;
  cout << "Digite o nome: ";
  cin.ignore();
  getline(cin, p->nome);
  cout << "Digite a cidade: ";
  getline(cin, p->cidade);
  cout << "Digite o endereço separando rua, numero e CEP por espacos: ";
  cin >> p->endereco.rua;
  cin >> p->endereco.numero;
  cin >> p->endereco.cep;
  cout << "Digite o email: ";
  cin.ignore();
  getline(cin, p->email);
  cout << "Digite o telefone: ";
  cin >> p->telefone;

}

int main() {
  int *agenda[20];
  contato meuContato;
  int opcao;
  fstream meuArquivo;
  string texto1,texto2,texto3,texto4,texto5,texto6,texto7,texto8;


  while (1) {
    cout << "------- MENU -------\n";
    cout << "1 - para cadastrar um contato.\n";
    cout << "2 - para mostrar contatos cadastrados.\n";
    cout << "3 - para salvar o contato.\n";
    cout << "4 - para carregar os contatos.\n";
    cout << "5 - para sair.\n";
    cout << "Digite sua opcao: ";
    cin >> opcao;

    if (opcao == 5)
      break;

    switch (opcao) {
    case 1:
      ler(&meuContato);
      break;
    case 2:
      mostrar(meuContato);
      break;
    case 3:
     meuArquivo.open("cadastro.txt",ios::out);
    if(meuArquivo.is_open()) {
        meuArquivo << meuContato.id << "\n";
        meuArquivo << meuContato.nome << "\n";
        meuArquivo << meuContato.cidade << "\n";
        meuArquivo << meuContato.endereco.rua << "\n";
        meuArquivo << meuContato.endereco.numero << "\n";
        meuArquivo << meuContato.endereco.cep << "\n";
        meuArquivo << meuContato.email<< "\n";
        meuArquivo << meuContato.telefone << "\n";
        meuArquivo.close();
    }
    break;
    case 4:
    meuArquivo.open("cadastro.txt",ios::in);//leitura
    if(meuArquivo.is_open()) {
        getline(meuArquivo,texto1);
        meuContato.id = texto1;
        getline(meuArquivo,texto2);
        meuContato.nome= texto2;
        getline(meuArquivo,texto3);
        meuContato.cidade= texto3;
        getline(meuArquivo,texto4);
        meuContato.endereco.rua= texto4;
        getline(meuArquivo,texto5);
        meuContato.endereco.numero= texto5;
        getline(meuArquivo,texto6);
        meuContato.endereco.cep= texto6;
        getline(meuArquivo,texto7);
        meuContato.email= texto7;
        getline(meuArquivo,texto8);
        meuContato.telefone= texto8;
        meuArquivo.close();
    }
    break;
    default:
      cout << "Opcao invalida. Digite novamente.\n";
      break;
    }
  }

  return 0;
}

