# LAB 1. 'JSON parser'
## Задание 1
Реализовать парсер данных в формате JSON.

Пример входных данных в формате JSON:
{
"lastname" : "Ivanov", "firstname" : "Ivan", "age" : 25,
"islegal" : false, "marks" : [
4,5,5,5,2,3 ],
"address" : {
"city" : "Moscow", "street" : "Vozdvijenka"
} }

Так как JSON может хранить данные произвольной структуры и произвольных типов (объект, массив, число, литералы
или строка), то целесообразно будет применить для хранения этих данных тип std::any . За основу необходимо взять следующий интерфейс (файл json.h ):
class Json { public:
// Конструктор из строки, содержащей Json-данные.
Json(const std::string& s);
// Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
bool is_array() const;
// Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
bool is_object() const;
// Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым. // Если экземпляр является JSON-массивом, генерируется исключение.
std::any& operator[](const std::string& key);
// Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым. // Если экземпляр является JSON-объектом, генерируется исключение.
std::any& operator[](int index);
// Метод возвращает объект класса Json из строки, содержащей Json-данные.
static Json parse(const std::string& s);
// Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
static Json parseFile(const std::string& path_to_file); };
Таким образом объект класса Json может являться либо Json-объектом, либо Json-массивом и может хранить в себе вложенные объекты класса Json .
Класс Json должен проходить unit-тесты из файла test.cpp на json-данных, приведённых выше:

Json student = Json::parse(json); EXPECT_EQ(std::any_cast<std::string>(object["lastname"]), "Ivanov"); EXPECT_EQ(std::any_cast<bool>(object["islegal"]), false); EXPECT_EQ(std::any_cast<int>(object["age"]), 25);
auto marks = std::any_cast<Json>(object["marks"]); EXPECT_EQ(std::any_cast<int>(marks[0]), 4); EXPECT_EQ(std::any_cast<int>(marks[1]), 5);
auto address = std::any_cast<Json>(object["address"]); EXPECT_EQ(std::any_cast<std::string>(address["city"]), "Moscow"); EXPECT_EQ(std::any_cast<std::string>(address["street"]), "Vozdvijenka");
  
