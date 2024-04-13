#include <iostream>

using namespace std;

class HugeInt{
    
   public :
      HugeInt(long);
      HugeInt(string);
      HugeInt operator + (const HugeInt &);

      
      string stringForm() const;

      int toGetLength();
   private :
      int integer[20];
      int length=20;
     
};