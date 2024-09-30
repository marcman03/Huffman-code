#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "TaulaFreq.hpp"
#include <queue>
#include "BinaryTree.hpp"
#include "PriorityQueue.hpp"
using namespace std;

class Huffman {

// Tipus de màdul: dades
// Descripció del tipus: Taula de codis de símbols obtinguts a partir de la
//                       codificació Huffman. 

private:	

	// COMPLETEU
	
    TaulaFreq TF;
    Queue<BinaryTree<Entrada>>qa;
public:
    // Constructors
	
	// Pre:  tf = TF
    // Post: Crea una codificació Huffman buida a partir de la taula de freqüències
    //       TF on només hi ha els símbols i la seva freqüència.
    Huffman(const TaulaFreq &tf);
	
    // Consultors
	
	// Pre:
	// Post: El resultat és la traducció del text d'entrada a un text
	//       amb la codificació Huffman ((string de 0 i 1)
	string codificar(const string &textE);
    
    // Modificadors	
	
		
		
	// Pre: qa no esta buida i té minim dos elements
    // Post: Calcula la codificació Huffman (els codis de Huffman per cada símbol
    //       segons la freqüència de cadascun d'ells).
     void inserirCodis();
     //pre: en qa hi ha nomes el arbre principal
     //post retorna el arbre principal
     BinaryTree<Entrada> maintree();
	 
	// Escriptura
	
	// Pre:
	// Post: S'ha mostrat pel canal estàndard de sortida el contingut 
	//       de la TaulaFreq del p.i., amb els símbols, freqüències i 
	//       codis Huffman.
	void mostrarCodis() const;
};

#endif
