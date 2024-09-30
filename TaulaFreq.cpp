#include "TaulaFreq.hpp"
TaulaFreq::TaulaFreq()
{
	size=0;
	
	}
int TaulaFreq:: mida() const
{
	return dades.size();
	}
void TaulaFreq::codiHuffman(BinaryTree<Entrada>bt){
	if (bt.isEmpty()){}
	else{
		for (int i=0;i<dades.size();++i){
			if (dades[i].getSimbol()==bt.getRoot().getSimbol()){
				dades[i].setCodificacio(bt.getRoot().getCodificacio());
				}
			
			}
		codiHuffman(bt.getLeft());
		//HI: recorre tot el arbre per la esquerra
		//Fita: nombre de nodes de l'arbre
		codiHuffman(bt.getRight());
		//HI: recorre tot el arbre per la esquerra
		//Fita: nombre de nodes de l'arbre
		}
	
	
	}

Entrada TaulaFreq::mostrarDada(int i) const
{
	return dades[i];
	
	
	}
void TaulaFreq::construirTaula(string text)
{
	
	for(int i=0; i< text.size();++i){
		bool trobat=false;
		for (int j=0;j<dades.size();++j){
			if (text[i]==dades[j].getSimbol()){
				trobat=true;
				dades[j].incremFrequencia();
				}
	
		}
	if (not trobat){
		Entrada e(text[i],1);
		dades.push_back(e);
		}
	
	}
	for(int i=0;i<dades.size();++i){
		dades[i].setFrequencia(dades[i].getFrequencia()/text.size());
		}
 }
void TaulaFreq::afegirEntrada(const Entrada &e)
{
	dades.push_back(e);
	
	}
string TaulaFreq::Textcodificat(string text){
	string codi;
	for(int i=0;i<text.size();++i){
		for(int j=0;j<dades.size();++j){
			if (dades[j].getSimbol()==text[i]){
				codi=codi +dades[j].getCodificacio();
				}
			}
		}
	return codi;
	
	
	
	}
void TaulaFreq::mostrarTaula() const
{
	cout<<"Mida: "<<dades.size()<<" simbols"<<endl;
	for (int i=0;i<dades.size();++i){
		cout<<"Entrada "<<i<<":"<<dades[i]<<endl;
		
		}
		

	
	}
