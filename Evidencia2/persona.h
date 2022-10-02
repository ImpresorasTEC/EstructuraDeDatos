#pragma once
#ifndef PERSONA_H
#define PERSONA_H

#include <cstddef>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;
class Persona{
  private:
    string first_name,last_name,city;
    int id, zip;

  public:
      Persona(int id = 0, int zip = 0, string fname = "", string lname = "", string city = ""){
        this->id = id;
        this->zip = zip;
        this->first_name = fname;
        this->last_name = lname;
        this->city = city;
      }

/*
Agrega las sobre cargas de operadores necesarias en la clase Persona.
*/
      friend ostream & operator << (ostream & os, Persona & p){
        os << "| ID: " << p.id << " | Name: " 
          << p.first_name << " " << p.last_name 
          << " | ZIP: " << p.zip << " | City: " << p.city << "\n";
        return os;
      }
      string getCity(){
        return city;
      }


      string getName() {
        return first_name;
      }
};
#endif