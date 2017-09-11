// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMemAlu.h for the primary calling header

#include "VMemAlu.h"           // For This
#include "VMemAlu__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMemAlu) {
    VMemAlu__Syms* __restrict vlSymsp = __VlSymsp = new VMemAlu__Syms(this, name());
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMemAlu::__Vconfigure(VMemAlu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMemAlu::~VMemAlu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VMemAlu::eval() {
    VMemAlu__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VMemAlu::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VMemAlu::_eval_initial_loop(VMemAlu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VMemAlu::_combo__TOP__1(VMemAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_combo__TOP__1\n"); );
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at MemAlu.v:33
    vlTOPp->MemAlu__DOT__tIdxAddr = (vlTOPp->idxAddr 
				     + vlTOPp->idxDisp);
    vlTOPp->MemAlu__DOT__tIdxAddr2 = ((VL_ULL(0xffffffff00000000) 
				       & vlTOPp->MemAlu__DOT__tIdxAddr2) 
				      | (IData)((IData)(vlTOPp->MemAlu__DOT__tIdxAddr)));
    vlTOPp->MemAlu__DOT__tIdxAddr2 = ((VL_ULL(0xffffffff) 
				       & vlTOPp->MemAlu__DOT__tIdxAddr2) 
				      | ((QData)((IData)(
							 ((0x80000000U 
							   & vlTOPp->MemAlu__DOT__tIdxAddr)
							   ? 0xffffffffU
							   : 0U))) 
					 << 0x20U));
    vlTOPp->MemAlu__DOT__tOutAddr = ((4U & (IData)(vlTOPp->mode))
				      ? ((2U & (IData)(vlTOPp->mode))
					  ? VL_ULL(0)
					  : ((1U & (IData)(vlTOPp->mode))
					      ? (vlTOPp->baseAddr 
						 + 
						 (vlTOPp->MemAlu__DOT__tIdxAddr2 
						  << 4U))
					      : (vlTOPp->baseAddr 
						 + 
						 (vlTOPp->MemAlu__DOT__tIdxAddr2 
						  << 3U))))
				      : ((2U & (IData)(vlTOPp->mode))
					  ? ((1U & (IData)(vlTOPp->mode))
					      ? (vlTOPp->baseAddr 
						 + 
						 (vlTOPp->MemAlu__DOT__tIdxAddr2 
						  << 2U))
					      : (vlTOPp->baseAddr 
						 + 
						 (vlTOPp->MemAlu__DOT__tIdxAddr2 
						  << 1U)))
					  : ((1U & (IData)(vlTOPp->mode))
					      ? (vlTOPp->baseAddr 
						 + vlTOPp->MemAlu__DOT__tIdxAddr2)
					      : VL_ULL(0))));
    vlTOPp->outAddr = vlTOPp->MemAlu__DOT__tOutAddr;
}

void VMemAlu::_eval(VMemAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_eval\n"); );
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VMemAlu::_eval_initial(VMemAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_eval_initial\n"); );
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMemAlu::final() {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::final\n"); );
    // Variables
    VMemAlu__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMemAlu::_eval_settle(VMemAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_eval_settle\n"); );
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VMemAlu::_change_request(VMemAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_change_request\n"); );
    VMemAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VMemAlu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    mode = VL_RAND_RESET_I(3);
    baseAddr = VL_RAND_RESET_Q(64);
    idxAddr = VL_RAND_RESET_I(32);
    idxDisp = VL_RAND_RESET_I(32);
    outAddr = VL_RAND_RESET_Q(64);
    MemAlu__DOT__tIdxAddr = VL_RAND_RESET_I(32);
    MemAlu__DOT__tIdxAddr2 = VL_RAND_RESET_Q(64);
    MemAlu__DOT__tOutAddr = VL_RAND_RESET_Q(64);
}

void VMemAlu::_configure_coverage(VMemAlu__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VMemAlu::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
