#include <iostream>
#include <cstring>

using namespace std;

#define MAXSTRING 100

int main(void){
    char c='a';
    char *p;
    char s[MAXSTRING];

    p=&c;
    cout << *p << " " << *p+1 << " " << *p+2 << endl;
    cout << *p << " " << (char) (*p+1)  << " "  <<char(*p+2) << endl ;

    strcpy(s,"ABC");
    cout << s << " " <<(char)(*s+6) <<" " << (char) (*s+7) << " " << char(*s+1) << endl;
    
    strcpy(s,"she sells sea shells by the seashore");
    p=s+14;
    for (; *p != '\0';p++){
	if (*p == 'e')
	   *p='E';
	if(*p == ' ')
	 *p='\n';
    } 

    cout << s << endl;
    return 0;

}
