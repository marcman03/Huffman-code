#include "Huffman.hpp"   

using namespace std;

// Función que recorre el árbol y asigna el código Huffman a cada hoja
void recorreArbre(BinaryTree<Entrada>& mtree, string codi){
    if (mtree.isEmpty()) {
        codi = "";
    } else if (mtree.getLeft().isEmpty() && mtree.getRight().isEmpty()) {
        mtree.getRoot().setCodificacio(codi);
    } else {
        if (!mtree.getLeft().isEmpty()) {
            recorreArbre(mtree.getLeft(), codi + '0');
        }
        if (!mtree.getRight().isEmpty()) {
            recorreArbre(mtree.getRight(), codi + '1');
        }
    }
}

int main (){
    string text;

    // 1. Lectura del texto de entrada (usamos getline para leer todo el texto incluyendo espacios)
    getline(cin, text);

    // 2. Creación de la tabla de frecuencias
    TaulaFreq tf;
    tf.construirTaula(text);

    // 3. Obtención de los códigos de Huffman    
    Huffman hf(tf);
    hf.inserirCodis();

    // Mostrar la tabla de frecuencias con códigos asignados
    tf.mostrarTaula();
    
    // Obtener el árbol principal y recorrerlo para asignar los códigos Huffman
    BinaryTree<Entrada> mtree;
    mtree = hf.maintree();
    string codi = "";
    recorreArbre(mtree, codi);

    // En el caso de tener un único símbolo, asignamos el código "0"
    if (mtree.getRoot().getCodificacio().empty()) {
        mtree.getRoot().setCodificacio("0");
    }

    // Aplicar los códigos al texto original
    tf.codiHuffman(mtree);
    
    cout << endl << "Bolcat taula de frequencies ---->" << endl << endl;
    tf.mostrarTaula();
    cout << "----> Fi bolcat taula" << endl << endl;

    cout << "Missatge d'entrada (com a string):" << endl << text << endl;
    cout << "Missatge codificat (com a string):" << endl;
    cout << tf.Textcodificat(text) << endl;

    return 0;
}

