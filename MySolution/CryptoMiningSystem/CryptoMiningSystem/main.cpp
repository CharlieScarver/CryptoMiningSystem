#include "User.h"
#include "LowPerfProcessor.h"
#include "HighPerfProcessor.h"
#include "GameVideoCard.h"
#include "MineVideoCard.h"
#include "CustomVideoCard.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 1. Constructor calls
	cout << "1. Constructor calls" << endl;

	// The Component() constructor is marked as private,
	// When we try to invoke it in the following initializations we get:
	// Error: Component::Component() is inaccessible
	// Component c1;
	// Component* c2 = new Component();
	// Component c3{};
	// For more details on initialization with {} read the commend at the bottom of this file.

	// This is a well known syntactic ambiguity in C++. 
	// When you write "int rand()", the compiler cannot know if you mean 
	// "create an int and default-initialize it" or "declare function rand".
	// The rule is that it chooses the latter whenever possible.
	Component c4();
	// This is just a pointer to a Component object.
	// It currently doesn't point to anything.
	// We're not constructing a Component object here.
	// We're just creating a pointer.
	Component* c5 = nullptr;

	GameVideoCard gvc0("Nvidia GeForce GTX 1060 Ti", 450, 5, 2);

	try {
		GameVideoCard gvc1("Nvidia GeForce RTX 2060", 700, 7, 3);
	}
	catch (const invalid_argument& ex) {
		std::cerr << "Invalid argument: " << ex.what() << endl;
	}


	// Copy constructor
	// The copy constructor is used when an object of a class T is initialized
	// using another object of class T (or a derived class of T - polymorphism)
	// The copy constructor has to do a deep copy of the object.
	// This means the value of every field of the given object has to be
	// assigned to the same field in the initializing object.
	GameVideoCard gvc2 = GameVideoCard("Nvidia GeForce RTX 3060 Ti", 1000, 8, 4);
	GameVideoCard gvc3 = gvc2;

	// Polymorphism allows the use of the parent's/VideoCard's copy constructor
	VideoCard vc = gvc0;

	// The empty constructor and the copy constructor are not inherited by child classes (exceptions).
	// Polymorphism works only from concrete to abstract and not the other way around:
	// GameVideoCard -> VideoCard is ok
	// VideoCard -> GameVideoCard is not ok because 
	// GameVideoCard requires additional data that's missing in VideoCard
	// GameVideoCard gvc4(vc); // Error - no matching constructor

	// Dynamically allocate a HighPerProcessor object and get a pointer to it
	HighPerfProcessor* hpp1 = new HighPerfProcessor("Intel 4", 400, 7, 10000);
	// This is just a pointer assignment, there's no constructor call
	HighPerfProcessor* hpp2 = hpp1; 


	// Move constructor - rvalues (temporaries)
	// A chronic performance problem with C++03 is the costly and unneeded deep copies
	// that can happen implicitly when objects are passed by value.
	// If an std::vector<T> temporary is created or returned from a function,
	// it can be stored only by creating a new std::vector<T> and copying all the rvalue's data into it.
	// Then the temporary and all its memory is destroyed.
	// In C++11, a move constructor of std::vector<T> that takes an rvalue reference to an std::vector<T> 
	// can copy the pointer to the internal C-style array out of the rvalue into the new std::vector<T>, 
	// then set the pointer inside the rvalue to null. Since the temporary will never again be used, 
	// no code will try to access the null pointer, and because the pointer is null, 
	// its memory is not deleted when it goes out of scope.

	// Move constructor
	VideoCard videoCardsStatic[] = {
		GameVideoCard("AMD 1", 450, 5, 2),
		MineVideoCard("AMD 2", 450, 5, 2),
		MineVideoCard("AMD 3", 450, 5, 2)
	};

	cout << endl << "Video cards static array:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << ". " << videoCardsStatic[i].GetModel() << ", " << videoCardsStatic[i].GetPrice() << endl;
	}

	// Polymorphism allows us to use both processors and video cards in a Component array
	Component componentsStatic[] = {
		HighPerfProcessor("Intel Core i5 750", 450, 5, 2),
		LowPerfProcessor("AMD Athlon II X2 210e", 450, 5, 2),
		gvc0,
		gvc2
	};

	cout << endl << "Components static array:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i << ". " << componentsStatic[i].GetModel() << ", " << componentsStatic[i].GetPrice() << endl;
	}

	// Polymorphism with dynamic Component* pointers in an array
	Component* componentsDynamic[5];
	componentsDynamic[0] = new GameVideoCard("Nvidia 3", 450, 5, 2);
	componentsDynamic[1] = new MineVideoCard("Nvidia 4", 450, 5, 2);
	componentsDynamic[2] = new HighPerfProcessor("Intel 1", 400, 7, 10000);
	componentsDynamic[3] = new LowPerfProcessor("Intel 2", 240, 3, 5000);
	componentsDynamic[4] = new HighPerfProcessor("Intel 3", 375, 6, 12000);

	cout << endl << "Components dynamic array:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i << ". " << componentsDynamic[i]->GetModel() << ", " << componentsDynamic[i]->GetPrice() << endl;
	}
	cout << endl;

	// Vector - copy + move constructors
	vector<GameVideoCard> vec;
	vec.push_back(GameVideoCard{ "Nvidia 5", 450, 5, 2 });
	vec.push_back(GameVideoCard{ "Nvidia 6", 450, 5, 2 });
	vec.push_back(GameVideoCard{ "Nvidia 7", 450, 5, 2 });
	cout << endl;


	// 2. Multiple Inheritance
	cout << "2. Multiple Inheritance" << endl;
	CustomVideoCard cvc(&gvc0, hpp1);
	// Conflicting names have to be descoped using the scope resolution operator (::)
	// Warning: Avoid writing code with conflicting names!!
	cout << "CustomVideoCard: " << cvc.GetModel() << ", " << cvc.GetPrice() << ", " << cvc.Processor::GetGeneration() << endl;
	cout << endl;
	
	// 3. Operator overloading
	// Operator == is overloaded for VideoCard
	cout << "3. Operator overloading"  << endl;
	cout << "gvc2 == gvc3   =>   " << (gvc2 == gvc3 ? "true" : "false") << endl;

	GameVideoCard gvc5 = GameVideoCard("Nvidia GeForce RTX 3060 Ti", 1000, 8, 4);
	cout << "gvc2 == gvc5   =>   " << (gvc2 == gvc5 ? "true" : "false") << endl;

	// Operator << is overloaded for both VideoCard and for GameVideoCard
	// The "more concrete" implementation takes precedence (GameVideoCard)
	// More concrete means => children first, parents after
	cout << "gvc2 = " << gvc2 << " => " << &gvc2 << endl;
	cout << "gvc4 = " << gvc5 << " => " << &gvc5 << endl;

	// Operator std::ostream& VideoCard::operator<<(std::ostream& os) is never found
	// because it needs to be called like so object.operator<<(os);
	// Only the operator std::ostream& GameVideoCard::operator<<(std::ostream& os) is found when we use
	// os.operator<<(object); or operator<<(os, object);
	MineVideoCard mvc1 = MineVideoCard("AMD 3", 450, 5, 2);
	// cout << "mvc1 = " << mvc1 << " => " << &mvc1 << endl; // Error: no operator "<<" matches these operands


	// Operator += is overloaded for VideoCard, it adds to the ram property
	gvc5 += 2;
	cout << "gvc2 == gvc5   =>   " << (gvc2 == gvc5 ? "true" : "false") << endl;
	cout << "gvc5 = " << gvc5 << " => " << &gvc5 << endl;

	cout << endl;
}

/*
The following initialization (with {}) is called "list initialization":
Component c3{};

Read the following StackOverflow question for more information:
https://stackoverflow.com/questions/18222926/what-are-the-advantages-of-list-initialization-using-curly-braces

Basically copying and pasting from Bjarne Stroustrup's "The C++ Programming Language 4th Edition":

List initialization does not allow narrowing (§iso.8.5.4). That is:

An integer cannot be converted to another integer that cannot hold its value. For example, char to int is allowed, but not int to char.
A floating-point value cannot be converted to another floating-point type that cannot hold its value. For example, float to double is allowed, but not double to float.
A floating-point value cannot be converted to an integer type.
An integer value cannot be converted to a floating-point type.

void fun(double val, int val2) {

	int x2 = val;    // if val == 7.9, x2 becomes 7 (bad)

	char c2 = val2;  // if val2 == 1025, c2 becomes 1 (bad)

	int x3 {val};    // error: possible truncation (good)

	char c3 {val2};  // error: possible narrowing (good)

	char c4 {24};    // OK: 24 can be represented exactly as a char (good)

	char c5 {264};   // error (assuming 8-bit chars): 264 cannot be
					 // represented as a char (good)

	int x4 {2.0};    // error: no double to int value conversion (good)

}
*/
