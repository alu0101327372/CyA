#include "Alphabet.h"

/// Constructor de copia 1, para hacer el objeto partiendo de sus atributos.
Alphabet::Alphabet(const std::string& name, const std::set<char>& alphabet)
    : name_(name), alphabet_(alphabet) {}



Alphabet::Alphabet(const Alphabet& alphabet) 
    : name_(alphabet.name_), alphabet_(alphabet.alphabet_) {}

/// Setter. Para cambiar el valor de un objeto con un caracter. 
void Alphabet::Insert(const char& symbol) {
  char aux(symbol);
  alphabet_.insert(aux);
}

/// Setter. Para cambiar el valor de un objeto con una std::string.
void Alphabet::Insert(const std::string& symbol) {
  if (symbol.size() == 1) {
    char aux(symbol.front());
    alphabet_.insert(aux);
  }
}

/// Setter. Para cambiar el valor del objeto partiendo de sus atributos.
void Alphabet::SetAlphabet(const std::string& name, 
                               const std::set<char>& alphabet) {
  name_ = name;
  alphabet_ = alphabet;
}

/// Setter. Para cambiar el valor del objeto partiendo de otro.
void Alphabet::SetAlphabet(const Alphabet& alphabet) {
  name_ = alphabet.name_;
  alphabet_ = alphabet.alphabet_;
}

/// Setter. Para cambiar el valor del nombre solo.
void Alphabet::SetName(const std::string& name) {
  name_ = name;
}

/// Getter. Para conseguir el valor del alfabeto en una posición concreta,
/// aunque es un std::set<Symbol>, actua como un std::vector<Symbol>.
char Alphabet::At(const size_t& position) const {
  char result;
  if (position < alphabet_.size()) {
    size_t count{0};
    for (std::set<char>::iterator i{alphabet_.begin()}; 
         i != alphabet_.end(); ++i) {
      if (count == position) {
        result = *i;
        break;
      }
      ++count;
    }
  }

  return result;
}

/// Getter. Para obtener todo el alfabeto de golpe.
std::set<char> Alphabet::GetAlphabet(void) const {
  return alphabet_;
}

/// Getter. Para conseguir el nombre dle alfabeto.
std::string Alphabet::GetName(void) const {
  return name_;
}

/// Función de la clase. Comprueba si el símbolo(caracter) está en el alfabeto.
bool Alphabet::IsItInAlphabet(const char& symbol) const {
  bool result{false};
  for (std::set<char>::iterator i{alphabet_.begin()}; 
       i != alphabet_.end(); ++i) {
    if (symbol == *i) {
      result = true;
      break;
    }
  }
  return result;
}

/// Función de la clase. Igual que la anterior, pero le pasas una std::string.
bool Alphabet::IsItInAlphabet(const std::string& symbol) const {
  bool result{false};
  if (symbol.size() == 1) {
    char aux(symbol.front());
    for (std::set<char>::iterator i{alphabet_.begin()}; 
      i != alphabet_.end(); ++i) {
      if (aux == *i) {
        result = true;
        break;
      }
    }
  }
  return result;
}

/// Función de la clase. Limpia el alfabeto.
void Alphabet::Clear(void) {
  alphabet_.clear();
}

/// Operador sobrecargado '='. Iguala los nombres y los alfabetos.
void Alphabet::operator=(const Alphabet& alphabet) {
  alphabet_ = alphabet.alphabet_;
  name_ = alphabet.name_;
}

/// Operador sobrecargado '=='. Comprueba si los alfabetos son iguales.
bool Alphabet::operator==(const Alphabet& alphabet) const {
  bool result{true};
  if (alphabet_.size() == alphabet.alphabet_.size()) {
    size_t count{0};
    for (std::set<char>::iterator i{alphabet_.begin()}; 
         i != alphabet_.end(); ++i) {
      if (!(alphabet.At(count) == *i)) {
        result = false;
        break;
      }
      ++count;
    }
  } else {
    result = false;
  }

  return result;
}

/// Operador sobrecargado '[]'. Devuelve el contenido del alfabeto en la
/// posición indicada.
char Alphabet::operator[](const size_t position) const {
  return this->At(position);
}

/// Operador sobrecargado '<<'. Muestra el contenido del alfabeto de forma
/// clara por la salida estándar.
std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  out << alphabet.name_ << " = ";
  std::string aux{"{"};
  if (alphabet.alphabet_.size() > 0) {
    for (std::set<char>::iterator i{alphabet.alphabet_.begin()}; 
         i != alphabet.alphabet_.end(); ++i) {
      aux += *i + ", ";
    }
    aux.pop_back(); ///< Quitamos el último espacio.
    aux.pop_back(); ///< Quitamos la última coma.
    out << aux << '}';
  } else {
    out << "{VOID}";
  }
  
  return out;
}

/// Operador sobrecargado '>>'. Permite crear un objeto de la clase
/// dinámicamente.
std::istream& operator>>(std::istream& input, Alphabet& alphabet) {
  std::cout << "¿Cuál quiere que sea el nombre del alfabeto? ";
  std::string aux_str{""};
  input >> aux_str;
  alphabet.SetName(aux_str);
  std::cout << "¿Cuántos Símbolos quiere que tenga el alfabeto? ";
  int aux{0};
  input >> aux;
  alphabet.Clear();
  for (size_t i{0}; int(i) < aux; ++i) {
    std::cout << "Introduzca el Símbolo " << i + 1 << ": ";
    input >> aux_str;
    while (alphabet.IsItInAlphabet(aux_str)) {
      std::cout << "Introduzca un símbolo no repetido por favor: ";
      input >> aux_str; 
    }
    alphabet.Insert(aux_str);
  }

  return input;
}