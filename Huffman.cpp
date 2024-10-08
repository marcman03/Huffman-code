#include "Huffman.hpp"
Huffman::Huffman(const TaulaFreq &tf) {
    for (int i = 0; i < tf.mida(); ++i) {
        BinaryTree<Entrada> bt;
        BinaryTree<Entrada> btree(tf.mostrarDada(i), bt, bt);
        qa.push(btree);
        
    }

    if (qa.size() == 0) {
        std::cerr << "Error: La cola de prioridad está vacía al inicializar el árbol de Huffman." << std::endl;
    }
}



void Huffman::inserirCodis() {
    // Continuar combinando los árboles hasta que quede solo uno
    while (qa.size() > 1) {
        BinaryTree<Entrada> aux1, aux2;

  

        // Verificar si hay al menos un árbol en la cola
        if (qa.size() > 0) {
            aux1 = qa.front();
            qa.pop();
   
        } else {
            std::cerr << "Error: No hay árboles en la cola para extraer el primer árbol." << std::endl;
            return;
        }

        // Verificar si hay un segundo árbol
        if (qa.size() > 0) {
            aux2 = qa.front();
            qa.pop();
       
        } else {
            std::cerr << "Error: No hay suficientes árboles en la cola para extraer el segundo árbol." << std::endl;
            return;
        }

        // Sumar las frecuencias de los dos árboles combinados
        Entrada suma;
        suma.setFrequencia(aux1.getRoot().getFrequencia() + aux2.getRoot().getFrequencia());

        // Crear un nuevo árbol combinando los dos árboles extraídos
        BinaryTree<Entrada> newbt(suma, aux1, aux2);

        // Mostrar mensaje de depuración con la nueva frecuencia
     

        // Insertar el nuevo árbol en la cola
        qa.push(newbt);

        
    }

    // Mensaje de éxito
    
}



BinaryTree<Entrada> Huffman::maintree(){
	return qa.front();
	}
