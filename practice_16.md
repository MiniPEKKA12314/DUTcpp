# 第 16 课测评

## `NoteManager` - 从程序到系统架构

### 涉及主题

- 为什么引入管理器类
- 职责分离
- 组合（“has-a” 关系）
- 管理对象集合
- 系统层面的封装
- 设计 `NoteManager`
- 委托
- 高内聚和低耦合
- 将 CLI Notes 重构为分层架构
- 为可扩展软件系统做准备

---

# 第 A 部分：单项选择题（10 分）

### 1. `NoteManager` 的主要职责是什么？

A. 存储一条笔记

B. 管理并协调多个 `Note` 对象

C. 替代 `Note` 类

D. 只处理用户输入

**答案：** 

---

### 2. 哪种面向对象关系最能描述 `NoteManager` 和 `Note`？

A. 继承（“is-a”）

B. 组合（“has-a”）

C. 友元关系

D. 多态

**答案：**

---

### 3. 为什么引入管理器类有益？

A. 它减少类的数量。

B. 它集中系统级职责并改善组织。

C. 它消除构造函数。

D. 它不再需要封装。

**答案：** 

---

### 4. 哪个数据成员最适合放在 `NoteManager` 中？

A. int age;

B. vector<Note> notes;

C. double area;

D. char letter;

**答案：** 

---

### 5. 哪个职责属于 `Note` 类，而不是 `NoteManager`？

A. 搜索所有笔记

B. 管理笔记集合

C. 显示单条笔记的内容

D. 协调所有笔记的文件加载

**答案：** 

---

### 6. 面向对象编程中的委托是什么？

A. 用全局变量替代对象

B. 将职责交给最适合执行它的对象

C. 让每个类负责每个任务

D. 自动调用构造函数

**答案：** 

---

### 7. 哪个设计原则鼓励每个类只有一个主要职责？

A. 单一职责原则（SRP）

B. 动态绑定

C. 运算符重载

D. 指针算术

**答案：** 

---

### 8. 哪种设计更可扩展？

A. 一个包含数百行代码的 `main()` 函数

B. 一个 `NoteManager` 类协调多个专门类

C. 到处访问的多个全局变量

D. 所有函数都放在一个源文件中

**答案：** 

---

### 9. 高内聚意味着：

A. 一个类有许多无关职责。

B. 一个类专注于紧密相关的职责。

C. 每个类都严重依赖所有其他类。

D. 所有成员函数都是 public。

**答案：** 

---

### 10. 第 16 课最大的概念改进是什么？

A. 从单个类转向软件架构思维

B. 用结构体替代类

C. 消除对象

D. 避免使用 vector

**答案：** 

---

# 第 B 部分：填空题（10 分）

### 1. `NoteManager` __________ 一个笔记集合。

**答案：** 

---

### 2. 组合表示一种 __________-a 关系。

**答案：** 

---

### 3. 委托意味着把工作分配给最 __________ 的对象。

**答案：** 

---

### 4. 设计良好的类应该具有 __________ 内聚。

**答案：** 

---

### 5. 减少类之间不必要的依赖称为低 __________。

**答案：** 

---

# 第 C 部分：判断题（10 分）

### 1. 管理器类应该包含应用程序的每一部分逻辑。

**答案：** 

---

### 2. 组合允许一个对象拥有或包含其他对象。

**答案：** 

---

### 3. `NoteManager` 应该知道如何管理笔记，而每个 `Note` 应该知道如何管理自己。

**答案：** 

---

### 4. 高耦合通常让软件更容易维护。

**答案：** 

---

### 5. 只有一个清晰职责的类通常更容易理解和测试。

**答案：** 

---

### 6.`main()` 应该协调程序，而不是直接实现每个功能。

**答案：** 

---

### 7. 在建模 “has-a” 关系时，组合通常优于继承。

**答案：** 

---

### 8. 如果 `NoteManager` 存储 `vector<Note>`，这种关系就是继承。

**答案：** 

---

### 9. 委托有助于减少重复逻辑。

**答案：** 

---

### 10. 设计良好的架构通常更容易扩展新功能。

**答案：** 

---

# 第 D 部分：代码阅读（10 分）

### 问题 1 思考下面的类：

```
class NoteManager
{
private:
vector<Note> notes;
};
```

`NoteManager` 和 `Note` 之间是什么关系？

**答案**

---

### 问题 2 下面代码存在什么设计问题？

```
int main()
{
// 500 lines of code
}
```

**答案**

---

### 问题 3 展示了什么设计原则？

```
manager.addNote(note);
```

而不是在 `main()` 中：

```
notes.push_back(note);
```

**答案**

---

### 问题 4 为什么下面的设计更好？

```
class Note
{
public:
void display() const;
};

class NoteManager
{
public:
void displayAll() const;
};
```

**答案**

---

### 问题 5 展示了哪个设计原则？

```
manager.displayAll();
```

其中 `displayAll()` 会对每条笔记调用 `display()`。

**答案** 

---

# 第 E 部分：简答题（10 分）

### 1. 为什么引入 `NoteManager` 比直接在 `main()` 中存储笔记更好？

**示例答案**

---

### 2. 解释继承和组合之间的区别。

**示例答案**

---

### 3. 为什么高内聚和低耦合很重要？

**示例答案**

---

# 第 F 部分：编程题（20 分）

## 问题 1 - 构建简单管理器

创建一个类：

```
class Book
{
private:
string title;
public:
Book(string title);
void display()const;
};

class Library
{
private:
vector<Book> books;

public:
void addBook(const Book& book);
void displayAll()const;
};
```

要求：

- 添加几本书。
- 显示所有书。

---

## 问题 2 - 在集合中搜索

扩展 `NoteManager` 类，添加：

```
bool containsTitle(const string& title)const;
```

如果存在指定标题的笔记，该函数返回 `true`。

---

## 问题 3 - 删除笔记

实现：

```
void removeNote(const string& title);
```

要求：

- 搜索集合。
- 删除第一条匹配的笔记。
- 如果没有找到笔记，打印合适的消息。

---

## 问题 4 - 分离职责

假设存在下面的代码：

```
class Note
{
public:
void saveToFile();
void loadFromFile();
void display();
void search();
void sort();
void backup();
};
```

通过决定哪些职责应保留在 `Note` 中、哪些应移动到 `NoteManager`，来重构设计。

简要解释你的设计决定。

---

## 问题 5 - CLI Notes 架构（挑战）

设计下面的架构：

```
class Note
{
public:
void display()const;
};

class NoteManager
{
public:
void addNote(const Note&);
void removeNote(const string&);
void search(const string&)const;
void displayAll()const;
};

int main()
{
NoteManager manager;
}
```

要求：

- 将所有笔记存储都放在 `NoteManager` 内。
- 不要从 `main()` 直接访问内部容器。
- 添加一个菜单，反复允许用户：
    - 添加笔记
    - 删除笔记
    - 搜索笔记
    - 显示所有笔记
    - 退出

---

# 第 G 部分：设计与思考挑战（可选加分）

### 问题 比较下面两种设计。

### 设计 A

```
int main()
{
vector<Note>notes;

// add
// remove
// search
// display
// save
// load
}
```

### 设计 B

```
class NoteManager
{
private:
vector<Note> notes;

public:
void addNote();
void removeNote();
void search();
void displayAll();
void save();
void load();
};

int main()
{
NoteManager manager;
}
```

随着程序增长，哪种设计更容易维护？解释你的答案。

**示例答案**

---

# 教师备注

第 16 课标志着从 **面向对象编程** 到 **软件架构** 的转变。

课程演进现在是：

```
Variables
      ->
Functions
      ->
Classes
      ->
Objects
      ->
Inheritance
      ->
Managers
      ->
Software Architecture
```

学生应该理解，写好软件 **不只是定义类**，还包括组织这些类如何协作。

关键收获是：

> **良好的架构会为每个类分配清晰职责，并让对象通过定义良好的接口协作。**
> 

本课为更大的软件系统做准备，这些系统包含多个交互类、设计模式（如 Factory、Strategy 和 Observer）、模型-视图-控制器（MVC），以及专业软件工程实践。
