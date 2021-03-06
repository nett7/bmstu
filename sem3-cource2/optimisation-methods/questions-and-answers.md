## Вопросы

- [x] Основные понятия и классы задач исследования операций.
- [x] Постановка задачи линейного программирования (ЛП)
- [ ] Симплекс-метод решения задачи ЛП. Основные этапы симплекс-метода.
- [ ] Двойственность в ЛП. Постановка двойственной задачи ЛП. Формулировка принципа двойственности в ЛП.
- [x] Постановка задачи целочисленного программирования (ЦП). Методы решения задач ЦП.
- [ ] Метод ветвей и границ решения задачи ЦП.
- [ ] Постановка задачи булева программирования (БП). Комбинаторная сложность задачи БП. Идея «жадного» алгоритма.
- [x] Метод Балаша решения задачи БП.
- [x] Задачи управления проектами. Диаграмма Ганта.
- [ ] Топологическая сортировка и частичное упорядочение. Основные понятия теории паросочетаний.
- [x] Метод критического пути.
- [x] Задача о назначениях. Квадратичная задача о назначениях.
- [x] Основные понятия многокритериальной оптимизации (МКО). Типы критериев.
- [x] Методы свертывания критериев в МКО.
- [x] Эффективное и слабо эффективное решения. Множество Парето и «точка утопии».
- [x] Метод Саати.
- [x] Методы прямого поиска: пассивный поиск, последовательный (дихотомии, золотого сечения, Фибоначчи) поиск.
- [x] Стохастические алгоритмы. Случайный поиск. Алгоритм прямого отжига. 
- [x] Эволюционные алгоритмы.
- [x] Генетические алгоритмы: критерии останова, алгоритмы селекции, кроссовера, мутации.
- [x] ROC-анализ. 

## Ответы:
### 1 Основные понятия и классы задач исследования операций.
Основные понятия и классы задач исследования операций.
Основные определения:
Критерий оптимальности – признаки и предпочтения по которым следует производить сравнительную характеристику альтернатив и 
выбрать среди них наилучшую.
Математическая модель объекта оптимизации – модель, описывающая объект с помощью соотношений между величинами, описывающими 
его свойства.
Параметры оптимизации – это изменяемые при оптимизации величины, входящие в ММО.
Ограничения – соотношения, устанавливающие возможные пределы изменения этих параметров.
Целевая функция – функция параметров оптимизации, выражающая количественную меру достижения цели оптимизации рассматриваемого 
объекта.
Конечномерная задача оптимизации – если множество параметров оптимизации является подмножеством конечномерного линейного 
пространства.
Задача математического программированиям – конечномерная задача с единственной ЦФ; в противном случае – задача много-
критериальной оптимизации.
Задача линейного программирования – ЦФ и ограничения являются линейными относительно параметров оптимизации; в противном 
случае – задача нелинейного программирования.
Классы задач оптимизации:
- 1. Общая задача математического программирования:
 где  -  множество различных альтернатив, рассматриваемых при поиске решения задачи.  – допустимое множество.   
 при которой ЦФ достигает наименьшего значения называют оптимальным решением. Данную задачу также будем называть задачей 
 минимизации целевой функции.
- 2. Стандартная задача линейного программирования:
- 3. Общая задача линейного программирования:
Если к (1.20 – 1.22) добавить ограничения типа неравенства.
- 4. Основная задача линейного программирования -  если убрать из 3 ограничения типа равенства.
- 5. Задача квадратичного программирования
- 6. Задача дробно-линейного программирования
- 7.  Задача сепарабельного программирования.
- 8. Задача геометрического программирования (обе части - позиномами)

### 3 Постановка задачи линейного программирования (ЛП). Каноническая форма задачи ЛП. ЛП как раздел выпуклого программирования.
### 4 Двойственность в ЛП. Постановка двойственной задачи ЛП. Формулировка принципа двойственности в ЛП.
### 5 Постановка задачи целочисленного программирования (ЦП). Методы решения задач ЦП.

Постановка задачи целочисленного программирования (ЦП). Методы решения задач ЦП.
Под задачей целочисленного программирования (ЦП) понимается задача, в которой все или некоторые переменные должны принимать 
целые значения. В том случае, когда ограничения и целевая функция задачи представляют собой линейные зависимости, задачу 
называют целочисленной задачей линейного программирования. В противном случае, когда хотя бы одна зависимость будет 
нелинейной, это будет целочисленной задачей нелинейного программирования.

### 6 Метод ветвей и границ решения задачи ЦП.
### 7 Постановка задачи булева программирования (БП). Комбинаторная сложность задачи БП. Идея «жадного» алгоритма.
- [ ] Постановка задачи булева программирования (БП). 
- [ ] Комбинаторная сложность задачи БП. 
- [x] Идея «жадного» алгоритма.

`Постановка задачи булева программирования`:
найти среди n-мерных булевый векторов x=(x1,x2, ... ,xn), xi in {0,1} для i = 1, ..., n,  удовлетворяющих системеЖ
```
{ a11x1+ ... + a1nxn <= b1
{ ....
{ am1x1+ ... + amnxn <= bm
```
такой, для которого достигается минимум ЦФ  `min F = c1x1`
`Жадный алгоритм` — алгоритм, заключающийся в принятии локально оптимальных решений на каждом этапе, допуская, что конечное решение также окажется оптимальным.

### 8 Метод Балаша решения задачи БП.

[Глава 5. МЕТОДЫ НЕЯВНОГО ПЕРЕБОРА](http://math.nsc.ru/LBRT/k4/LOR/lor_Theme5.pdf)

Рассмотрим другой метод неявного перебора, который применим для решения линейной задачи булевого программирования:
```
Z(x) = ∑(j = 1 to n) cjxj → min( x∈Bn ) ;

∑(j = 1 to n)aijxj ≥bi,i=1,...,m.
```
Множество решений:
{xj : xj = 1, j ∈ N1; xj = 0, j ∈ N \ N1, N = {1, ..., n}}.

Решение является допустимым, если выполняются неравенства `∑(j = 1 to n)aijxj ≥bi,i=1,...,m.`

Предположим, что выполнены неравенства `0 ≤ c1 ≤ c2 ≤ ... ≤ cn`.

(Если для некоторого j имеет место неравенство cj < 0, то достаточ-
но ввести новую переменную xj′ = 1 – xj.)

`Допустимое решение x доминирует допустимое решение y, если Z(x) < Z(y). (Для недопустимого решения x положим Z(x) = +∞.)`

Если решения доминируются лучшим найденным допустимым решением (рекордом), то их можно отбросить.
Задача имеет 2n различных решений. Разобьем все множество решений на n + 1 подмножества с номерами k = 0, 1, ..., n таким образом, что k-е подмножество содержит все решения с k переменными, равными единице и n − k переменными, равными нулю.

![balash-all](/sem3-cource2/optimisation-methods/balash-min.png)

− при k = 0, подмножество решений состоит из единственного решения х = 0;
− при k = 1, подмножество решений включает C(1 n) решений, в которых xi=1;xj=0, j≠i; i=1,...,n;
− k-е подмножество состоит из C (k n) решений.

Если в диаграмме существует путь из вершины u в вершину v, то вершина u называется предшествующей для вершины v, а вершина v называется следующей за u. Таким образом, решения частично упорядочены.

Алгоритм начинает работу с вершины х = 0. Затем просматривает следующие за ней вершины. При этом перебор вершин может быть сокращен на основе различных правил, некоторые из которых приведены ниже.
`Правило 1.` Так как имеют место неравенства 0 ≤ c1 ≤ c2 ≤ ... ≤ cn, то значение целевой функции при переходе к следующему решению может только возрасти. Значит, если некоторая вершина соответст- вует допустимому решению, то не надо просматривать следующие за ней вершины. Они исключаются. На рис. 4 показана диаграмма в случае, когда решение х = (0, 0, 0, 1) является допустимым. Семь следующих за ней решений (вершин) исключены из рассмотрения.
`Правило 2.` Пусть Z* − минимальное (рекордное) значение целе- вой функции на найденных допустимых решениях, ZQ – значение функционала в вершине VQ, где xj = 1, j ∈ Q; xj = 0, j ∈ N \ Q. Если для некоторого r ∈ N \ Q имеет место неравенство ZQ + cr > Z*, то достаточно проверять только те следующие за VQ вершины, в кото- рыхxu =0длявсехu∈N\Q,u≥r(всилунеравенств 0≤c1 ≤c2 ≤...≤cn).

### 9 Задачи управления проектами. Диаграмма Ганта.
- [x] Задачи управления проектами. 
- [x] Диаграмма Ганта.

[Задачи управления проектами](https://studfiles.net/preview/6323124/page:2/)
[История диаграммы Ганта](http://gibtech.ru/blog/discus?entry_id=177)

`Задачи управления проектами`. 
При реализации проекта следует различать следующие фазы:
- Фаза определения и планирования (начальная фаза)
- Фаза формирования (фаза разработки и развития)
- Фаза преобразования (фаза координирования и изменения)
- Заключительная фаза

Организацию и управление проектом в отдельных фазах его реализации следует рассматривать как главные факторы успеха.

Задачи управления проектом выполняются в ходе реализации определённого проекта по внедрению системы менеджмента качества прежде всего руководителем проекта, но также и другими сотрудниками проекта. 

`Планирование проекта`
- Определение проекта (целей проекта)
- Учёт окружающей среды (анализ окружающей среды)
- Планирование задач
- Планирование хода и сроков реализации
- Планирование ресурсов
- Планирование затрат

`Определение организации проекта и культуры проекта`
- Организация проекта
- Определение ролей
- Распределение полномочий и ответственности
- Распределение задач
- Правила,ценности,нормы

`Управление персоналом,руководство командой`
- Отбор персонала
- Образование
- Руководство командой (группой реализации проекта)

`Интегрированный контроллинг проекта`
- Задачи (количество,качество)
- Процессы (сроки)
- Ресурсы,затраты

`Завершение проекта`
- Роспуск команды
- Завершение проекта

`Диаграмма Ганта`
Диагра́мма Га́нта (англ. Gantt chart, также ленточная диаграмма, график Ганта) — это популярный тип столбчатых диаграмм (гистограмм), который используется для иллюстрации плана, графика работ по какому-либо проекту. Является одним из методов планирования проектов. Используется в приложениях по управлению проектами.

`Достоинства и недостатки Диаграммы Ганта`:

- `Графический обзор`- преимущество диаграммы Ганта является ее графическое представление. Бизнесмены стали хорошо знакомы с графическим представлением диаграммы Ганта проекта сроками и этапам, и им нравится то, что они могут четко выделить этапы проекта. Так как задачи часто представляют собой ряд различных цветовых полос, члены команды по управлению проектами могут определить свои задачи с первого взгляда.
- `Приоритеты диаграммы Ганта` является хорошим презентационным инструментом, который показывает основные приоритеты проекта. Когда руководители проектов выделяют и распределяют каждый ресурс, вся команда узнает об этом и следует указаниям. Эта способность, чтобы проиллюстрировать этапы также является полезным инструментом для руководителей высшего звена, при подготовке отчетов о состоянии проекта. Диаграмма Ганта дает им способ выработать критический путь.
- `Зависимости` - недостатком диаграммы Ганта относится к зависимости задач. Часто при презентации проекта, руководители хотят показать, какие задачи зависят друг от друга. К сожалению, формат диаграммы Ганта не позволяет этого сделать. Чтобы смягчить такие проблемы, менеджеры проектов могут проиллюстрировать ограничения, связанные с задачами, добавив вертикальные линии, но это временное решение, не предоставляющее достаточно информации о ключевых зависимостях, и это не позволяет менеджерам проектов проверять их.
- `Негибкость` - проекты не являются статичными: они постоянно меняются. Тем не менее, диаграмма Ганта не является гибкой, она не может учесть такие изменения. Руководители проектов должны оценить все, прежде чем они смогут построить график, так что если изменяется оценка, то они диаграмму надо перерисовывать. Кроме того, диаграмма Ганта не может проиллюстрировать несколько возможностей планирования в том же графике.

### 10 Топологическая сортировка и частичное упорядочение. Основные понятия теории паросочетаний.
### 11 Метод критического пути.

Метод критического пути (МКП) — это метод планирования операций, в основе которого лежит математический алгоритм. Использование такой методики подразумевает создание модели проекта, включающей следующие элементы:
список всех операций, необходимых для выполнения проекта;
зависимости между этими операциями;
период времени, необходимый для выполнения каждой операции (длительность).
Зная эти значения, с помощью метода критического пути можно определить наиболее длительную последовательность операций, необходимую для завершения проекта, а также самые ранние и самые поздние моменты начала и окончания каждой операции, которые не приведут к задержке выполнения проекта. В процессе определяются так называемые «критические» операции (то есть лежащие на самом длинном пути), а также операции с общим временным резервом (их сроки можно передвинуть, но продолжительность проекта от этого не увеличится).
Если задуматься об этих задачах, мы поймем, что некоторые из них нельзя начать, пока не будут выполнены предыдущие задачи. То есть некоторые задачи зависимы от остальных.

### 12 Задача о назначениях. Квадратичная задача о назначениях.
- [x] Задача о назначениях. 
- [x] Квадратичная задача о назначениях.

`Задача о назначениях` — одна из фундаментальных задач комбинаторной оптимизации в области математической оптимизации или исследовании операций. Задача состоит в поиске минимальной суммы дуг во взвешенном двудольном графе.
В наиболее общей форме задача формулируется следующим образом:
`Имеется некоторое число работ и некоторое число исполнителей. Любой исполнитель может быть назначен на выполнение любой (но только одной) работы, но с неодинаковыми затратами. Нужно распределить работы так, чтобы выполнить работы с минимальными затратами.`

`Квадрати́чная зада́ча о назначе́ниях` (КЗН, англ. Quadratic assignment problem, QAP) — одна из фундаментальных задач комбинаторной оптимизации в области оптимизации или исследования операций, принадлежащая категории задач размещения объектов.
Задача моделирует следующую задачу из реальной жизни:
Есть множество n предприятий, которые могут быть расположены в n местах. Для каждой пары мест задано расстояние и для каждой пары производств задан вес или поток (т. e. количество материала (сырья или продукции), перевозимого между двумя производствами). Требуется расставить производства по местам (два производства нельзя размещать в одном месте) таким образом, что сумма расстояний, умноженных на соответствующие потоки, будет минимальной


### 13 Основные понятия многокритериальной оптимизации (МКО). Типы критериев.
[Обоснование и выбор критериев оптимальности](https://studopedia.ru/3_52957_vidi-kriteriev-optimalnosti.html)

Инженерные методы решения мко.

- Метод главного критерия 
```
f1 > f2, ... , fn, 
f1 - главный критерий,
```
- Метод свертки критериев
- - линейная свертка
```
МКО->ОКО

F(x)=a1f1+ ... + anfn -> max/min

ai-?
```

- Метод экспертного оценивания (аi-?)
- - Метод круглого стола (метод мозгового штурма, метод круглова стола),
- - Метод анонимных оценок (мотод "Дельфи"(дельфийский оратор), методы политического принятия решений).

f:W->R

f - критерий оптимизации.
W - множество всех решений.

`Типы критериев`.
В зависимости от вида и уровня задач оптимизации (расчет режимов резания, проектирование операции и технологического процесса или оценка работы предприятия в целом) основные используемые критерии оптимальности можно подразделить на следующие виды:
- 1) экономические: минимальная себестоимость; наименьшие народнохозяйственные приведенные затраты; наименьшие приведенные хозрасчетные затраты; наибольшая прибыль; рентабельность; минимальный уровень затрат на производство (минимальные затра­ты на электрическую и другие виды энергии, на основные и вспомогательные материалы, на фонд заработной платы и др.);
- 2) технико-экономические: максимальная производительность; наименьшее штучное время; основное и вспомогательное время; коэффициент полезного действия оборудования; надежность работы системы оборудования или отдельных ее элементов; станкоемкость изделия; стабильность технологического процесса обработки;
- 3) технологические: точность изготовления изделия, показатели качества поверхности изделия (шероховатость, волнистость, микротвердость, остаточные напряжения и др.); физико-химические свой­ства изделий; стойкость инструмента;
- 4) эксплуатационные: износостойкость; усталостная прочность; контактная жесткость и другие показатели долговечности изделий;
- 5) прочие: психологические; эстетические; эргономические.

### 14 Методы свертывания критериев в МКО.

- [ответ на главный вопрос: в чем же преимущество мультеплекативной свертки](https://studfiles.net/preview/4031478/page:6/)

`При использовании мультипликативных критериев не требуется нормировка частных критериев, и это является их преимуществом `

Метод свертывания критериев предполагает преобразование набора имеющихся частных критериев в один суперкритерий.
`F = phi(f1,f2, ... fn)`

- линейная свертка критериев
- мультиплекативная свертка критериев

1. Обоснование допустимости свертки
При обосновании допустимости свертки, мы в первую очередь должны подтвердить, что критерии, которые мы сворачиваем, должны быть однородными. Выделяют такие группы показателей эффективности;
- показатели результативности;
- показатели ресурсоемкости;
- показатели оперативности.
Критерии, которые мы сворачиваем, должны относиться к одной и той же группе, нельзя сворачивать критерии, которые относятся, например, один из них к показателям оперативности, а другой к показателям результативности. Т.е. для каждой группы свертывание частных критериев следует выполнять отдельно. При нарушении этого принципа теряется смысл критерия.
2. Нормировка критериев
Правила нормализации критериев, мы рассматривали ранее в предыдущем разделе.
3. Учет приоритетов критериев
Учет приоритетов обычно задается некоторым векторам весовых коэффициентов, которые отображают важность того или иного критерия для решаемой задачи.
4. Построение функции свертки
Для свертывания критериев, используют такие основные типы функций:
- Аддитивные функции свертки;
- Мультипликативные;

### 15 Эффективное и слабо эффективное решения. Множество Парето и «точка утопии».
- [Оптимизация векторного критерия. Парето-оптимальные решения](http://www.systematy.ru/articles/44_optimizatsiya_vektornogo_kriteriya__pareto-optimalnyie_resheniya)
- [Аналитическая иерархическая процедура Саати](http://www.gorskiy.ru/Articles/Dmss/AHP.html)
- [3.5. Методы, основанные на свертывании критериев](https://studfiles.net/preview/6826383/page:3/)
- [2.2. Метод главного критерия](https://studfiles.net/preview/4031478/page:5/)
- [Метод анализа иерархий](https://www.hse.ru/mirror/pubs/share/204810376)

[МКО](http://math.nsc.ru/~alekseeva/TPR-FIT-2012/L6_fit.pdf)

- [x] Эффективное и 
- [x] слабо эффективное решения. 
- [x] Множество Парето
- [x] «точка утопии».

`Эффективное решение`
Допустимое решение x􏰃~ ∈ X называется эффективным по Парето (оптимальным по Парето), если не существует решения x ∈ X такого, что fk(x) ≤ fk(x~􏰃), для всех k = 1,...,p, и fk(x) < fk(x􏰃) хотя бы для одного
i = 1,...,p.
Множество всех эффективных решений называется эффективным множеством и обозначается XE.
Если x􏰃 — эффективное решение, то y􏰃, такое что y􏰃 = f (x􏰃) называется недоминируемой точкой.
Множество всех недоминируемых точек называется недоминируемым множеством и обозначается YN .

`Слабо эффективное решение`
Допустимое решение x􏰃 ∈ X называется слабо эффективным (слабо эффективным по Парето), если не существует решения x ∈ X такого, что fk(x) < fk(x􏰃), для всех k = 1, ..., p.
Множество всех слабо эффективных решений называется слабо эффективным множеством и обозначается XwE.
Если x􏰃 — слабо эффективное решение, то y􏰃, такое что y􏰃 = f (x􏰃) называется слабо недоминируемой точкой
Множество всех слабо недоминируемых точек называется слабо недоминируемым множеством и обозначается YwN .

`Множество состояний системы, оптимальных по Парето, называют «множеством Парето»`
`Точка утопии` - точка с идеальным или целевым значением. Она выбирается исходя из условий задачи. 
### 16 Метод Саати.

Основа этого метода заключается в попарном сравнении альтернатив по каждому из критериев и попарном сравнении критериев с точки зрения важности для поставленной цели. Таким образом все сравнения в данном методе производится попарно.
Для сравнения Саати предполагается использовать качественные признаки переводимые потом в количественные по 9 бальной шкале.

### 17 Методы прямого поиска: пассивный поиск, последовательный (дихотомии, золотого сечения, Фибоначчи) поиск.

- [x] Методы прямого поиска: 
- [x] пассивный поиск, 
- [x] последовательный поиск
- - [x] дихотомии, 
- - [x] золотого сечения, 
- - [x] Фибоначчи

- [Вычислительные методы для инженеров. прямой пассивный поиск](http://info.alnam.ru/book_clm.php?id=69)
- [ОДНОМЕРНАЯ МИНИМИЗАЦИЯ](http://window.edu.ru/resource/882/40882/files/dvgu003.pdf)
- [метод золотого сечения](http://www.machinelearning.ru/wiki/index.php?title=Метод_золотого_сечения._Симметричные_методы)
- [метод дихотомии](http://www.machinelearning.ru/wiki/index.php?title=Методы_дихотомии)
- [метод фибоначи 6 стр](http://window.edu.ru/resource/882/40882/files/dvgu003.pdf)

`Прямой пассивный поиск`
Метод решения поставленной задачи, в котором задается правило вычисления сразу всех пробных точек x1, x2, x3, ... и за х~* принимается та точка xk,  для которой f(xk) = min(1<=i<=N) f(xi) называется методом пассивною поиска. 
Погрешность:

`ε = {b-a}/ N+1`

`Mетод дихотомии`
Существует довольно очевидная теорема: "Если непрерывная функция на концах некоторого интервала имеет значения разных знаков, то внутри этого интервала у нее есть корень (как минимум, один, но м.б. и несколько)". На базе этой теоремы построено численное нахождение приближенного значения корня функции. Обобщенно этот метод называется дихотомией, т.е. `делением отрезка на две части`.
Обобщенный алгоритм выглядит так:
- Задать начальный интервал [X_{left}..X_{right}];
- Убедиться, что на концах функция имеет разный знак;
- Повторять
- - выбрать внутри интервала точку X;
- - сравнить знак функции в точке X со знаком функции в одном из концов;
- - - если совпадает, то переместить этот конец интервала в точку X,
- - - иначе переместить в точку X другой конец интервала;
- пока не будет достигнута нужная точность.
Есть два способа выбирать х: метод хорд и метод половинного деления

`Симметричные методы`

В классе симметричных методов на каждом шаге выбирается две точки отрезка x_1 и x_2, симметрично расположенных относительно центра этого отрезка. Дальнейшие действия определяются свойством унимодальной функции: 
Пусть функция f(x) унимодальна на отрезке [a, \quad b], а ее минимум достигается в точке x*. Для любых точек x_1 и x_2 этого отрезка и таких, что a < x_1 < x_2 < b верно следующее:
- `если f(x_1) > f(x_2), то точка минимума x^* in [x_1,  b),`
- `если f(x_1) < f(x_2), то точка минимума x^* in (a, x_2].`

Исходя из определения методов, видно, что всякий симметричный метод полностью определяется заданием отрезка [a, \quad b] и правилом выбора первой точки. Тогда другая точка x_2 находится по правилу общему для всех симметричных методов: x_2=a+b-x_{1}.
Соответственно, методы различаются способом выбора симметричных точек x_1 и x_2.

`Метод золотого сечения`
Определение:
Говорят, что точка x осуществляет золотое сечение отрезка [a, b], если
{b-a}/{b-x}={b-x}/{x-a}=phi={1+sqrt{5} }/{2}

В качестве x_1 и x_2 выберем точку золотого сечения отрезка и симметричную ей. Если a<x_1<x_2<b, то при указанном выборе точек получаем, что x_1 - точка золотого сечения отрезка [a, x_2], а x_2 - точка золотого сечения отрезка [x_1, b]. Таким образом, на каждом шаге, кроме первого, необходимо вычислять значение только в одной точке, вторая берется из предыдущего шага.
Описание метода

`phi={1+sqrt{5} }/{2}`

Параметр на входе:  `epsilon - достаточно малая положительная константа, погрешность метода.`
```
1. x_1 = b-{b-a}/{phi}, \quad x_2 = a+{b-a}/{\phi}
2. Повторять:
3. Если f(x_1) > f(x_2), то a=x_1, x_1=x_2, x_2=b-(x_1-a);
4. Если f(x_1) < f(x_2), то b=x_2, x_2=x_1, x_1=a+(b-x_2);
5. пока {b-a}/{2} >= epsilon;
6. x~*={a+b}/{2}.
```
`МЕТОД ФИБОНАЧЧИ`

В тех случаях, когда вычисление значений функции в точках отрезка затруднительно (например, в условиях промышленного эксперимента) естественно стремление ограничиться числом необходимых измерений, не теряя в точности определения точки минимума. Поэтому в таких ситуациях применять метод, который бы при заданном n и мел бы наибольшую точность. К числу методов оптимальных по точности относится и метод Фибоначчи.

```
x1 = (1 − λn−1+k)a + λn−k+1b;
x2 = (λn−1+k)a + (1 − λn−k+1)b

В этом методе λn−k+1 = x1−a/b−a изменяется на каждом шагу.

На первом шаге 
x1 = a+ Fn/Fn+2 (b−a)
x2 =a+b−x1 =a+(1− Fn/Fn+1 )(b−a)=a+ Fn+1/Fn+2

Как и в методе золотого сечения, точки x1,x2 находятся на одинаковом расстоянии от середины
отрезка [a, b] и ближе к середине, чем к соответствующему концу.
На первом шаге λn = Fn/Fn+2

Число вычислений значений функции f(x) фиксировано, текущим параметром процесса будет па-
раметр k
Длина отрезка на втором шаге будет равна (∆1 = b−a); ∆2 = b−x1 = x2 −a = Fn+1/Fn+2 (b−a) = Fn+1/Fn+2 ∆1

Если на втором шаге будем иметь отрезок поиска [x1 , b], то точка x2 , будет левее середины нового от резка.По этому на новом отрезке [a,b]=[x1,b],тогда роль x1 играет точка x2,т.е.x1 =a+Fn−1/Fn+1(b−a), аx2=a+ Fn/Fn+1 (b−a)ит.д.
```


При k = n процесс заканчивается, в этом случае x1 = x2, длина отрезка поиска

`∆n= 2/Fn+2 ∆1`

Перед началом процесса поиска определяется наименьшее натуральное n, удовлетворяющее неравенству
`εFn+2 ≥b−a`

Критерием остановки процесса служит выполнение условия k = n

Применение описанных методов накладывает единственное требование на исследуемую функцию: она должна быть унимодальной.
Следовательно, указанные методы можно использовать для анализа, как непрерывных, так и разрывных функций


### 18 Стохастические алгоритмы. Случайный поиск. Алгоритм прямого отжига. 
- [x] Стохастические алгоритмы. 
- [x] Случайный поиск. 
- [x] Алгоритм прямого отжига. 

[Методы стохастической оптимизации](https://www.researchgate.net/publication/307963525_Metody_stohasticeskoj_optimizacii)
[Введение в оптимизацию. Имитация отжига](https://habr.com/ru/post/209610/)

Стохастический (от греч. στοχαστικός — «умеющий угадывать») - случайный.

Среди стохастических методов оптимизации особенно хорошо за- рекомендовали себя на практике методы, использующие закономерно- сти и принципы, заимствованные у самой природы, такие как методы эволюционной оптимизации, методы роевого интеллекта, алгоритмы имитации отжига.

`Случайный поиск`
Самым простым методом поиска является произвольная выборка решений. Случайным образом генерируются и оцениваются произ- вольные решения X до тех пор, пока не будет найдено достаточно хо- рошее решение или не пройдет заданное время или число итераций алгоритма. В качестве результата выбирается наилучшее решение из всех, которые были сформированы в процессе выборки. Основным до- стоинством метода является простота, хотя выбор произвольных ре- шений с одинаковой вероятностью может быть нетривиальной зада- чей. Существуют некоторые условия, при выполнении которых метод случайного поиска можно успешно применять:
– пространство решений содержит высокую долю удовлетвори- тельных решений;
– пространство решений не является однородным. Иными словами, нельзя определить признаки приближения к оптимальному решению.

`Алгоритм прямого отжига` 
Алгоритм основан на аналогии с процессом кристаллизации вещества, например, при отжиге металла. В ходе этого процесса температура вещества понижается, оно отвердевает, при этом замедляется скорость движения частиц вещества.
Кристаллическую решетку можно представить как систему частиц, а ее энергетическое состояние – совокупностью состояний частиц. Частицы переходят из одного энергетического состояния в другое произвольным образом, но вероятность переходов зависит от температуры системы. Вероятность перехода из высокоэнергетического состояния в низкоэнергетическое велика при любой температуре, также существует отличная от нуля вероятность перехода в состояние с более высоким значением энергии. Эта вероятность тем выше, чем меньше разница между состояниями и чем выше температура системы.
Если в роли физической системы представить задачу оптимизации, в роли энергии системы – значение целевой функции f(X), а в роли частиц – управляющие переменные X, то можно решать задачу оптимизации функции f(X), используя механизмы и законы, которые определяют процесс отвердевания.

### 19 Эволюционные алгоритмы.
-[x] Эволюционные алгоритмы.

Эволюционные алгоритмы - это алгоритмы основанные на механизмах эволюцонного отбота из природы.
Эвристический = эволюционный

Эволюционные алгоритмы делятся на три вида:

- генетические алгоритмы (с помощью селекции находится наилучшее решение)
- эволюционные стратегии (используются алгоритмы эволюции)
- эволюционное программировани (основаны на теории автоматов)

### 20 Генетические алгоритмы: критерии остановки, алгоритмы селекции, кроссовера, мутации.
-[x] ГА
-[x] критерии остановки,
-[x] алгоритмы селекции,
-[x] кроссовера,
-[x] мутации.

`Генетический алгоритм` (ГА) относится к стохастическим методам и основан на принципе естественного эволюционного отбора. 

`Критерий остановки` - условие по которому алгоритм завершает свою работу
`Алгоритм селекции` - условие по которому выбераются хромосомы для создание потомства для следующего поколения популяции
- `детерминистскй отбор` или `элитарный отбор` - убить неприспособленных - оставить приспособленных
- `пропорцинальный отбор` - выбор с помощью имитации рулетки. У каждой осыби может быть одинаковый шанс или сектора рулетки могут отличаться в зависимости от преспособленности осыбей.
- `случайный отбор` - рулетка с обинаковыми секторами.
`Алгоритм кроссовера` - алгоритм с помощью которого из двух хромосом получается одна или более новых хромосом. Напримар если хромосомы - двумерные точки, то кросовер происходит путем обмена одной из координат (одной и той же для обоих из родителей) между двума точками.
`Алгоритм мутации` - алгоритм преобразования хромосом, случайно изменяющий одну или несколько позиций (генов) в хромосоме.

### 21 ROC-анализ. 
[ROC-АНАЛИЗ](http://scicenter.online/tehnologii-meditsine-informatsionnyie-scicenter/roc-analiz-136141.html)

Метод ROC-анализа позволяет провести сравнительную оценку информативности двух методов визуализации.

`Пример`:
ROC-кривые, построенные для сравнения информативности двух диагностическим методов. Кривая А располагается ближе к верхнему левому углу. Следовательно, она более информативна, чем кривая Б

![ROC-example](/sem3-cource2/optimisation-methods/ROC-example-1.png)

ROC-кривые, построенные для сравнительной оценки информативности двух методов диагностики. Для количественной оценки методов используется сравнительный анализ площадей под кривыми. У кривой Вэта площадь больше, чем у кривой А.

Следовательно, метод В более информативен, чем метод А

![ROC-example](/sem3-cource2/optimisation-methods/ROC-example.png)

При анализе ROC-кривых придерживаются следующего принципа: `чем ближе к левому верхнему углу координатной сетки расположена кривая, тем выше информативность исследуемого метода диагностики или лучше качество системы отображения данных`. Если кривая прилежит к диагонали (или совпадает с ней), то информативность метода ничтожна. Необходимо отметить, что в качестве истинно положительных решений может выступать критерий «чувствительность», а в качестве ложно положительных - критерии «1 - специфичность». 
Метод ROC-анализа позволяет провести сравнительную оценку информативности двух методов визуализации. Если, например, необходимо сравнить возможности рентгеновской компьютерной и магнитно-резонансной томографии в выявлении очаговых патологических изменений в печени, проводят процедуру построения ROC-кривых для каждого из рассматриваемых диагностических методов. На итоговой диаграмме устанавливается взаимоотношение ROC-кривых: та кривая, которая расположена выше, будет соответствовать более информативному методу. `Метод ROC- анализа позволяет определить количественную величину достоверности различия в информативности изучаемых методов. Для этого вычисляют площадь под кривыми (рис.9.5) и по специальным формулам устанавливают доверительный интервал в различии информативности методов`. Принято считать, что коэффициент площади кривой, находящийся в интервале 0,9-1,0 следует рассматривать как показатель наивысшей информативности диагностического метода, 0,8-0,9 - хорошей, 0,7-0,8 - приемлемой, 0,6-0,7 - слабой, 0.5-0,6 - чрезвычайно слабой. Диагональ на приведенном рисунке отображает полное отсутствие информативности диагностического метода. Подробные сведения по ROC-анализу имеются в Интернете на соответствующих порталах.
