// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VflipFlopNbit_H_
#define _VflipFlopNbit_H_

#include "verilated.h"

class VflipFlopNbit__Syms;

//----------

VL_MODULE(VflipFlopNbit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(D,7,0);
    VL_OUT8(Q,7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(flipFlopNbit__DOT__q,7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__reset_n,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VflipFlopNbit__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VflipFlopNbit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VflipFlopNbit(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VflipFlopNbit();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VflipFlopNbit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VflipFlopNbit__Syms* symsp, bool first);
  private:
    static QData _change_request(VflipFlopNbit__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(VflipFlopNbit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VflipFlopNbit__Syms* __restrict vlSymsp);
    static void _eval_settle(VflipFlopNbit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(VflipFlopNbit__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VflipFlopNbit__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
