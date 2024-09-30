#include "Entrada.hpp"


Entrada::Entrada(){
	dada.frequence=0;
	dada.huffman="";

	}
Entrada::Entrada(char c, double f){
	dada.simbol=c;
	dada.frequence=f;
	
	
	}
Entrada::Entrada(const Entrada &e){
	dada.simbol =e.dada.simbol;
	dada.frequence=e.dada.frequence;
	dada.huffman=e.dada.huffman;
	
	}
Entrada& Entrada::operator=(const Entrada &e)
{
	this->dada.simbol=e.dada.simbol;
	this->dada.frequence=e.dada.frequence;
	this->dada.huffman=e.dada.huffman;
	return *this;
	}
Entrada::~Entrada(){}

void Entrada::incremFrequencia()
{
	dada.frequence+=1;
	
	}
void Entrada::setFrequencia(double f){
	
	dada.frequence=f;
	
	}
void Entrada:: setCodificacio(string co){
	dada.huffman=co;
	
	}
void Entrada:: setSimbol(char c){
	dada.simbol=c;
	
	
	}
char Entrada::getSimbol() const{
	
	return dada.simbol;
	}
double Entrada::getFrequencia() const{
	return dada.frequence;
	
	}
string Entrada::getCodificacio() const
{
	return dada.huffman;
	}
bool Entrada::operator<(const Entrada &e) const
{
	return dada.frequence<e.dada.frequence;
	
	}
ostream& operator<<(ostream &os, const Entrada &e){
	os<<"Simbol:"<<e.dada.simbol<<", Frequencia: "<<e.dada.frequence<<", Codificacio: "<<e.dada.huffman;
	return os;
	
	
}



