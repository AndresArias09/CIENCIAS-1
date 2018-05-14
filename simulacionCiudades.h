#ifndef SIMULACION_C
#define SIMULACION_C

#include "estructuras.h"
#include "Librerias/ListaOrdenada.h"
#include "Librerias/Lista.h"
#include "Librerias/arbolAVL.h"
#include "ciudad.h"
#include "departamento.h"
#include <time.h>

class simulacionCiudades{
	private:
		//arbol de las ciudades con sus estadisticas
		arbolAVL<territorioSimulacion> *arbolSimulacionCiudades;
		//constructor privado
		simulacionCiudades(){
			arbolSimulacionCiudades = new arbolAVL<territorioSimulacion>();
		}
		//instancia unica
		static simulacionCiudades *instance;
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
					//se añade el candidato a su territorio ordenando la lista por porcentaje
					territorio.candidatos.anadir(porcentaje,canSimulacion);
				}
				//ganador de las elecciones
				territorio.ganador = territorio.candidatos.devolverDato(0);
				//se agrega el territorio al departamento correspondiente
				departamento::getInstance()->agregarCiudad(ciuda.clave,territorio);
				//se agrega el territorio al arbol de simulaciones de ciudades
				arbolSimulacionCiudades->agregar(territorio);
			}
		}
		//retornar una estructura de tipo "territorioSimulacion" que contiene las estadisticas de una ciudad, dado el codigo
		territorioSimulacion consultarEstadisticasTerritorio(int clave){
			territorioSimulacion terri = *arbolSimulacionCiudades->retornarEstructura(clave);
			return terri;
		}
		//la instancia unica se vuelve nula, para que asi se puedan hacer nuevas simulaciones
		void limpiar(){
			delete arbolSimulacionCiudades;
			this->instance = 0;
		}
};
simulacionCiudades* simulacionCiudades::instance = 0;
#endif

