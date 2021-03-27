#ifndef _TASKS_H_
#define _TASKS_H_

#include <cmath>
#include <algorithm>
#include "./List/List.hpp"

/**
 * Функция, которая формирует список L, включив в него по одному разу элементы, значения которых
 * входят в список L1 и не входят в список L2
 *
 * @param list1         первый рассматриваемый список
 * @param list2         второй рассматриваемый список
 */
List task1(const List& list1, const List& list2);


/**
 * Функция, которая удаляет подсписок списка L1 заданный диапазоном
 * позиций. Например, со второго три
 *
 * @param list        список, в котором происходит удаление
 * @param start       начальная позиция в списке
 * @param amount      количество удаляемых элементов
 */
void task2(List& list, int start, int amount);


/**
 * Функция, которая упорядочивает значения списка L2,
 * располагая их в порядке возрастания
 *
 * @param list        упорядочиваемый список
 */
void task3(List& list);

#endif
