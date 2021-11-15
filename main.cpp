#include <iostream> 
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Elevator {
	public:
		//Atributes
		bool doorLocked =false;
		bool panicButton=false;
		bool maxSize = false;
		
		
		//Methods
		// method 1
		void changeDoor(){
			if (doorLocked ==false){
				doorLocked=true;
				panicButton=true;
			}else{
				doorLocked=false;
				panicButton=false;
			}
		}
		// method 2
		void changeButton(){
			if (panicButton==false){
				panicButton=true;
				doorLocked=true;
			}else{
				panicButton=false;
				doorLocked=false;
			}
			cout<<"El boton de panico ha sido activado el sistema detendra el ascensor en la puerta mas cercana, Salga en orden.\n";
		}
		// method 3 
		string moversePiso(){
			if ((doorLocked == false) && (panicButton==false) && (maxSize==false)){
				int opc;
				int ultimo;
			cout<<"A que piso desea dirigirse?\n 0 al 7\n";
			cin >> opc;
			while (opc!=-5){
				if (opc >= 0 && opc <= 7){
				switch (opc){
				case 0:
					cout << "Estamos moviendonos hacia la planta baja";
					opc = -5;
					break;
				case 1:
					cout << "Estamos moviendonos hacia el primer piso";
					opc = -5;
					break;
				case 2:
					cout<<"Estamos moviendonos hacia el segundo piso";
					opc = -5;
					break;
				case 3:
					cout<<"Estamos moviendonos hacia el tercer piso";
					opc = -5;
					break;
				case 4:
					cout<<"Estamos moviendonos hacie el cuarto piso";
					opc = -5;
					break;
				case 5:
					cout<<"Estamos moviendonos hacia el quinto piso";
					opc = -5;
					break;
				case 6:
					cout<<"Estamos moviendonos hacia el sexto piso";
					opc = -5;
					break;
				case 7:
					cout<<"estamos moviendonos hacia el septimo piso";
					opc = -5;
					break;
			}
			}else{
				cout<<"Numero invalido, intente de nuevo\n";
				cin >> opc;
			}
			}
			}else{
				cout<<"Las puertas del elevador estan abiertas, el ascensor no se movera.\n";
			}
			
		}
		
	void ascensorLleno(){
		maxSize = true;
	}

};

// cuerpo del codigo
int main(){
	float peso;
	float pesoAcumulado = 0;
	float pesoMaximo = 300;
	int cond1=1;
	
	Elevator elevator;
//	elevator.saludar();
//	elevator.changeButton();
//	elevator.changeDoor();
//	elevator.moversePiso();
	
	// validacion del peso mayor y menor
	while (peso!=-5){
		int comando;
		cout<< "bienvenidos a nuestro asensor, por favor digite su peso aproximado: \n";
		while(cond1==1){
		cout<<"Ingrese su peso aproximado\n";
		cin >> peso;
		if(peso>=19 && peso<=120){
			pesoAcumulado += peso;
			cout<<"Va a ingresar otro peso?\n 1. Si \n 2. No\n";
			cin >>cond1;
		}else{
			cout<<"El valor ingresado no corresponde a un peso real, porfavor digite correctamente\n";
		}	
		}
		if(pesoAcumulado>300){
			cout<<"El peso maximo ha sido superado, el ascensor no se movera, les pedimos porfavor se retiren las personas necesarias para que el ascensor continue su transcurso\n";
			elevator.ascensorLleno();
			pesoAcumulado = 5;
			break;
		}else{
			cout<<"El ascensor cerrara sus puertas\n";
			cond1 = 0;
			peso = -5;
		}
		while(pesoMaximo>pesoAcumulado){
			cout<<"Que vamos hacer?\n 1. para movernos entre los pisos. \n 2. Abrir/Cerrar Puerta. \n 3. para activar el boton de panico\n";
		cin>>comando;
		if((comando>=1)&&(comando<=3)){
			switch(comando){
			case 1:
				cout<<"ha seleccionado moverse entre los pisos.\n";
				elevator.moversePiso();
				break;
			case 2:
				elevator.changeDoor();
				break;
			case 3:
				elevator.changeButton();
				break;
		}
		};	
		}
		
	};
	
	return 0;
}
