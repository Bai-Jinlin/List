# List

## simple example
* **create list**  
```cpp
List<int>* list= cons(1,cons(3,cons(2, List<int>::empty)));
```
* **append list**
```cpp
List<int>* l=append(l,4);
l and list =[1,3,2,4]
```
*append have functional editon*
```cpp
List<int>* l=append(l,4);
l =[1,3,2,4]
list = [1,3,2]
```

