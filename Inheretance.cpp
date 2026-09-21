x#include <iostream>
using namespace std;

// ==========================================
// 1. SINGLE INHERITANCE
// One derived class inherits from one base class.
// ==========================================
class Animal {
public:
    void eat() {
        cout << "Animal is eating...\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking...\n";
    }
};


// ==========================================
// 2. MULTIPLE INHERITANCE
// One derived class inherits from multiple base classes.
// ==========================================
class Walker {
public:
    void walk() {
        cout << "Walking on land...\n";
    }
};

class Swimmer {
public:
    void swim() {
        cout << "Swimming in water...\n";
    }
};

class Frog : public Walker, public Swimmer {
public:
    void display() {
        cout << "Frog can walk and swim!\n";
    }
};


// ==========================================
// 3. MULTILEVEL INHERITANCE
// A class is derived from another derived class.
// ==========================================
class LivingBeing {
public:
    void breathe() {
        cout << "Breathing oxygen...\n";
    }
};

class Mammal : public LivingBeing {
public:
    void feedMilk() {
        cout << "Feeding milk to young ones...\n";
    }
};

class Human : public Mammal {
public:
    void think() {
        cout << "Human is thinking...\n";
    }
};


// ==========================================
// 4. HIERARCHICAL INHERITANCE
// Multiple derived classes inherit from a single base class.
// ==========================================
class Shape {
public:
    void render() {
        cout << "Rendering base shape...\n";
    }
};

class Circle : public Shape {
public:
    void drawCircle() {
        cout << "Drawing a Circle.\n";
    }
};

class Square : public Shape {
public:
    void drawSquare() {
        cout << "Drawing a Square.\n";
    }
};


// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {
    cout << "=== 1. Single Inheritance ==-\n";
    Dog myDog;
    myDog.eat();   // Inherited from Animal
    myDog.bark();  // Defined in Dog

    cout << "\n=== 2. Multiple Inheritance ==-\n";
    Frog myFrog;
    myFrog.walk(); // Inherited from Walker
    myFrog.swim(); // Inherited from Swimmer
    myFrog.display();

    cout << "\n=== 3. Multilevel Inheritance ==-\n";
    Human myHuman;
    myHuman.breathe();  // From LivingBeing
    myHuman.feedMilk(); // From Mammal
    myHuman.think();    // Defined in Human

    cout << "\n=== 4. Hierarchical Inheritance ==-\n";
    Circle myCircle;
    myCircle.render();
    myCircle.drawCircle();

    Square mySquare;
    mySquare.render();
    mySquare.drawSquare();

    return 0;
}
