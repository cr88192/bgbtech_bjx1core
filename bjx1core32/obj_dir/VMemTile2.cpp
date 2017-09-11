// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMemTile2.h for the primary calling header

#include "VMemTile2.h"         // For This
#include "VMemTile2__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMemTile2) {
    VMemTile2__Syms* __restrict vlSymsp = __VlSymsp = new VMemTile2__Syms(this, name());
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMemTile2::__Vconfigure(VMemTile2__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMemTile2::~VMemTile2() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VMemTile2::eval() {
    VMemTile2__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VMemTile2::eval\n"); );
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

void VMemTile2::_eval_initial_loop(VMemTile2__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void VMemTile2::_sequent__TOP__1(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_sequent__TOP__1\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__iTileBase__v0,6,0);
    VL_SIG8(__Vdlyvset__MemTile2__DOT__iTileBase__v0,0,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__dTileBase__v0,6,0);
    VL_SIG8(__Vdlyvset__MemTile2__DOT__dTile__v0,0,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v0,6,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v1,6,0);
    VL_SIG8(__Vdlyvset__MemTile2__DOT__iTile__v0,0,0);
    VL_SIG8(__Vdlyvset__MemTile2__DOT__dTile__v3,0,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__iTileBase__v1,6,0);
    VL_SIG8(__Vdlyvset__MemTile2__DOT__iTileBase__v1,0,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__iTileBaseHi__v0,6,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__dTileBase__v1,6,0);
    VL_SIG8(__Vdlyvset__MemTile2__DOT__dTileBase__v1,0,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__dTileBaseHi__v0,6,0);
    VL_SIG8(__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v2,6,0);
    VL_SIG8(__Vdly__MemTile2__DOT__ldTileAct,0,0);
    VL_SIG8(__Vdly__MemTile2__DOT__ldTileStAct,0,0);
    VL_SIG8(__Vdly__MemTile2__DOT__ldTileDn,0,0);
    VL_SIG16(__Vdlyvdim0__MemTile2__DOT__dTile__v0,10,0);
    VL_SIG16(__Vdlyvdim0__MemTile2__DOT__dTile__v1,10,0);
    VL_SIG16(__Vdlyvdim0__MemTile2__DOT__dTile__v2,10,0);
    VL_SIG16(__Vdlyvdim0__MemTile2__DOT__iTile__v0,10,0);
    VL_SIG16(__Vdlyvdim0__MemTile2__DOT__dTile__v3,10,0);
    VL_SIG16(__Vdlyvval__MemTile2__DOT__iTileBaseHi__v0,9,0);
    VL_SIG16(__Vdlyvval__MemTile2__DOT__dTileBaseHi__v0,9,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__dTile__v0,31,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__dTile__v1,31,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__dTile__v2,31,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__iTile__v0,31,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__dTile__v3,31,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__iTileBase__v1,31,0);
    VL_SIG(__Vdlyvval__MemTile2__DOT__dTileBase__v1,31,0);
    // Body
    __Vdlyvset__MemTile2__DOT__iTile__v0 = 0U;
    __Vdly__MemTile2__DOT__ldTileStAct = vlTOPp->MemTile2__DOT__ldTileStAct;
    __Vdly__MemTile2__DOT__ldTileDn = vlTOPp->MemTile2__DOT__ldTileDn;
    __Vdly__MemTile2__DOT__ldTileAct = vlTOPp->MemTile2__DOT__ldTileAct;
    __Vdlyvset__MemTile2__DOT__dTileBase__v1 = 0U;
    __Vdlyvset__MemTile2__DOT__iTileBase__v1 = 0U;
    __Vdlyvset__MemTile2__DOT__iTileBase__v0 = 0U;
    __Vdlyvset__MemTile2__DOT__dTile__v3 = 0U;
    __Vdlyvset__MemTile2__DOT__dTile__v0 = 0U;
    // ALWAYS at MemTile2.v:426
    if (vlTOPp->MemTile2__DOT__resetAct) {
	__Vdlyvset__MemTile2__DOT__iTileBase__v0 = 1U;
	__Vdlyvdim0__MemTile2__DOT__iTileBase__v0 = vlTOPp->MemTile2__DOT__resetCurTile;
	__Vdlyvdim0__MemTile2__DOT__dTileBase__v0 = vlTOPp->MemTile2__DOT__resetCurTile;
	vlTOPp->MemTile2__DOT__resetTOK = 0x1234U;
    } else {
	vlTOPp->MemTile2__DOT__ldTileWIdx = vlTOPp->MemTile2__DOT__ldTileNextWIdx;
	vlTOPp->MemTile2__DOT__ldTileDlyAct = vlTOPp->MemTile2__DOT__ldTileNextDlyAct;
	vlTOPp->MemTile2__DOT__ldTileExtOE = vlTOPp->MemTile2__DOT__ldTileNextExtOE;
	vlTOPp->MemTile2__DOT__ldTileExtWR = vlTOPp->MemTile2__DOT__ldTileNextExtWR;
	vlTOPp->MemTile2__DOT__reqSyncTile = vlTOPp->MemTile2__DOT__reqNextSyncTile;
	vlTOPp->MemTile2__DOT__reqSyncTileIdx = vlTOPp->MemTile2__DOT__reqNextSyncTileIdx;
	vlTOPp->MemTile2__DOT__ldTileLastAct = vlTOPp->MemTile2__DOT__ldTileNextLastAct;
	if (VL_UNLIKELY(((IData)(vlTOPp->MemTile2__DOT__dTileOpWrOK) 
			 & ((~ (IData)(vlTOPp->MemTile2__DOT__ldTileAct)) 
			    | (IData)(vlTOPp->MemTile2__DOT__ldTileDn))))) {
	    VL_WRITEF("Posedge Write CA=%03x CB=%04x BH=%08x BL=%08x\n",
		      11,vlTOPp->MemTile2__DOT__dTileIdx,
		      32,((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
			  << 2U),32,vlTOPp->MemTile2__DOT__rdtTBlock2[1U],
		      32,vlTOPp->MemTile2__DOT__rdtTBlock2[0U]);
	    __Vdlyvval__MemTile2__DOT__dTile__v0 = 
		vlTOPp->MemTile2__DOT__rdtTBlock2[0U];
	    __Vdlyvset__MemTile2__DOT__dTile__v0 = 1U;
	    __Vdlyvdim0__MemTile2__DOT__dTile__v0 = vlTOPp->MemTile2__DOT__dTileIdx;
	    __Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v0 
		= (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
			    >> 4U));
	    __Vdlyvval__MemTile2__DOT__dTile__v1 = 
		vlTOPp->MemTile2__DOT__rdtTBlock2[1U];
	    __Vdlyvdim0__MemTile2__DOT__dTile__v1 = 
		(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__dTileIdx)));
	    __Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v1 
		= (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
			    >> 4U));
	    __Vdlyvval__MemTile2__DOT__dTile__v2 = 
		vlTOPp->MemTile2__DOT__rdtTBlock2[2U];
	    __Vdlyvdim0__MemTile2__DOT__dTile__v2 = 
		(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->MemTile2__DOT__dTileIdx)));
	}
	if ((((IData)(vlTOPp->MemTile2__DOT__ldTileAct) 
	      & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileDn))) 
	     & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileStAct)))) {
	    if (vlTOPp->MemTile2__DOT__reqLdITile) {
		__Vdlyvval__MemTile2__DOT__iTile__v0 
		    = vlTOPp->extData;
		__Vdlyvset__MemTile2__DOT__iTile__v0 = 1U;
		__Vdlyvdim0__MemTile2__DOT__iTile__v0 
		    = vlTOPp->MemTile2__DOT__ldTileIdx;
	    } else {
		__Vdlyvval__MemTile2__DOT__dTile__v3 
		    = vlTOPp->extData;
		__Vdlyvset__MemTile2__DOT__dTile__v3 = 1U;
		__Vdlyvdim0__MemTile2__DOT__dTile__v3 
		    = vlTOPp->MemTile2__DOT__ldTileIdx;
	    }
	}
	if (vlTOPp->MemTile2__DOT__ldTileDn) {
	    if (vlTOPp->MemTile2__DOT__reqLdITile) {
		__Vdlyvval__MemTile2__DOT__iTileBase__v1 
		    = vlTOPp->MemTile2__DOT__reqLdTileBaseLo;
		__Vdlyvset__MemTile2__DOT__iTileBase__v1 = 1U;
		__Vdlyvdim0__MemTile2__DOT__iTileBase__v1 
		    = vlTOPp->MemTile2__DOT__reqLdTileIdx;
		__Vdlyvval__MemTile2__DOT__iTileBaseHi__v0 
		    = vlTOPp->MemTile2__DOT__reqLdTileBaseHi;
		__Vdlyvdim0__MemTile2__DOT__iTileBaseHi__v0 
		    = vlTOPp->MemTile2__DOT__reqLdTileIdx;
	    } else {
		__Vdlyvval__MemTile2__DOT__dTileBase__v1 
		    = vlTOPp->MemTile2__DOT__reqLdTileBaseLo;
		__Vdlyvset__MemTile2__DOT__dTileBase__v1 = 1U;
		__Vdlyvdim0__MemTile2__DOT__dTileBase__v1 
		    = vlTOPp->MemTile2__DOT__reqLdTileIdx;
		__Vdlyvval__MemTile2__DOT__dTileBaseHi__v0 
		    = vlTOPp->MemTile2__DOT__reqLdTileBaseHi;
		__Vdlyvdim0__MemTile2__DOT__dTileBaseHi__v0 
		    = vlTOPp->MemTile2__DOT__reqLdTileIdx;
		__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v2 
		    = vlTOPp->MemTile2__DOT__reqLdTileIdx;
	    }
	}
	__Vdly__MemTile2__DOT__ldTileAct = vlTOPp->MemTile2__DOT__ldTileNextAct;
	__Vdly__MemTile2__DOT__ldTileStAct = vlTOPp->MemTile2__DOT__ldTileNextStAct;
	__Vdly__MemTile2__DOT__ldTileDn = vlTOPp->MemTile2__DOT__ldTileNextDn;
    }
    // ALWAYSPOST at MemTile2.v:492
    if (__Vdlyvset__MemTile2__DOT__iTileBase__v1) {
	vlTOPp->MemTile2__DOT__iTileBaseHi[__Vdlyvdim0__MemTile2__DOT__iTileBaseHi__v0] 
	    = __Vdlyvval__MemTile2__DOT__iTileBaseHi__v0;
    }
    // ALWAYSPOST at MemTile2.v:479
    if (__Vdlyvset__MemTile2__DOT__iTile__v0) {
	vlTOPp->MemTile2__DOT__iTile[__Vdlyvdim0__MemTile2__DOT__iTile__v0] 
	    = __Vdlyvval__MemTile2__DOT__iTile__v0;
    }
    vlTOPp->MemTile2__DOT__ldTileDn = __Vdly__MemTile2__DOT__ldTileDn;
    vlTOPp->MemTile2__DOT__ldTileStAct = __Vdly__MemTile2__DOT__ldTileStAct;
    vlTOPp->MemTile2__DOT__ldTileAct = __Vdly__MemTile2__DOT__ldTileAct;
    // ALWAYSPOST at MemTile2.v:428
    if (__Vdlyvset__MemTile2__DOT__iTileBase__v0) {
	vlTOPp->MemTile2__DOT__iTileBase[__Vdlyvdim0__MemTile2__DOT__iTileBase__v0] = 0xffffffffU;
    }
    if (__Vdlyvset__MemTile2__DOT__iTileBase__v1) {
	vlTOPp->MemTile2__DOT__iTileBase[__Vdlyvdim0__MemTile2__DOT__iTileBase__v1] 
	    = __Vdlyvval__MemTile2__DOT__iTileBase__v1;
    }
    // ALWAYSPOST at MemTile2.v:458
    if (__Vdlyvset__MemTile2__DOT__dTile__v0) {
	vlTOPp->MemTile2__DOT__dTileBaseDty[__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v0] = 1U;
	vlTOPp->MemTile2__DOT__dTileBaseDty[__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v1] = 1U;
    }
    if (__Vdlyvset__MemTile2__DOT__dTileBase__v1) {
	vlTOPp->MemTile2__DOT__dTileBaseDty[__Vdlyvdim0__MemTile2__DOT__dTileBaseDty__v2] = 0U;
    }
    // ALWAYSPOST at MemTile2.v:497
    if (__Vdlyvset__MemTile2__DOT__dTileBase__v1) {
	vlTOPp->MemTile2__DOT__dTileBaseHi[__Vdlyvdim0__MemTile2__DOT__dTileBaseHi__v0] 
	    = __Vdlyvval__MemTile2__DOT__dTileBaseHi__v0;
    }
    // ALWAYSPOST at MemTile2.v:429
    if (__Vdlyvset__MemTile2__DOT__iTileBase__v0) {
	vlTOPp->MemTile2__DOT__dTileBase[__Vdlyvdim0__MemTile2__DOT__dTileBase__v0] = 0xffffffffU;
    }
    if (__Vdlyvset__MemTile2__DOT__dTileBase__v1) {
	vlTOPp->MemTile2__DOT__dTileBase[__Vdlyvdim0__MemTile2__DOT__dTileBase__v1] 
	    = __Vdlyvval__MemTile2__DOT__dTileBase__v1;
    }
    // ALWAYSPOST at MemTile2.v:454
    if (__Vdlyvset__MemTile2__DOT__dTile__v0) {
	vlTOPp->MemTile2__DOT__dTile[__Vdlyvdim0__MemTile2__DOT__dTile__v0] 
	    = __Vdlyvval__MemTile2__DOT__dTile__v0;
	vlTOPp->MemTile2__DOT__dTile[__Vdlyvdim0__MemTile2__DOT__dTile__v1] 
	    = __Vdlyvval__MemTile2__DOT__dTile__v1;
	vlTOPp->MemTile2__DOT__dTile[__Vdlyvdim0__MemTile2__DOT__dTile__v2] 
	    = __Vdlyvval__MemTile2__DOT__dTile__v2;
    }
    if (__Vdlyvset__MemTile2__DOT__dTile__v3) {
	vlTOPp->MemTile2__DOT__dTile[__Vdlyvdim0__MemTile2__DOT__dTile__v3] 
	    = __Vdlyvval__MemTile2__DOT__dTile__v3;
    }
    vlTOPp->extOE = vlTOPp->MemTile2__DOT__ldTileExtOE;
    vlTOPp->extWR = vlTOPp->MemTile2__DOT__ldTileExtWR;
    // ALWAYS at MemTile2.v:424
    vlTOPp->MemTile2__DOT__resetCurTile = vlTOPp->MemTile2__DOT__resetNextTile;
    // ALWAYS at MemTile2.v:423
    vlTOPp->MemTile2__DOT__resetAct = vlTOPp->MemTile2__DOT__resetNextAct;
    // ALWAYS at MemTile2.v:290
    vlTOPp->MemTile2__DOT__ldTileNextDlyAct = vlTOPp->MemTile2__DOT__ldTileAct;
    // ALWAYS at MemTile2.v:291
    vlTOPp->MemTile2__DOT__ldTileNextLastAct = vlTOPp->MemTile2__DOT__ldTileDlyAct;
}

void VMemTile2::_settle__TOP__2(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_settle__TOP__2\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->extOE = vlTOPp->MemTile2__DOT__ldTileExtOE;
    vlTOPp->extWR = vlTOPp->MemTile2__DOT__ldTileExtWR;
    // ALWAYS at MemTile2.v:290
    vlTOPp->MemTile2__DOT__ldTileNextDlyAct = vlTOPp->MemTile2__DOT__ldTileAct;
    // ALWAYS at MemTile2.v:291
    vlTOPp->MemTile2__DOT__ldTileNextLastAct = vlTOPp->MemTile2__DOT__ldTileDlyAct;
    // ALWAYS at MemTile2.v:131
    vlTOPp->MemTile2__DOT__dTileMiss = 0U;
    vlTOPp->MemTile2__DOT__iTileMiss = 0U;
    vlTOPp->MemTile2__DOT__dTileMiss2 = 0U;
    vlTOPp->MemTile2__DOT__iTileMiss2 = 0U;
    vlTOPp->MemTile2__DOT__reqLdTile = 0U;
    vlTOPp->MemTile2__DOT__reqStTile = 0U;
    vlTOPp->MemTile2__DOT__reqNextSyncTile = 0U;
    vlTOPp->MemTile2__DOT__reqNextSyncTileIdx = 0U;
    if (((IData)(vlTOPp->opRd) | (IData)(vlTOPp->opWr))) {
	vlTOPp->MemTile2__DOT__dMemAddr = (VL_ULL(0xffffffffffff) 
					   & vlTOPp->memAddr);
	vlTOPp->MemTile2__DOT__dMemAddrLim = (VL_ULL(0xffffffffffff) 
					      & (VL_ULL(0xf) 
						 + vlTOPp->MemTile2__DOT__dMemAddr));
	vlTOPp->MemTile2__DOT__dTileIdx = (0x7ffU & (IData)(
							    (vlTOPp->MemTile2__DOT__dMemAddr 
							     >> 2U)));
	vlTOPp->MemTile2__DOT__dTileLimIdx = (0x7ffU 
					      & (IData)(
							(vlTOPp->MemTile2__DOT__dMemAddrLim 
							 >> 2U)));
	vlTOPp->MemTile2__DOT__dTileMiss = (vlTOPp->MemTile2__DOT__dTileBase
					    [(0x7fU 
					      & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
						 >> 4U))] 
					    != (IData)(
						       (vlTOPp->MemTile2__DOT__dMemAddr 
							>> 6U)));
	vlTOPp->MemTile2__DOT__dTileMiss2 = (vlTOPp->MemTile2__DOT__dTileBase
					     [(0x7fU 
					       & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
						  >> 4U))] 
					     != (IData)(
							(vlTOPp->MemTile2__DOT__dMemAddrLim 
							 >> 6U)));
	if (((((IData)(vlTOPp->opRd) & (IData)((vlTOPp->memAddr 
						>> 0x3cU))) 
	      & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileDlyAct))) 
	     & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileLastAct)))) {
	    vlTOPp->MemTile2__DOT__dTileMiss = 1U;
	}
	vlTOPp->MemTile2__DOT__rdtShl = ((7U & (IData)(vlTOPp->MemTile2__DOT__rdtShl)) 
					 | (0x18U & 
					    ((IData)(vlTOPp->memAddr) 
					     << 3U)));
	vlTOPp->MemTile2__DOT__rdtShl = (0x18U & (IData)(vlTOPp->MemTile2__DOT__rdtShl));
	vlTOPp->MemTile2__DOT__rdtTBlock[0U] = vlTOPp->MemTile2__DOT__dTile
	    [vlTOPp->MemTile2__DOT__dTileIdx];
	vlTOPp->MemTile2__DOT__rdtTBlock[1U] = vlTOPp->MemTile2__DOT__dTile
	    [(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__dTileIdx)))];
	vlTOPp->MemTile2__DOT__rdtTBlock[2U] = vlTOPp->MemTile2__DOT__dTile
	    [(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->MemTile2__DOT__dTileIdx)))];
	if (vlTOPp->MemTile2__DOT__dTileMiss) {
	    vlTOPp->MemTile2__DOT__reqLdTile = 1U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		= (IData)((vlTOPp->MemTile2__DOT__dMemAddr 
			   >> 6U));
	    vlTOPp->MemTile2__DOT__reqLdTileIdx = (0x7fU 
						   & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
						      >> 4U));
	    vlTOPp->MemTile2__DOT__reqLdITile = 0U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		= (0x3ffU & (IData)((vlTOPp->MemTile2__DOT__dMemAddr 
				     >> 0x26U)));
	    vlTOPp->MemTile2__DOT__reqLdSTile = vlTOPp->MemTile2__DOT__dTileBaseDty
		[(0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
			   >> 4U))];
	} else {
	    if (vlTOPp->MemTile2__DOT__dTileMiss2) {
		vlTOPp->MemTile2__DOT__reqLdTile = 1U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		    = (IData)((vlTOPp->MemTile2__DOT__dMemAddrLim 
			       >> 6U));
		vlTOPp->MemTile2__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
				>> 4U));
		vlTOPp->MemTile2__DOT__reqLdITile = 0U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		    = (0x3ffU & (IData)((vlTOPp->MemTile2__DOT__dMemAddrLim 
					 >> 0x26U)));
		vlTOPp->MemTile2__DOT__reqLdSTile = 
		    vlTOPp->MemTile2__DOT__dTileBaseDty
		    [(0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
			       >> 4U))];
	    }
	}
	if ((1U & ((~ (IData)(vlTOPp->MemTile2__DOT__dTileMiss)) 
		   & (~ (IData)(vlTOPp->MemTile2__DOT__dTileMiss2))))) {
	    if (vlTOPp->MemTile2__DOT__reqSyncTile) {
		vlTOPp->MemTile2__DOT__reqStTile = 1U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		    = vlTOPp->MemTile2__DOT__dTileBase
		    [vlTOPp->MemTile2__DOT__reqSyncTileIdx];
		vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		    = vlTOPp->MemTile2__DOT__dTileBaseHi
		    [vlTOPp->MemTile2__DOT__reqSyncTileIdx];
		vlTOPp->MemTile2__DOT__reqLdTileIdx 
		    = vlTOPp->MemTile2__DOT__reqSyncTileIdx;
		vlTOPp->MemTile2__DOT__reqLdITile = 0U;
	    }
	    if (((IData)(vlTOPp->opWr) & ((1U & (IData)(
							(vlTOPp->memAddr 
							 >> 0x3cU))) 
					  != (1U & (IData)(
							   (vlTOPp->memAddr 
							    >> 0x3fU)))))) {
		vlTOPp->MemTile2__DOT__reqNextSyncTile = 1U;
		vlTOPp->MemTile2__DOT__reqNextSyncTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
				>> 4U));
	    }
	}
    }
    if (vlTOPp->iopRd) {
	vlTOPp->MemTile2__DOT__iMemAddr = vlTOPp->imemAddr;
	vlTOPp->MemTile2__DOT__iMemAddrLim = (VL_ULL(0xffffffffffff) 
					      & (VL_ULL(7) 
						 + vlTOPp->MemTile2__DOT__iMemAddr));
	vlTOPp->MemTile2__DOT__iTileIdx = (0x7ffU & (IData)(
							    (vlTOPp->MemTile2__DOT__iMemAddr 
							     >> 2U)));
	vlTOPp->MemTile2__DOT__iTileLimIdx = (0x7ffU 
					      & (IData)(
							(vlTOPp->MemTile2__DOT__iMemAddrLim 
							 >> 2U)));
	vlTOPp->MemTile2__DOT__iTileMiss = (vlTOPp->MemTile2__DOT__iTileBase
					    [(0x7fU 
					      & ((IData)(vlTOPp->MemTile2__DOT__iTileIdx) 
						 >> 4U))] 
					    != (IData)(
						       (vlTOPp->MemTile2__DOT__iMemAddr 
							>> 6U)));
	vlTOPp->MemTile2__DOT__iTileMiss2 = (vlTOPp->MemTile2__DOT__iTileBase
					     [(0x7fU 
					       & ((IData)(vlTOPp->MemTile2__DOT__iTileLimIdx) 
						  >> 4U))] 
					     != (IData)(
							(vlTOPp->MemTile2__DOT__iMemAddrLim 
							 >> 6U)));
	vlTOPp->MemTile2__DOT__irdtShl = ((7U & (IData)(vlTOPp->MemTile2__DOT__irdtShl)) 
					  | (0x18U 
					     & ((IData)(vlTOPp->imemAddr) 
						<< 3U)));
	vlTOPp->MemTile2__DOT__irdtShl = (0x18U & (IData)(vlTOPp->MemTile2__DOT__irdtShl));
	if (vlTOPp->MemTile2__DOT__iTileMiss) {
	    vlTOPp->MemTile2__DOT__reqLdTile = 1U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		= (IData)((vlTOPp->imemAddr >> 6U));
	    vlTOPp->MemTile2__DOT__reqLdTileIdx = (0x7fU 
						   & ((IData)(vlTOPp->MemTile2__DOT__iTileIdx) 
						      >> 4U));
	    vlTOPp->MemTile2__DOT__reqLdITile = 1U;
	    vlTOPp->MemTile2__DOT__reqLdSTile = 0U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		= (0x3ffU & (IData)((vlTOPp->imemAddr 
				     >> 0x26U)));
	} else {
	    if (vlTOPp->MemTile2__DOT__iTileMiss2) {
		vlTOPp->MemTile2__DOT__reqLdTile = 1U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		    = (IData)((vlTOPp->MemTile2__DOT__iMemAddrLim 
			       >> 6U));
		vlTOPp->MemTile2__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__iTileLimIdx) 
				>> 4U));
		vlTOPp->MemTile2__DOT__reqLdITile = 1U;
		vlTOPp->MemTile2__DOT__reqLdSTile = 0U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		    = (0x3ffU & (IData)((vlTOPp->MemTile2__DOT__iMemAddrLim 
					 >> 0x26U)));
	    }
	}
    }
    // ALWAYS at MemTile2.v:405
    if (vlTOPp->MemTile2__DOT__resetAct) {
	vlTOPp->MemTile2__DOT__resetNextTile = (0x7fU 
						& ((IData)(1U) 
						   + (IData)(vlTOPp->MemTile2__DOT__resetCurTile)));
	if ((0U == (IData)(vlTOPp->MemTile2__DOT__resetNextTile))) {
	    vlTOPp->MemTile2__DOT__resetNextAct = 0U;
	}
    } else {
	if (((IData)(vlTOPp->reset) | (0x1234U != (IData)(vlTOPp->MemTile2__DOT__resetTOK)))) {
	    vlTOPp->MemTile2__DOT__resetNextAct = 1U;
	    vlTOPp->MemTile2__DOT__resetNextTile = 0U;
	}
    }
}

VL_INLINE_OPT void VMemTile2::_combo__TOP__3(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_combo__TOP__3\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,95,0,3);
    //char	__VpadToAlign116[4];
    VL_SIGW(__Vtemp2,95,0,3);
    // Body
    // ALWAYS at MemTile2.v:131
    vlTOPp->MemTile2__DOT__dTileMiss = 0U;
    vlTOPp->MemTile2__DOT__iTileMiss = 0U;
    vlTOPp->MemTile2__DOT__dTileMiss2 = 0U;
    vlTOPp->MemTile2__DOT__iTileMiss2 = 0U;
    vlTOPp->MemTile2__DOT__reqLdTile = 0U;
    vlTOPp->MemTile2__DOT__reqStTile = 0U;
    vlTOPp->MemTile2__DOT__reqNextSyncTile = 0U;
    vlTOPp->MemTile2__DOT__reqNextSyncTileIdx = 0U;
    if (((IData)(vlTOPp->opRd) | (IData)(vlTOPp->opWr))) {
	vlTOPp->MemTile2__DOT__dMemAddr = (VL_ULL(0xffffffffffff) 
					   & vlTOPp->memAddr);
	vlTOPp->MemTile2__DOT__dMemAddrLim = (VL_ULL(0xffffffffffff) 
					      & (VL_ULL(0xf) 
						 + vlTOPp->MemTile2__DOT__dMemAddr));
	vlTOPp->MemTile2__DOT__dTileIdx = (0x7ffU & (IData)(
							    (vlTOPp->MemTile2__DOT__dMemAddr 
							     >> 2U)));
	vlTOPp->MemTile2__DOT__dTileLimIdx = (0x7ffU 
					      & (IData)(
							(vlTOPp->MemTile2__DOT__dMemAddrLim 
							 >> 2U)));
	vlTOPp->MemTile2__DOT__dTileMiss = (vlTOPp->MemTile2__DOT__dTileBase
					    [(0x7fU 
					      & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
						 >> 4U))] 
					    != (IData)(
						       (vlTOPp->MemTile2__DOT__dMemAddr 
							>> 6U)));
	vlTOPp->MemTile2__DOT__dTileMiss2 = (vlTOPp->MemTile2__DOT__dTileBase
					     [(0x7fU 
					       & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
						  >> 4U))] 
					     != (IData)(
							(vlTOPp->MemTile2__DOT__dMemAddrLim 
							 >> 6U)));
	if (((((IData)(vlTOPp->opRd) & (IData)((vlTOPp->memAddr 
						>> 0x3cU))) 
	      & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileDlyAct))) 
	     & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileLastAct)))) {
	    vlTOPp->MemTile2__DOT__dTileMiss = 1U;
	}
	vlTOPp->MemTile2__DOT__rdtShl = ((7U & (IData)(vlTOPp->MemTile2__DOT__rdtShl)) 
					 | (0x18U & 
					    ((IData)(vlTOPp->memAddr) 
					     << 3U)));
	vlTOPp->MemTile2__DOT__rdtShl = (0x18U & (IData)(vlTOPp->MemTile2__DOT__rdtShl));
	vlTOPp->MemTile2__DOT__rdtTBlock[0U] = vlTOPp->MemTile2__DOT__dTile
	    [vlTOPp->MemTile2__DOT__dTileIdx];
	vlTOPp->MemTile2__DOT__rdtTBlock[1U] = vlTOPp->MemTile2__DOT__dTile
	    [(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__dTileIdx)))];
	vlTOPp->MemTile2__DOT__rdtTBlock[2U] = vlTOPp->MemTile2__DOT__dTile
	    [(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->MemTile2__DOT__dTileIdx)))];
	if (vlTOPp->MemTile2__DOT__dTileMiss) {
	    vlTOPp->MemTile2__DOT__reqLdTile = 1U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		= (IData)((vlTOPp->MemTile2__DOT__dMemAddr 
			   >> 6U));
	    vlTOPp->MemTile2__DOT__reqLdTileIdx = (0x7fU 
						   & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
						      >> 4U));
	    vlTOPp->MemTile2__DOT__reqLdITile = 0U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		= (0x3ffU & (IData)((vlTOPp->MemTile2__DOT__dMemAddr 
				     >> 0x26U)));
	    vlTOPp->MemTile2__DOT__reqLdSTile = vlTOPp->MemTile2__DOT__dTileBaseDty
		[(0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
			   >> 4U))];
	} else {
	    if (vlTOPp->MemTile2__DOT__dTileMiss2) {
		vlTOPp->MemTile2__DOT__reqLdTile = 1U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		    = (IData)((vlTOPp->MemTile2__DOT__dMemAddrLim 
			       >> 6U));
		vlTOPp->MemTile2__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
				>> 4U));
		vlTOPp->MemTile2__DOT__reqLdITile = 0U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		    = (0x3ffU & (IData)((vlTOPp->MemTile2__DOT__dMemAddrLim 
					 >> 0x26U)));
		vlTOPp->MemTile2__DOT__reqLdSTile = 
		    vlTOPp->MemTile2__DOT__dTileBaseDty
		    [(0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileLimIdx) 
			       >> 4U))];
	    }
	}
	if ((1U & ((~ (IData)(vlTOPp->MemTile2__DOT__dTileMiss)) 
		   & (~ (IData)(vlTOPp->MemTile2__DOT__dTileMiss2))))) {
	    if (vlTOPp->MemTile2__DOT__reqSyncTile) {
		vlTOPp->MemTile2__DOT__reqStTile = 1U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		    = vlTOPp->MemTile2__DOT__dTileBase
		    [vlTOPp->MemTile2__DOT__reqSyncTileIdx];
		vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		    = vlTOPp->MemTile2__DOT__dTileBaseHi
		    [vlTOPp->MemTile2__DOT__reqSyncTileIdx];
		vlTOPp->MemTile2__DOT__reqLdTileIdx 
		    = vlTOPp->MemTile2__DOT__reqSyncTileIdx;
		vlTOPp->MemTile2__DOT__reqLdITile = 0U;
	    }
	    if (((IData)(vlTOPp->opWr) & ((1U & (IData)(
							(vlTOPp->memAddr 
							 >> 0x3cU))) 
					  != (1U & (IData)(
							   (vlTOPp->memAddr 
							    >> 0x3fU)))))) {
		vlTOPp->MemTile2__DOT__reqNextSyncTile = 1U;
		vlTOPp->MemTile2__DOT__reqNextSyncTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__dTileIdx) 
				>> 4U));
	    }
	}
    }
    if (vlTOPp->iopRd) {
	vlTOPp->MemTile2__DOT__iMemAddr = vlTOPp->imemAddr;
	vlTOPp->MemTile2__DOT__iMemAddrLim = (VL_ULL(0xffffffffffff) 
					      & (VL_ULL(7) 
						 + vlTOPp->MemTile2__DOT__iMemAddr));
	vlTOPp->MemTile2__DOT__iTileIdx = (0x7ffU & (IData)(
							    (vlTOPp->MemTile2__DOT__iMemAddr 
							     >> 2U)));
	vlTOPp->MemTile2__DOT__iTileLimIdx = (0x7ffU 
					      & (IData)(
							(vlTOPp->MemTile2__DOT__iMemAddrLim 
							 >> 2U)));
	vlTOPp->MemTile2__DOT__iTileMiss = (vlTOPp->MemTile2__DOT__iTileBase
					    [(0x7fU 
					      & ((IData)(vlTOPp->MemTile2__DOT__iTileIdx) 
						 >> 4U))] 
					    != (IData)(
						       (vlTOPp->MemTile2__DOT__iMemAddr 
							>> 6U)));
	vlTOPp->MemTile2__DOT__iTileMiss2 = (vlTOPp->MemTile2__DOT__iTileBase
					     [(0x7fU 
					       & ((IData)(vlTOPp->MemTile2__DOT__iTileLimIdx) 
						  >> 4U))] 
					     != (IData)(
							(vlTOPp->MemTile2__DOT__iMemAddrLim 
							 >> 6U)));
	vlTOPp->MemTile2__DOT__irdtShl = ((7U & (IData)(vlTOPp->MemTile2__DOT__irdtShl)) 
					  | (0x18U 
					     & ((IData)(vlTOPp->imemAddr) 
						<< 3U)));
	vlTOPp->MemTile2__DOT__irdtShl = (0x18U & (IData)(vlTOPp->MemTile2__DOT__irdtShl));
	if (vlTOPp->MemTile2__DOT__iTileMiss) {
	    vlTOPp->MemTile2__DOT__reqLdTile = 1U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		= (IData)((vlTOPp->imemAddr >> 6U));
	    vlTOPp->MemTile2__DOT__reqLdTileIdx = (0x7fU 
						   & ((IData)(vlTOPp->MemTile2__DOT__iTileIdx) 
						      >> 4U));
	    vlTOPp->MemTile2__DOT__reqLdITile = 1U;
	    vlTOPp->MemTile2__DOT__reqLdSTile = 0U;
	    vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		= (0x3ffU & (IData)((vlTOPp->imemAddr 
				     >> 0x26U)));
	} else {
	    if (vlTOPp->MemTile2__DOT__iTileMiss2) {
		vlTOPp->MemTile2__DOT__reqLdTile = 1U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseLo 
		    = (IData)((vlTOPp->MemTile2__DOT__iMemAddrLim 
			       >> 6U));
		vlTOPp->MemTile2__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->MemTile2__DOT__iTileLimIdx) 
				>> 4U));
		vlTOPp->MemTile2__DOT__reqLdITile = 1U;
		vlTOPp->MemTile2__DOT__reqLdSTile = 0U;
		vlTOPp->MemTile2__DOT__reqLdTileBaseHi 
		    = (0x3ffU & (IData)((vlTOPp->MemTile2__DOT__iMemAddrLim 
					 >> 0x26U)));
	    }
	}
    }
    // ALWAYS at MemTile2.v:405
    if (vlTOPp->MemTile2__DOT__resetAct) {
	vlTOPp->MemTile2__DOT__resetNextTile = (0x7fU 
						& ((IData)(1U) 
						   + (IData)(vlTOPp->MemTile2__DOT__resetCurTile)));
	if ((0U == (IData)(vlTOPp->MemTile2__DOT__resetNextTile))) {
	    vlTOPp->MemTile2__DOT__resetNextAct = 0U;
	}
    } else {
	if (((IData)(vlTOPp->reset) | (0x1234U != (IData)(vlTOPp->MemTile2__DOT__resetTOK)))) {
	    vlTOPp->MemTile2__DOT__resetNextAct = 1U;
	    vlTOPp->MemTile2__DOT__resetNextTile = 0U;
	}
    }
    // ALWAYS at MemTile2.v:504
    if (vlTOPp->opRd) {
	VL_SHIFTR_WWI(96,96,5, __Vtemp1, vlTOPp->MemTile2__DOT__rdtTBlock, (IData)(vlTOPp->MemTile2__DOT__rdtShl));
	vlTOPp->MemTile2__DOT__rdtValue[0U] = __Vtemp1[0U];
	vlTOPp->MemTile2__DOT__rdtValue[1U] = __Vtemp1[1U];
	vlTOPp->MemTile2__DOT__rdtValue[2U] = __Vtemp1[2U];
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= (VL_ULL(0xffff) & vlTOPp->MemTile2__DOT__tDrdValue);
		} else {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= (VL_ULL(0xff) & vlTOPp->MemTile2__DOT__tDrdValue);
		}
	    } else {
		vlTOPp->MemTile2__DOT__tDrdValue = 
		    ((1U & (IData)(vlTOPp->opMode))
		      ? (((QData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[1U])) 
			  << 0x20U) | (QData)((IData)(
						      vlTOPp->MemTile2__DOT__rdtValue[0U])))
		      : (((QData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[1U])) 
			  << 0x20U) | (QData)((IData)(
						      vlTOPp->MemTile2__DOT__rdtValue[0U]))));
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff00000000) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[0U])));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff) & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | ((QData)((IData)(((0x80000000U 
						& vlTOPp->MemTile2__DOT__rdtValue[0U])
					        ? 0xffffffffU
					        : 0U))) 
			      << 0x20U));
		} else {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffff) & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (((0x8000U & vlTOPp->MemTile2__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffff)
			        : VL_ULL(0)) << 0x10U));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xff) & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (((0x80U & vlTOPp->MemTile2__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffffff)
			        : VL_ULL(0)) << 8U));
		} else {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= (((QData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->MemTile2__DOT__rdtValue[0U])));
		}
	    }
	}
    }
    // ALWAYS at MemTile2.v:756
    if (vlTOPp->iopRd) {
	vlTOPp->MemTile2__DOT__irdtTBlock[0U] = vlTOPp->MemTile2__DOT__iTile
	    [vlTOPp->MemTile2__DOT__iTileIdx];
	vlTOPp->MemTile2__DOT__irdtTBlock[1U] = vlTOPp->MemTile2__DOT__iTile
	    [(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__iTileIdx)))];
	vlTOPp->MemTile2__DOT__irdtTBlock[2U] = vlTOPp->MemTile2__DOT__iTile
	    [(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->MemTile2__DOT__iTileIdx)))];
	VL_SHIFTR_WWI(96,96,5, __Vtemp2, vlTOPp->MemTile2__DOT__irdtTBlock, (IData)(vlTOPp->MemTile2__DOT__irdtShl));
	vlTOPp->MemTile2__DOT__irdtValue[0U] = __Vtemp2[0U];
	vlTOPp->MemTile2__DOT__irdtValue[1U] = __Vtemp2[1U];
	vlTOPp->MemTile2__DOT__irdtValue[2U] = __Vtemp2[2U];
	vlTOPp->MemTile2__DOT__tIrdValue = (((QData)((IData)(
							     vlTOPp->MemTile2__DOT__irdtValue[1U])) 
					     << 0x20U) 
					    | (QData)((IData)(
							      vlTOPp->MemTile2__DOT__irdtValue[0U])));
    }
    // ALWAYS at MemTile2.v:571
    vlTOPp->MemTile2__DOT__dTileOpWrOK = 0U;
    if ((((IData)(vlTOPp->opWr) & (~ (IData)(vlTOPp->MemTile2__DOT__reqLdTile))) 
	 & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileAct)))) {
	vlTOPp->MemTile2__DOT__rdtTBlock2[0U] = vlTOPp->MemTile2__DOT__rdtTBlock[0U];
	vlTOPp->MemTile2__DOT__rdtTBlock2[1U] = vlTOPp->MemTile2__DOT__rdtTBlock[1U];
	vlTOPp->MemTile2__DOT__rdtTBlock2[2U] = vlTOPp->MemTile2__DOT__rdtTBlock[2U];
	vlTOPp->MemTile2__DOT__dTileOpWrOK = 1U;
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((1U & (~ ((IData)(vlTOPp->opMode) >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->opMode)))) {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->wrValue);
			vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
			    = (IData)((vlTOPp->wrValue 
				       >> 0x20U));
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->wrValue) 
				       << 8U)));
			    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				= ((0xffU & ((IData)(vlTOPp->wrValue) 
					     >> 0x18U)) 
				   | (0xffffff00U & 
				      ((IData)((vlTOPp->wrValue 
						>> 0x20U)) 
				       << 8U)));
			    vlTOPp->MemTile2__DOT__rdtTBlock2[2U] 
				= ((0xffffff00U & vlTOPp->MemTile2__DOT__rdtTBlock2[2U]) 
				   | (0xffU & ((IData)(
						       (vlTOPp->wrValue 
							>> 0x20U)) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
				vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				    = ((0xffffU & ((IData)(vlTOPp->wrValue) 
						   >> 0x10U)) 
				       | (0xffff0000U 
					  & ((IData)(
						     (vlTOPp->wrValue 
						      >> 0x20U)) 
					     << 0x10U)));
				vlTOPp->MemTile2__DOT__rdtTBlock2[2U] 
				    = ((0xffff0000U 
					& vlTOPp->MemTile2__DOT__rdtTBlock2[2U]) 
				       | (0xffffU & 
					  ((IData)(
						   (vlTOPp->wrValue 
						    >> 0x20U)) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
					= ((0xffffffU 
					    & ((IData)(vlTOPp->wrValue) 
					       >> 8U)) 
					   | (0xff000000U 
					      & ((IData)(
							 (vlTOPp->wrValue 
							  >> 0x20U)) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[2U] 
					= ((0xff000000U 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[2U]) 
					   | (0xffffffU 
					      & ((IData)(
							 (vlTOPp->wrValue 
							  >> 0x20U)) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->wrValue);
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->wrValue) 
				       << 8U)));
			    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				= ((0xffffff00U & vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
				   | (0xffU & ((IData)(vlTOPp->wrValue) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
				vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				    = ((0xffff0000U 
					& vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
				       | (0xffffU & 
					  ((IData)(vlTOPp->wrValue) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
					= ((0xff000000U 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
					   | (0xffffffU 
					      & ((IData)(vlTOPp->wrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		} else {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = ((0xffff0000U & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
			       | (0xffffU & (IData)(vlTOPp->wrValue)));
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xff0000ffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xffff00U & ((IData)(vlTOPp->wrValue) 
						   << 8U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
					= ((0xffffff00U 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
					   | (0xffU 
					      & ((IData)(vlTOPp->wrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = ((0xffffff00U & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
			       | (0xffU & (IData)(vlTOPp->wrValue)));
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xffff00ffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xff00U & ((IData)(vlTOPp->wrValue) 
						 << 8U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xff00ffffU 
					& vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at MemTile2.v:293
    if ((((IData)(vlTOPp->MemTile2__DOT__reqLdTile) 
	  | (IData)(vlTOPp->MemTile2__DOT__reqStTile)) 
	 | (IData)(vlTOPp->MemTile2__DOT__ldTileAct))) {
	if (vlTOPp->MemTile2__DOT__ldTileAct) {
	    vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0xfU 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| ((IData)(vlTOPp->MemTile2__DOT__reqLdTileIdx) 
						   << 4U));
	    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0x7f0U 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| (IData)(vlTOPp->MemTile2__DOT__ldTileWIdx));
	    vlTOPp->MemTile2__DOT__ldTileNextStAct 
		= vlTOPp->MemTile2__DOT__ldTileStAct;
	    if (vlTOPp->MemTile2__DOT__ldTileStAct) {
		vlTOPp->MemTile2__DOT__extData__out__out0 
		    = vlTOPp->MemTile2__DOT__dTile[vlTOPp->MemTile2__DOT__ldTileIdx];
	    }
	    vlTOPp->MemTile2__DOT__ldTileExtAddr = 
		((VL_ULL(0xffffffffffc3) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		 | ((QData)((IData)(vlTOPp->MemTile2__DOT__ldTileWIdx)) 
		    << 2U));
	    if (vlTOPp->MemTile2__DOT__ldTileDn) {
		vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
		vlTOPp->MemTile2__DOT__ldTileNextAct = 0U;
	    }
	    if (vlTOPp->extNotReady) {
		vlTOPp->MemTile2__DOT__ldTileNextWIdx 
		    = vlTOPp->MemTile2__DOT__ldTileWIdx;
	    } else {
		vlTOPp->MemTile2__DOT__ldTileNextWIdx 
		    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__ldTileWIdx)));
		if ((0U == (IData)(vlTOPp->MemTile2__DOT__ldTileNextWIdx))) {
		    if (vlTOPp->MemTile2__DOT__ldTileStAct) {
			if (vlTOPp->MemTile2__DOT__reqLdTile) {
			    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextStAct = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtOE = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
			    vlTOPp->MemTile2__DOT__ldTileExtAddr 
				= ((VL_ULL(0x3fffffffff) 
				    & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
				   | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseHi)) 
				      << 0x26U));
			    vlTOPp->MemTile2__DOT__ldTileExtAddr 
				= ((VL_ULL(0xffc00000003f) 
				    & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
				   | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseLo)) 
				      << 6U));
			} else {
			    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextStAct = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextDn = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtOE = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
			}
		    } else {
			vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
			vlTOPp->MemTile2__DOT__ldTileNextDn = 1U;
			vlTOPp->MemTile2__DOT__ldTileNextExtOE = 0U;
			vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
		    }
		}
	    }
	} else {
	    vlTOPp->MemTile2__DOT__ldTileNextWIdx = 0U;
	    vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
	    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0xfU 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| ((IData)(vlTOPp->MemTile2__DOT__reqLdTileIdx) 
						   << 4U));
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0x7f0U 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| (IData)(vlTOPp->MemTile2__DOT__ldTileWIdx));
	    if (((IData)(vlTOPp->MemTile2__DOT__reqLdSTile) 
		 | (IData)(vlTOPp->MemTile2__DOT__reqStTile))) {
		vlTOPp->MemTile2__DOT__ldTileNextStAct = 1U;
		vlTOPp->MemTile2__DOT__ldTileNextExtOE = 0U;
		vlTOPp->MemTile2__DOT__ldTileNextExtWR = 1U;
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0x3fffffffff) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__dTileBaseHi
					  [(0x7fU & 
					    ((IData)(vlTOPp->MemTile2__DOT__ldTileIdx) 
					     >> 4U))])) 
			  << 0x26U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0xffc00000003f) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__dTileBase
					  [(0x7fU & 
					    ((IData)(vlTOPp->MemTile2__DOT__ldTileIdx) 
					     >> 4U))])) 
			  << 6U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = (VL_ULL(0xffffffffffc0) & vlTOPp->MemTile2__DOT__ldTileExtAddr);
	    } else {
		vlTOPp->MemTile2__DOT__ldTileNextStAct = 0U;
		vlTOPp->MemTile2__DOT__ldTileNextExtOE = 1U;
		vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0x3fffffffff) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseHi)) 
			  << 0x26U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0xffc00000003f) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseLo)) 
			  << 6U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = (VL_ULL(0xffffffffffc0) & vlTOPp->MemTile2__DOT__ldTileExtAddr);
	    }
	}
    }
    vlTOPp->extHold = ((((IData)(vlTOPp->MemTile2__DOT__reqLdTile) 
			 | (IData)(vlTOPp->MemTile2__DOT__ldTileAct)) 
			| (IData)(vlTOPp->MemTile2__DOT__ldTileDlyAct)) 
		       | (IData)(vlTOPp->MemTile2__DOT__resetAct));
}

void VMemTile2::_settle__TOP__4(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_settle__TOP__4\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp3,95,0,3);
    //char	__VpadToAlign164[4];
    VL_SIGW(__Vtemp4,95,0,3);
    // Body
    // ALWAYS at MemTile2.v:504
    if (vlTOPp->opRd) {
	VL_SHIFTR_WWI(96,96,5, __Vtemp3, vlTOPp->MemTile2__DOT__rdtTBlock, (IData)(vlTOPp->MemTile2__DOT__rdtShl));
	vlTOPp->MemTile2__DOT__rdtValue[0U] = __Vtemp3[0U];
	vlTOPp->MemTile2__DOT__rdtValue[1U] = __Vtemp3[1U];
	vlTOPp->MemTile2__DOT__rdtValue[2U] = __Vtemp3[2U];
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= (VL_ULL(0xffff) & vlTOPp->MemTile2__DOT__tDrdValue);
		} else {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= (VL_ULL(0xff) & vlTOPp->MemTile2__DOT__tDrdValue);
		}
	    } else {
		vlTOPp->MemTile2__DOT__tDrdValue = 
		    ((1U & (IData)(vlTOPp->opMode))
		      ? (((QData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[1U])) 
			  << 0x20U) | (QData)((IData)(
						      vlTOPp->MemTile2__DOT__rdtValue[0U])))
		      : (((QData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[1U])) 
			  << 0x20U) | (QData)((IData)(
						      vlTOPp->MemTile2__DOT__rdtValue[0U]))));
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff00000000) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[0U])));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff) & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | ((QData)((IData)(((0x80000000U 
						& vlTOPp->MemTile2__DOT__rdtValue[0U])
					        ? 0xffffffffU
					        : 0U))) 
			      << 0x20U));
		} else {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffff) & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (((0x8000U & vlTOPp->MemTile2__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffff)
			        : VL_ULL(0)) << 0x10U));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->MemTile2__DOT__rdtValue[0U]))));
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= ((VL_ULL(0xff) & vlTOPp->MemTile2__DOT__tDrdValue) 
			   | (((0x80U & vlTOPp->MemTile2__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffffff)
			        : VL_ULL(0)) << 8U));
		} else {
		    vlTOPp->MemTile2__DOT__tDrdValue 
			= (((QData)((IData)(vlTOPp->MemTile2__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->MemTile2__DOT__rdtValue[0U])));
		}
	    }
	}
    }
    // ALWAYS at MemTile2.v:756
    if (vlTOPp->iopRd) {
	vlTOPp->MemTile2__DOT__irdtTBlock[0U] = vlTOPp->MemTile2__DOT__iTile
	    [vlTOPp->MemTile2__DOT__iTileIdx];
	vlTOPp->MemTile2__DOT__irdtTBlock[1U] = vlTOPp->MemTile2__DOT__iTile
	    [(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__iTileIdx)))];
	vlTOPp->MemTile2__DOT__irdtTBlock[2U] = vlTOPp->MemTile2__DOT__iTile
	    [(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->MemTile2__DOT__iTileIdx)))];
	VL_SHIFTR_WWI(96,96,5, __Vtemp4, vlTOPp->MemTile2__DOT__irdtTBlock, (IData)(vlTOPp->MemTile2__DOT__irdtShl));
	vlTOPp->MemTile2__DOT__irdtValue[0U] = __Vtemp4[0U];
	vlTOPp->MemTile2__DOT__irdtValue[1U] = __Vtemp4[1U];
	vlTOPp->MemTile2__DOT__irdtValue[2U] = __Vtemp4[2U];
	vlTOPp->MemTile2__DOT__tIrdValue = (((QData)((IData)(
							     vlTOPp->MemTile2__DOT__irdtValue[1U])) 
					     << 0x20U) 
					    | (QData)((IData)(
							      vlTOPp->MemTile2__DOT__irdtValue[0U])));
    }
    // ALWAYS at MemTile2.v:571
    vlTOPp->MemTile2__DOT__dTileOpWrOK = 0U;
    if ((((IData)(vlTOPp->opWr) & (~ (IData)(vlTOPp->MemTile2__DOT__reqLdTile))) 
	 & (~ (IData)(vlTOPp->MemTile2__DOT__ldTileAct)))) {
	vlTOPp->MemTile2__DOT__rdtTBlock2[0U] = vlTOPp->MemTile2__DOT__rdtTBlock[0U];
	vlTOPp->MemTile2__DOT__rdtTBlock2[1U] = vlTOPp->MemTile2__DOT__rdtTBlock[1U];
	vlTOPp->MemTile2__DOT__rdtTBlock2[2U] = vlTOPp->MemTile2__DOT__rdtTBlock[2U];
	vlTOPp->MemTile2__DOT__dTileOpWrOK = 1U;
	if ((4U & (IData)(vlTOPp->opMode))) {
	    if ((1U & (~ ((IData)(vlTOPp->opMode) >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->opMode)))) {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->wrValue);
			vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
			    = (IData)((vlTOPp->wrValue 
				       >> 0x20U));
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->wrValue) 
				       << 8U)));
			    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				= ((0xffU & ((IData)(vlTOPp->wrValue) 
					     >> 0x18U)) 
				   | (0xffffff00U & 
				      ((IData)((vlTOPp->wrValue 
						>> 0x20U)) 
				       << 8U)));
			    vlTOPp->MemTile2__DOT__rdtTBlock2[2U] 
				= ((0xffffff00U & vlTOPp->MemTile2__DOT__rdtTBlock2[2U]) 
				   | (0xffU & ((IData)(
						       (vlTOPp->wrValue 
							>> 0x20U)) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
				vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				    = ((0xffffU & ((IData)(vlTOPp->wrValue) 
						   >> 0x10U)) 
				       | (0xffff0000U 
					  & ((IData)(
						     (vlTOPp->wrValue 
						      >> 0x20U)) 
					     << 0x10U)));
				vlTOPp->MemTile2__DOT__rdtTBlock2[2U] 
				    = ((0xffff0000U 
					& vlTOPp->MemTile2__DOT__rdtTBlock2[2U]) 
				       | (0xffffU & 
					  ((IData)(
						   (vlTOPp->wrValue 
						    >> 0x20U)) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
					= ((0xffffffU 
					    & ((IData)(vlTOPp->wrValue) 
					       >> 8U)) 
					   | (0xff000000U 
					      & ((IData)(
							 (vlTOPp->wrValue 
							  >> 0x20U)) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[2U] 
					= ((0xff000000U 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[2U]) 
					   | (0xffffffU 
					      & ((IData)(
							 (vlTOPp->wrValue 
							  >> 0x20U)) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->opMode))) {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->wrValue);
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->wrValue) 
				       << 8U)));
			    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				= ((0xffffff00U & vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
				   | (0xffU & ((IData)(vlTOPp->wrValue) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
				vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
				    = ((0xffff0000U 
					& vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
				       | (0xffffU & 
					  ((IData)(vlTOPp->wrValue) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
					= ((0xff000000U 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
					   | (0xffffffU 
					      & ((IData)(vlTOPp->wrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		} else {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = ((0xffff0000U & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
			       | (0xffffU & (IData)(vlTOPp->wrValue)));
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xff0000ffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xffff00U & ((IData)(vlTOPp->wrValue) 
						   << 8U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				    vlTOPp->MemTile2__DOT__rdtTBlock2[1U] 
					= ((0xffffff00U 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[1U]) 
					   | (0xffU 
					      & ((IData)(vlTOPp->wrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->opMode))) {
		    if ((0U == (3U & (IData)(vlTOPp->memAddr)))) {
			vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
			    = ((0xffffff00U & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
			       | (0xffU & (IData)(vlTOPp->wrValue)));
		    } else {
			if ((1U == (3U & (IData)(vlTOPp->memAddr)))) {
			    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				= ((0xffff00ffU & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				   | (0xff00U & ((IData)(vlTOPp->wrValue) 
						 << 8U)));
			} else {
			    if ((2U == (3U & (IData)(vlTOPp->memAddr)))) {
				vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
				    = ((0xff00ffffU 
					& vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
				       | (0xff0000U 
					  & ((IData)(vlTOPp->wrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & (IData)(vlTOPp->memAddr)))) {
				    vlTOPp->MemTile2__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->MemTile2__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->wrValue) 
						 << 0x18U)));
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at MemTile2.v:293
    if ((((IData)(vlTOPp->MemTile2__DOT__reqLdTile) 
	  | (IData)(vlTOPp->MemTile2__DOT__reqStTile)) 
	 | (IData)(vlTOPp->MemTile2__DOT__ldTileAct))) {
	if (vlTOPp->MemTile2__DOT__ldTileAct) {
	    vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0xfU 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| ((IData)(vlTOPp->MemTile2__DOT__reqLdTileIdx) 
						   << 4U));
	    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0x7f0U 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| (IData)(vlTOPp->MemTile2__DOT__ldTileWIdx));
	    vlTOPp->MemTile2__DOT__ldTileNextStAct 
		= vlTOPp->MemTile2__DOT__ldTileStAct;
	    if (vlTOPp->MemTile2__DOT__ldTileStAct) {
		vlTOPp->MemTile2__DOT__extData__out__out0 
		    = vlTOPp->MemTile2__DOT__dTile[vlTOPp->MemTile2__DOT__ldTileIdx];
	    }
	    vlTOPp->MemTile2__DOT__ldTileExtAddr = 
		((VL_ULL(0xffffffffffc3) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		 | ((QData)((IData)(vlTOPp->MemTile2__DOT__ldTileWIdx)) 
		    << 2U));
	    if (vlTOPp->MemTile2__DOT__ldTileDn) {
		vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
		vlTOPp->MemTile2__DOT__ldTileNextAct = 0U;
	    }
	    if (vlTOPp->extNotReady) {
		vlTOPp->MemTile2__DOT__ldTileNextWIdx 
		    = vlTOPp->MemTile2__DOT__ldTileWIdx;
	    } else {
		vlTOPp->MemTile2__DOT__ldTileNextWIdx 
		    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->MemTile2__DOT__ldTileWIdx)));
		if ((0U == (IData)(vlTOPp->MemTile2__DOT__ldTileNextWIdx))) {
		    if (vlTOPp->MemTile2__DOT__ldTileStAct) {
			if (vlTOPp->MemTile2__DOT__reqLdTile) {
			    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextStAct = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtOE = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
			    vlTOPp->MemTile2__DOT__ldTileExtAddr 
				= ((VL_ULL(0x3fffffffff) 
				    & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
				   | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseHi)) 
				      << 0x26U));
			    vlTOPp->MemTile2__DOT__ldTileExtAddr 
				= ((VL_ULL(0xffc00000003f) 
				    & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
				   | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseLo)) 
				      << 6U));
			} else {
			    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextStAct = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextDn = 1U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtOE = 0U;
			    vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
			}
		    } else {
			vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
			vlTOPp->MemTile2__DOT__ldTileNextDn = 1U;
			vlTOPp->MemTile2__DOT__ldTileNextExtOE = 0U;
			vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
		    }
		}
	    }
	} else {
	    vlTOPp->MemTile2__DOT__ldTileNextWIdx = 0U;
	    vlTOPp->MemTile2__DOT__ldTileNextDn = 0U;
	    vlTOPp->MemTile2__DOT__ldTileNextAct = 1U;
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0xfU 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| ((IData)(vlTOPp->MemTile2__DOT__reqLdTileIdx) 
						   << 4U));
	    vlTOPp->MemTile2__DOT__ldTileIdx = ((0x7f0U 
						 & (IData)(vlTOPp->MemTile2__DOT__ldTileIdx)) 
						| (IData)(vlTOPp->MemTile2__DOT__ldTileWIdx));
	    if (((IData)(vlTOPp->MemTile2__DOT__reqLdSTile) 
		 | (IData)(vlTOPp->MemTile2__DOT__reqStTile))) {
		vlTOPp->MemTile2__DOT__ldTileNextStAct = 1U;
		vlTOPp->MemTile2__DOT__ldTileNextExtOE = 0U;
		vlTOPp->MemTile2__DOT__ldTileNextExtWR = 1U;
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0x3fffffffff) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__dTileBaseHi
					  [(0x7fU & 
					    ((IData)(vlTOPp->MemTile2__DOT__ldTileIdx) 
					     >> 4U))])) 
			  << 0x26U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0xffc00000003f) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__dTileBase
					  [(0x7fU & 
					    ((IData)(vlTOPp->MemTile2__DOT__ldTileIdx) 
					     >> 4U))])) 
			  << 6U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = (VL_ULL(0xffffffffffc0) & vlTOPp->MemTile2__DOT__ldTileExtAddr);
	    } else {
		vlTOPp->MemTile2__DOT__ldTileNextStAct = 0U;
		vlTOPp->MemTile2__DOT__ldTileNextExtOE = 1U;
		vlTOPp->MemTile2__DOT__ldTileNextExtWR = 0U;
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0x3fffffffff) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseHi)) 
			  << 0x26U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = ((VL_ULL(0xffc00000003f) & vlTOPp->MemTile2__DOT__ldTileExtAddr) 
		       | ((QData)((IData)(vlTOPp->MemTile2__DOT__reqLdTileBaseLo)) 
			  << 6U));
		vlTOPp->MemTile2__DOT__ldTileExtAddr 
		    = (VL_ULL(0xffffffffffc0) & vlTOPp->MemTile2__DOT__ldTileExtAddr);
	    }
	}
    }
    vlTOPp->extHold = ((((IData)(vlTOPp->MemTile2__DOT__reqLdTile) 
			 | (IData)(vlTOPp->MemTile2__DOT__ldTileAct)) 
			| (IData)(vlTOPp->MemTile2__DOT__ldTileDlyAct)) 
		       | (IData)(vlTOPp->MemTile2__DOT__resetAct));
    vlTOPp->rdValue = vlTOPp->MemTile2__DOT__tDrdValue;
    vlTOPp->irdValue = vlTOPp->MemTile2__DOT__tIrdValue;
    vlTOPp->extAddr = vlTOPp->MemTile2__DOT__ldTileExtAddr;
    vlTOPp->extData = vlTOPp->MemTile2__DOT__extData__out__out0;
}

VL_INLINE_OPT void VMemTile2::_combo__TOP__5(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_combo__TOP__5\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rdValue = vlTOPp->MemTile2__DOT__tDrdValue;
    vlTOPp->irdValue = vlTOPp->MemTile2__DOT__tIrdValue;
    vlTOPp->extAddr = vlTOPp->MemTile2__DOT__ldTileExtAddr;
    vlTOPp->extData = vlTOPp->MemTile2__DOT__extData__out__out0;
}

void VMemTile2::_eval(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_eval\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VMemTile2::_eval_initial(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_eval_initial\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMemTile2::final() {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::final\n"); );
    // Variables
    VMemTile2__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMemTile2::_eval_settle(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_eval_settle\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData VMemTile2::_change_request(VMemTile2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_change_request\n"); );
    VMemTile2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VMemTile2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    opRd = VL_RAND_RESET_I(1);
    opWr = VL_RAND_RESET_I(1);
    opMode = VL_RAND_RESET_I(3);
    memAddr = VL_RAND_RESET_Q(64);
    wrValue = VL_RAND_RESET_Q(64);
    rdValue = VL_RAND_RESET_Q(64);
    iopRd = VL_RAND_RESET_I(1);
    imemAddr = VL_RAND_RESET_Q(48);
    irdValue = VL_RAND_RESET_Q(64);
    extAddr = VL_RAND_RESET_Q(48);
    extData = VL_RAND_RESET_I(32);
    extOE = VL_RAND_RESET_I(1);
    extWR = VL_RAND_RESET_I(1);
    extHold = VL_RAND_RESET_I(1);
    extNotReady = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    MemTile2__DOT__dTile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    MemTile2__DOT__dTileBase[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    MemTile2__DOT__dTileBaseHi[__Vi0] = VL_RAND_RESET_I(10);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    MemTile2__DOT__dTileBaseDty[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    MemTile2__DOT__iTile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    MemTile2__DOT__iTileBase[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    MemTile2__DOT__iTileBaseHi[__Vi0] = VL_RAND_RESET_I(10);
    }}
    MemTile2__DOT__dTileIdx = VL_RAND_RESET_I(11);
    MemTile2__DOT__iTileIdx = VL_RAND_RESET_I(11);
    MemTile2__DOT__dTileLimIdx = VL_RAND_RESET_I(11);
    MemTile2__DOT__iTileLimIdx = VL_RAND_RESET_I(11);
    MemTile2__DOT__dTileMiss = VL_RAND_RESET_I(1);
    MemTile2__DOT__iTileMiss = VL_RAND_RESET_I(1);
    MemTile2__DOT__dTileMiss2 = VL_RAND_RESET_I(1);
    MemTile2__DOT__iTileMiss2 = VL_RAND_RESET_I(1);
    MemTile2__DOT__dMemAddr = VL_RAND_RESET_Q(48);
    MemTile2__DOT__dMemAddrLim = VL_RAND_RESET_Q(48);
    MemTile2__DOT__iMemAddr = VL_RAND_RESET_Q(48);
    MemTile2__DOT__iMemAddrLim = VL_RAND_RESET_Q(48);
    VL_RAND_RESET_W(96,MemTile2__DOT__rdtTBlock);
    VL_RAND_RESET_W(96,MemTile2__DOT__rdtTBlock2);
    VL_RAND_RESET_W(96,MemTile2__DOT__rdtValue);
    MemTile2__DOT__rdtShl = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(96,MemTile2__DOT__irdtTBlock);
    VL_RAND_RESET_W(96,MemTile2__DOT__irdtValue);
    MemTile2__DOT__irdtShl = VL_RAND_RESET_I(5);
    MemTile2__DOT__tDrdValue = VL_RAND_RESET_Q(64);
    MemTile2__DOT__tIrdValue = VL_RAND_RESET_Q(64);
    MemTile2__DOT__reqLdTileBaseLo = VL_RAND_RESET_I(32);
    MemTile2__DOT__reqLdTileBaseHi = VL_RAND_RESET_I(10);
    MemTile2__DOT__reqLdTileIdx = VL_RAND_RESET_I(7);
    MemTile2__DOT__reqLdTile = VL_RAND_RESET_I(1);
    MemTile2__DOT__reqLdITile = VL_RAND_RESET_I(1);
    MemTile2__DOT__reqLdSTile = VL_RAND_RESET_I(1);
    MemTile2__DOT__reqStTile = VL_RAND_RESET_I(1);
    MemTile2__DOT__reqSyncTile = VL_RAND_RESET_I(1);
    MemTile2__DOT__reqNextSyncTile = VL_RAND_RESET_I(1);
    MemTile2__DOT__reqSyncTileIdx = VL_RAND_RESET_I(7);
    MemTile2__DOT__reqNextSyncTileIdx = VL_RAND_RESET_I(7);
    MemTile2__DOT__ldTileWIdx = VL_RAND_RESET_I(4);
    MemTile2__DOT__ldTileNextWIdx = VL_RAND_RESET_I(4);
    MemTile2__DOT__ldTileExtAddr = VL_RAND_RESET_Q(48);
    MemTile2__DOT__ldTileIdx = VL_RAND_RESET_I(11);
    MemTile2__DOT__ldTileAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileStAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextStAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileDlyAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextDlyAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileLastAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextLastAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileDn = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextDn = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileExtOE = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextExtOE = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileExtWR = VL_RAND_RESET_I(1);
    MemTile2__DOT__ldTileNextExtWR = VL_RAND_RESET_I(1);
    MemTile2__DOT__dTileOpWrOK = VL_RAND_RESET_I(1);
    MemTile2__DOT__resetAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__resetNextAct = VL_RAND_RESET_I(1);
    MemTile2__DOT__resetCurTile = VL_RAND_RESET_I(7);
    MemTile2__DOT__resetNextTile = VL_RAND_RESET_I(7);
    MemTile2__DOT__resetTOK = VL_RAND_RESET_I(16);
    MemTile2__DOT__extData__out__out0 = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}

void VMemTile2::_configure_coverage(VMemTile2__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VMemTile2::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
