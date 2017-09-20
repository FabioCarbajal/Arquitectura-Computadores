#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

int convert(bitset<8> a){
	int n=0;
	for(int i=0;i<a.size()-1;i++)
		n+=pow(2,i)*a[i];
	n-=pow(2,a.size()-1)*a[7];
	return n;
}

bitset<8> sumaBit(bitset<8> a, bitset<8> b){
	bool aca=0;  //Inicializa el Acarreo
	bitset<8> c;
	for(int i=0; i<a.size();i++){
		c[i]=(a[i] ^ b[i]) ^ aca;  //Opera la suma
		aca=(a[i] & b[i]) | (a[i] & aca) | (aca & b[i]); //Usa la lgica del acarreo
	}
	return c;
}

bitset<8> complementoBit(bitset<8> a){
	bitset<8> b, u(1);
	for(int i=0; i<a.size();i++)
		b[i]=~a[i]; //Usa el operador NOT para convertir el numero
	return sumaBit(b,u);
}

void division(int a, int b){ //Implementado a traves del diagrama de flujo
	bitset<8> Q(a),M(b),A(0), temp(0);
	int n=Q.size();
	while(n>0){
		A=A<<1;
		A[0]=Q[7];
		Q=Q<<1;
		A=sumaBit(A,complementoBit(M));
		if(A[Q.size()-1]==1){
			Q[0]=0;
			A=sumaBit(A,M);
		}
		else
		   Q[0]=1;
		n--;
	}
	cout<<"Resultado Binario: "<<Q<<endl;
	cout<<"Resultado Decimal: "<<convert(Q)<<endl;
	cout<<"Resto: "<<convert(A)<<endl;
}

int main()
{
	division(200,-4);
	cout<<sumaBit(124,131)<<endl;
    return 0;
}
