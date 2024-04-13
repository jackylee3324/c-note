# 排序



* ## 宣告

```c++
    map<string, string> mapTest;
```

* ## insert()

```c++
    // 用 insert 函數插入 pair
        mapTest.insert(pair<string, string>("r000", "student_zero"));

    //用 "array" 方式插入
        mapTest["r123"] = "student_first";
        mapTest["r456"] = "student_second";
```

* ## find()

出現時，它返回資料所在位置，如果沒有，返回 iter 與 end() 函數的返回值相同。

```c++
    iter = mapTest.find("r123");

    if(iter != mapTest.end())
        cout<<"Find, the value is"<<iter->second<<endl;
    else
    cout<<"Do not Find"<<endl;
```

* ## 刪除與清空

```c++
    //迭代器刪除
    iter = mapTest.find("r123");
    mapTest.erase(iter);

    //用關鍵字刪除
    int n = mapTest.erase("r123");//如果刪除了會返回1，否則返回0

    //用迭代器範圍刪除 : 把整個map清空
    mapTest.erase(mapTest.begin(), mapTest.end());
    //等同於mapStudent.clear()
```

* ## cout
```c++
    // 印出來
    for(auto item :mapTest){
        cout << item.first << " " << (item.second / sum) * 100 << "\n";
    }


    for (auto it = mapTest.cbegin(); it != mapTest.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }

    for (const auto &n : mapTest)
    {
        std::cout << "key: " << n.first << " value: " << n.second << "\n";
    }

    // 反向印出來
    for (auto it = mapTest.rbegin(); it != mapTest.rend(); it++)
    {
        std::cout << "id: " << (*it).first << ", name: " << (*it).second << "\n";
    }
```