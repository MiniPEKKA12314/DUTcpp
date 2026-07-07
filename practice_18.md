# 第 18 课测评

## Context Builder - 走向 LLM 风格的知识系统

### 涉及主题

- 为什么上下文很重要
- 从关键词搜索到上下文检索
- Context Builder 的作用
- 从多条笔记构建提示词
- 分离检索和生成
- 相关性与上下文选择
- 面向 LLM 的信息组织
- 流水线设计：Retrieval -> Context -> Generation
- 将 CLI Notes 系统扩展到检索增强生成（RAG）
- 为智能知识系统做准备

---

# 第 A 部分：单项选择题（10 分）

### 1. `ContextBuilder` 的主要职责是什么？

A. 创建新笔记

B. 将相关信息组织成上下文，供下游处理使用

C. 删除重复笔记

D. 替代 `NoteManager`

**答案：** 

---

### 2. 为什么上下文对 LLM 很重要？

A. 它提高 CPU 速度。

B. 它提供相关信息，引导模型回答。

C. 它替代训练数据。

D. 它保证答案正确。

**答案：** 

---

### 3. 哪个处理流水线最能代表第 18 课？

A. Generation -> Retrieval -> Storage

B. Storage -> Generation -> Search

C. Retrieval -> Context Building -> Generation

D. Prompt -> Training -> Compilation

**答案：** 

---

### 4. 哪个组件应该搜索相关笔记？

A. `ContextBuilder`

B. `NoteManager`

C. `Note`

D. `main()`

**答案：** 

---

### 5. 哪个说法最能描述上下文？

A. 随机的笔记集合

B. 因为与任务或问题相关而被选出的信息

C. 系统中存储的每一条笔记

D. 备份文件

**答案：** 

---

### 6. 为什么应该分离检索和生成？

A. 为了减少类的数量

B. 为了让每个组件专注于特定职责

C. 为了避免使用继承

D. 为了消除多态

**答案：** 

---

### 7. 引入 `ContextBuilder` 展示了哪个原则？

A. 关注点分离

B. 函数重载

C. 运算符优先级

D. 指针算术

**答案：** 

---

### 8. 关于上下文选择，哪个说法正确？

A. 信息越多总是越好。

B. 只应包含最相关的信息。

C. 上下文应该包含无关笔记。

D. 上下文不应该变化。

**答案：** 

---

### 9. 哪种设计最适合未来集成 LLM？

A. 把整个数据库传给模型

B. 从相关笔记构建聚焦的上下文

C. 对所有笔记使用全局变量

D. 把提示词直接嵌入每个类中

**答案：** 

---

### 10. 第 18 课的主要架构贡献是什么？

A. 将笔记系统转变为知识检索流水线

B. 消除笔记存储

C. 用函数替代类

D. 删除面向对象设计

**答案：** 

---

# 第 B 部分：填空题（10 分）

### 1. `ContextBuilder` 将多段相关 __________ 合并成一个上下文。

**答案：** 

---

### 2. 检索选择相关笔记，而 __________ 组织它们。

**答案：** 

---

### 3. 好的上下文应该既相关又 __________。

**答案：** 

---

### 4. 在检索增强生成中，检索发生在生成 __________。

**答案：** 

---

### 5. 只选择有用信息有助于减少不必要的 __________。

**答案：** 

---

# 第 C 部分：判断题（10 分）

### 1. `ContextBuilder` 的目的是直接生成答案。

**答案：** 

---

### 2. 设计良好的上下文包含与用户请求相关的信息。

**答案：** 

---

### 3. 检索和生成通常应该由同一个类处理。

**答案：** 

---

### 4. 把每条已存储笔记都传给 LLM 通常是高效策略。

**答案：** 

---

### 5. `ContextBuilder` 可以合并来自多条笔记的信息。

**答案：** 

---

### 6. 上下文质量会影响生成回答的质量。

**答案：** 

---

### 7. 上下文构建与笔记检索过程相互独立。

**答案：** 

---

### 8. 聚焦的上下文通常比大量无关信息更有用。

**答案：** 

---

### 9. 第 18 课为 CLI Notes 项目未来集成 AI 做准备。

**答案：** 

---

### 10. `ContextBuilder` 取代了对 `NoteManager` 的需求。

**答案：** 

---

# 第 D 部分：代码阅读（10 分）

### 问题 1

思考下面的设计：

```
classNoteManager
{
public:
vector<Note> search(conststring&keyword);
};

classContextBuilder
{
public:
string buildContext(constvector<Note>&notes);
};
```

哪个职责属于 `ContextBuilder`？

**答案**

它将检索到的笔记转换为结构化上下文（例如格式化字符串），供另一个组件使用，例如 LLM。

---

### 问题 2

展示了哪个软件设计原则？

```
autonotes =manager.search(query);
stringcontext =builder.buildContext(notes);
```

**答案**

关注点分离。检索和上下文构建由不同类处理。

---

### 问题 3

假设：

```
vector<Note>notes =manager.search("AI");
```

返回五条笔记。

`ContextBuilder` 是否总是应该包含全部五条笔记？

**答案**

不一定。它应该包含与用户请求最相关的笔记（或笔记片段），同时避免不必要的信息。

---

### 问题 4

下面函数扮演什么架构角色？

```
stringbuildContext(constvector<Note>&notes);
```

**答案**

它将检索到的笔记数据转换为适合下游处理的表示形式，例如为 LLM 构建提示词。

---

### 问题 5

表示哪种流水线？

```
search()
      ->
buildContext()
      ->
generate()
```

**答案**

一种检索增强生成（RAG）风格的流水线。

---

# 第 E 部分：简答题（10 分）

### 1.

为什么构建聚焦上下文通常比把所有可用笔记都传给 LLM 更好？

**示例答案**

聚焦上下文会减少无关信息，帮助模型专注于最有用的内容。它还可以提高效率，并降低干扰信息或冲突信息影响回答的风险。

---

### 2.

解释检索和上下文构建之间的区别。

**示例答案**

检索根据查询识别相关笔记，而上下文构建会把检索到的信息组织成连贯格式，以便用于文本生成等下游任务。

---

### 3.

`ContextBuilder` 如何改善整体软件架构？

**示例答案**

它将上下文构建与笔记管理、答案生成分离，使每个组件更容易独立维护、测试和扩展。

---

# 第 F 部分：编程题（20 分）

## 问题 1 - 构建简单上下文

创建：

```
classContextBuilder
{
public:
string buildContext(constvector<string>&notes);
};
```

要求：

- 将所有笔记字符串组合成一个格式化上下文。
- 每条笔记之间用空行分隔。

示例输出：

```
=== Context ===

Meeting at 2 PM.

Remember to review Chapter 5.

Finish the project proposal.
```

---

## 问题 2 - 选择相关笔记

假设每条笔记都有：

```
title
content
tag
```

实现：

```
vector<Note>filterByTag(constvector<Note>&notes,
conststring&tag);
```

该函数只返回具有指定标签的笔记。

---

## 问题 3 - 构建 LLM 提示词

编写：

```
stringbuildPrompt(conststring&context,
conststring&question);
```

示例输出：

```
Context:
...

Question:
...

Answer:
```

---

## 问题 4 - 上下文长度控制

实现一个函数：

```
stringbuildLimitedContext(
constvector<Note>&notes,
size_tmaxCharacters);
```

要求：

- 一条一条添加笔记。
- 当再添加一条笔记会超过最大字符数时停止。

**挑战：** 解释在使用 LLM 时为什么限制上下文大小很重要。

---

## 问题 5 - CLI Notes 上下文流水线（挑战）

设计下面的架构：

```
classNoteManager
{
public:
vector<Note> search(conststring&);
};

classContextBuilder
{
public:
string buildContext(constvector<Note>&);
};

classAIClient
{
public:
void generate(conststring&prompt);
};
```

程序流程：

```
User Question
      ->
Search Notes
      ->
Build Context
      ->
Construct Prompt
      ->
Generate Response
```

使用占位输出实现 `AIClient::generate()`。

---

# 第 G 部分：设计与思考挑战（可选加分）

### 问题

比较下面两种方法。

### 设计 A

```
User Question
      ->
Send every stored note to the AI model
```

### 设计 B

```
User Question
      ->
Retrieve relevant notes
      ->
Build a focused context
      ->
Send only the context to the AI model
```

通常更推荐哪种设计？为什么？

### 示例答案

通常更推荐设计 B，因为它只发送与用户请求相关的信息。这减少了不必要的数据，提高效率，并且通常会带来更聚焦、更准确的回答。它还允许检索和上下文构建独立于语言模型演进，使系统更容易维护和扩展。

---

# 教师备注

第 18 课标志着从 **软件架构** 到 **AI 系统架构** 的重要转变。

课程演进变为：

```
Objects
      ->
Managers
      ->
Factories
      ->
Retrieval
      ->
Context Building
      ->
LLM Integration
```

学生应该理解，**大型语言模型并不直接处理数据库或笔记集合**。相反，它们处理的是由相关信息构建出的精心组织的 **上下文**。

关键收获是：

> **智能系统不只由语言模型定义，也由它在生成之前检索、选择和组织信息的效果定义。**
> 

本课为高级主题做准备，例如检索增强生成（RAG）、向量数据库、语义搜索、嵌入、重排序、提示词工程和 AI Agent 架构。
