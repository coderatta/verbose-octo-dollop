#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

void apresentacao()
{
    cout << "********************************\n";
    cout << "Bem vindo ao jogo da adivinhação\n";
    cout << "********************************\n";
}

double subtrai_pontos(int chute, int NUMERO_SECRETO)
{
    return abs((chute - NUMERO_SECRETO) / 2.0);
}

int escolhe_dificuldade()
{
    char dificuldade;

    cout << "Escolha a dificuldade: f(fácil) m(médio) d(difícil): ";
    cin >> dificuldade;

    switch (tolower(dificuldade))
    {
    case 'f':
        return 15;
        break;
    case 'm':
        return 10;
        break;
    case 'd':
        return 5;
        break;
    default:
        cout << "Entrada inválida\n";
        return escolhe_dificuldade();
    }
}

int main(void)
{
    apresentacao();

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    int chute;
    bool acertou = false;
    int tentativas = 1;
    double pontuacao = 1000.0;
    int chances = escolhe_dificuldade();

    while (!acertou && tentativas < chances)
    {
        cout << "Chuta aí: ";
        cin >> chute;

        if (chute == NUMERO_SECRETO)
        {
            cout << "Você acertou em " << tentativas << " de " << chances << " tentativas\n";
            cout << fixed << setprecision(4);
            cout << "Sua pontuação foi de " << pontuacao << " pontos\n";
            acertou = true;
        }
        else if (chute > NUMERO_SECRETO)
        {
            cout << "Seu chute foi maior\n";
        }
        else
        {
            cout << "Seu chute foi menor\n";
        }
        tentativas++;
        pontuacao -= subtrai_pontos(chute, NUMERO_SECRETO);
    }

    if (chances == 0)
    {
        cout << "Não foi dessa vez\n";
    }
    return 0;
}
