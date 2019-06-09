#include <iostream>
#include <math.h>
#include <string> 
#include <stdlib.h>
using namespace std;

int main(){
	
	//variables de la columna,fila y para recolectar los valores de 
	int a=0,b=0;
	cout<<" Dame el numero de filas, no puede ser menor que 1: ";
	cin>>a;
	cout<<" Dame el numero de columnas, no puede ser menor que 1: ";
	cin>>b;
	
			
	
	//matriz de usuario
	//matriz de elemento diferente a 0
	//matriz temporal 
	int matriz[a][b][2];
	
	
	cout<<" Solo elementos enteros  \n";
	
	//recolectar la matriz a resolver
	for(int i=0;i<a;i++){
		
		for(int j=0;j<b;j++){
			cout<<" Dame el elemento  de la fila"<<(i+1)<<" y columna "<<(j+1)<<"  ";
			cin>>matriz[i][j][0];
			matriz[i][j][1]=1;
		}
		
		
		
	}
	
		cout<<" Matriz recolectada  \n";
	
	//imprimir matriz recolectada

	for(int i=0;i<a;i++){
		cout<<endl;
		for(int j=0;j<b;j++){
			
			
			cout<<matriz[i][j][0]<<" / "<<matriz[i][j][1]<<"  ";
			
		}
		
		
		
	}
	
	
	
	
	//resolver matriz

	//Gauss
	//se inicia desde 1 por que la primera fila es el pivote
	for(int i=1;i<a;i++){
		
			for(int j=0;j<i;j++){
				
			
			//elemento actual
			if(matriz[i][j][0]!=0)	{
				
				
				//el numerador es diferente de 0 por lo tanto hay que eliminarlo para obtener 0
				//para eso dividimos  el numero entre si mismo para obtener 1 y lo multiplicamos por el valor del primer elemento de la matriz
				
				//buscar el pivote
				int l=i-1;
				while(matriz[l][j][0]==0){
					l--;
				}
			
				
				//variable para hacer el pivote =1 b y d
				int piv_num= matriz[l][j][0]; // a c //-4
				int piv_den= matriz[l][j][1]; // b d // 2
				int ele_num= matriz[i][j][0]; 
				int ele_den= matriz[i][j][1]; 
				int signo=-1;
				int sign=-1;
				/*cout<<" pivote "<<piv_num<<"  "<<piv_den<<endl;
				cout<<" pivote "<<l<<endl;*/
				
				

	
			

				
				if(piv_num/piv_den>0){
					signo=1;
				}
				if(ele_num/ele_den>0){
					sign=1;
				}
				
				
				//hacer 0 el elemento actual y los elementos de las demas columnas
				for(int k=0;k<b;k++){
					

					
					//numerador temporal
					int num=(abs(ele_num)*(matriz[l][k][0]*abs(piv_den) ));
					//denominador temporal
					int den=(abs(ele_den)*(matriz[l][k][1]*abs(piv_num)) );
					/*cout<<" numerador "<<num<<endl;
					cout<<" denominador "<<den<<endl;*/
					
					

						
						//si el signo es igual
						if((signo==1 && sign==1 )|| (signo==-1 && sign==-1)){
							
							matriz[i][k][0]=matriz[i][k][0]*den-matriz[i][k][1]*num;
								matriz[i][k][1]=matriz[i][k][1]*den;
							
							
						}
						//si el signo es diferente
						else{
							
						
								matriz[i][k][0]=matriz[i][k][1]*num + matriz[i][k][0]*den;
								matriz[i][k][1]=matriz[i][k][1]*den;
							
						}
						
						
					
					
					
					
				
					
					
					
					
					
				}
			}//end del primer if
			
			}
		
	
	}
	
	//gauss-jordan
	for(int i=a-2;i>-1;i--){

			for(int j=b-2;j>i;j--){
			
			//elemento actual
			if(matriz[i][j][0]!=0)	{
				
				
				//el numerador es diferente de 0 por lo tanto hay que eliminarlo para obtener 0
				//para eso dividimos  el numero entre si mismo para obtener 1 y lo multiplicamos por el valor del primer elemento de la matriz
				
				//buscar el pivote
				int l=i+1;
				while(matriz[l][j][0]==0){
					l++;
				}
			
				
				//variable para hacer el pivote =1 b y d
				int piv_num= matriz[l][j][0]; // a c //-4
				int piv_den= matriz[l][j][1]; // b d // 2
				int ele_num= matriz[i][j][0]; 
				int ele_den= matriz[i][j][1]; 
				int signo=-1;
				int sign=-1;
				
				

	
			

				
				if(piv_num/piv_den>0){
					signo=1;
				}
				if(ele_num/ele_den>0){
					sign=1;
				}
				
				
				//hacer 0 el elemento actual y los elementos de las demas columnas
				for(int k=b-1;k>-1;k--){
					

					
					//numerador temporal
					int num=(abs(ele_num)*(matriz[l][k][0]*abs(piv_den) ));
					//denominador temporal
					int den=(abs(ele_den)*(matriz[l][k][1]*abs(piv_num)) );
					/*cout<<" numerador "<<num<<endl;
					cout<<" denominador "<<den<<endl;*/
					
					

						
						//si el signo es igual
						if((signo==1 && sign==1 )|| (signo==-1 && sign==-1)){
							
							matriz[i][k][0]=matriz[i][k][0]*den-matriz[i][k][1]*num;
								matriz[i][k][1]=matriz[i][k][1]*den;
							
							
						}
						//si el signo es diferente
						else{
							
						
								matriz[i][k][0]=matriz[i][k][1]*num + matriz[i][k][0]*den;
								matriz[i][k][1]=matriz[i][k][1]*den;
							
						}

					
				}
				
			
			}//end del primer if
			
			}
		
	
	}
	
	//convertir pivotes en 1
	for(int i =0;i<a;i++){
		
		matriz[i][b-1][0]=matriz[i][b-1][0]*matriz[i][i][1];
		matriz[i][b-1][1]=matriz[i][b-1][1]*matriz[i][i][0];
		
		matriz[i][i][0]=1;
		matriz[i][i][1]=1;
	}
	
	//reducirla
	for(int i=0;i<3;i++){
		
		int div=2;
		while(matriz[i][b-1][0]>div){
			matriz[i][b-1][0]/div;
			matriz[i][b-1][1]/div;
		}
	}
		//imprimir matriz recolectada
	cout<<" Matriz recolectada  \n";

	for(int i=0;i<a;i++){
		cout<<endl;
		for(int j=0;j<b;j++){
			
			
			cout<<matriz[i][j][0]<<" / "<<matriz[i][j][1]<<"  ";
			
		}
		
		
	}
		
		
		
		
	

	
		return 0;
}
	
	
	


