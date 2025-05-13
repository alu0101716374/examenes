#include <iostream>
#include <vector>

const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int ALPHABET_size = (int)sizeof(ALPHABET) - 1;

// EJERCICIO 2. Dado un objeto pw de la clase vector_t<char> de longitud n que
// almacenará diferentes contraseñas (passwords), y el siguiente alfabeto: se
// pide desarrollar un procedimiento recursivo en C++ con la siguiente cabecera:

// que genere por pantalla todas las cadenas de caracteres de longitud n basadas
// en el alfabeto anterior. Por ejemplo, si ejecutamos hacking(pw) teniendo pw
// un tamaño n igual a 4, el resultado debería ser:

// AAAA AAAB AAAC AAAD AAAE AAAF AAAG AAAH AAAI AAAJ AAAK AAAL AAAM AAAN AAAO
// AAAP AAAQ AAAR AAAS AAAT AAAU AAAV AAAW AAAX AAAY AAAZ AAA0 AAA1 AAA2 AAA3
// AAA4 AAA5 AAA6 AAA7 AAA8 AAA9 AABA AABB AABC AABD AABE AABF AABG AABH AABI
// AABJ AABK AABL AABM AABN AABO AABP AABQ AABR AABS AABT AABU AABV AABW AABX
// .... 9993 9994 9995 9996 9997 9998 9999

// NOTA: El último parámetro es el índice que itera sobre la cadena de
// caracteres que, por defecto, empieza en 0. En la evaluación de este ejercicio
// se tendrá muy en cuenta la implementación del caso base y del caso general, y
// la eficiencia de los bucles (si fueran necesarios).


void hacking(std::vector<char>& pw, const int i = 0) {
  if (pw.size() == i) {
    for (int j{0}; j < pw.size(); j++) {
      std::cout << pw[j];
    }
    std::cout << ' ';
  } else {
    for (int j{0}; j < ALPHABET_size; j++) {
      pw[i] = ALPHABET[j];
      hacking(pw, i + 1);
    }
  }
}

void Binary_generate(std::vector<char>& binary, const int i = 0) {
  if (binary.size() == i + 1) {
    for (int j{0}; j < binary.size(); j++) {
      std::cout << binary[j];
    }
    std::cout << ' ';
  } else {
    binary[i] = '0';
    Binary_generate(binary, i + 1);
    binary[i] = '1';
    Binary_generate(binary, i + 1);
  }
}

void generate_all(std::vector<char>& binary) {
  binary[binary.size() - 1] = '0';
  Binary_generate(binary);
}

int main() {
  int length{0};
  std::cin >> length;
  std::cout << std::endl;
  std::vector<char> password(length);

  // hacking(password);
  generate_all(password);
  std::cout << std::endl;
  return 0;
}