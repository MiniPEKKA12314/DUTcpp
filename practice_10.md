# 第 10 课测评

## 引用与数据流 - CLI Notes v6 基础

### 涉及主题

- 为什么数据流很重要
- 函数参数
- 按值传递
- 按引用传递
- 引用变量（`&`）
- 输入参数与输出参数
- 避免不必要的复制
- 函数之间的共享状态
- 数据所有权与修改
- 将 CLI Notes 重构为数据流架构

# 第 A 部分：单项选择题（10 分）

### 1. 按引用传递主要解决什么问题？

A. 它创建更多变量

B. 它允许函数修改原始数据

C. 它阻止函数调用

D. 它不再需要字符串

**答案：** 

---

### 2. C++ 中用哪个符号声明引用参数？

A. *

B. #

C. &

D. @

**答案：** 

---

### 3. 思考：

```
void update(string note)
{
note ="Updated";
}
```

原始变量会发生什么？

A. 它变成 `"Updated"`

B. 它被删除

C. 它保持不变

D. 编译失败

**答案：** 

---

### 4. 哪个函数参数会把原始字符串传入函数？

A. string note

B. string* note

C. string& note

D. const string note

**答案：** 

---

### 5. 模块化数据流的主要优势是什么？

A. 函数可以清晰、可预测地通信

B. 程序可以不使用变量运行

C. 文件变得不必要

D. 循环变得更快

**答案：** 

---

### 6. 哪个函数最可能需要引用参数？

A. printWelcome()

B. displayMenu()

C. createNote(string&note)

D. showVersion()

**答案：** 

---

### 7. 关于引用，哪个说法正确？

A. 引用总是创建副本

B. 引用可以指向已有变量

C. 引用只能用于整数

D. 引用是文件

**答案：** 

---

### 8. 为什么按值传递可能效率低？

A. 它会导致大型对象被反复复制

B. 它会删除数据

C. 它会阻止循环

D. 它会禁用函数

**答案：** 

---

### 9. 哪种设计最能支持不断增长的 CLI Notes 系统？

A. 每个函数都创建自己的无关笔记

B. 函数通过参数共享并更新笔记数据

C. 所有代码都放在 `main()` 中

D. 函数之间不传递任何数据

**答案：** 

---

### 10. 从第 9 课到第 10 课，最大的概念变化是什么？

A. 从函数到图形

B. 从代码组织到函数之间的数据移动

C. 从文件到数据库

D. 从字符串到整数

**答案：** 

# 第 B 部分：填空题（10 分）

### 1. 按 __________ 传递的参数会创建原始值的副本。

**答案：** 

---

### 2. 按 __________ 传递的参数允许修改原始变量。

**答案：** 

---

### 3. 引用使用的符号是 __________。

**答案：** 

---

### 4. 高效的软件设计要求函数之间有清晰的 __________ 流。

**答案：** 

---

### 5. 通过引用传递大型字符串可以避免不必要的 __________。

**答案：** 

---

# 第 C 部分：判断题（10 分）

### 1. 按值传递会创建实参的独立副本。

**答案：** 

---

### 2. 引用参数指向原始变量。

**答案：** 

---

### 3. 修改按值传递的参数会改变原始变量。

**答案：** 

---

### 4. 当多个函数需要处理同一条笔记时，引用很有用。

**答案：** 

---

### 5. 下面的参数是按引用传递：

```
string& note
```

**答案：** 

---

### 6. 每个函数都应该使用按引用传递。

**答案：** 

---

### 7. 数据流描述信息如何在程序中移动。

**答案：** 

---

### 8. 按值传递字符串可能比按引用传递消耗更多内存。

**答案：** 

---

### 9. 引用变量必须引用一个已经存在的对象。

**答案：** 

---

### 10. 良好的软件架构既依赖模块化函数，也依赖清晰的数据流。

**答案：** 

# 第 D 部分：代码阅读（10 分）

### 问题 1 输出是什么？

```
void change(intx)
{
x =100;
}

int main()
{
int value =10;
change(value);

cout<<value;
}
```

**答案**

---

### 问题 2 输出是什么？

```
void change(int&x)
{
x =100;
}

intmain()
{
int value =10;
change(value);

cout<<value;
}
```

**答案**

---

### 问题 3 `note` 的最终内容是什么？

```
void addTag(string&note)
{
note+=" #Programming";
}

int main()
{
string note ="Learn Functions";
addTag(note);
}
```

**答案**

---

### 问题 4 这里存在什么设计问题？

```
void createNote()
{
string note;
getline(cin,note);
}
```

**答案**

---

### 问题 5 哪种参数类型更合适？

```
void viewNote(__________note)
{
cout<<note;
}
```

**答案**

---

# 第 E 部分：简答题（10 分）

### 1. 解释按值传递和按引用传递之间的区别。

**示例答案**

---

### 2. 为什么数据流在多函数应用中很重要？

**示例答案**

---

### 3. 什么时候应该优先使用按引用传递？

**示例答案**

---

# 第 F 部分：编程题（20 分）

## 问题 1 - 更新用户名

编写一个函数：

```
void updateUsername(string& username)
```

将用户名改为：

```
GuestUser
```

调用该函数并显示更新后的值。

---

## 问题 2 - 笔记编辑器

创建一个函数：

```
void appendReminder(string& note)
```

在笔记末尾追加：

```
[Review Tomorrow]
```

### 示例

之前：

```
Study Functions
```

之后：

```
Study Functions [Review Tomorrow]
```

---

## 问题 3 - 不修改地查看

编写一个函数：

```
void viewNote(conststring&note)
```

显示一条笔记，但不修改它。

解释为什么这里 `const` 有用。

---

## 问题 4 - 多函数数据流

创建三个函数：

```
void createNote(string&note);
void addTag(string&note);
void displayNote(conststring&note);
```

工作流程：

1. 创建一条笔记。
2. 添加一个标签。
3. 显示最终结果。

所有函数都应操作同一个 `note` 变量。

---

## 问题 5 - CLI Notes v6 基础（挑战）

重构笔记系统，使所有主要操作都通过参数接收笔记数据。

建议结构：

```cpp
void createNote(string& note);
void viewNote(const string& note);
void saveNote(const string& note);
void loadNote(string& note);
void searchNote(const string& note);
```

要求：

- 避免使用全局变量。
- 在合适的地方使用引用。
- 对只读操作使用 `const` 引用。
- 展示函数之间清晰的数据流。

---

# 第 G 部分：设计与思考挑战（可选加分）

### 问题 比较下面两种设计。

### 设计 A

```
string note;

void createNote()
{
getline(cin,note);
}

void viewNote()
{
cout<<note;
}
```

### 设计 B

```
void createNote(string& note)
{
getline(cin,note);
}

void viewNote(const string& note)
{
cout<<note;
}
```

为什么设计 B 通常被认为是更好的软件工程实践？

### 示例答案

---

# 教师备注

第 10 课引入了软件架构中最重要的思想之一：

```
Functions
      ->
Functions + Data
      ->
System Design
```

学生应该理解：

> **函数定义行为，但数据流把行为连接成一个可工作的系统。**
> 

CLI Notes 项目现在从一组函数演变为一种协调架构，信息会有意地在组件之间流动。

本课为以下内容打下基础：

- 类和对象
- 封装
- API
- 软件架构
- 大规模系统设计

这些将在后续课程中继续探索。
