#include "./includes/tasks.hpp"

using namespace std;

int main() {
  int length1;
  int length2;

  cout << "Enter two lengths: ";
  cin >> length1 >> length2;

  List list1;
  List list2;

  /*===== СОЗДАНИЕ СПИСКОВ =====*/
  cout << endl;

  cout << "Enter " << length1 << " symbols: ";
  list1.read(length1);

  cout << "Enter " << length2 << " symbols: ";
  list2.read(length2);

  /*===== ВЫВОД СПИСКОВ =====*/
  cout << endl;

  cout << "L1 = " << list1 << endl;
  cout << "L2 = " << list2 << endl;

  /*===== ПЕРВОЕ ЗАДАНИЕ =====*/
  cout << endl;

  List task1List = task1(list1, list2);

  cout << "======== FIRST TASK ========" << endl;
  cout << "L = " << task1List << endl;

  /*===== ВТОРОЕ ЗАДАНИЕ =====*/
  cout << endl;
  cout << "======== SECOND TASK ========" << endl;

  int start;
  int amount;

  cout << "Enter the star position: ";
  cin >> start;

  cout << "Enter the amount of deleting elements: ";
  cin >> amount;

  task2(list1, start, amount);
  cout << "L1 = " << list1 << endl;

  /*===== ТРЕТЬЕ ЗАДАНИЕ =====*/
  cout << endl;
  cout << "======== THIRD TASK ========" << endl;

  task3(list2);
  cout << "L2 = " << list2 << endl;

  return 0;
}
