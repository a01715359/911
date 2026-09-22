
#ifndef CENTRODESPACHO_H
#define CENTRODESPACHO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Emergencia.h"

class CentroDespacho {
    private:
        std::vector<Emergencia> listaEmergencias;

	    void copyArray(std::vector<Emergencia>& original, 
            std::vector<Emergencia>& result, int low, int high);
        void mergeArray(std::vector<Emergencia>& original, 
            std::vector<Emergencia>& result, int low, int mid, int high);
        void mergeSplit(std::vector<Emergencia>& original, 
            std::vector<Emergencia>& result, int low, int high);
    public:
        CentroDespacho() {};
        
        void cargarCSV(const std::string& archiveName);
        void ordenarPorUrgencia();
        void mostrarEmergencias() const;
};

void CentroDespacho::cargarCSV(const std::string& archiveName) {
    std::ifstream archivo(archiveName);
    if (!archivo.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo " << archiveName << "\n";
        return;
    }

    std::string linea;
    getline(archivo, linea);

    listaEmergencias.clear();

    while (getline(archivo, linea)) {
            if (!linea.empty()) {

            std::stringstream ss(linea);
            std::string id, type, priorityStr, waitTimeStr, distanceStr;

            getline(ss, id, ',');
            getline(ss, type, ',');
            getline(ss, priorityStr, ',');
            getline(ss, waitTimeStr, ',');
            getline(ss, distanceStr, ',');

            int priority = std::stoi(priorityStr);
            int waitTime = std::stoi(waitTimeStr);
            double distance = std::stod(distanceStr);

            listaEmergencias.push_back(Emergencia(id, type, priority, waitTime, distance));
            }
        }

    archivo.close();
        std::cout << "-> Datos cargados exitosamente (" << listaEmergencias.size() << " emergencias).\n";
}

void CentroDespacho::copyArray(std::vector<Emergencia> &original, 
        std::vector<Emergencia> &result, int low, int high) {
    for (int i = low; i <= high; i++) {
        original[i] = result[i];
    }
}

void CentroDespacho::mergeArray(std::vector<Emergencia> &original, 
        std::vector<Emergencia> &result, int low, int mid, int high) {
	int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (original[i].calculateUrgency() >= original[j].calculateUrgency()) {
            result[k] = original[i];
            i++;
        } else {
            result[k] = original[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++) {
            result[k++] = original[j];
        }
    } else {
        for (; i <= mid; i++) {
            result[k++] = original[i];
        }
    }
}

void CentroDespacho::mergeSplit(std::vector<Emergencia> &original, std::vector<Emergencia> &result, int low, int high) {
	if ((high - low) < 1) {
		return;
    }
	int mid = (high + low) / 2;
	mergeSplit(original, result, low, mid);
	mergeSplit(original, result, mid + 1, high);
	mergeArray(original, result, low, mid, high);
	copyArray(original, result, low, high);
}

void CentroDespacho::ordenarPorUrgencia() {
    if (listaEmergencias.empty()) return;
    std::vector<Emergencia> tmp(listaEmergencias.size());
    mergeSplit(listaEmergencias, tmp, 0, listaEmergencias.size() - 1);
}

void CentroDespacho::mostrarEmergencias() const {
    std::cout << "\n" << std::left 
              << std::setw(6)  << "ID"
              << std::setw(42) << "TIPO"
              << std::setw(7)  << "PRIO"
              << std::setw(10) << "ESPERA"
              << std::setw(10) << "DIST"
              << std::setw(10) << "URGENCIA" << "\n";
    std::cout << "----------------------------------------------------------------------------------\n";

    for (int i = 0; i < listaEmergencias.size(); i++) {
        std::cout << std::left 
                  << std::setw(6)  << listaEmergencias[i].getId()
                  << std::setw(42) << listaEmergencias[i].getType()
                  << std::setw(7)  << listaEmergencias[i].getPriority()
                  << std::setw(10) << (std::to_string(listaEmergencias[i].getWaitTime()) + " min")
                  << std::setw(10) << (std::to_string(listaEmergencias[i].getDistance()) + " km")
                  << std::setw(10) << listaEmergencias[i].calculateUrgency() << "\n";
    }
}

#endif
