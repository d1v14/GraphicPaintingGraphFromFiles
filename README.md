GUI приложение, выполняющее функцию визуализации графа состояний.  
Граф состояний - это ориентированный граф, одна из вершин которого в каждый момент времени считается активной. Каждой дуге приписано некоторое событие, при возникновении которого происходит смена активной вершины.      
Граф состояний описывается матрицей, число строк которой равно числу вершин, а число столбцов - числу событий. Элементом i-ой строки и j- го столбца является номер строки (т.е. соответствующая ей вершина графа), которая становится активной при возникновении j-го события, если при этом вершина i была активна.  

Основной функцией объекта класса "Интерфейсное окно" является выбор файла, который содержит данные о графе состояний. При чтении файла необходимо проверить корректность данных и в случае обнаружения ошибки необходимо сформировать соответствующее сообщение пользователю.  
Номер активной вершины также задается в интерфейсе.  
При корректности данных создается объект класса "Граф состояний", устанавливаются (если необходимо) связи между новым объектом и существующими, после чего граф отображается в соответствующем окне (объект класса "Окно представления графа").  
Активная вершина помечается цветом. При смене значения номера активной вершины должны происходить изменения в отображении.  
В интерфейсе должна быть предусмотрена возможность инициирования любого из возможных событий. При их возникновении должен происходить переход в новую активную вершину, согласно графу, смена значения в интерфейсном окне и его перерисовка.  
При выборе в интерфейсе другого графа (другого файла) старый должен заменяться на новый, номер активной вершины принимать исходное (корректное) значение и граф перерисовываться.  

# Класс Graph  
graphMatrix– переменная для хранения матрицы.    
Тип: Matrix<qint16>  
Область видимости: privite   
## Методы:  
Graph() – конструктор класса.  
Тип возвращаемого значения: void

# Класс WeightedGraph  
view () – визуализация графа  
Тип возвращаемого значения: void  
Параметры на входе: QPainter& painter,const QPoint& center  
Область видимости: public  
changeActiveNumber() – изменение активной вершины  
Тип возвращаемого значения: void  
Параметры на входе: int  
Область видимости: public
fillGraph() – заполнение графа  
Тип возвращаемого значения: void  
Параметры на входе: const QString &  
Область видимости: public  

# Класс GraphWindow  
graph – переменная для хранения графа  
Тип: WeightedGraph   
Область видимости: private  
## Методы: 
GraphWindow() – конструктор класса  
Тип возвращаемого значения: void  
Параметры на входе: QWidget *parent = nullptr
Область видимости: public    
updateGraph() – Обновление графа  
Тип возвращаемого значения: void Параметры на входе: const Graph& graph
Область видимости: public  
paintEvent() – Вывод графа в окне    
Тип возвращаемого значения: void
Параметры на входе: QPaintEvent *event Область видимости: public  

# Класс Matrix  
Matrix – QVector<QVector<T>> - Хранит матрицу   
# Класс MainWndow  
Graph – хранение графа  
Область видимости: private  
Тип: WeightedGraph   
graphWindow – Окно графа  
Область видимости: private  
Тип: GraphWindow   
loadGraph– кнопка загрузки графа  
Область видимости: private  
Тип: QPushButton  
error– сообщение об ошибке/успехе  
Область видимости: private  
Тип: QLabel   
changeStatus – лейбл для отображения результата смены активной вершины  
Область видимости: private   
newNumberLabel – лейбл для отображения места выбора новой активной вершины   
Область видимости: private  
Тип: QLabel    
newNumber – поле ввода новой активной вершины  
Область видимости: private  
Тип: QLabel   

changeActiveButton – поле ввода новой активной вершины  
Область видимости: private  
Тип: QPushButton   
# Методы и слоты:  
openFile() – открытие файла  
Тип возвращаемого значения: void  
updateGraphWindow() – обновление графа  
Тип возвращаемого значения: void  
checkData() – проверка входных данных Тип возвращаемого значения: bool Параметры на входе: QString  
Область видимости: public   

