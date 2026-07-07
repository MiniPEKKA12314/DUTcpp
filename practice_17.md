# 第 17 课测评

## 工厂模式 - 清晰的对象创建

### 涉及主题

- 为什么需要工厂模式
- 直接创建对象的问题
- 封装对象创建
- 工厂类和工厂方法
- 工厂与多态
- 低耦合
- 开闭原则（OCP）
- 依赖抽象而不是具体类
- 使用 `NoteFactory` 扩展 CLI Notes 系统

---

# 第 A 部分：单项选择题（10 分）

### 1. 工厂模式的主要目的是什么？

A. 让继承变得不必要

B. 集中并封装对象创建

C. 消除构造函数

D. 替代虚函数

**答案：** 

---

### 2. 哪个说法最能描述工厂模式？

A. 每个类都创建自己。

B. 对象创建被委托给专门的工厂。

C. 对象只能在 `main()` 中创建。

D. 每个类都必须继承自 `Factory`。

**答案：** 

---

### 3. 为什么通常不鼓励在整个程序中到处直接使用 `new`？

A. 它总是导致内存泄漏。

B. 它让程序与具体类紧密耦合。

C. 它阻止继承。

D. 它禁用多态。

**答案：** 

---

### 4. 通常应该由哪个类创建不同类型的笔记？

A. TextNote

B. TodoNote

C. NoteFactory

D. Note

**答案：** 

---

### 6. 对于创建不同笔记类型的工厂，哪种返回类型最合适？

A. TextNote

B. TodoNote

C. Note*

D. string

**答案：** 

---

### 7. 关于工厂方法，哪个说法正确？

A. 它负责创建对象。

B. 它替代构造函数。

C. 它必须是虚函数。

D. 它只能创建一种对象类型。

**答案：** 

---

### 8. 什么是低耦合？

A. 每个类都依赖所有其他类。

B. 类通过定义良好的接口交互，并尽量少了解彼此的实现。

C. 类只包含 private 成员。

D. 类不能通信。

**答案：** 

---

### 9. 使用工厂时，哪种更改最容易？

A. 用一个具体实现替换另一个具体实现。

B. 删除继承。

C. 消除虚函数。

D. 避免构造函数。

**答案：** 

---

### 10. 工厂模式最大的架构贡献是什么？

A. 分离 **对象创建** 与 **对象使用**

B. 让每个类都变成抽象类

C. 删除所有构造函数

D. 消除多态

**答案：** 

---

# 第 B 部分：填空题（10 分）

### 1. 工厂封装对象的 __________。

**答案：** 

---

### 2. 工厂模式有助于减少类之间的 __________。

**答案：** 

---

### 3. 工厂通常返回指向 __________ 类的指针或引用。

**答案：** 

---

### 4. 开闭原则鼓励软件对 __________ 开放，对修改关闭。

**答案：** 

---

### 5. 客户端从工厂请求对象，而不是 __________ 创建它。

**答案：** 

---

# 第 C 部分：判断题（10 分）

### 1. 工厂模式改变对象如何创建，而不是改变对象如何行为。

**答案：** 

---

### 2. 工厂消除了对构造函数的需要。

**答案：** 

---

### 3. 客户端通常不需要知道实例化的是哪个具体类。

**答案：** 

---

### 4. 工厂可以通过同一个基类接口返回不同派生对象。

**答案：** 

---

### 5. 使用工厂通常会提高可维护性。

**答案：** 

---

### 6. 每个项目都应该恰好有一个工厂类。

**答案：** 

---

### 7. 工厂内部可能使用构造函数创建对象。

**答案：** 

---

### 8. 工厂模式常与多态一起使用。

**答案：** 

---

### 9. 用工厂替换每个构造函数总是良好设计。

**答案：** 

---

### 10. 工厂模式有助于让代码更容易扩展新对象类型。

**答案：** 

---

# 第 D 部分：代码阅读（10 分）

### 问题 1 思考下面的代码：

```
class NoteFactory
{
public:
Note* createNote();
};
```

`NoteFactory` 的主要职责是什么？

**答案**

---

### 问题 2 展示了什么设计原则？

```
Note* note =factory.createNote();
```

而不是

```
Note* note =new TextNote();
```

**答案**

---

### 问题 3

假设：

```
Note* note =factory.create("todo");
```

最可能返回哪个对象？

**答案**

---

### 问题 4 为什么下面的设计不够灵活？

```
if(type=="text")
	note =new TextNote();
elseif(type=="todo")
	note =new TodoNote();
elseif(type=="reminder")
	note =new ReminderNote();
```

放在 `main()` 中。

**答案**

---

### 问题 5 展示了什么关系？

```
Note* note =factory.create(type);
note->display();
```

**答案**

---

# 第 E 部分：简答题（10 分）

### 1. 为什么大型软件系统经常使用工厂模式？

**示例答案**

---

### 2. 解释工厂模式如何支持开闭原则。

**示例答案**

---

### 3. 工厂模式和多态如何互相配合？

**示例答案**

---

# 第 F 部分：编程题（20 分）

## 问题 1 - 构建你的第一个工厂

创建以下类：

```
class Animal
{
public:
virtual void speak() =0;
virtual ~Animal() =default;
};

class Dog :public Animal;
class Cat :public Animal;

class AnimalFactory
{
public:
Animal* createAnimal(const string& type);
};
```

要求：

- 根据用户输入创建 `Dog` 或 `Cat`。
- 通过 `Animal*` 调用 `speak()`。

---

## 问题 2 - Shape 工厂

创建：

```
class Shape
{
public:
virtual void draw() =0;
};

class Circle;
class Rectangle;

class ShapeFactory;
```

要求：

- 工厂创建请求的形状。
- 使用 `Shape*` 展示多态绘制。

---

## 问题 3 - 重构对象创建

下面代码多次出现：

```
if(type=="text")
	note =new TextNote();
elseif(type=="todo")
	note =new TodoNote();
```

将其重构为：

```
class NoteFactory
{
public:
Note* create(const string& type);
};
```

解释这如何改善设计。

---

## 问题 4 - 扩展工厂

假设 `NoteFactory` 已经支持：

- `TextNote`
- `TodoNote`

添加一个新类：

```
ReminderNote
```

更新工厂，使它可以创建新的笔记类型，且 **不需要修改任何客户端代码**。

---

## 问题 5 - CLI Notes 工厂（挑战）

设计下面的架构：

```
class Note
{
public:
virtual void display() const =0;
virtual ~Note() =default;
};

class TextNote :public Note;
class TodoNote :public Note;
class ReminderNote :public Note;

class NoteFactory
{
public:
Note* create(const string& type);
};

class NoteManager
{
private:
vector<Note*> notes;
};
```

要求：

- 用户从菜单选择笔记类型。
- `NoteManager` 从 `NoteFactory` 请求对象。
- 通过 `Note*` 存储所有笔记。
- 以多态方式显示所有笔记。

**挑战扩展（推荐）：**

将裸指针替换为：

```
std::unique_ptr<Note>
```

解释为什么这种设计更安全。

---

# 第 G 部分：设计与思考挑战（可选加分）

### 问题 比较下面两种设计。

### 设计 A

```
if(type=="text")
	note =new TextNote();
elseif(type=="todo")
	note =new TodoNote();
elseif(type=="reminder")
	note =new ReminderNote();
```

### 设计 B

```
NoteFactory factory;

Note* note =factory.create(type);
```

为什么设计 B 通常被认为在面向对象软件设计中更好？

### 示例答案

---

# 教师备注

第 17 课介绍了面向对象编程中最常用的 **创建型设计模式** 之一。

课程的架构演进现在是：

```
Classes
      ->
Objects
      ->
Inheritance
      ->
Polymorphism
      ->
Managers
      ->
Factories
```

学生应该认识到，**创建对象也是一种设计职责**。随着系统增长，把 `new` 表达式散落在代码库中会增加耦合，并让维护变得更困难。

关键收获是：

> **工厂模式将对象创建与对象使用分离，使软件依赖抽象而不是具体实现。**
> 

本课为更高级的软件工程主题打下基础，包括抽象工厂、建造者、依赖注入、插件架构和控制反转（IoC）。
