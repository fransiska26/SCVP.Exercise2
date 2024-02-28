#ifndef NAND_H
#define NAND_H

#include <systemc.h>


SC_MODULE(nand)     //module declaration
{
    public:
    //define input ports
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;     //define output port

    SC_CTOR(nand) : A("A"), B("B"), Z("Z")      //module constructor
    {
        SC_METHOD(do_nand);
        sensitive << A << B;
    }

    void do_nand()
    {
       Z.write(!(A.read() && B.read()));
    }
};


#endif
