#include <iostream>
using namespace std;

int main (){

    int *pNum = NULL;

    pNum = new int;

    *pNum = 25;

    cout << "direccion: " << pNum << '\n';
    
    cout << "valor: " << *pNum << '\n';
    
    cout << "valor: " << &pNum << '\n';

    cout << sizeof(pNum) << '\n';

    return 0;

}