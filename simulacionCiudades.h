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

class simulacionCiudades{
	private:
		//arbol de las ciudades con sus estadisticas
		arbolAVL<territorioSimulacion> *arbolSimulacionCiudades;
		//arbol de los departamentos con sus estadisticas
		arbolAVL<departamentoSimulacion> *arbolSimulacionDepartamentos;
		//constructor privado
		simulacionCiudades(){
			arbolSimulacionCiudades = new arbolAVL<territorioSimulacion>();
			arbolSimulacionDepartamentos = new arbolAVL<departamentoSimulacion>();
		}
		//instancia unica
		static simulacionCiudades *instance;
		//genera las estadisticas por departamento de las elecciones a alcaldias locales
		void estadisticasDepartamento(){
			Lista<departament> *departamentos = departamento::getInstance()->consultarDepartamentos();
			int cantidadPartidos = partido::getInstance()->getCantidad();
			long long totalVotos, votosBlanco, votosNulos, abstencion,censo;
			int totalHombres,totalMujeres,cantidadCiudades;
			for(int i=0;i<departamentos->getTam();i++){
				totalVotos = votosBlanco = votosNulos = abstencion = censo = 0;
				totalHombres = totalMujeres = cantidadCiudades = 0;
				//departamento
				departament depart = departamentos->devolverDato(i);
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
					//totales por partido
					depSimulacion.totalByPartido[candidatoGanador.partido-1]++;
					//total mujeres y hombres
					if(candidatoGanador.sexo.compare("Mujer")==0){
						totalMujeres++;
					}
					else{
						totalHombres++;
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
		//genera las estadisticas por ciudad de las elecciones a alcaldias locales
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
				territorio.ciu = ciuda;
				territorio.clave = ciuda.clave;
				candidatosByCiudad = ciuda.candidatos; //candidatos de la ciudad
				censo = ciuda.censo; //censo electoral de la ciudad
				//voto en blanco
				votosBlanco = 0+rand()%(censo+1-0);
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
				srand(time(NULL)); 
				//votos para cada uno de los candidatos de la ciudad
				for(int j=0;j<candidatosByCiudad.getTam();j++){
					candidatoSimulacion canSimulacion;
					candidate candi;
					//candidato
					candi = *candidatosByCiudad.devolverDato(j);
					canSimulacion.can = candi;
					//votos
					//ultimo candidato al que se le generan los votos
					if(j==candidatosByCiudad.getTam()-1){
						votos = censo;
					}
					else{
						votos = 0+rand()%(censo+1-0);	
					}
					canSimulacion.votos = votos;
					censo = censo - votos;
					//porcentaje
					porcentaje = ((float)votos/(float)censoVotante)*100;
					canSimulacion.porcentaje = porcentaje;
					//se a�ade el candidato a su territorio ordenando la lista por porcentaje
					territorio.candidatos.anadir(porcentaje,canSimulacion);
				}
				//ganador de las elecciones
				territorio.ganador = territorio.candidatos.devolverDato(0);
				//se agrega el territorio al departamento correspondiente
				departamento::getInstance()->agregarCiudad(ciuda.departamento,territorio);
				//se agrega el territorio al arbol de simulaciones de ciudades
				arbolSimulacionCiudades->agregar(territorio);
			}
		}
	public:
		//se obtiene la instancia unica
		static simulacionCiudades *getInstance(){
			if(instance==0){
				instance = new simulacionCiudades();
			}
			return instance;
		}
		//se inicia la simulacion de elecciones a alcaldias locales
		void iniciar(){
			estadisticasCiudades();
			estadisticasDepartamento();
		}
		//retorna una estructura de tipo "territorioSimulacion" que contiene las estadisticas de una ciudad, dado el codigo
		territorioSimulacion consultarEstadisticasTerritorio(int clave){
			territorioSimulacion terri = *arbolSimulacionCiudades->retornarEstructura(clave);
			return terri;
		}
		//retorna una estructura de tipo "departamentoSimulacion" que contiene las estadisticas de un departamento,dado el codigo
		departamentoSimulacion consultarEstadisticasDepartamento(int clave){
			departamentoSimulacion depSimulacion = *arbolSimulacionDepartamentos->retornarEstructura(clave);
			return depSimulacion;
		}
		//la instancia unica se vuelve nula, para que asi se puedan hacer nuevas simulaciones
		void limpiar(){
			delete arbolSimulacionCiudades;
			delete arbolSimulacionDepartamentos;
			this->instance = 0;
		}
};
simulacionCiudades* simulacionCiudades::instance = 0;
#endif

