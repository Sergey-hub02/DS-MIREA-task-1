#include "./Node.hpp"

/**
 * Создаёт узел без какой-либо информации
 */
Node::Node() {
  ;
}


/**
 * Создаёт узел, имеющий только информационную часть
 * @param data        информационная часть узла
 */
Node::Node(const char& data) {
  this->data = data;
}


/**
 * Выводит на экран информационную часть узла
 * @param out       поток вывода
 * @param node      узел, информационную часть которого нужно вывести
 */
std::ostream& operator<<(std::ostream& out, Node* node) {
  out << node->data;
  return out;
}
