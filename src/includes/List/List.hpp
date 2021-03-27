#ifndef _LIST_H_
#define _LIST_H_

#include "../Node/Node.hpp"

struct List {
  int size;
  Node* header;       // указатель на первый элемент списка

  /**
   * Конструктор по умолчанию. Инициализирует header значением nullptr
   */
  List();

  /**
   * Деструктор для освобождения памяти
   */
  ~List();


  /**
   * Возвращает индекс найденного элемента, если значение data было найдено в списке
   * @param data        нужное значение
   */
  Node* find(const char& data) const;


  /**
   * Добавляет элемент в начало списка
   * @param data        добавляемый элемент
   */
  void push(const char& data);


  /**
   * Удаляет элемент из списка
   * @param data        удаляемый элемент
   */
  void remove(const char& data);


  /**
   * Создаёт список длины length из элементов, введённых с клавиатуры
   * @param length        длина списка
   */
  void read(const int& length);


  Node* operator[](int index) const;
};


/**
 * Перегрузка оператора <<, для вывода списка на экран в формате [ эл.N, эл.N-1, ... , эл.1 ]
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list);

#endif
