#include "./List.hpp"

/**
 * Конструктор по умолчанию. Инициализирует header значением nullptr
 */
List::List() {
  this->size = 0;
  this->header = nullptr;
}


/**
 * Деструктор для освобождения памяти
 */
List::~List() {
  while (this->header != nullptr) {
    Node* temp = this->header->next;
    delete this->header;
    this->header = temp;
  }
}


/**
 * Возвращает индекс найденного элемента, если значение data было найдено в списке
 * @param data        нужное значение
 */
Node* List::find(const char& data) const {
  Node* copyHeader = this->header;

  while (copyHeader != nullptr) {
    char nodeData = copyHeader->data;

    if (nodeData == data) {
      return copyHeader;
    }

    copyHeader = copyHeader->next;
  }

  return nullptr;
}

/**
 * Добавляет элемент в начало списка
 * @param data        добавляемый элемент
 */
void List::push(const char& data) {
  if (this->header == nullptr) {         // список на данный момент пустой
    this->header = new Node(data);
    this->header->next = nullptr;

    ++this->size;
    return;
  }

  // в списке уже есть данные, поэтому применяем трюк Вирта
  Node* tempNode = new Node();

  tempNode->data = this->header->data;
  this->header->data = data;

  tempNode->next = this->header->next;
  this->header->next = tempNode;

  ++this->size;
}


/**
 * Удаляет элемент из списка
 * @param data        удаляемый элемент
 */
void List::remove(const char& data) {
  Node* del = this->find(data);     // ссылка на удаляемый элемент

  if (this->header == nullptr|| del == nullptr) {  // список пуст либо удаляемый элемент не найден в списке
    return;
  }

  if (del == this->header) {        // нужно удалить начальный элемент списка
    Node* temp = this->header->next;
    delete this->header;
    this->header = temp;

    --this->size;
    return;
  }

  Node* beforeDel = this->header;   // ссылка на элемент, предыдущий удаляемому

  while (beforeDel->next != del) {
    beforeDel = beforeDel->next;
  }

  beforeDel->next = del->next;
  --this->size;

  delete del;
  return;
}


/**
 * Создаёт список длины length из элементов, введённых с клавиатуры
 * @param length        длина списка
 */
void List::read(const int& length) {
  for (int i = 0; i < length; ++i) {
    char ch;
    std::cin >> ch;
    this->push(ch);
  }
}


Node* List::operator[](int index) const {
  Node* copyHeader = this->header;

  while (copyHeader != nullptr && (index--) > 0) {
    copyHeader = copyHeader->next;
  }

  return copyHeader;
}


/**
 * Перегрузка оператора <<, для вывода списка на экран в формате [ эл.N, эл.N-1, ... , эл.1 ]
 * @param out         поток вывода
 * @param list        выводимый список
 */
std::ostream& operator<<(std::ostream& out, const List& list) {
  Node* copyHeader = list.header;

  if (copyHeader == nullptr) {    // список на данный момент пустой
    out << "[ ]";
    return out;
  }

  out << "[ " << copyHeader->data;
  copyHeader = copyHeader->next;

  while (copyHeader != nullptr) {
    out << ", " << copyHeader->data;
    copyHeader = copyHeader->next;
  }

  out << " ]";
  return out;
}
