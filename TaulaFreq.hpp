#ifndef TAULAFREQ_HPP
#define TAULAFREQ_HPP

#include "Entrada.hpp"
#include <vector>
#include "BinaryTree.hpp"
using namespace std;

class TaulaFreq {
// Tipus de mòdul: dades
// Descripció del tipus: Taula de símbols i freqüències per la codificació Huffman.

private:
	vector<Entrada> dades;
	int size;
    // COMPLETEU

public:

	// Constructors
	
	// Pre: 
	// Post: Crea una taula de freqüències buida.
	TaulaFreq();
	
	
	// Consultors
	//Pre:
	//Post:mostra la dada de la taula de frequencia p.i. en la posicio i
	Entrada mostrarDada(int i) const;
	// Pre:
	// Post: El resultat és el nombre d'elements de la taula p.i.
	int mida() const; 
	
	
	// Modificadors
	
	//pre: bt es el arbre principal del algoritme de huffman
	//post: omple els codis de la taula p.i a a partir de las entradas que hiha en bt.
	//recorre tot el arbre i si hi ha un element de la taula que esta en el arbre l'omple
	//amb el codihuffman que esta en el arbre.
	void codiHuffman(BinaryTree<Entrada>bt);
	// Pre:
	// Post: Omple la taula p.i. a partir dels caràcters de text.
	void construirTaula(string text);
	
	// Pre:
	// Post: Afegeix l'entrada e al final de la taula p.i.
	void afegirEntrada(const Entrada &e);
	
	
	// Escriptura
	//pre: la taula esta omplerta
	//post: retorna el text codificat.
	
	string Textcodificat(string text);
		
	
	// Pre:
	// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
	//       de la taula p.i.
	void mostrarTaula() const;
};

#endif
