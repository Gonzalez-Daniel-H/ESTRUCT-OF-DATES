#include <iostream>

using namespace std;


class Cafetera {
public:
    virtual void Capuchino() = 0;
    virtual void Tinto() = 0; 
};

class Oster : public Cafetera {
public:
    void Capuchino() override {
        cout << "Oster haciendo capuchino!!!" << endl;
    }

    void Tinto() override {
        cout << "Oster haciendo tinto!!!" << endl;
    }
};


class Haceb : public Cafetera {
public:
    void Capuchino() override {
        cout << "Haceb haciendo capuchino!!!" << endl;
    }

    void Tinto() override {
        cout << "Haceb haciendo tinto!!!" << endl;
    }
};

int main() {

    Cafetera* c_Oster = new Oster();
    Cafetera* c_Haceb = new Haceb();


    c_Oster->Capuchino();
    c_Oster->Tinto();


    c_Haceb->Capuchino();
    c_Haceb->Tinto();


    delete c_Oster;
    delete c_Haceb;

    return 0;
}
