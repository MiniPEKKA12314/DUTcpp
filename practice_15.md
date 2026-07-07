# 第 15 课测评

## 继承、虚函数与多态

### 涉及主题

- 为什么需要继承
- 基类和派生类
- `public` 继承关系
- 通过继承复用代码
- 函数重写
- `virtual` 关键字
- 动态绑定（后期绑定）
- 运行时多态
- 虚析构函数
- 将继承应用到 CLI Notes 项目

---

# 第 A 部分：单项选择题（10 分）

### 1. 继承的主要目的是什么？

A. 增加变量数量

B. 允许一个类复用并扩展另一个类

C. 替代构造函数

D. 避免使用函数

**答案：** 

---

### 2. 在下面的声明中，

```
class TextNote :public Note
{
};
```

哪个类是基类？

A. `TextNote`

B. `public`

C. `Note`

D. 以上都不是

**答案：** 

---

### 3. 哪个关键字启用运行时多态？

A. override

B. virtual

C. friend

D. const

**答案：** 

---

### 4. 什么是函数重写？

A. 编写两个名称不同的函数

B. 在派生类中为虚函数定义新的实现

C. 调用一个函数两次

D. 重载运算符

**答案：** 

---

### 5. 思考：

```
class Animal
{
public:
virtual void speak();
};

class Dog :public Animal
{
public:
void speak();
};
```

如果一个 `Animal*` 指向 `Dog` 对象并调用 `speak()`，哪个函数会执行？

A. `Animal::speak()`

B. `Dog::speak()`

C. 两者都会

D. 两者都不会

**答案：** 

---

### 6. 什么是多态？

A. 一个变量同时存储多个值

B. 使用一个接口处理不同对象类型的能力

C. 一个类中有多个构造函数

D. 只使用指针

**答案：** 

---

### 7. 用于多态的基类通常为什么应该有虚析构函数？

A. 为了让构造函数变成虚函数

B. 为了确保通过基类指针删除对象时，派生类析构函数能被正确调用

C. 为了提高执行速度

D. 为了减少内存使用

**答案：** 

---

### 8. 关于继承，哪个说法正确？

A. 派生类会自动失去基类的所有成员。

B. 派生类继承基类中可访问的成员。

C. 继承替代封装。

D. 每个类都必须继承另一个类。

**答案：** 

---

### 9. 哪种符号/类型常用于以多态方式存储不同派生对象？

A. Animal

B. Animal*

C. char

D. int

**答案：** 

---

### 10. 第 15 课的主要概念贡献是什么？

A. 程序可以通过共同接口处理不同对象类型。

B. 构造函数变得可选。

C. 类替代函数。

D. 对象不再需要数据成员。

**答案：** 

---

# 第 B 部分：填空题（10 分）

### 1. 被继承的类称为 __________ 类。

**答案：** 

---

### 2. 从另一个类继承的类称为 __________ 类。

**答案：** 

---

### 3. 用于启用动态分派的关键字是 __________。

**答案：** 

---

### 4. 为继承来的虚函数提供新实现称为 __________。

**答案：** 

---

### 5. 通过一个共同接口处理不同派生对象的能力称为 __________。

**答案：** 

---

# 第 C 部分：判断题（10 分）

### 1. 派生类可以添加新的数据成员和成员函数。

**答案：** 

---

### 2. 继承总是违反封装。

**答案：** 

---

### 3. 函数必须在基类中声明为 `virtual`，才能支持运行时多态。

**答案：** 

---

### 4. C++ 语言要求必须使用 `override` 关键字。

**答案：** 

---

### 5. 没有 `virtual` 时，通过基类指针调用函数会使用静态绑定。

**答案：** 

---

### 6. 基类指针可以指向派生类对象。

**答案：** 

---

### 7. 如果基类没有虚析构函数，通过基类指针删除派生对象可能导致未定义行为。

**答案：** 

---

### 8. 派生类会自动继承基类的构造函数。

**答案：** 

---

### 9. 多态允许同一个函数调用根据对象的实际类型产生不同行为。

**答案：** 

---

### 10. 继承表示一种 “is-a” 关系。

**答案：** 

---

# 第 D 部分：代码阅读（10 分）

### 问题 1 输出是什么？

```
class Animal
{
public:
	void speak(){
		cout<<"Animal";
	}
};

class Dog :public Animal
{};

int main(){
Dog d;
d.speak();
}
```

**答案**

---

### 问题 2 输出是什么？

```
class Animal
{
public:
virtual void speak()
    {
cout<<"Animal";
    }
};

class Dog :public Animal
{
public:
void speak()override
    {
cout<<"Dog";
    }
};

int main()
{
Animal* p =new Dog();
p->speak();
}
```

**答案**

---

### 问题 3 下面代码有什么问题？

```
class Shape{
public:
virtual double area();
};

class Circle :public Shape
{
public:
double Area() override;
};
```

**答案**

---

### 问题 4 为什么推荐下面的声明？

```
virtual~Shape() {}
```

**答案**

---

### 问题 5 下面展示了什么编程原则？

```
Shape* shape =new Circle();
shape->draw();
```

**答案**

---

# 第 E 部分：简答题（10 分）

### 1. 解释继承和多态之间的区别。

**示例答案**

---

### 2. 为什么虚函数很重要？

**示例答案**

---

### 3. 为什么继承常被描述为 “is-a” 关系？

**示例答案**

---

# 第 F 部分：编程题（20 分）

## 问题 1 - 构建你的第一个继承层次

创建：

```
class Animal
{
public:
void eat();
};

class Dog :public Animal
{
public:
void bark();
};
```

要求：

- 创建一个 `Dog` 对象。
- 同时调用 `eat()` 和 `bark()`。

---

## 问题 2 - 函数重写

创建：

```
class Employee
{
public:
virtual void work();
};

class Programmer :public Employee
{
public:
void work()override;
};
```

要求：

- 重写 `work()`。
- 使用 `Employee*` 展示多态行为。

---

## 问题 3 - Shape 层次结构

创建：

```
class Shape
{
public:
virtual void draw();
};

class Circle :public Shape;
class Rectangle :public Shape;
```

要求：

- 在每个派生类中重写 `draw()`。
- 将两个对象存储在 `Shape*` 数组中。
- 对每个对象调用 `draw()`。

---

## 问题 4 - 虚析构函数练习

创建：

```
class Base
{
public:
virtual ~Base();
};

class Derived :public Base
{
public:
~Derived();
};
```

要求：

- 从两个析构函数中打印消息。
- 通过 `Base*` 删除一个 `Derived` 对象。
- 观察析构顺序。

---

## 问题 5 - CLI Notes 多态（挑战）

重构笔记系统。

建议设计：

```
class Note
{
public:
virtual void display() const =0;
virtual ~Note() = default;
};

class TextNote :public Note
{
    ...
};

class TodoNote :public Note
{
    ...
};

class ReminderNote :public Note
{
    ...
};
```

要求：

- 在每个派生类中以不同方式实现 `display()`。
- 将所有笔记类型存储在 `Note*` 容器中（如果已引入智能指针，也可以用 `std::unique_ptr<Note>`）。
- 使用一个循环显示所有笔记。

---

# 第 G 部分：设计与思考挑战（可选加分）

### 问题 思考两种设计。

### 设计 A

```
class Note
{
public:
string type;

void display();
};
```

在 `display()` 内：

```
if(type=="Text")
{
    ...
}
elseif(type=="Todo")
{
    ...
}
elseif(type=="Reminder")
{
    ...
}
```

### 设计 B

```
class Note
{
public:
virtual void display() const =0;
};

class TextNote :public Note
{
    ...
};

class TodoNote :public Note
{
    ...
};

class ReminderNote :public Note
{
    ...
};
```

为什么设计 B 通常被认为更好？

### 示例答案

---

# 教师备注

第 15 课引入了面向对象编程的定义性特征之一：

```
Class
      ->
Inheritance
      ->
Virtual Functions
      ->
Polymorphism
      ->
Flexible Software Design
```

学生应该理解，继承 **不只是代码复用的方式**。它真正的价值是启用 **多态**，使不同对象类型可以通过共同接口被操作，同时保留各自独特的行为。

关键收获是：

> **继承建模 “is-a” 关系，而虚函数让对象在运行时选择正确的行为。**
> 

本课为高级 OOP 主题做准备，例如抽象类、接口、设计模式（如 Strategy 和 Factory）、泛型编程和大规模软件架构。
