# cin
I/O

* ### cin

```c++
//只會讀掉一個換行或空白
string str1;
cin >> str1;
cin.clear();
cin.sync();
cout << "str1=" << str1 << endl;

// 1 2 3 
// str1=1
```

* ### getline

```c++
//讀入一整行,會讀掉換行
string str2;
getline(cin,str2);
cout << "str2=" << str2 << endl;
// 1 2 3 4
// str2=1 2 3 4
```
