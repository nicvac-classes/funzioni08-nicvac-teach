#include <iostream>
#include <ctime>

using namespace std;


void visualizzaStato(int capacitaMax, int contPiante, float umiditaPerc) {
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "Capacità del giardino: " << capacitaMax << " piante" << endl;
    cout << "Numero di piante piantate: " << contPiante << endl;
    cout << "Umidità del terreno: " << umiditaPerc  <<"%"<< endl;
    cout << "Si possono piantare " << capacitaMax - contPiante << " piante" << endl;
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference,
// modificando direttamente le variabili passata dal main
//Qui modificherò  direttamente le variabili umiditaPerc e capacitaMax del main
// perchè per questi due parametri ho usato il passaggio per reference (il simbolo &)
void resetGiardino(int & capacitaMax, int valoreCapacitaMax, float & umiditaPerc, float valoreUmiditaPerc ) {
    // Controllo l'input e sistemo i valori
    capacitaMax = valoreCapacitaMax;
    if (capacitaMax > 80) {
        capacitaMax = 80;
        cout << "Valore troppo grande per capacita massima. Impostato a " << capacitaMax << endl;
    } else {
        if (capacitaMax < 10) {
            capacitaMax = 10;
            cout << "Valore negativo per capacita massima. Impostato a " << capacitaMax << endl;
        }
    }

    // Controllo l'input e sistemo i valori
    umiditaPerc = valoreUmiditaPerc;
    if (umiditaPerc > 100) {
        umiditaPerc = 100;
        cout << "Valore umidità troppo grande. Limitato a " << umiditaPerc << endl;
    } else {
        if (umiditaPerc < 0) {
            umiditaPerc = 0;
            cout << "Umidità negativa. Impostata a " << umiditaPerc << endl;
        }
    }

}


string leggiComando() {
    string c;
    
    do {
        cout << "[T] Reset giardino | [P]ianta | [I]nnaffia | [R]accogli | [S]ole | [X] esci" << endl;
        cin >> c;
    } while (c != "T" && c != "P" && c != "I" && c != "R" && c != "S" && c != "X");
    
    return c;
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference (simbolo &),
// modificando direttamente le variabili passata dal main
void innaffia(float & umiditaPerc) {
    umiditaPerc = umiditaPerc + 10;
    if (umiditaPerc > 100) {
        umiditaPerc = 100;
    }
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference (simbolo &),
// modificando direttamente le variabili passata dal main
void sole(float & umiditaPerc) {
    umiditaPerc = umiditaPerc - (rand() % 50 + 1);
    if (umiditaPerc < 0) {
        umiditaPerc = 0;
    }
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference,
// modificando direttamente la variabile contPiante passata dal main (simbolo &)
void pianta(int numPiante, int capacitaMax, int & contPiante) {
    int piantate;
    int postiLiberi;
    
    postiLiberi = capacitaMax - contPiante;
    if (postiLiberi >= numPiante) {
        piantate = numPiante;
    } else {
        piantate = postiLiberi;
        cout << "Non c'è spazio per tutte le piante che hai richiesto. Ne ho piantate " << piantate << endl;
    }
    contPiante = contPiante + piantate;
}

//A differenza di flowgorithm, posso usare il passaggio dei parametri per reference (simbolo &),
// modificando direttamente la variabile contPiante passata dal main
void raccogli(int numPiante, int & contPiante) {
    int raccolte;
    
    if (contPiante >= numPiante) {
        raccolte = numPiante;
    } else {
        raccolte = contPiante;
        cout << "Non ci sono piante a sufficienza. Ne ho raccolte " << raccolte << endl;
    }
    contPiante = contPiante - raccolte;
}




int main() {
    
    srand(time(0)); //Inizializzazione funzione random...
    
    string c;
    int capacitaMax, contPiante, numPiante;
    float umiditaPerc;
    
    contPiante = 0;

    resetGiardino(capacitaMax, 50, umiditaPerc, (rand() % 101) );
    do {
        //Visualizza lo stato corrente
        visualizzaStato(capacitaMax, contPiante, umiditaPerc);

        //Legge il comando
        c = leggiComando();
        if (c == "T") {
            int valCapacitaMax;
            cout << "Inserisci la capacità massima: ";
            cin >> valCapacitaMax;
            umiditaPerc = rand() % 101;

            resetGiardino(capacitaMax, valCapacitaMax, umiditaPerc, (rand() % 101) );
            contPiante = 0;
        } else if (c == "I") {
            innaffia(umiditaPerc);
        
        } else if (c == "S") {
            sole(umiditaPerc);

        } else if (c == "P") {
            cout << "Quante piante da piantare?" << endl;
            cin >> numPiante;
            pianta(numPiante, capacitaMax, contPiante);

        } else if (c == "R") {
            cout << "Quante piante da raccogliere?" << endl;
            cin >> numPiante;
            raccogli(numPiante, contPiante);
        }
    } while (c != "X");
    cout << "Torna presto!" << endl;
    return 0;
}
