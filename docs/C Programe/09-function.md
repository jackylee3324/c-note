# function


## 傳值 (Call by Value)
```
void test(int x) {
    x += 10;
}
int num = 5;
test(num);
cout << num; // 輸出 5

```
## 傳參考 (Call by Reference)
```
void test(int &x) {
    x += 10;
}
int num = 5;
test(num);
cout << num; // 輸出 15

```

## 傳指標 (Call by Pointer)
```
void test(int *x) {
    *x += 10;
}
int num = 5;
test(&num);
cout << num; // 輸出 15

```