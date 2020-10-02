#include <iostream>
#include "generators/RandomGenerator.h"
#include "generators/GeneratorWithStep.h"

using namespace std;

void TestRandomGenerators() {
    try {
        RandomGenerator gen1("test1", 3);

        if (gen1.getName() == "test1") {
            cout << "test 1 completed" << endl;
        }
        else {
            cout << "test 1 uncompleted" << endl;
        }

        if (gen1.generate() == gen1.getPrevious()) {
            cout << "test 2 completed" << endl;
        }
        else {
            cout << "test 2 uncompleted" << endl;
        }

        gen1.setPrevious(3);
        if (gen1.getPrevious() == 3) {
            cout << "test 3 completed" << endl;
        }
        else {
            cout << "test 3 uncompleted" << endl;
        }

        RandomGenerator gen2("test2", 3);
        gen1.add(&gen2);

        if (gen1.generate() == gen1.getPrevious()) {
            cout << "test 4 completed" << endl;
        }
        else {
            cout << "test 4 uncompleted" << endl;
        }

    }
    catch (exception & ex) {
        cout << "Global test uncompleted";
    }

}

void TestGeneratorWithStep() {
    try {
        GeneratorWithStep gen1("test1", 5, 1, 3);
        if (gen1.getName() == "test1") {
            cout << "test 1 completed" << endl;
        }
        else {
            cout << "test 1 uncompleted" << endl;
        }

        if (gen1.getPrevious()) {
            cout << "test 2 completed" << endl;
        }
        else {
            cout << "test 2 uncompleted" << endl;
        }
        gen1.setPrevious(3);
        if (gen1.getPrevious() == 3) {
            cout << "test 3 completed" << endl;
        }
        else {
            cout << "test 3 uncompleted" << endl;
        }
    

        RandomGenerator gen2("test2", 3);
        gen1.add(&gen2);

        if (gen1.generate() == gen1.getPrevious()) {
            cout << "test 4 completed" << endl;
        }
        else {
            cout << "test 4 uncompleted" << endl;
        }
    }
    catch (exception & ex) {
        cout << "Global test uncompleted";
    }
}

int main() {
    cout << "Test \"RandomGenerators\"" << endl;
    TestRandomGenerators();
    cout << "Test \"GeneratorWithStep\"" << endl;
    TestGeneratorWithStep();

    return 0;
}
