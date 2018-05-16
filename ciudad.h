#ifndef CIUDAD
#define CIUDAD
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "Librerias/arbolAVL.h"
#include "facade.h"
#include "estructuras.h"
#include "departamento.h"

//esta clase gestiona la lectura, escritura y la busqueda en el archivo ciudad.txt
class ciudad: public facade{
	private:
		//arbol AVL
		arbolAVL<city> *arbolCiudades;
		//instancia unica
		static ciudad *instance;
		//constructor privado
		ciudad(){
			arbolCiudades = new arbolAVL<city>();
			this->cantidad = 0;
			this->leido = false;
			leerRegistros();
		}
	public:
		//se obtiene la instancia unica
		static ciudad *getInstance(){
			if(instance == 0){
				instance = new ciudad();
			}
			return instance;
		}
		//se leen los registros del archivo
		void leerRegistros(){
			if(this->leido==false){
				int clave;
				string nombre;
				int departamento;		
				long long censo;
				city ciuda;
				//archivo de entrada
				ifstream archEntrada("Archivos/ciudades.txt", ios::in);
				if (!archEntrada.good()){
					cerr << "No se pudo abrir el archivo ciudades" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()){
					archEntrada >> clave;
					archEntrada >> nombre;
					archEntrada >> departamento;
					archEntrada >> censo;
					ciuda.clave = clave;
					ciuda.nombre = nombre;
					ciuda.departamento = departamento;
					ciuda.censo = censo;
					this->agregarCiudad(ciuda);
				}
				archEntrada.close();
				this->leido = true;
			} 
		}
		//se agrega una ciudad al arbol avl
		void agregarCiudad(city ciudad){
			city *ciu;
			ciudad.clave = this->cantidad++;
			arbolCiudades->agregar(ciudad);
			ciu = arbolCiudades->retornarEstructura(ciudad.clave);
			//se agrega la ciudad al departamento
			departamento::getInstance()->agregarCiudad(ciudad.departamento,ciu);
		}
		//se consultan todas las ciudades habilitadas para el censo electoral
		Lista<city> *consultarCiudades(){
			Lista<city> *lista = arbolCiudades->recorridoInOrden();
			return lista;
		}
		//retorna una lista de apuntadores de candidatos asociados a una ciudad
		Lista<candidate*> getCandidatoByCiudad(int clave){
			city *ciudad = arbolCiudades->retornarEstructura(clave);
			Lista<candidate*> lista = ciudad->candidatos;
			return lista;
		}
		//agrega un candidato a su ciudad correspondiente
		void agregarCandidato(candidate *candidato,int territorio){
			city *ciu = arbolCiudades->retornarEstructura(territorio);
			ciu->candidatos.anadir_final(candidato);
		}
		//retorna el nombre de la ciudad dado el codigo
		string getNombreCiudad(int clave){
			city *ciu = arbolCiudades->retornarEstructura(clave);
			return ciu->nombre;
		}
		//retorna el censo de una ciudad
		long long getCenso(int clave){
			city *ciu=arbolCiudades->retornarEstructura(clave);
			return ciu->censo;
		}
		//retorna el censo nacional
		long long getCensoTotal(){
			Lista <city> *cities=arbolCiudades->recorridoInOrden();
			long long censototal=0;
			for(int i=1;i<cities->getTam();i++){
				censototal+=getCenso(i);
			}
			return censototal;
		}
		//retorna de lista de candidato presidenciales
		Lista<candidate*>getCandidatoPresidencial(){
			city *ciu = arbolCiudades->retornarEstructura(0);
			Lista <candidate*> candidatoszona=ciu->candidatos;
			Lista <candidate*> candidatosp;
			candidate *can;
			int i;
			for (i=0;i<candidatoszona.getTam();i++){
				can=candidatoszona.devolverDato(i);
				if(can->formulaVi!=0 && can->estado==1){
					candidatosp.anadir_final(can);
				}
			}
			return candidatosp; 
		}
		//retorna el candidato presidencial segun el partido
		candidate *getCandidatoPByPartido(int partido){
			Lista<candidate*> lista = ciudad::getInstance()->getCandidatoByCiudad(0);
			candidate *presi = NULL;
			for(int i=0;i<lista.getTam();i++){
				presi = lista.devolverDato(i);
				if(presi->partido==partido && presi->estado==1){
					i=lista.getTam();
				}
			}
			return presi;
		}
		//retona un apuntador a la ciudad dado su codigo
		city *getCiudad(int clave){
			return arbolCiudades->retornarEstructura(clave);
		}
		//retonar el codigo del departamento de una ciudad
		int getDepartamento(int clave){
			city *ciu=arbolCiudades->retornarEstructura(clave);
			return ciu->departamento;
		}
		
		Lista<long long> getVotosPbyCiudad(int clave){
			//valor objetivo->censo de la ciudad
			long long objetivo=getCenso(clave);
			double esteVoto=0;
			double votos=0;
			long long verdaderosVotos=0;
			//semilla de tiempo
			srand(time(NULL));
			//se necesita lista de numeros aleatorios y otra de los votos como tal
			Lista <long long> aleatorios;
			Lista <long long> lista;
			//captura los candidatos
			Lista<candidate*> candidatos=getCandidatoPresidencial();
			int i;
			//tam + 3 ya que son los candidatos mas votos en blanco, nulos y abstinencia
			for (i=0;i<candidatos.getTam()+3;i++){
				esteVoto=rand();
				votos+=esteVoto;
				aleatorios.anadir_final(esteVoto);
			}
			
			//votos de los candidatos 
			//logica tomada de excel XD
			for (i=0;i<aleatorios.getTam()-1;i++){
				esteVoto=(rand()/votos)*objetivo;
				verdaderosVotos+=esteVoto;
				lista.anadir_final(esteVoto);
			}
			//estos serian los votos de abstinencia
			if(objetivo>verdaderosVotos){
				lista.anadir_final((objetivo-verdaderosVotos));
			}else{
				lista.anadir_final((verdaderosVotos-objetivo));
			}
			
			
			return lista;
		}
		Lista <Lista <long long> > getVotosCiudades (){
			Lista <city> *ciudades=consultarCiudades();
			Lista <Lista <long long> > lista;
			Lista <long long> auxiliar;
			int i;
			for (i=0;i<ciudades->getTam();i++){
				auxiliar=getVotosPbyCiudad(i);
				lista.anadir_final(auxiliar);
			}
			return lista;
		}
		
		Lista <long long> getVotosPTotal(Lista <Lista <long long> > lista){
			Lista <long long> totales;
			int i=0;
			int j=0;
			long long total;
			for (i=0;i<lista.devolverDato(i).getTam();i++){
				total=0;
				for(j=1;j<lista.getTam();j++){
					total+=lista.devolverDato(j).devolverDato(i);
				}
				totales.anadir_final(total);
			}
			return totales;
		}
		Lista <float> getPorcentajesPTotal(Lista <long long>enviada){
			Lista <float> porcentajes;
			float porcentaje=0.0;
			int i;
			for(i=0;i<enviada.getTam();i++) {
				porcentaje= ((float)enviada.devolverDato(i)*100.0)/(float)getCensoTotal();
				porcentajes.anadir_final(porcentaje);
			}
			return porcentajes;
		}
		Lista < Lista <float> > getPorcentajesCiudades (Lista <Lista <long long> > simulacion ){
			int i;
			int j;
			Lista <Lista <float> > porcentajes;
			float porcentaje=0.0;
			for (i=1;i<simulacion.getTam();i++){
				Lista <float>  auxiliar;
				for(j=0;j<simulacion.devolverDato(i).getTam();j++){
					porcentaje= ((float)simulacion.devolverDato(i).devolverDato(j)/(float)getCenso(i))*100.0;
					auxiliar.anadir_final(porcentaje);
				}
				porcentajes.anadir_final(auxiliar);
			}
			return porcentajes;
		}
		Lista <long long> getVotosPSexo (Lista <long long>votostotales){
			Lista <candidate*>candidatos=getCandidatoPresidencial();
			candidate *can;
			Lista <long long> retorno;
			int i;
			long long hombres;
			long long mujeres;
			for(i=0;i<candidatos.getTam();i++){
				can=candidatos.devolverDato(i);
				if(can->sexo.compare("Mujer")==0){
					mujeres+=votostotales.devolverDato(i);
				}
				else{
					hombres+=votostotales.devolverDato(i);
				}
			}
			retorno.anadir_final(mujeres);
			retorno.anadir_final(hombres);
			
			return retorno;
		}
};
ciudad* ciudad::instance = 0;
#endif
