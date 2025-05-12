#include <iostream>

// todo EJERCICIO 1.
// Desarrollar el destructor de la lista sll_t de forma recursiva implementando
// un método privado void sll_t<T>::destroy_(sll_node_t<T>*) que será llamado
// por el destructor:

void sll_t<T>::destroy_(sll_node_t<T>* nodo) {
  if (nodo == NULL) return;
  destroy_(nodo->get_next());
  delete nodo;
  nodo = NULL;
}

// todo EJERCICIO 2.
// Dentro de la clase sll_t<T>, desarrollar de forma recursiva el siguiente
// método que invierte los elementos sobre la misma lista, sin usar estructuras
// auxiliares. Por ejemplo, dada la lista [1]→[2]→[3]→[4]–||, el resultado
// esperado sería [4]→[3]→[2]→[1]–||.

void sll_t<T>::reverse(sll_node_t<T>* nodo) {
  assert(nodo != NULL);
  if (nodo_ > get_next() == NULL) {
    head_ = nodo;  // hemos llegado al final de la lista
  } else {
    reverse_(nodo->get_next());  // iterar hasta el head
    nodo->get_next()->set_next(nodo);
    nodo->set_next(NULL);
  }
}

// todo. EJERCICIO 3. Desarrollar el procedimiento:

// que sume dos números enteros positivos representados en las listas A y B de
// la clase dll_t<unsigned>, y devuelva el resultado en la lista C. Por ejemplo:

void sum(dll_t<unsigned>& A, dll_t<unsigned>& B, dll_t<unsigned>& C) {
  dll_node_t<unsigned>* aux1 = A.get_tail();
  dll_node_t<unsigned>* aux2 = B.get_tail();
  unsigned sum{0};
  unsigned carry{0};
  while (aux1 != NULL && aux2 != NULL) {
    sum = aux1->get_data() + aux2->get_data() + carry;
    C.insert_head(new dll_node_t(sum % 10));
    carry = sum / 10;
    aux1 = aux1->get_prev();
    aux2 = aux2->get_prev();
  }
  while (aux1 != NULL) {
    sum = aux1->get_data() + carry;
    C.insert_head(new dll_node_t(sum % 10));
    carry = sum / 10;
    aux1 = aux1->get_prev();
  }
  while (aux2 != NULL) {
    sum = aux2->get_data() + carry;
    C.insert_head(new dll_node_t(sum % 10));
    carry = sum / 10;
    aux2 = aux2->get_prev();
  }
  if (carry != 0) {
    C.insert_head(new dll_node_t<unsigned>(carry));
  }
}

// todo EJERCICIO 4.
// Considérese el problema de determinar si una cadena de paréntesis, corchetes
// y llaves está o no balanceada. Impleméntese una función booleana que
// determine si una cadena de caracteres, en términos de un tipo string o un
// vector de caracteres, conteniendo únicamente los símbolos ()[]{} está
// balanceada o no. Para tal fin, debe hacerse uso de una estructura de datos
// con organización LIFO.

bool isBalanced(const std::string& cadena) {
  stack_l_t<char> pila;
  for (char character : cadena) {
    if (character == '(' || character == '[' || character == '{') {
      pila.push(character);
    } else {
      if (pila.empty()) return false;
      if (character == ')' && pila.top() != '(') return false;
      if (character == ']' && pila.top() != '[') return false;
      if (character == '}' && pila.top() != '{') return false;
      pila.pop();
    }
  }
  return (pila.empty());
}