//
// Created by shira on 14/04/2020.
//
#include <string>
#include <iostream>
#include "FamilyTree.hpp"
using namespace std;
using namespace family;

static string relationM[][2] = {{"me"},{"father","mother"},{"grandfather","grandmother"}};

Tree& Tree::addFather(string root,string father){
    if (addFather(this,root,father)) return *this;
    else throw runtime_error("addFather() throw - This name does not exist in the tree: "+ root);
}

bool Tree::addFather(Tree *tree, string root, string father){
    bool flag = false;
    if (tree->root==root){
        if (tree->father == nullptr){
            tree->father = new Tree(father);
            if (tree->mother == nullptr) Tree::depthTree++; //update depth of the tree
            return true;
        } else throw runtime_error("addFather() throw - There is already had father to: "+root);
    } else {
        if(tree->father != nullptr)
            flag = addFather(tree->father, root, father);
        if(!flag && tree->mother != nullptr)
            flag = addFather(tree->mother, root, father);
    }
    return flag;
}

Tree& Tree::addMother(string root,string mother){
    if (addMother(this,root,mother)) return *this;
    else throw runtime_error("addMother() throw - This name does not exist in the tree: "+ root);
}

bool Tree::addMother(Tree *tree, string root, string mother){
    bool flag = false;
    if (tree->root==root){
        if (tree->mother== nullptr){
            tree->mother = new Tree(mother);
            if (tree->father == nullptr) Tree::depthTree++; //update depth of the tree
            return true;
        } else throw runtime_error("addMother() throw - There is already had mother to: "+ root);
    } else  {
        if(tree->father != nullptr)
            flag = addMother(tree->father, root, mother);
        if(!flag && tree->mother != nullptr)
            flag = addMother(tree->mother, root, mother);
    }
    return flag;
}

string Tree::relation(string name){
    string ans = relation(this,name,0,0);
    return ans!="" ? ans : "unrelated";
}

string Tree::relation(Tree *tree,string name,int depth,int gender){
    string ans = "";
    //string whoIAM=tree->root;
    if (tree->root == name)
        return whatTheRelation(depth,gender);
    if (tree->father != nullptr)
        ans = relation(tree->father,name,++depth,0);
    else depth++;
    if (ans == "" && tree->mother != nullptr)
        ans = relation(tree->mother, name,depth,1);
    return ans;
}

string Tree::whatTheRelation(int depth,int gender){
    int numOfGreat= depth-2;
    if (numOfGreat >= 1){
        string ans = "";
        for (int i = 0; i < numOfGreat; ++i) {ans += "great-";}
        return ans += relationM[2][gender];
    }
    return relationM[depth][gender];
}

string Tree::find(string relation){
    string ans = find(this,relation,0,0);
    return ans!="" ? ans :
           throw runtime_error("The tree cannot handle the relation: "+ relation);
}

string Tree::find(Tree *tree,string relation,int depth,int gender){
    string ans = "";
    if (relation == whatTheRelation(depth,gender))
        return tree->root;
    if (tree->father != nullptr) 
        ans = find(tree->father,relation,++depth,0);
    else depth++;
    if (ans == "" && tree->mother != nullptr)
        ans = find(tree->mother, relation,depth,1);
    return ans;
}

void Tree::display(){
    string myFamily[Tree::depthTree];
    display(this,myFamily,0);
    for(int i = 0; i < Tree::depthTree; ++i){
        for (int j = 0; j <(Tree::depthTree*4)-(i*5) ; ++j) {cout<<" ";} //to make spaces in print
        cout << myFamily[i].substr(0, myFamily[i].size()-3) << "\n";
    }
}

void Tree::display(Tree *tree,string* myFamily,int depth) {
    if (tree != nullptr) {
        myFamily[depth] += tree->root + " _ ";
        display(tree->father,myFamily,++depth);
        display(tree->mother,myFamily,depth);
    }
}

void Tree::remove(string toRemove){
    if (this->root == toRemove)
        throw runtime_error("The root cannot be deleted");
    if(!remove(this,toRemove)) {
        throw runtime_error("This name do not exist in the tree: " + toRemove);
    }
}

bool Tree::remove(Tree* tree, string toRemove){
    if(tree == nullptr) return false;
    if (tree->father != nullptr && tree->father->root == toRemove) {
        delete tree->father;
        tree->father = nullptr;
        return true;
    }
    if (tree->mother != nullptr && tree->mother->root == toRemove) {
        delete tree->mother;
        tree->mother = nullptr;
        return true;
    }
    return remove(tree->father,toRemove) || remove(tree->mother,toRemove);
}