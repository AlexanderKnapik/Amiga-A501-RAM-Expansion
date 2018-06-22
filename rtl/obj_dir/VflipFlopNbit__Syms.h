// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VflipFlopNbit__Syms_H_
#define _VflipFlopNbit__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VflipFlopNbit.h"

// SYMS CLASS
class VflipFlopNbit__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VflipFlopNbit*                 TOPp;
    
    // CREATORS
    VflipFlopNbit__Syms(VflipFlopNbit* topp, const char* namep);
    ~VflipFlopNbit__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
