
/*
 * Proyecto 
 * Rashell Aleck Jiménez Almánzar
 * A01715359
 * 20/09/2026
 */

/*
 * Clase Emergencia
 * Representa una Emergencia con id, tipo, prioridad, tiempo
 * de espera y distancia.
 *
 */

#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include <string>

class Emergencia {
   private:
    std::string id;             // id de la Emergencia
    std::string type;           // Tipo de la Emergencia
    int priority;               // Prioridad de la Emergencia
    int waitTime;               // Tiempo que lleva la emergencia 
                                // esperando a que le asignen 
                                // ambulancia
    double distance;            // Distancia desde el hospital 
                                // al punto de Emergenicas

   public:
    /**
     * Constructor por default.
     *
     * Inicializa todos los atributos con valores vacíos o cero,
     * creando un objeto Emergencia con datos no definidos.
     *
     * @param
     * @return Objeto Emergencia inicializado con valores por defecto.
     */
     Emergencia()
        : id(""),
          type(""),
          priority(0),
          waitTime(0),
          distance(0.0) {};

    /**
     * Constructor con parámetros.
     *
     * Permite inicializar un objeto Emergencia con valores específicos.
     *
     * @param i id de la Emergencia.
     * @param t tipo de la Emergencia.
     * @param p prioridad de la Emergencia.
     * @param w Tiempo de espera en que le asignen ambulancia.
     * @param d Distancia. 
     * @return Objeto Emergencia con valores asignados.
     */
 Emergencia(std::string i, std::string t, int p, int w, double d)
        : id(i),
          type(t),
          priority(p),
          waitTime(w),
          distance(d) {}

    // Métodos getter

    /**
     * Obtiene el id de la Emergencia.
     *
     * @param
     * @return id de la Emergencia.
     */
    const std::string& getId() const;

    /**
     * Obtiene el tipo de la Emergencia.
     *
     * @param
     * @return tipo.
     */
    const std::string& getType() const;

    /**
     * Obtiene la prioridad de la Emergencia.
     * del 1-5 donde:
     * 1 = muy poca prioridad y 
     * 5 = muy alta prioridad
     * @param
     * @return priority.
     */
    int getPriority() const;

    /**
     * Obtiene el tiempo de espera de la Emergencia.
     *
     * @param
     * @return waitTime.
     */
    int getWaitTime() const;

    /**
     * Calcula el nivel de urgencia.
     *
     * Utilizando la prioridad y el tiempo de espera.
     *
     * @param
     * @return número de urgencia unitario.
     */
    int calculateUrgency() const;

    /**
     * Obtiene la distancia desde el punto de la Emergencia y
     * el hospital.
     *
     * @param
     * @return distance.
     */
    double getDistance() const;
};

// Implementaciones de los métodos

const std::string& Emergencia::getId() const {
    return id;
}

const std::string& Emergencia::getType() const {
    return type;
}

int Emergencia::getPriority() const {
    return priority;
}

int Emergencia::getWaitTime() const {
    return waitTime;
}

double Emergencia::getDistance() const {
    return distance;
}

int Emergencia::calculateUrgency() const {
    return (priority * 100) + waitTime;
}

#endif
