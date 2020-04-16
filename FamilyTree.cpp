//
// Created by shira on 14/04/2020.
//

#include <string>
#include "FamilyTree.hpp"
using namespace std;
using namespace family;


Tree& Tree::addFather(string root,string father){
    return *this;

}
Tree& Tree::addMother(string root,string mother){
    return *this;
}
string Tree::relation(string name){
    return "defult";
}
string Tree::find(string relation){
    return "defult";
}
void Tree::display(){}
void Tree::remove(string remove){}