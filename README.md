# *List library*

一些函数的分为函数式版本和命令式版本  
函数式版本的带有后缀_F  
默认情况下若函数返回了列表，函数式版本函数会生成新的列表，而过程式不会
## 使用演示

创建列表
```cpp
List<int> *l = cons(1, cons(4, cons(3, List<int>::empty)));
l===[1,4,3]
```
基本原语
* **cons**用于把数据追加到一个列表的头
```cpp
List<int> *t1=cons(5,l);
t1===[5,1,4,3]
```
* **head**用于获取列表的第一个元素
```cpp
int k=head(l);
k===1;
```
* **tail**用于获取列表第一个元素之后的列表
```cpp
List<int> *t=tail(l);
t==[4,3]
```



TODO

