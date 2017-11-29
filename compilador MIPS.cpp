#include <iostream>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <sstream>

using namespace std;

class registro{
private:
	int generarPosicion(string a){
		int i=0;
		while(registros[i]!=a){
			i++;
		}
		return i;
	}
	
	string To_Binary(int dividendo){
		int resto;
		string binario = "", ordenado = "";
		stringstream stream;
		
		while(dividendo >= 1){
			resto = dividendo % 2;
			stream << resto;
			dividendo = dividendo/2;
		}
		
		binario = stream.str();
		while(binario.size()< 5) binario+='0';
		for(int i = 0; i < binario.size(); i++)
			ordenado = binario[i] + ordenado;
		return ordenado;
	}
	
	void generarDibujoInstruccionALU(string op , string rs , string rt , string rd, string fn ){
		cout<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - -  ______ - - - - - - - - - - - - -rd - - -"<<endl;
		cout<<" - - - - - - - -rs - - - -______ - - |      \\ - - - - - - - - - - -_______ - -"<<endl;
		cout<<" -  __ - - - _______ - - |      |- - |       \\ - - -  ________  - |       |- -"<<endl;
		cout<<" - |  | - - | "<<rs<<" |- - |      |- - -\\       \\ - - -|        | - |       |- -"<<endl;
		cout<<" - |  |     | "<<rt<<" |    |      |      \\       |     |  NONE  |   | "<<rd<<" |- -"<<endl;
		cout<<" - |__|     |_______|    |      |      /       |     |________|   |       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |      |- - -/       / -- - - - - - - - -|       |- -"<<endl;
		cout<<" - - - - - - - -rt - - - |______|- - |       / - - - -  - - - - - |_______|- -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - |______/- - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<endl;cout<<endl;cout<<endl;
		return;
	}
	
	void generarDibujoInstruccionLOAD(string op , string rs , string rt , string rd, string fn ){
		cout<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - -  ______ - - - - - - - - - - - - -rd - - -"<<endl;
		cout<<" - - - - - - - - - - - - -______ - - |      \\ - - - - - - - - - - -_______ - -"<<endl;
		cout<<" -  __ - - - _______ - - |      |- - |       \\ - - -  ________  - |       |- -"<<endl;
		cout<<" - |  | - - | "<<rs<<" |- - |      |- - -\\       \\ - - -|        | - |       |- -"<<endl;
		cout<<" - |  |     | "<<rt<<" |    |      |      \\       |     |        |   |          |- -"<<endl;
		cout<<" - |__|     |_______|    |      |      /       |     |________|   |       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |      |- - -/       / -- - - - - - - - -|       |- -"<<endl;
		cout<<" - - - - - - - -rt - - - |______|- - |       / - - - -  - - - - - |_______|- -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - |______/- - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<endl;cout<<endl;cout<<endl;
		return;
	}
	
	void generarDibujoInstruccionSAVE(string op , string rs , string rt , string rd, string fn ){
		cout<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - -  ______ - - - - - - - - - - - - -rd - - -"<<endl;
		cout<<" - - - - - - - - - - - - -______ - - |      \\ - - - - - - - - - - -_______ - -"<<endl;
		cout<<" -  __ - - - _______ - - |      |- - |       \\ - - -  ________  - |       |- -"<<endl;
		cout<<" - |  | - - | "<<rs<<" |- - |      |- - -\\       \\ - - -|        | - |       |- -"<<endl;
		cout<<" - |  |     | "<<rt<<" |    |      |      \\       |     |        |   |   NONE   |- -"<<endl;
		cout<<" - |__|     |_______|    |      |      /       |     |________|   |       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |      |- - -/       / -- - - - - - - - -|       |- -"<<endl;
		cout<<" - - - - - - - -rt - - - |______|- - |       / - - - -  - - - - - |_______|- -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - |______/- - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<endl;cout<<endl;cout<<endl;
		return;
	}
	
	void generarDibujoInstruccionBRANCH(string op , string rs , string rt , string rd, string fn ){
		cout<<endl;
		cout<<" - - - - - - -_____- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - |0x2f8| - - - - - - - -  ______ - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - |_____| - - -______ - - |      \\ - - - - - - - - - - -_______ - -"<<endl;
		cout<<" -  __ - - - _______ - - |      |- - |       \\ - - -  ________  - |       |- -"<<endl;
		cout<<" - |  | - - | "<<rs<<" |- - |      |- - -\\       \\ - - -|        | - |       |- -"<<endl;
		cout<<" - |  |     | "<<rt<<" |    |      |      \\  NONE |     |  NONE  |   |  NONE   |- -"<<endl;
		cout<<" - |__|     |_______|    |      |      /       |     |________|   |       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |      |- - -/       / -- - - - - - - - -|       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |______|- - |       / - - - -  - - - - - |_______|- -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - |______/- - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<endl;cout<<endl;cout<<endl;
		return;
	}
	void generarDibujoInstruccionJUMP(string op , string rs ,string rt,  string fn ){
		cout<<endl;
		cout<<" - - - - - - -_____- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - |0x3d6| - - - - - - - -  ______ - - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - |_____| - - -______ - - |      \\ - - - - - - - - - - -_______ - -"<<endl;
		cout<<" -  __ - - - _______ - - |      |- - |       \\ - - -  ________  - |       |- -"<<endl;
		cout<<" - |  | - - | "<<rs<<" |- - |      |- - -\\       \\ - - -|        | - |       |- -"<<endl;
		cout<<" - |  |     | "<<rt<<" |    | NONE |      \\  NONE |     |  NONE  |   |  NONE   |- -"<<endl;
		cout<<" - |__|     |_______|    |      |      /       |     |________|   |       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |      |- - -/       / -- - - - - - - - -|       |- -"<<endl;
		cout<<" - - - - - - - - - - - - |______|- - |       / - - - -  - - - - - |_______|- -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - |______/- - - - - - - - - - - - - - - - -"<<endl;
		cout<<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
		cout<<endl;cout<<endl;cout<<endl;
		return;
	}
	
	
	
	void TablaALUinmediato(string op , int rs_ , int rt_ , int off_){
		string rs= To_Binary(rs_);
		string rt= To_Binary(rt_);
		string off= To_Binary(off_);
		while(off.size()< 16) off.insert(0,"0");
		cout<<endl;
		cout<<"\t          op       rs      rt      operand/offset    "<<endl;
		cout<<"\t       _________________________________________________"<<endl;
		cout<<"\t      |        |       |       |                        |"<<endl;
		cout<<"\t      | "<< op<<" | "<<rs<<" | "<<rt<<" |    "<< off <<"    |"<<endl;
		cout<<"\t      |________|_______|_______|________________________|"<<endl;
		cout<<endl;
		cout<<endl;cout<<endl;
		
		generarDibujoInstruccionALU(op, "     " , rs , rt, off);
	}
	
	void TablaALU(string op , int rs_ , int rt_ , int rd_, string fn ){
		string rs= To_Binary(rs_);
		string rt= To_Binary(rt_);
		string rd= To_Binary(rd_);
		cout<<endl;
		cout<<"\t          op       rs      rt      rd    shift     fn    "<<endl;
		cout<<"\t       _________________________________________________"<<endl;
		cout<<"\t      |        |       |       |       |       |        |"<<endl;
		cout<<"\t      | "<< op<<" | "<<rs<<" | "<<rt<<" | "<<rd<<" | 00000 | "<<fn<<" |"<<endl;
		cout<<"\t      |________|_______|_______|_______|_______|________|"<<endl;
		cout<<endl;
		cout<<endl;cout<<endl;
		
		generarDibujoInstruccionALU(op, rs , rt , rd, fn);
	}
	
	void TablaJUMP(string op , int rs_  , int rd_, string fn, int rt_){
		string rs= To_Binary(rs_);
		string rt= To_Binary(rt_);
		string rd= To_Binary(rd_);
		cout<<endl;
		cout<<"\t          op       rs      rt      rd    shift     fn    "<<endl;
		cout<<"\t       _________________________________________________"<<endl;
		cout<<"\t      |        |       |       |       |       |        |"<<endl;
		cout<<"\t      | "<< op<<" | "<<rs<<" | "<<rt<<" | "<<rd<<" | 00000 | "<<fn<<" |"<<endl;
		cout<<"\t      |________|_______|_______|_______|_______|________|"<<endl;
		cout<<endl;
		cout<<endl;cout<<endl;
		
		generarDibujoInstruccionALU(op, rs , rt , rd, fn);
	}
	
	
public:
	vector<string>registros;
	vector<int> registros_contenido;
	
	registro(){
		registros.push_back("$zero");registros.push_back("$at");registros.push_back("$v0");registros.push_back("$v1");registros.push_back("$a0");registros.push_back("$a1");registros.push_back("$a2");registros.push_back("$a3");registros.push_back("$t0");registros.push_back("$t1");registros.push_back("$t2");registros.push_back("$t3");registros.push_back("$t4");registros.push_back("$t5");registros.push_back("$t6");registros.push_back("$t7");registros.push_back("$s0");registros.push_back("$s1");registros.push_back("$s2");registros.push_back("$s3");registros.push_back("$s4");registros.push_back("$s5");registros.push_back("$s6");registros.push_back("$s7");registros.push_back("$t8");registros.push_back("$t9");registros.push_back("$k0");registros.push_back("$k1");registros.push_back("$gp");registros.push_back("$sp");registros.push_back("$fp");registros.push_back("$ra");
		for(int i=0;i<32;i++)registros_contenido.push_back(0);
	}
	
	void imprimirRegistros(){
		cout<<"\t\t\t _______________________________"<<endl;
		cout<<"\t\t\t|\t    REGISTROS\t\t|"<<endl;
		cout<<"\t\t\t|_______________________________|"<<endl;
		cout<<"\t\t\t|\t"<<"\t|\t"<<"\t|"<<endl;
		for(int i=0;i<32;i++){
			cout<<"\t\t\t|\t"<<registros[i]<<"\t|\t"<<registros_contenido[i]<<"\t|"<<endl;
		}
		cout<<"\t\t\t|_______________|_______________|"<<endl;
	}
	
	void Save(){
		
	}
	
	//funcions de operacion de MIPS
	
	void li(string registro1, int valor){
		int posicion=generarPosicion(registro1);
		registros_contenido[posicion]=valor;
	}
	
	void add(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=registros_contenido[rs]+registros_contenido[rt];
		TablaALU("000000",rs,rt,rd,"100000");
	}
	
	void sub(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=registros_contenido[rs]-registros_contenido[rt];
		TablaALU("000000",rs,rt,rd,"100010");
	}
	
	void and_(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=registros_contenido[rs]&registros_contenido[rt];
		TablaALU("000000",rs,rt,rd,"100100");
	}
	
	void or_(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=registros_contenido[rs]|registros_contenido[rt];
		TablaALU("000000",rs,rt,rd,"100101");
	}
	
	void xor_(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=registros_contenido[rs]^registros_contenido[rt];
		TablaALU("000000",rs,rt,rd,"100110");
	}
	
	void nor_(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=~(registros_contenido[rs]|registros_contenido[rt]);
		TablaALU("000000",rs,rt,rd,"100111");
	}
	
	void addi(string registroAGuardar, string registro1, int inmediato){
		int rs=generarPosicion(registroAGuardar);
		int rt=generarPosicion(registro1);
		registros_contenido[rs]=registros_contenido[rt]+inmediato;
		TablaALUinmediato("001000",rs,rt,inmediato);
	}
	
	void andi(string registroAGuardar, string registro1, int inmediato){
		int rs=generarPosicion(registroAGuardar);
		int rt=generarPosicion(registro1);
		registros_contenido[rs]=registros_contenido[rt]&inmediato;
		TablaALUinmediato("001100",rs,rt,inmediato);
	}
	
	void ori(string registroAGuardar, string registro1, int inmediato){
		int rs=generarPosicion(registroAGuardar);
		int rt=generarPosicion(registro1);
		registros_contenido[rs]=registros_contenido[rt]|inmediato;
		TablaALUinmediato("001101",rs,rt,inmediato);
	}
	
	void xori(string registroAGuardar, string registro1, int inmediato){
		int rs=generarPosicion(registroAGuardar);
		int rt=generarPosicion(registro1);
		registros_contenido[rs]=registros_contenido[rt]^inmediato;
		TablaALUinmediato("001110",rs,rt,inmediato);
	}
	
	void slt(string registroAGuardar, string registro1, string registro2){
		int rd=generarPosicion(registroAGuardar);
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		registros_contenido[rd]=(registros_contenido[rs]<registros_contenido[rt])?1:0;
		TablaALU("000000",rs,rt,rd,"101010");
	}
	
	void slti(string registroAGuardar, string registro1, int inmediato){
		int rs=generarPosicion(registroAGuardar);
		int rt=generarPosicion(registro1);
		registros_contenido[rs]=(registros_contenido[rt]<inmediato)?1:0;
		TablaALUinmediato("001010",rs,rt,inmediato);
	}
	/*
	void lw(string registroAGuardar, string inmediato, string registro1){
		int rs=generarPosicion(registroAGuardar);
		int rt=generarPosicion(registro1);
		TablaALUinmediato("001010",rs,rt,inmediato);
	}
	*/
	void j(string proces){
		generarDibujoInstruccionJUMP("000010","     ","     ","      ");
	}
	
	void jr(string poces){
		generarDibujoInstruccionJUMP("000000","     ","     ","001000");
	}
	
	void jal(string proces){
		generarDibujoInstruccionJUMP("000011","     ","     ","      ");
	}
	/*
	void syscall(string proces){
		int rs;
		generarDibujoInstruccionJUMP("000000",rs,"     ","001100");
	}
	
	void bltz(string registro1, string proces){
		int rs=generarPosicion(registro1);
		generarDibujoInstruccionBRANCH("000001","     ","     ","      ");
	}
	
	void beq(string registro1, string registro2, string proces){
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		generarDibujoInstruccionBRANCH("000100","     ","     ","      ");
	}
	
	void bne(string registro1, string registro2, string proces){
		int rs=generarPosicion(registro1);
		int rt=generarPosicion(registro2);
		generarDibujoInstruccionBRANCH("000101","     ","     ","      ");
	}
	*/
};

int main()
{
	system("color 03");
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t    INSTRUCCIONES MICROMIPS"<<endl;
	cout<<endl;
	//crea una clase registro para operar
	registro a;
	registro b;
	a.li("$t1",4);
	a.li("$t2",5);
	a.add("$t3","$t2","$t1");
	a.sub("$t4","$t1","$t2");
	//a.add("$t5","$t3","$t2");
	a.imprimirRegistros();
	return 0;
}
