#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

string SENHA;
string CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%¨&*()_-+=\\\'\"";
bool encontrada = false;

void teste(string provisoria, int tamanho, int& tentativas){

    if (encontrada){

        return;
    }
        
    if(provisoria.length() == tamanho){

        cout << "Combinação: " << provisoria << endl;
        tentativas++;
        
        if(provisoria == SENHA){

            cout << "\nSenha encontrada: " << provisoria << endl;
            cout << "Tentativas: " << tentativas << endl;
            encontrada = true;
        }
    }
    else{

        for(char c : CHARS){

            teste(provisoria + c, tamanho, tentativas);
        }
    }
}

int main() {

    int chances = 0;

    cout << "Digite sua senha:\n";
    getline(cin, SENHA);

    auto inicio = high_resolution_clock::now();

    for(int i = 1; i < 101; i++){

        if (encontrada){

            break;
        }
        
        else{
            
            teste("", i, chances);
        }
    }

    auto fim = high_resolution_clock::now();
    auto intervalo = duration_cast<milliseconds>(fim - inicio);

    cout << "Intervalo de tempo: " << intervalo.count() << "ms" << endl;

    return 0;
}