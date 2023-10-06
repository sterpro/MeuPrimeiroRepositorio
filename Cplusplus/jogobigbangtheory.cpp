//Jogo de The Big Bang Theory em C++

#include <iostream>
#include <cstdio>
#include <ctime>
#include <random>

using namespace std;

int jogador_pontos = 0, cpu_pontos = 0;
int cpu, jogador;

void inicializar(){
	cout << "O jogo de 'The Big Bang Theory': " << endl;
    cout << "PEDRA - PAPEL - TESOURA - LAGARTO - SPOCK" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "As regras são: " << endl;
	cout << "Tesoura corta papel" << endl;
	cout << "Papel cobre pedra" << endl;
	cout << "Pedra esmaga lagarto" << endl;
	cout << "Lagarto envenena Spock" << endl;
	cout << "Spock esmaga (ou derrete) tesoura" << endl;
	cout << "Tesoura decapita lagarto" << endl;
	cout << "Lagarto come papel" << endl;
	cout << "Papel refuta Spock" << endl;
	cout << "Spock vaporiza pedra" << endl;
	cout << "Pedra amassa tesoura" << endl;
	cout << "-----------------------------------------" << endl;
}

void placar(){
    cout << " #-------- PLACAR --------# " << endl;
    cout << " #   Jogador " << jogador_pontos << " X CPU " << cpu_pontos << "    # " << endl;
    cout << " #------------------------# " << endl;
}

void jogo(){

    placar();
    printf ("\n");
    printf (" Escolha um número para a sua jogada:\n");
    printf ("\n");
    cout << " 0. Pedra" << endl; 
    cout << " 1. Papel" << endl; 
    cout << " 2. Tesoura" << endl; 
	cout << " 3. Lagarto" << endl;
	cout << " 4. Spock" << endl; 
    cout << " 5. Sair" << "\n";

    srand(time(NULL));
    cpu = rand() % 5;

    cin >> jogador;

    if (jogador < 0 || jogador >= 5)
        exit(0);

    switch(jogador){
        case 0: printf (" -> Voce jogou Pedra\n");
        break;
        case 1: printf (" -> Voce jogou Papel\n");
        break;
        case 2: printf (" -> Voce jogou Tesoura\n");
        break;
		case 3: printf (" -> Voce jogou Lagarto\n");
        break;
		case 4: printf (" -> Voce jogou Spock\n");
        break;
    }
    switch(cpu){
        case 0: printf (" -> CPU jogou Pedra\n");
        break;
        case 1: printf (" -> CPU jogou Papel\n");
        break;
        case 2: printf (" -> CPU jogou Tesoura\n");
        break;
		case 3: printf (" -> Voce jogou Lagarto\n");
        break;
		case 4: printf (" -> Voce jogou Spock\n");
        break;
    }


    if ((jogador == 2 && cpu == 1) || (jogador == 1 && cpu == 0) || (jogador == 0 && cpu == 3)  || (jogador == 3 && cpu == 4) || (jogador == 4 && cpu == 2) || (jogador == 2 && cpu == 3) || (jogador == 3 && cpu == 1) || (jogador == 1 && cpu == 4) || (jogador == 4 && cpu == 0) || (jogador == 0 && cpu == 2)){
        cout << "PARABENS, VOCE GANHOU!" << endl;
        jogador_pontos++;
    }
    else if (jogador == cpu)
        cout << "Oh, nao, houve um empate!" << endl;
        
    else {
        cout << "Ish, nao foi dessa vez!" << endl;
        cpu_pontos++;
    }
}

int main(){
	
    inicializar();
    jogo();

    int novojogo;
	
    while (novojogo != 1)
    {
        cout<<"Deseja jogar novamente?" << endl;
        cout<<"0. Sim" << endl;
        cout<<"1. Nao" << endl;
        cin >> novojogo;
		
        system("cls");
		
        if(novojogo == 0){
            inicializar();
            jogo();
        }
		else{
            inicializar();
            placar();

            if (jogador_pontos > cpu_pontos)
                cout << "Parabens, voce ganhou!" << endl;
                
			else if (jogador_pontos == cpu_pontos)
                cout << "Deu empate!" << endl;
                
			else
                cout << "Ah, que pena, nao foi dessa vez!" << endl;
        }
    }
	
	return 0;
}