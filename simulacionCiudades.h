/**
	@file simulacionCiudades.h
	@brief Clase que gestiona la simulacion de elecciones a alcaldias locales
	
	Este archivo genera la simulacion de elecciones a alcaldias locales, con sus estadisticas a nivel de ciudad, departamento y a nivel nacional
	
	@author Andres Arias & Isabel Perez
	
	@date 8/05/2018,28/05/2018
*/
#ifndef SIMULACION_C
#define SIMULACION_C

#include "estructuras.h"
#include "Librerias/ListaOrdenada.h"
#include "Librerias/Lista.h"
#include "Librerias/arbolAVL.h"
#include "ciudad.h"
#include "departamento.h"
#include <time.h>
#include "partido.h"
#include <sstream>
class simulacionCiudades{
	private:
		//arbol de las ciudades con sus estadisticas
		arbolAVL<territorioSimulacion> *arbolSimulacionCiudades;
		//arbol de los departamentos con sus estadisticas
		arbolAVL<departamentoSimulacion> *arbolSimulacionDepartamentos;
		//arbol en los que se guardan las ciudades en las que se hace simulacion del proceso electoral
		//segun su departamento
		arbolAVL<departament> *arbolDepartamentos;
		//estructura que contiene las estadisticas de alcaldias locales a nivel nacional
		simulacionNacionales *nacionales;
		//instancia unica
		static simulacionCiudades *instance;
		/** 
			@brief metodo constructor 
		*/
		simulacionCiudades(){
			arbolSimulacionCiudades = new arbolAVL<territorioSimulacion>();
			arbolSimulacionDepartamentos = new arbolAVL<departamentoSimulacion>();
			arbolDepartamentos = new arbolAVL<departament>();
			this->nacionales = new simulacionNacionales();
			this->nacionales->totalesByPartido = new int[partido::getInstance()->getCantidad()];
		}
		/** 
			@brief Funcion que genera todas las estadisticas a nivel departamentos de las elecciones a alcaldias locales
		*/
		void estadisticasDepartamento(){
			Lista<departament> *departamentos = this->arbolDepartamentos->recorridoInOrden();
			int cantidadPartidos = partido::getInstance()->getCantidad();
			long long totalVotos, votosBlanco, votosNulos, abstencion,censo;
			int totalHombres,totalMujeres,cantidadCiudades;
			for(int i=0;i<departamentos->getTam();i++){
				totalVotos = votosBlanco = votosNulos = abstencion = censo = 0;
				totalHombres = totalMujeres = cantidadCiudades = 0;
				//departamento
				departament depart = departamentos->devolverDato(i);
				if(depart.ciudades.getTam()!=0){
					//estructura que contiene al departamento con sus estadisticas
					departamentoSimulacion depSimulacion;
					depSimulacion.dep = depart;
					depSimulacion.clave = depart.clave;
					depSimulacion.totalByPartido = new int[cantidadPartidos];
					//se inicializa el arreglo
					for(int k=0;k<cantidadPartidos;k++){
						depSimulacion.totalByPartido[k] = 0;
					}
					//ciudades asociadas a ese departamento
					Lista<territorioSimulacion> ciudades = depart.ciudades;
					cantidadCiudades = ciudades.getTam();
					//se recorre cada ciudad del departamento
					for(int j=0;j<ciudades.getTam();j++){
						territorioSimulacion ciud = ciudades.devolverDato(j);
						candidate candidatoGanador = ciud.ganador.can;
						//total votos
						totalVotos = totalVotos + ciud.censoVotante;
						//total votos en blanco
						votosBlanco = votosBlanco + ciud.votosBlanco;
						//total votos nulos
						votosNulos = votosNulos + ciud.votosNulos;
						//total abstencion
						abstencion = abstencion + ciud.abstencion;
						//se verifica si el voto en blanco gano en la eleccion de la ciudad
						if(ciud.votosBlanco<ciud.ganador.votos){
							//totales por partido
							depSimulacion.totalByPartido[candidatoGanador.partido-1]++;
							//total mujeres y hombres
							if(candidatoGanador.sexo.compare("Mujer")==0){
								totalMujeres++;
							}
							else{
								totalHombres++;
							}
						}
						else{
							depSimulacion.ciudadesVotoBlanco.anadir_final(ciud);
						}
						censo = censo + ciud.ciu.censo;
					}
					depSimulacion.totalVotos = totalVotos;
					depSimulacion.votosBlanco = votosBlanco;
					depSimulacion.votosNulos = votosNulos;
					depSimulacion.abstencion = abstencion;
					depSimulacion.totalHombres = totalHombres;
					depSimulacion.totalMujeres = totalMujeres;
					depSimulacion.censo = censo;
					//cantidad de ciudades
					depSimulacion.cantidadCiudades = cantidadCiudades;
					//se agrega al arbol de departamentos con estadisticas
					arbolSimulacionDepartamentos->agregar(depSimulacion);
				}
			}
		}
		/** 
			@brief Funcion que genera todas las estadisiticas a nivel ciudades de las elecciones a a alcaldias locales
		*/
		void estadisticasCiudades(){
			//lista de todas las ciudades en las que se haran elecciones
			Lista<city> *ciudadesHabilitadas = ciudad::getInstance()->consultarCiudades(); 
			long long censo,censoVotante;
			long long votosBlanco;
			long long votosNulos;
			long long abstencion;
			long long votos;
			float porcentaje;
			//comienza en uno porque el codigo 0 corresponde a "Colombia"
			for(int i=1;i<ciudadesHabilitadas->getTam();i++){
				srand(time(NULL));
				city ciuda;
				territorioSimulacion territorio;
				Lista<candidate*> candidatosByCiudad;
				ciuda = ciudadesHabilitadas->devolverDato(i); //ciudad
				//se verifica que la ciudad tenga candidatos
				if(ciuda.candidatos.getTam()!=0){
					territorio.ciu = ciuda;
					territorio.clave = ciuda.clave;
					candidatosByCiudad = ciuda.candidatos; //candidatos de la ciudad
					censo = ciuda.censo; //censo electoral de la ciudad
					//voto en blanco
					votosBlanco = 0+rand()%((censo/6)+1-0);
					territorio.votosBlanco = votosBlanco;
					censo = censo - votosBlanco;
					//votos nulos
					votosNulos = 0+rand()%(censo+1-0);
					territorio.votosNulos = votosNulos;
					censo = censo - votosNulos;
					//abstencion
					abstencion = 0+rand()%(censo+1-0);
					territorio.abstencion = abstencion;
					censo = censo - abstencion;
					//censo que va a votar, bien sea por un candidato o por el voto en blanco
					censoVotante = censo + votosBlanco;
					territorio.censoVotante = censoVotante;
					//votos para cada uno de los candidatos de la ciudad
					srand(time(NULL));
					int dividendo;
					for(int j=0;j<candidatosByCiudad.getTam();j++){
						candidate candi;
						//candidato
						candi = *candidatosByCiudad.devolverDato(j);
						//se verifica que el candidato este habilitado
						if(candi.estado!=0){
							candidatoSimulacion canSimulacion;
							canSimulacion.can = candi;
							//votos
							//ultimo candidato al que se le generan los votos
							if(j==candidatosByCiudad.getTam()-1){
								votos = censo;
							}
							else{
								dividendo = rand()%5+1;
								votos = (censo/dividendo)+rand()%((censo/dividendo)+1-(censo/dividendo));	
							}
							canSimulacion.votos = votos;
							censo = censo - votos;
							//porcentaje
							porcentaje = ((float)votos/(float)censoVotante)*100;
							canSimulacion.porcentaje = porcentaje;
							//se añade el candidato a su territorio ordenando la lista por porcentaje
							territorio.candidatos.anadir(porcentaje,canSimulacion);
						}
					}
					//ganador de las elecciones
					territorio.ganador = territorio.candidatos.devolverDato(0);
					//se agrega el territorio al departamento correspondiente
					agregarCiudad(ciuda.departamento,territorio);
					//se agrega el territorio al arbol de simulaciones de ciudades
					arbolSimulacionCiudades->agregar(territorio);
				}
			}
		}
		/** 
			@brief Funcion que genera las estadisticas a nivel nacional de las elecciones a alcaldias locales
		*/
		void totalesNacionales(){
			Lista<departamentoSimulacion> *departamentos = arbolSimulacionDepartamentos->recorridoInOrden();
			int totalHombres = 0,totalMujeres=0;
			int cantidadPartidos = partido::getInstance()->getCantidad();
			int totalCiudades=0;
			//se recorre cada uno de los departamentos
			for(int i=0;i<departamentos->getTam();i++){
				departamentoSimulacion dep = departamentos->devolverDato(i);
				totalCiudades = dep.cantidadCiudades + totalCiudades;
				totalHombres = totalHombres + dep.totalHombres;
				totalMujeres = totalMujeres + dep.totalMujeres;
				for(int j=0;j<cantidadPartidos;j++){
					this->nacionales->totalesByPartido[j] = this->nacionales->totalesByPartido[j] + dep.totalByPartido[j];
				}
				for(int k=0;k<dep.ciudadesVotoBlanco.getTam();k++){
					this->nacionales->ciudadesVotoBlanco.anadir_final(dep.ciudadesVotoBlanco.devolverDato(k));
				}
			}
			this->nacionales->totalHombres = totalHombres;
			this->nacionales->totalMujeres = totalMujeres;
			this->nacionales->totalCiudades = totalCiudades;
		}
		/** 
			@brief Funcion que agrega una ciudad (con sus respectivas estadisticas) a su correspondiente departamento
			@param clave int, corresponde a la clave del departamento al que se va a agregar la ciudad
			@param ciudad territorioSimulacion, corresponde a la estructura que contiene las estadisticas de una ciudad 
		*/
		void agregarCiudad(int clave,territorioSimulacion ciudad){
			departament *dep = arbolDepartamentos->retornarEstructura(clave);
			dep->ciudades.anadir_final(ciudad); 
		}
		/** 
			@brief Funcion que carga los departamentos al arbol AVL de la clase
		*/
		void cargarDepartamentos(){
			Lista<departament> departamentos = *departamento::getInstance()->consultarDepartamentos();
			for(int i=0;i<departamentos.getTam();i++){
				this->arbolDepartamentos->agregar(departamentos.devolverDato(i));
			}
		}
	public:
		/** 
			@brief Funcion que devuelve la instancia unica de la clase (patron de diseño Singleton) 
			@returns instance statc *simulacionCiudades
		*/
		static simulacionCiudades *getInstance(){
			if(instance==0){
				instance = new simulacionCiudades();
			}
			return instance;
		}
		/** 
			@brief Funcion que inicia la simulacion a elecciones de alcaldias locales
		*/
		void iniciar(){
			cargarDepartamentos();
			estadisticasCiudades();
			estadisticasDepartamento();
			totalesNacionales();
		}
		/** 
			@brief Funcion que retona las estadisticas de un determinado territorio
			@param clave int, corresponde al codigo de la ciudad que se desea consultar
			@returns retornar una estrucutra de tipo territorioSimulacion que contiene todas las estadisticas de una ciudad
		*/
		territorioSimulacion consultarEstadisticasTerritorio(int clave){
			territorioSimulacion terri = *arbolSimulacionCiudades->retornarEstructura(clave);
			return terri;
		}
		/** 
			@brief Funcion que retona las estadisticas de un determinado departamento
			@param clave int, corresponde al codigo del departamento que se desea consultar
			@returns retornar una estrucutra de tipo departamentoSimulacion que contiene todas las estadisticas de un departamento
		*/
		departamentoSimulacion consultarEstadisticasDepartamento(int clave){
			departamentoSimulacion depSimulacion = *arbolSimulacionDepartamentos->retornarEstructura(clave);
			return depSimulacion;
		}
		/** 
			@brief Funcion que retona las estadisticas nacionales de las elecciones a alcaldias locales
			@returns retornar una estrucutra de tipo simulacionNacionales que contiene todas las estadisticas a nivel nacional
		*/
		simulacionNacionales *consultarEstadisticasNacionales(){
			return this->nacionales;
		}
		/** 
			@brief Funcion reinicia la instancia unica para poder volver a hacer la simulacion
		*/
		static void limpiar(){
			instance = NULL;
		}
		/** 
			@brief Funcion que libera memoria, eliminando los atributos de la clase
		*/
		void liberar(){
			delete arbolSimulacionCiudades;
			delete arbolSimulacionDepartamentos;
			delete instance;
			delete arbolDepartamentos;
		}
		ListaO<string> ciudadesAbstencion(float porcentaje){
			Lista<territorioSimulacion> lista = *this->arbolSimulacionCiudades->recorridoInOrden();
			ListaO<string> ordenada;
			for(int i=0;i<lista.getTam();i++){
				float porcen = ((float)lista.devolverDato(i).abstencion/(float)lista.devolverDato(i).ciu.censo)*100;
				if(porcen<porcentaje){
					std::ostringstream ss;
					ss<<porcen;
					ordenada.anadir(porcen,lista.devolverDato(i).ciu.nombre +" "+ss.str());
				}
			}
			return ordenada;
		}
};
simulacionCiudades* simulacionCiudades::instance = 0;
#endif

