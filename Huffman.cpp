#include "Huffman.hpp"
Huffman::Huffman(const TaulaFreq &tf)
{
	
	for(int i=0;i<tf.mida();++i){
		BinaryTree<Entrada> bt;
		BinaryTree<Entrada> btree(tf.mostrarDada(i),bt,bt);
		qa.push(btree);
		}

	
	}

void Huffman::inserirCodis(){
	while(qa.size()!=1){
		BinaryTree<Entrada>aux1;
		BinaryTree<Entrada>aux2;
		aux1=qa.front();
		qa.pop();
		aux2=qa.front();
		qa.pop();
		Entrada suma;
		suma.setFrequencia(aux1.getRoot().getFrequencia()+aux2.getRoot().getFrequencia());
		BinaryTree<Entrada> newbt(suma,aux1,aux2);
		qa.push(newbt);
	}	
}
BinaryTree<Entrada> Huffman::maintree(){
	return qa.front();
	}
