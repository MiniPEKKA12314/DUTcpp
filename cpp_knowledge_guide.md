# C++ 课程知识点总整理

本手册汇总本目录 Practice 1-18 的核心内容。示例默认省略了部分无关代码；使用 `string`、`cout`、`vector` 等名称时，需包含对应头文件，并可写 `using namespace std;`。

## 1. 课程知识地图

| 课次 | 核心主题 | 关键内容 |
|---|---|---|
| 1 | C++ 入门 | `main`、输出、变量、基本类型 |
| 2 | 变量与输入 | `cin`、赋值、字符串拼接 |
| 3 | 条件判断 | `bool`、比较运算符、`if/else` |
| 4 | 循环与菜单 | `while`、计数器、无限循环 |
| 5 | 文件持久化 | `ofstream`、`ifstream` |
| 6 | 完整文本输入 | `getline`、空格、多行笔记 |
| 7 | 搜索 | `string::find`、`string::npos` |
| 8 | 结构化笔记 | 标签、元数据、按标签检索 |
| 9 | 函数 | 声明、定义、参数、返回值、模块化 |
| 10 | 引用与数据流 | 按值、按引用、`const T&` |
| 11 | 指针与内存 | 地址、`&`、`*`、`nullptr` |
| 12 | 类与封装 | `class`、对象、`public`、`private` |
| 13 | 对象生命周期 | 构造函数、析构函数、RAII |
| 14 | 运算符与友元 | `operator`、`friend`、`<<` |
| 15 | 多态 | 继承、`virtual`、`override` |
| 16 | 系统架构 | 组合、`NoteManager`、委托、低耦合 |
| 17 | 工厂模式 | `NoteFactory`、创建与使用分离 |
| 18 | 上下文系统 | 检索、Context Builder、RAG 流水线 |

---

## 2. 程序基础：头文件、`main`、输出

最小 C++ 程序：

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, C++!\n";
    return 0;
}
```

- `#include <iostream>`：提供 `cout`、`cin` 等输入输出工具。
- `main()`：每个 C++ 程序的入口。
- `cout`：输出到终端。
- `<<`：将右边内容写入输出流。
- `\n`：换行；也可使用 `endl`，但通常 `\n` 更轻量。
- `return 0;`：表示程序正常结束；现代 C++ 的 `main` 中可省略。

### 常用头文件

```cpp
#include <iostream>   // cout, cin
#include <string>     // string
#include <fstream>    // ifstream, ofstream
#include <vector>     // vector
#include <algorithm>  // find, find_if, sort
#include <memory>     // unique_ptr, make_unique
#include <limits>     // numeric_limits
```

不使用 `using namespace std;` 时，需要写完整名称：

```cpp
std::cout << "Hello\n";
std::string title;
```

---

## 3. 变量、类型与赋值

变量是“有名字的存储位置”。

```cpp
int age = 18;              // 整数
double price = 19.99;      // 小数
char grade = 'A';          // 单个字符，使用单引号
bool finished = false;     // true 或 false
string name = "Alice";    // 文本，使用双引号
```

### 声明、初始化、赋值

```cpp
int score;         // 声明：创建变量
score = 100;       // 赋值：之后放入值

int level = 1;     // 声明并初始化
level = level + 1; // 读取旧值，计算后再赋回
```

### 命名规则

```cpp
int playerScore;  // 合法
int _count;       // 合法，但初学阶段不建议以 _ 开头

// int 2score;    // 不合法：不能以数字开头
// int class;     // 不合法：class 是关键字
// int my-score;  // 不合法：- 被理解为减号
```

### 字符串拼接

```cpp
string name = "Alice";
string message = "Hello " + name;
cout << message << '\n';  // Hello Alice
```

---

## 4. 输入：`cin` 与 `getline`

### `cin >> variable`

适合读取一个不含空格的单词、数字或菜单选项：

```cpp
int age;
cin >> age;

string command;
cin >> command;  // 输入 "add note" 时只会读到 "add"
```

### `getline(cin, text)`

适合读取一整行文本，包括空格：

```cpp
string note;
cout << "Enter note: ";
getline(cin, note);
```

输入：

```text
Learn classes and pointers
```

`note` 会保存整行。

### `cin >>` 后接 `getline` 的常见问题

`cin >> choice` 会留下换行符。紧接着的 `getline` 会读到这个空行：

```cpp
int choice;
string title;

cin >> choice;
getline(cin, title);  // 常常直接得到空字符串
```

处理方式：读完数字后丢弃输入缓冲区剩余内容。

```cpp
#include <limits>

cin >> choice;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, title);
```

`cin.clear()` 用于输入类型错误后恢复输入流：

```cpp
if (!(cin >> choice)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter a number.\n";
}
```

---

## 5. 条件判断与布尔表达式

### 比较运算符

| 运算符 | 含义 | 示例 |
|---|---|---|
| `==` | 等于 | `score == 100` |
| `!=` | 不等于 | `name != ""` |
| `>` | 大于 | `age > 18` |
| `<` | 小于 | `count < 10` |
| `>=` | 大于等于 | `score >= 60` |
| `<=` | 小于等于 | `level <= 5` |

注意：`=` 是赋值，`==` 才是比较。

```cpp
if (score >= 60) {
    cout << "Pass\n";
} else {
    cout << "Fail\n";
}
```

多个条件：

```cpp
if (age >= 18 && hasTicket) {
    cout << "Allowed\n";
}

if (type == "text" || type == "todo") {
    cout << "Known type\n";
}

if (!finished) {
    cout << "Not finished\n";
}
```

---

## 6. 循环与菜单程序

### `while` 循环

只要条件为 `true`，循环持续执行。

```cpp
int count = 1;

while (count <= 3) {
    cout << count << '\n';
    count++;
}
```

输出 `1`、`2`、`3`。若忘记更新 `count`，可能产生无限循环。

### 菜单循环模板

```cpp
int choice = 0;

while (choice != 4) {
    cout << "1. Add\n2. View\n3. Search\n4. Exit\n";
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1) {
        // add
    } else if (choice == 2) {
        // view
    } else if (choice == 3) {
        // search
    } else if (choice != 4) {
        cout << "Invalid choice.\n";
    }
}
```

也可使用 `switch`：

```cpp
switch (choice) {
case 1: /* add */ break;
case 2: /* view */ break;
case 3: /* search */ break;
case 4: /* exit */ break;
default: cout << "Invalid choice.\n";
}
```

---

## 7. 文件读写与持久化

持久化表示：程序关闭后，数据仍保存在文件中。

### 写文件：`ofstream`

```cpp
#include <fstream>

ofstream file("notes.txt");

if (!file) {
    cout << "Could not open file.\n";
} else {
    file << "First note\n";
}
```

默认写入模式会覆盖旧文件内容。使用 `ios::app` 追加到文件末尾：

```cpp
ofstream file("notes.txt", ios::app);
file << "Another note\n";
```

### 读文件：`ifstream`

```cpp
ifstream file("notes.txt");

if (!file) {
    cout << "Could not open file.\n";
} else {
    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }
}
```

文件对象离开作用域时会自动关闭；手动 `file.close()` 也可以，但通常不是必需的。

---

## 8. 字符串与搜索：`find`

### `string::find`

用于在一个字符串中查找子字符串：

```cpp
string note = "Learn C++ classes";

if (note.find("C++") != string::npos) {
    cout << "Found\n";
}
```

```cpp
size_t position = note.find("classes");
```

若找到，`position` 是起始下标，**从 0 开始计数**；找不到时返回 `string::npos`。

```cpp
string text = "Hello";
cout << text.find("ll");  // 2
```

`find` 默认大小写敏感：

```cpp
"Machine".find("machine");  // 找不到
```

### `std::find` 与 `find_if`

它们来自 `<algorithm>`，用于在容器中找元素，与 `string::find` 不同。

```cpp
#include <algorithm>

vector<int> values = {3, 7, 10};
vector<int>::iterator it = find(values.begin(), values.end(), 7);

if (it != values.end()) {
    cout << "Found\n";
}
```

初学阶段，删除笔记可以先用普通下标循环，避免过早使用复杂的 lambda 和迭代器：

```cpp
for (int i = 0; i < notes.size(); i++) {
    if (notes[i].hasTitle(title)) {
        notes.erase(notes.begin() + i);
        return;
    }
}
```

---

## 9. 标签、元数据与结构化信息

普通笔记只有内容：

```cpp
string note;
```

结构化笔记还可以有标题、内容、标签等元数据：

```cpp
string title;
string content;
string tag;
```

标签使分类和搜索更容易：

```text
Title: Study OOP
Tag: C++
```

例如按标签匹配：

```cpp
if (tag == "C++") {
    cout << "Matched tag\n";
}
```

---

## 10. 函数、作用域与模块化

### 函数定义与调用

```cpp
void printWelcome()
{
    cout << "Welcome\n";
}

int main()
{
    printWelcome();
}
```

`void` 表示函数不返回值。

有返回值的函数：

```cpp
int add(int a, int b)
{
    return a + b;
}

int total = add(3, 4);
```

### 声明与定义分开

若函数定义在 `main()` 后，需要先声明：

```cpp
void printWelcome();  // 声明

int main()
{
    printWelcome();
}

void printWelcome()   // 定义
{
    cout << "Welcome\n";
}
```

### 局部变量与作用域

```cpp
void example()
{
    int count = 0;  // 只在 example 的 {} 内可用
}
```

模块化的目标是让函数职责明确：

```text
displayMenu()：显示菜单
createNote() ：读取一条笔记
searchNote() ：搜索笔记
saveNote()   ：保存笔记
```

---

## 11. 参数：按值、引用与 `const`

### 按值传递

函数得到副本，修改不影响原变量：

```cpp
void change(int x)
{
    x = 100;
}

int value = 10;
change(value);
// value 仍是 10
```

### 按引用传递：`T&`

函数直接操作原变量：

```cpp
void change(int& x)
{
    x = 100;
}

int value = 10;
change(value);
// value 是 100
```

### 常量引用：`const T&`

适合只读的大对象，例如字符串：不复制，也不允许修改。

```cpp
void display(const string& note)
{
    cout << note << '\n';
}
```

| 参数类型 | 函数能否修改原变量 | 是否复制 |
|---|---:|---:|
| `string note` | 否 | 是 |
| `string& note` | 是 | 否 |
| `const string& note` | 否 | 否 |

---

## 12. 指针、地址与空指针

```cpp
int score = 100;
int* ptr = &score;
```

| 表达式 | 含义 |
|---|---|
| `score` | 值 `100` |
| `&score` | `score` 的地址 |
| `ptr` | 保存的地址，等于 `&score` |
| `*ptr` | 该地址处的值，即 `100` |

```cpp
*ptr = 90;  // 修改 score
cout << score; // 90
```

`*` 的含义取决于位置：

```cpp
int* ptr;  // 声明指针
*ptr = 3;  // 解引用，访问指向对象
```

### 指针参数

```cpp
void increaseScore(int* scorePtr)
{
    if (scorePtr != nullptr) {
        *scorePtr += 10;
    }
}

int score = 90;
increaseScore(&score);
```

### `nullptr`

```cpp
int* ptr = nullptr;
```

`nullptr` 不指向有效对象，不能解引用：

```cpp
// cout << *ptr;  // 未定义行为，可能崩溃
```

先检查：

```cpp
if (ptr != nullptr) {
    cout << *ptr;
}
```

### 指针与引用对比

- 引用是对象别名，通常必须绑定有效对象，使用时直接写变量名。
- 指针保存地址，可以是 `nullptr`，可改为指向别处，访问目标时用 `*`。

---

## 13. `struct`、`class`、对象与封装

两者都能有数据成员、成员函数、构造函数等。默认权限不同：

```cpp
struct Point
{
    int x;  // 默认 public
};

class Note
{
    string title;  // 默认 private
};
```

`public`：类外可访问；`private`：只能被类自己的成员函数访问。

```cpp
class Note
{
private:
    string title;

public:
    void setTitle(const string& value)
    {
        title = value;
    }

    const string& getTitle() const
    {
        return title;
    }
};
```

```cpp
Note note;
note.setTitle("Learn C++");
cout << note.getTitle() << '\n';
```

### `this`

非静态成员函数中，`this` 指向当前对象：

```cpp
void setTitle(const string& title)
{
    this->title = title;
}
```

左边是成员变量，右边是参数。通常成员和参数不同名时可以省略 `this->`。

### 成员函数末尾的 `const`

```cpp
void display() const
{
    cout << title;
}
```

表示该函数不修改当前对象。只读函数如 getter、`display()`、比较函数通常应加 `const`。

---

## 14. 构造函数、析构函数与 RAII

### 构造函数

对象创建时自动调用；名称等于类名，没有返回类型。

```cpp
class Note
{
private:
    string title;

public:
    Note() : title("Untitled")
    {
    }

    Note(const string& noteTitle) : title(noteTitle)
    {
    }
};
```

```cpp
Note a;          // 调用 Note()
Note b("Study"); // 调用 Note(string)
```

参数列表不同的同名函数叫**重载**。

### 成员初始化列表

```cpp
Book(const string& newTitle, int newPages)
    : title(newTitle), pages(newPages)
{
}
```

冒号后的内容在构造函数体执行前直接初始化成员。对于 `string` 等对象，它通常比先默认构造再赋值更直接；`const` 成员和引用成员必须使用初始化列表。

### 析构函数

对象离开作用域时自动调用：

```cpp
class Logger
{
public:
    ~Logger()
    {
        cout << "Destroyed\n";
    }
};

void work()
{
    Logger logger;
}  // logger 在这里析构
```

析构函数名为 `~类名()`，无返回类型、无参数、不能重载。

### RAII

Resource Acquisition Is Initialization：资源跟随对象生命周期管理。

```cpp
void save()
{
    ofstream file("notes.txt");
    file << "Saved\n";
}  // file 自动关闭
```

---

## 15. 运算符重载与友元函数

运算符重载不创造新符号，而是定义现有运算符对自定义类型的含义。

```cpp
class Counter
{
private:
    int value;

public:
    Counter(int initial) : value(initial) {}

    Counter operator+(const Counter& other) const
    {
        return Counter(value + other.value);
    }
};
```

```cpp
Counter a(3);
Counter b(7);
Counter c = a + b;
```

### `operator==`

```cpp
bool operator==(const Note& other) const
{
    return title == other.title;
}
```

### `friend` 与 `operator<<`

友元函数不是成员函数，但可访问私有成员：

```cpp
class Note
{
private:
    string title;

public:
    Note(const string& value) : title(value) {}

    friend ostream& operator<<(ostream& out, const Note& note)
    {
        out << note.title;
        return out;
    }
};
```

```cpp
Note note("C++");
cout << note << '\n';
```

`operator<<` 常是非成员友元，因为 `cout << note` 的左操作数是 `ostream`，不是 `Note`。

---

## 16. 继承、虚函数与多态

### 继承：is-a 关系

```cpp
class Animal
{
public:
    void eat() const
    {
        cout << "Eating\n";
    }
};

class Dog : public Animal
{
public:
    void bark() const
    {
        cout << "Woof\n";
    }
};
```

`Dog is an Animal`，因此 `Dog` 可使用继承来的 `eat()`。

### 虚函数与重写

```cpp
class Animal
{
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        cout << "Woof\n";
    }
};
```

- `virtual`：基类函数支持动态绑定。
- `= 0`：纯虚函数，基类成为抽象类，不能直接创建对象。
- `override`：确认派生函数确实重写基类虚函数；签名不一致时编译器会报错。
- 基类和派生类的 `const` 必须一致。

### 多态

```cpp
Dog dog;
Animal* animal = &dog;
animal->speak();  // Woof
```

变量类型是 `Animal*`，但实际对象是 `Dog`，因此调用 `Dog::speak()`。

多态基类通常应有虚析构函数：

```cpp
virtual ~Animal() = default;
```

这样 `delete animal;` 才能正确析构派生对象。

---

## 17. 容器、组合与 `NoteManager`

### `vector`

`vector` 是可变长度数组：

```cpp
vector<int> scores;
scores.push_back(90);
scores.push_back(100);

cout << scores[0];  // 90
cout << scores.size();
```

常用成员：

| 写法 | 作用 |
|---|---|
| `push_back(value)` | 在末尾添加 |
| `size()` | 元素数量 |
| `empty()` | 是否为空 |
| `erase(position)` | 删除某个位置元素 |
| `begin()` | 第一个元素的位置 |
| `end()` | 最后一个元素之后的位置 |

### 组合：has-a 关系

```cpp
class NoteManager
{
private:
    vector<Note> notes;
};
```

这表示 `NoteManager has Notes`。管理器不是笔记，不应写成继承。

### 职责分离与委托

```cpp
class Note
{
public:
    void display() const;
    bool contains(const string& keyword) const;
};

class NoteManager
{
private:
    vector<Note> notes;

public:
    void addNote(const Note& note);
    void removeNote(const string& title);
    void search(const string& keyword) const;
    void displayAll() const;
};
```

```cpp
void NoteManager::displayAll() const
{
    for (const Note& note : notes) {
        note.display();
    }
}
```

- `Note` 负责一条笔记自身的数据和显示。
- `NoteManager` 负责集合的添加、删除、搜索、遍历。
- `main()` 负责菜单与程序流程。
- 管理器调用 `note.display()` 是**委托**。

### 高内聚与低耦合

- 高内聚：一个类内部的功能紧密相关。
- 低耦合：类之间只依赖必要的公开接口，不依赖内部实现。
- 目标是高内聚、低耦合；它们不是同一维度的相反词。

---

## 18. 工厂模式与对象所有权

工厂模式把“创建什么对象”集中在工厂中。

```cpp
class NoteFactory
{
public:
    Note* create(const string& type)
    {
        if (type == "text") {
            return new TextNote;
        }
        if (type == "todo") {
            return new TodoNote;
        }
        return nullptr;
    }
};
```

使用者只依赖抽象基类：

```cpp
Note* note = factory.create(type);

if (note != nullptr) {
    note->display();
}
```

### 为什么使用工厂

```text
用户选择类型
  -> NoteFactory 创建 TextNote / TodoNote / ReminderNote
  -> 返回 Note*
  -> NoteManager 保存并使用 Note*
```

- 创建逻辑集中，避免在多个位置复制 `if(type == ...)`。
- 客户端依赖 `Note` 抽象，不直接依赖具体类。
- 新增派生类型时，管理器的多态显示逻辑通常不必改变。

### 裸指针与 `unique_ptr`

若使用 `new`，必须在恰当位置 `delete`：

```cpp
Note* note = factory.create("text");
delete note;
```

更安全的现代写法：

```cpp
#include <memory>

unique_ptr<Note> note = make_unique<TextNote>();
```

`unique_ptr` 离开作用域时自动删除对象，减少内存泄漏风险。

---

## 19. Context Builder、检索与 RAG

第 18 课的重点是系统架构，不是新的基础 C++ 语法。

```text
问题
  -> Retrieval（检索相关笔记）
  -> Context Building（组织上下文）
  -> Generation（基于上下文生成回答）
```

职责可分为：

```text
NoteManager
  -> 保存笔记、按关键词或标签检索

ContextBuilder
  -> 将相关笔记整理为一段上下文/提示词

LLM / Generation 模块
  -> 使用上下文回答问题
```

例如用户提问“引用和指针的区别”：

1. `NoteManager` 找到“引用”和“指针”相关笔记。
2. `ContextBuilder` 把它们拼接为清晰资料。
3. 生成模块基于这些资料回答。

这叫 RAG：`Retrieval-Augmented Generation`，即检索增强生成。

---

## 20. 容易混淆的符号速查

| 符号/关键字 | 位置 | 含义 |
|---|---|---|
| `=` | `x = 3` | 赋值 |
| `==` | `x == 3` | 比较是否相等 |
| `&` | `&value` | 取变量地址 |
| `&` | `int& ref` | 声明引用 |
| `*` | `int* ptr` | 声明指针 |
| `*` | `*ptr` | 解引用指针 |
| `::` | `NoteManager::displayAll` | 指明函数属于哪个类/命名空间 |
| `->` | `ptr->display()` | 通过指针访问成员 |
| `.` | `note.display()` | 通过对象访问成员 |
| `:` | `: title(value)` | 构造函数成员初始化列表 |
| `const` | 参数前 | 不修改该参数 |
| `const` | 成员函数末尾 | 不修改当前对象 |
| `virtual` | 基类成员函数 | 支持多态 |
| `override` | 派生类成员函数末尾 | 重写基类虚函数 |
| `= 0` | 虚函数声明 | 纯虚函数 |
| `= default` | 特殊成员函数 | 让编译器生成默认实现 |

---

## 21. 推荐学习顺序

1. 能独立写变量、输入输出、`if` 和 `while`。
2. 熟练处理 `cin` 和 `getline` 的换行问题。
3. 能用文件保存和读取完整文本。
4. 能用 `string::find` 做关键词搜索。
5. 能把重复代码拆成函数，并选择值/引用/常量引用参数。
6. 理解地址、指针、引用和 `nullptr`。
7. 能写含 `private` 数据、`public` 成员函数的类。
8. 理解构造、析构、初始化列表和 `const` 成员函数。
9. 能正确使用继承、虚函数、`override` 和虚析构函数。
10. 能用 `NoteManager` 管理集合，并将创建工作交给 `NoteFactory`。
11. 最后理解检索、上下文构建和生成之间的职责边界。
