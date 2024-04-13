#include "../HugInt/huge_int.h"
#include <iostream>
#include <string>
#include <cstring>

int HugeInt::toGetLength(){
 return length;
}

HugeInt::HugeInt(long n)
{
    std::cout << "n=" << n << std::endl;
    string temp = to_string(n);
    std::cout << "temp="+temp << std::endl;

    const int length2 = temp.length();
    
    char *char_array = new char[length2 + 1];
    strcpy(char_array, temp.c_str());

    for (int i = 0; i < length; i++)
    {
        integer[i] = 0;
    }

    for (int i = 0; i < length2; i++)
    {
        integer[i] = char_array[i] - 48;

        std::cout << char_array[i] << std::endl;
    }
}

HugeInt::HugeInt(string n)
{
    std::cout << "input=" << n << std::endl;
    string temp = n;

    const int length2 = temp.length();
    //toSetLength(length2);


    char *char_array = new char[length2 + 1];
    strcpy(char_array, temp.c_str());

    for (int i = 0; i < length; i++)
    {
        integer[i] = 0;
    }

   int originalLength=length; 
    //轉入陣列
    for (int i = length2-1; i >=0; i--){
        originalLength=originalLength-1;
        integer[originalLength] = char_array[i] - 48;
    }
}

HugeInt HugeInt::operator+(const HugeInt &input)
{
    std::cout << "operator length="<< length << std::endl;

    HugeInt temp = input;
    
    //從陣列後面往前計算
    int carry = 0;
    for (int i = length - 1; i >= 0; i--)
    {

        temp.integer[i] = integer[i] + input.integer[i] + carry;

        // 確認是否有進位
        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    return temp;
}

string HugeInt::stringForm() const
{
    string output;
    output = "";
    for (int i = 0; i < length; i++)
    {
        //前綴去除0字串
        // if (to_string(integer[i])=="0"){
        //     if (output!=""){
        //     output = output + to_string(integer[i]);
        //     }
        // }
        // else
        // {
        // output = output + to_string(integer[i]);
        // }

        output = output + to_string(integer[i]);
    }
    return output;
}
