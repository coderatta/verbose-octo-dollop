#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;
vector<string> palavras;

bool letra_existe(char chute)
{
    for (char letra : palavra_secreta)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

bool acertou()
{
    for (char letra : palavra_secreta)
    {
        if (!chutou[letra])
        {
            return false;
        }
    }
    return true;
}

bool enforcou()
{
    return chutes_errados.size() > 4;
}

void imprime_cabecalho()
{
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprime_erros()
{
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra()
{
    for (char letra : palavra_secreta)
    {
        if (chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta()
{
    cout << "Seu chute: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);
    chutou[chute] = true;

    if (letra_existe(chute))
    {
        cout << "Você acertou! Seu chute está na palavra." << endl;
    }
    else
    {
        cout << "Você errou! Seu chute não está na palavra." << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

void salva_nova_palavra()
{
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        arquivo << palavras.size() << endl;
        for (string palavra : palavras)
        {
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else
    {
        cout << "File not found.\n";
        exit(0);
    }
}

void adiciona_palavra()
{
    string nova_palavra;
    cout << "Digita a nova palavra com letras maiúsculas: ";
    cin >> nova_palavra;
    palavras.push_back(nova_palavra);

    salva_nova_palavra();
}

void final_do_jogo()
{
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (acertou())
    {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;
        cout << "Você gostaria de adicionar uma nova palavra ao banco de dados? s(sim) ou n(não): ";
        char adicionar_palavra;
        cin >> adicionar_palavra;
        if (tolower(adicionar_palavra) == 's')
        {
            adiciona_palavra();
        }
    }
    else
    {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
}

void sorteia_palavra(int quantidade_de_palavras)
{
    srand(time(NULL));
    int linha_da_palavra = rand() % quantidade_de_palavras;
    palavra_secreta = palavras[linha_da_palavra];
}

void le_arquivo()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");
    if (arquivo.is_open())
    {
        int quantidade_de_palavras;
        arquivo >> quantidade_de_palavras;

        for (int i = 0; i < quantidade_de_palavras; i++)
        {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras.push_back(palavra_lida);
        }
        arquivo.close();

        sorteia_palavra(quantidade_de_palavras);
    }
    else
    {
        cout << "File not found.\n";
        exit(0);
    }
}

int main()
{
    imprime_cabecalho();
    le_arquivo();
    while (!acertou() && !enforcou())
    {
        imprime_erros();
        imprime_palavra();
        chuta();
    }
    final_do_jogo();
}