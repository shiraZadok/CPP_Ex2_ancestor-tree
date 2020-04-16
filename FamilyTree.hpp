//
// Created by shira on 14/04/2020.
//
# pragma once
#include <string>
using namespace std;

namespace family{
    class Tree;
}

class family::Tree{
private:
    string root;
    Tree *father,*mother;

public:
    Tree(){
        this->root="Yosef";
        this->addFather("Yosef", "Yaakov")
                .addMother("Yosef", "Rachel")
                .addMother("Rachel","?")
                .addFather("Rachel","Lavan")
                .addFather("Yaakov", "Isaac")
                .addMother("Yaakov", "Rivka")
                .addMother("Rivka","??")
                .addFather("Rivka","Betoel")
                .addFather("Isaac", "Avraham")
                .addMother("Isaac", "Sara")
                .addFather("Avraham", "Terah")
                .addFather("Terah","Nachor");
    }

    Tree(string root){ //constructor
        this->root=root;
        this->father= nullptr;
        this->mother= nullptr;
    }

    Tree& addFather(string root,string father);
    Tree& addMother(string root,string mother);
    string relation(string name);
    string find(string relation);
    void display();
    void remove(string remove);
};
