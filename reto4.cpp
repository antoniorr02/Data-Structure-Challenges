#include <iostream>

using namespace std;

template <class T> class ABB;

template<class T>
struct Nodo {
      T dato; // Dato a almacenar
      Nodo<T> *izquierdo; // Puntero a la izquierda del árbol
      Nodo<T> *derecho; // Puntero a la derecha del árbol


      /**
       * @brief Constructor por defecto.
       */
      Nodo(const T dat, Nodo<T> *izq=NULL, Nodo<T> *der=NULL) {
        dato = dat;
        izquierdo = izq;
        derecho = der;
      }

      /**
       * @brief Crea un nuevo nodo.
       * @param dato dato con el que se crea.
       * @return Devuelve el nodo creado.
       */
      Nodo createNode(T & dato);

   };

// Clase declarada como template para crear árboles.
// El template nos permite usar cualquier tipo de dato.
template<class T>
class ABB {
  private:   
   Nodo<T> *raiz; // Declaración la raíz del árbol
   Nodo<T> *actual; // Declaracion del nodo actual del arbol
   int contador; // Variable de tipo entero para contar la cantidad de nodos del árbol

  public:
    
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa tanto raíz como actual a NULL.
     */
    ABB();


    /**
     * @brief Inserta un nodo en el árbol.
     *
     * Si el árbol está vacío creará un nuevo nodo invocando a createNodo.
     *
     * @param dato A insertar
     */
    void Insert(const T & dat);

    /**
     * @brief Comprueba si el árbol está vacío.
     * 
     * @return Si está vacío.
     */
    bool Empty();
   
   /**
     * @brief Imprime nuestro árbol desde el nodo que indiquemos por parámetro.
     * @param Nodo desde el que se inicia la impresión, si pasamos por parámetro el nodo raíz obtendremos por pantalla el árbol completo.
     */
    void printTree(Nodo<T> *& nodo);


    /**
     * @brief Cuenta el número de nodos
     * @param Nodo desde el que comenzará a contar el número de nodos.
     */
    void auxContador(Nodo<TDA>* nodo);
  
};

int main(){}