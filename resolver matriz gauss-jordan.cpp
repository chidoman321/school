
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
	long long matriz[a][b][2];
	
	
	cout<<" Solo elementos enteros  \n";
	
	//recolectar la matriz a resolver
	for(int i=0;i<a;i++){
		
		for(int j=0;j<b;j++){
			cout<<" Dame el elemento  de la fila"<<(i+1)<<" y columna "<<(j+1)<<"  ";
			cin>>matriz[i][j][0];
			matriz[i][j][1]=1;
		}
		
		
		
	}
	
		cout<<" Matriz recolectada  \n"<<endl;
	
	//imprimir matriz recolectada

	for(int i=0;i<a;i++){
		cout<<endl;
		for(int j=0;j<b;j++){
			
			
			cout<<matriz[i][j][0]<<" / "<<matriz[i][j][1]<<"  ";
			
		}
		
		
		
	}
	
	cout<<endl;
	
	
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
				long long piv_num= matriz[l][j][0]; // a c //-4
				long long piv_den= matriz[l][j][1]; // b d // 2
				long long ele_num= matriz[i][j][0]; 
				long long ele_den= matriz[i][j][1]; 
				int signo=-1;
				int sign=-1;
				/*cout<<" pivote "<<piv_num<<"  "<<piv_den<<endl;
				cout<<" pivote "<<l<<endl;*/
				
				

	
			

				
				if(piv_num>=0 && piv_den>=0){
					signo=1;
				}
				if(ele_num>=0 && ele_den>=0){
					sign=1;
				}
				
				//hacer 0 el elemento actual y los elementos de las demas columnas
				for(int k=0;k<b;k++){
					

					
					//numerador temporal
					long long num=(abs(ele_num)*(matriz[l][k][0]*abs(piv_den) ));
					//denominador temporal
					long long  den=(abs(ele_den)*(matriz[l][k][1]*abs(piv_num)) );
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
						
						if(matriz[i][k][1]==1 || matriz[i][k][1]==0 || matriz[i][k][0]==0){
									}else{
									int div=2;
									while(div<=abs(matriz[i][k][0])){
										if(matriz[i][k][1]%div==0 && matriz[i][k][0]%div==0){
											cout<<endl;
											cout<<" modulo "<<"  "<<div<<matriz[i][k][1]%div;
											cout<<"elemento "<<matriz[i][k][0]<<" "<<matriz[i][k][1];
											matriz[i][k][1]=matriz[i][k][1]/div;
											matriz[i][k][0]=matriz[i][k][0]/div;
											cout<<endl;
											
											cout<<" modulo "<<"  "<<div<<matriz[i][k][1]%div;
											cout<<"elemento "<<matriz[i][k][0]<<" "<<matriz[i][k][1];
										}else{
										div++;
										}
									}
							
						}
					
					
					
					
				
					
					
					
					
					
				}
			}//end del primer if
			
			}
		
	
	}
	/*
	//simplificar
	for(int i=0;i<a;i++){
			for(int j=0;i<b;j++){
cout<<matriz[i][j][0]<<" / "<<matriz[i][j][1]<<"  ";
			
		
			}
	}
}*/
	
	/*
	for(int i=1;i<a;i++){
		
			for(int j=0;j<i;j++){
				int div=2;
				while(abs(matriz[i][j][0]-matriz[i][j][1])%2==0   && matriz[i][j][0]!=0){
					if((matriz[i][j][0]%div==0) && (matriz[i][j][1]%div)==0){
						matriz[i][j][0]=matriz[i][j][0]/=div;
						matriz[i][j][1]=matriz[i][j][1]/=div;
					}
					else{
						div++;
					}
					
				}
			
			}
			
			}
			
				*/

	/*for(int i=0;i<a;i++){
		
		for(int j=0;j<b;j++){
		int div=2;
		
		while(div<matriz[i][j][0] && div<matriz[i][j][1]){
			
	
			if((matriz[i][j][0]%div)==0 && (matriz[i][j][1]%div)==0){
				matriz[i][j][0]/div;
				matriz[i][j][1]/div;
			}
			
			
			div++;
		}
	}*/
	
	cout<<endl;
	//reducir o simplificar
/*
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			
			int div=2;
			while(div<matriz[i][j][1]){
				
				if((matriz[i][j][0] % div)==0 && (matriz[i][j][1] % div)==0){
					matriz[i][j][0]/=div;
					matriz[i][j][1]/=div;
					
				}
				else{
					div++;
				}
				
			}
			
			
		}
		
		
	}*/
	
		cout<<" Matriz Guass  \n"<<endl;
	for(int i=0;i<a;i++){
		cout<<endl;
				//int div=2;
		for(int j=0;j<b;j++){
			/*while((matriz[i][j][0] % div)==0 && (matriz[i][j][1] % div)==0){
				matriz[i][j][0]/=2;
				matriz[i][i][1]/=2;
			}*/
			
			cout<<matriz[i][j][0]<<" / "<<matriz[i][j][1]<<"  ";
			
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
				int sign=-1;/*
					cout<<" pivote"<< piv_num<<" "<< piv_den;
					cout<<" pivote"<< ele_num<<" "<< ele_den;*/

	
			

				
				if(piv_num>=0 && piv_den>=0){
					signo=1;
				}
				if(ele_num>=0 && ele_den>=0){
					sign=1;
				}
				//hacer 0 el elemento actual y los elementos de las demas columnas
				for(int k=0;k<b;k++){
					

					
					//numerador temporal
					long long num=(abs(ele_num)*(matriz[l][k][0]*abs(piv_den) ));
					//denominador temporal
					long long den=(abs(ele_den)*(matriz[l][k][1]*abs(piv_num)) );
					/*cout<<" numerador "<<num<<endl;
					cout<<" denominador "<<den<<endl;*/
					/*
					cout<<" num"<< num<<endl;
					cout<<" den"<< den<<endl;*/

						
						//si el signo es igual
						if((signo==1 && sign==1 )|| (signo==-1 && sign==-1)){
							
							matriz[i][k][0]=matriz[i][k][0]*den-matriz[i][k][1]*num;
								matriz[i][k][1]=matriz[i][k][1]*den;
							//	cout<<"positivo"<<endl;
							
							
							
						
							
							
							
						}
						//si el signo es diferente
						else{
							
						
								matriz[i][k][0]=matriz[i][k][0]*den + matriz[i][k][1]*num  ;
								matriz[i][k][1]=matriz[i][k][1]*den;
						//	cout<<"entraste"<<endl;
						
						
							
						}
						
						if(matriz[i][k][1]==1 || matriz[i][k][1]==0 || matriz[i][k][0]==0){
									}else{
									int div=2;
									while(div<=abs(matriz[i][k][0])){
										if(matriz[i][k][1]%div==0 && matriz[i][k][0]%div==0){
											cout<<endl;
											cout<<" modulo "<<"  "<<div<<matriz[i][k][1]%div;
											cout<<"elemento "<<matriz[i][k][0]<<" "<<matriz[i][k][1];
											matriz[i][k][1]=matriz[i][k][1]/div;
											matriz[i][k][0]=matriz[i][k][0]/div;
											cout<<endl;
											
											cout<<" modulo "<<"  "<<div<<matriz[i][k][1]%div;
											cout<<"elemento "<<matriz[i][k][0]<<" "<<matriz[i][k][1];
										}else{
										div++;
										}
									}
							
						}

					
				}
				
			
			}//end del primer if
			
			}
		
	
	}
	cout<<endl;
	
	//convertir pivotes en 1

	for(int i =0;i<a;i++){
		
		matriz[i][b-1][0]=matriz[i][b-1][0]*matriz[i][i][1];
		matriz[i][b-1][1]=matriz[i][b-1][1]*matriz[i][i][0];
		
		matriz[i][i][0]=1;
		matriz[i][i][1]=1;
	}
	
/*
	for(int i=0;i<3;i++){
		
		int div=2;
		while(matriz[i][b-1][0]>div){
			matriz[i][b-1][0]/div;
			matriz[i][b-1][1]/div;
		}
	}*/
		//imprimir matriz recolectada
		cout<<" Matriz Guass-Jordan \n"<<endl;
	for(int i=0;i<a;i++){
		cout<<endl;

		for(int j=0;j<b;j++){
			
			
				
			cout<<matriz[i][j][0]<<" / "<<matriz[i][j][1]<<"  ";
			
		}
		
		
	}
		
		
		
		
	

	
		return 0;
}
	

	


