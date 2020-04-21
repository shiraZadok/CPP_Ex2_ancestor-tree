/**
 * Demo for Family Tree
 * 
 * First version by Adam Lev-Ari,  2019-12
 * Second version by Erel Segal-Halevi, 2020-04
 */

#include "FamilyTree.hpp"

#include <iostream>
#include <ostream>
using namespace std;

int main(){
	family::Tree T ("Yosef");
	T.addFather("Yosef", "Yaakov")
	.addMother("Yosef", "Rachel")
	.addFather("Yaakov", "Isaac")
	.addMother("Yaakov", "Rivka")
	.addFather("Isaac", "Avraham")
	.addFather("Avraham", "Terah");

	T.display();// displays the tree in a human-friendly format.

//	cout << T.relation("Yaakov") << endl;  // prints "father"
//	cout << T.relation("Rachel") << endl;  // prints "mother"
//	cout << T.relation("Rivka") << endl;  // prints "grandmother"
//	cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
//	cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
//	cout << T.relation("xyz") << endl;  // prints "unrelated"
//	cout << T.relation("Yosef") << endl;  // prints "me"
//
//	cout << T.find("mother") << endl;  // prints "Rachel"
//	cout << T.find("great-great-grandfather") << endl;  // prints "Terah"
//	try {
//		cout << T.find("uncle") << endl;  // throws an exception
//	} catch (const exception& ex) {
//	 	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
//	}
//
//	T.remove("Avraham"); // removes Avraham and Terah
//	cout << T.relation("Terah") << endl;  // prints "unrelated"

    return 0;

//    family::Tree T ("Yosef");
//    T.addFather("Yosef", "Yaakov")
//    .addMother("Yosef","Rachel")
//    .addFather("Yaakov","Issac")
//    .addMother("Yaakov","Rivka")
//    .addFather("Rachel","Lavan")
//    .addFather("Issac", "Avrham")
//    .addFather("Avrham","Terach");
//    T.display();
//    T.addFather("Yose", "Yaakov");
//    T.addFather("Yosef", "Yaakov");
//    cout<< "\nrelation: \n";
//    cout << T.relation("Yosef");
//    cout << T.find("great-grandfather");
//    cout << T.relation("Yaakov");
//    cout << T.relation("Rachel");
//    cout << T.relation("Lavan");
//    cout << T.relation("Avrham");
//    cout << T.relation("Terach");


//    T.remove("Yaakov");
//    T.display();
//    return 0;
}
