# C++ 综合测评卷

覆盖范围：Practice 1-25  
满分：100 分  
建议时间：120 分钟

## 评分构成

| 题型 | 题数 | 每题分值 | 小计 |
|---|---:|---:|---:|
| 单项选择题 | 20 | 1 分 | 20 分 |
| 判断题 | 20 | 1 分 | 20 分 |
| 填空题 | 20 | 1 分 | 20 分 |
| 简答题 | 15 | 2 分 | 30 分 |
| 编程题 | 2 | 5 分 | 10 分 |
| **总计** |  |  | **100 分** |

---

# 一、单项选择题（共 20 题，每题 1 分，共 20 分）

### 1. 每个 C++ 程序的入口函数是：

A. start()  
B. run()  
C. main()  
D. begin()

### 2. 下列哪个变量声明合法？

A. int 2score;  
B. int class;  
C. int playerScore;  
D. int my-score;

### 3. 下列哪个输入方式可以读取包含空格的一整行文本？

A. cin >> text;  
B. getline(cin, text);  
C. cout << text;  
D. text.find();

### 4. string::find() 找不到目标字符串时返回：

A. 0  
B. -1  
C. string::npos  
D. nullptr

### 5. 写入文件通常使用哪个类型？

A. ifstream  
B. ofstream  
C. ostream  
D. vector

### 6. 下列函数参数属于按引用传递的是：

A. string note  
B. const string note  
C. string& note  
D. string* note

### 7. 下列代码中，ptr 保存的内容是：

~~~cpp
int score = 90;
int* ptr = &score;
~~~

A. 90  
B. score 的地址  
C. score 的副本  
D. nullptr

### 8. C++ 中 class 成员的默认访问权限是：

A. public  
B. private  
C. protected  
D. friend

### 9. 哪个函数会在对象创建时自动调用？

A. 普通成员函数  
B. 析构函数  
C. 构造函数  
D. 友元函数

### 10. 下列哪项正确描述成员初始化列表？

~~~cpp
Book(const string& name) : title(name)
{
}
~~~

A. title(name) 是函数调用  
B. title 在构造函数体后初始化  
C. title 在构造函数体前初始化  
D. 冒号表示继承

### 11. friend 关键字的主要作用是：

A. 创建派生类  
B. 允许指定的非成员函数访问私有成员  
C. 让函数自动成为虚函数  
D. 自动释放内存

### 12. 哪个运算符通常重载为输出对象？

A. +  
B. ==  
C. <<  
D. &&

### 13. 基类函数要支持运行时多态，应使用：

A. static  
B. friend  
C. virtual  
D. template

### 14. 下列哪种关系适合使用组合？

A. Dog 是 Animal  
B. TextNote 是 Note  
C. NoteManager 拥有多条 Note  
D. Cat 是 Animal

### 15. NoteManager 中最适合保存多条笔记的数据成员是：

A. string note;  
B. vector<Note> notes;  
C. int notes;  
D. NoteManager* notes;

### 16. 工厂模式的主要职责是：

A. 显示对象  
B. 集中对象创建逻辑  
C. 替代构造函数  
D. 替代继承

### 17. 对于可创建多种 Note 派生类的基础工厂，最合适的返回类型是：

A. TextNote  
B. TodoNote  
C. Note*  
D. string

### 18. std::vector 最适合的描述是：

A. 固定长度数组  
B. 自动增长的连续动态数组  
C. 只能保存整数的容器  
D. 自动去重的有序集合

### 19. std::find(values.begin(), values.end(), 7) 找不到 7 时，返回值等于：

A. values.begin()  
B. values.end()  
C. nullptr  
D. 0

### 20. ContextBuilder 在 RAG 流水线中的主要职责是：

A. 删除笔记  
B. 创建派生类对象  
C. 将相关笔记组织为上下文  
D. 编译 C++ 程序

---

# 二、判断题（共 20 题，每题 1 分，共 20 分）

### 1. = 用于比较两个值是否相等。 （ ）

### 2. getline(cin, text) 可以读取包含空格的文本。 （ ）

### 3. ofstream 主要用于从文件读取内容。 （ ）

### 4. ios::app 表示在文件末尾追加写入。 （ ）

### 5. 函数按值传递时，修改形参会修改调用者的原变量。 （ ）

### 6. const string& note 可以避免复制，并保证函数内不修改 note。 （ ）

### 7. 表达式 &value 表示变量 value 的地址。 （ ）

### 8. 空指针可以安全地执行 *ptr。 （ ）

### 9. struct 和 class 都可以定义成员函数。 （ ）

### 10. 类外部代码可以直接访问 private 成员。 （ ）

### 11. 构造函数可以写返回类型 void。 （ ）

### 12. 一个类可以拥有多个参数列表不同的构造函数。 （ ）

### 13. 析构函数可以重载为多个不同参数版本。 （ ）

### 14. operator<< 通常返回 ostream&，这样可以连续输出。 （ ）

### 15. 友元函数一定是类的成员函数。 （ ）

### 16. override 可以帮助检查派生类函数是否真正重写了基类虚函数。 （ ）

### 17. 多态基类通常应提供虚析构函数。 （ ）

### 18. vector<Note> 表示 NoteManager 和 Note 的继承关系。 （ ）

### 19. 工厂模式将对象的创建与对象的使用分离。 （ ）

### 20. std::remove 会自动缩小 vector 的大小。 （ ）

---

# 三、填空题（共 20 题，每题 1 分，共 20 分）

### 1. 用于向终端输出内容的对象是 __________。

### 2. 保存真或假值的 C++ 类型是 __________。

### 3. 用于读取一整行文本的函数是 __________。

### 4. 用于检查字符串中是否存在关键词的常见写法是 text.find(keyword) != __________。

### 5. 用于读取文件的流类型是 __________。

### 6. 用于将内容追加到文件末尾的打开模式是 __________。

### 7. 当函数不返回值时，返回类型写作 __________。

### 8. string& note 中的 & 表示参数按 __________ 传递。

### 9. int* ptr = &value; 中，ptr 的类型是指向 __________ 的指针。

### 10. 不指向有效对象的现代空指针值是 __________。

### 11. 类中默认访问权限是 __________。

### 12. 创建对象时自动执行的特殊成员函数称为 __________。

### 13. 对象离开作用域时自动执行的特殊成员函数称为 __________。

### 14. 构造函数名必须与 __________ 相同。

### 15. 在 Book::display() 中，:: 称为 __________ 运算符。

### 16. 用于让非成员函数访问私有成员的关键字是 __________。

### 17. 基类中声明可被派生类动态重写的函数时使用关键字 __________。

### 18. 派生类函数末尾常用 __________ 来确认它重写了基类虚函数。

### 19. vector 末尾添加元素的成员函数是 __________。

### 20. RAG 流水线通常写作 Retrieval -> __________ -> Generation。

---

# 四、简答题（共 15 题，每题 2 分，共 30 分）

### 1. 说明 cin >> text 与 getline(cin, text) 的区别，并各举一个适用场景。

### 2. 为什么在先使用 cin >> choice、后使用 getline(cin, title) 时，通常需要调用 cin.ignore()？

### 3. 解释 ofstream 与 ifstream 的作用区别。

### 4. 说明 string::find 找到和找不到关键词时分别返回什么。

### 5. 说明按值传递与按引用传递的区别。

### 6. 分别解释 p、*p、&value 在下列代码中的含义：

~~~cpp
int value = 10;
int* p = &value;
~~~

### 7. 为什么解引用指针前应检查它是否为 nullptr？

### 8. 比较 struct 与 class 的默认访问权限，并说明 private 的用途。

### 9. 解释构造函数与析构函数分别在什么时候调用、主要用于做什么。

### 10. 为什么只读成员函数通常在参数列表后写 const？

### 11. 为什么 operator<< 通常实现为非成员友元函数？

### 12. 解释继承、虚函数与运行时多态之间的关系。

### 13. 说明组合（has-a）与继承（is-a）的区别，各举一个例子。

### 14. 为什么 NoteManager 应负责管理笔记集合，而单条 Note 应负责显示自身？请使用职责分离或委托说明。

### 15. 解释工厂模式如何降低客户端代码对具体类（如 TextNote、TodoNote）的依赖。

---

# 五、编程题（共 2 题，每题 5 分，共 10 分）

## 1. 笔记管理器（5 分）

编写 Note 和 NoteManager 两个类。

要求：

1. Note 有私有成员 title 和 content。
2. Note 提供构造函数 Note(const string& title, const string& content)。
3. Note 提供 display() const，输出标题和内容。
4. NoteManager 私有保存 vector<Note> notes。
5. NoteManager 提供 addNote(const Note&) 和 displayAll() const。
6. 在 main() 中添加至少两条笔记并显示全部笔记。

## 2. 多态工厂（5 分）

编写一个最小的笔记工厂系统。

要求：

1. 定义抽象基类 Note，包含纯虚函数：

~~~cpp
virtual void display() const = 0;
~~~

并提供虚析构函数。

2. 定义 TextNote 和 TodoNote 两个派生类，分别重写 display()。
3. 定义 NoteFactory，提供：

~~~cpp
Note* create(const string& type);
~~~

当 type 为 "text" 时创建 TextNote，当其为 "todo" 时创建 TodoNote；未知类型返回 nullptr。

4. 在 main() 中通过工厂创建一条 "todo" 笔记，用 Note* 调用 display()，并正确释放对象。
