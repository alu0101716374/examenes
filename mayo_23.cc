#include <iostream>

// todo EJERCICIO 1. Se solicita crear una nueva clase template Pila llamada
// template<class T> class stack_sll_t que contenga lo siguiente:

template <class T>
class stack_l_t {
  // (a) Atributo  privado de la clase para implementar una pila mediante una
  // sll_t
 private:
  sll_t<T> lista;

 public:
  // (b) Método Push
  void push(const T& dato) { lista.insert_head(new sll_node_t(dato)); }
  // (c) Método Pop
  void pop() {
    assert(!lista.empty());
    delete lista.extract_head();
  }

  // (d) Método Top
  T top() {
    assert(!lista.empty());
    return lista.get_head()->get_data();
  }

  // (e) Método Empty
  bool empty() { return lista.empty(); }
};

// todo. EJERCICIO 2.
// Se tiene un programa principal que utiliza una pila stack  P. Utilizando sólo
// los métodos propios de una pila, desarrolla una función recursiva llamada
// sumaElementos que reciba por parámetros una pila y sume los elementos de la
// misma de forma recursiva.

int sumaElementos(stack_t<int>& p) {
  if (p.empty()) return 0;
  int sum{p.top()};
  p.pop();
  return sum + sumaElementos()
}

// todo EJERCICIO 3.  Implementar el procedimiento:
// que realiza la unión (tipo conjunto) de dos listas no ordenadas A y B con
// elementos no repetidos, y devuelve el resultado en la lista C.

// ! Por ejemplo, si A={2,1,4,3} y B={1,5,3,6}, el resultado sería
// C={6,3,5,1,4,2}.

void sll_union(const sll_t<int>& A, const sll_t<int>& B, sll_t<int>& C) {
  sll_node_t<int>* aux = A.get_head();
  // añado elementos de A que no están en B
  while (aux != NULL) {
    if (B.search(aux->get_data()) == NULL) {  // no está en B
      C.insert_head(new sll_node_t<int>(aux.get_data()));
    }
    aux = aux->get_next();
  }
  // añado los elementos de B
  aux = B.get_head();
  while (aux != NULL) {
    C.insert_head(new sll_node_t<int>(aux->get_data()));
    aux = aux->get_next();
  }
}

// todo EJERCICIO 4.
// El clásico algoritmo de conversión de un número n en base decimal (base 10) a
// otra base b, consiste en dividir n entre la base b sucesivamente mientras el
// dividendo sea mayor o igual que b y, a continuación, se coge el último
// cociente hasta el primer resto en orden inverso. Por ejemplo, si se convierte
// el número 100 en base 10 a base 2, las operaciones a realizar ser ́ıan las
// siguientes:

// void to_base(const unsigned n, const unsigned short b, queue_t<unsigned>& q) {
//   if (n < b) q.push(n); // valor menor que base
//   else {
//     to_base(n / b, b, q); // iterar hasta llegar al menor
//     q.push(n % 10); // añadir el actual
//   }
// }
void to_base(const unsigned n, const unsigned short b) {
  if (n < b) std::cout << n; // valor menor que base
  else {
    to_base(n / b); // iterar hasta llegar al menor
    std::cout << n % b; // añadir el actual
  }
}

// todo EJERCICIO 5. 
// Desarrollar el procedimiento que calcule el resultado sombreado en la figura usando solo el tipo block_t y las operaciones sobre bits AND (&), OR (|) y NOT (~).


// interseccion de a y b, + interseccion de a y c + interseccion de b y c - inetrsec a b c
block_t op1(const block_t A, const block_t B, const block t_C) {
  return block_t(A&B | A&C | B&C &~((A&B)&C));
}

