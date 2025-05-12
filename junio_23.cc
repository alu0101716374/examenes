#include <iostream>
#include <vector>
// todo.. EJERCICIO 1. Escribe una función en C++ con la siguiente cabecera:
// ? que devuelve un nuevo vector vector_t<int>, y que contiene los elementos
// del vector original rotados r veces hacia la derecha. Por ejemplo, si
// v=[10,21,32,43,54,65,76,87,98], el resultado esperado para la llamada a
// rotate(v, 5) sería [54,65,76,87,98,10,21,32,43].

// vector_t<int> rotate(const vector_t<int>& v, const int r) {
//   vector_t<int>(v.get_size()) result;
//   for (int i{0}; i < result.get_size(); i++) {
//     result[(i + r) % result.get_size()] = v[i];
//   }
//   return result;
// }

// todo.  EJERCICIO 2.  Escribe una función en C++ con la siguiente cabecera:
// ? y verifique si la cadena de entrada es palíndroma. Un palíndromo es una
// palabra o frase que se lee igual de izquierda a derecha y de derecha a
// izquierda, sin tener en cuenta los espacios ni los caracteres especiales. La
// función debe utilizar una pila (stack_v_t<char> o stack_l_t<char>) para
// realizar la verificación. Por ejemplo, el resultado esperado sería true para
// la siguiente cadena de entrada: !
// ['Y','O','H','A','G','O','Y','O','G','A','H','O','Y'] racecar

// bool es_palindroma(const vector_t<char>& cadena) {
//   stack_l_t<char> pila;
//   for (int i{0}; i < cadena.size() / 2; i++) {
//     pila.push(cadena[i]);
//   }
//   int inicio{0};
//   if (cadena.size() % 2 != 0) {
//     inicio = (cadena.size() / 2) + 1;
//   }
//   for (int i{inicio}; i < cadena.size(); i++) {
//     if (pila.top() == cadena[i]) {
//       pila.pop();
//     } else {
//       return false;
//     }
//   }
//   return true;
// }

// todo. EJERCICIO 3.  Dado un tamaño n, y un objeto de la clase vector_t<char>
// de longitud n, se pide desarrollar un procedimiento recursivo en C++ con la
// siguiente cabecera: ?  que genere por pantalla todas las cadenas de números
// binarios de longitud n. Por ejemplo, si ejecutamos all_bin(binario) con un
// tamaño n igual a 4, el resultado debería ser:

// ! 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110
// 1111

void all_bin(std::vector<char>& binario, const int i = 0) {
  if (i == binario.size()) {
    for (int i{0}; i < binario.size(); i++) {
      std::cout << binario[i];
    }
    std::cout << ' ';
    return;
  }
  binario[i] = '0';
  all_bin(binario, i + 1);
  binario[i] = '1';
  all_bin(binario, i + 1);
}

// todo. EJERCICIO 4. Para la clase dll_t<int>, desarrollar el método
// especializado ? que busca un valor dentro de la lista, devolviendo el puntero
// del nodo que lo contiene o NULL si no lo encuentra.

template <>
dll_node_t<int>* dll_t<int>::find(const int v) {
  dll_node_t<int>* aux = get_head();
  while (aux != NULL && aux->get_data() != v) {
    aux = aux->get_next();
  }
  return aux;
}

// todo EJERCICIO 5. Para la clase sll_t<T>,
// ?  desarrollar el método especializado que elimina y libera todos los
// elementos de posiciones pares de la lista, y cuya cabecera es:

template <class T>
void sll_t<T>::erase_evens(void) {
  sll_node_t<T>* aux = get_head();
  while (aux != NULL && aux->get_next() != NULL) {
    delete erase_after(aux);
    aux = aux->get_next();
  }
}

// todo EJERCICIO 6.
// ? Considérese la función de Ackermann. Implementar un algoritmo recursivo que
// calcule el valor de la función para cualquier par de términos.
int Ackerman(int x, int y) {
  if (x == 0) return y + 1;
  if (y == 0) return Ackerman(x - 1, 1);
  return Ackerman(x - 1, Ackerman(x, y - 1));
}
int main() {
  std::vector<char> binary(4);
  all_bin(binary);
  std::cout << std::endl;
  return 0;
}