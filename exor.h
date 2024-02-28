#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor)
{
    public:
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;
    
    private:
    nand nanda,nandb,nandc,nandd;
    sc_signal<bool> h1,h2,h3;

    public:
    SC_CTOR(exor) : A("A"), B("B"), Z("Z"), nanda("nanda"), nandb("nandb"), nandc("nandc"), nandd("nandd"), h1("h1"), h2("h2"), h3("h3")
    {
        nanda.A.bind(A);
        nanda.B.bind(B);
        nanda.Z.bind(h1);

        nandb.A.bind(h1);
        nandb.B.bind(B);
        nandb.Z.bind(h3);

        nandc.A.bind(A);
        nandc.B.bind(h1);
        nandc.Z.bind(h2);

        nandd.A.bind(h2);
        nandd.B.bind(h3);
        nandd.Z.bind(Z);
    }

};



#endif // EXOR_H
