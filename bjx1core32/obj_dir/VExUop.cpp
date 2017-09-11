// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VExUop.h for the primary calling header

#include "VExUop.h"            // For This
#include "VExUop__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VExUop) {
    VExUop__Syms* __restrict vlSymsp = __VlSymsp = new VExUop__Syms(this, name());
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VExUop::__Vconfigure(VExUop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VExUop::~VExUop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VExUop::eval() {
    VExUop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VExUop::eval\n"); );
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

void VExUop::_eval_initial_loop(VExUop__Syms* __restrict vlSymsp) {
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

void VExUop::_settle__TOP__1(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__1\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst = (VL_ULL(0xffffffff) 
						& vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst);
}

void VExUop::_initial__TOP__2(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_initial__TOP__2\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,95,0,3);
    //char	__VpadToAlign36[4];
    VL_SIGW(__Vtemp2,95,0,3);
    // Body
    // INITIAL at DecOp.v:40
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x70696478U;
    __Vtemp1[2U] = 0x756fU;
    VL_READMEM_W (true,12,256, 0,3, __Vtemp1, vlTOPp->ExUop__DOT__dec1__DOT__uopPcIdx
		  ,0,~0);
    __Vtemp2[0U] = 0x2e747874U;
    __Vtemp2[1U] = 0x7070676dU;
    __Vtemp2[2U] = 0x756fU;
    VL_READMEM_W (true,32,4096, 0,3, __Vtemp2, vlTOPp->ExUop__DOT__dec1__DOT__uopPgm
		  ,0,~0);
}

VL_INLINE_OPT void VExUop::_sequent__TOP__3(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_sequent__TOP__3\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__ExUop__DOT__tPipeFlush,2,0);
    VL_SIG8(__Vdly__ExUop__DOT__tPipeDsFlush,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v0,5,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v0,5,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v1,5,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v1,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v1,5,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v1,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__creg_lo__v0,3,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__creg_lo__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__creg_hi__v0,3,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__creg_hi__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v2,5,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v2,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v2,5,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v2,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTileBase__v0,6,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBase__v0,6,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v0,6,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v1,6,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__mem1__DOT__iTile__v0,0,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v3,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTileBase__v1,6,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v1,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBase__v1,6,0);
    VL_SIG8(__Vdlyvset__ExUop__DOT__mem1__DOT__dTileBase__v1,0,0);
    VL_SIG8(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v2,6,0);
    VL_SIG8(__Vdly__ExUop__DOT__mem1__DOT__ldTileAct,0,0);
    VL_SIG8(__Vdly__ExUop__DOT__mem1__DOT__ldTileStAct,0,0);
    VL_SIG8(__Vdly__ExUop__DOT__mem1__DOT__ldTileDn,0,0);
    //char	__VpadToAlign105[1];
    VL_SIG16(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v0,10,0);
    VL_SIG16(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v1,10,0);
    VL_SIG16(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v2,10,0);
    VL_SIG16(__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTile__v0,10,0);
    VL_SIG16(__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v3,10,0);
    VL_SIG(__Vdly__ExUop__DOT__ifRegPc,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v0,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v0,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v1,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v1,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__creg_lo__v0,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__creg_hi__v0,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v2,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v2,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v0,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v1,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v2,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__iTile__v0,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v3,31,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__iTileBase__v1,25,0);
    VL_SIG(__Vdlyvval__ExUop__DOT__mem1__DOT__dTileBase__v1,25,0);
    // Body
    __Vdly__ExUop__DOT__mem1__DOT__ldTileStAct = vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct;
    __Vdly__ExUop__DOT__mem1__DOT__ldTileDn = vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn;
    __Vdlyvset__ExUop__DOT__mem1__DOT__iTile__v0 = 0U;
    __Vdlyvset__ExUop__DOT__mem1__DOT__dTileBase__v1 = 0U;
    __Vdly__ExUop__DOT__mem1__DOT__ldTileAct = vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct;
    __Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v1 = 0U;
    __Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v0 = 0U;
    __Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v3 = 0U;
    __Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v0 = 0U;
    __Vdly__ExUop__DOT__tPipeFlush = vlTOPp->ExUop__DOT__tPipeFlush;
    __Vdly__ExUop__DOT__tPipeDsFlush = vlTOPp->ExUop__DOT__tPipeDsFlush;
    __Vdly__ExUop__DOT__ifRegPc = vlTOPp->ExUop__DOT__ifRegPc;
    __Vdlyvset__ExUop__DOT__regs__DOT__creg_lo__v0 = 0U;
    __Vdlyvset__ExUop__DOT__regs__DOT__creg_hi__v0 = 0U;
    __Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v1 = 0U;
    __Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v2 = 0U;
    __Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v1 = 0U;
    __Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v2 = 0U;
    __Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v0 = 0U;
    // ALWAYS at MemTile2.v:515
    if (vlTOPp->ExUop__DOT__mem1__DOT__resetAct) {
	__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v0 = 1U;
	__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTileBase__v0 
	    = vlTOPp->ExUop__DOT__mem1__DOT__resetCurTile;
	__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBase__v0 
	    = vlTOPp->ExUop__DOT__mem1__DOT__resetCurTile;
	vlTOPp->ExUop__DOT__mem1__DOT__resetTOK = 0x1234U;
    } else {
	vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx;
	vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct 
	    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDlyAct;
	vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtOE 
	    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE;
	vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtWR 
	    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR;
	vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTile 
	    = vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTile;
	vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTileIdx 
	    = vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTileIdx;
	vlTOPp->ExUop__DOT__mem1__DOT__ldTileLastAct 
	    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextLastAct;
	if (VL_UNLIKELY(((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileOpWrOK) 
			 & ((~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct)) 
			    | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn))))) {
	    VL_WRITEF("Posedge Write CA=%03x CB=%04x BH=%08x BL=%08x\n",
		      11,vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx,
		      32,((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			  << 2U),32,vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U],
		      32,vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]);
	    __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v0 
		= vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U];
	    __Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v0 = 1U;
	    __Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v0 
		= vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx;
	    __Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v0 
		= (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			    >> 4U));
	    __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v1 
		= vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U];
	    __Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v1 
		= (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx)));
	    __Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v1 
		= (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
			    >> 4U));
	    __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v2 
		= vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U];
	    __Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v2 
		= (0x7ffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx)));
	}
	if ((((IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct) 
	      & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn))) 
	     & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct)))) {
	    if (vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile) {
		__Vdlyvval__ExUop__DOT__mem1__DOT__iTile__v0 
		    = vlTOPp->extData;
		__Vdlyvset__ExUop__DOT__mem1__DOT__iTile__v0 = 1U;
		__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTile__v0 
		    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx;
	    } else {
		__Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v3 
		    = vlTOPp->extData;
		__Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v3 = 1U;
		__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v3 
		    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx;
	    }
	}
	if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn) {
	    if (vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile) {
		__Vdlyvval__ExUop__DOT__mem1__DOT__iTileBase__v1 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo;
		__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v1 = 1U;
		__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTileBase__v1 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx;
	    } else {
		__Vdlyvval__ExUop__DOT__mem1__DOT__dTileBase__v1 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo;
		__Vdlyvset__ExUop__DOT__mem1__DOT__dTileBase__v1 = 1U;
		__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBase__v1 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx;
		__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v2 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx;
	    }
	}
	__Vdly__ExUop__DOT__mem1__DOT__ldTileAct = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct;
	__Vdly__ExUop__DOT__mem1__DOT__ldTileStAct 
	    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct;
	__Vdly__ExUop__DOT__mem1__DOT__ldTileDn = vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn;
    }
    // ALWAYS at ExUop.v:733
    if ((1U & ((IData)(vlTOPp->ExUop__DOT__memHold) 
	       | (~ (IData)(vlTOPp->ExUop__DOT__tResetOK))))) {
	vlTOPp->ExUop__DOT__tResetMagic = ((IData)(vlTOPp->reset)
					    ? 0U : 0x3039U);
	if ((1U & (~ (IData)(vlTOPp->ExUop__DOT__tResetOK)))) {
	    vlTOPp->ExUop__DOT__regs__DOT__reg_sr = 0U;
	    vlTOPp->ExUop__DOT__regs__DOT__reg_pc = 0U;
	    vlTOPp->ExUop__DOT__regs__DOT__reg_pr = 0U;
	    vlTOPp->ExUop__DOT__imemAddr = 0U;
	    vlTOPp->ExUop__DOT__imemRd = 1U;
	}
    } else {
	vlTOPp->ExUop__DOT__regs__DOT__reg_sr = vlTOPp->ExUop__DOT__regNextSr;
	vlTOPp->ExUop__DOT__regs__DOT__reg_pc = vlTOPp->ExUop__DOT__regNextPc;
	vlTOPp->ExUop__DOT__regs__DOT__reg_pr = vlTOPp->ExUop__DOT__regNextPr;
	vlTOPp->ExUop__DOT__imemAddr = vlTOPp->ExUop__DOT__regNextPc;
	vlTOPp->ExUop__DOT__imemRd = 1U;
	if (((1U < (IData)(vlTOPp->ExUop__DOT__tPipeFlush)) 
	     | (IData)(vlTOPp->ExUop__DOT__tPipeDsFlush))) {
	    vlTOPp->ExUop__DOT__idInstWord = 0xf090f09U;
	    vlTOPp->ExUop__DOT__idRegPc = vlTOPp->ExUop__DOT__ifRegPc;
	} else {
	    if ((0U != (IData)(vlTOPp->ExUop__DOT__tPipeFlush))) {
		vlTOPp->ExUop__DOT__idInstWord = (IData)(vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue);
		vlTOPp->ExUop__DOT__idRegPc = vlTOPp->ExUop__DOT__ifRegPc;
	    } else {
		vlTOPp->ExUop__DOT__idInstWord = (IData)(vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue);
		vlTOPp->ExUop__DOT__idRegPc = vlTOPp->ExUop__DOT__idRegNextPc;
	    }
	}
	vlTOPp->ExUop__DOT__ixRegD = vlTOPp->ExUop__DOT__idRegD;
	vlTOPp->ExUop__DOT__ixRegS = vlTOPp->ExUop__DOT__idRegS;
	vlTOPp->ExUop__DOT__ixRegT = vlTOPp->ExUop__DOT__idRegT;
	vlTOPp->ExUop__DOT__ixImm = vlTOPp->ExUop__DOT__idImm;
	vlTOPp->ExUop__DOT__ixRegPc = vlTOPp->ExUop__DOT__ixRegNextPc;
	vlTOPp->ExUop__DOT__regPrPc = vlTOPp->ExUop__DOT__regPrNextPc;
	vlTOPp->ExUop__DOT__uopPc = vlTOPp->ExUop__DOT__uopNextPc;
	vlTOPp->ExUop__DOT__uopWord = vlTOPp->ExUop__DOT__uopNextWord;
	vlTOPp->ExUop__DOT__uopPcLive = vlTOPp->ExUop__DOT__uopNextPcLive;
	__Vdly__ExUop__DOT__tPipeFlush = vlTOPp->ExUop__DOT__tNextPipeFlush;
	__Vdly__ExUop__DOT__tPipeDsFlush = vlTOPp->ExUop__DOT__tNextPipeDsFlush;
	__Vdly__ExUop__DOT__ifRegPc = vlTOPp->ExUop__DOT__regNextPc;
    }
    // ALWAYS at GpReg.v:274
    if (vlTOPp->ExUop__DOT__oIsWr2D) {
	if (VL_LIKELY((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__oIdReg2D) 
				    >> 4U))))) {
	    if (vlTOPp->ExUop__DOT__oIsQw2D) {
		VL_WRITEF("R[%x]Q=%x\n",6,(0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D)),
			  64,vlTOPp->ExUop__DOT__oData2D);
		__Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v0 
		    = (IData)(vlTOPp->ExUop__DOT__oData2D);
		__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v0 = 1U;
		__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v0 
		    = (0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		__Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v0 
		    = (IData)((vlTOPp->ExUop__DOT__oData2D 
			       >> 0x20U));
		__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v0 
		    = (0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
	    } else {
		VL_WRITEF("R[%x]D=%x\n",6,(0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D)),
			  64,vlTOPp->ExUop__DOT__oData2D);
		if ((0x40U & (IData)(vlTOPp->ExUop__DOT__oIdReg2D))) {
		    __Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v1 
			= (IData)(vlTOPp->ExUop__DOT__oData2D);
		    __Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v1 = 1U;
		    __Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v1 
			= (0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		} else {
		    __Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v1 
			= (IData)(vlTOPp->ExUop__DOT__oData2D);
		    __Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v1 = 1U;
		    __Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v1 
			= (0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		}
	    }
	} else {
	    VL_WRITEF("CSR[%x]=%x\n",6,(0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D)),
		      64,vlTOPp->ExUop__DOT__oData2D);
	    if ((0x40U & (IData)(vlTOPp->ExUop__DOT__oIdReg2D))) {
		__Vdlyvval__ExUop__DOT__regs__DOT__creg_lo__v0 
		    = (IData)(vlTOPp->ExUop__DOT__oData2D);
		__Vdlyvset__ExUop__DOT__regs__DOT__creg_lo__v0 = 1U;
		__Vdlyvdim0__ExUop__DOT__regs__DOT__creg_lo__v0 
		    = (0xfU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		if (vlTOPp->ExUop__DOT__oIsQw2D) {
		    __Vdlyvval__ExUop__DOT__regs__DOT__creg_hi__v0 
			= (IData)((vlTOPp->ExUop__DOT__oData2D 
				   >> 0x20U));
		    __Vdlyvset__ExUop__DOT__regs__DOT__creg_hi__v0 = 1U;
		    __Vdlyvdim0__ExUop__DOT__regs__DOT__creg_hi__v0 
			= (0xfU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		}
	    } else {
		__Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v2 
		    = (IData)(vlTOPp->ExUop__DOT__oData2D);
		__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v2 = 1U;
		__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v2 
		    = (0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		if (vlTOPp->ExUop__DOT__oIsQw2D) {
		    __Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v2 
			= (IData)((vlTOPp->ExUop__DOT__oData2D 
				   >> 0x20U));
		    __Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v2 = 1U;
		    __Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v2 
			= (0x3fU & (IData)(vlTOPp->ExUop__DOT__oIdReg2D));
		}
	    }
	}
    }
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn = __Vdly__ExUop__DOT__mem1__DOT__ldTileDn;
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct = __Vdly__ExUop__DOT__mem1__DOT__ldTileStAct;
    // ALWAYSPOST at MemTile2.v:552
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__iTile__v0) {
	vlTOPp->ExUop__DOT__mem1__DOT__iTile[__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTile__v0] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__iTile__v0;
    }
    // ALWAYSPOST at MemTile2.v:517
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v0) {
	vlTOPp->ExUop__DOT__mem1__DOT__iTileBase[__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTileBase__v0] = 0x3ffffffU;
    }
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v1) {
	vlTOPp->ExUop__DOT__mem1__DOT__iTileBase[__Vdlyvdim0__ExUop__DOT__mem1__DOT__iTileBase__v1] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__iTileBase__v1;
    }
    // ALWAYSPOST at MemTile2.v:518
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__iTileBase__v0) {
	vlTOPp->ExUop__DOT__mem1__DOT__dTileBase[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBase__v0] = 0x3ffffffU;
    }
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__dTileBase__v1) {
	vlTOPp->ExUop__DOT__mem1__DOT__dTileBase[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBase__v1] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__dTileBase__v1;
    }
    // ALWAYSPOST at MemTile2.v:544
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v0) {
	vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v0] = 1U;
	vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v1] = 1U;
    }
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__dTileBase__v1) {
	vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTileBaseDty__v2] = 0U;
    }
    // ALWAYSPOST at MemTile2.v:541
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v0) {
	vlTOPp->ExUop__DOT__mem1__DOT__dTile[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v0] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v0;
	vlTOPp->ExUop__DOT__mem1__DOT__dTile[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v1] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v1;
	vlTOPp->ExUop__DOT__mem1__DOT__dTile[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v2] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v2;
    }
    if (__Vdlyvset__ExUop__DOT__mem1__DOT__dTile__v3) {
	vlTOPp->ExUop__DOT__mem1__DOT__dTile[__Vdlyvdim0__ExUop__DOT__mem1__DOT__dTile__v3] 
	    = __Vdlyvval__ExUop__DOT__mem1__DOT__dTile__v3;
    }
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct = __Vdly__ExUop__DOT__mem1__DOT__ldTileAct;
    vlTOPp->ExUop__DOT__tPipeFlush = __Vdly__ExUop__DOT__tPipeFlush;
    vlTOPp->ExUop__DOT__tPipeDsFlush = __Vdly__ExUop__DOT__tPipeDsFlush;
    vlTOPp->ExUop__DOT__ifRegPc = __Vdly__ExUop__DOT__ifRegPc;
    // ALWAYSPOST at GpReg.v:302
    if (__Vdlyvset__ExUop__DOT__regs__DOT__creg_lo__v0) {
	vlTOPp->ExUop__DOT__regs__DOT__creg_lo[__Vdlyvdim0__ExUop__DOT__regs__DOT__creg_lo__v0] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__creg_lo__v0;
    }
    // ALWAYSPOST at GpReg.v:304
    if (__Vdlyvset__ExUop__DOT__regs__DOT__creg_hi__v0) {
	vlTOPp->ExUop__DOT__regs__DOT__creg_hi[__Vdlyvdim0__ExUop__DOT__regs__DOT__creg_hi__v0] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__creg_hi__v0;
    }
    // ALWAYSPOST at GpReg.v:283
    if (__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v0) {
	vlTOPp->ExUop__DOT__regs__DOT__regs_lo[__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v0] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v0;
    }
    if (__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v1) {
	vlTOPp->ExUop__DOT__regs__DOT__regs_lo[__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v1] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v1;
    }
    if (__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v2) {
	vlTOPp->ExUop__DOT__regs__DOT__regs_lo[__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_lo__v2] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__regs_lo__v2;
    }
    // ALWAYSPOST at GpReg.v:284
    if (__Vdlyvset__ExUop__DOT__regs__DOT__regs_lo__v0) {
	vlTOPp->ExUop__DOT__regs__DOT__regs_hi[__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v0] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v0;
    }
    if (__Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v1) {
	vlTOPp->ExUop__DOT__regs__DOT__regs_hi[__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v1] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v1;
    }
    if (__Vdlyvset__ExUop__DOT__regs__DOT__regs_hi__v2) {
	vlTOPp->ExUop__DOT__regs__DOT__regs_hi[__Vdlyvdim0__ExUop__DOT__regs__DOT__regs_hi__v2] 
	    = __Vdlyvval__ExUop__DOT__regs__DOT__regs_hi__v2;
    }
    vlTOPp->extOE = vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtOE;
    vlTOPp->extWR = vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtWR;
    // ALWAYS at MemTile2.v:513
    vlTOPp->ExUop__DOT__mem1__DOT__resetCurTile = vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile;
    // ALWAYS at MemTile2.v:294
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDlyAct 
	= vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct;
    // ALWAYS at MemTile2.v:295
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextLastAct 
	= vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct;
    // ALWAYS at MemTile2.v:512
    vlTOPp->ExUop__DOT__mem1__DOT__resetAct = vlTOPp->ExUop__DOT__mem1__DOT__resetNextAct;
    // ALWAYS at FpuFp64B.v:124
    vlTOPp->ExUop__DOT__fpu1__DOT__tSro = (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
    // ALWAYS at DecOp.v:55
    vlTOPp->ExUop__DOT__dec1__DOT__opIs32p = (((((0U 
						  == 
						  (0xfU 
						   & (vlTOPp->ExUop__DOT__idInstWord 
						      >> 0xcU))) 
						 & (0U 
						    == 
						    (7U 
						     & (vlTOPp->ExUop__DOT__idInstWord 
							>> 1U)))) 
						| ((3U 
						    == 
						    (0xfU 
						     & (vlTOPp->ExUop__DOT__idInstWord 
							>> 0xcU))) 
						   & ((1U 
						       == 
						       (0xfU 
							& vlTOPp->ExUop__DOT__idInstWord)) 
						      | (9U 
							 == 
							 (0xfU 
							  & vlTOPp->ExUop__DOT__idInstWord))))) 
					       | ((0xfU 
						   == 
						   (0xfU 
						    & (vlTOPp->ExUop__DOT__idInstWord 
						       >> 0xcU))) 
						  & (0xfU 
						     == 
						     (0xfU 
						      & vlTOPp->ExUop__DOT__idInstWord)))) 
					      | ((8U 
						  == 
						  (0xfU 
						   & (vlTOPp->ExUop__DOT__idInstWord 
						      >> 0xcU))) 
						 & (((0xaU 
						      == 
						      (0xfU 
						       & vlTOPp->ExUop__DOT__idInstWord)) 
						     | (0xcU 
							== 
							(0xfU 
							 & vlTOPp->ExUop__DOT__idInstWord))) 
						    | (0xeU 
						       == 
						       (0xfU 
							& vlTOPp->ExUop__DOT__idInstWord)))));
    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0U;
    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0U;
    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
    vlTOPp->ExUop__DOT__idStepPc = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__opIs32p)
				     ? 2U : 1U);
    if ((0U == vlTOPp->ExUop__DOT__idInstWord)) {
	vlTOPp->ExUop__DOT__idStepPc = 1U;
    }
    vlTOPp->ExUop__DOT__idUopWord = 0U;
    vlTOPp->ExUop__DOT__idUopWord = (0xff7fffffU & vlTOPp->ExUop__DOT__idUopWord);
    vlTOPp->ExUop__DOT__dec1__DOT__srIsDq = (1U & (vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
						   >> 0xcU));
    if ((0x8000U & vlTOPp->ExUop__DOT__idInstWord)) {
	if ((0x4000U & vlTOPp->ExUop__DOT__idInstWord)) {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		    vlTOPp->ExUop__DOT__idStepPc = 1U;
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xffffffU : 0U) << 8U));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x1000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffffff00U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xffU & vlTOPp->ExUop__DOT__idInstWord));
		}
	    } else {
		vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		vlTOPp->ExUop__DOT__idStepPc = 1U;
	    }
	} else {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xfffffU : 0U) << 0xcU));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x30000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffff000U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfffU & vlTOPp->ExUop__DOT__idInstWord));
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xfffffU : 0U) << 0xcU));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x20000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffff000U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfffU & vlTOPp->ExUop__DOT__idInstWord));
		}
	    } else {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		    vlTOPp->ExUop__DOT__idStepPc = 1U;
		} else {
		    if ((0x800U & vlTOPp->ExUop__DOT__idInstWord)) {
			if ((0x400U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((0x200U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffeffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffdffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				}
			    } else {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x10000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffdffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				}
			    }
			} else {
			    if ((0x200U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffeffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x20000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				}
			    } else {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x10000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x20000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((0x4000U & vlTOPp->ExUop__DOT__idInstWord)) {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xffffffU : 0U) << 8U));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x1000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffffff00U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xffU & vlTOPp->ExUop__DOT__idInstWord));
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    if ((1U & (~ (vlTOPp->ExUop__DOT__idInstWord 
				  >> 3U)))) {
			if ((1U & (~ (vlTOPp->ExUop__DOT__idInstWord 
				      >> 2U)))) {
			    vlTOPp->ExUop__DOT__idUopWord 
				= ((2U & vlTOPp->ExUop__DOT__idInstWord)
				    ? ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0x27000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0x33000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord)))
				    : ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0x32000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0x31000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))));
			}
		    }
		}
	    } else {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffffff0U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfU & vlTOPp->ExUop__DOT__idInstWord));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x33000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		    vlTOPp->ExUop__DOT__idStepPc = 1U;
		}
	    }
	} else {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    if ((8U & vlTOPp->ExUop__DOT__idInstWord)) {
			if ((4U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xa000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    } else {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x1000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			} else {
			    if ((1U & (~ (vlTOPp->ExUop__DOT__idInstWord 
					  >> 1U)))) {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x2000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			}
		    } else {
			if ((4U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				vlTOPp->ExUop__DOT__idUopWord 
				    = ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0xc000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0xf000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord)));
			    }
			} else {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				vlTOPp->ExUop__DOT__idUopWord 
				    = ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0xd000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0xe000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord)));
			    } else {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xb000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			}
		    }
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    if ((0U == (0xfU & vlTOPp->ExUop__DOT__idInstWord))) {
			vlTOPp->ExUop__DOT__idUopWord 
			    = (0x39000000U | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
		    } else {
			if ((1U == (0xfU & vlTOPp->ExUop__DOT__idInstWord))) {
			    vlTOPp->ExUop__DOT__idUopWord 
				= (0x3a000000U | (0xffffffU 
						  & vlTOPp->ExUop__DOT__idUopWord));
			} else {
			    if ((2U == (0xfU & vlTOPp->ExUop__DOT__idInstWord))) {
				vlTOPp->ExUop__DOT__idUopWord 
				    = (0x3b000000U 
				       | (0xffffffU 
					  & vlTOPp->ExUop__DOT__idUopWord));
			    }
			}
		    }
		}
	    } else {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffffff0U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfU & vlTOPp->ExUop__DOT__idInstWord));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x3b000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		} else {
		    if ((8U & vlTOPp->ExUop__DOT__idInstWord)) {
			if ((4U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 4U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x33000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    } else {
				if ((1U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 4U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (((IData)(vlTOPp->ExUop__DOT__dec1__DOT__srIsDq)
					        ? 0x34U
					        : 0x32U) 
					      << 0x18U));
				} else {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 4U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x31000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			} else {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((1U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x40000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x210000U 
					   | (0xff00ffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffff0000U 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (0xffffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				}
			    } else {
				if ((1U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x40000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x210000U 
					   | (0xff00ffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffff0000U 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (0xffffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				} else {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x40000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x210000U 
					   | (0xff00ffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffff0000U 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (0xffffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ExUop__DOT__idRegD = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD) 
				  ^ (((vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
				       >> 0x1dU) & 
				      (0U == (0xfU 
					      & ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD) 
						 >> 3U))))
				      ? 0x58U : 0U));
    vlTOPp->ExUop__DOT__idRegS = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS) 
				  ^ (((vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
				       >> 0x1dU) & 
				      (0U == (0xfU 
					      & ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS) 
						 >> 3U))))
				      ? 0x58U : 0U));
    vlTOPp->ExUop__DOT__idRegT = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT) 
				  ^ (((vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
				       >> 0x1dU) & 
				      (0U == (0xfU 
					      & ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT) 
						 >> 3U))))
				      ? 0x58U : 0U));
    vlTOPp->ExUop__DOT__idImm = vlTOPp->ExUop__DOT__dec1__DOT__tIdImm;
}

VL_INLINE_OPT void VExUop::_sequent__TOP__4(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_sequent__TOP__4\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ExUop.v:727
    vlTOPp->ExUop__DOT__oData2D = vlTOPp->ExUop__DOT__tData2D;
    // ALWAYS at ExUop.v:728
    vlTOPp->ExUop__DOT__oIsWr2D = vlTOPp->ExUop__DOT__tIsWr2D;
    // ALWAYS at ExUop.v:729
    vlTOPp->ExUop__DOT__oIsQw2D = vlTOPp->ExUop__DOT__tIsQw2D;
    // ALWAYS at ExUop.v:730
    vlTOPp->ExUop__DOT__oIdReg2D = vlTOPp->ExUop__DOT__tIdReg2D;
}

void VExUop::_settle__TOP__5(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__5\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->extOE = vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtOE;
    vlTOPp->extWR = vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtWR;
    // ALWAYS at MemTile2.v:294
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDlyAct 
	= vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct;
    // ALWAYS at MemTile2.v:295
    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextLastAct 
	= vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct;
    vlTOPp->ExUop__DOT__tResetOK = ((~ (IData)(vlTOPp->reset)) 
				    & (0x3039U == (IData)(vlTOPp->ExUop__DOT__tResetMagic)));
    // ALWAYS at FpuFp64B.v:124
    vlTOPp->ExUop__DOT__fpu1__DOT__tSro = (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
    // ALWAYS at DecOp.v:55
    vlTOPp->ExUop__DOT__dec1__DOT__opIs32p = (((((0U 
						  == 
						  (0xfU 
						   & (vlTOPp->ExUop__DOT__idInstWord 
						      >> 0xcU))) 
						 & (0U 
						    == 
						    (7U 
						     & (vlTOPp->ExUop__DOT__idInstWord 
							>> 1U)))) 
						| ((3U 
						    == 
						    (0xfU 
						     & (vlTOPp->ExUop__DOT__idInstWord 
							>> 0xcU))) 
						   & ((1U 
						       == 
						       (0xfU 
							& vlTOPp->ExUop__DOT__idInstWord)) 
						      | (9U 
							 == 
							 (0xfU 
							  & vlTOPp->ExUop__DOT__idInstWord))))) 
					       | ((0xfU 
						   == 
						   (0xfU 
						    & (vlTOPp->ExUop__DOT__idInstWord 
						       >> 0xcU))) 
						  & (0xfU 
						     == 
						     (0xfU 
						      & vlTOPp->ExUop__DOT__idInstWord)))) 
					      | ((8U 
						  == 
						  (0xfU 
						   & (vlTOPp->ExUop__DOT__idInstWord 
						      >> 0xcU))) 
						 & (((0xaU 
						      == 
						      (0xfU 
						       & vlTOPp->ExUop__DOT__idInstWord)) 
						     | (0xcU 
							== 
							(0xfU 
							 & vlTOPp->ExUop__DOT__idInstWord))) 
						    | (0xeU 
						       == 
						       (0xfU 
							& vlTOPp->ExUop__DOT__idInstWord)))));
    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0U;
    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0U;
    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
    vlTOPp->ExUop__DOT__idStepPc = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__opIs32p)
				     ? 2U : 1U);
    if ((0U == vlTOPp->ExUop__DOT__idInstWord)) {
	vlTOPp->ExUop__DOT__idStepPc = 1U;
    }
    vlTOPp->ExUop__DOT__idUopWord = 0U;
    vlTOPp->ExUop__DOT__idUopWord = (0xff7fffffU & vlTOPp->ExUop__DOT__idUopWord);
    vlTOPp->ExUop__DOT__dec1__DOT__srIsDq = (1U & (vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
						   >> 0xcU));
    if ((0x8000U & vlTOPp->ExUop__DOT__idInstWord)) {
	if ((0x4000U & vlTOPp->ExUop__DOT__idInstWord)) {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		    vlTOPp->ExUop__DOT__idStepPc = 1U;
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xffffffU : 0U) << 8U));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x1000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffffff00U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xffU & vlTOPp->ExUop__DOT__idInstWord));
		}
	    } else {
		vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		vlTOPp->ExUop__DOT__idStepPc = 1U;
	    }
	} else {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xfffffU : 0U) << 0xcU));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x30000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffff000U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfffU & vlTOPp->ExUop__DOT__idInstWord));
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xfffffU : 0U) << 0xcU));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x20000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffff000U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfffU & vlTOPp->ExUop__DOT__idInstWord));
		}
	    } else {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		    vlTOPp->ExUop__DOT__idStepPc = 1U;
		} else {
		    if ((0x800U & vlTOPp->ExUop__DOT__idInstWord)) {
			if ((0x400U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((0x200U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffeffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffdffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				}
			    } else {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x10000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffdffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				}
			    }
			} else {
			    if ((0x200U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xfffeffffU 
					   & vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x20000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				}
			    } else {
				if ((0x100U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x5fU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffU 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (((0x80U 
						& vlTOPp->ExUop__DOT__idInstWord)
					        ? 0xfffffU
					        : 0U) 
					      << 0xcU));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x50000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
					= ((0xfffff000U 
					    & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
					   | (0xfffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x10000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x20000U 
					   | vlTOPp->ExUop__DOT__idUopWord);
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((0x4000U & vlTOPp->ExUop__DOT__idInstWord)) {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5eU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffU & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (((0x80U & vlTOPp->ExUop__DOT__idInstWord)
			        ? 0xffffffU : 0U) << 8U));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x1000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xffffff00U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xffU & vlTOPp->ExUop__DOT__idInstWord));
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    if ((1U & (~ (vlTOPp->ExUop__DOT__idInstWord 
				  >> 3U)))) {
			if ((1U & (~ (vlTOPp->ExUop__DOT__idInstWord 
				      >> 2U)))) {
			    vlTOPp->ExUop__DOT__idUopWord 
				= ((2U & vlTOPp->ExUop__DOT__idInstWord)
				    ? ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0x27000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0x33000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord)))
				    : ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0x32000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0x31000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))));
			}
		    }
		}
	    } else {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffffff0U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfU & vlTOPp->ExUop__DOT__idInstWord));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x33000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x7fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm = 0U;
		    vlTOPp->ExUop__DOT__idStepPc = 1U;
		}
	    }
	} else {
	    if ((0x2000U & vlTOPp->ExUop__DOT__idInstWord)) {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    if ((8U & vlTOPp->ExUop__DOT__idInstWord)) {
			if ((4U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xa000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    } else {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x1000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			} else {
			    if ((1U & (~ (vlTOPp->ExUop__DOT__idInstWord 
					  >> 1U)))) {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x2000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			}
		    } else {
			if ((4U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				vlTOPp->ExUop__DOT__idUopWord 
				    = ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0xc000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0xf000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord)));
			    }
			} else {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				vlTOPp->ExUop__DOT__idUopWord 
				    = ((1U & vlTOPp->ExUop__DOT__idInstWord)
				        ? (0xd000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord))
				        : (0xe000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord)));
			    } else {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0xb000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			}
		    }
		} else {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    if ((0U == (0xfU & vlTOPp->ExUop__DOT__idInstWord))) {
			vlTOPp->ExUop__DOT__idUopWord 
			    = (0x39000000U | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
		    } else {
			if ((1U == (0xfU & vlTOPp->ExUop__DOT__idInstWord))) {
			    vlTOPp->ExUop__DOT__idUopWord 
				= (0x3a000000U | (0xffffffU 
						  & vlTOPp->ExUop__DOT__idUopWord));
			} else {
			    if ((2U == (0xfU & vlTOPp->ExUop__DOT__idInstWord))) {
				vlTOPp->ExUop__DOT__idUopWord 
				    = (0x3b000000U 
				       | (0xffffffU 
					  & vlTOPp->ExUop__DOT__idUopWord));
			    }
			}
		    }
		}
	    } else {
		if ((0x1000U & vlTOPp->ExUop__DOT__idInstWord)) {
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 4U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
			= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
			   | (0xfU & (vlTOPp->ExUop__DOT__idInstWord 
				      >> 8U)));
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0x5fU;
		    vlTOPp->ExUop__DOT__dec1__DOT__tIdImm 
			= ((0xfffffff0U & vlTOPp->ExUop__DOT__dec1__DOT__tIdImm) 
			   | (0xfU & vlTOPp->ExUop__DOT__idInstWord));
		    vlTOPp->ExUop__DOT__idUopWord = 
			(0x3b000000U | (0xffffffU & vlTOPp->ExUop__DOT__idUopWord));
		} else {
		    if ((8U & vlTOPp->ExUop__DOT__idInstWord)) {
			if ((4U & vlTOPp->ExUop__DOT__idInstWord)) {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((1U & (~ vlTOPp->ExUop__DOT__idInstWord))) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 4U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x33000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    } else {
				if ((1U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 4U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (((IData)(vlTOPp->ExUop__DOT__dec1__DOT__srIsDq)
					        ? 0x34U
					        : 0x32U) 
					      << 0x18U));
				} else {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 4U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT = 0U;
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x31000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				}
			    }
			} else {
			    if ((2U & vlTOPp->ExUop__DOT__idInstWord)) {
				if ((1U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x40000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x210000U 
					   | (0xff00ffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffff0000U 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (0xffffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				}
			    } else {
				if ((1U & vlTOPp->ExUop__DOT__idInstWord)) {
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT 
					= ((0x70U & (IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT)) 
					   | (0xfU 
					      & (vlTOPp->ExUop__DOT__idInstWord 
						 >> 8U)));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x40000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x210000U 
					   | (0xff00ffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffff0000U 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (0xffffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				} else {
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x40000000U 
					   | (0xffffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= (0x210000U 
					   | (0xff00ffffU 
					      & vlTOPp->ExUop__DOT__idUopWord));
				    vlTOPp->ExUop__DOT__idUopWord 
					= ((0xffff0000U 
					    & vlTOPp->ExUop__DOT__idUopWord) 
					   | (0xffffU 
					      & vlTOPp->ExUop__DOT__idInstWord));
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ExUop__DOT__idRegD = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD) 
				  ^ (((vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
				       >> 0x1dU) & 
				      (0U == (0xfU 
					      & ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegD) 
						 >> 3U))))
				      ? 0x58U : 0U));
    vlTOPp->ExUop__DOT__idRegS = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS) 
				  ^ (((vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
				       >> 0x1dU) & 
				      (0U == (0xfU 
					      & ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegS) 
						 >> 3U))))
				      ? 0x58U : 0U));
    vlTOPp->ExUop__DOT__idRegT = ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT) 
				  ^ (((vlTOPp->ExUop__DOT__regs__DOT__reg_sr 
				       >> 0x1dU) & 
				      (0U == (0xfU 
					      & ((IData)(vlTOPp->ExUop__DOT__dec1__DOT__tIdRegT) 
						 >> 3U))))
				      ? 0x58U : 0U));
    vlTOPp->ExUop__DOT__idImm = vlTOPp->ExUop__DOT__dec1__DOT__tIdImm;
    // ALWAYS at GpReg.v:179
    vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo = (0x3fU 
						& (IData)(vlTOPp->ExUop__DOT__iRegD));
    if ((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__iRegD) 
		      >> 4U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegD))) {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])));
	    vlTOPp->ExUop__DOT__iDataD = (VL_ULL(0xffffffff) 
					  & vlTOPp->ExUop__DOT__iDataD);
	} else {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])));
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])) 
					     << 0x20U));
	}
    } else {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegD))) {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__creg_lo
							    [
							    (0xfU 
							     & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo))])));
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__creg_hi
							     [
							     (0xfU 
							      & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo))])) 
					     << 0x20U));
	} else {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])));
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])) 
					     << 0x20U));
	}
    }
    // ALWAYS at GpReg.v:180
    vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo = (0x3fU 
						& (IData)(vlTOPp->ExUop__DOT__iRegS));
    if ((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__iRegS) 
		      >> 4U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegS))) {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])));
	    vlTOPp->ExUop__DOT__iDataS = (VL_ULL(0xffffffff) 
					  & vlTOPp->ExUop__DOT__iDataS);
	} else {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])));
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])) 
					     << 0x20U));
	}
    } else {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegS))) {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__creg_lo
							    [
							    (0xfU 
							     & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo))])));
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__creg_hi
							     [
							     (0xfU 
							      & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo))])) 
					     << 0x20U));
	} else {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])));
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])) 
					     << 0x20U));
	}
    }
    // ALWAYS at GpReg.v:181
    vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo = (0x3fU 
						& (IData)(vlTOPp->ExUop__DOT__iRegT));
    if ((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__iRegT) 
		      >> 4U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegT))) {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])));
	    vlTOPp->ExUop__DOT__iDataT = (VL_ULL(0xffffffff) 
					  & vlTOPp->ExUop__DOT__iDataT);
	} else {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])));
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])) 
					     << 0x20U));
	}
    } else {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegT))) {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__creg_lo
							    [
							    (0xfU 
							     & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo))])));
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__creg_hi
							     [
							     (0xfU 
							      & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo))])) 
					     << 0x20U));
	} else {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])));
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])) 
					     << 0x20U));
	}
    }
    vlTOPp->ExUop__DOT__memHold = ((((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile) 
				     | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct)) 
				    | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct)) 
				   | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetAct));
}

VL_INLINE_OPT void VExUop::_combo__TOP__6(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_combo__TOP__6\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__tResetOK = ((~ (IData)(vlTOPp->reset)) 
				    & (0x3039U == (IData)(vlTOPp->ExUop__DOT__tResetMagic)));
    // ALWAYS at GpReg.v:179
    vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo = (0x3fU 
						& (IData)(vlTOPp->ExUop__DOT__iRegD));
    if ((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__iRegD) 
		      >> 4U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegD))) {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])));
	    vlTOPp->ExUop__DOT__iDataD = (VL_ULL(0xffffffff) 
					  & vlTOPp->ExUop__DOT__iDataD);
	} else {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])));
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])) 
					     << 0x20U));
	}
    } else {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegD))) {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__creg_lo
							    [
							    (0xfU 
							     & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo))])));
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__creg_hi
							     [
							     (0xfU 
							      & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo))])) 
					     << 0x20U));
	} else {
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])));
	    vlTOPp->ExUop__DOT__iDataD = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataD) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg1Lo])) 
					     << 0x20U));
	}
    }
    // ALWAYS at GpReg.v:180
    vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo = (0x3fU 
						& (IData)(vlTOPp->ExUop__DOT__iRegS));
    if ((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__iRegS) 
		      >> 4U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegS))) {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])));
	    vlTOPp->ExUop__DOT__iDataS = (VL_ULL(0xffffffff) 
					  & vlTOPp->ExUop__DOT__iDataS);
	} else {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])));
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])) 
					     << 0x20U));
	}
    } else {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegS))) {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__creg_lo
							    [
							    (0xfU 
							     & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo))])));
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__creg_hi
							     [
							     (0xfU 
							      & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo))])) 
					     << 0x20U));
	} else {
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])));
	    vlTOPp->ExUop__DOT__iDataS = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataS) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg2Lo])) 
					     << 0x20U));
	}
    }
    // ALWAYS at GpReg.v:181
    vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo = (0x3fU 
						& (IData)(vlTOPp->ExUop__DOT__iRegT));
    if ((1U != (3U & ((IData)(vlTOPp->ExUop__DOT__iRegT) 
		      >> 4U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegT))) {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])));
	    vlTOPp->ExUop__DOT__iDataT = (VL_ULL(0xffffffff) 
					  & vlTOPp->ExUop__DOT__iDataT);
	} else {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])));
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])) 
					     << 0x20U));
	}
    } else {
	if ((0x40U & (IData)(vlTOPp->ExUop__DOT__iRegT))) {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__creg_lo
							    [
							    (0xfU 
							     & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo))])));
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__creg_hi
							     [
							     (0xfU 
							      & (IData)(vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo))])) 
					     << 0x20U));
	} else {
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff00000000) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | (IData)((IData)(
							    vlTOPp->ExUop__DOT__regs__DOT__regs_lo
							    [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])));
	    vlTOPp->ExUop__DOT__iDataT = ((VL_ULL(0xffffffff) 
					   & vlTOPp->ExUop__DOT__iDataT) 
					  | ((QData)((IData)(
							     vlTOPp->ExUop__DOT__regs__DOT__regs_hi
							     [vlTOPp->ExUop__DOT__regs__DOT__tIdReg3Lo])) 
					     << 0x20U));
	}
    }
    vlTOPp->ExUop__DOT__memHold = ((((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile) 
				     | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct)) 
				    | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct)) 
				   | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetAct));
    // ALWAYS at ExUop.v:287
    if (VL_LIKELY(vlTOPp->ExUop__DOT__tResetOK)) {
	if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->ExUop__DOT__tResetOK)) 
			       & (~ (IData)(vlTOPp->ExUop__DOT__memHold)))))) {
	    VL_WRITEF("Hold\n");
	} else {
	    if (VL_UNLIKELY(((~ (IData)(vlTOPp->ExUop__DOT__memHold)) 
			     & (IData)(vlTOPp->ExUop__DOT__tResetOK)))) {
		if (VL_LIKELY(vlTOPp->ExUop__DOT__uopPcLive)) {
		    vlTOPp->ExUop__DOT__idNextInstWord 
			= vlTOPp->ExUop__DOT__idInstWord;
		} else {
		    vlTOPp->ExUop__DOT__idNextInstWord 
			= (IData)(vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue);
		    VL_WRITEF("1F: PC=%x Op=%x\n",32,
			      vlTOPp->ExUop__DOT__ifRegPc,
			      32,vlTOPp->ExUop__DOT__idNextInstWord);
		    vlTOPp->ExUop__DOT__idRegNextPc 
			= vlTOPp->ExUop__DOT__ifRegPc;
		    if ((VL_ULL(0) == vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue)) {
			vlTOPp->ExUop__DOT__idNextInstWord = 0xffffffffU;
		    }
		}
		vlTOPp->ExUop__DOT__iDataFpuD = vlTOPp->ExUop__DOT__iDataD;
		vlTOPp->ExUop__DOT__iDataFpuS = vlTOPp->ExUop__DOT__iDataS;
		vlTOPp->ExUop__DOT__iDataFpuT = vlTOPp->ExUop__DOT__iDataT;
		vlTOPp->ExUop__DOT__tIsQw2D = 0U;
		vlTOPp->ExUop__DOT__fpuOpFp32 = 0U;
		vlTOPp->ExUop__DOT__tRegStepPc = (7U 
						  & vlTOPp->ExUop__DOT__tRegStepPc);
		vlTOPp->ExUop__DOT__tRegStepPc = ((0xfffffff9U 
						   & vlTOPp->ExUop__DOT__tRegStepPc) 
						  | ((IData)(vlTOPp->ExUop__DOT__idStepPc) 
						     << 1U));
		vlTOPp->ExUop__DOT__tRegStepPc = (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__tRegStepPc);
		if (VL_UNLIKELY((1U < (IData)(vlTOPp->ExUop__DOT__tPipeFlush)))) {
		    VL_WRITEF("2D-0/F: PC=%x Op=%x St=%x\n",
			      32,vlTOPp->ExUop__DOT__idRegPc,
			      32,vlTOPp->ExUop__DOT__idInstWord,
			      2,(IData)(vlTOPp->ExUop__DOT__idStepPc));
		    vlTOPp->ExUop__DOT__regNextPc = vlTOPp->ExUop__DOT__regs__DOT__reg_pc;
		    vlTOPp->ExUop__DOT__regPrNextPc 
			= ((IData)(4U) + vlTOPp->ExUop__DOT__regs__DOT__reg_pc);
		    vlTOPp->ExUop__DOT__uopNextPc = 0U;
		    vlTOPp->ExUop__DOT__uopNextWord 
			= vlTOPp->ExUop__DOT__idUopWord;
		    vlTOPp->ExUop__DOT__ixRegNextPc 
			= vlTOPp->ExUop__DOT__idRegPc;
		    VL_WRITEF("2D-1/F: uPC=000 uOp=%x\n",
			      32,vlTOPp->ExUop__DOT__idUopWord);
		} else {
		    if (VL_LIKELY(vlTOPp->ExUop__DOT__uopPcLive)) {
			if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->ExUop__DOT__memHold))))) {
			    VL_WRITEF("2D-2 uPC=000 uOp=%x\n",
				      32,vlTOPp->ExUop__DOT__idUopWord);
			}
			vlTOPp->ExUop__DOT__regNextPc 
			    = vlTOPp->ExUop__DOT__regs__DOT__reg_pc;
			vlTOPp->ExUop__DOT__regPrNextPc 
			    = ((IData)(4U) + vlTOPp->ExUop__DOT__regs__DOT__reg_pc);
		    } else {
			VL_WRITEF("2D-0: PC=%x Op=%x St=%x\n",
				  32,vlTOPp->ExUop__DOT__idRegPc,
				  32,vlTOPp->ExUop__DOT__idInstWord,
				  2,(IData)(vlTOPp->ExUop__DOT__idStepPc));
			vlTOPp->ExUop__DOT__uopNextPc = 0U;
			vlTOPp->ExUop__DOT__uopNextWord 
			    = vlTOPp->ExUop__DOT__idUopWord;
			vlTOPp->ExUop__DOT__regNextPc 
			    = (vlTOPp->ExUop__DOT__ifRegPc 
			       + vlTOPp->ExUop__DOT__tRegStepPc);
			vlTOPp->ExUop__DOT__ixRegNextPc 
			    = vlTOPp->ExUop__DOT__idRegPc;
			VL_WRITEF("2D-1: uPC=000 uOp=%x\n",
				  32,vlTOPp->ExUop__DOT__idUopWord);
			vlTOPp->ExUop__DOT__regPrNextPc 
			    = (vlTOPp->ExUop__DOT__ifRegPc 
			       + vlTOPp->ExUop__DOT__tRegStepPc);
			if (VL_UNLIKELY((0xffffffffU 
					 == vlTOPp->ExUop__DOT__idInstWord))) {
			    vl_finish("ExUop.v",344,"");
			}
		    }
		}
		vlTOPp->ExUop__DOT__uopCmd = (0xffU 
					      & (vlTOPp->ExUop__DOT__uopWord 
						 >> 0x18U));
		if ((0U != (IData)(vlTOPp->ExUop__DOT__tPipeFlush))) {
		    vlTOPp->ExUop__DOT__tNextPipeFlush 
			= (7U & ((IData)(vlTOPp->ExUop__DOT__tPipeFlush) 
				 - (IData)(1U)));
		    vlTOPp->ExUop__DOT__tNextPipeDsFlush 
			= vlTOPp->ExUop__DOT__tPipeDsFlush;
		} else {
		    vlTOPp->ExUop__DOT__tNextPipeFlush = 0U;
		    vlTOPp->ExUop__DOT__tNextPipeDsFlush = 0U;
		}
		VL_WRITEF("3E-0: PC=%x\n",32,vlTOPp->ExUop__DOT__ixRegPc);
		VL_WRITEF("3E-1 uPC=%x uOp=%x\n",12,
			  vlTOPp->ExUop__DOT__uopPc,
			  32,vlTOPp->ExUop__DOT__uopWord);
		if ((0x800000U & vlTOPp->ExUop__DOT__uopWord)) {
		    vlTOPp->ExUop__DOT__uopNextPc = 
			(0xfffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__uopPc)));
		    vlTOPp->ExUop__DOT__uopNextWord 
			= vlTOPp->ExUop__DOT__dec1__DOT__uopPgm
			[vlTOPp->ExUop__DOT__uopNextPc];
		    vlTOPp->ExUop__DOT__uopNextPcLive = 1U;
		} else {
		    vlTOPp->ExUop__DOT__uopNextPcLive = 0U;
		}
		if ((0U != (IData)(vlTOPp->ExUop__DOT__tPipeFlush))) {
		    vlTOPp->ExUop__DOT__uopNextPcLive = 0U;
		}
		if ((0x400000U & vlTOPp->ExUop__DOT__uopWord)) {
		    if ((0x200000U & vlTOPp->ExUop__DOT__uopWord)) {
			vlTOPp->ExUop__DOT__iRegD = 
			    (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegD));
			vlTOPp->ExUop__DOT__iRegS = 
			    (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegS));
			vlTOPp->ExUop__DOT__iRegT = 
			    (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegT));
			vlTOPp->ExUop__DOT__iImm = 
			    ((0xffU & vlTOPp->ExUop__DOT__iImm) 
			     | (((1U & ((vlTOPp->ExUop__DOT__uopWord 
					 >> 0x14U) 
					& (vlTOPp->ExUop__DOT__uopWord 
					   >> 7U)))
				  ? 0xffffffU : 0U) 
				<< 8U));
			vlTOPp->ExUop__DOT__iRegD = 
			    ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegD)) 
			     | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 0x10U)));
			vlTOPp->ExUop__DOT__iRegS = 
			    ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegS)) 
			     | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 0xcU)));
			vlTOPp->ExUop__DOT__iRegT = 
			    ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegT)) 
			     | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 8U)));
			vlTOPp->ExUop__DOT__iImm = 
			    ((0xffffff00U & vlTOPp->ExUop__DOT__iImm) 
			     | (0xffU & vlTOPp->ExUop__DOT__uopWord));
		    } else {
			vlTOPp->ExUop__DOT__iRegD = 
			    (0x7fU & (vlTOPp->ExUop__DOT__uopWord 
				      >> 0xeU));
			vlTOPp->ExUop__DOT__iRegS = 
			    (0x7fU & (vlTOPp->ExUop__DOT__uopWord 
				      >> 7U));
			vlTOPp->ExUop__DOT__iRegT = 
			    (0x7fU & vlTOPp->ExUop__DOT__uopWord);
			vlTOPp->ExUop__DOT__iImm = vlTOPp->ExUop__DOT__ixImm;
		    }
		} else {
		    if ((0x200000U & vlTOPp->ExUop__DOT__uopWord)) {
			if ((0x100000U & vlTOPp->ExUop__DOT__uopWord)) {
			    vlTOPp->ExUop__DOT__iRegS 
				= vlTOPp->ExUop__DOT__ixRegS;
			    vlTOPp->ExUop__DOT__iRegT 
				= vlTOPp->ExUop__DOT__ixRegT;
			    vlTOPp->ExUop__DOT__iRegD 
				= (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegD));
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xffffU & vlTOPp->ExUop__DOT__iImm) 
				   | (((0x8000U & vlTOPp->ExUop__DOT__uopWord)
				        ? 0xffffU : 0U) 
				      << 0x10U));
			    vlTOPp->ExUop__DOT__iRegD 
				= ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegD)) 
				   | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					      >> 0x10U)));
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xffff0000U & vlTOPp->ExUop__DOT__iImm) 
				   | (0xffffU & vlTOPp->ExUop__DOT__uopWord));
			} else {
			    vlTOPp->ExUop__DOT__iRegD 
				= vlTOPp->ExUop__DOT__ixRegD;
			    vlTOPp->ExUop__DOT__iRegS 
				= vlTOPp->ExUop__DOT__ixRegS;
			    vlTOPp->ExUop__DOT__iRegT 
				= vlTOPp->ExUop__DOT__ixRegT;
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xfffffU & vlTOPp->ExUop__DOT__iImm) 
				   | (((0x80000U & vlTOPp->ExUop__DOT__uopWord)
				        ? 0xfffU : 0U) 
				      << 0x14U));
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xfff00000U & vlTOPp->ExUop__DOT__iImm) 
				   | (0xfffffU & vlTOPp->ExUop__DOT__uopWord));
			}
		    } else {
			vlTOPp->ExUop__DOT__iRegD = vlTOPp->ExUop__DOT__ixRegD;
			vlTOPp->ExUop__DOT__iRegS = vlTOPp->ExUop__DOT__ixRegS;
			vlTOPp->ExUop__DOT__iRegT = vlTOPp->ExUop__DOT__ixRegT;
			vlTOPp->ExUop__DOT__iImm = vlTOPp->ExUop__DOT__ixImm;
		    }
		}
		vlTOPp->ExUop__DOT__iDataAluS = (IData)(vlTOPp->ExUop__DOT__iDataS);
		vlTOPp->ExUop__DOT__iDataAluT = (IData)(vlTOPp->ExUop__DOT__iDataT);
		if ((0x5fU == (IData)(vlTOPp->ExUop__DOT__iRegS))) {
		    vlTOPp->ExUop__DOT__iDataAluS = 0U;
		}
		if ((0x5eU == (IData)(vlTOPp->ExUop__DOT__iRegT))) {
		    vlTOPp->ExUop__DOT__iDataAluT = vlTOPp->ExUop__DOT__iImm;
		}
		vlTOPp->ExUop__DOT__tData2D = vlTOPp->ExUop__DOT__iDataD;
		vlTOPp->ExUop__DOT__tIsWr2D = 0U;
		vlTOPp->ExUop__DOT__regNextSr = vlTOPp->ExUop__DOT__regs__DOT__reg_sr;
		vlTOPp->ExUop__DOT__regNextPr = vlTOPp->ExUop__DOT__regs__DOT__reg_pr;
		vlTOPp->ExUop__DOT__tIdReg2D = vlTOPp->ExUop__DOT__iRegD;
		vlTOPp->ExUop__DOT__aguHasIndex = (0xfU 
						   != 
						   (0xfU 
						    & (IData)(vlTOPp->ExUop__DOT__iRegT)));
		vlTOPp->ExUop__DOT__aluCmd = 0U;
		vlTOPp->ExUop__DOT__aguCmd = 0U;
		vlTOPp->ExUop__DOT__memCmd = 0U;
		vlTOPp->ExUop__DOT__fpuCmd = 0U;
		VL_WRITEF("Uop Cmd %x\n",8,vlTOPp->ExUop__DOT__uopCmd);
		if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
			      >> 7U)))) {
		    if ((0x40U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
				      >> 5U)))) {
			    if ((0x10U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
				if ((0U == (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd)))) {
				    if (VL_UNLIKELY(
						    (0U 
						     == 
						     ((1U 
						       & vlTOPp->ExUop__DOT__regs__DOT__reg_sr) 
						      ^ 
						      (1U 
						       & (vlTOPp->ExUop__DOT__uopWord 
							  >> 0x10U)))))) {
					vlTOPp->ExUop__DOT__regNextPc 
					    = (vlTOPp->ExUop__DOT__regPrPc 
					       + (vlTOPp->ExUop__DOT__iDataAluT 
						  << 1U));
					vlTOPp->ExUop__DOT__tNextPipeFlush = 2U;
					vlTOPp->ExUop__DOT__tNextPipeDsFlush 
					    = (1U & 
					       (vlTOPp->ExUop__DOT__uopWord 
						>> 0x11U));
					VL_WRITEF("3E BRTF PC=%x -> %x (Disp=%x)\n",
						  32,
						  vlTOPp->ExUop__DOT__regPrPc,
						  32,
						  vlTOPp->ExUop__DOT__regNextPc,
						  32,
						  vlTOPp->ExUop__DOT__iDataAluT);
				    }
				} else {
				    vlTOPp->ExUop__DOT__fpuCmd 
					= (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tData2D 
					= vlTOPp->ExUop__DOT__fpu1__DOT__tDst2;
				    vlTOPp->ExUop__DOT__tIsWr2D = 1U;
				    if (((0xaU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					 | (0xbU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)))) {
					vlTOPp->ExUop__DOT__tIsWr2D = 0U;
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((1U 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0xfffffffeU 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (1U 
						  & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)));
				    }
				}
			    } else {
				if ((0U != (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd)))) {
				    vlTOPp->ExUop__DOT__fpuCmd 
					= (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tData2D 
					= vlTOPp->ExUop__DOT__fpu1__DOT__tDst2;
				    vlTOPp->ExUop__DOT__tIsWr2D = 1U;
				    if (((0xaU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					 | (0xbU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)))) {
					vlTOPp->ExUop__DOT__tIsWr2D = 0U;
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((1U 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0xfffffffeU 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (1U 
						  & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)));
				    }
				}
			    }
			}
		    } else {
			if ((0x20U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
			    if ((0x10U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
				if (VL_UNLIKELY((0U 
						 == 
						 (0xfU 
						  & (IData)(vlTOPp->ExUop__DOT__uopCmd))))) {
				    vlTOPp->ExUop__DOT__regNextPr 
					= vlTOPp->ExUop__DOT__regPrNextPc;
				    vlTOPp->ExUop__DOT__tNextPipeFlush = 2U;
				    vlTOPp->ExUop__DOT__regNextPc 
					= (vlTOPp->ExUop__DOT__regPrNextPc 
					   + (vlTOPp->ExUop__DOT__iDataAluT 
					      << 1U));
				    VL_WRITEF("3E BSR PC=%x -> %x (Disp=%x)\n",
					      32,vlTOPp->ExUop__DOT__regPrPc,
					      32,vlTOPp->ExUop__DOT__regNextPc,
					      32,vlTOPp->ExUop__DOT__iDataAluT);
				} else {
				    vlTOPp->ExUop__DOT__aguCmd 
					= (7U & ((0U 
						  == (IData)(vlTOPp->ExUop__DOT__iRegT))
						  ? 1U
						  : (IData)(vlTOPp->ExUop__DOT__uopCmd)));
				    vlTOPp->ExUop__DOT__memAddr 
					= vlTOPp->ExUop__DOT__tDataAguD;
				    vlTOPp->ExUop__DOT__memWrValue 
					= vlTOPp->ExUop__DOT__iDataD;
				    vlTOPp->ExUop__DOT__tData2D 
					= vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue;
				    vlTOPp->ExUop__DOT__memCmd 
					= (7U & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tIsWr2D 
					= (1U & ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
						 >> 3U));
				    if ((8U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
					vlTOPp->ExUop__DOT__memRd = 0U;
					vlTOPp->ExUop__DOT__memWr = 1U;
				    } else {
					vlTOPp->ExUop__DOT__memRd = 1U;
					vlTOPp->ExUop__DOT__memWr = 0U;
				    }
				}
			    } else {
				if (VL_UNLIKELY((0U 
						 == 
						 (0xfU 
						  & (IData)(vlTOPp->ExUop__DOT__uopCmd))))) {
				    vlTOPp->ExUop__DOT__regNextPc 
					= (vlTOPp->ExUop__DOT__regPrPc 
					   + (vlTOPp->ExUop__DOT__iDataAluT 
					      << 1U));
				    vlTOPp->ExUop__DOT__tNextPipeFlush = 2U;
				    VL_WRITEF("3E BRA PC=%x -> %x (Disp=%x)\n",
					      32,vlTOPp->ExUop__DOT__regPrPc,
					      32,vlTOPp->ExUop__DOT__regNextPc,
					      32,vlTOPp->ExUop__DOT__iDataAluT);
				} else {
				    vlTOPp->ExUop__DOT__aguCmd 
					= (7U & ((0U 
						  == (IData)(vlTOPp->ExUop__DOT__iRegT))
						  ? 1U
						  : (IData)(vlTOPp->ExUop__DOT__uopCmd)));
				    vlTOPp->ExUop__DOT__tData2D 
					= (QData)((IData)(vlTOPp->ExUop__DOT__tDataAguD));
				    vlTOPp->ExUop__DOT__tIsWr2D = 1U;
				    if ((8U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
					vlTOPp->ExUop__DOT__tIdReg2D 
					    = vlTOPp->ExUop__DOT__iRegS;
					vlTOPp->ExUop__DOT__aguHasIndex = 0U;
				    }
				}
			    }
			} else {
			    if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
					  >> 4U)))) {
				if (VL_LIKELY((0U == 
					       (0xfU 
						& (IData)(vlTOPp->ExUop__DOT__uopCmd))))) {
				    vlTOPp->ExUop__DOT__uopNextPcLive = 0U;
				} else {
				    vlTOPp->ExUop__DOT__aluCmd 
					= (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tData2D 
					= (QData)((IData)(vlTOPp->ExUop__DOT__alu1__DOT__tDst));
				    vlTOPp->ExUop__DOT__tIsWr2D 
					= (0xbU > (IData)(vlTOPp->ExUop__DOT__aluCmd));
				    if ((0xaU <= (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((1U 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0xfffffffeU 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (1U 
						  & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)));
				    }
				    VL_WRITEF("EX ALU.L Op=%x D=%x(%x) S=%x(%x) T=%x(%x) -> %x\n",
					      4,vlTOPp->ExUop__DOT__aluCmd,
					      7,(IData)(vlTOPp->ExUop__DOT__iRegD),
					      64,vlTOPp->ExUop__DOT__iDataD,
					      7,(IData)(vlTOPp->ExUop__DOT__iRegS),
					      32,vlTOPp->ExUop__DOT__iDataAluS,
					      7,(IData)(vlTOPp->ExUop__DOT__iRegT),
					      32,vlTOPp->ExUop__DOT__iDataAluT,
					      32,vlTOPp->ExUop__DOT__alu1__DOT__tDst);
				}
			    }
			}
		    }
		}
		if ((0x40U == (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
		    if ((0U == (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 0xcU)))) {
			if ((8U == (0xfU & vlTOPp->ExUop__DOT__uopWord))) {
			    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
					  >> 7U)))) {
				if ((0x40U & vlTOPp->ExUop__DOT__uopWord)) {
				    if ((0x20U & vlTOPp->ExUop__DOT__uopWord)) {
					if ((1U & (~ 
						   (vlTOPp->ExUop__DOT__uopWord 
						    >> 4U)))) {
					    vlTOPp->ExUop__DOT__regNextSr 
						= (
						   (0xfffffffeU 
						    & vlTOPp->ExUop__DOT__regNextSr) 
						   | (1U 
						      & (~ vlTOPp->ExUop__DOT__regs__DOT__reg_sr)));
					}
				    } else {
					if ((0x10U 
					     & vlTOPp->ExUop__DOT__uopWord)) {
					    if ((0x800U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (2U 
						     | vlTOPp->ExUop__DOT__regNextSr);
					    } else {
						if (
						    (0x400U 
						     & vlTOPp->ExUop__DOT__uopWord)) {
						    vlTOPp->ExUop__DOT__regNextSr 
							= 
							(2U 
							 | vlTOPp->ExUop__DOT__regNextSr);
						} else {
						    if (
							(0x200U 
							 & vlTOPp->ExUop__DOT__uopWord)) {
							if (
							    (0x100U 
							     & vlTOPp->ExUop__DOT__uopWord)) {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x80000000U 
								 | vlTOPp->ExUop__DOT__regNextSr);
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x1000U 
								 | vlTOPp->ExUop__DOT__regNextSr);
							} else {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x80000000U 
								 | vlTOPp->ExUop__DOT__regNextSr);
							}
						    } else {
							vlTOPp->ExUop__DOT__regNextSr 
							    = 
							    ((0x100U 
							      & vlTOPp->ExUop__DOT__uopWord)
							      ? 
							     (0x1000U 
							      | vlTOPp->ExUop__DOT__regNextSr)
							      : 
							     (2U 
							      | vlTOPp->ExUop__DOT__regNextSr));
						    }
						}
					    }
					} else {
					    if ((0x800U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffffdU 
						     & vlTOPp->ExUop__DOT__regNextSr);
					    } else {
						if (
						    (0x400U 
						     & vlTOPp->ExUop__DOT__uopWord)) {
						    vlTOPp->ExUop__DOT__regNextSr 
							= 
							(0xfffffffdU 
							 & vlTOPp->ExUop__DOT__regNextSr);
						} else {
						    if (
							(0x200U 
							 & vlTOPp->ExUop__DOT__uopWord)) {
							if (
							    (0x100U 
							     & vlTOPp->ExUop__DOT__uopWord)) {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x7fffffffU 
								 & vlTOPp->ExUop__DOT__regNextSr);
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0xffffefffU 
								 & vlTOPp->ExUop__DOT__regNextSr);
							} else {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x7fffffffU 
								 & vlTOPp->ExUop__DOT__regNextSr);
							}
						    } else {
							vlTOPp->ExUop__DOT__regNextSr 
							    = 
							    ((0x100U 
							      & vlTOPp->ExUop__DOT__uopWord)
							      ? 
							     (0xffffefffU 
							      & vlTOPp->ExUop__DOT__regNextSr)
							      : 
							     (0xfffffffdU 
							      & vlTOPp->ExUop__DOT__regNextSr));
						    }
						}
					    }
					}
				    }
				} else {
				    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
						  >> 5U)))) {
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0x10U 
						& vlTOPp->ExUop__DOT__uopWord)
					        ? (1U 
						   | vlTOPp->ExUop__DOT__regNextSr)
					        : (0xfffffffeU 
						   & vlTOPp->ExUop__DOT__regNextSr));
				    }
				}
			    }
			} else {
			    if ((9U == (0xfU & vlTOPp->ExUop__DOT__uopWord))) {
				if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
					      >> 7U)))) {
				    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
						  >> 6U)))) {
					if ((0x20U 
					     & vlTOPp->ExUop__DOT__uopWord)) {
					    if ((0x10U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    ((0xfffffffeU 
						      & vlTOPp->ExUop__DOT__regNextSr) 
						     | (1U 
							& (IData)(vlTOPp->ExUop__DOT__iDataT)));
					    } else {
						vlTOPp->ExUop__DOT__tData2D = VL_ULL(0);
						vlTOPp->ExUop__DOT__tData2D 
						    = 
						    ((VL_ULL(0xfffffffffffffffe) 
						      & vlTOPp->ExUop__DOT__tData2D) 
						     | (IData)((IData)(
								       (1U 
									& vlTOPp->ExUop__DOT__regs__DOT__reg_sr))));
					    }
					} else {
					    if ((0x10U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffffeU 
						     & vlTOPp->ExUop__DOT__regNextSr);
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffeffU 
						     & vlTOPp->ExUop__DOT__regNextSr);
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffdffU 
						     & vlTOPp->ExUop__DOT__regNextSr);
					    }
					}
				    }
				}
			    } else {
				if ((0xbU == (0xfU 
					      & vlTOPp->ExUop__DOT__uopWord))) {
				    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
						  >> 7U)))) {
					if ((1U & (~ 
						   (vlTOPp->ExUop__DOT__uopWord 
						    >> 6U)))) {
					    if ((1U 
						 & (~ 
						    (vlTOPp->ExUop__DOT__uopWord 
						     >> 5U)))) {
						if (
						    (1U 
						     & (~ 
							(vlTOPp->ExUop__DOT__uopWord 
							 >> 4U)))) {
						    vlTOPp->ExUop__DOT__regNextPc 
							= vlTOPp->ExUop__DOT__regs__DOT__reg_pr;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	VL_WRITEF("Reset\n");
    }
}

void VExUop::_settle__TOP__7(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__7\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign260[4];
    VL_SIGW(__Vtemp3,95,0,3);
    //char	__VpadToAlign276[4];
    VL_SIGW(__Vtemp4,95,0,3);
    // Body
    // ALWAYS at ExUop.v:287
    if (VL_LIKELY(vlTOPp->ExUop__DOT__tResetOK)) {
	if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->ExUop__DOT__tResetOK)) 
			       & (~ (IData)(vlTOPp->ExUop__DOT__memHold)))))) {
	    VL_WRITEF("Hold\n");
	} else {
	    if (VL_UNLIKELY(((~ (IData)(vlTOPp->ExUop__DOT__memHold)) 
			     & (IData)(vlTOPp->ExUop__DOT__tResetOK)))) {
		if (VL_LIKELY(vlTOPp->ExUop__DOT__uopPcLive)) {
		    vlTOPp->ExUop__DOT__idNextInstWord 
			= vlTOPp->ExUop__DOT__idInstWord;
		} else {
		    vlTOPp->ExUop__DOT__idNextInstWord 
			= (IData)(vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue);
		    VL_WRITEF("1F: PC=%x Op=%x\n",32,
			      vlTOPp->ExUop__DOT__ifRegPc,
			      32,vlTOPp->ExUop__DOT__idNextInstWord);
		    vlTOPp->ExUop__DOT__idRegNextPc 
			= vlTOPp->ExUop__DOT__ifRegPc;
		    if ((VL_ULL(0) == vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue)) {
			vlTOPp->ExUop__DOT__idNextInstWord = 0xffffffffU;
		    }
		}
		vlTOPp->ExUop__DOT__iDataFpuD = vlTOPp->ExUop__DOT__iDataD;
		vlTOPp->ExUop__DOT__iDataFpuS = vlTOPp->ExUop__DOT__iDataS;
		vlTOPp->ExUop__DOT__iDataFpuT = vlTOPp->ExUop__DOT__iDataT;
		vlTOPp->ExUop__DOT__tIsQw2D = 0U;
		vlTOPp->ExUop__DOT__fpuOpFp32 = 0U;
		vlTOPp->ExUop__DOT__tRegStepPc = (7U 
						  & vlTOPp->ExUop__DOT__tRegStepPc);
		vlTOPp->ExUop__DOT__tRegStepPc = ((0xfffffff9U 
						   & vlTOPp->ExUop__DOT__tRegStepPc) 
						  | ((IData)(vlTOPp->ExUop__DOT__idStepPc) 
						     << 1U));
		vlTOPp->ExUop__DOT__tRegStepPc = (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__tRegStepPc);
		if (VL_UNLIKELY((1U < (IData)(vlTOPp->ExUop__DOT__tPipeFlush)))) {
		    VL_WRITEF("2D-0/F: PC=%x Op=%x St=%x\n",
			      32,vlTOPp->ExUop__DOT__idRegPc,
			      32,vlTOPp->ExUop__DOT__idInstWord,
			      2,(IData)(vlTOPp->ExUop__DOT__idStepPc));
		    vlTOPp->ExUop__DOT__regNextPc = vlTOPp->ExUop__DOT__regs__DOT__reg_pc;
		    vlTOPp->ExUop__DOT__regPrNextPc 
			= ((IData)(4U) + vlTOPp->ExUop__DOT__regs__DOT__reg_pc);
		    vlTOPp->ExUop__DOT__uopNextPc = 0U;
		    vlTOPp->ExUop__DOT__uopNextWord 
			= vlTOPp->ExUop__DOT__idUopWord;
		    vlTOPp->ExUop__DOT__ixRegNextPc 
			= vlTOPp->ExUop__DOT__idRegPc;
		    VL_WRITEF("2D-1/F: uPC=000 uOp=%x\n",
			      32,vlTOPp->ExUop__DOT__idUopWord);
		} else {
		    if (VL_LIKELY(vlTOPp->ExUop__DOT__uopPcLive)) {
			if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->ExUop__DOT__memHold))))) {
			    VL_WRITEF("2D-2 uPC=000 uOp=%x\n",
				      32,vlTOPp->ExUop__DOT__idUopWord);
			}
			vlTOPp->ExUop__DOT__regNextPc 
			    = vlTOPp->ExUop__DOT__regs__DOT__reg_pc;
			vlTOPp->ExUop__DOT__regPrNextPc 
			    = ((IData)(4U) + vlTOPp->ExUop__DOT__regs__DOT__reg_pc);
		    } else {
			VL_WRITEF("2D-0: PC=%x Op=%x St=%x\n",
				  32,vlTOPp->ExUop__DOT__idRegPc,
				  32,vlTOPp->ExUop__DOT__idInstWord,
				  2,(IData)(vlTOPp->ExUop__DOT__idStepPc));
			vlTOPp->ExUop__DOT__uopNextPc = 0U;
			vlTOPp->ExUop__DOT__uopNextWord 
			    = vlTOPp->ExUop__DOT__idUopWord;
			vlTOPp->ExUop__DOT__regNextPc 
			    = (vlTOPp->ExUop__DOT__ifRegPc 
			       + vlTOPp->ExUop__DOT__tRegStepPc);
			vlTOPp->ExUop__DOT__ixRegNextPc 
			    = vlTOPp->ExUop__DOT__idRegPc;
			VL_WRITEF("2D-1: uPC=000 uOp=%x\n",
				  32,vlTOPp->ExUop__DOT__idUopWord);
			vlTOPp->ExUop__DOT__regPrNextPc 
			    = (vlTOPp->ExUop__DOT__ifRegPc 
			       + vlTOPp->ExUop__DOT__tRegStepPc);
			if (VL_UNLIKELY((0xffffffffU 
					 == vlTOPp->ExUop__DOT__idInstWord))) {
			    vl_finish("ExUop.v",344,"");
			}
		    }
		}
		vlTOPp->ExUop__DOT__uopCmd = (0xffU 
					      & (vlTOPp->ExUop__DOT__uopWord 
						 >> 0x18U));
		if ((0U != (IData)(vlTOPp->ExUop__DOT__tPipeFlush))) {
		    vlTOPp->ExUop__DOT__tNextPipeFlush 
			= (7U & ((IData)(vlTOPp->ExUop__DOT__tPipeFlush) 
				 - (IData)(1U)));
		    vlTOPp->ExUop__DOT__tNextPipeDsFlush 
			= vlTOPp->ExUop__DOT__tPipeDsFlush;
		} else {
		    vlTOPp->ExUop__DOT__tNextPipeFlush = 0U;
		    vlTOPp->ExUop__DOT__tNextPipeDsFlush = 0U;
		}
		VL_WRITEF("3E-0: PC=%x\n",32,vlTOPp->ExUop__DOT__ixRegPc);
		VL_WRITEF("3E-1 uPC=%x uOp=%x\n",12,
			  vlTOPp->ExUop__DOT__uopPc,
			  32,vlTOPp->ExUop__DOT__uopWord);
		if ((0x800000U & vlTOPp->ExUop__DOT__uopWord)) {
		    vlTOPp->ExUop__DOT__uopNextPc = 
			(0xfffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__uopPc)));
		    vlTOPp->ExUop__DOT__uopNextWord 
			= vlTOPp->ExUop__DOT__dec1__DOT__uopPgm
			[vlTOPp->ExUop__DOT__uopNextPc];
		    vlTOPp->ExUop__DOT__uopNextPcLive = 1U;
		} else {
		    vlTOPp->ExUop__DOT__uopNextPcLive = 0U;
		}
		if ((0U != (IData)(vlTOPp->ExUop__DOT__tPipeFlush))) {
		    vlTOPp->ExUop__DOT__uopNextPcLive = 0U;
		}
		if ((0x400000U & vlTOPp->ExUop__DOT__uopWord)) {
		    if ((0x200000U & vlTOPp->ExUop__DOT__uopWord)) {
			vlTOPp->ExUop__DOT__iRegD = 
			    (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegD));
			vlTOPp->ExUop__DOT__iRegS = 
			    (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegS));
			vlTOPp->ExUop__DOT__iRegT = 
			    (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegT));
			vlTOPp->ExUop__DOT__iImm = 
			    ((0xffU & vlTOPp->ExUop__DOT__iImm) 
			     | (((1U & ((vlTOPp->ExUop__DOT__uopWord 
					 >> 0x14U) 
					& (vlTOPp->ExUop__DOT__uopWord 
					   >> 7U)))
				  ? 0xffffffU : 0U) 
				<< 8U));
			vlTOPp->ExUop__DOT__iRegD = 
			    ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegD)) 
			     | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 0x10U)));
			vlTOPp->ExUop__DOT__iRegS = 
			    ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegS)) 
			     | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 0xcU)));
			vlTOPp->ExUop__DOT__iRegT = 
			    ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegT)) 
			     | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 8U)));
			vlTOPp->ExUop__DOT__iImm = 
			    ((0xffffff00U & vlTOPp->ExUop__DOT__iImm) 
			     | (0xffU & vlTOPp->ExUop__DOT__uopWord));
		    } else {
			vlTOPp->ExUop__DOT__iRegD = 
			    (0x7fU & (vlTOPp->ExUop__DOT__uopWord 
				      >> 0xeU));
			vlTOPp->ExUop__DOT__iRegS = 
			    (0x7fU & (vlTOPp->ExUop__DOT__uopWord 
				      >> 7U));
			vlTOPp->ExUop__DOT__iRegT = 
			    (0x7fU & vlTOPp->ExUop__DOT__uopWord);
			vlTOPp->ExUop__DOT__iImm = vlTOPp->ExUop__DOT__ixImm;
		    }
		} else {
		    if ((0x200000U & vlTOPp->ExUop__DOT__uopWord)) {
			if ((0x100000U & vlTOPp->ExUop__DOT__uopWord)) {
			    vlTOPp->ExUop__DOT__iRegS 
				= vlTOPp->ExUop__DOT__ixRegS;
			    vlTOPp->ExUop__DOT__iRegT 
				= vlTOPp->ExUop__DOT__ixRegT;
			    vlTOPp->ExUop__DOT__iRegD 
				= (0xfU & (IData)(vlTOPp->ExUop__DOT__iRegD));
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xffffU & vlTOPp->ExUop__DOT__iImm) 
				   | (((0x8000U & vlTOPp->ExUop__DOT__uopWord)
				        ? 0xffffU : 0U) 
				      << 0x10U));
			    vlTOPp->ExUop__DOT__iRegD 
				= ((0x70U & (IData)(vlTOPp->ExUop__DOT__iRegD)) 
				   | (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					      >> 0x10U)));
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xffff0000U & vlTOPp->ExUop__DOT__iImm) 
				   | (0xffffU & vlTOPp->ExUop__DOT__uopWord));
			} else {
			    vlTOPp->ExUop__DOT__iRegD 
				= vlTOPp->ExUop__DOT__ixRegD;
			    vlTOPp->ExUop__DOT__iRegS 
				= vlTOPp->ExUop__DOT__ixRegS;
			    vlTOPp->ExUop__DOT__iRegT 
				= vlTOPp->ExUop__DOT__ixRegT;
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xfffffU & vlTOPp->ExUop__DOT__iImm) 
				   | (((0x80000U & vlTOPp->ExUop__DOT__uopWord)
				        ? 0xfffU : 0U) 
				      << 0x14U));
			    vlTOPp->ExUop__DOT__iImm 
				= ((0xfff00000U & vlTOPp->ExUop__DOT__iImm) 
				   | (0xfffffU & vlTOPp->ExUop__DOT__uopWord));
			}
		    } else {
			vlTOPp->ExUop__DOT__iRegD = vlTOPp->ExUop__DOT__ixRegD;
			vlTOPp->ExUop__DOT__iRegS = vlTOPp->ExUop__DOT__ixRegS;
			vlTOPp->ExUop__DOT__iRegT = vlTOPp->ExUop__DOT__ixRegT;
			vlTOPp->ExUop__DOT__iImm = vlTOPp->ExUop__DOT__ixImm;
		    }
		}
		vlTOPp->ExUop__DOT__iDataAluS = (IData)(vlTOPp->ExUop__DOT__iDataS);
		vlTOPp->ExUop__DOT__iDataAluT = (IData)(vlTOPp->ExUop__DOT__iDataT);
		if ((0x5fU == (IData)(vlTOPp->ExUop__DOT__iRegS))) {
		    vlTOPp->ExUop__DOT__iDataAluS = 0U;
		}
		if ((0x5eU == (IData)(vlTOPp->ExUop__DOT__iRegT))) {
		    vlTOPp->ExUop__DOT__iDataAluT = vlTOPp->ExUop__DOT__iImm;
		}
		vlTOPp->ExUop__DOT__tData2D = vlTOPp->ExUop__DOT__iDataD;
		vlTOPp->ExUop__DOT__tIsWr2D = 0U;
		vlTOPp->ExUop__DOT__regNextSr = vlTOPp->ExUop__DOT__regs__DOT__reg_sr;
		vlTOPp->ExUop__DOT__regNextPr = vlTOPp->ExUop__DOT__regs__DOT__reg_pr;
		vlTOPp->ExUop__DOT__tIdReg2D = vlTOPp->ExUop__DOT__iRegD;
		vlTOPp->ExUop__DOT__aguHasIndex = (0xfU 
						   != 
						   (0xfU 
						    & (IData)(vlTOPp->ExUop__DOT__iRegT)));
		vlTOPp->ExUop__DOT__aluCmd = 0U;
		vlTOPp->ExUop__DOT__aguCmd = 0U;
		vlTOPp->ExUop__DOT__memCmd = 0U;
		vlTOPp->ExUop__DOT__fpuCmd = 0U;
		VL_WRITEF("Uop Cmd %x\n",8,vlTOPp->ExUop__DOT__uopCmd);
		if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
			      >> 7U)))) {
		    if ((0x40U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
				      >> 5U)))) {
			    if ((0x10U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
				if ((0U == (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd)))) {
				    if (VL_UNLIKELY(
						    (0U 
						     == 
						     ((1U 
						       & vlTOPp->ExUop__DOT__regs__DOT__reg_sr) 
						      ^ 
						      (1U 
						       & (vlTOPp->ExUop__DOT__uopWord 
							  >> 0x10U)))))) {
					vlTOPp->ExUop__DOT__regNextPc 
					    = (vlTOPp->ExUop__DOT__regPrPc 
					       + (vlTOPp->ExUop__DOT__iDataAluT 
						  << 1U));
					vlTOPp->ExUop__DOT__tNextPipeFlush = 2U;
					vlTOPp->ExUop__DOT__tNextPipeDsFlush 
					    = (1U & 
					       (vlTOPp->ExUop__DOT__uopWord 
						>> 0x11U));
					VL_WRITEF("3E BRTF PC=%x -> %x (Disp=%x)\n",
						  32,
						  vlTOPp->ExUop__DOT__regPrPc,
						  32,
						  vlTOPp->ExUop__DOT__regNextPc,
						  32,
						  vlTOPp->ExUop__DOT__iDataAluT);
				    }
				} else {
				    vlTOPp->ExUop__DOT__fpuCmd 
					= (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tData2D 
					= vlTOPp->ExUop__DOT__fpu1__DOT__tDst2;
				    vlTOPp->ExUop__DOT__tIsWr2D = 1U;
				    if (((0xaU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					 | (0xbU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)))) {
					vlTOPp->ExUop__DOT__tIsWr2D = 0U;
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((1U 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0xfffffffeU 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (1U 
						  & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)));
				    }
				}
			    } else {
				if ((0U != (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd)))) {
				    vlTOPp->ExUop__DOT__fpuCmd 
					= (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tData2D 
					= vlTOPp->ExUop__DOT__fpu1__DOT__tDst2;
				    vlTOPp->ExUop__DOT__tIsWr2D = 1U;
				    if (((0xaU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					 | (0xbU != (IData)(vlTOPp->ExUop__DOT__fpuCmd)))) {
					vlTOPp->ExUop__DOT__tIsWr2D = 0U;
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((1U 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0xfffffffeU 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (1U 
						  & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)));
				    }
				}
			    }
			}
		    } else {
			if ((0x20U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
			    if ((0x10U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
				if (VL_UNLIKELY((0U 
						 == 
						 (0xfU 
						  & (IData)(vlTOPp->ExUop__DOT__uopCmd))))) {
				    vlTOPp->ExUop__DOT__regNextPr 
					= vlTOPp->ExUop__DOT__regPrNextPc;
				    vlTOPp->ExUop__DOT__tNextPipeFlush = 2U;
				    vlTOPp->ExUop__DOT__regNextPc 
					= (vlTOPp->ExUop__DOT__regPrNextPc 
					   + (vlTOPp->ExUop__DOT__iDataAluT 
					      << 1U));
				    VL_WRITEF("3E BSR PC=%x -> %x (Disp=%x)\n",
					      32,vlTOPp->ExUop__DOT__regPrPc,
					      32,vlTOPp->ExUop__DOT__regNextPc,
					      32,vlTOPp->ExUop__DOT__iDataAluT);
				} else {
				    vlTOPp->ExUop__DOT__aguCmd 
					= (7U & ((0U 
						  == (IData)(vlTOPp->ExUop__DOT__iRegT))
						  ? 1U
						  : (IData)(vlTOPp->ExUop__DOT__uopCmd)));
				    vlTOPp->ExUop__DOT__memAddr 
					= vlTOPp->ExUop__DOT__tDataAguD;
				    vlTOPp->ExUop__DOT__memWrValue 
					= vlTOPp->ExUop__DOT__iDataD;
				    vlTOPp->ExUop__DOT__tData2D 
					= vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue;
				    vlTOPp->ExUop__DOT__memCmd 
					= (7U & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tIsWr2D 
					= (1U & ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
						 >> 3U));
				    if ((8U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
					vlTOPp->ExUop__DOT__memRd = 0U;
					vlTOPp->ExUop__DOT__memWr = 1U;
				    } else {
					vlTOPp->ExUop__DOT__memRd = 1U;
					vlTOPp->ExUop__DOT__memWr = 0U;
				    }
				}
			    } else {
				if (VL_UNLIKELY((0U 
						 == 
						 (0xfU 
						  & (IData)(vlTOPp->ExUop__DOT__uopCmd))))) {
				    vlTOPp->ExUop__DOT__regNextPc 
					= (vlTOPp->ExUop__DOT__regPrPc 
					   + (vlTOPp->ExUop__DOT__iDataAluT 
					      << 1U));
				    vlTOPp->ExUop__DOT__tNextPipeFlush = 2U;
				    VL_WRITEF("3E BRA PC=%x -> %x (Disp=%x)\n",
					      32,vlTOPp->ExUop__DOT__regPrPc,
					      32,vlTOPp->ExUop__DOT__regNextPc,
					      32,vlTOPp->ExUop__DOT__iDataAluT);
				} else {
				    vlTOPp->ExUop__DOT__aguCmd 
					= (7U & ((0U 
						  == (IData)(vlTOPp->ExUop__DOT__iRegT))
						  ? 1U
						  : (IData)(vlTOPp->ExUop__DOT__uopCmd)));
				    vlTOPp->ExUop__DOT__tData2D 
					= (QData)((IData)(vlTOPp->ExUop__DOT__tDataAguD));
				    vlTOPp->ExUop__DOT__tIsWr2D = 1U;
				    if ((8U & (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
					vlTOPp->ExUop__DOT__tIdReg2D 
					    = vlTOPp->ExUop__DOT__iRegS;
					vlTOPp->ExUop__DOT__aguHasIndex = 0U;
				    }
				}
			    }
			} else {
			    if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__uopCmd) 
					  >> 4U)))) {
				if (VL_LIKELY((0U == 
					       (0xfU 
						& (IData)(vlTOPp->ExUop__DOT__uopCmd))))) {
				    vlTOPp->ExUop__DOT__uopNextPcLive = 0U;
				} else {
				    vlTOPp->ExUop__DOT__aluCmd 
					= (0xfU & (IData)(vlTOPp->ExUop__DOT__uopCmd));
				    vlTOPp->ExUop__DOT__tData2D 
					= (QData)((IData)(vlTOPp->ExUop__DOT__alu1__DOT__tDst));
				    vlTOPp->ExUop__DOT__tIsWr2D 
					= (0xbU > (IData)(vlTOPp->ExUop__DOT__aluCmd));
				    if ((0xaU <= (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((1U 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (0xfffffffeU 
						  & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0xfffffffeU 
						& vlTOPp->ExUop__DOT__regNextSr) 
					       | (1U 
						  & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)));
				    }
				    VL_WRITEF("EX ALU.L Op=%x D=%x(%x) S=%x(%x) T=%x(%x) -> %x\n",
					      4,vlTOPp->ExUop__DOT__aluCmd,
					      7,(IData)(vlTOPp->ExUop__DOT__iRegD),
					      64,vlTOPp->ExUop__DOT__iDataD,
					      7,(IData)(vlTOPp->ExUop__DOT__iRegS),
					      32,vlTOPp->ExUop__DOT__iDataAluS,
					      7,(IData)(vlTOPp->ExUop__DOT__iRegT),
					      32,vlTOPp->ExUop__DOT__iDataAluT,
					      32,vlTOPp->ExUop__DOT__alu1__DOT__tDst);
				}
			    }
			}
		    }
		}
		if ((0x40U == (IData)(vlTOPp->ExUop__DOT__uopCmd))) {
		    if ((0U == (0xfU & (vlTOPp->ExUop__DOT__uopWord 
					>> 0xcU)))) {
			if ((8U == (0xfU & vlTOPp->ExUop__DOT__uopWord))) {
			    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
					  >> 7U)))) {
				if ((0x40U & vlTOPp->ExUop__DOT__uopWord)) {
				    if ((0x20U & vlTOPp->ExUop__DOT__uopWord)) {
					if ((1U & (~ 
						   (vlTOPp->ExUop__DOT__uopWord 
						    >> 4U)))) {
					    vlTOPp->ExUop__DOT__regNextSr 
						= (
						   (0xfffffffeU 
						    & vlTOPp->ExUop__DOT__regNextSr) 
						   | (1U 
						      & (~ vlTOPp->ExUop__DOT__regs__DOT__reg_sr)));
					}
				    } else {
					if ((0x10U 
					     & vlTOPp->ExUop__DOT__uopWord)) {
					    if ((0x800U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (2U 
						     | vlTOPp->ExUop__DOT__regNextSr);
					    } else {
						if (
						    (0x400U 
						     & vlTOPp->ExUop__DOT__uopWord)) {
						    vlTOPp->ExUop__DOT__regNextSr 
							= 
							(2U 
							 | vlTOPp->ExUop__DOT__regNextSr);
						} else {
						    if (
							(0x200U 
							 & vlTOPp->ExUop__DOT__uopWord)) {
							if (
							    (0x100U 
							     & vlTOPp->ExUop__DOT__uopWord)) {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x80000000U 
								 | vlTOPp->ExUop__DOT__regNextSr);
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x1000U 
								 | vlTOPp->ExUop__DOT__regNextSr);
							} else {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x80000000U 
								 | vlTOPp->ExUop__DOT__regNextSr);
							}
						    } else {
							vlTOPp->ExUop__DOT__regNextSr 
							    = 
							    ((0x100U 
							      & vlTOPp->ExUop__DOT__uopWord)
							      ? 
							     (0x1000U 
							      | vlTOPp->ExUop__DOT__regNextSr)
							      : 
							     (2U 
							      | vlTOPp->ExUop__DOT__regNextSr));
						    }
						}
					    }
					} else {
					    if ((0x800U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffffdU 
						     & vlTOPp->ExUop__DOT__regNextSr);
					    } else {
						if (
						    (0x400U 
						     & vlTOPp->ExUop__DOT__uopWord)) {
						    vlTOPp->ExUop__DOT__regNextSr 
							= 
							(0xfffffffdU 
							 & vlTOPp->ExUop__DOT__regNextSr);
						} else {
						    if (
							(0x200U 
							 & vlTOPp->ExUop__DOT__uopWord)) {
							if (
							    (0x100U 
							     & vlTOPp->ExUop__DOT__uopWord)) {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x7fffffffU 
								 & vlTOPp->ExUop__DOT__regNextSr);
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0xffffefffU 
								 & vlTOPp->ExUop__DOT__regNextSr);
							} else {
							    vlTOPp->ExUop__DOT__regNextSr 
								= 
								(0x7fffffffU 
								 & vlTOPp->ExUop__DOT__regNextSr);
							}
						    } else {
							vlTOPp->ExUop__DOT__regNextSr 
							    = 
							    ((0x100U 
							      & vlTOPp->ExUop__DOT__uopWord)
							      ? 
							     (0xffffefffU 
							      & vlTOPp->ExUop__DOT__regNextSr)
							      : 
							     (0xfffffffdU 
							      & vlTOPp->ExUop__DOT__regNextSr));
						    }
						}
					    }
					}
				    }
				} else {
				    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
						  >> 5U)))) {
					vlTOPp->ExUop__DOT__regNextSr 
					    = ((0x10U 
						& vlTOPp->ExUop__DOT__uopWord)
					        ? (1U 
						   | vlTOPp->ExUop__DOT__regNextSr)
					        : (0xfffffffeU 
						   & vlTOPp->ExUop__DOT__regNextSr));
				    }
				}
			    }
			} else {
			    if ((9U == (0xfU & vlTOPp->ExUop__DOT__uopWord))) {
				if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
					      >> 7U)))) {
				    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
						  >> 6U)))) {
					if ((0x20U 
					     & vlTOPp->ExUop__DOT__uopWord)) {
					    if ((0x10U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    ((0xfffffffeU 
						      & vlTOPp->ExUop__DOT__regNextSr) 
						     | (1U 
							& (IData)(vlTOPp->ExUop__DOT__iDataT)));
					    } else {
						vlTOPp->ExUop__DOT__tData2D = VL_ULL(0);
						vlTOPp->ExUop__DOT__tData2D 
						    = 
						    ((VL_ULL(0xfffffffffffffffe) 
						      & vlTOPp->ExUop__DOT__tData2D) 
						     | (IData)((IData)(
								       (1U 
									& vlTOPp->ExUop__DOT__regs__DOT__reg_sr))));
					    }
					} else {
					    if ((0x10U 
						 & vlTOPp->ExUop__DOT__uopWord)) {
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffffeU 
						     & vlTOPp->ExUop__DOT__regNextSr);
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffeffU 
						     & vlTOPp->ExUop__DOT__regNextSr);
						vlTOPp->ExUop__DOT__regNextSr 
						    = 
						    (0xfffffdffU 
						     & vlTOPp->ExUop__DOT__regNextSr);
					    }
					}
				    }
				}
			    } else {
				if ((0xbU == (0xfU 
					      & vlTOPp->ExUop__DOT__uopWord))) {
				    if ((1U & (~ (vlTOPp->ExUop__DOT__uopWord 
						  >> 7U)))) {
					if ((1U & (~ 
						   (vlTOPp->ExUop__DOT__uopWord 
						    >> 6U)))) {
					    if ((1U 
						 & (~ 
						    (vlTOPp->ExUop__DOT__uopWord 
						     >> 5U)))) {
						if (
						    (1U 
						     & (~ 
							(vlTOPp->ExUop__DOT__uopWord 
							 >> 4U)))) {
						    vlTOPp->ExUop__DOT__regNextPc 
							= vlTOPp->ExUop__DOT__regs__DOT__reg_pr;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	VL_WRITEF("Reset\n");
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa 
	= (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa 
	= ((0xf00U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)) 
	   | (0xffU & (IData)((vlTOPp->ExUop__DOT__iDataFpuD 
			       >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuD 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuD)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst);
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuD 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuD)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa 
	= (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa 
	= ((0xf00U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)) 
	   | (0xffU & (IData)((vlTOPp->ExUop__DOT__iDataFpuS 
			       >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuS 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuS)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst);
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuS 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuS)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp64FromInt.v:49
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc = 0U;
    if (vlTOPp->ExUop__DOT__fpuOpFp32) {
	if ((1U & (IData)((vlTOPp->ExUop__DOT__iDataFpuT 
			   >> 0x1fU)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)((~ (IData)(vlTOPp->ExUop__DOT__iDataFpuT)))));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)(vlTOPp->ExUop__DOT__iDataFpuT)));
	}
    } else {
	if ((1U & (IData)((vlTOPp->ExUop__DOT__iDataFpuT 
			   >> 0x3fU)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= (~ vlTOPp->ExUop__DOT__iDataFpuT);
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= vlTOPp->ExUop__DOT__iDataFpuT;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	}
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc = 0U;
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC = VL_ULL(0);
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc = 0U;
    } else {
	if ((0U == (0xfffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
				      >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E;
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		= vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B 
		= vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm;
	    if ((0U != (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
					>> 0x3cU))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		       >> 8U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(8U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U != (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x38U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		       >> 4U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(4U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x36U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		       >> 2U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x35U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		       >> 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa 
	= (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa 
	= ((0xf00U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)) 
	   | (0xffU & (IData)((vlTOPp->ExUop__DOT__iDataFpuT 
			       >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuT 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuT)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst);
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuT 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuT)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst);
	}
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i = (((IData)(vlTOPp->ExUop__DOT__fpuOpFp32) 
						| (0xcU 
						   == (IData)(vlTOPp->ExUop__DOT__fpuCmd))) 
					       & (0xfU 
						  != (IData)(vlTOPp->ExUop__DOT__fpuCmd)));
    // ALWAYS at ArithAlu.v:47
    if ((8U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      >= vlTOPp->ExUop__DOT__iDataAluT));
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      > vlTOPp->ExUop__DOT__iDataAluT));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      >= vlTOPp->ExUop__DOT__iDataAluT));
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      > vlTOPp->ExUop__DOT__iDataAluT));
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      == vlTOPp->ExUop__DOT__iDataAluT));
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((1U & vlTOPp->ExUop__DOT__regs__DOT__reg_sr)
			    ? ((IData)(1U) + (vlTOPp->ExUop__DOT__iDataAluS 
					      + vlTOPp->ExUop__DOT__iDataAluT))
			    : (vlTOPp->ExUop__DOT__iDataAluS 
			       + vlTOPp->ExUop__DOT__iDataAluT));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (1U & ((vlTOPp->ExUop__DOT__alu1__DOT__tDst 
				     ^ vlTOPp->ExUop__DOT__iDataAluS) 
				    >> 0x1fU)));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tShl 
			= (0x3fU & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((0x1fU >= (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    ? (vlTOPp->ExUop__DOT__iDataAluS 
			       >> (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    : 0U);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tShl 
			= (0x3fU & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((0x1fU >= (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    ? (vlTOPp->ExUop__DOT__iDataAluS 
			       >> (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    : 0U);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tShl 
			= (0x3fU & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((0x1fU >= (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    ? (vlTOPp->ExUop__DOT__iDataAluS 
			       << (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    : 0U);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   ^ vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   | vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   * vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   - vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   + vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst = 0U;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    }
	}
    }
    // ALWAYS at MemAlu.v:34
    vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr = (((IData)(vlTOPp->ExUop__DOT__aguHasIndex)
						 ? (IData)(vlTOPp->ExUop__DOT__iDataT)
						 : 0U) 
					       + vlTOPp->ExUop__DOT__iImm);
    vlTOPp->ExUop__DOT__agu1__DOT__tOutAddr = ((4U 
						& (IData)(vlTOPp->ExUop__DOT__aguCmd))
					        ? (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? vlTOPp->ExUop__DOT__iDataAluS
						     : 0U)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 4U))
						     : 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 3U))))
					        : (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 2U))
						     : 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 1U)))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr)
						     : 0U)));
    vlTOPp->ExUop__DOT__tDataAguD = vlTOPp->ExUop__DOT__agu1__DOT__tOutAddr;
    // ALWAYS at MemTile2.v:174
    vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2 = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss2 = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqStTile = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTile = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTileIdx = 0U;
    if (((IData)(vlTOPp->ExUop__DOT__memRd) | (IData)(vlTOPp->ExUop__DOT__memWr))) {
	vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr = vlTOPp->ExUop__DOT__memAddr;
	vlTOPp->ExUop__DOT__mem1__DOT__rdtShl = ((7U 
						  & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtShl)) 
						 | (0x18U 
						    & (vlTOPp->ExUop__DOT__memAddr 
						       << 3U)));
	vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
	    = ((IData)(0xfU) + vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr);
	vlTOPp->ExUop__DOT__mem1__DOT__rdtShl = (0x18U 
						 & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtShl));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx = (0x7ffU 
						   & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr 
						      >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx 
	    = (0x7ffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
			 >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr 
						   >> 6U)));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2 = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
						   >> 6U)));
	if (((((IData)(vlTOPp->ExUop__DOT__memRd) & 
	       (vlTOPp->ExUop__DOT__memAddr >> 0x1dU)) 
	      & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct))) 
	     & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileLastAct)))) {
	    vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss = 1U;
	}
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[0U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__dTile[vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[1U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__dTile[
	    (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx)))];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[2U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__dTile[
	    (0x7ffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx)))];
	if (vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss) {
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		= (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr 
				 >> 6U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		= (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			    >> 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile 
		= vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty
		[(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			   >> 4U))];
	} else {
	    if (vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		    = (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
				     >> 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
				>> 4U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile 
		    = vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty
		    [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
			       >> 4U))];
	    }
	}
	if ((1U & ((~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss)) 
		   & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2))))) {
	    if (vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTile) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqStTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		    = vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
		    [vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTileIdx];
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTileIdx;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 0U;
	    }
	    if (((IData)(vlTOPp->ExUop__DOT__memWr) 
		 & (vlTOPp->ExUop__DOT__memAddr >> 0x1dU))) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
				>> 4U));
	    }
	}
    }
    if (vlTOPp->ExUop__DOT__imemRd) {
	vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr = vlTOPp->ExUop__DOT__imemAddr;
	vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
	    = ((IData)(7U) + vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr);
	vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx = (0x7ffU 
						   & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr 
						      >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__iTileLimIdx 
	    = (0x7ffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
			 >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__iTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr 
						   >> 6U)));
	vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss2 = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__iTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileLimIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
						   >> 6U)));
	vlTOPp->ExUop__DOT__mem1__DOT__irdtShl = ((7U 
						   & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtShl)) 
						  | (0x18U 
						     & (vlTOPp->ExUop__DOT__imemAddr 
							<< 3U)));
	vlTOPp->ExUop__DOT__mem1__DOT__irdtShl = (0x18U 
						  & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtShl));
	if (vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss) {
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		= (0x3ffffffU & (vlTOPp->ExUop__DOT__imemAddr 
				 >> 6U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		= (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx) 
			    >> 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile = 0U;
	} else {
	    if (VL_LIKELY(vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss2)) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		    = (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
				     >> 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileLimIdx) 
				>> 4U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile = 0U;
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock[0U] 
		    = vlTOPp->ExUop__DOT__mem1__DOT__iTile
		    [vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock[1U] 
		    = vlTOPp->ExUop__DOT__mem1__DOT__iTile
		    [(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx)))];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock[2U] 
		    = vlTOPp->ExUop__DOT__mem1__DOT__iTile
		    [(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx)))];
		VL_SHIFTR_WWI(96,96,5, __Vtemp3, vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock, (IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtShl));
		vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[0U] 
		    = __Vtemp3[0U];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[1U] 
		    = __Vtemp3[1U];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[2U] 
		    = __Vtemp3[2U];
		vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue 
		    = (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[1U])) 
			<< 0x20U) | (QData)((IData)(
						    vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[0U])));
		VL_WRITEF("iTileRd A=%x Ix=%x,Sh=%x Val=%x\n",
			  32,vlTOPp->ExUop__DOT__imemAddr,
			  11,(IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx),
			  5,vlTOPp->ExUop__DOT__mem1__DOT__irdtShl,
			  64,vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue);
	    }
	}
    }
    if ((((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile) 
	  | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqStTile)) 
	 | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct))) {
	if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct) {
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0xfU & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx) 
		      << 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0x7f0U & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx));
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct 
		= vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct;
	    if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct) {
		vlTOPp->ExUop__DOT__mem1__DOT__extData__out__out0 
		    = vlTOPp->ExUop__DOT__mem1__DOT__dTile
		    [vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx];
	    }
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		= ((0xffffffc3U & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
		   | ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx) 
		      << 2U));
	    if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn) {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 0U;
	    }
	    if (vlTOPp->extNotReady) {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx 
		    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx;
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx 
		    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx)));
		if ((0U == (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx))) {
		    if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct) {
			if (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile) {
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
				= ((0x3fU & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
				   | (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
				      << 6U));
			} else {
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
			}
		    } else {
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 1U;
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 0U;
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
		    }
		}
	    }
	} else {
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0xfU & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx) 
		      << 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0x7f0U & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx));
	    if (((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile) 
		 | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqStTile))) {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = ((0x3fU & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
		       | (vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
			  [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx) 
				     >> 4U))] << 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = (0xffffffc0U & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr);
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = ((0x3fU & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
		       | (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
			  << 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = (0xffffffc0U & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr);
	    }
	}
    }
    if (vlTOPp->ExUop__DOT__mem1__DOT__resetAct) {
	vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile 
	    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetCurTile)));
	if ((0U == (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile))) {
	    vlTOPp->ExUop__DOT__mem1__DOT__resetNextAct = 0U;
	}
    } else {
	if (((IData)(vlTOPp->reset) | (0x1234U != (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetTOK)))) {
	    vlTOPp->ExUop__DOT__mem1__DOT__resetNextAct = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile = 0U;
	}
    }
    if (vlTOPp->ExUop__DOT__memRd) {
	VL_SHIFTR_WWI(96,96,5, __Vtemp4, vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock, (IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtShl));
	vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U] 
	    = __Vtemp4[0U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U] 
	    = __Vtemp4[1U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[2U] 
	    = __Vtemp4[2U];
	if ((4U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= (VL_ULL(0xffff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue);
		} else {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= (VL_ULL(0xff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue);
		}
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
		    = ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))
		        ? (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])))
		        : (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff00000000) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | ((QData)((IData)(((0x80000000U 
						& vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])
					        ? 0xffffffffU
					        : 0U))) 
			      << 0x20U));
		} else {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (((0x8000U & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffff)
			        : VL_ULL(0)) << 0x10U));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (((0x80U & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffffff)
			        : VL_ULL(0)) << 8U));
		} else {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])));
		}
	    }
	}
    }
    vlTOPp->ExUop__DOT__mem1__DOT__dTileOpWrOK = 0U;
    if ((((IData)(vlTOPp->ExUop__DOT__memWr) & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile))) 
	 & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct)))) {
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[0U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[1U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[2U];
	vlTOPp->ExUop__DOT__mem1__DOT__dTileOpWrOK = 1U;
	if ((4U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
	    if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__memCmd) 
			  >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->ExUop__DOT__memCmd)))) {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->ExUop__DOT__memWrValue);
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
			    = (IData)((vlTOPp->ExUop__DOT__memWrValue 
				       >> 0x20U));
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
				       << 8U)));
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				= ((0xffU & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     >> 0x18U)) 
				   | (0xffffff00U & 
				      ((IData)((vlTOPp->ExUop__DOT__memWrValue 
						>> 0x20U)) 
				       << 8U)));
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
				= ((0xffffff00U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U]) 
				   | (0xffU & ((IData)(
						       (vlTOPp->ExUop__DOT__memWrValue 
							>> 0x20U)) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				    = ((0xffffU & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						   >> 0x10U)) 
				       | (0xffff0000U 
					  & ((IData)(
						     (vlTOPp->ExUop__DOT__memWrValue 
						      >> 0x20U)) 
					     << 0x10U)));
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
				    = ((0xffff0000U 
					& vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U]) 
				       | (0xffffU & 
					  ((IData)(
						   (vlTOPp->ExUop__DOT__memWrValue 
						    >> 0x20U)) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
					= ((0xffffffU 
					    & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					       >> 8U)) 
					   | (0xff000000U 
					      & ((IData)(
							 (vlTOPp->ExUop__DOT__memWrValue 
							  >> 0x20U)) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
					= ((0xff000000U 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U]) 
					   | (0xffffffU 
					      & ((IData)(
							 (vlTOPp->ExUop__DOT__memWrValue 
							  >> 0x20U)) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->ExUop__DOT__memWrValue);
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
				       << 8U)));
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				= ((0xffffff00U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
				   | (0xffU & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				    = ((0xffff0000U 
					& vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
				       | (0xffffU & 
					  ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
					= ((0xff000000U 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
					   | (0xffffffU 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		} else {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = ((0xffff0000U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
			       | (0xffffU & (IData)(vlTOPp->ExUop__DOT__memWrValue)));
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xff0000ffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xffff00U & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						   << 8U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
					= ((0xffffff00U 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
					   | (0xffU 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = ((0xffffff00U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
			       | (0xffU & (IData)(vlTOPp->ExUop__DOT__memWrValue)));
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xffff00ffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xff00U & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 8U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xff00ffffU 
					& vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				}
			    }
			}
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void VExUop::_combo__TOP__8(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_combo__TOP__8\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp5,95,0,3);
    //char	__VpadToAlign324[4];
    VL_SIGW(__Vtemp6,95,0,3);
    // Body
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa 
	= (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa 
	= ((0xf00U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)) 
	   | (0xffU & (IData)((vlTOPp->ExUop__DOT__iDataFpuD 
			       >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuD 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuD)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst);
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuD 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuD)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa 
	= (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa 
	= ((0xf00U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)) 
	   | (0xffU & (IData)((vlTOPp->ExUop__DOT__iDataFpuS 
			       >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuS 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuS)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst);
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuS 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuS)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst);
	}
    }
    // ALWAYS at FpuFp64FromInt.v:49
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc = 0U;
    if (vlTOPp->ExUop__DOT__fpuOpFp32) {
	if ((1U & (IData)((vlTOPp->ExUop__DOT__iDataFpuT 
			   >> 0x1fU)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)((~ (IData)(vlTOPp->ExUop__DOT__iDataFpuT)))));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= (VL_ULL(0xffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2);
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= ((VL_ULL(0xffffffff00000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2) 
		   | (IData)((IData)(vlTOPp->ExUop__DOT__iDataFpuT)));
	}
    } else {
	if ((1U & (IData)((vlTOPp->ExUop__DOT__iDataFpuT 
			   >> 0x3fU)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= (~ vlTOPp->ExUop__DOT__iDataFpuT);
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		= vlTOPp->ExUop__DOT__iDataFpuT;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = 0x433U;
	}
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc = 0U;
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC = VL_ULL(0);
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc = 0U;
    } else {
	if ((0U == (0xfffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
				      >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E;
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		= vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2;
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B 
		= vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm;
	    if ((0U != (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
					>> 0x3cU))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B 
		       >> 8U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = (0x1fffU & ((IData)(8U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B;
	    }
	    if ((0U != (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
					>> 0x38U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C 
		       >> 4U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = (0x1fffU & ((IData)(4U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
				      >> 0x36U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D 
		       >> 2U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = (0x1fffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
			       >> 0x35U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E 
		       >> 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E;
		vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp32To64.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa 
	= (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa 
	= ((0xf00U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)) 
	   | (0xffU & (IData)((vlTOPp->ExUop__DOT__iDataFpuT 
			       >> 0x17U))));
    if ((0U == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst = VL_ULL(0);
    } else {
	if ((0xffU == (0xffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuT 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuT)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst);
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exb 
		= (0xfffU & ((IData)(0x380U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((1U & (IData)(
						    (vlTOPp->ExUop__DOT__iDataFpuT 
						     >> 0x1fU))))) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exb)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= ((VL_ULL(0xfff000001fffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst) 
		   | ((QData)((IData)((0x7fffffU & (IData)(vlTOPp->ExUop__DOT__iDataFpuT)))) 
		      << 0x1dU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst 
		= (VL_ULL(0xffffffffe0000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst);
	}
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i = (((IData)(vlTOPp->ExUop__DOT__fpuOpFp32) 
						| (0xcU 
						   == (IData)(vlTOPp->ExUop__DOT__fpuCmd))) 
					       & (0xfU 
						  != (IData)(vlTOPp->ExUop__DOT__fpuCmd)));
    // ALWAYS at ArithAlu.v:47
    if ((8U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      >= vlTOPp->ExUop__DOT__iDataAluT));
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      > vlTOPp->ExUop__DOT__iDataAluT));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      >= vlTOPp->ExUop__DOT__iDataAluT));
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      > vlTOPp->ExUop__DOT__iDataAluT));
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__iDataAluS;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (vlTOPp->ExUop__DOT__iDataAluS 
			      == vlTOPp->ExUop__DOT__iDataAluT));
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((1U & vlTOPp->ExUop__DOT__regs__DOT__reg_sr)
			    ? ((IData)(1U) + (vlTOPp->ExUop__DOT__iDataAluS 
					      + vlTOPp->ExUop__DOT__iDataAluT))
			    : (vlTOPp->ExUop__DOT__iDataAluS 
			       + vlTOPp->ExUop__DOT__iDataAluT));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((3U & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (0xcU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr));
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= ((0xeU & (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tSr)) 
			   | (1U & ((vlTOPp->ExUop__DOT__alu1__DOT__tDst 
				     ^ vlTOPp->ExUop__DOT__iDataAluS) 
				    >> 0x1fU)));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tShl 
			= (0x3fU & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((0x1fU >= (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    ? (vlTOPp->ExUop__DOT__iDataAluS 
			       >> (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    : 0U);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tShl 
			= (0x3fU & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((0x1fU >= (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    ? (vlTOPp->ExUop__DOT__iDataAluS 
			       >> (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    : 0U);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tShl 
			= (0x3fU & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= ((0x1fU >= (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    ? (vlTOPp->ExUop__DOT__iDataAluS 
			       << (IData)(vlTOPp->ExUop__DOT__alu1__DOT__tShl))
			    : 0U);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   ^ vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   | vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   & vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   * vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   - vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__aluCmd))) {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst 
			= (vlTOPp->ExUop__DOT__iDataAluS 
			   + vlTOPp->ExUop__DOT__iDataAluT);
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		} else {
		    vlTOPp->ExUop__DOT__alu1__DOT__tDst = 0U;
		    vlTOPp->ExUop__DOT__alu1__DOT__tSr 
			= (0xfU & vlTOPp->ExUop__DOT__regs__DOT__reg_sr);
		}
	    }
	}
    }
    // ALWAYS at MemAlu.v:34
    vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr = (((IData)(vlTOPp->ExUop__DOT__aguHasIndex)
						 ? (IData)(vlTOPp->ExUop__DOT__iDataT)
						 : 0U) 
					       + vlTOPp->ExUop__DOT__iImm);
    vlTOPp->ExUop__DOT__agu1__DOT__tOutAddr = ((4U 
						& (IData)(vlTOPp->ExUop__DOT__aguCmd))
					        ? (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? vlTOPp->ExUop__DOT__iDataAluS
						     : 0U)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 4U))
						     : 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 3U))))
					        : (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 2U))
						     : 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + 
						     (vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr 
						      << 1U)))
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__aguCmd))
						     ? 
						    (vlTOPp->ExUop__DOT__iDataAluS 
						     + vlTOPp->ExUop__DOT__agu1__DOT__tIdxAddr)
						     : 0U)));
    vlTOPp->ExUop__DOT__tDataAguD = vlTOPp->ExUop__DOT__agu1__DOT__tOutAddr;
    // ALWAYS at MemTile2.v:174
    vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2 = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss2 = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqStTile = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTile = 0U;
    vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTileIdx = 0U;
    if (((IData)(vlTOPp->ExUop__DOT__memRd) | (IData)(vlTOPp->ExUop__DOT__memWr))) {
	vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr = vlTOPp->ExUop__DOT__memAddr;
	vlTOPp->ExUop__DOT__mem1__DOT__rdtShl = ((7U 
						  & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtShl)) 
						 | (0x18U 
						    & (vlTOPp->ExUop__DOT__memAddr 
						       << 3U)));
	vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
	    = ((IData)(0xfU) + vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr);
	vlTOPp->ExUop__DOT__mem1__DOT__rdtShl = (0x18U 
						 & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtShl));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx = (0x7ffU 
						   & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr 
						      >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx 
	    = (0x7ffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
			 >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr 
						   >> 6U)));
	vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2 = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
						   >> 6U)));
	if (((((IData)(vlTOPp->ExUop__DOT__memRd) & 
	       (vlTOPp->ExUop__DOT__memAddr >> 0x1dU)) 
	      & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileDlyAct))) 
	     & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileLastAct)))) {
	    vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss = 1U;
	}
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[0U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__dTile[vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[1U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__dTile[
	    (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx)))];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[2U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__dTile[
	    (0x7ffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx)))];
	if (vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss) {
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		= (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddr 
				 >> 6U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		= (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			    >> 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile 
		= vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty
		[(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
			   >> 4U))];
	} else {
	    if (vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		    = (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__dMemAddrLim 
				     >> 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
				>> 4U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile 
		    = vlTOPp->ExUop__DOT__mem1__DOT__dTileBaseDty
		    [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileLimIdx) 
			       >> 4U))];
	    }
	}
	if ((1U & ((~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss)) 
		   & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileMiss2))))) {
	    if (vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTile) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqStTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		    = vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
		    [vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTileIdx];
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		    = vlTOPp->ExUop__DOT__mem1__DOT__reqSyncTileIdx;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 0U;
	    }
	    if (((IData)(vlTOPp->ExUop__DOT__memWr) 
		 & (vlTOPp->ExUop__DOT__memAddr >> 0x1dU))) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqNextSyncTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__dTileIdx) 
				>> 4U));
	    }
	}
    }
    if (vlTOPp->ExUop__DOT__imemRd) {
	vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr = vlTOPp->ExUop__DOT__imemAddr;
	vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
	    = ((IData)(7U) + vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr);
	vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx = (0x7ffU 
						   & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr 
						      >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__iTileLimIdx 
	    = (0x7ffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
			 >> 2U));
	vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__iTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddr 
						   >> 6U)));
	vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss2 = 
	    (vlTOPp->ExUop__DOT__mem1__DOT__iTileBase
	     [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileLimIdx) 
			>> 4U))] != (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
						   >> 6U)));
	vlTOPp->ExUop__DOT__mem1__DOT__irdtShl = ((7U 
						   & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtShl)) 
						  | (0x18U 
						     & (vlTOPp->ExUop__DOT__imemAddr 
							<< 3U)));
	vlTOPp->ExUop__DOT__mem1__DOT__irdtShl = (0x18U 
						  & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtShl));
	if (vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss) {
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		= (0x3ffffffU & (vlTOPp->ExUop__DOT__imemAddr 
				 >> 6U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		= (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx) 
			    >> 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile = 0U;
	} else {
	    if (VL_LIKELY(vlTOPp->ExUop__DOT__mem1__DOT__iTileMiss2)) {
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
		    = (0x3ffffffU & (vlTOPp->ExUop__DOT__mem1__DOT__iMemAddrLim 
				     >> 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx 
		    = (0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileLimIdx) 
				>> 4U));
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdITile = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile = 0U;
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock[0U] 
		    = vlTOPp->ExUop__DOT__mem1__DOT__iTile
		    [vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock[1U] 
		    = vlTOPp->ExUop__DOT__mem1__DOT__iTile
		    [(0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx)))];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock[2U] 
		    = vlTOPp->ExUop__DOT__mem1__DOT__iTile
		    [(0x7ffU & ((IData)(2U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx)))];
		VL_SHIFTR_WWI(96,96,5, __Vtemp5, vlTOPp->ExUop__DOT__mem1__DOT__irdtTBlock, (IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtShl));
		vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[0U] 
		    = __Vtemp5[0U];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[1U] 
		    = __Vtemp5[1U];
		vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[2U] 
		    = __Vtemp5[2U];
		vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue 
		    = (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[1U])) 
			<< 0x20U) | (QData)((IData)(
						    vlTOPp->ExUop__DOT__mem1__DOT__irdtValue[0U])));
		VL_WRITEF("iTileRd A=%x Ix=%x,Sh=%x Val=%x\n",
			  32,vlTOPp->ExUop__DOT__imemAddr,
			  11,(IData)(vlTOPp->ExUop__DOT__mem1__DOT__iTileIdx),
			  5,vlTOPp->ExUop__DOT__mem1__DOT__irdtShl,
			  64,vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue);
	    }
	}
    }
    if ((((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile) 
	  | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqStTile)) 
	 | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct))) {
	if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct) {
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0xfU & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx) 
		      << 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0x7f0U & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx));
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct 
		= vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct;
	    if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct) {
		vlTOPp->ExUop__DOT__mem1__DOT__extData__out__out0 
		    = vlTOPp->ExUop__DOT__mem1__DOT__dTile
		    [vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx];
	    }
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		= ((0xffffffc3U & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
		   | ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx) 
		      << 2U));
	    if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileDn) {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 0U;
	    }
	    if (vlTOPp->extNotReady) {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx 
		    = vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx;
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx 
		    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx)));
		if ((0U == (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx))) {
		    if (vlTOPp->ExUop__DOT__mem1__DOT__ldTileStAct) {
			if (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile) {
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
				= ((0x3fU & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
				   | (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
				      << 6U));
			} else {
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 1U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 0U;
			    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
			}
		    } else {
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 1U;
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 0U;
			vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
		    }
		}
	    }
	} else {
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextWIdx = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextDn = 0U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextAct = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0xfU & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileIdx) 
		      << 4U));
	    vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx 
		= ((0x7f0U & (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx)) 
		   | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileWIdx));
	    if (((IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdSTile) 
		 | (IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqStTile))) {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = ((0x3fU & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
		       | (vlTOPp->ExUop__DOT__mem1__DOT__dTileBase
			  [(0x7fU & ((IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileIdx) 
				     >> 4U))] << 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = (0xffffffc0U & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr);
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextStAct = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtOE = 1U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileNextExtWR = 0U;
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = ((0x3fU & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr) 
		       | (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTileBaseLo 
			  << 6U));
		vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr 
		    = (0xffffffc0U & vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr);
	    }
	}
    }
    if (vlTOPp->ExUop__DOT__mem1__DOT__resetAct) {
	vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile 
	    = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetCurTile)));
	if ((0U == (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile))) {
	    vlTOPp->ExUop__DOT__mem1__DOT__resetNextAct = 0U;
	}
    } else {
	if (((IData)(vlTOPp->reset) | (0x1234U != (IData)(vlTOPp->ExUop__DOT__mem1__DOT__resetTOK)))) {
	    vlTOPp->ExUop__DOT__mem1__DOT__resetNextAct = 1U;
	    vlTOPp->ExUop__DOT__mem1__DOT__resetNextTile = 0U;
	}
    }
    if (vlTOPp->ExUop__DOT__memRd) {
	VL_SHIFTR_WWI(96,96,5, __Vtemp6, vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock, (IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtShl));
	vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U] 
	    = __Vtemp6[0U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U] 
	    = __Vtemp6[1U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[2U] 
	    = __Vtemp6[2U];
	if ((4U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= (VL_ULL(0xffff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue);
		} else {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= (VL_ULL(0xff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue);
		}
	    } else {
		vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
		    = ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))
		        ? (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])))
		        : (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff00000000) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | ((QData)((IData)(((0x80000000U 
						& vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])
					        ? 0xffffffffU
					        : 0U))) 
			      << 0x20U));
		} else {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffff0000) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (((0x8000U & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffff)
			        : VL_ULL(0)) << 0x10U));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xffffffffffffff00) 
			    & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (IData)((IData)((0xffU 
					      & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U]))));
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= ((VL_ULL(0xff) & vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue) 
			   | (((0x80U & vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])
			        ? VL_ULL(0xffffffffffffff)
			        : VL_ULL(0)) << 8U));
		} else {
		    vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue 
			= (((QData)((IData)(vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUop__DOT__mem1__DOT__rdtValue[0U])));
		}
	    }
	}
    }
    vlTOPp->ExUop__DOT__mem1__DOT__dTileOpWrOK = 0U;
    if ((((IData)(vlTOPp->ExUop__DOT__memWr) & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile))) 
	 & (~ (IData)(vlTOPp->ExUop__DOT__mem1__DOT__ldTileAct)))) {
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[0U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[1U];
	vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
	    = vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock[2U];
	vlTOPp->ExUop__DOT__mem1__DOT__dTileOpWrOK = 1U;
	if ((4U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
	    if ((1U & (~ ((IData)(vlTOPp->ExUop__DOT__memCmd) 
			  >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->ExUop__DOT__memCmd)))) {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->ExUop__DOT__memWrValue);
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
			    = (IData)((vlTOPp->ExUop__DOT__memWrValue 
				       >> 0x20U));
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
				       << 8U)));
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				= ((0xffU & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     >> 0x18U)) 
				   | (0xffffff00U & 
				      ((IData)((vlTOPp->ExUop__DOT__memWrValue 
						>> 0x20U)) 
				       << 8U)));
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
				= ((0xffffff00U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U]) 
				   | (0xffU & ((IData)(
						       (vlTOPp->ExUop__DOT__memWrValue 
							>> 0x20U)) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				    = ((0xffffU & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						   >> 0x10U)) 
				       | (0xffff0000U 
					  & ((IData)(
						     (vlTOPp->ExUop__DOT__memWrValue 
						      >> 0x20U)) 
					     << 0x10U)));
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
				    = ((0xffff0000U 
					& vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U]) 
				       | (0xffffU & 
					  ((IData)(
						   (vlTOPp->ExUop__DOT__memWrValue 
						    >> 0x20U)) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
					= ((0xffffffU 
					    & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					       >> 8U)) 
					   | (0xff000000U 
					      & ((IData)(
							 (vlTOPp->ExUop__DOT__memWrValue 
							  >> 0x20U)) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U] 
					= ((0xff000000U 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[2U]) 
					   | (0xffffffU 
					      & ((IData)(
							 (vlTOPp->ExUop__DOT__memWrValue 
							  >> 0x20U)) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = (IData)(vlTOPp->ExUop__DOT__memWrValue);
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xffffff00U & 
				      ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
				       << 8U)));
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				= ((0xffffff00U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
				   | (0xffU & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					       >> 0x18U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
				    = ((0xffff0000U 
					& vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
				       | (0xffffU & 
					  ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					   >> 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
					= ((0xff000000U 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
					   | (0xffffffU 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		} else {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = ((0xffff0000U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
			       | (0xffffU & (IData)(vlTOPp->ExUop__DOT__memWrValue)));
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xff0000ffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xffff00U & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						   << 8U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xffffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xffff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U] 
					= ((0xffffff00U 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[1U]) 
					   | (0xffU 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 >> 8U)));
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__memCmd))) {
		    if ((0U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
			    = ((0xffffff00U & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
			       | (0xffU & (IData)(vlTOPp->ExUop__DOT__memWrValue)));
		    } else {
			if ((1U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
			    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				= ((0xffff00ffU & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				   | (0xff00U & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 8U)));
			} else {
			    if ((2U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
				    = ((0xff00ffffU 
					& vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
				       | (0xff0000U 
					  & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
					     << 0x10U)));
			    } else {
				if ((3U == (3U & vlTOPp->ExUop__DOT__memAddr))) {
				    vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U] 
					= ((0xffffffU 
					    & vlTOPp->ExUop__DOT__mem1__DOT__rdtTBlock2[0U]) 
					   | (0xff000000U 
					      & ((IData)(vlTOPp->ExUop__DOT__memWrValue) 
						 << 0x18U)));
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA = ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i)
					      ? vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst
					      : vlTOPp->ExUop__DOT__iDataFpuS);
    vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB = ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i)
					      ? vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst
					      : vlTOPp->ExUop__DOT__iDataFpuT);
    vlTOPp->extAddr = vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr;
    vlTOPp->extData = vlTOPp->ExUop__DOT__mem1__DOT__extData__out__out0;
}

void VExUop::_settle__TOP__9(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__9\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA = ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i)
					      ? vlTOPp->ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst
					      : vlTOPp->ExUop__DOT__iDataFpuS);
    vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB = ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i)
					      ? vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst
					      : vlTOPp->ExUop__DOT__iDataFpuT);
    vlTOPp->extAddr = vlTOPp->ExUop__DOT__mem1__DOT__ldTileExtAddr;
    vlTOPp->extData = vlTOPp->ExUop__DOT__mem1__DOT__extData__out__out0;
    vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA = (((9U 
						== (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					       | (4U 
						  == (IData)(vlTOPp->ExUop__DOT__fpuCmd)))
					       ? ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i)
						   ? vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst
						   : vlTOPp->ExUop__DOT__iDataFpuD)
					       : vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA);
    // ALWAYS at FpuFp64B.v:125
    vlTOPp->ExUop__DOT__fpu1__DOT__tDst = vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB;
    // ALWAYS at FpuFp64ToInt.v:28
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__sgn 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa 
	= ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb 
	= (0xfffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa) 
		     - (IData)(0x433U)));
    if (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__sgn) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					     & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra) 
	       | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra) 
	       | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
    }
    if ((0x433U <= (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl 
	    = (0x3fU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
	    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	       << (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl 
	    = (0x3fU & VL_NEGATE_I((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb)));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
	    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	       >> (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl));
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst2 
	= ((IData)(vlTOPp->ExUop__DOT__fpuOpFp32) ? 
	   ((VL_ULL(0x1ffffffff) == (VL_ULL(0x1ffffffff) 
				     & (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
					>> 0x1fU)))
	     ? vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst
	     : ((VL_ULL(0) == (VL_ULL(0x1ffffffff) 
			       & (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
				  >> 0x1fU))) ? vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst
		 : VL_ULL(0x80000000))) : vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst);
    // ALWAYS at FpuFp64_Mul.v:46
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgna 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnb 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc 
	= ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgna) 
	   ^ (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnb));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA 
	= (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB 
	= (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA 
	= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA) 
	   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB 
	= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB) 
	   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
	= ((vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA 
	    >> 0x15U) * (vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB 
			 >> 0x15U));
    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
		       >> 0x3fU)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
					  >> 0xbU));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc 
	    = (0x1fffU & (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa) 
			   + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb)) 
			  - (IData)(0x3feU)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
					  >> 0xaU));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc 
	    = (0x1fffU & (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa) 
			   + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb)) 
			  - (IData)(0x3ffU)));
    }
    if ((0x1000U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2);
	}
    }
}

VL_INLINE_OPT void VExUop::_combo__TOP__10(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_combo__TOP__10\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA = (((9U 
						== (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					       | (4U 
						  == (IData)(vlTOPp->ExUop__DOT__fpuCmd)))
					       ? ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tOpFp32i)
						   ? vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst
						   : vlTOPp->ExUop__DOT__iDataFpuD)
					       : vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA);
    // ALWAYS at FpuFp64B.v:125
    vlTOPp->ExUop__DOT__fpu1__DOT__tDst = vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB;
    // ALWAYS at FpuFp64ToInt.v:28
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__sgn 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa 
	= ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb 
	= (0xfffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa) 
		     - (IData)(0x433U)));
    if (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__sgn) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					     & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra) 
	       | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra) 
	       | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
    }
    if ((0x433U <= (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl 
	    = (0x3fU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
	    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	       << (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl 
	    = (0x3fU & VL_NEGATE_I((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb)));
	vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
	    = (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra 
	       >> (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl));
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst2 
	= ((IData)(vlTOPp->ExUop__DOT__fpuOpFp32) ? 
	   ((VL_ULL(0x1ffffffff) == (VL_ULL(0x1ffffffff) 
				     & (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
					>> 0x1fU)))
	     ? vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst
	     : ((VL_ULL(0) == (VL_ULL(0x1ffffffff) 
			       & (vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst 
				  >> 0x1fU))) ? vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst
		 : VL_ULL(0x80000000))) : vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst);
    // ALWAYS at FpuFp64_Mul.v:46
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgna 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnb 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc 
	= ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgna) 
	   ^ (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnb));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA 
	= (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB 
	= (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA 
	= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA) 
	   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB 
	= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB) 
	   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
	= ((vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA 
	    >> 0x15U) * (vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB 
			 >> 0x15U));
    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
		       >> 0x3fU)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
					  >> 0xbU));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc 
	    = (0x1fffU & (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa) 
			   + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb)) 
			  - (IData)(0x3feU)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2 
	    = (VL_ULL(0xfffffffffffff) & (vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC 
					  >> 0xaU));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc 
	    = (0x1fffU & (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exa) 
			   + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exb)) 
			  - (IData)(0x3ffU)));
    }
    if ((0x1000U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst) 
		   | vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2);
	}
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB = (((9U 
						== (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					       | (4U 
						  == (IData)(vlTOPp->ExUop__DOT__fpuCmd)))
					       ? vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst
					       : vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB);
}

void VExUop::_settle__TOP__11(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__11\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB = (((9U 
						== (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
					       | (4U 
						  == (IData)(vlTOPp->ExUop__DOT__fpuCmd)))
					       ? vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst
					       : vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB);
    // ALWAYS at FpuFp64_Add.v:53
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgna 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnb 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm 
	= (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa) 
	    >= (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb))
	    ? (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa)
	    : (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb));
    if (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgna) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					     & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA) 
	       | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA) 
	       | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA));
    }
    if (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnb) 
	 ^ ((2U == (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
	    | (4U == (IData)(vlTOPp->ExUop__DOT__fpuCmd))))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					     & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB) 
	       | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB) 
	       | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB));
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA1 
	= ((0x3fU >= (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
				 - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa))))
	    ? (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	       >> (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
			      - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa))))
	    : VL_ULL(0));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB1 
	= ((0x3fU >= (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
				 - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb))))
	    ? (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	       >> (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
			      - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb))))
	    : VL_ULL(0));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1 
	= (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA1 
	   + vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB1);
    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1 
		       >> 0x3fU)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = 1U;
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
	    = (~ vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1);
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
	    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1;
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC = VL_ULL(0);
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc = 0U;
    } else {
	if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
				  >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E;
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
			       >> 0x35U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
		       >> 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC));
	}
    }
}

VL_INLINE_OPT void VExUop::_combo__TOP__12(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_combo__TOP__12\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp64_Add.v:53
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgna 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnb 
	= (1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB 
			 >> 0x3fU)));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb 
	= ((0x1800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm 
	= (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa) 
	    >= (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb))
	    ? (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa)
	    : (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb));
    if (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgna) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					     & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA) 
	       | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA) 
	       | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcA));
    }
    if (((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnb) 
	 ^ ((2U == (IData)(vlTOPp->ExUop__DOT__fpuCmd)) 
	    | (4U == (IData)(vlTOPp->ExUop__DOT__fpuCmd))))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = (VL_ULL(0xffe0000000000000) | (VL_ULL(0xfffffffffffff) 
					     & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB) 
	       | (VL_ULL(0xfffffffffffff) & (~ vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB)));
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = (VL_ULL(0x10000000000000) | (VL_ULL(0xfffffffffffff) 
					   & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	    = ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB) 
	       | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpaSrcB));
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA1 
	= ((0x3fU >= (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
				 - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa))))
	    ? (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA 
	       >> (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
			      - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exa))))
	    : VL_ULL(0));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB1 
	= ((0x3fU >= (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
				 - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb))))
	    ? (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB 
	       >> (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
			      - (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exb))))
	    : VL_ULL(0));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1 
	= (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA1 
	   + vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB1);
    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1 
		       >> 0x3fU)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = 1U;
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
	    = (~ vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1);
    } else {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
	    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1;
    }
    if ((VL_ULL(0) == (VL_ULL(0x1fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = 0U;
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC = VL_ULL(0);
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc = 0U;
    } else {
	if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
				  >> 0x34U))))) {
	    if ((0U == (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
				>> 0x15U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
		       << 0x20U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm) 
				  - (IData)(0x20U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm;
	    }
	    if ((0U == (0xffffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
					   >> 0x25U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A 
		       << 0x10U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A) 
				  - (IData)(0x10U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A;
	    }
	    if ((0U == (0xffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
					 >> 0x2dU))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B 
		       << 8U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B) 
				  - (IData)(8U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B;
	    }
	    if ((0U == (0xfU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
					>> 0x31U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C 
		       << 4U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C) 
				  - (IData)(4U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C;
	    }
	    if ((0U == (3U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
				      >> 0x33U))))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D 
		       << 2U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D) 
				  - (IData)(2U)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D;
	    }
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
			       >> 0x34U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E;
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E 
		       << 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E) 
				  - (IData)(1U)));
	    }
	} else {
	    if ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
			       >> 0x35U)))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = (vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 
		       >> 1U);
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm)));
	    } else {
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2;
		vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc 
		    = vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exm;
	    }
	}
    }
    if ((0x1000U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst = VL_ULL(0);
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= (VL_ULL(0x7ff0000000000000) | (VL_ULL(0x8000000000000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst));
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x7fffffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc)) 
		      << 0x3fU));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0x800fffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | ((QData)((IData)((0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__exc)))) 
		      << 0x34U));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst 
		= ((VL_ULL(0xfff0000000000000) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst) 
		   | (VL_ULL(0xfffffffffffff) & vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC));
	}
    }
    // ALWAYS at FpuFp64B.v:128
    if ((8U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__tDst = (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						     ? vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst
						     : vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst2)
						    : vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB);
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__tSro 
		    = ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
		        ? ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
					  >> 0x3fU)))
			    ? ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
					      >> 0x3fU)))
			        ? ((0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)) 
				   | ((VL_ULL(0x7fffffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA) 
				      < (VL_ULL(0x7fffffffffffffff) 
					 & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)))
			        : (0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)))
			    : ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
					      >> 0x3fU)))
			        ? (1U | (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro))
			        : ((0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)) 
				   | ((VL_ULL(0x7fffffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA) 
				      > (VL_ULL(0x7fffffffffffffff) 
					 & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)))))
		        : ((0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)) 
			   | (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
			      == vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)));
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst;
		} else {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x7fffffffffffffff) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | ((QData)((IData)((1U & (IData)(
							    (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
							     >> 0x3fU))))) 
			      << 0x3fU));
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & (VL_ULL(0x3ff0000000000000) 
				 + (VL_ULL(0x3fffffffffffffff) 
				    & ((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
					- VL_ULL(0x3ff0000000000000)) 
				       >> 1U)))));
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x7fffffffffffffff) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | ((QData)((IData)((1U & (IData)(
							    (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
							     >> 0x3fU))))) 
			      << 0x3fU));
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & (VL_ULL(0x3ff0000000000000) 
				 + VL_NEGATE_Q((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
						- VL_ULL(0x3ff0000000000000))))));
		} else {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x7fffffffffffffff) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | ((QData)((IData)((1U & 
					       (~ (IData)(
							  (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
							   >> 0x3fU)))))) 
			      << 0x3fU));
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= (VL_ULL(0x7fffffffffffffff) 
			   & vlTOPp->ExUop__DOT__fpu1__DOT__tDst);
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
		} else {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst;
		}
	    }
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__tDst = (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						     ? vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst
						     : vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						     ? vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst
						     : VL_ULL(0)));
	}
    }
}

void VExUop::_settle__TOP__13(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__13\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp64B.v:128
    if ((8U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__tDst = (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						     ? vlTOPp->ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst
						     : vlTOPp->ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst2)
						    : vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB);
	} else {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		vlTOPp->ExUop__DOT__fpu1__DOT__tSro 
		    = ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
		        ? ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
					  >> 0x3fU)))
			    ? ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
					      >> 0x3fU)))
			        ? ((0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)) 
				   | ((VL_ULL(0x7fffffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA) 
				      < (VL_ULL(0x7fffffffffffffff) 
					 & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)))
			        : (0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)))
			    : ((1U & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
					      >> 0x3fU)))
			        ? (1U | (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro))
			        : ((0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)) 
				   | ((VL_ULL(0x7fffffffffffffff) 
				       & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA) 
				      > (VL_ULL(0x7fffffffffffffff) 
					 & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)))))
		        : ((0xeU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__tSro)) 
			   | (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcA 
			      == vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB)));
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst;
		} else {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x7fffffffffffffff) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | ((QData)((IData)((1U & (IData)(
							    (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
							     >> 0x3fU))))) 
			      << 0x3fU));
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & (VL_ULL(0x3ff0000000000000) 
				 + (VL_ULL(0x3fffffffffffffff) 
				    & ((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
					- VL_ULL(0x3ff0000000000000)) 
				       >> 1U)))));
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
	    if ((2U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x7fffffffffffffff) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | ((QData)((IData)((1U & (IData)(
							    (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
							     >> 0x3fU))))) 
			      << 0x3fU));
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & (VL_ULL(0x3ff0000000000000) 
				 + VL_NEGATE_Q((vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
						- VL_ULL(0x3ff0000000000000))))));
		} else {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x7fffffffffffffff) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | ((QData)((IData)((1U & 
					       (~ (IData)(
							  (vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB 
							   >> 0x3fU)))))) 
			      << 0x3fU));
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUop__DOT__fpuCmd))) {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= (VL_ULL(0x7fffffffffffffff) 
			   & vlTOPp->ExUop__DOT__fpu1__DOT__tDst);
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= ((VL_ULL(0x8000000000000000) 
			    & vlTOPp->ExUop__DOT__fpu1__DOT__tDst) 
			   | (VL_ULL(0x7fffffffffffffff) 
			      & vlTOPp->ExUop__DOT__fpu1__DOT__fcSrcB));
		} else {
		    vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
			= vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst;
		}
	    }
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__tDst = (
						   (2U 
						    & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						    ? 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						     ? vlTOPp->ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst
						     : vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst)
						    : 
						   ((1U 
						     & (IData)(vlTOPp->ExUop__DOT__fpuCmd))
						     ? vlTOPp->ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst
						     : VL_ULL(0)));
	}
    }
    // ALWAYS at FpuFp64To32.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa 
	= ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb 
	= (0xfffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa) 
		     - (IData)(0x380U)));
    if ((0U == (0xfU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb) 
			>> 8U)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
	    = ((0x7fffffffU & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
	       | (0x80000000U & ((IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
					  >> 0x3fU)) 
				 << 0x1fU)));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
	    = ((0x807fffffU & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
	       | (0x7f800000U & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb) 
				 << 0x17U)));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
	    = ((0xff800000U & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
	       | (0x7fffffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
				       >> 0x1dU))));
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst = 0U;
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
		   | (0x80000000U & ((IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
					      >> 0x3fU)) 
				     << 0x1fU)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
		= (0x7f800000U | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
		= (0xff800000U & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst);
	}
    }
}

VL_INLINE_OPT void VExUop::_combo__TOP__14(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_combo__TOP__14\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at FpuFp64To32.v:21
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa 
	= (0x7ffU & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa 
	= ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa)) 
	   | (0x7ffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
				>> 0x34U))));
    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb 
	= (0xfffU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa) 
		     - (IData)(0x380U)));
    if ((0U == (0xfU & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb) 
			>> 8U)))) {
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
	    = ((0x7fffffffU & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
	       | (0x80000000U & ((IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
					  >> 0x3fU)) 
				 << 0x1fU)));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
	    = ((0x807fffffU & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
	       | (0x7f800000U & ((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb) 
				 << 0x17U)));
	vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
	    = ((0xff800000U & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
	       | (0x7fffffU & (IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
				       >> 0x1dU))));
    } else {
	if ((0x800U & (IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb))) {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst = 0U;
	} else {
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
		= ((0x7fffffffU & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst) 
		   | (0x80000000U & ((IData)((vlTOPp->ExUop__DOT__fpu1__DOT__tDst 
					      >> 0x3fU)) 
				     << 0x1fU)));
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
		= (0x7f800000U | vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst);
	    vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst 
		= (0xff800000U & vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst);
	}
    }
    vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst = ((VL_ULL(0xffffffff00000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst) 
						| (IData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst)));
}

void VExUop::_settle__TOP__15(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_settle__TOP__15\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst = ((VL_ULL(0xffffffff00000000) 
						 & vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst) 
						| (IData)((IData)(vlTOPp->ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst)));
    vlTOPp->ExUop__DOT__fpu1__DOT__tDst2 = ((((IData)(vlTOPp->ExUop__DOT__fpuOpFp32) 
					      | (0xdU 
						 == (IData)(vlTOPp->ExUop__DOT__fpuCmd))) 
					     & (0xeU 
						!= (IData)(vlTOPp->ExUop__DOT__fpuCmd)))
					     ? vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst
					     : vlTOPp->ExUop__DOT__fpu1__DOT__tDst);
}

VL_INLINE_OPT void VExUop::_combo__TOP__16(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_combo__TOP__16\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUop__DOT__fpu1__DOT__tDst2 = ((((IData)(vlTOPp->ExUop__DOT__fpuOpFp32) 
					      | (0xdU 
						 == (IData)(vlTOPp->ExUop__DOT__fpuCmd))) 
					     & (0xeU 
						!= (IData)(vlTOPp->ExUop__DOT__fpuCmd)))
					     ? vlTOPp->ExUop__DOT__fpu1__DOT__fpCnvdDst
					     : vlTOPp->ExUop__DOT__fpu1__DOT__tDst);
}

void VExUop::_eval(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_eval\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->_combo__TOP__10(vlSymsp);
    vlTOPp->_combo__TOP__12(vlSymsp);
    vlTOPp->_combo__TOP__14(vlSymsp);
    vlTOPp->_combo__TOP__16(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VExUop::_eval_initial(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_eval_initial\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void VExUop::final() {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::final\n"); );
    // Variables
    VExUop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VExUop::_eval_settle(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_eval_settle\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
    vlTOPp->_settle__TOP__9(vlSymsp);
    vlTOPp->_settle__TOP__11(vlSymsp);
    vlTOPp->_settle__TOP__13(vlSymsp);
    vlTOPp->_settle__TOP__15(vlSymsp);
}

VL_INLINE_OPT QData VExUop::_change_request(VExUop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_change_request\n"); );
    VExUop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->ExUop__DOT__iRegD ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegD)
	 | (vlTOPp->ExUop__DOT__iRegS ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegS)
	 | (vlTOPp->ExUop__DOT__iRegT ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegT)
	 | (vlTOPp->ExUop__DOT__tDataAguD ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__tDataAguD)
	 | (vlTOPp->ExUop__DOT__alu1__DOT__tDst ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__alu1__DOT__tDst)
	 | (vlTOPp->ExUop__DOT__alu1__DOT__tSr ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__alu1__DOT__tSr)
	 | (vlTOPp->ExUop__DOT__fpu1__DOT__tDst2 ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2) | (vlTOPp->ExUop__DOT__fpu1__DOT__tDst2 ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2)
	 | (vlTOPp->ExUop__DOT__fpu1__DOT__tSro ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tSro)
	 | (vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue)|| (vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue)
	 | (vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue) | (vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue)
	 | (vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__reqLdTile));
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__iRegD ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegD))) VL_PRINTF("	CHANGE: ExUop.v:173: ExUop.iRegD\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__iRegS ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegS))) VL_PRINTF("	CHANGE: ExUop.v:174: ExUop.iRegS\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__iRegT ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegT))) VL_PRINTF("	CHANGE: ExUop.v:175: ExUop.iRegT\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__tDataAguD ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__tDataAguD))) VL_PRINTF("	CHANGE: ExUop.v:217: ExUop.tDataAguD\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__alu1__DOT__tDst ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__alu1__DOT__tDst))) VL_PRINTF("	CHANGE: ArithAlu.v:39: ExUop.alu1.tDst\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__alu1__DOT__tSr ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__alu1__DOT__tSr))) VL_PRINTF("	CHANGE: ArithAlu.v:41: ExUop.alu1.tSr\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__fpu1__DOT__tDst2 ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2) | (vlTOPp->ExUop__DOT__fpu1__DOT__tDst2 ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2))) VL_PRINTF("	CHANGE: FpuFp64B.v:99: ExUop.fpu1.tDst2\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__fpu1__DOT__tSro ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tSro))) VL_PRINTF("	CHANGE: FpuFp64B.v:100: ExUop.fpu1.tSro\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue) | (vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue))) VL_PRINTF("	CHANGE: MemTile2.v:100: ExUop.mem1.tDrdValue\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue) | (vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue))) VL_PRINTF("	CHANGE: MemTile2.v:101: ExUop.mem1.tIrdValue\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile ^ vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__reqLdTile))) VL_PRINTF("	CHANGE: MemTile2.v:115: ExUop.mem1.reqLdTile\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegD = vlTOPp->ExUop__DOT__iRegD;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegS = vlTOPp->ExUop__DOT__iRegS;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__iRegT = vlTOPp->ExUop__DOT__iRegT;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__tDataAguD 
	= vlTOPp->ExUop__DOT__tDataAguD;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__alu1__DOT__tDst 
	= vlTOPp->ExUop__DOT__alu1__DOT__tDst;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__alu1__DOT__tSr 
	= vlTOPp->ExUop__DOT__alu1__DOT__tSr;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2 
	= vlTOPp->ExUop__DOT__fpu1__DOT__tDst2;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tSro 
	= vlTOPp->ExUop__DOT__fpu1__DOT__tSro;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue 
	= vlTOPp->ExUop__DOT__mem1__DOT__tDrdValue;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue 
	= vlTOPp->ExUop__DOT__mem1__DOT__tIrdValue;
    vlTOPp->__Vchglast__TOP__ExUop__DOT__mem1__DOT__reqLdTile 
	= vlTOPp->ExUop__DOT__mem1__DOT__reqLdTile;
    return __req;
}

void VExUop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    extAddr = VL_RAND_RESET_I(32);
    extData = VL_RAND_RESET_I(32);
    extOE = VL_RAND_RESET_I(1);
    extWR = VL_RAND_RESET_I(1);
    extNotReady = VL_RAND_RESET_I(1);
    ExUop__DOT__ifRegPc = VL_RAND_RESET_I(32);
    ExUop__DOT__idNextInstWord = VL_RAND_RESET_I(32);
    ExUop__DOT__idInstWord = VL_RAND_RESET_I(32);
    ExUop__DOT__idRegD = VL_RAND_RESET_I(7);
    ExUop__DOT__idRegS = VL_RAND_RESET_I(7);
    ExUop__DOT__idRegT = VL_RAND_RESET_I(7);
    ExUop__DOT__idImm = VL_RAND_RESET_I(32);
    ExUop__DOT__idUopWord = VL_RAND_RESET_I(32);
    ExUop__DOT__idRegPc = VL_RAND_RESET_I(32);
    ExUop__DOT__idRegNextPc = VL_RAND_RESET_I(32);
    ExUop__DOT__uopWord = VL_RAND_RESET_I(32);
    ExUop__DOT__uopNextWord = VL_RAND_RESET_I(32);
    ExUop__DOT__uopCmd = VL_RAND_RESET_I(8);
    ExUop__DOT__ixRegD = VL_RAND_RESET_I(7);
    ExUop__DOT__ixRegS = VL_RAND_RESET_I(7);
    ExUop__DOT__ixRegT = VL_RAND_RESET_I(7);
    ExUop__DOT__ixImm = VL_RAND_RESET_I(32);
    ExUop__DOT__ixRegPc = VL_RAND_RESET_I(32);
    ExUop__DOT__ixRegNextPc = VL_RAND_RESET_I(32);
    ExUop__DOT__iRegD = VL_RAND_RESET_I(7);
    ExUop__DOT__iRegS = VL_RAND_RESET_I(7);
    ExUop__DOT__iRegT = VL_RAND_RESET_I(7);
    ExUop__DOT__iImm = VL_RAND_RESET_I(32);
    ExUop__DOT__iDataD = VL_RAND_RESET_Q(64);
    ExUop__DOT__iDataS = VL_RAND_RESET_Q(64);
    ExUop__DOT__iDataT = VL_RAND_RESET_Q(64);
    ExUop__DOT__tData2D = VL_RAND_RESET_Q(64);
    ExUop__DOT__tIdReg2D = VL_RAND_RESET_I(7);
    ExUop__DOT__tIsWr2D = VL_RAND_RESET_I(1);
    ExUop__DOT__tIsQw2D = VL_RAND_RESET_I(1);
    ExUop__DOT__oData2D = VL_RAND_RESET_Q(64);
    ExUop__DOT__oIdReg2D = VL_RAND_RESET_I(7);
    ExUop__DOT__oIsWr2D = VL_RAND_RESET_I(1);
    ExUop__DOT__oIsQw2D = VL_RAND_RESET_I(1);
    ExUop__DOT__iDataAluS = VL_RAND_RESET_I(32);
    ExUop__DOT__iDataAluT = VL_RAND_RESET_I(32);
    ExUop__DOT__regNextSr = VL_RAND_RESET_I(32);
    ExUop__DOT__regNextPc = VL_RAND_RESET_I(32);
    ExUop__DOT__regPrNextPc = VL_RAND_RESET_I(32);
    ExUop__DOT__regPrPc = VL_RAND_RESET_I(32);
    ExUop__DOT__regNextPr = VL_RAND_RESET_I(32);
    ExUop__DOT__aluCmd = VL_RAND_RESET_I(4);
    ExUop__DOT__aguHasIndex = VL_RAND_RESET_I(1);
    ExUop__DOT__tDataAguD = VL_RAND_RESET_I(32);
    ExUop__DOT__aguCmd = VL_RAND_RESET_I(3);
    ExUop__DOT__fpuOpFp32 = VL_RAND_RESET_I(1);
    ExUop__DOT__fpuCmd = VL_RAND_RESET_I(4);
    ExUop__DOT__iDataFpuD = VL_RAND_RESET_Q(64);
    ExUop__DOT__iDataFpuS = VL_RAND_RESET_Q(64);
    ExUop__DOT__iDataFpuT = VL_RAND_RESET_Q(64);
    ExUop__DOT__memRd = VL_RAND_RESET_I(1);
    ExUop__DOT__memWr = VL_RAND_RESET_I(1);
    ExUop__DOT__memCmd = VL_RAND_RESET_I(3);
    ExUop__DOT__memAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__memWrValue = VL_RAND_RESET_Q(64);
    ExUop__DOT__imemRd = VL_RAND_RESET_I(1);
    ExUop__DOT__imemAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__memHold = VL_RAND_RESET_I(1);
    ExUop__DOT__idStepPc = VL_RAND_RESET_I(2);
    ExUop__DOT__tRegStepPc = VL_RAND_RESET_I(32);
    ExUop__DOT__uopPc = VL_RAND_RESET_I(12);
    ExUop__DOT__uopNextPc = VL_RAND_RESET_I(12);
    ExUop__DOT__uopPcLive = VL_RAND_RESET_I(1);
    ExUop__DOT__uopNextPcLive = VL_RAND_RESET_I(1);
    ExUop__DOT__tResetMagic = VL_RAND_RESET_I(16);
    ExUop__DOT__tResetOK = VL_RAND_RESET_I(1);
    ExUop__DOT__tPipeFlush = VL_RAND_RESET_I(3);
    ExUop__DOT__tNextPipeFlush = VL_RAND_RESET_I(3);
    ExUop__DOT__tPipeDsFlush = VL_RAND_RESET_I(1);
    ExUop__DOT__tNextPipeDsFlush = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    ExUop__DOT__regs__DOT__regs_lo[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    ExUop__DOT__regs__DOT__regs_hi[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    ExUop__DOT__regs__DOT__creg_lo[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    ExUop__DOT__regs__DOT__creg_hi[__Vi0] = VL_RAND_RESET_I(32);
    }}
    ExUop__DOT__regs__DOT__reg_pc = VL_RAND_RESET_I(32);
    ExUop__DOT__regs__DOT__reg_pr = VL_RAND_RESET_I(32);
    ExUop__DOT__regs__DOT__reg_sr = VL_RAND_RESET_I(32);
    ExUop__DOT__regs__DOT__tIdReg1Lo = VL_RAND_RESET_I(6);
    ExUop__DOT__regs__DOT__tIdReg2Lo = VL_RAND_RESET_I(6);
    ExUop__DOT__regs__DOT__tIdReg3Lo = VL_RAND_RESET_I(6);
    ExUop__DOT__alu1__DOT__tDst = VL_RAND_RESET_I(32);
    ExUop__DOT__alu1__DOT__tShl = VL_RAND_RESET_I(6);
    ExUop__DOT__alu1__DOT__tSr = VL_RAND_RESET_I(4);
    ExUop__DOT__agu1__DOT__tIdxAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__agu1__DOT__tOutAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__fpu1__DOT__fcSrcA = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fcSrcB = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpaSrcA = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpaSrcB = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__tOpFp32i = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__tDst2 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__tSro = VL_RAND_RESET_I(4);
    ExUop__DOT__fpu1__DOT__fpCnvdDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__sgna = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnb = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__exa = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__exb = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__exc = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__exm = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA1 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB1 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__sgna = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnb = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__exa = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__exb = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__exc = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2 = VL_RAND_RESET_Q(52);
    ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnva__DOT__exb = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exb = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exb = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__sgn = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl = VL_RAND_RESET_I(6);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst2 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc = VL_RAND_RESET_I(1);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2 = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E = VL_RAND_RESET_I(13);
    ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst = VL_RAND_RESET_Q(64);
    ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb = VL_RAND_RESET_I(12);
    ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    ExUop__DOT__mem1__DOT__dTile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    ExUop__DOT__mem1__DOT__dTileBase[__Vi0] = VL_RAND_RESET_I(26);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    ExUop__DOT__mem1__DOT__dTileBaseDty[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    ExUop__DOT__mem1__DOT__iTile[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    ExUop__DOT__mem1__DOT__iTileBase[__Vi0] = VL_RAND_RESET_I(26);
    }}
    ExUop__DOT__mem1__DOT__dTileIdx = VL_RAND_RESET_I(11);
    ExUop__DOT__mem1__DOT__iTileIdx = VL_RAND_RESET_I(11);
    ExUop__DOT__mem1__DOT__dTileLimIdx = VL_RAND_RESET_I(11);
    ExUop__DOT__mem1__DOT__iTileLimIdx = VL_RAND_RESET_I(11);
    ExUop__DOT__mem1__DOT__dTileMiss = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__iTileMiss = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__dTileMiss2 = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__iTileMiss2 = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__dMemAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__mem1__DOT__dMemAddrLim = VL_RAND_RESET_I(32);
    ExUop__DOT__mem1__DOT__iMemAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__mem1__DOT__iMemAddrLim = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(96,ExUop__DOT__mem1__DOT__rdtTBlock);
    VL_RAND_RESET_W(96,ExUop__DOT__mem1__DOT__rdtTBlock2);
    VL_RAND_RESET_W(96,ExUop__DOT__mem1__DOT__rdtValue);
    ExUop__DOT__mem1__DOT__rdtShl = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(96,ExUop__DOT__mem1__DOT__irdtTBlock);
    VL_RAND_RESET_W(96,ExUop__DOT__mem1__DOT__irdtValue);
    ExUop__DOT__mem1__DOT__irdtShl = VL_RAND_RESET_I(5);
    ExUop__DOT__mem1__DOT__tDrdValue = VL_RAND_RESET_Q(64);
    ExUop__DOT__mem1__DOT__tIrdValue = VL_RAND_RESET_Q(64);
    ExUop__DOT__mem1__DOT__reqLdTileBaseLo = VL_RAND_RESET_I(26);
    ExUop__DOT__mem1__DOT__reqLdTileIdx = VL_RAND_RESET_I(7);
    ExUop__DOT__mem1__DOT__reqLdTile = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__reqLdITile = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__reqLdSTile = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__reqStTile = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__reqSyncTile = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__reqNextSyncTile = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__reqSyncTileIdx = VL_RAND_RESET_I(7);
    ExUop__DOT__mem1__DOT__reqNextSyncTileIdx = VL_RAND_RESET_I(7);
    ExUop__DOT__mem1__DOT__ldTileWIdx = VL_RAND_RESET_I(4);
    ExUop__DOT__mem1__DOT__ldTileNextWIdx = VL_RAND_RESET_I(4);
    ExUop__DOT__mem1__DOT__ldTileExtAddr = VL_RAND_RESET_I(32);
    ExUop__DOT__mem1__DOT__ldTileIdx = VL_RAND_RESET_I(11);
    ExUop__DOT__mem1__DOT__ldTileAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileStAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextStAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileDlyAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextDlyAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileLastAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextLastAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileDn = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextDn = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileExtOE = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextExtOE = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileExtWR = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__ldTileNextExtWR = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__dTileOpWrOK = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__resetAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__resetNextAct = VL_RAND_RESET_I(1);
    ExUop__DOT__mem1__DOT__resetCurTile = VL_RAND_RESET_I(7);
    ExUop__DOT__mem1__DOT__resetNextTile = VL_RAND_RESET_I(7);
    ExUop__DOT__mem1__DOT__resetTOK = VL_RAND_RESET_I(16);
    ExUop__DOT__mem1__DOT__extData__out__out0 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUop__DOT__dec1__DOT__uopPcIdx[__Vi0] = VL_RAND_RESET_I(12);
    }}
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
	    ExUop__DOT__dec1__DOT__uopPgm[__Vi0] = VL_RAND_RESET_I(32);
    }}
    ExUop__DOT__dec1__DOT__srIsDq = VL_RAND_RESET_I(1);
    ExUop__DOT__dec1__DOT__opIs32p = VL_RAND_RESET_I(1);
    ExUop__DOT__dec1__DOT__tIdRegD = VL_RAND_RESET_I(7);
    ExUop__DOT__dec1__DOT__tIdRegS = VL_RAND_RESET_I(7);
    ExUop__DOT__dec1__DOT__tIdRegT = VL_RAND_RESET_I(7);
    ExUop__DOT__dec1__DOT__tIdImm = VL_RAND_RESET_I(32);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__ExUop__DOT__iRegD = VL_RAND_RESET_I(7);
    __Vchglast__TOP__ExUop__DOT__iRegS = VL_RAND_RESET_I(7);
    __Vchglast__TOP__ExUop__DOT__iRegT = VL_RAND_RESET_I(7);
    __Vchglast__TOP__ExUop__DOT__tDataAguD = VL_RAND_RESET_I(32);
    __Vchglast__TOP__ExUop__DOT__alu1__DOT__tDst = VL_RAND_RESET_I(32);
    __Vchglast__TOP__ExUop__DOT__alu1__DOT__tSr = VL_RAND_RESET_I(4);
    __Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2 = VL_RAND_RESET_Q(64);
    __Vchglast__TOP__ExUop__DOT__fpu1__DOT__tSro = VL_RAND_RESET_I(4);
    __Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue = VL_RAND_RESET_Q(64);
    __Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue = VL_RAND_RESET_Q(64);
    __Vchglast__TOP__ExUop__DOT__mem1__DOT__reqLdTile = VL_RAND_RESET_I(1);
}

void VExUop::_configure_coverage(VExUop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VExUop::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
