#include <iostream>

template <class T>
class stack_sll_t {
  private:
    sll_t<T> lista;
  public:
    void push(const &T dato)  {
      assert(dato != NULL);
      lista.insert_head(new sll_node_t<T>(dato));
    }
    void pop() {
      assert(!lista.empty());
      delete lista.extract_head();
    }
    T top() {
      assert(!lista.empty());
      return lista.get_head()->get_data();
    }
    bool empty() {
      return lista.empty();
    }
};

// Se tiene un programa principal que utiliza una pila stack  P. Utilizando sólo los métodos propios de una pila, desarrolla una función recursiva llamada sumaElementos que reciba por parámetros una pila y sume los elementos de la misma de forma recursiva.
int sumaElementos(stack_t<int>& p) {
  int suma{0};
  while (!p.empty()) {
    suma += p.top();
    p.pop();
  }
  return suma;
}

int sumaElementos(stack_t<int>& p) {
  if (p.empty()) return;
  int top;
  top = p.top();
  p.pop();
  return top + sumaElementos(p);
}

// EJERCICIO 3.  Implementar el procedimiento:

// que realiza la unión (tipo conjunto) de dos listas no ordenadas A y B con elementos no repetidos, y devuelve el resultado en la lista C.

// Por ejemplo, si A={2,1,4,3} y B={1,5,3,6}, el resultado sería C={6,3,5,1,4,2}.

void sll_union(const sll_t<int>& A, const sll_t<int>& B, sll_t<int>& C) {
   sll_node_t<int>* aux1 = A.get_head();
   while (aux1 != NULL && B.search(aux1->get_data()) != NULL) {
    C.insert_head(new sll_node_t<int> (aux1->get_data()));
    aux1 = aux1->get_next();
  }
  aux1 = B.get_head();
  while (aux1 != NULL) {
     C.insert_head(new sll_node_t<int> (aux1->get_data()));
     aux1 = aux1->get_next();
   }
}


// EJERCICIO 4. El clásico algoritmo de conversión de un número n en base decimal (base 10) a otra base b, consiste en dividir n entre la base b sucesivamente mientras el dividendo sea mayor o igual que b y, a continuación, se coge el último cociente hasta el primer resto en orden inverso. Por ejemplo, si se convierte el número 100 en base 10 a base 2, las operaciones a realizar ser ́ıan las siguientes

// Dado un número entero positivo n y una base entera b, se pide desarrollar un algoritmo recursivo de conversión de dicho número entero a cualquier base b (con 1 < b < 10) usando una cola (queue_t<T>) para guardar el número en dicha base, y cuya cabecera debe ser:

// Usando el ejemplo anterior, si el valor del entero es 100, y la base es 2, el resultado esperado por pantalla sería: 1100100. En caso de ser base 8, el resultado sería: 144.

// NOTA: s
void to_base(const unsigned numero, const unsigned short base, queue_t<unsigned>& q) {
  if (numero < base) {
    q.push(numero);
  } else {
    to_base(numero / base, base, q);
    q.push(numero % base);
    std::cout << numero;

  }

}
block_t op1(const block_t A, const block_t B, const block_t C) {ckco
  return block_t((A&B) | (A&C) | (B&C) &~(A&(B&C));
}


// bool IsBalanced(const std::string& secuencia) {
//   stack_l_t<char> pila;
//   for (char character : secuencia) {
//     if (character == '(' || character == '[' || character == '{') {
//       pila.push(character);
//     } else {
//       if (pila.empty()) return false;
//       if (character == ')' && pila.top() != '(') return false; 
//       if (character == ']' && pila.top() != '[') return false; 
//       if (character == '}' && pila.top() != '{') return false; 
//     }
//   }
//   return stack.empty();
// }

