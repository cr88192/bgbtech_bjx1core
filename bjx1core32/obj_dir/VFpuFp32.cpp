// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VFpuFp32.h for the primary calling header

#include "VFpuFp32.h"          // For This
#include "VFpuFp32__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VFpuFp32) {
    VFpuFp32__Syms* __restrict vlSymsp = __VlSymsp = new VFpuFp32__Syms(this, name());
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VFpuFp32::__Vconfigure(VFpuFp32__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VFpuFp32::~VFpuFp32() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VFpuFp32::eval() {
    VFpuFp32__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VFpuFp32::eval\n"); );
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

void VFpuFp32::_eval_initial_loop(VFpuFp32__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void VFpuFp32::_combo__TOP__1(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_combo__TOP__1\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp32_Add.v:47
    vlTOPp->FpuFp32__DOT__fpadd__DOT__sgna = (1U & 
					      (vlTOPp->srca 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnb = (1U & 
					      (vlTOPp->srcb 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exa = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa)) 
					     | (0xffU 
						& (vlTOPp->srca 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exb = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb)) 
					     | (0xffU 
						& (vlTOPp->srcb 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exa = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exb = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exm = (((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa) 
					      >= (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb))
					      ? (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa)
					      : (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb));
    if (vlTOPp->FpuFp32__DOT__fpadd__DOT__sgna) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    (0xff000000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA) 
	     | (0x7fffffU & (~ vlTOPp->srca)));
    } else {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    (0x800000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA) 
	     | (0x7fffffU & vlTOPp->srca));
    }
    if (((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnb) 
	 ^ (2U == (IData)(vlTOPp->opMode)))) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    (0xff000000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB) 
	     | (0x7fffffU & (~ vlTOPp->srcb)));
    } else {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    (0x800000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB) 
	     | (0x7fffffU & vlTOPp->srcb));
    }
    vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA1 = ((0x1fU 
						  >= 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa))))
						  ? 
						 (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA 
						  >> 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa))))
						  : 0U);
    vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB1 = ((0x1fU 
						  >= 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb))))
						  ? 
						 (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB 
						  >> 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb))))
						  : 0U);
    vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1 = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA1 
						 + vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB1);
    if ((0x80000000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1)) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc = 1U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 = 
	    (~ vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1);
    } else {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1;
    }
    if ((0U == (0xffffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2))) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC = 0U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__exc = 0U;
    } else {
	if ((0U == (3U & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
			  >> 0x17U)))) {
	    if ((0U == (0xffffU & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
				   >> 8U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
		       << 0x10U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
				 - (IData)(0x10U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__exm;
	    }
	    if ((0U == (0xffU & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
				 >> 0x10U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
		       << 8U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A) 
				 - (IData)(8U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A;
	    }
	    if ((0U == (0xfU & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
				>> 0x14U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
		       << 4U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B) 
				 - (IData)(4U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B;
	    }
	    if ((0U == (3U & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
			      >> 0x16U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
		       << 2U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C) 
				 - (IData)(2U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C;
	    }
	    if ((0x800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D)) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D;
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D 
		       << 1U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D) 
				 - (IData)(1U)));
	    }
	} else {
	    if ((0x1000000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2)) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
		       >> 1U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__exm;
	    }
	}
    }
    if ((0x200U & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exc))) {
	vlTOPp->FpuFp32__DOT__fpaDst = 0U;
    } else {
	if ((0x100U & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exc))) {
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0x7fffffffU 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc) 
					       << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpaDst = (0x7f800000U 
					    | (0x80000000U 
					       & vlTOPp->FpuFp32__DOT__fpaDst));
	} else {
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0x7fffffffU 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc) 
					       << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0x807fffffU 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | (0x7f800000U 
					       & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exc) 
						  << 0x17U)));
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0xff800000U 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | (0x7fffffU 
					       & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp32_Rcp.v:22
    vlTOPp->FpuFp32__DOT__fprcp__DOT__exa = (0xffU 
					     & (vlTOPp->srcb 
						>> 0x17U));
    vlTOPp->FpuFp32__DOT__fprcp__DOT__fra = (0x7fffffU 
					     & vlTOPp->FpuFp32__DOT__fprcp__DOT__fra);
    vlTOPp->FpuFp32__DOT__fprcp__DOT__fra = ((0x800000U 
					      & vlTOPp->FpuFp32__DOT__fprcp__DOT__fra) 
					     | (0x7fffffU 
						& vlTOPp->srcb));
    vlTOPp->FpuFp32__DOT__fprcp__DOT__tFr2 = (0xffffffU 
					      & ((0xffffffU 
						  & (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						     >> 0xcU)) 
						 * 
						 (0xffffffU 
						  & (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						     >> 0xcU))));
    vlTOPp->FpuFp32__DOT__fprcp__DOT__frb = (0xffffffU 
					     & ((((((IData)(0x800000U) 
						    - 
						    (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						     >> 1U)) 
						   - 
						   (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						    >> 2U)) 
						  - 
						  (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						   >> 3U)) 
						 + 
						 (vlTOPp->FpuFp32__DOT__fprcp__DOT__tFr2 
						  >> 1U)) 
						+ (vlTOPp->FpuFp32__DOT__fprcp__DOT__tFr2 
						   >> 2U)));
    if ((0x800000U & vlTOPp->FpuFp32__DOT__fprcp__DOT__frb)) {
	vlTOPp->FpuFp32__DOT__fprcp__DOT__exb = (0xffU 
						 & ((IData)(0xfeU) 
						    - (IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exa)));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x7fffffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x80000000U 
					     & vlTOPp->srcb));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x807fffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | ((IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exb) 
					     << 0x17U));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0xff800000U 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x7fffffU 
					     & vlTOPp->FpuFp32__DOT__fprcp__DOT__frb));
    } else {
	vlTOPp->FpuFp32__DOT__fprcp__DOT__exb = (0xffU 
						 & ((IData)(0xfdU) 
						    - (IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exa)));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x7fffffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x80000000U 
					     & vlTOPp->srcb));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x807fffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | ((IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exb) 
					     << 0x17U));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0xff800001U 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x7ffffeU 
					     & (vlTOPp->FpuFp32__DOT__fprcp__DOT__frb 
						<< 1U)));
    }
}

void VFpuFp32::_settle__TOP__2(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_settle__TOP__2\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp32_Add.v:47
    vlTOPp->FpuFp32__DOT__fpadd__DOT__sgna = (1U & 
					      (vlTOPp->srca 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnb = (1U & 
					      (vlTOPp->srcb 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exa = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa)) 
					     | (0xffU 
						& (vlTOPp->srca 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exb = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb)) 
					     | (0xffU 
						& (vlTOPp->srcb 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exa = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exb = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb));
    vlTOPp->FpuFp32__DOT__fpadd__DOT__exm = (((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa) 
					      >= (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb))
					      ? (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa)
					      : (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb));
    if (vlTOPp->FpuFp32__DOT__fpadd__DOT__sgna) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    (0xff000000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA) 
	     | (0x7fffffU & (~ vlTOPp->srca)));
    } else {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    (0x800000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA) 
	     | (0x7fffffU & vlTOPp->srca));
    }
    if (((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnb) 
	 ^ (2U == (IData)(vlTOPp->opMode)))) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    (0xff000000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB) 
	     | (0x7fffffU & (~ vlTOPp->srcb)));
    } else {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    (0x800000U | (0x7fffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB));
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB = 
	    ((0xff800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB) 
	     | (0x7fffffU & vlTOPp->srcb));
    }
    vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA1 = ((0x1fU 
						  >= 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa))))
						  ? 
						 (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA 
						  >> 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exa))))
						  : 0U);
    vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB1 = ((0x1fU 
						  >= 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb))))
						  ? 
						 (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB 
						  >> 
						  (0x3ffU 
						   & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
						      - (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exb))))
						  : 0U);
    vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1 = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracA1 
						 + vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracB1);
    if ((0x80000000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1)) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc = 1U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 = 
	    (~ vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1);
    } else {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC1;
    }
    if ((0U == (0xffffffU & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2))) {
	vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC = 0U;
	vlTOPp->FpuFp32__DOT__fpadd__DOT__exc = 0U;
    } else {
	if ((0U == (3U & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
			  >> 0x17U)))) {
	    if ((0U == (0xffffU & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
				   >> 8U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
		       << 0x10U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm) 
				 - (IData)(0x10U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__exm;
	    }
	    if ((0U == (0xffU & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
				 >> 0x10U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A 
		       << 8U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A) 
				 - (IData)(8U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_A;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_A;
	    }
	    if ((0U == (0xfU & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
				>> 0x14U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B 
		       << 4U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B) 
				 - (IData)(4U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_B;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_B;
	    }
	    if ((0U == (3U & (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
			      >> 0x16U)))) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C 
		       << 2U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C) 
				 - (IData)(2U)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_C;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_C;
	    }
	    if ((0x800000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D)) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D;
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2_D 
		       << 1U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = (0x3ffU & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__tExc_D) 
				 - (IData)(1U)));
	    }
	} else {
	    if ((0x1000000U & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2)) {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2 
		       >> 1U);
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exm)));
	    } else {
		vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC2;
		vlTOPp->FpuFp32__DOT__fpadd__DOT__exc 
		    = vlTOPp->FpuFp32__DOT__fpadd__DOT__exm;
	    }
	}
    }
    if ((0x200U & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exc))) {
	vlTOPp->FpuFp32__DOT__fpaDst = 0U;
    } else {
	if ((0x100U & (IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exc))) {
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0x7fffffffU 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc) 
					       << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpaDst = (0x7f800000U 
					    | (0x80000000U 
					       & vlTOPp->FpuFp32__DOT__fpaDst));
	} else {
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0x7fffffffU 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__sgnc) 
					       << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0x807fffffU 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | (0x7f800000U 
					       & ((IData)(vlTOPp->FpuFp32__DOT__fpadd__DOT__exc) 
						  << 0x17U)));
	    vlTOPp->FpuFp32__DOT__fpaDst = ((0xff800000U 
					     & vlTOPp->FpuFp32__DOT__fpaDst) 
					    | (0x7fffffU 
					       & vlTOPp->FpuFp32__DOT__fpadd__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp32_Rcp.v:22
    vlTOPp->FpuFp32__DOT__fprcp__DOT__exa = (0xffU 
					     & (vlTOPp->srcb 
						>> 0x17U));
    vlTOPp->FpuFp32__DOT__fprcp__DOT__fra = (0x7fffffU 
					     & vlTOPp->FpuFp32__DOT__fprcp__DOT__fra);
    vlTOPp->FpuFp32__DOT__fprcp__DOT__fra = ((0x800000U 
					      & vlTOPp->FpuFp32__DOT__fprcp__DOT__fra) 
					     | (0x7fffffU 
						& vlTOPp->srcb));
    vlTOPp->FpuFp32__DOT__fprcp__DOT__tFr2 = (0xffffffU 
					      & ((0xffffffU 
						  & (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						     >> 0xcU)) 
						 * 
						 (0xffffffU 
						  & (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						     >> 0xcU))));
    vlTOPp->FpuFp32__DOT__fprcp__DOT__frb = (0xffffffU 
					     & ((((((IData)(0x800000U) 
						    - 
						    (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						     >> 1U)) 
						   - 
						   (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						    >> 2U)) 
						  - 
						  (vlTOPp->FpuFp32__DOT__fprcp__DOT__fra 
						   >> 3U)) 
						 + 
						 (vlTOPp->FpuFp32__DOT__fprcp__DOT__tFr2 
						  >> 1U)) 
						+ (vlTOPp->FpuFp32__DOT__fprcp__DOT__tFr2 
						   >> 2U)));
    if ((0x800000U & vlTOPp->FpuFp32__DOT__fprcp__DOT__frb)) {
	vlTOPp->FpuFp32__DOT__fprcp__DOT__exb = (0xffU 
						 & ((IData)(0xfeU) 
						    - (IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exa)));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x7fffffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x80000000U 
					     & vlTOPp->srcb));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x807fffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | ((IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exb) 
					     << 0x17U));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0xff800000U 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x7fffffU 
					     & vlTOPp->FpuFp32__DOT__fprcp__DOT__frb));
    } else {
	vlTOPp->FpuFp32__DOT__fprcp__DOT__exb = (0xffU 
						 & ((IData)(0xfdU) 
						    - (IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exa)));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x7fffffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x80000000U 
					     & vlTOPp->srcb));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0x807fffffU 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | ((IData)(vlTOPp->FpuFp32__DOT__fprcp__DOT__exb) 
					     << 0x17U));
	vlTOPp->FpuFp32__DOT__fpRcpDst = ((0xff800001U 
					   & vlTOPp->FpuFp32__DOT__fpRcpDst) 
					  | (0x7ffffeU 
					     & (vlTOPp->FpuFp32__DOT__fprcp__DOT__frb 
						<< 1U)));
    }
    vlTOPp->FpuFp32__DOT__fpmSrcB = ((4U == (IData)(vlTOPp->opMode))
				      ? vlTOPp->FpuFp32__DOT__fpRcpDst
				      : vlTOPp->srcb);
}

VL_INLINE_OPT void VFpuFp32::_combo__TOP__3(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_combo__TOP__3\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FpuFp32__DOT__fpmSrcB = ((4U == (IData)(vlTOPp->opMode))
				      ? vlTOPp->FpuFp32__DOT__fpRcpDst
				      : vlTOPp->srcb);
    // ALWAYS at FpuFp32_Mul.v:29
    vlTOPp->FpuFp32__DOT__fpmul__DOT__sgna = (1U & 
					      (vlTOPp->srca 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnb = (1U & 
					      (vlTOPp->FpuFp32__DOT__fpmSrcB 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exa = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa)) 
					     | (0xffU 
						& (vlTOPp->srca 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exb = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb)) 
					     | (0xffU 
						& (vlTOPp->FpuFp32__DOT__fpmSrcB 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exa = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exb = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnc = ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgna) 
					      ^ (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnb));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA = (VL_ULL(0x800000) 
						| (VL_ULL(0x7fffff) 
						   & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB = (VL_ULL(0x800000) 
						| (VL_ULL(0x7fffff) 
						   & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA = ((VL_ULL(0xffffff800000) 
						 & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA) 
						| (IData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->srca))));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB = ((VL_ULL(0xffffff800000) 
						 & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB) 
						| (IData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->FpuFp32__DOT__fpmSrcB))));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC = (VL_ULL(0xffffffffffff) 
						& (vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA 
						   * vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB));
    if ((1U & (IData)((vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC 
		       >> 0x2fU)))) {
	vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC2 = 
	    (0x7fffffU & (IData)((vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC 
				  >> 0x18U)));
	vlTOPp->FpuFp32__DOT__fpmul__DOT__exc = (0x3ffU 
						 & (((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa) 
						     + (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb)) 
						    - (IData)(0x7eU)));
    }
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC2 = (0x7fffffU 
						 & (IData)(
							   (vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC 
							    >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exc = (0x3ffU 
					     & (((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa) 
						 + (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb)) 
						- (IData)(0x7fU)));
    if ((0x200U & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exc))) {
	vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst = 0U;
    } else {
	if ((0x100U & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exc))) {
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnc) 
		      << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= (0x7f800000U | (0x80000000U & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst));
	} else {
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnc) 
		      << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0x807fffffU & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | (0x7f800000U & ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exc) 
				     << 0x17U)));
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0xff800000U & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC2);
	}
    }
    vlTOPp->FpuFp32__DOT__fpmDst = vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst;
}

void VFpuFp32::_settle__TOP__4(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_settle__TOP__4\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp32_Mul.v:29
    vlTOPp->FpuFp32__DOT__fpmul__DOT__sgna = (1U & 
					      (vlTOPp->srca 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnb = (1U & 
					      (vlTOPp->FpuFp32__DOT__fpmSrcB 
					       >> 0x1fU));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exa = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa)) 
					     | (0xffU 
						& (vlTOPp->srca 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exb = ((0x300U 
					      & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb)) 
					     | (0xffU 
						& (vlTOPp->FpuFp32__DOT__fpmSrcB 
						   >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exa = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exb = (0xffU 
					     & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnc = ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgna) 
					      ^ (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnb));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA = (VL_ULL(0x800000) 
						| (VL_ULL(0x7fffff) 
						   & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB = (VL_ULL(0x800000) 
						| (VL_ULL(0x7fffff) 
						   & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA = ((VL_ULL(0xffffff800000) 
						 & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA) 
						| (IData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->srca))));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB = ((VL_ULL(0xffffff800000) 
						 & vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB) 
						| (IData)((IData)(
								  (0x7fffffU 
								   & vlTOPp->FpuFp32__DOT__fpmSrcB))));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC = (VL_ULL(0xffffffffffff) 
						& (vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracA 
						   * vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracB));
    if ((1U & (IData)((vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC 
		       >> 0x2fU)))) {
	vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC2 = 
	    (0x7fffffU & (IData)((vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC 
				  >> 0x18U)));
	vlTOPp->FpuFp32__DOT__fpmul__DOT__exc = (0x3ffU 
						 & (((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa) 
						     + (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb)) 
						    - (IData)(0x7eU)));
    }
    vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC2 = (0x7fffffU 
						 & (IData)(
							   (vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC 
							    >> 0x17U)));
    vlTOPp->FpuFp32__DOT__fpmul__DOT__exc = (0x3ffU 
					     & (((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exa) 
						 + (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exb)) 
						- (IData)(0x7fU)));
    if ((0x200U & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exc))) {
	vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst = 0U;
    } else {
	if ((0x100U & (IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exc))) {
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnc) 
		      << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= (0x7f800000U | (0x80000000U & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst));
	} else {
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__sgnc) 
		      << 0x1fU));
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0x807fffffU & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | (0x7f800000U & ((IData)(vlTOPp->FpuFp32__DOT__fpmul__DOT__exc) 
				     << 0x17U)));
	    vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst 
		= ((0xff800000U & vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst) 
		   | vlTOPp->FpuFp32__DOT__fpmul__DOT__tFracC2);
	}
    }
    vlTOPp->FpuFp32__DOT__fpmDst = vlTOPp->FpuFp32__DOT__fpmul__DOT__tDst;
    // ALWAYS at FpuFp32.v:50
    if ((8U & (IData)(vlTOPp->opMode))) {
	vlTOPp->FpuFp32__DOT__tDst = ((4U & (IData)(vlTOPp->opMode))
				       ? vlTOPp->srcb
				       : ((2U & (IData)(vlTOPp->opMode))
					   ? vlTOPp->srcb
					   : ((1U & (IData)(vlTOPp->opMode))
					       ? vlTOPp->srcb
					       : ((IData)(0x3f800000U) 
						  + 
						  ((vlTOPp->srcb 
						    - (IData)(0x3f800000U)) 
						   >> 1U)))));
    } else {
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp32__DOT__tDst = vlTOPp->FpuFp32__DOT__fpRcpDst;
		} else {
		    vlTOPp->FpuFp32__DOT__tDst = ((0x7fffffffU 
						   & vlTOPp->FpuFp32__DOT__tDst) 
						  | (0x80000000U 
						     & ((~ 
							 (vlTOPp->srcb 
							  >> 0x1fU)) 
							<< 0x1fU)));
		    vlTOPp->FpuFp32__DOT__tDst = ((0x80000000U 
						   & vlTOPp->FpuFp32__DOT__tDst) 
						  | (0x7fffffffU 
						     & vlTOPp->srcb));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp32__DOT__tDst = (0x7fffffffU 
						  & vlTOPp->FpuFp32__DOT__tDst);
		    vlTOPp->FpuFp32__DOT__tDst = ((0x80000000U 
						   & vlTOPp->FpuFp32__DOT__tDst) 
						  | (0x7fffffffU 
						     & vlTOPp->srcb));
		} else {
		    vlTOPp->FpuFp32__DOT__tDst = vlTOPp->FpuFp32__DOT__fpmDst;
		}
	    }
	} else {
	    vlTOPp->FpuFp32__DOT__tDst = ((2U & (IData)(vlTOPp->opMode))
					   ? ((1U & (IData)(vlTOPp->opMode))
					       ? vlTOPp->FpuFp32__DOT__fpmDst
					       : vlTOPp->FpuFp32__DOT__fpaDst)
					   : ((1U & (IData)(vlTOPp->opMode))
					       ? vlTOPp->FpuFp32__DOT__fpaDst
					       : vlTOPp->srcb));
	}
    }
    vlTOPp->dst = vlTOPp->FpuFp32__DOT__tDst;
}

VL_INLINE_OPT void VFpuFp32::_combo__TOP__5(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_combo__TOP__5\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp32.v:50
    if ((8U & (IData)(vlTOPp->opMode))) {
	vlTOPp->FpuFp32__DOT__tDst = ((4U & (IData)(vlTOPp->opMode))
				       ? vlTOPp->srcb
				       : ((2U & (IData)(vlTOPp->opMode))
					   ? vlTOPp->srcb
					   : ((1U & (IData)(vlTOPp->opMode))
					       ? vlTOPp->srcb
					       : ((IData)(0x3f800000U) 
						  + 
						  ((vlTOPp->srcb 
						    - (IData)(0x3f800000U)) 
						   >> 1U)))));
    } else {
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp32__DOT__tDst = vlTOPp->FpuFp32__DOT__fpRcpDst;
		} else {
		    vlTOPp->FpuFp32__DOT__tDst = ((0x7fffffffU 
						   & vlTOPp->FpuFp32__DOT__tDst) 
						  | (0x80000000U 
						     & ((~ 
							 (vlTOPp->srcb 
							  >> 0x1fU)) 
							<< 0x1fU)));
		    vlTOPp->FpuFp32__DOT__tDst = ((0x80000000U 
						   & vlTOPp->FpuFp32__DOT__tDst) 
						  | (0x7fffffffU 
						     & vlTOPp->srcb));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->FpuFp32__DOT__tDst = (0x7fffffffU 
						  & vlTOPp->FpuFp32__DOT__tDst);
		    vlTOPp->FpuFp32__DOT__tDst = ((0x80000000U 
						   & vlTOPp->FpuFp32__DOT__tDst) 
						  | (0x7fffffffU 
						     & vlTOPp->srcb));
		} else {
		    vlTOPp->FpuFp32__DOT__tDst = vlTOPp->FpuFp32__DOT__fpmDst;
		}
	    }
	} else {
	    vlTOPp->FpuFp32__DOT__tDst = ((2U & (IData)(vlTOPp->opMode))
					   ? ((1U & (IData)(vlTOPp->opMode))
					       ? vlTOPp->FpuFp32__DOT__fpmDst
					       : vlTOPp->FpuFp32__DOT__fpaDst)
					   : ((1U & (IData)(vlTOPp->opMode))
					       ? vlTOPp->FpuFp32__DOT__fpaDst
					       : vlTOPp->srcb));
	}
    }
    vlTOPp->dst = vlTOPp->FpuFp32__DOT__tDst;
}

void VFpuFp32::_eval(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_eval\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->_combo__TOP__5(vlSymsp);
}

void VFpuFp32::_eval_initial(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_eval_initial\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFpuFp32::final() {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::final\n"); );
    // Variables
    VFpuFp32__Syms* __restrict vlSymsp = this->__VlSymsp;
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VFpuFp32::_eval_settle(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_eval_settle\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData VFpuFp32::_change_request(VFpuFp32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_change_request\n"); );
    VFpuFp32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VFpuFp32::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    opMode = VL_RAND_RESET_I(4);
    srca = VL_RAND_RESET_I(32);
    srcb = VL_RAND_RESET_I(32);
    dst = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpaDst = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpmSrcB = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpmDst = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpRcpDst = VL_RAND_RESET_I(32);
    FpuFp32__DOT__tDst = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__sgna = VL_RAND_RESET_I(1);
    FpuFp32__DOT__fpadd__DOT__sgnb = VL_RAND_RESET_I(1);
    FpuFp32__DOT__fpadd__DOT__sgnc = VL_RAND_RESET_I(1);
    FpuFp32__DOT__fpadd__DOT__exa = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__exb = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__exc = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__exm = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__tFracA = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracB = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracA1 = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracB1 = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC1 = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC2 = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC2_A = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC2_B = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC2_C = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tFracC2_D = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fpadd__DOT__tExc_A = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__tExc_B = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__tExc_C = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpadd__DOT__tExc_D = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpmul__DOT__sgna = VL_RAND_RESET_I(1);
    FpuFp32__DOT__fpmul__DOT__sgnb = VL_RAND_RESET_I(1);
    FpuFp32__DOT__fpmul__DOT__sgnc = VL_RAND_RESET_I(1);
    FpuFp32__DOT__fpmul__DOT__exa = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpmul__DOT__exb = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpmul__DOT__exc = VL_RAND_RESET_I(10);
    FpuFp32__DOT__fpmul__DOT__tFracA = VL_RAND_RESET_Q(48);
    FpuFp32__DOT__fpmul__DOT__tFracB = VL_RAND_RESET_Q(48);
    FpuFp32__DOT__fpmul__DOT__tFracC = VL_RAND_RESET_Q(48);
    FpuFp32__DOT__fpmul__DOT__tFracC2 = VL_RAND_RESET_I(23);
    FpuFp32__DOT__fpmul__DOT__tDst = VL_RAND_RESET_I(32);
    FpuFp32__DOT__fprcp__DOT__exa = VL_RAND_RESET_I(8);
    FpuFp32__DOT__fprcp__DOT__exb = VL_RAND_RESET_I(8);
    FpuFp32__DOT__fprcp__DOT__fra = VL_RAND_RESET_I(24);
    FpuFp32__DOT__fprcp__DOT__frb = VL_RAND_RESET_I(24);
    FpuFp32__DOT__fprcp__DOT__tFr2 = VL_RAND_RESET_I(24);
}

void VFpuFp32::_configure_coverage(VFpuFp32__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VFpuFp32::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
