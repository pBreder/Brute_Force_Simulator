#include <iostream>
#include <string>
#include <chrono> // Biblioteca para medir intervalos de tempo

using namespace std; // Uso do namespace para simplificar a escrita, visto que é um codigo para aprendizado
using namespace chrono;

void forcaBruta(string tentativaAtual, int tamanho, string charset, int& tentativas, string senha, bool& encontrada){

    if (encontrada){

        return;
    }
        
    if(tentativaAtual.length() == tamanho){

        tentativas++;
        
        if(tentativaAtual == senha){

            cout << "\nSenha encontrada: " << tentativaAtual << endl;
            cout << "Tentativas: " << tentativas << endl;
            encontrada = true;
        }
    }
    else{

        for(char caractere : charset){

            forcaBruta(tentativaAtual + caractere, tamanho, charset, tentativas, senha, encontrada); // Uso de recursão (Não é a melhor escolha, mas no momento sera essa a escolhida)
        }
    }
}

int main(){

    string senha;
    string chars;
    int tentativas = 0; // Contador para as tentativas até encontrar a senha
    int opcao;
    bool encontrada = false;

    do{

        cout << "Digite sua senha:\n";
        getline(cin, senha);
    }
    while(senha == "");    // Evitar senhas vazias

    // Menu 
    cout << "|---------- Menu Simulador ----------|" << endl;
    cout << "1. Apenas letras minusculas." << endl;
    cout << "2. Todas as letras." << endl;
    cout << "3. Apenas números." << endl;
    cout << "4. Letras e números." << endl;
    cout << "5. Letras, numeros e simbolos." << endl;
    cout << "Escolha uma das opcoes: " << endl;
    cin >> opcao;

    switch (opcao) {
        case 1:
            chars = "abcdefghijklmnopqrstuvwxyz";
            break;
        case 2:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 3:
            chars = "0123456789";
            break;
        case 4:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            break;
        case 5:
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%&*()_-+=\\'";
            break;
        default: // Qualquer numero que nao esteja no conjunto de numeros definidos
            cout << "Opção inválida. Encerrando o programa." << endl;
            return 1;
    }

    auto inicio = high_resolution_clock::now(); // Uso do chrono para cronometrar

    for(int i = 1; i <= 24; i++){

        if (encontrada){

            break;
        }
        
        else{
            
            cout << "Testando senha com " << i << " caracteres" << endl;
            forcaBruta("", i, chars, tentativas, senha, encontrada);
        }
    }

    if(!encontrada){ // Devido ás condções limitantes do codigo, podem haver casos onde a senha nao é encontrada

        cout << "Senha não foi encontrada. Teste com um charset diferente ou aumente a quantidade de caracteres.";
    }

    auto fim = high_resolution_clock::now(); // Marca o momento em que foi encontrado a senha
    auto intervalo = duration_cast<milliseconds>(fim - inicio); // Faz o calculo do intervalo

    cout << "Intervalo de tempo: " << intervalo.count() << "ms" << endl;

    return 0;
}

