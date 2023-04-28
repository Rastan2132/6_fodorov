#pragma once
#include <iostream>
#include <string>

using namespace std;

class Silnik
{
    short moc{ 1000 };
public:
    Silnik(short moc_ = 0) :moc(moc_) {}
    short get_moc() const { return moc; }
};

class Pojazd 
{
protected:
    short v{ 400 };
    Silnik* s{ nullptr };


public:
    Pojazd(short v_ = 0, short moc_ = 0) : v(v_), s{ new Silnik {moc_} } {}

    Pojazd(const Pojazd& other) : v(other.v), s(new Silnik(*other.s)) {}

    ~Pojazd() {
        delete s;
    }

    Pojazd& operator=(const Pojazd& other) {
        if (this != &other) {
            v = other.v;
            *s = *other.s;
        }
        return *this;
    }

    short get_v() const { return v; }
    short get_moc() const { return s->get_moc(); }

    void print() const {
        cout << v << " " << s->get_moc() << endl;
    }
};

class Kolo
{
protected:
    short rozmiar{ 15 };
public:
    Kolo(short rozmiar_ = 0) :rozmiar(rozmiar_) {}
    short get_rozmiar() const { return rozmiar; }
};

class Samohud : public Pojazd
{
protected:
    Kolo kola[4];
public:
    Samohud(short v = 0, short moc = 0) : Pojazd{v, moc} {}
    void print()const
    {
    Pojazd:print();
        for (Kolo k : kola)
            cout << k.get_rozmiar()<<endl;

    }
    Samohud(const Samohud& other) : Pojazd(other), kola{ other.kola[0], other.kola[1], other.kola[2], other.kola[3] } {}

};