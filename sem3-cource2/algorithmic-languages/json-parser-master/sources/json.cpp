#include "json.h"
#include <iostream>
#include <fstream>

#include <string>

// Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
bool Json::is_array() const{
    return not jarr.field_array.empty();
}

// Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
bool is_object() const {
    return not jmap.field_object.empty();
}

// Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
// Если экземпляр является JSON-массивом, генерируется исключение.
std::any& Json::operator[](const std::string& key) {
    if (this->is_array) throw logic_error("экземпляр является JSON-массивом");
}
