#include "Huffman.hpp"   

using namespace std;
//pre: mtree conte el arbre principal del algoritme de huffman
//post: les Entrades del arbre es codifican per el algoritme de huffman
void recorreArbre(BinaryTree<Entrada>&mtree, string codi){
	if (mtree.isEmpty())codi="";
	else if(mtree.getLeft().isEmpty() and mtree.getRight().isEmpty()){
		mtree.getRoot().setCodificacio(codi);
		}
	else{
	
	if (not mtree.getLeft().isEmpty()){
		
		recorreArbre(mtree.getLeft(),codi+'0');
		}
	//HI: el codi obte un 0, ja que va cap a la esquerra
	//Fita: nombre de nodes de l'arbre
	if (not mtree.getRight().isEmpty()){
	
	recorreArbre(mtree.getRight(),codi+'1');
}
	//HI: el codi obte un 1, ja que va cap a la dreta 
	//Fita: nombre de nodes de l'arbre
	}
	
	
	
}


int main (){
	string text;
	// 1. Lectura del text d'entrada
	cin>>text;
	// 2. Creació de la taula de freqüències
	TaulaFreq tf;
	tf.construirTaula(text);

	// 3. Obtenció dels codis de Huffman    
	Huffman hf(tf);
	hf.inserirCodis();
	
	
	
	BinaryTree<Entrada> mtree;
	mtree=hf.maintree();
	string codi="";
	recorreArbre(mtree,codi);
	mtree.getRoot().setCodificacio("0");
	tf.codiHuffman(mtree);
	
	cout<<endl<<"Bolcat taula de frequencies ---->"<<endl<<endl;
	tf.mostrarTaula();
	cout<<"----> Fi bolcat taula"<<endl<<endl;
	cout<<"Missatge d'entrada (com a string):"<<endl<<text<<endl;
	cout<<"Missatge codificat (com a string):"<<endl;
	cout<<tf.Textcodificat(text)<<endl;
}
