#include <iostream>
#include <string>
#define i 23

using namespace std;


int main()
{
    cout<<"Compilador MIPS"<<endl;
    cout<<endl;
    string inst;
    string instru[i]={"lui","add","sub","slt","addi","slti","and","or","xor","nor","andi","ori","xori","lw","sw","j","jr","bltz","beq","bne","jal","syscall"};
    cout<<"Ingrese la instruccion: ";
    cin>>inst;
    if(inst=="add")
    {
        cout<<"Se usa la instruccion adicion";
    }
    else if(inst=="sub")
    {
        cout<<"Usa la substraccion";
    }
    return 0;
}
