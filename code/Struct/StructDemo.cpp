#include <stdio.h>

typedef const char* String;

typedef struct {  
    String id;  
    String name; 
    double balance;
} Account;

typedef struct {  
    Account acct;
    double overdraftlimit;

} CheckingAccount;

int main() { 
    CheckingAccount checking = {
        .acct = {"123-456-789", "Justin Lee", 1000},
        .overdraftlimit = 30000
    };

    printf("%s\n", checking.acct.id);
    printf("%s\n", checking.acct.name);
    printf("%f\n", checking.acct.balance);
    printf("%f\n", checking.overdraftlimit);

    return 0; 
} 