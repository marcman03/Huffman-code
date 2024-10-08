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
void TaulaFreq::construirTaula(string text) {
    

    // Recorrer el texto para construir la tabla de frecuencias
    for(int i = 0; i < text.size(); ++i) {
        char simbol = text[i];
      
        
        bool trobat = false;
        for (int j = 0; j < dades.size(); ++j) {
            // Si el símbolo ya está en la tabla, incrementamos su frecuencia
            if (simbol == dades[j].getSimbol()) {
                trobat = true;
                dades[j].incremFrequencia();
                break; // Salimos del bucle cuando encontramos el símbolo
            }
        }

        if (!trobat) {
            // Si el símbolo no está en la tabla, lo añadimos
            Entrada e(simbol, 1);
            dades.push_back(e);
 
        }
    }

    // Normalizar las frecuencias
    for(int i = 0; i < dades.size(); ++i) {
        dades[i].setFrequencia(static_cast<float>(dades[i].getFrequencia()) / text.size());
    }

    // Verificar el tamaño final de la tabla

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
void TaulaFreq::mostrarTaula() const {
    std::cout << "Mida: " << dades.size() << " simbols" << std::endl;
    for (int i = 0; i < dades.size(); ++i) {
        std::cout << "Entrada " << i << ": Simbol: '" << dades[i].getSimbol() 
                  << "', Frequencia: " << dades[i].getFrequencia() 
                  << ", Codificacio: " << dades[i].getCodificacio() << std::endl;
    }
}



