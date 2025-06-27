#include "..\src\Persistencia.h"


void limparTela() {
    // Limpa a tela do console
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

