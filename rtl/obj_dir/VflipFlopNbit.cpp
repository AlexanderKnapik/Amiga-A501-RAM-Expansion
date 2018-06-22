// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VflipFlopNbit.h for the primary calling header

#include "VflipFlopNbit.h"     // For This
#include "VflipFlopNbit__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VflipFlopNbit) {
    VflipFlopNbit__Syms* __restrict vlSymsp = __VlSymsp = new VflipFlopNbit__Syms(this, name());
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VflipFlopNbit::__Vconfigure(VflipFlopNbit__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VflipFlopNbit::~VflipFlopNbit() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VflipFlopNbit::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VflipFlopNbit::eval\n"); );
    VflipFlopNbit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VflipFlopNbit::_eval_initial_loop(VflipFlopNbit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VflipFlopNbit::_sequent__TOP__1(VflipFlopNbit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_sequent__TOP__1\n"); );
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at flipFlopNbit.v:20
    if (vlTOPp->reset_n) {
	if (vlTOPp->clk) {
	    vlTOPp->flipFlopNbit__DOT__q = vlTOPp->D;
	}
    } else {
	vlTOPp->flipFlopNbit__DOT__q = 0U;
    }
    vlTOPp->Q = vlTOPp->flipFlopNbit__DOT__q;
}

void VflipFlopNbit::_settle__TOP__2(VflipFlopNbit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_settle__TOP__2\n"); );
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q = vlTOPp->flipFlopNbit__DOT__q;
}

void VflipFlopNbit::_eval(VflipFlopNbit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_eval\n"); );
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->reset_n)) & (IData)(vlTOPp->__Vclklast__TOP__reset_n)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

void VflipFlopNbit::_eval_initial(VflipFlopNbit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_eval_initial\n"); );
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VflipFlopNbit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::final\n"); );
    // Variables
    VflipFlopNbit__Syms* __restrict vlSymsp = this->__VlSymsp;
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VflipFlopNbit::_eval_settle(VflipFlopNbit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_eval_settle\n"); );
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VflipFlopNbit::_change_request(VflipFlopNbit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_change_request\n"); );
    VflipFlopNbit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VflipFlopNbit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
	Verilated::overWidthError("reset_n");}
}
#endif // VL_DEBUG

void VflipFlopNbit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VflipFlopNbit::_ctor_var_reset\n"); );
    // Body
    D = VL_RAND_RESET_I(8);
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    Q = VL_RAND_RESET_I(8);
    flipFlopNbit__DOT__q = VL_RAND_RESET_I(8);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__reset_n = VL_RAND_RESET_I(1);
}
