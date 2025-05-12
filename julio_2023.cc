#include <iostream>
#include <vector>

const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int ALPHABET_size = (int)sizeof(ALPHABET) - 1;

void hacking(std::vector<char>& pw, const int i = 0) {
  if (i == pw.size()) {
    for (int j{0}; j < pw.size(); j++) {
      std::cout << pw[j];
    }
    std::cout << ' ';
    return;
  }
  for (int j{0}; j < ALPHABET_size; j++) {
    pw[i] = ALPHABET[j];
    hacking(pw, i + 1);
  }
}

bool is_palindrome(const std::vector<char>& s, const int i, const int d) {
  if (i >= d) return true;
  return s[i] == s[d] && is_palindrome(s, i + 1, d - 1);
}

// todo. que fusiona dos listas de enteros L1 y L2, y devuelve el resultado en R, estando las tres listas ordenadas de menor a mayor.
void merge(dll_t<int>& L1, dll_t<int>& L2, dll_t<int>& R) {
  
  dll_node_t<int>* aux1 = L1.get_head();
  dll_node_t<int>* aux2 = L2.get_head();
  int val1, val2, value;
  // ambos listas tienen elementos
  while (aux1 != NULL && aux2 != NULL) { 
    val1 = aux1->get_data();
    val2 = aux2->get_data();
    // val2 es menor, meterlo y avanzar aux2
    if (val1 > val2) { 
      value = val2;
      aux2 = aux2->get_next();
    } else if (val1 < val2) { // val1 es menor, meterlo y avanzar aux1
      value = val1;
      aux1 = aux1->get_next();
    } else { // son iguales, meter uno y avanzar ambos
      value = val1;
      aux1 = aux1->get_next();
      aux2 = aux2->get_next();
    }
    R.insert_tail(new dll_node_t<int>(value));
  }
  // segunda lista ya vacia, meter lo que queda de la primera
  while (aux1 != NULL) {
    R.insert_tail(new dll_node_t<int>(aux1->get_data()));
    aux1 = aux1->get_next();
  }
  
  // primera lista ya vacia, meter lo que queda de la segunda
  while (aux2 != NULL) {
    R.insert_tail(new dll_node_t<int>(aux2->get_data()));
    aux2 = aux2->get_next();
  }
}

// todo. EJERCICIO 1. Implementar el operador * que devuelve el producto escalar de dos vectores dispersos (sparse_vector_t), con la siguiente cabecera:


double operator*(const sparse_vector_t& a, const sparse_vector_t& b) {
  doule result{0.0};
  
}


int main() {
  int n{0};
  std::cout << "Intoduce el numero de caractéres: ";
  std::cin >> n;
  std::vector<char> password(n);
  std::cout << "\nLAs cadenas son:\n";
  hacking(password, 0);
  return 0;
}