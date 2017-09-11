// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFpuFp64B.h for the primary calling header

#include "VFpuFp64B.h"         // For This
#include "VFpuFp64B__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VFpuFp64B) {
    VFpuFp64B__Syms* __restrict vlSymsp = __VlSymsp = new VFpuFp64B__Syms(this, name());
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFpuFp64B::__Vconfigure(VFpuFp64B__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VFpuFp64B::~VFpuFp64B() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VFpuFp64B::eval() {
    VFpuFp64B__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VFpuFp64B::eval\n"); );
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

void VFpuFp64B::_eval_initial_loop(VFpuFp64B__Syms* __restrict vlSymsp) {
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

void VFpuFp64B::_settle__TOP__1(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_settle__TOP__1\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FpuFp64B__DOT__fpCnvdDst = (VL_ULL(0xffffffff) 
					& vlTOPp->FpuFp64B__DOT__fpCnvdDst);
    // ALWAYS at FpuFp64B.v:121
    vlTOPp->FpuFp64B__DOT__tSro = vlTOPp->sri;
    // ALWAYS at FpuFp64FromInt.v:49
    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc = 0U;
    if (vlTOPp->opf32) {
	if ((1U & (IData)((vlTOPp->srcb >> 0x1fU)))) {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)((~ (IData)(vlTOPp->srcb)))));
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)(vlTOPp->srcb)));
	}
    } else {
	if ((1U & (IData)((vlTOPp->srcb >> 0x3fU)))) {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= (~ vlTOPp->srcb);
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= vlTOPp->srcb;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	}
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2))) {
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc = 0U;
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC = VL_ULL(0);
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc = 0U;
    } else {
	if ((0U == (0xfffU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
				      >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E;
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		= vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B 
		= vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm;
	    if ((0U != (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
					>> 0x3cU))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		       >> 8U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(8U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U != (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x38U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		       >> 4U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(4U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x36U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		       >> 2U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(2U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x35U)))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		       >> 1U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc))) {
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc))) {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst));
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa = (0xffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa = ((0xf00U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)) 
					       | (0xffU 
						  & (IData)(
							    (vlTOPp->srcc 
							     >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)))) {
	vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)))) {
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcc 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcc)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst);
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcc 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcc)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa = (0xffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa = ((0xf00U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)) 
					       | (0xffU 
						  & (IData)(
							    (vlTOPp->srca 
							     >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)))) {
	vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)))) {
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srca 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srca)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst);
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srca 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srca)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa = (0xffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa = ((0xf00U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)) 
					       | (0xffU 
						  & (IData)(
							    (vlTOPp->srcb 
							     >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)))) {
	vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)))) {
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcb 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcb)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst);
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcb 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcb)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst);
	}
    }
    vlTOPp->FpuFp64B__DOT__tOpFp32i = (((IData)(vlTOPp->opf32) 
					| (0xcU == (IData)(vlTOPp->opMode))) 
				       & (0xfU != (IData)(vlTOPp->opMode)));
}

VL_INLINE_OPT void VFpuFp64B::_combo__TOP__2(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_combo__TOP__2\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp64B.v:121
    vlTOPp->FpuFp64B__DOT__tSro = vlTOPp->sri;
    // ALWAYS at FpuFp64FromInt.v:49
    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc = 0U;
    if (vlTOPp->opf32) {
	if ((1U & (IData)((vlTOPp->srcb >> 0x1fU)))) {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)((~ (IData)(vlTOPp->srcb)))));
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)(vlTOPp->srcb)));
	}
    } else {
	if ((1U & (IData)((vlTOPp->srcb >> 0x3fU)))) {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= (~ vlTOPp->srcb);
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		= vlTOPp->srcb;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm = 0x433U;
	}
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2))) {
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc = 0U;
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC = VL_ULL(0);
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc = 0U;
    } else {
	if ((0U == (0xfffU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
				      >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E;
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		= vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2;
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B 
		= vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exm;
	    if ((0U != (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
					>> 0x3cU))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B 
		       >> 8U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(8U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U != (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x38U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C 
		       >> 4U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(4U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x36U))))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D 
		       >> 2U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(2U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x35U)))) {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E 
		       >> 1U);
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E)));
	    } else {
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tExc_E;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc))) {
	vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc))) {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst));
	} else {
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa = (0xffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa = ((0xf00U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)) 
					       | (0xffU 
						  & (IData)(
							    (vlTOPp->srcc 
							     >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)))) {
	vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)))) {
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcc 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcc)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst);
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exa)));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcc 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcc)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa = (0xffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa = ((0xf00U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)) 
					       | (0xffU 
						  & (IData)(
							    (vlTOPp->srca 
							     >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)))) {
	vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)))) {
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srca 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srca)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst);
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exa)));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srca 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnva__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srca)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa = (0xffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa = ((0xf00U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)) 
					       | (0xffU 
						  & (IData)(
							    (vlTOPp->srcb 
							     >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)))) {
	vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)))) {
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcb 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcb)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst);
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exa)));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->srcb 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->srcb)))) 
		      << 0x1dU));
	    vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst);
	}
    }
    vlTOPp->FpuFp64B__DOT__tOpFp32i = (((IData)(vlTOPp->opf32) 
					| (0xcU == (IData)(vlTOPp->opMode))) 
				       & (0xfU != (IData)(vlTOPp->opMode)));
    vlTOPp->FpuFp64B__DOT__fcSrcA = ((IData)(vlTOPp->FpuFp64B__DOT__tOpFp32i)
				      ? vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst
				      : vlTOPp->srca);
    vlTOPp->FpuFp64B__DOT__fcSrcB = ((IData)(vlTOPp->FpuFp64B__DOT__tOpFp32i)
				      ? vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst
				      : vlTOPp->srcb);
}

void VFpuFp64B::_settle__TOP__3(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_settle__TOP__3\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FpuFp64B__DOT__fcSrcA = ((IData)(vlTOPp->FpuFp64B__DOT__tOpFp32i)
				      ? vlTOPp->FpuFp64B__DOT__fpcnva__DOT__tDst
				      : vlTOPp->srca);
    vlTOPp->FpuFp64B__DOT__fcSrcB = ((IData)(vlTOPp->FpuFp64B__DOT__tOpFp32i)
				      ? vlTOPp->FpuFp64B__DOT__fpcnvb__DOT__tDst
				      : vlTOPp->srcb);
    vlTOPp->FpuFp64B__DOT__fpaSrcA = (((9U == (IData)(vlTOPp->opMode)) 
				       | (4U == (IData)(vlTOPp->opMode)))
				       ? ((IData)(vlTOPp->FpuFp64B__DOT__tOpFp32i)
					   ? vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst
					   : vlTOPp->srcc)
				       : vlTOPp->FpuFp64B__DOT__fcSrcA);
    // ALWAYS at FpuFp64B.v:125
    vlTOPp->FpuFp64B__DOT__tDst = vlTOPp->FpuFp64B__DOT__fcSrcB;
    // ALWAYS at FpuFp64ToInt.v:28
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__sgn = (1U 
						& (IData)(
							  (vlTOPp->FpuFp64B__DOT__fcSrcB 
							   >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa = (0x7ffU 
						& (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa));
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa = ((0x800U 
						 & (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa)) 
						| (0x7ffU 
						   & (IData)(
							     (vlTOPp->FpuFp64B__DOT__fcSrcB 
							      >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exb = (0xfffU 
						& ((IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa) 
						   - (IData)(0x433U)));
    if (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__sgn) {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra) 
	     | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->FpuFp64B__DOT__fcSrcB)));
    } else {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					 & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra) 
	     | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fcSrcB));
    }
    if ((0x433U <= (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa))) {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl = 
	    (0x3fU & (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exb));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst = 
	    (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra 
	     << (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl));
    } else {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl = 
	    (0x3fU & VL_NEGATE_I((IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exb)));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst = 
	    (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra 
	     >> (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl));
    }
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst2 = ((IData)(vlTOPp->opf32)
						   ? 
						  ((VL_ULL(0x1ffffffff) 
						    == 
						    (VL_ULL(0x1ffffffff) 
						     & (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst 
							>> 0x1fU)))
						    ? vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst
						    : 
						   ((VL_ULL(0) 
						     == 
						     (VL_ULL(0x1ffffffff) 
						      & (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst 
							 >> 0x1fU)))
						     ? vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst
						     : VL_ULL(0x80000000)))
						   : vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst);
    // ALWAYS at FpuFp64_Mul.v:46
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgna = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fcSrcA 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnb = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fcSrcB 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fcSrcA 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fcSrcB 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnc = ((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgna) 
					       ^ (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnb));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA = (VL_ULL(0x10000000000000) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB = (VL_ULL(0x10000000000000) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA = ((VL_ULL(0xfff0000000000000) 
						  & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fcSrcA));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB = ((VL_ULL(0xfff0000000000000) 
						  & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fcSrcB));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC = ((vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA 
						  >> 0x15U) 
						 * 
						 (vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB 
						  >> 0x15U));
    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC 
		       >> 0x3fU)))) {
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC 
					  >> 0xbU));
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc = (0x1fffU 
						  & (((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa) 
						      + (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb)) 
						     - (IData)(0x3feU)));
    } else {
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC 
					  >> 0xaU));
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc = (0x1fffU 
						  & (((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa) 
						      + (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb)) 
						     - (IData)(0x3ffU)));
    }
    if ((0x1000U & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc))) {
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc))) {
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst));
	} else {
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC2);
	}
    }
}

VL_INLINE_OPT void VFpuFp64B::_combo__TOP__4(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_combo__TOP__4\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FpuFp64B__DOT__fpaSrcA = (((9U == (IData)(vlTOPp->opMode)) 
				       | (4U == (IData)(vlTOPp->opMode)))
				       ? ((IData)(vlTOPp->FpuFp64B__DOT__tOpFp32i)
					   ? vlTOPp->FpuFp64B__DOT__fpcnvc__DOT__tDst
					   : vlTOPp->srcc)
				       : vlTOPp->FpuFp64B__DOT__fcSrcA);
    // ALWAYS at FpuFp64B.v:125
    vlTOPp->FpuFp64B__DOT__tDst = vlTOPp->FpuFp64B__DOT__fcSrcB;
    // ALWAYS at FpuFp64ToInt.v:28
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__sgn = (1U 
						& (IData)(
							  (vlTOPp->FpuFp64B__DOT__fcSrcB 
							   >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa = (0x7ffU 
						& (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa));
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa = ((0x800U 
						 & (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa)) 
						| (0x7ffU 
						   & (IData)(
							     (vlTOPp->FpuFp64B__DOT__fcSrcB 
							      >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exb = (0xfffU 
						& ((IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa) 
						   - (IData)(0x433U)));
    if (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__sgn) {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra) 
	     | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->FpuFp64B__DOT__fcSrcB)));
    } else {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					 & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra) 
	     | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fcSrcB));
    }
    if ((0x433U <= (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exa))) {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl = 
	    (0x3fU & (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exb));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst = 
	    (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra 
	     << (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl));
    } else {
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl = 
	    (0x3fU & VL_NEGATE_I((IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__exb)));
	vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst = 
	    (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__fra 
	     >> (IData)(vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tShl));
    }
    vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst2 = ((IData)(vlTOPp->opf32)
						   ? 
						  ((VL_ULL(0x1ffffffff) 
						    == 
						    (VL_ULL(0x1ffffffff) 
						     & (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst 
							>> 0x1fU)))
						    ? vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst
						    : 
						   ((VL_ULL(0) 
						     == 
						     (VL_ULL(0x1ffffffff) 
						      & (vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst 
							 >> 0x1fU)))
						     ? vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst
						     : VL_ULL(0x80000000)))
						   : vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst);
    // ALWAYS at FpuFp64_Mul.v:46
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgna = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fcSrcA 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnb = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fcSrcB 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fcSrcA 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fcSrcB 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnc = ((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgna) 
					       ^ (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnb));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA = (VL_ULL(0x10000000000000) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB = (VL_ULL(0x10000000000000) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA = ((VL_ULL(0xfff0000000000000) 
						  & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fcSrcA));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB = ((VL_ULL(0xfff0000000000000) 
						  & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB) 
						 | (VL_ULL(0xfffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__fcSrcB));
    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC = ((vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracA 
						  >> 0x15U) 
						 * 
						 (vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracB 
						  >> 0x15U));
    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC 
		       >> 0x3fU)))) {
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC 
					  >> 0xbU));
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc = (0x1fffU 
						  & (((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa) 
						      + (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb)) 
						     - (IData)(0x3feU)));
    } else {
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC 
					  >> 0xaU));
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc = (0x1fffU 
						  & (((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exa) 
						      + (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exb)) 
						     - (IData)(0x3ffU)));
    }
    if ((0x1000U & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc))) {
	vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc))) {
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst));
	} else {
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpmul__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst) 
		   | vlTOPp->FpuFp64B__DOT__fpmul__DOT__tFracC2);
	}
    }
    vlTOPp->FpuFp64B__DOT__fpaSrcB = (((9U == (IData)(vlTOPp->opMode)) 
				       | (4U == (IData)(vlTOPp->opMode)))
				       ? vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst
				       : vlTOPp->FpuFp64B__DOT__fcSrcB);
}

void VFpuFp64B::_settle__TOP__5(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_settle__TOP__5\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FpuFp64B__DOT__fpaSrcB = (((9U == (IData)(vlTOPp->opMode)) 
				       | (4U == (IData)(vlTOPp->opMode)))
				       ? vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst
				       : vlTOPp->FpuFp64B__DOT__fcSrcB);
    // ALWAYS at FpuFp64_Add.v:53
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgna = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fpaSrcA 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnb = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fpaSrcB 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fpaSrcA 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fpaSrcB 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm = (((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa) 
					       >= (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb))
					       ? (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa)
					       : (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb));
    if (vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgna) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA) 
	     | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->FpuFp64B__DOT__fpaSrcA)));
    } else {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					 & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA) 
	     | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fpaSrcA));
    }
    if (((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnb) 
	 ^ ((2U == (IData)(vlTOPp->opMode)) | (4U == (IData)(vlTOPp->opMode))))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB) 
	     | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->FpuFp64B__DOT__fpaSrcB)));
    } else {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					 & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB) 
	     | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fpaSrcB));
    }
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA1 = ((0x3fU 
						   >= 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa))))
						   ? 
						  (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA 
						   >> 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa))))
						   : VL_ULL(0));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB1 = ((0x3fU 
						   >= 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb))))
						   ? 
						  (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB 
						   >> 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb))))
						   : VL_ULL(0));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1 = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA1 
						  + vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB1);
    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1 
		       >> 0x3fU)))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc = 1U;
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
	    = (~ vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1);
    } else {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
	    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1;
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC = VL_ULL(0);
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc = 0U;
    } else {
	if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
				  >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E;
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
			       >> 0x35U)))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
		       >> 1U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc))) {
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst));
	} else {
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC));
	}
    }
}

VL_INLINE_OPT void VFpuFp64B::_combo__TOP__6(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_combo__TOP__6\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp64_Add.v:53
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgna = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fpaSrcA 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnb = (1U & (IData)(
							    (vlTOPp->FpuFp64B__DOT__fpaSrcB 
							     >> 0x3fU)));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fpaSrcA 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb = ((0x1800U 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb)) 
					      | (0x7ffU 
						 & (IData)(
							   (vlTOPp->FpuFp64B__DOT__fpaSrcB 
							    >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb = (0x7ffU 
					      & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm = (((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa) 
					       >= (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb))
					       ? (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa)
					       : (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb));
    if (vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgna) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA) 
	     | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->FpuFp64B__DOT__fpaSrcA)));
    } else {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					 & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA) 
	     | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fpaSrcA));
    }
    if (((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnb) 
	 ^ ((2U == (IData)(vlTOPp->opMode)) | (4U == (IData)(vlTOPp->opMode))))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB) 
	     | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->FpuFp64B__DOT__fpaSrcB)));
    } else {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					 & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB = 
	    ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB) 
	     | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fpaSrcB));
    }
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA1 = ((0x3fU 
						   >= 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa))))
						   ? 
						  (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA 
						   >> 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exa))))
						   : VL_ULL(0));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB1 = ((0x3fU 
						   >= 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb))))
						   ? 
						  (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB 
						   >> 
						   (0x1fffU 
						    & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
						       - (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exb))))
						   : VL_ULL(0));
    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1 = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracA1 
						  + vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracB1);
    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1 
		       >> 0x3fU)))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc = 1U;
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
	    = (~ vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1);
    } else {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
	    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC1;
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC = VL_ULL(0);
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc = 0U;
    } else {
	if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
				  >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_A;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_B;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_C;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_D;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E;
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    if ((1U & (IData)((vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
			       >> 0x35U)))) {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2 
		       >> 1U);
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm)));
	    } else {
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp64B__DOT__fpadd__DOT__exm;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc))) {
	vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc))) {
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst));
	} else {
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->FpuFp64B__DOT__fpadd__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->FpuFp64B__DOT__fpadd__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp64B.v:128
    if ((8U & (IData)(vlTOPp->opMode))) {
	if ((4U & (IData)(vlTOPp->opMode))) {
	    vlTOPp->FpuFp64B__DOT__tDst = ((2U & (IData)(vlTOPp->opMode))
					    ? ((1U 
						& (IData)(vlTOPp->opMode))
					        ? vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst
					        : vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst2)
					    : vlTOPp->FpuFp64B__DOT__fcSrcB);
	} else {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		vlTOPp->FpuFp64B__DOT__tSro = ((1U 
						& (IData)(vlTOPp->opMode))
					        ? (
						   (1U 
						    & (IData)(
							      (vlTOPp->FpuFp64B__DOT__fcSrcA 
							       >> 0x3fU)))
						    ? 
						   ((1U 
						     & (IData)(
							       (vlTOPp->FpuFp64B__DOT__fcSrcB 
								>> 0x3fU)))
						     ? 
						    ((0xeU 
						      & (IData)(vlTOPp->FpuFp64B__DOT__tSro)) 
						     | ((VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcA) 
							< 
							(VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcB)))
						     : 
						    (0xeU 
						     & (IData)(vlTOPp->FpuFp64B__DOT__tSro)))
						    : 
						   ((1U 
						     & (IData)(
							       (vlTOPp->FpuFp64B__DOT__fcSrcB 
								>> 0x3fU)))
						     ? 
						    (1U 
						     | (IData)(vlTOPp->FpuFp64B__DOT__tSro))
						     : 
						    ((0xeU 
						      & (IData)(vlTOPp->FpuFp64B__DOT__tSro)) 
						     | ((VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcA) 
							> 
							(VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcB)))))
					        : (
						   (0xeU 
						    & (IData)(vlTOPp->FpuFp64B__DOT__tSro)) 
						   | (vlTOPp->FpuFp64B__DOT__fcSrcA 
						      == vlTOPp->FpuFp64B__DOT__fcSrcB)));
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp64B__DOT__tDst = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst;
		} else {
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x7fffffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | ((QData)((IData)(
								      (1U 
								       & (IData)(
										(vlTOPp->FpuFp64B__DOT__fcSrcB 
										>> 0x3fU))))) 
						      << 0x3fU));
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & (VL_ULL(0x3ff0000000000000) 
							 + 
							 (VL_ULL(0x3fffffffffffffff) 
							  & ((vlTOPp->FpuFp64B__DOT__fcSrcB 
							      - VL_ULL(0x3ff0000000000000)) 
							     >> 1U)))));
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x7fffffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | ((QData)((IData)(
								      (1U 
								       & (IData)(
										(vlTOPp->FpuFp64B__DOT__fcSrcB 
										>> 0x3fU))))) 
						      << 0x3fU));
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & (VL_ULL(0x3ff0000000000000) 
							 + 
							 VL_NEGATE_Q(
								     (vlTOPp->FpuFp64B__DOT__fcSrcB 
								      - VL_ULL(0x3ff0000000000000))))));
		} else {
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x7fffffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | ((QData)((IData)(
								      (1U 
								       & (~ (IData)(
										(vlTOPp->FpuFp64B__DOT__fcSrcB 
										>> 0x3fU)))))) 
						      << 0x3fU));
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & vlTOPp->FpuFp64B__DOT__fcSrcB));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp64B__DOT__tDst = (VL_ULL(0x7fffffffffffffff) 
						   & vlTOPp->FpuFp64B__DOT__tDst);
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & vlTOPp->FpuFp64B__DOT__fcSrcB));
		} else {
		    vlTOPp->FpuFp64B__DOT__tDst = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst;
		}
	    }
	} else {
	    vlTOPp->FpuFp64B__DOT__tDst = ((2U & (IData)(vlTOPp->opMode))
					    ? ((1U 
						& (IData)(vlTOPp->opMode))
					        ? vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst
					        : vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst)
					    : ((1U 
						& (IData)(vlTOPp->opMode))
					        ? vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst
					        : VL_ULL(0)));
	}
    }
}

void VFpuFp64B::_settle__TOP__7(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_settle__TOP__7\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp64B.v:128
    if ((8U & (IData)(vlTOPp->opMode))) {
	if ((4U & (IData)(vlTOPp->opMode))) {
	    vlTOPp->FpuFp64B__DOT__tDst = ((2U & (IData)(vlTOPp->opMode))
					    ? ((1U 
						& (IData)(vlTOPp->opMode))
					        ? vlTOPp->FpuFp64B__DOT__cnv2is1__DOT__tDst
					        : vlTOPp->FpuFp64B__DOT__cnv2si1__DOT__tDst2)
					    : vlTOPp->FpuFp64B__DOT__fcSrcB);
	} else {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		vlTOPp->FpuFp64B__DOT__tSro = ((1U 
						& (IData)(vlTOPp->opMode))
					        ? (
						   (1U 
						    & (IData)(
							      (vlTOPp->FpuFp64B__DOT__fcSrcA 
							       >> 0x3fU)))
						    ? 
						   ((1U 
						     & (IData)(
							       (vlTOPp->FpuFp64B__DOT__fcSrcB 
								>> 0x3fU)))
						     ? 
						    ((0xeU 
						      & (IData)(vlTOPp->FpuFp64B__DOT__tSro)) 
						     | ((VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcA) 
							< 
							(VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcB)))
						     : 
						    (0xeU 
						     & (IData)(vlTOPp->FpuFp64B__DOT__tSro)))
						    : 
						   ((1U 
						     & (IData)(
							       (vlTOPp->FpuFp64B__DOT__fcSrcB 
								>> 0x3fU)))
						     ? 
						    (1U 
						     | (IData)(vlTOPp->FpuFp64B__DOT__tSro))
						     : 
						    ((0xeU 
						      & (IData)(vlTOPp->FpuFp64B__DOT__tSro)) 
						     | ((VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcA) 
							> 
							(VL_ULL(0x7fffffffffffffff) 
							 & vlTOPp->FpuFp64B__DOT__fcSrcB)))))
					        : (
						   (0xeU 
						    & (IData)(vlTOPp->FpuFp64B__DOT__tSro)) 
						   | (vlTOPp->FpuFp64B__DOT__fcSrcA 
						      == vlTOPp->FpuFp64B__DOT__fcSrcB)));
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp64B__DOT__tDst = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst;
		} else {
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x7fffffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | ((QData)((IData)(
								      (1U 
								       & (IData)(
										(vlTOPp->FpuFp64B__DOT__fcSrcB 
										>> 0x3fU))))) 
						      << 0x3fU));
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & (VL_ULL(0x3ff0000000000000) 
							 + 
							 (VL_ULL(0x3fffffffffffffff) 
							  & ((vlTOPp->FpuFp64B__DOT__fcSrcB 
							      - VL_ULL(0x3ff0000000000000)) 
							     >> 1U)))));
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x7fffffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | ((QData)((IData)(
								      (1U 
								       & (IData)(
										(vlTOPp->FpuFp64B__DOT__fcSrcB 
										>> 0x3fU))))) 
						      << 0x3fU));
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & (VL_ULL(0x3ff0000000000000) 
							 + 
							 VL_NEGATE_Q(
								     (vlTOPp->FpuFp64B__DOT__fcSrcB 
								      - VL_ULL(0x3ff0000000000000))))));
		} else {
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x7fffffffffffffff) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | ((QData)((IData)(
								      (1U 
								       & (~ (IData)(
										(vlTOPp->FpuFp64B__DOT__fcSrcB 
										>> 0x3fU)))))) 
						      << 0x3fU));
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & vlTOPp->FpuFp64B__DOT__fcSrcB));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp64B__DOT__tDst = (VL_ULL(0x7fffffffffffffff) 
						   & vlTOPp->FpuFp64B__DOT__tDst);
		    vlTOPp->FpuFp64B__DOT__tDst = (
						   (VL_ULL(0x8000000000000000) 
						    & vlTOPp->FpuFp64B__DOT__tDst) 
						   | (VL_ULL(0x7fffffffffffffff) 
						      & vlTOPp->FpuFp64B__DOT__fcSrcB));
		} else {
		    vlTOPp->FpuFp64B__DOT__tDst = vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst;
		}
	    }
	} else {
	    vlTOPp->FpuFp64B__DOT__tDst = ((2U & (IData)(vlTOPp->opMode))
					    ? ((1U 
						& (IData)(vlTOPp->opMode))
					        ? vlTOPp->FpuFp64B__DOT__fpmul__DOT__tDst
					        : vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst)
					    : ((1U 
						& (IData)(vlTOPp->opMode))
					        ? vlTOPp->FpuFp64B__DOT__fpadd__DOT__tDst
					        : VL_ULL(0)));
	}
    }
    vlTOPp->sro = vlTOPp->FpuFp64B__DOT__tSro;
    // ALWAYS at FpuFp64To32.v:21
    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa = (0x7ffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa = ((0x800U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa)) 
					       | (0x7ffU 
						  & (IData)(
							    (vlTOPp->FpuFp64B__DOT__tDst 
							     >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb = (0xfffU 
					       & ((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa) 
						  - (IData)(0x380U)));
    if ((0U == (0xfU & ((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb) 
			>> 8U)))) {
	vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 
	    ((0x7fffffffU & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
	     | (0x80000000U & ((IData)((vlTOPp->FpuFp64B__DOT__tDst 
					>> 0x3fU)) 
			       << 0x1fU)));
	vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 
	    ((0x807fffffU & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
	     | (0x7f800000U & ((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb) 
			       << 0x17U)));
	vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 
	    ((0xff800000U & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
	     | (0x7fffffU & (IData)((vlTOPp->FpuFp64B__DOT__tDst 
				     >> 0x1dU))));
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb))) {
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 0U;
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
		   | (0x80000000U & ((IData)((vlTOPp->FpuFp64B__DOT__tDst 
					      >> 0x3fU)) 
				     << 0x1fU)));
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst 
		= (0x7f800000U | vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst 
		= (0xff800000U & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst);
	}
    }
}

VL_INLINE_OPT void VFpuFp64B::_combo__TOP__8(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_combo__TOP__8\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sro = vlTOPp->FpuFp64B__DOT__tSro;
    // ALWAYS at FpuFp64To32.v:21
    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa = (0x7ffU 
					       & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa));
    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa = ((0x800U 
						& (IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa)) 
					       | (0x7ffU 
						  & (IData)(
							    (vlTOPp->FpuFp64B__DOT__tDst 
							     >> 0x34U))));
    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb = (0xfffU 
					       & ((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exa) 
						  - (IData)(0x380U)));
    if ((0U == (0xfU & ((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb) 
			>> 8U)))) {
	vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 
	    ((0x7fffffffU & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
	     | (0x80000000U & ((IData)((vlTOPp->FpuFp64B__DOT__tDst 
					>> 0x3fU)) 
			       << 0x1fU)));
	vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 
	    ((0x807fffffU & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
	     | (0x7f800000U & ((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb) 
			       << 0x17U)));
	vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 
	    ((0xff800000U & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
	     | (0x7fffffU & (IData)((vlTOPp->FpuFp64B__DOT__tDst 
				     >> 0x1dU))));
    } else {
	if ((0x800U & (IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__exb))) {
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst = 0U;
	} else {
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst) 
		   | (0x80000000U & ((IData)((vlTOPp->FpuFp64B__DOT__tDst 
					      >> 0x3fU)) 
				     << 0x1fU)));
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst 
		= (0x7f800000U | vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst);
	    vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst 
		= (0xff800000U & vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst);
	}
    }
    vlTOPp->FpuFp64B__DOT__fpCnvdDst = ((VL_ULL(0xffffffff00000000) 
					 & vlTOPp->FpuFp64B__DOT__fpCnvdDst) 
					| (IData)((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst)));
}

void VFpuFp64B::_settle__TOP__9(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_settle__TOP__9\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FpuFp64B__DOT__fpCnvdDst = ((VL_ULL(0xffffffff00000000) 
					 & vlTOPp->FpuFp64B__DOT__fpCnvdDst) 
					| (IData)((IData)(vlTOPp->FpuFp64B__DOT__fpcnvd__DOT__tDst)));
    vlTOPp->dst = ((((IData)(vlTOPp->opf32) | (0xdU 
					       == (IData)(vlTOPp->opMode))) 
		    & (0xeU != (IData)(vlTOPp->opMode)))
		    ? vlTOPp->FpuFp64B__DOT__fpCnvdDst
		    : vlTOPp->FpuFp64B__DOT__tDst);
}

VL_INLINE_OPT void VFpuFp64B::_combo__TOP__10(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_combo__TOP__10\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->dst = ((((IData)(vlTOPp->opf32) | (0xdU 
					       == (IData)(vlTOPp->opMode))) 
		    & (0xeU != (IData)(vlTOPp->opMode)))
		    ? vlTOPp->FpuFp64B__DOT__fpCnvdDst
		    : vlTOPp->FpuFp64B__DOT__tDst);
}

void VFpuFp64B::_eval(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_eval\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->_combo__TOP__10(vlSymsp);
}

void VFpuFp64B::_eval_initial(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_eval_initial\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFpuFp64B::final() {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::final\n"); );
    // Variables
    VFpuFp64B__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFpuFp64B::_eval_settle(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_eval_settle\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
    vlTOPp->_settle__TOP__9(vlSymsp);
}

VL_INLINE_OPT QData VFpuFp64B::_change_request(VFpuFp64B__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_change_request\n"); );
    VFpuFp64B* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VFpuFp64B::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    opf32 = VL_RAND_RESET_I(1);
    opMode = VL_RAND_RESET_I(4);
    srca = VL_RAND_RESET_Q(64);
    srcb = VL_RAND_RESET_Q(64);
    srcc = VL_RAND_RESET_Q(64);
    dst = VL_RAND_RESET_Q(64);
    sri = VL_RAND_RESET_I(4);
    sro = VL_RAND_RESET_I(4);
    FpuFp64B__DOT__fcSrcA = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fcSrcB = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpaSrcA = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpaSrcB = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__tOpFp32i = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__tSro = VL_RAND_RESET_I(4);
    FpuFp64B__DOT__fpCnvdDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__sgna = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__fpadd__DOT__sgnb = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__fpadd__DOT__sgnc = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__fpadd__DOT__exa = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__exb = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__exc = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__exm = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__tFracA = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracB = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracA1 = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracB1 = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC1 = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC2 = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC2_A = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC2_B = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC2_C = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC2_D = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tFracC2_E = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpadd__DOT__tExc_A = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__tExc_B = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__tExc_C = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__tExc_D = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__tExc_E = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpadd__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpmul__DOT__sgna = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__fpmul__DOT__sgnb = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__fpmul__DOT__sgnc = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__fpmul__DOT__exa = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpmul__DOT__exb = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpmul__DOT__exc = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__fpmul__DOT__tFracA = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpmul__DOT__tFracB = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpmul__DOT__tFracC = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpmul__DOT__tFracC2 = VL_RAND_RESET_Q(52);
    FpuFp64B__DOT__fpmul__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpcnva__DOT__exa = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnva__DOT__exb = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnva__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpcnvb__DOT__exa = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnvb__DOT__exb = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnvb__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpcnvc__DOT__exa = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnvc__DOT__exb = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnvc__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2si1__DOT__exa = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__cnv2si1__DOT__exb = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__cnv2si1__DOT__fra = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2si1__DOT__sgn = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__cnv2si1__DOT__tShl = VL_RAND_RESET_I(6);
    FpuFp64B__DOT__cnv2si1__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2si1__DOT__tDst2 = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__sgnc = VL_RAND_RESET_I(1);
    FpuFp64B__DOT__cnv2is1__DOT__exc = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__exm = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC2 = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC2_A = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC2_B = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC2_C = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC2_D = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tFracC2_E = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__cnv2is1__DOT__tExc_A = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__tExc_B = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__tExc_C = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__tExc_D = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__tExc_E = VL_RAND_RESET_I(13);
    FpuFp64B__DOT__cnv2is1__DOT__tDst = VL_RAND_RESET_Q(64);
    FpuFp64B__DOT__fpcnvd__DOT__exa = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnvd__DOT__exb = VL_RAND_RESET_I(12);
    FpuFp64B__DOT__fpcnvd__DOT__tDst = VL_RAND_RESET_I(32);
}

void VFpuFp64B::_configure_coverage(VFpuFp64B__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp64B::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
