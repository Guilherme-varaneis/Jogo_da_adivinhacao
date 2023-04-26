#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

int const NUMERO_SECRETO = rand() % 100;
char dificult;
int numero_tentativas;
int tentativas = 0;
int chute;
bool naoacertou = true;
double score = 1000.0;
int pontos_perdidos;

srand(time(NULL));
cout << "jogo da adivinhacao \n";
cout << "escolha a dificuldade que deseja jogar: " << endl;
cout << "FACIL (F) \nMEDIO (M)\nDIFICIL (D) \n";
cout << "escolha: ";
cin >> dificult;

if (dificult == 'F') {
    numero_tentativas = 15;
}else if(dificult == 'M'){
    numero_tentativas = 10;
}else{
    numero_tentativas = 5;
}

for (tentativas = 1; tentativas<=numero_tentativas; tentativas++){
    cout << "Tentativa " << tentativas << " DE " << numero_tentativas << endl;
    cout << "faça o chute: "; 
    cin >> chute;
    pontos_perdidos = abs(chute - NUMERO_SECRETO)/2;
    score = score - pontos_perdidos;

    bool acertou = chute == NUMERO_SECRETO;
    bool menor = chute < NUMERO_SECRETO;

    if (acertou){
        cout << "VOCÊ ACERTOU O NUMERO SECRETO\n";
        naoacertou = false;
        break;
    }else if (menor){
       cout << "SEU CHUTE É MENOR QUE O NUMERO SECRETO \n";
        
    }else {
        cout << "SEU CHUTE É MAIOR QUE O NUMERO SECRETO \n";
    }

}
cout << "FIM DE JOGO!\n";
if(naoacertou){
    cout << "perdeu! tente novamente!\n" << endl;
}else{
    cout << "você acertou o numero em " << tentativas << endl;
    cout.precision(2);
    cout << fixed;
    cout << "sua pontuação foi " << score << " pontos" <<endl;

}
}
