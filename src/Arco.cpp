#include "../header/Arco.hpp"

Arco::Arco(Nodo *A, Nodo *B, int superiorCapacity) {
    this->fromA = A;
    this->toB = B;
    this->superiorCapacity = superiorCapacity;
}
Nodo* Arco::getNodoFrom() {
    return this->fromA;
}
Nodo* Arco::getNodoTO() {
    return this->toB;
}
string Arco::toString() {
    string res = this->fromA->toString();
    res = res + this->toB->toString();
    return res;
}
void Arco::draw(sf::RenderWindow &window) {}

