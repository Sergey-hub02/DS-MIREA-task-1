#include "./tasks.hpp"

/**
 * Функция, которая формирует список L, включив в него по одному разу элементы, значения которых
 * входят в список L1 и не входят в список L2
 *
 * @param list1         первый рассматриваемый список
 * @param list2         второй рассматриваемый список
 */
List task1(const List& list1, const List& list2) {
  List list;
  Node* list1Header = list1.header;

  while (list1Header != nullptr) {
    char value = list1Header->data;

    if (list1.find(value) != nullptr && list2.find(value) == nullptr) {
      list.push(value);
    }

    list1Header = list1Header->next;
  }

  return list;
}


/**
 * Функция, которая удаляет подсписок списка L1 заданный диапазоном
 * позиций. Например, со второго три
 *
 * @param list        список, в котором происходит удаление
 * @param start       начальная позиция в списке
 * @param amount      количество удаляемых элементов
 */
void task2(List& list, int start, int amount) {
  --start;

  if (start < 0 || start > list.size - 1) {
    return;
  }

  int index = 0;
  Node* listHeader = list.header;

  while ((index++) < start) {
    listHeader = listHeader->next;
  }

  // сейчас в listHeader указатель на элемент под индексом start
  while ((amount--) > 0 && listHeader != nullptr) {
    Node* temp = listHeader->next;
    list.remove(listHeader->data);
    listHeader = temp;
  }
}


/**
 * Функция, которая упорядочивает значения списка L2,
 * располагая их в порядке возрастания
 *
 * @param list        упорядочиваемый список
 */
void task3(List& list) {
  const int N = list.size;

  for (int i = 0; i < N; ++i) {
    int minCharIndex = i;

    for (int j = i + 1; j < N; ++j) {
      if (list[j]->data < list[minCharIndex]->data) {
        minCharIndex = j;
      }
    }

    // обмен информационными частями
    Node* current = list[i];
    Node* minElement = list[minCharIndex];

    std::swap(current->data, minElement->data);
  }
}
