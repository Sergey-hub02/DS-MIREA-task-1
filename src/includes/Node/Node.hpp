#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

struct Node {
  char data;        // информационная часть узла
  Node* next;       // указатель на следующий элемент списка

  /**
   * Создаёт узел без какой-либо информации
   */
  Node();

  /**
   * Создаёт узел, имеющий только информационную часть
   * @param data        информационная часть узла
   */
  Node(const char& data);
};


/**
 * Выводит на экран информационную часть узла
 * @param out       поток вывода
 * @param node      узел, информационную часть которого нужно вывести
 */
std::ostream& operator<<(std::ostream& out, Node* node);

#endif
