//float a binario
#include<iostream>
#include<string>
#include<math.h>
#include <stdio.h>
using namespace std; 

int entero_bit(int parte_entero,string &entero){  
	if (parte_entero==0){
		return 0;}
	entero_bit(parte_entero/2,entero);
	char temp =(parte_entero%2)+48;
	entero=entero + (temp);								
}
void flotante_bit(float parte_float,string &flotante){

	for(int i=0;i<22;i++){
		parte_float=parte_float*2;
		flotante[i]=int(parte_float)+48;
		parte_float=parte_float-int(parte_float);
			
	}}
void flot (int numero,string &entero,string &flotante,char &signo){
	int nunm_cadena= entero.length();
	if (numero!=0)
		nunm_cadena--;
	int biased=(pow(2, 7)-1)+nunm_cadena;
	
	string agrega="";
	if (numero!=0)
		agrega=entero.substr(1,nunm_cadena);
	agrega = agrega+ flotante;
	flotante=agrega;
	entero="";
	entero_bit(biased,entero);
	flotante=flotante.substr(0,23);
	
}
int main(){
	float numero;
	cout<< "Ingrese el numero 'Float': ";
	cin>>numero;
	int parte_entero;
	float parte_float;
	string entero=""; 
	string flotante="                    	";
	char signo=' ';
	if(numero==0)
		signo='X';
	else if (numero<0){
	
		signo='1';
		numero=numero*(-1);
}
	else
		signo='0';
	
	parte_entero=numero;
	parte_float=numero-parte_entero;
	entero_bit(parte_entero,entero);
	flotante_bit(parte_float,flotante);
	flot (numero,entero,flotante,signo);
	cout<<"\nFloat\n";
	cout<<signo<<" "<<entero<<" "<<flotante<<"\n";
	//string p=&numero;
	//cout<<p<<"\n";
	int numero2=(long long int)&entero;
	//cout<<numero2<<"\n";
	string entero2;
	entero_bit(numero2,entero2);
	int nfaltas=32-entero2.length();
	string perm="";
	for (int i=0;i<nfaltas;i++)
		perm=perm+'0';
	perm=perm+entero2;
	entero2=perm;
	cout<<"hexadecimal a binario(RAM)\n";
	cout<<entero2<<"\n";
	return 0;	
}
