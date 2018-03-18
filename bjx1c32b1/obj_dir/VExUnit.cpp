// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VExUnit.h for the primary calling header

#include "VExUnit.h"           // For This
#include "VExUnit__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VExUnit) {
    VExUnit__Syms* __restrict vlSymsp = __VlSymsp = new VExUnit__Syms(this, name());
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VExUnit::__Vconfigure(VExUnit__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VExUnit::~VExUnit() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VExUnit::eval() {
    VExUnit__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VExUnit::eval\n"); );
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

void VExUnit::_eval_initial_loop(VExUnit__Syms* __restrict vlSymsp) {
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

void VExUnit::_initial__TOP__1(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_initial__TOP__1\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,95,0,3);
    // Body
    // INITIAL at ExUnit.v:48
    vlTOPp->extOE = 0U;
    // INITIAL at ExUnit.v:49
    vlTOPp->extWR = 0U;
    // INITIAL at ExUnit.v:33
    vlTOPp->extAddr = 0U;
    // INITIAL at ExUnit.v:34
    vlTOPp->extData[0U] = 0U;
    vlTOPp->extData[1U] = 0U;
    vlTOPp->extData[2U] = 0U;
    vlTOPp->extData[3U] = 0U;
    // INITIAL at ModNtsc.v:89
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0U] = 0x80U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[1U] = 0x87U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[2U] = 0x8eU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[3U] = 0x94U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[4U] = 0x9aU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[5U] = 0x9eU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[6U] = 0xa2U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[7U] = 0xa4U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[8U] = 0xa5U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[9U] = 0xa4U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0xaU] = 0xa2U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0xbU] = 0x9eU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0xcU] = 0x9aU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0xdU] = 0x94U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0xeU] = 0x8eU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0xfU] = 0x87U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x10U] = 0x80U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x11U] = 0x79U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x12U] = 0x72U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x13U] = 0x6cU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x14U] = 0x66U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x15U] = 0x62U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x16U] = 0x5eU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x17U] = 0x5cU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x18U] = 0x5bU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x19U] = 0x5cU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x1aU] = 0x5eU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x1bU] = 0x62U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x1cU] = 0x66U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x1dU] = 0x6cU;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x1eU] = 0x72U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[0x1fU] = 0x79U;
    // INITIAL at Dc2Tile.v:113
    __Vtemp1[0U] = 0x2e747874U;
    __Vtemp1[1U] = 0x74726f6dU;
    __Vtemp1[2U] = 0x626f6fU;
    VL_READMEM_W (true,128,256, 0,3, __Vtemp1, vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		  ,0,~0);
}

VL_INLINE_OPT void VExUnit::_sequent__TOP__2(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_sequent__TOP__2\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0,2,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0,0,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0,0,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0,0,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0,0,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0,0,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkA__v0,7,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkB__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkC__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkD__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkE__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkAd__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkFl__v0,7,0);
    VL_SIG8(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkFl__v0,3,0);
    VL_SIG8(__Vdly__ExUnit__DOT__dcf__DOT__isReqTileSt,3,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkA__v0,7,0);
    VL_SIG8(__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0,0,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkB__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkC__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkD__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkE__v0,7,0);
    VL_SIG8(__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkAd__v0,7,0);
    VL_SIG8(__Vdly__ExUnit__DOT__icf__DOT__isReqTileSt,2,0);
    //char	__VpadToAlign65[1];
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0,9,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0,9,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0,9,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0,9,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileA__v0,10,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileB__v0,10,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileC__v0,10,0);
    VL_SIG16(__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileD__v0,10,0);
    //char	__VpadToAlign82[2];
    VL_SIG(__Vdly__ExUnit__DOT__regIfPc,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__regIfSr,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__regIdPc,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileA__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileB__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileC__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileD__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkA__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkB__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkC__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkD__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkE__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkAd__v0,27,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkA__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkB__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkC__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkD__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkE__v0,31,0);
    VL_SIG(__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkAd__v0,27,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR0B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR1B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR2B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR3B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR4B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR5B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR6B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR7B,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR0A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR1A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR2A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR3A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR4A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR5A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR6A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR7A,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR8,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR9,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR10,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR11,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR12,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR13,31,0);
    VL_SIG(__Vdly__ExUnit__DOT__gpr__DOT__regGprR14,31,0);
    VL_SIGW(__Vtemp2,127,0,4);
    VL_SIG64(__Vdly__ExUnit__DOT__regIdPcVal,47,0);
    // Body
    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0 = 0U;
    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0 = 0U;
    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0 = 0U;
    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0 = 0U;
    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0 = 0U;
    __Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0 = 0U;
    __Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0 = 0U;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR8 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR9 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR10 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR11 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR12 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR13 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR14 = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14;
    __Vdly__ExUnit__DOT__regIfSr = vlTOPp->ExUnit__DOT__regIfSr;
    __Vdly__ExUnit__DOT__regIdPc = vlTOPp->ExUnit__DOT__regIdPc;
    __Vdly__ExUnit__DOT__dcf__DOT__isReqTileSt = vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt;
    __Vdly__ExUnit__DOT__regIfPc = vlTOPp->ExUnit__DOT__regIfPc;
    __Vdly__ExUnit__DOT__regIdPcVal = vlTOPp->ExUnit__DOT__regIdPcVal;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR0B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR1B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR2B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR3B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR4B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR5B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR6B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR7B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7B;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR0A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR1A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR2A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR3A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR4A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR5A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR6A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A;
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR7A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A;
    __Vdly__ExUnit__DOT__icf__DOT__isReqTileSt = vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt;
    __Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0 = 0U;
    // ALWAYS at ModNtsc.v:250
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextSt8;
    // ALWAYS at ModTxtMemW.v:140
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph;
    // ALWAYS at ModNtsc.v:252
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal;
    // ALWAYS at ModTxtMemW.v:141
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData1 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData2;
    // ALWAYS at ModNtsc.v:265
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCy 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy;
    // ALWAYS at ModNtsc.v:266
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCu 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu;
    // ALWAYS at ModNtsc.v:267
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCv 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv;
    // ALWAYS at ModFbTxtW.v:290
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosX;
    // ALWAYS at ModFbTxtW.v:291
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosY;
    // ALWAYS at ModNtsc.v:253
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc;
    // ALWAYS at ModNtsc.v:255
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk;
    // ALWAYS at ModNtsc.v:256
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk;
    // ALWAYS at ModNtsc.v:258
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk;
    // ALWAYS at ModNtsc.v:259
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk;
    // ALWAYS at ModNtsc.v:260
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt;
    // ALWAYS at ModNtsc.v:269
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCy 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy;
    // ALWAYS at ModNtsc.v:270
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCu 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu;
    // ALWAYS at ModNtsc.v:271
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCv 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv;
    // ALWAYS at ModNtsc.v:272
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCu 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu;
    // ALWAYS at ModNtsc.v:273
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCv 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv;
    // ALWAYS at DcTile3.v:532
    vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd = vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd;
    // ALWAYS at DcTile3.v:533
    vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqNeedAd;
    // ALWAYS at DcTile3.v:541
    vlTOPp->ExUnit__DOT__dcf__DOT__accHit = vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit;
    // ALWAYS at DcTile3.v:542
    vlTOPp->ExUnit__DOT__dcf__DOT__accCommitOK = vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccCommitOK;
    // ALWAYS at DcTile3.v:543
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B = vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2;
    // ALWAYS at DcTile3.v:534
    vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[0U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U];
    vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[1U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U];
    vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[2U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U];
    vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[3U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U];
    vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[4U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U];
    // ALWAYS at DcTile3.v:544
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB = vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutData;
    // ALWAYS at ModTxtMemW.v:135
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A
	[(0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B
	[(0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[2U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C
	[(0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[3U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D
	[(0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx))];
    // ALWAYS at DcTile3.v:536
    vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkA[(0xffU 
					       & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3)];
    vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkB[(0xffU 
					       & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3)];
    vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkC[(0xffU 
					       & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3)];
    vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkD[(0xffU 
					       & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3)];
    vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U] = 
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkE[(0xffU 
					       & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd4)];
    // ALWAYS at Dc2Tile.v:255
    if (vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileSt) {
	__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileA__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U];
	__Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0 = 1U;
	__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileA__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx;
	__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileB__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U];
	__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileB__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx;
	__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileC__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U];
	__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileC__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx;
	__Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileD__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U];
	__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileD__v0 
	    = vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx;
    }
    // ALWAYS at ExUnit.v:597
    vlTOPp->ExUnit__DOT__dcfRegInAddr = vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr;
    // ALWAYS at ExUnit.v:598
    vlTOPp->ExUnit__DOT__dcfRegInData = (QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemData));
    // ALWAYS at ExUnit.v:601
    vlTOPp->ExUnit__DOT__dcfRegInOp = vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode;
    // ALWAYS at ExUnit.v:599
    vlTOPp->ExUnit__DOT__dcfRegInOE = vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad;
    // ALWAYS at ExUnit.v:600
    vlTOPp->ExUnit__DOT__dcfRegInWR = vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore;
    // ALWAYS at Dc2Tile.v:253
    vlTOPp->ExUnit__DOT__dcl2__DOT__tAccTileIx = vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx;
    // ALWAYS at Dc2Tile.v:249
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[0U] = 
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileA[vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx];
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[1U] = 
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileB[vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx];
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[2U] = 
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileC[vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx];
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[3U] = 
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileD[vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx];
    // ALWAYS at DcTile3.v:546
    if (vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit) {
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkA__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U];
	__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0 = 1U;
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkA__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkB__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U];
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkB__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkC__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U];
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkC__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkD__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U];
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkD__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkE__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U];
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkE__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2);
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkAd__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1;
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkAd__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkFl__v0 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl;
	__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkFl__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1);
    }
    // ALWAYS at ExOp2.v:898
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpB = vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpB0;
    // ALWAYS at ExOp2.v:897
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu = (((
						   ((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_BB)) 
						    << 0x20U) 
						   | (QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_AA))) 
						  + 
						  ((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_AB)) 
						   << 0x10U)) 
						 + 
						 ((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_BA)) 
						  << 0x10U));
    // ALWAYS at RegGPR2.v:465
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR8 = ((8U 
						== (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
					        ? vlTOPp->ExUnit__DOT__idWbRegValO
					        : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8);
    // ALWAYS at RegGPR2.v:466
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR9 = ((9U 
						== (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
					        ? vlTOPp->ExUnit__DOT__idWbRegValO
					        : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9);
    // ALWAYS at RegGPR2.v:467
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR10 = ((0xaU 
						 == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
						 ? vlTOPp->ExUnit__DOT__idWbRegValO
						 : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10);
    // ALWAYS at RegGPR2.v:468
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR11 = ((0xbU 
						 == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
						 ? vlTOPp->ExUnit__DOT__idWbRegValO
						 : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11);
    // ALWAYS at RegGPR2.v:469
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR12 = ((0xcU 
						 == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
						 ? vlTOPp->ExUnit__DOT__idWbRegValO
						 : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12);
    // ALWAYS at RegGPR2.v:470
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR13 = ((0xdU 
						 == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
						 ? vlTOPp->ExUnit__DOT__idWbRegValO
						 : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13);
    // ALWAYS at RegGPR2.v:471
    __Vdly__ExUnit__DOT__gpr__DOT__regGprR14 = ((0xeU 
						 == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
						 ? vlTOPp->ExUnit__DOT__idWbRegValO
						 : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14);
    // ALWAYS at IcTile2.v:222
    vlTOPp->ExUnit__DOT__icf__DOT__reqNeedAd = vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd;
    // ALWAYS at IcTile2.v:223
    vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqNeedAd;
    // ALWAYS at IcTile2.v:225
    vlTOPp->ExUnit__DOT__icf__DOT__doReqNeedAd = vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd;
    // ALWAYS at IcTile2.v:224
    vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[0U] = 
	vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U];
    vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[1U] = 
	vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U];
    vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[2U] = 
	vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U];
    vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[3U] = 
	vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U];
    vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[4U] = 
	vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U];
    // ALWAYS at RegGPR2.v:474
    if (((IData)(vlTOPp->reset) | (0x55U != (IData)(vlTOPp->ExUnit__DOT__regRstTok)))) {
	vlTOPp->ExUnit__DOT__gpr__DOT__regSr = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regPr = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regPc = 0xa0000000U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regMac = VL_ULL(0);
	vlTOPp->ExUnit__DOT__gpr__DOT__regSp = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regGbr = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regVbr = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regSSr = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regSPc = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regSGr = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regFpul = 0U;
	vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__tRegExHold)))) {
	    vlTOPp->ExUnit__DOT__gpr__DOT__regSr = 
		((0x20U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regPr = 
		((0x62U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPr);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regPc = 
		((0x27U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exNextPc2);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regMac = 
		((VL_ULL(0xffffffff00000000) & vlTOPp->ExUnit__DOT__gpr__DOT__regMac) 
		 | (IData)((IData)(((0x61U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
				     ? vlTOPp->ExUnit__DOT__idWbRegValO
				     : (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac)))));
	    vlTOPp->ExUnit__DOT__gpr__DOT__regSp = 
		((0xfU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSp);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regGbr = 
		((0x21U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutGbr);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regVbr = 
		((0x22U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutVbr);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regSSr = 
		((0x23U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSSr);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regSPc = 
		((0x24U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSPc);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regSGr = 
		((0x63U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		  ? vlTOPp->ExUnit__DOT__idWbRegValO
		  : vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSGr);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regFpul 
		= ((0x65U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		    ? vlTOPp->ExUnit__DOT__idWbRegValO
		    : vlTOPp->ExUnit__DOT__exNextFpul2);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
		= ((0x66U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
		    ? vlTOPp->ExUnit__DOT__idWbRegValO
		    : vlTOPp->ExUnit__DOT__exNextFpScr2);
	    vlTOPp->ExUnit__DOT__gpr__DOT__regMac = 
		((VL_ULL(0xffffffff) & vlTOPp->ExUnit__DOT__gpr__DOT__regMac) 
		 | ((QData)((IData)(((0x60U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
				      ? vlTOPp->ExUnit__DOT__idWbRegValO
				      : (IData)((vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
						 >> 0x20U))))) 
		    << 0x20U));
	}
    }
    // ALWAYS at DcTile3.v:557
    if ((1U == (IData)(vlTOPp->ExUnit__DOT__dcfMemPcOK))) {
	__Vdly__ExUnit__DOT__dcf__DOT__isReqTileSt 
	    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt;
    } else {
	if ((0U == (IData)(vlTOPp->ExUnit__DOT__dcfMemPcOK))) {
	    if ((0U == (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		__Vdly__ExUnit__DOT__dcf__DOT__isReqTileSt 
		    = vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt;
	    } else {
		if ((1U == (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    __Vdly__ExUnit__DOT__dcf__DOT__isReqTileSt 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt;
		}
	    }
	}
    }
    // ALWAYS at RegGPR2.v:424
    if ((1U & ((IData)(vlTOPp->ExUnit__DOT__gpr__DOT__regSrRB) 
	       ^ (vlTOPp->ExUnit__DOT__regIdSr >> 0x1dU)))) {
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR0B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR1B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR2B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR3B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR4B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR5B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR6B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR7B = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR0A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR1A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR2A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR3A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR4A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR5A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR6A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6B;
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR7A = vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7B;
    } else {
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR0A = 
	    ((0U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR1A = 
	    ((1U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR2A = 
	    ((2U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR3A = 
	    ((3U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR4A = 
	    ((4U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR5A = 
	    ((5U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR6A = 
	    ((6U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR7A = 
	    ((7U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR0B = 
	    ((0x28U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR1B = 
	    ((0x29U == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR2B = 
	    ((0x2aU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR3B = 
	    ((0x2bU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR4B = 
	    ((0x2cU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR5B = 
	    ((0x2dU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR6B = 
	    ((0x2eU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6B);
	__Vdly__ExUnit__DOT__gpr__DOT__regGprR7B = 
	    ((0x2fU == (IData)(vlTOPp->ExUnit__DOT__idWbRegO))
	      ? vlTOPp->ExUnit__DOT__idWbRegValO : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7B);
    }
    // ALWAYS at IcTile2.v:227
    if (VL_UNLIKELY(vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit)) {
	VL_WRITEF("IcTile: Commit %x %x\n",28,vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1,
		  160,vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk);
	__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkA__v0 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U];
	__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0 = 1U;
	__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkA__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkB__v0 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U];
	__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkB__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkC__v0 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U];
	__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkC__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkD__v0 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U];
	__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkD__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1);
	__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkE__v0 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U];
	__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkE__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2);
	__Vdlyvval__ExUnit__DOT__icf__DOT__icBlkAd__v0 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1;
	__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkAd__v0 
	    = (0xffU & vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1);
    }
    if (VL_UNLIKELY((1U == (IData)(vlTOPp->ExUnit__DOT__memIfPcOK)))) {
	VL_WRITEF("IcTile: MemOK %x->%x\n",3,vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt,
		  3,(IData)(vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt));
	__Vdly__ExUnit__DOT__icf__DOT__isReqTileSt 
	    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt;
    } else {
	if ((0U == (IData)(vlTOPp->ExUnit__DOT__memIfPcOK))) {
	    if ((0U == (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
		__Vdly__ExUnit__DOT__icf__DOT__isReqTileSt 
		    = vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt;
	    }
	} else {
	    if (VL_UNLIKELY((2U == (IData)(vlTOPp->ExUnit__DOT__memIfPcOK)))) {
		VL_WRITEF("IcTile: MemHold\n");
	    } else {
		if (VL_UNLIKELY((3U == (IData)(vlTOPp->ExUnit__DOT__memIfPcOK)))) {
		    VL_WRITEF("IcTile: MemFault\n");
		}
	    }
	}
    }
    // ALWAYSPOST at Dc2Tile.v:258
    if (__Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0) {
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileA[__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileA__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileA__v0;
    }
    // ALWAYSPOST at Dc2Tile.v:259
    if (__Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0) {
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileB[__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileB__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileB__v0;
    }
    // ALWAYSPOST at Dc2Tile.v:260
    if (__Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0) {
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileC[__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileC__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileC__v0;
    }
    // ALWAYSPOST at Dc2Tile.v:261
    if (__Vdlyvset__ExUnit__DOT__dcl2__DOT__memTileA__v0) {
	vlTOPp->ExUnit__DOT__dcl2__DOT__memTileD[__Vdlyvdim0__ExUnit__DOT__dcl2__DOT__memTileD__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcl2__DOT__memTileD__v0;
    }
    // ALWAYSPOST at DcTile3.v:548
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkA[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkA__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkA__v0;
    }
    // ALWAYSPOST at DcTile3.v:549
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkB[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkB__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkB__v0;
    }
    // ALWAYSPOST at DcTile3.v:550
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkC[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkC__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkC__v0;
    }
    // ALWAYSPOST at DcTile3.v:551
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkD[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkD__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkD__v0;
    }
    // ALWAYSPOST at DcTile3.v:552
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkE[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkE__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkE__v0;
    }
    // ALWAYSPOST at DcTile3.v:553
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkAd__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkAd__v0;
    }
    // ALWAYSPOST at DcTile3.v:554
    if (__Vdlyvset__ExUnit__DOT__dcf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__dcf__DOT__icBlkFl[__Vdlyvdim0__ExUnit__DOT__dcf__DOT__icBlkFl__v0] 
	    = __Vdlyvval__ExUnit__DOT__dcf__DOT__icBlkFl__v0;
    }
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR8;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR9;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR10;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR11;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR12;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR13;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14 = __Vdly__ExUnit__DOT__gpr__DOT__regGprR14;
    vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt = __Vdly__ExUnit__DOT__dcf__DOT__isReqTileSt;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR0B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR1B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR2B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR3B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR4B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR5B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR6B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7B = __Vdly__ExUnit__DOT__gpr__DOT__regGprR7B;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR0A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR1A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR2A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR3A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR4A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR5A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR6A;
    vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A = __Vdly__ExUnit__DOT__gpr__DOT__regGprR7A;
    vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt = __Vdly__ExUnit__DOT__icf__DOT__isReqTileSt;
    // ALWAYSPOST at IcTile2.v:230
    if (__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__icf__DOT__icBlkA[__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkA__v0] 
	    = __Vdlyvval__ExUnit__DOT__icf__DOT__icBlkA__v0;
    }
    // ALWAYSPOST at IcTile2.v:231
    if (__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__icf__DOT__icBlkB[__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkB__v0] 
	    = __Vdlyvval__ExUnit__DOT__icf__DOT__icBlkB__v0;
    }
    // ALWAYSPOST at IcTile2.v:232
    if (__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__icf__DOT__icBlkC[__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkC__v0] 
	    = __Vdlyvval__ExUnit__DOT__icf__DOT__icBlkC__v0;
    }
    // ALWAYSPOST at IcTile2.v:233
    if (__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__icf__DOT__icBlkD[__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkD__v0] 
	    = __Vdlyvval__ExUnit__DOT__icf__DOT__icBlkD__v0;
    }
    // ALWAYSPOST at IcTile2.v:234
    if (__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__icf__DOT__icBlkE[__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkE__v0] 
	    = __Vdlyvval__ExUnit__DOT__icf__DOT__icBlkE__v0;
    }
    // ALWAYSPOST at IcTile2.v:235
    if (__Vdlyvset__ExUnit__DOT__icf__DOT__icBlkA__v0) {
	vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd[__Vdlyvdim0__ExUnit__DOT__icf__DOT__icBlkAd__v0] 
	    = __Vdlyvval__ExUnit__DOT__icf__DOT__icBlkAd__v0;
    }
    // ALWAYS at ModNtsc.v:137
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextSt8 
	= (0xffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8) 
		    + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal)));
    // ALWAYS at ModNtsc.v:137
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmCarry 
	= (1U & (((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8) 
		  + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal)) 
		 >> 8U));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmOut 
	= ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmCarry)
	    ? 0xfU : 0U);
    // ALWAYS at ModNtsc.v:262
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosX 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX;
    // ALWAYS at ModNtsc.v:263
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosY 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY;
    // ALWAYS at ModTxtMemW.v:134
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx 
	= (0x3fffU & (((0x80U == (0xffffU & (vlTOPp->mmioAddr 
					     >> 0x10U))) 
		       & (IData)(vlTOPp->mmioOE)) ? 
		      (vlTOPp->mmioAddr >> 2U) : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx)));
    if ((((0x80U == (0xffffU & (vlTOPp->mmioAddr >> 0x10U))) 
	  & (IData)(vlTOPp->mmioWR)) & (~ (IData)(vlTOPp->mmioOE)))) {
	if ((0xffU == (0xffU & (vlTOPp->mmioAddr >> 8U)))) {
	    __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0 
		= vlTOPp->mmioData;
	    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0 = 1U;
	    __Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0 
		= (7U & (vlTOPp->mmioAddr >> 2U));
	} else {
	    if ((8U & vlTOPp->mmioAddr)) {
		if ((4U & vlTOPp->mmioAddr)) {
		    __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0 
			= vlTOPp->mmioData;
		    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0 = 1U;
		    __Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0 
			= (0x3ffU & (vlTOPp->mmioAddr 
				     >> 4U));
		} else {
		    __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0 
			= vlTOPp->mmioData;
		    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0 = 1U;
		    __Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0 
			= (0x3ffU & (vlTOPp->mmioAddr 
				     >> 4U));
		}
	    } else {
		if ((4U & vlTOPp->mmioAddr)) {
		    __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0 
			= vlTOPp->mmioData;
		    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0 = 1U;
		    __Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0 
			= (0x3ffU & (vlTOPp->mmioAddr 
				     >> 4U));
		} else {
		    __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0 
			= vlTOPp->mmioData;
		    __Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0 = 1U;
		    __Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0 
			= (0x3ffU & (vlTOPp->mmioAddr 
				     >> 4U));
		}
	    }
	}
    }
    // ALWAYS at ExOp2.v:889
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpB0 = vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpA0;
    // ALWAYS at ExOp2.v:888
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_BB = 
	((0xffffU & (IData)((vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA 
			     >> 0x10U))) * (0xffffU 
					    & (IData)(
						      (vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA 
						       >> 0x10U))));
    // ALWAYS at ExOp2.v:885
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_AA = 
	((0xffffU & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA)) 
	 * (0xffffU & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA)));
    // ALWAYS at ExOp2.v:886
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_AB = 
	((0xffffU & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA)) 
	 * (0xffffU & (IData)((vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA 
			       >> 0x10U))));
    // ALWAYS at ExOp2.v:887
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRuB_BA = 
	((0xffffU & (IData)((vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA 
			     >> 0x10U))) * (0xffffU 
					    & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA)));
    // ALWAYS at ExOp2.v:241
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutGbr = vlTOPp->ExUnit__DOT__gpr__DOT__regGbr;
    // ALWAYS at ExOp2.v:242
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutVbr = vlTOPp->ExUnit__DOT__gpr__DOT__regVbr;
    // ALWAYS at ExUnit.v:564
    vlTOPp->ExUnit__DOT__exNextFpul2 = vlTOPp->ExUnit__DOT__gpr__DOT__regFpul;
    // ALWAYS at ExOp2.v:243
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSSr = vlTOPp->ExUnit__DOT__gpr__DOT__regSSr;
    // ALWAYS at ExOp2.v:244
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSPc = vlTOPp->ExUnit__DOT__gpr__DOT__regSPc;
    // ALWAYS at ExOp2.v:245
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSGr = vlTOPp->ExUnit__DOT__gpr__DOT__regSGr;
    // ALWAYS at ExUnit.v:441
    vlTOPp->ExUnit__DOT__regIdCsFl = 0U;
    vlTOPp->ExUnit__DOT__regIdCsFl = (1U | (IData)(vlTOPp->ExUnit__DOT__regIdCsFl));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xfffdU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (2U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
					       >> 0x12U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xfffbU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (4U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
					       >> 0x12U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xfff7U & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (8U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
					       >> 0x12U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xffefU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (0x10U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
						  >> 0x14U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xffdfU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (0x20U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						  >> 0x1aU)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xffbfU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (0x40U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						  >> 6U)));
    // ALWAYS at ExUnit.v:603
    vlTOPp->ExUnit__DOT__idWbRegO = vlTOPp->ExUnit__DOT__wbRegO;
    vlTOPp->ExUnit__DOT__idWbRegValO = vlTOPp->ExUnit__DOT__wbRegValO;
    if ((((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad) 
	  | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore)) 
	 & (1U == (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK)))) {
	vlTOPp->ExUnit__DOT__idWbRegO = vlTOPp->ExUnit__DOT__dec__DOT__opRegN;
	vlTOPp->ExUnit__DOT__idWbRegValO = (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutData);
    } else {
	vlTOPp->ExUnit__DOT__idWbRegO = vlTOPp->ExUnit__DOT__wbRegO;
	vlTOPp->ExUnit__DOT__idWbRegValO = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    // ALWAYS at RegGPR2.v:423
    vlTOPp->ExUnit__DOT__gpr__DOT__regSrRB = (1U & 
					      (vlTOPp->ExUnit__DOT__regIdSr 
					       >> 0x1dU));
    // ALWAYS at ModNtsc.v:142
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc 
	= (0x3fffffU & ((IData)(0x24a79U) + vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk 
	= (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0x4cU;
    if ((0U < (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk = 0U;
	if ((0xc68U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk 
		= (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk) 
			 - (IData)(1U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = 0U;
	} else {
	    if ((0x1d8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0U;
	    }
	}
    } else {
	if ((0U < (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk = 0U;
	    if ((0xc68U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk 
		    = (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk) 
			     - (IData)(1U)));
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = 0U;
	    } else {
		if ((0xb80U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0U;
		}
	    }
	} else {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCb 
		= (0x1fU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
			    >> 0x11U));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCu 
		= (0x1fU & ((IData)(0xbU) + (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
					     >> 0x11U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCv 
		= (0x1fU & ((IData)(3U) + (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
					   >> 0x11U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu 
		= (0xffffU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab
			      [vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCu] 
			      - (IData)(0x80U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv 
		= (0xffffU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab
			      [vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCv] 
			      - (IData)(0x80U)));
	    if ((0x18d0U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk 
		    = (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk)));
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = 0U;
		if ((0x106U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt 
			= (3U & ((IData)(1U) + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt)));
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk = 5U;
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk 
			= (7U & ((1U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))
				  ? 5U : 6U));
		    if ((0U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
			vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0U;
		    } else {
			if ((1U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0x100000U;
			} else {
			    if ((2U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
				vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0x200000U;
			    } else {
				if ((3U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
				    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0x300000U;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x16f8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0U;
		} else {
		    if (((0x70U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)) 
			 & (0x168U > (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)))) {
			vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal 
			    = (0xffU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab
					[vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCb] 
					- (IData)(0x20U)));
		    } else {
			if (((0x1d8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)) 
			     & (0x15d8U > (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)))) {
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX 
				= (0x3ffU & (((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk) 
					      >> 3U) 
					     - (IData)(0x3bU)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY 
				= (0x3ffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk) 
					     - (IData)(0x14U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy 
				= (0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCu) 
					      - (IData)(0x80U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCv) 
					      - (IData)(0x80U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy 
				= (0xffffU & vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy);
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy 
				= ((0xff00U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy)) 
				   | (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCy));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy 
				= ((0x30000U & vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy) 
				   | (0xffffU & ((IData)(0x4c00U) 
						 + 
						 ((IData)(0x90U) 
						  * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCy)))));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCu 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCu) 
					      * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCu)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCv 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCv) 
					      * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCv)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCt 
				= (0x3ffU & (((vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy 
					       >> 8U) 
					      + ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCu) 
						 >> 6U)) 
					     + ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCv) 
						>> 6U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal 
				= (0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCt));
			}
		    }
		}
	    }
	}
    }
    // ALWAYSPOST at ModTxtMemW.v:161
    if (__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D[__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0] 
	    = __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D__v0;
    }
    // ALWAYSPOST at ModTxtMemW.v:160
    if (__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C[__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0] 
	    = __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C__v0;
    }
    // ALWAYSPOST at ModTxtMemW.v:159
    if (__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B[__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0] 
	    = __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B__v0;
    }
    // ALWAYSPOST at ModTxtMemW.v:158
    if (__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A[__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0] 
	    = __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A__v0;
    }
    // ALWAYSPOST at ModTxtMemW.v:152
    if (__Vdlyvset__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl[__Vdlyvdim0__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0] 
	    = __Vdlyvval__ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl__v0;
    }
    // ALWAYS at ModFbTxtW.v:293
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextIx;
    // ALWAYS at ExOp2.v:882
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpA0 = vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp;
    // ALWAYS at ExOp2.v:880
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRsA = vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs;
    // ALWAYS at ExUnit.v:624
    if (VL_UNLIKELY(vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE)) {
	VL_WRITEF("ExUnit: memIfPcOE\n");
	vlTOPp->ExUnit__DOT__dc2RegInAddr = vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr;
	vlTOPp->ExUnit__DOT__dc2RegInData[0U] = 0U;
	vlTOPp->ExUnit__DOT__dc2RegInData[1U] = 0U;
	vlTOPp->ExUnit__DOT__dc2RegInData[2U] = 0U;
	vlTOPp->ExUnit__DOT__dc2RegInData[3U] = 0U;
	vlTOPp->ExUnit__DOT__dc2RegInOE = vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE;
	vlTOPp->ExUnit__DOT__dc2RegInWR = 0U;
	vlTOPp->ExUnit__DOT__dc2RegInOp = 1U;
	vlTOPp->ExUnit__DOT__memIfPcData[0U] = vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U];
	vlTOPp->ExUnit__DOT__memIfPcData[1U] = vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U];
	vlTOPp->ExUnit__DOT__memIfPcData[2U] = vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U];
	vlTOPp->ExUnit__DOT__memIfPcData[3U] = vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U];
	vlTOPp->ExUnit__DOT__memIfPcOK = vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK;
	vlTOPp->ExUnit__DOT__dcfMemInData[0U] = 0U;
	vlTOPp->ExUnit__DOT__dcfMemInData[1U] = 0U;
	vlTOPp->ExUnit__DOT__dcfMemInData[2U] = 0U;
	vlTOPp->ExUnit__DOT__dcfMemInData[3U] = 0U;
	vlTOPp->ExUnit__DOT__dcfMemPcOK = (((IData)(vlTOPp->ExUnit__DOT__dcfMemPcOE) 
					    | (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR))
					    ? 2U : 0U);
    } else {
	if (((IData)(vlTOPp->ExUnit__DOT__dcfMemPcOE) 
	     | (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR))) {
	    vlTOPp->ExUnit__DOT__dc2RegInAddr = vlTOPp->ExUnit__DOT__dcfMemPcAddr;
	    vlTOPp->ExUnit__DOT__dc2RegInData[0U] = 
		vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U];
	    vlTOPp->ExUnit__DOT__dc2RegInData[1U] = 
		vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U];
	    vlTOPp->ExUnit__DOT__dc2RegInData[2U] = 
		vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U];
	    vlTOPp->ExUnit__DOT__dc2RegInData[3U] = 
		vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U];
	    vlTOPp->ExUnit__DOT__dc2RegInOE = vlTOPp->ExUnit__DOT__dcfMemPcOE;
	    vlTOPp->ExUnit__DOT__dc2RegInWR = vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR;
	    vlTOPp->ExUnit__DOT__dc2RegInOp = vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp;
	    vlTOPp->ExUnit__DOT__dcfMemInData[0U] = 
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U];
	    vlTOPp->ExUnit__DOT__dcfMemInData[1U] = 
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U];
	    vlTOPp->ExUnit__DOT__dcfMemInData[2U] = 
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U];
	    vlTOPp->ExUnit__DOT__dcfMemInData[3U] = 
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U];
	    vlTOPp->ExUnit__DOT__dcfMemPcOK = vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK;
	    vlTOPp->ExUnit__DOT__memIfPcData[0U] = 0U;
	    vlTOPp->ExUnit__DOT__memIfPcData[1U] = 0U;
	    vlTOPp->ExUnit__DOT__memIfPcData[2U] = 0U;
	    vlTOPp->ExUnit__DOT__memIfPcData[3U] = 0U;
	    vlTOPp->ExUnit__DOT__memIfPcOK = ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE)
					       ? 2U
					       : 0U);
	} else {
	    vlTOPp->ExUnit__DOT__dc2RegInAddr = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInData[0U] = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInData[1U] = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInData[2U] = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInData[3U] = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInOE = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInWR = 0U;
	    vlTOPp->ExUnit__DOT__dc2RegInOp = 1U;
	}
    }
    if ((0x55U != (IData)(vlTOPp->ExUnit__DOT__regRstTok))) {
	__Vdly__ExUnit__DOT__regIfPc = 0xa0000000U;
	__Vdly__ExUnit__DOT__regIfSr = 0U;
	__Vdly__ExUnit__DOT__regIdPc = 0xa0000000U;
	vlTOPp->ExUnit__DOT__regIdSr = 0U;
	__Vdly__ExUnit__DOT__regIdPcVal = VL_ULL(0);
	vlTOPp->ExUnit__DOT__regExPcVal = VL_ULL(0);
	vlTOPp->ExUnit__DOT__regExPc = 0xa0000000U;
	vlTOPp->ExUnit__DOT__exStepPc = 0U;
	vlTOPp->ExUnit__DOT__exStepPc2 = 0U;
    } else {
	if (vlTOPp->ExUnit__DOT__tRegExHold) {
	    VL_WRITEF("Hold\n");
	} else {
	    VL_WRITEF("Step\n");
	    vlTOPp->ExUnit__DOT__regIdSr = vlTOPp->ExUnit__DOT__regIfSr;
	    vlTOPp->ExUnit__DOT__regExPcVal = vlTOPp->ExUnit__DOT__regIdPcVal;
	    vlTOPp->ExUnit__DOT__regExPc = vlTOPp->ExUnit__DOT__regIdPc;
	    vlTOPp->ExUnit__DOT__exRegN = vlTOPp->ExUnit__DOT__dec__DOT__opRegN;
	    vlTOPp->ExUnit__DOT__exRegS = vlTOPp->ExUnit__DOT__dec__DOT__opRegS;
	    vlTOPp->ExUnit__DOT__exRegT = vlTOPp->ExUnit__DOT__dec__DOT__opRegT;
	    vlTOPp->ExUnit__DOT__exImm = vlTOPp->ExUnit__DOT__dec__DOT__opImm;
	    vlTOPp->ExUnit__DOT__exStepPc = vlTOPp->ExUnit__DOT__dec__DOT__opStepPc;
	    vlTOPp->ExUnit__DOT__exStepPc2 = vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2;
	    vlTOPp->ExUnit__DOT__exUCmd = vlTOPp->ExUnit__DOT__idUCmd2;
	    vlTOPp->ExUnit__DOT__exRegValN = vlTOPp->ExUnit__DOT__idRegValN2;
	    vlTOPp->ExUnit__DOT__exRegValS = vlTOPp->ExUnit__DOT__idRegValS2;
	    vlTOPp->ExUnit__DOT__exRegValT = vlTOPp->ExUnit__DOT__idRegValT2;
	    __Vdly__ExUnit__DOT__regIfSr = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr;
	    __Vdly__ExUnit__DOT__regIdPc = vlTOPp->ExUnit__DOT__regIfPc;
	    __Vdly__ExUnit__DOT__regIdPcVal = vlTOPp->ExUnit__DOT__regIfPcVal2;
	    __Vdly__ExUnit__DOT__regIfPc = vlTOPp->ExUnit__DOT__exNextPc2;
	}
    }
    // ALWAYS at ModFbTxtW.v:134
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX 
	= ((0x3fc0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX)) 
	   | (0x3fU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX) 
		       >> 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY 
	= ((0x3f80U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY)) 
	   | (0x7fU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY) 
		       >> 3U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextIx 
	= (0x3fffU & ((((IData)(0x28U) * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY)) 
		       + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX)) 
		      - (IData)(0x50U)));
    vlTOPp->ExUnit__DOT__regIfSr = __Vdly__ExUnit__DOT__regIfSr;
    vlTOPp->ExUnit__DOT__regIdPc = __Vdly__ExUnit__DOT__regIdPc;
    vlTOPp->ExUnit__DOT__regIfPc = __Vdly__ExUnit__DOT__regIfPc;
    vlTOPp->ExUnit__DOT__regIdPcVal = __Vdly__ExUnit__DOT__regIdPcVal;
    // ALWAYS at ModFbTxtW.v:139
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx 
	= ((0xcU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)) 
	   | (3U & ((IData)(3U) - ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX) 
				   >> 2U))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx 
	= ((3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)) 
	   | (0xcU & (((IData)(3U) - ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY) 
				      >> 1U)) << 2U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx 
	= ((0x38U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx)) 
	   | (7U & ((IData)(7U) - ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX) 
				   >> 1U))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx 
	= ((7U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx)) 
	   | (0x38U & (((IData)(7U) - (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY)) 
		       << 3U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[2U];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[3U];
    if ((0x7d0U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U] = 0U;
    }
    if ((0x3e8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U] = 0U;
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph 
	= (0xffffU & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U]);
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA 
	= (0x3fU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		     << 0x10U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				  >> 0x10U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB 
	= (0x3fU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		     << 0xaU) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				 >> 0x16U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A 
	= (0x1ffU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		      << 0x16U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				   >> 0xaU)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B 
	= (0x1ffU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		      << 0xdU) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				  >> 0x13U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB = 0U;
    if ((0U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		       << 4U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				 >> 0x1cU))))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0xc00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			    << 6U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0xc00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			    << 6U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xcffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0x300U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			    << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xcffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0x300U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			    << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xf3fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0xc0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			   << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xf3fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0xc0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			   << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xfcfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0x30U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			   << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xfcfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0x30U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			   << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xff3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			  << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xff3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			  << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xffcU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xffcU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB)));
    } else {
	if ((2U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			   << 4U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				     >> 0x1cU))))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
		= ((0x1ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
		   | (0xe00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A) 
				<< 3U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
		= ((0x1ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
		   | (0xe00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B) 
				<< 3U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
		= ((0xf1fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
		   | (0xe0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A) 
			       << 2U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
		= ((0xf1fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
		   | (0xe0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B) 
			       << 2U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
		= ((0xff1U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
		   | (0xeU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A) 
			      << 1U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
		= ((0xff1U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
		   | (0xeU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B) 
			      << 1U)));
	}
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	= ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	   | (0xf00U & ((((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
				 >> 5U)) + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
						  >> 0xaU))) 
			 + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
				  >> 2U))) << 8U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	= ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	   | (0xf00U & ((((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
				 >> 5U)) + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
						  >> 0xaU))) 
			 + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
				  >> 2U))) << 8U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	= ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	   | (0xf0U & (((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
					      >> 1U)) 
				       - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
						>> 5U)))) 
		       << 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	= ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	   | (0xf0U & (((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
					      >> 1U)) 
				       - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
						>> 5U)))) 
		       << 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	= ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	   | (0xfU & ((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
					    >> 9U)) 
				     - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
					      >> 5U))))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	= ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	   | (0xfU & ((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
					    >> 9U)) 
				     - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
					      >> 5U))))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData1;
    if ((2U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		       << 2U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				 >> 0x1eU))))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
	    = (((QData)((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U])) 
		<< 0x20U) | (QData)((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U])));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	    = ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	       | (0xf00U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			     << 0x10U) | (0xff00U & 
					  (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					   >> 0x10U)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	    = ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	       | (0xf00U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			     << 0x16U) | (0x3fff00U 
					  & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					     >> 0xaU)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	    = ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	       | (0xf0U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			    << 0x18U) | (0xfffff0U 
					 & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					    >> 8U)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	    = ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	       | (0xf0U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			    << 0x1cU) | (0xffffff0U 
					 & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					    >> 4U)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	    = ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	       | (0xfU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			   << 0x1cU) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					>> 4U))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	    = ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	       | (0xfU & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U]));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphU 
	    = (0xffffU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] 
			   << 0x10U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
					>> 0x10U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphV 
	    = (0xffffU & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U]);
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
	    = ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)) 
	       | (0xf00U & (((1U & (IData)((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
					    >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx))))
			      ? ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA) 
				 >> 8U) : ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB) 
					   >> 8U)) 
			    << 8U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
	    = ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)) 
	       | (0xf0U & (((1U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphU) 
				   >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)))
			     ? ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA) 
				>> 4U) : ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB) 
					  >> 4U)) << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
	    = ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)) 
	       | (0xfU & ((1U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphV) 
				 >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)))
			   ? (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)
			   : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB))));
    } else {
	if ((0U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U] 
			   << 2U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U] 
				     >> 0x1eU))))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
		= ((1U & (IData)((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
				  >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx))))
		    ? (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)
		    : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB));
	} else {
	    if ((1U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U] 
			       << 2U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U] 
					 >> 0x1eU))))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
		    = ((1U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph) 
			      >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)))
		        ? (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)
		        : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB));
	    }
	}
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy 
	= ((0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy)) 
	   | (0xf0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		       >> 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy 
	= ((0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy)) 
	   | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		      >> 8U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu 
	= ((0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu)) 
	   | (0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu 
	= ((0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu)) 
	   | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		      >> 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv 
	= ((0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv)) 
	   | (0xf0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		       << 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv 
	= ((0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv)) 
	   | (0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)));
    // ALWAYS at ExUnit.v:595
    vlTOPp->ExUnit__DOT__regRstTok = vlTOPp->ExUnit__DOT__regNextRstTok;
    // ALWAYS at DcTile3.v:143
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc1 = vlTOPp->ExUnit__DOT__dcfRegInAddr;
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc2 = ((IData)(4U) 
						+ vlTOPp->ExUnit__DOT__dcfRegInAddr);
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc1 
						     >> 4U));
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc2 
						     >> 4U));
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutData = VL_ULL(0);
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3 = vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1;
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd4 = vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[0U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[1U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[2U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[3U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[4U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 = VL_ULL(0);
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccCommitOK = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqNeedAd = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 0U;
    if ((5U == (7U & (vlTOPp->ExUnit__DOT__dcfRegInAddr 
		      >> 0x1dU)))) {
	vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 1U;
    }
    if ((6U == (7U & (vlTOPp->ExUnit__DOT__dcfRegInAddr 
		      >> 0x1dU)))) {
	vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 1U;
    }
    if ((7U == (7U & (vlTOPp->ExUnit__DOT__dcfRegInAddr 
		      >> 0x1dU)))) {
	vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 1U;
    }
    if ((((IData)(vlTOPp->ExUnit__DOT__dcfRegInOE) 
	  | (IData)(vlTOPp->ExUnit__DOT__dcfRegInWR)) 
	 & (0U == (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt)))) {
	if (vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache) {
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit = 0U;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
		= ((0xc0000003U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
		   | (0x3ffffffcU & vlTOPp->ExUnit__DOT__dcfRegInAddr));
	    VL_EXTEND_WI(128,32, __Vtemp2, (IData)(vlTOPp->ExUnit__DOT__dcfRegInData));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
		= __Vtemp2[0U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U] 
		= __Vtemp2[1U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U] 
		= __Vtemp2[2U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U] 
		= __Vtemp2[3U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE 
		= vlTOPp->ExUnit__DOT__dcfRegInOE;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR 
		= vlTOPp->ExUnit__DOT__dcfRegInWR;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 1U;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK 
		= vlTOPp->ExUnit__DOT__dcfMemPcOK;
	} else {
	    if (((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1 
		  == vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
		  [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1)]) 
		 & (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2 
		    == vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
		    [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2)]))) {
		vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit = 1U;
	    } else {
		if ((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1 
		     == vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
		     [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1)])) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2;
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1;
		}
	    }
	}
	if (vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit) {
	    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
		= ((8U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
		    ? ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
		        ? (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U])))
		        : (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U]))))
		    : ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
		        ? (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U])))
		        : (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U])))));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData 
		= ((0x10U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		    ? ((8U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? vlTOPp->ExUnit__DOT__dcfRegInData
			    : (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       ^ vlTOPp->ExUnit__DOT__dcfRegInData))
		        : ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       | vlTOPp->ExUnit__DOT__dcfRegInData)
			    : (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       & vlTOPp->ExUnit__DOT__dcfRegInData)))
		    : ((8U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? vlTOPp->ExUnit__DOT__dcfRegInData
			    : (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       - vlTOPp->ExUnit__DOT__dcfRegInData))
		        : ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       + vlTOPp->ExUnit__DOT__dcfRegInData)
			    : vlTOPp->ExUnit__DOT__dcfRegInData)));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx = 
		(3U == (7U & ((IData)(vlTOPp->ExUnit__DOT__dcfRegInOp) 
			      >> 2U)));
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData;
		} else {
		    if ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xff00000000ffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData))) 
				      << 0x18U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x38U))))) 
				      << 0x38U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffff00000000ffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData))) 
				      << 0x10U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x30U))))) 
				      << 0x30U));
			}
		    } else {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff00000000ff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData))) 
				      << 8U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x28U))))) 
				      << 0x28U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff00000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(
							      (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
							       >> 0x20U)))) 
				      << 0x20U));
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))) {
		    if ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff0000ffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x18U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x28U))))) 
				      << 0x28U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff0000ffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x10U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(
							      (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
							       >> 0x20U)))) 
				      << 0x20U));
			}
		    } else {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff0000ff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 8U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffff000000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffffff0000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			}
		    }
		} else {
		    if ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff00ffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x18U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(
							      (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
							       >> 0x20U)))) 
				      << 0x20U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff00ffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x10U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffff000000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			}
		    } else {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff00ff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 8U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffffff0000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xff) & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffffffff00) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			}
		    }
		}
	    }
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit 
		= ((IData)(vlTOPp->ExUnit__DOT__dcfRegInWR) 
		   & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accHit));
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 
		= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3;
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 
		= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd4;
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 1U;
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccCommitOK 
		= ((IData)(vlTOPp->ExUnit__DOT__dcfRegInWR) 
		   & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accHit));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK 
		= ((((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accHit) 
		     & (~ (IData)(vlTOPp->ExUnit__DOT__dcfRegInWR))) 
		    | (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accCommitOK))
		    ? 1U : 2U);
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutData 
		= ((2U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2
		        : ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			    ? ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x37U)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(
								(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								 >> 0x18U))))
			        : (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x2fU)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(
								(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								 >> 0x10U)))))
			    : ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x27U)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(
								(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								 >> 8U))))
			        : (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x1fU)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2))))))
		    : ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			    ? ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x27U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(
									   (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									    >> 0x18U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x1fU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(
									   (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									    >> 0x10U)))))))
			    : ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x17U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(
									   (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									    >> 8U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0xfU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2)))))))
		        : ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			    ? ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x1fU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(
									(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									 >> 0x18U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x17U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(
									(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									 >> 0x10U)))))))
			    : ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0xfU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(
									(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									 >> 8U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 7U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2)))))))));
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U];
	    if ((8U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
		if ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		}
	    } else {
		if ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		}
	    }
	}
    }
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit = 0U;
    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
	if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
		      >> 2U)))) {
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 0xbU;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 0xaU;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 9U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 7U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 6U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 5U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= (0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr);
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[1U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[2U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[3U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= (0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr);
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 0U;
		} else {
		    if ((0U != vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)) {
			vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqNeedAd 
			    = vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd;
			vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 4U;
			if ((1U & vlTOPp->ExUnit__DOT__dcf__DOT__icBlkFl
			     [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)])) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 8U;
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ExUnit__DOT__dcl2__DOT__addrIsRam = ((0xc000000U 
						  <= 
						  (0x1fffffffU 
						   & vlTOPp->ExUnit__DOT__dc2RegInAddr)) 
						 & (0x1e000000U 
						    >= 
						    (0x1fffffffU 
						     & vlTOPp->ExUnit__DOT__dc2RegInAddr)));
    // ALWAYS at IcTile2.v:89
    vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc1 = vlTOPp->ExUnit__DOT__regIfPc;
    vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc2 = ((IData)(4U) 
						+ vlTOPp->ExUnit__DOT__regIfPc);
    vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc1 
						     >> 4U));
    vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc2 
						     >> 4U));
    vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal = VL_ULL(0xf3b0f3b0f3b);
    vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcOK = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = 0U;
    if (((vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1 
	  == vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd
	  [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)]) 
	 & (vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2 
	    == vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2)]))) {
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[0U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkA
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcOK = 1U;
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkB
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkC
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkD
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkE
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2)];
	vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal 
	    = (VL_ULL(0xffffffffffff) & ((8U & vlTOPp->ExUnit__DOT__regIfPc)
					  ? ((4U & vlTOPp->ExUnit__DOT__regIfPc)
					      ? ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U])) 
						   << 0x10U) 
						  | ((QData)((IData)(
								     vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						     >> 0x10U))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U]))))
					      : ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U])) 
						   << 0x30U) 
						  | (((QData)((IData)(
								      vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						      << 0x10U) 
						     | ((QData)((IData)(
									vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
							>> 0x10U)))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])))))
					  : ((4U & vlTOPp->ExUnit__DOT__regIfPc)
					      ? ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						   << 0x30U) 
						  | (((QData)((IData)(
								      vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
						      << 0x10U) 
						     | ((QData)((IData)(
									vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U])) 
							>> 0x10U)))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U]))))
					      : ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
						   << 0x30U) 
						  | (((QData)((IData)(
								      vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U])) 
						      << 0x10U) 
						     | ((QData)((IData)(
									vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[0U])) 
							>> 0x10U)))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[0U])))))));
    } else {
	if ((0U == (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	    if ((vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1 
		 == vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd
		 [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)])) {
		VL_WRITEF("IcMiss2 %x\n",28,vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2);
		vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd 
		    = vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2;
	    } else {
		VL_WRITEF("IcMiss1 %x\n",28,vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1);
		vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd 
		    = vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = 1U;
	    }
	}
    }
    vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[0U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[1U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[2U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[3U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[4U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1 = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2 = 0U;
    if ((4U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 0U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
	    } else {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 7U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 6U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
	    } else {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 5U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
	    }
	}
    } else {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))))) {
		VL_WRITEF("IcTile2: Get2 %x\n",128,
			  vlTOPp->ExUnit__DOT__memIfPcData);
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[1U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[2U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[3U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 0U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit 
		    = (1U == (IData)(vlTOPp->ExUnit__DOT__memIfPcOK));
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = (0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr);
	    }
	} else {
	    if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt)))) {
		if (vlTOPp->ExUnit__DOT__icf__DOT__doReqNeedAd) {
		    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqNeedAd 
			= vlTOPp->ExUnit__DOT__icf__DOT__reqNeedAd;
		    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 2U;
		}
	    }
	}
    }
    // ALWAYS at DecOp4_XE.v:82
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord 
	= (0xffffU & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
			      >> 0x10U)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord 
	= (0xffffU & (IData)(vlTOPp->ExUnit__DOT__regIdPcVal));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl 
	= (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
		   >> 8U));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl 
	= (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
		   >> 4U));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegO_Dfl 
	= (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl 
	= (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
		   >> 4U));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_Dfl 
	= (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_FR 
	= (0x40U | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
			    >> 8U)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_FR 
	= (0x40U | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
			    >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_FR 
	= (0x40U | (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xffffffU : 0U) << 8U) | (0xffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Zx8E 
	= (0xffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Nx8E 
	= (0xffffff00U | (0xffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmM12_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xfffffU : 0U) << 0xcU) | ((0xff0U 
					    & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					       << 4U)) 
					   | (0xfU 
					      & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						 >> 4U))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xfffffU : 0U) << 0xcU) | ((0xff0U 
					    & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					       << 4U)) 
					   | (0xfU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xffffU : 0U) << 0x10U) | ((0xff00U 
					    & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					       << 8U)) 
					   | (0xffU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm20_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xfffU : 0U) << 0x14U) | ((0xff000U 
					   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					      << 0xcU)) 
					  | (0xfffU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm4_ZxXE 
	= (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 3U;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x1fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 0U;
    if ((0x8000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
	if ((0x4000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
			      >> 0xcU)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 2U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xcU;
		}
	    } else {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
			      >> 0xcU)))) {
		    if ((0x800U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 0xaU)))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x14U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x15U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x13U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x11U;
				}
			    }
			}
		    } else {
			if ((0x400U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					      >> 8U)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x17U;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xdU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x17U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xcU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x17U;
				}
			    }
			} else {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					      >> 8U)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x13U;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x13U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 8U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x13U;
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x31U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xfU;
		} else {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x30U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xfU;
		}
	    } else {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x50U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xcU;
		} else {
		    if ((0x800U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((0x400U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x35U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x34U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    }
			} else {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x37U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x36U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x38U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				}
			    }
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 0xaU)))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x33U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x32U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((0x4000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x10U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xcU;
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 7U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 6U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 5U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 4U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 7U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 6U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 5U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 4U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xdU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xcU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 6U;
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    if ((0U == (0xfU 
						& ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						   >> 4U)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4cU;
					vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
				    } else {
					if ((1U == 
					     (0xfU 
					      & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						 >> 4U)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4dU;
					    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
					}
				    }
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x17U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 0U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x16U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 0U;
				}
			    }
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    if ((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
					if ((0x40U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
					    if ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						if (
						    (1U 
						     & (~ 
							((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
							 >> 4U)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x23U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x14U;
						}
					    } else {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x22U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x14U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x21U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x14U;
						}
					    }
					} else {
					    if ((1U 
						 & (~ 
						    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						     >> 5U)))) {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x6dU;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x16U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    }
					}
				    } else {
					if ((0x40U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
					    if ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x6cU;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x17U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    } else {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x15U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x14U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    }
					} else {
					    if ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x13U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x12U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    } else {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x11U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x10U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
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
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					  >> 1U)))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x10U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			} else {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					  >> 1U)))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x11U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x39U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3aU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3bU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				}
			    } else {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x38U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				}
			    }
			}
		    }
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x12U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 2U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x12U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x14U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x15U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x13U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xbU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 8U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 6U;
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xdU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xcU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xbU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 8U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		} else {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		}
	    } else {
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_FR;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_FR;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_FR;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
		    }
		}
	    }
	}
    } else {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			= ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))
			    ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm20_Sx8E
			    : vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E);
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				       >> 8U));
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmM12_Sx8E;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = ((0U == (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx))
			        ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E
			        : ((1U == (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx))
				    ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Zx8E
				    : ((2U == (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx))
				        ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Nx8E
				        : 0U)));
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegO_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm4_ZxXE;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		}
	    }
	}
    }
}

void VExUnit::_initial__TOP__3(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_initial__TOP__3\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign316[4];
    VL_SIGW(__Vtemp4,95,0,3);
    //char	__VpadToAlign332[4];
    VL_SIGW(__Vtemp5,95,0,3);
    //char	__VpadToAlign348[4];
    VL_SIGW(__Vtemp6,95,0,3);
    //char	__VpadToAlign364[4];
    VL_SIGW(__Vtemp7,127,0,4);
    VL_SIGW(__Vtemp8,127,0,4);
    VL_SIGW(__Vtemp9,127,0,4);
    VL_SIGW(__Vtemp10,127,0,4);
    // Body
    // INITIAL at ModTxtMemW.v:67
    __Vtemp4[0U] = 0x2e747874U;
    __Vtemp4[1U] = 0x746d656dU;
    __Vtemp4[2U] = 0x666f6eU;
    VL_READMEM_W (true,64,256, 0,3, __Vtemp4, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontMem
		  ,0,~0);
    __Vtemp5[0U] = 0x2e747874U;
    __Vtemp5[1U] = 0x6f6e7430U;
    __Vtemp5[2U] = 0x67667866U;
    VL_READMEM_W (true,64,128, 0,3, __Vtemp5, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx1Mem
		  ,0,~0);
    __Vtemp6[0U] = 0x2e747874U;
    __Vtemp6[1U] = 0x6f6e7431U;
    __Vtemp6[2U] = 0x67667866U;
    VL_READMEM_W (true,64,128, 0,3, __Vtemp6, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx2Mem
		  ,0,~0);
    __Vtemp7[0U] = 0x2e747874U;
    __Vtemp7[1U] = 0x6d5f3161U;
    __Vtemp7[2U] = 0x63726d65U;
    __Vtemp7[3U] = 0x73U;
    VL_READMEM_W (true,32,1024, 0,4, __Vtemp7, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A
		  ,0,~0);
    __Vtemp8[0U] = 0x2e747874U;
    __Vtemp8[1U] = 0x6d5f3162U;
    __Vtemp8[2U] = 0x63726d65U;
    __Vtemp8[3U] = 0x73U;
    VL_READMEM_W (true,32,1024, 0,4, __Vtemp8, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B
		  ,0,~0);
    __Vtemp9[0U] = 0x2e747874U;
    __Vtemp9[1U] = 0x6d5f3163U;
    __Vtemp9[2U] = 0x63726d65U;
    __Vtemp9[3U] = 0x73U;
    VL_READMEM_W (true,32,1024, 0,4, __Vtemp9, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C
		  ,0,~0);
    __Vtemp10[0U] = 0x2e747874U;
    __Vtemp10[1U] = 0x6d5f3164U;
    __Vtemp10[2U] = 0x63726d65U;
    __Vtemp10[3U] = 0x73U;
    VL_READMEM_W (true,32,1024, 0,4, __Vtemp10, vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D
		  ,0,~0);
}

void VExUnit::_settle__TOP__4(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_settle__TOP__4\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign452[4];
    VL_SIGW(__Vtemp11,127,0,4);
    VL_SIGW(__Vtemp14,127,0,4);
    VL_SIGW(__Vtemp15,127,0,4);
    VL_SIGW(__Vtemp16,127,0,4);
    VL_SIGW(__Vtemp17,127,0,4);
    VL_SIGW(__Vtemp18,127,0,4);
    VL_SIGW(__Vtemp19,127,0,4);
    VL_SIGW(__Vtemp20,127,0,4);
    VL_SIGW(__Vtemp21,127,0,4);
    VL_SIGW(__Vtemp22,127,0,4);
    VL_SIGW(__Vtemp23,127,0,4);
    VL_SIGW(__Vtemp24,127,0,4);
    VL_SIGW(__Vtemp25,127,0,4);
    // Body
    // ALWAYS at ModNtsc.v:137
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextSt8 
	= (0xffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8) 
		    + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal)));
    // ALWAYS at ModNtsc.v:137
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmCarry 
	= (1U & (((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8) 
		  + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal)) 
		 >> 8U));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmOut 
	= ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmCarry)
	    ? 0xfU : 0U);
    // ALWAYS at ExOp2.v:241
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutGbr = vlTOPp->ExUnit__DOT__gpr__DOT__regGbr;
    // ALWAYS at ExOp2.v:242
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutVbr = vlTOPp->ExUnit__DOT__gpr__DOT__regVbr;
    // ALWAYS at ExUnit.v:564
    vlTOPp->ExUnit__DOT__exNextFpul2 = vlTOPp->ExUnit__DOT__gpr__DOT__regFpul;
    // ALWAYS at ExOp2.v:243
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSSr = vlTOPp->ExUnit__DOT__gpr__DOT__regSSr;
    // ALWAYS at ExOp2.v:244
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSPc = vlTOPp->ExUnit__DOT__gpr__DOT__regSPc;
    // ALWAYS at ExOp2.v:245
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSGr = vlTOPp->ExUnit__DOT__gpr__DOT__regSGr;
    // ALWAYS at ExUnit.v:441
    vlTOPp->ExUnit__DOT__regIdCsFl = 0U;
    vlTOPp->ExUnit__DOT__regIdCsFl = (1U | (IData)(vlTOPp->ExUnit__DOT__regIdCsFl));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xfffdU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (2U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
					       >> 0x12U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xfffbU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (4U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
					       >> 0x12U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xfff7U & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (8U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
					       >> 0x12U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xffefU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (0x10U & (vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr 
						  >> 0x14U)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xffdfU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (0x20U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						  >> 0x1aU)));
    vlTOPp->ExUnit__DOT__regIdCsFl = ((0xffbfU & (IData)(vlTOPp->ExUnit__DOT__regIdCsFl)) 
				      | (0x40U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						  >> 6U)));
    // ALWAYS at ModNtsc.v:142
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc 
	= (0x3fffffU & ((IData)(0x24a79U) + vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk 
	= (0x1fffU & ((IData)(1U) + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0x4cU;
    if ((0U < (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk = 0U;
	if ((0xc68U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk 
		= (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk) 
			 - (IData)(1U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = 0U;
	} else {
	    if ((0x1d8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0U;
	    }
	}
    } else {
	if ((0U < (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk = 0U;
	    if ((0xc68U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk 
		    = (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk) 
			     - (IData)(1U)));
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = 0U;
	    } else {
		if ((0xb80U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0U;
		}
	    }
	} else {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCb 
		= (0x1fU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
			    >> 0x11U));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCu 
		= (0x1fU & ((IData)(0xbU) + (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
					     >> 0x11U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCv 
		= (0x1fU & ((IData)(3U) + (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc 
					   >> 0x11U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu 
		= (0xffffU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab
			      [vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCu] 
			      - (IData)(0x80U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv 
		= (0xffffU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab
			      [vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCv] 
			      - (IData)(0x80U)));
	    if ((0x18d0U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk 
		    = (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk)));
		vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = 0U;
		if ((0x106U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt 
			= (3U & ((IData)(1U) + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt)));
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk = 5U;
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk 
			= (7U & ((1U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))
				  ? 5U : 6U));
		    if ((0U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
			vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0U;
		    } else {
			if ((1U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0x100000U;
			} else {
			    if ((2U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
				vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0x200000U;
			    } else {
				if ((3U == (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt))) {
				    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = 0x300000U;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x16f8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = 0U;
		} else {
		    if (((0x70U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)) 
			 & (0x168U > (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)))) {
			vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal 
			    = (0xffU & (vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab
					[vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCb] 
					- (IData)(0x20U)));
		    } else {
			if (((0x1d8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)) 
			     & (0x15d8U > (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk)))) {
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX 
				= (0x3ffU & (((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk) 
					      >> 3U) 
					     - (IData)(0x3bU)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY 
				= (0x3ffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk) 
					     - (IData)(0x14U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy 
				= (0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCu) 
					      - (IData)(0x80U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCv) 
					      - (IData)(0x80U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy 
				= (0xffffU & vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy);
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy 
				= ((0xff00U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy)) 
				   | (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCy));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy 
				= ((0x30000U & vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy) 
				   | (0xffffU & ((IData)(0x4c00U) 
						 + 
						 ((IData)(0x90U) 
						  * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCy)))));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCu 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCu) 
					      * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCu)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCv 
				= (0xffffU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCv) 
					      * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCv)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCt 
				= (0x3ffU & (((vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy 
					       >> 8U) 
					      + ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCu) 
						 >> 6U)) 
					     + ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCv) 
						>> 6U)));
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal 
				= (0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCt));
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ModFbTxtW.v:134
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX 
	= ((0x3fc0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX)) 
	   | (0x3fU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX) 
		       >> 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY 
	= ((0x3f80U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY)) 
	   | (0x7fU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY) 
		       >> 3U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextIx 
	= (0x3fffU & ((((IData)(0x28U) * (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY)) 
		       + (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX)) 
		      - (IData)(0x50U)));
    // ALWAYS at ModFbTxtW.v:139
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx 
	= ((0xcU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)) 
	   | (3U & ((IData)(3U) - ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX) 
				   >> 2U))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx 
	= ((3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)) 
	   | (0xcU & (((IData)(3U) - ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY) 
				      >> 1U)) << 2U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx 
	= ((0x38U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx)) 
	   | (7U & ((IData)(7U) - ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX) 
				   >> 1U))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx 
	= ((7U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx)) 
	   | (0x38U & (((IData)(7U) - (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY)) 
		       << 3U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[2U];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U] 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[3U];
    if ((0x7d0U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U] = 0U;
    }
    if ((0x3e8U <= (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] = 0U;
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U] = 0U;
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph 
	= (0xffffU & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U]);
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA 
	= (0x3fU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		     << 0x10U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				  >> 0x10U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB 
	= (0x3fU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		     << 0xaU) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				 >> 0x16U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A 
	= (0x1ffU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		      << 0x16U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				   >> 0xaU)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B 
	= (0x1ffU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		      << 0xdU) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				  >> 0x13U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA = 0U;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB = 0U;
    if ((0U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		       << 4U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				 >> 0x1cU))))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0xc00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			    << 6U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0x3ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0xc00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			    << 6U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xcffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0x300U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			    << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xcffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0x300U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			    << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xf3fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0xc0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			   << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xf3fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0xc0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			   << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xfcfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0x30U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			   << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xfcfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0x30U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			   << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xff3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA) 
			  << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xff3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB) 
			  << 2U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
	    = ((0xffcU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
	       | (3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
	    = ((0xffcU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
	       | (3U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB)));
    } else {
	if ((2U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			   << 4U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				     >> 0x1cU))))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
		= ((0x1ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
		   | (0xe00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A) 
				<< 3U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
		= ((0x1ffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
		   | (0xe00U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B) 
				<< 3U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
		= ((0xf1fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
		   | (0xe0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A) 
			       << 2U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
		= ((0xf1fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
		   | (0xe0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B) 
			       << 2U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA 
		= ((0xff1U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA)) 
		   | (0xeU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A) 
			      << 1U)));
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB 
		= ((0xff1U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB)) 
		   | (0xeU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B) 
			      << 1U)));
	}
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	= ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	   | (0xf00U & ((((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
				 >> 5U)) + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
						  >> 0xaU))) 
			 + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
				  >> 2U))) << 8U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	= ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	   | (0xf00U & ((((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
				 >> 5U)) + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
						  >> 0xaU))) 
			 + (3U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
				  >> 2U))) << 8U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	= ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	   | (0xf0U & (((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
					      >> 1U)) 
				       - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
						>> 5U)))) 
		       << 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	= ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	   | (0xf0U & (((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
					      >> 1U)) 
				       - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
						>> 5U)))) 
		       << 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	= ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	   | (0xfU & ((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
					    >> 9U)) 
				     - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA) 
					      >> 5U))))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	= ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	   | (0xfU & ((IData)(8U) + ((7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
					    >> 9U)) 
				     - (7U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB) 
					      >> 5U))))));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData1;
    if ((2U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
		       << 2U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
				 >> 0x1eU))))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
	    = (((QData)((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[3U])) 
		<< 0x20U) | (QData)((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U])));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	    = ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	       | (0xf00U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			     << 0x10U) | (0xff00U & 
					  (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					   >> 0x10U)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	    = ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	       | (0xf00U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			     << 0x16U) | (0x3fff00U 
					  & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					     >> 0xaU)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	    = ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	       | (0xf0U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			    << 0x18U) | (0xfffff0U 
					 & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					    >> 8U)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	    = ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	       | (0xf0U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			    << 0x1cU) | (0xffffff0U 
					 & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					    >> 4U)))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB 
	    = ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB)) 
	       | (0xfU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
			   << 0x1cU) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U] 
					>> 4U))));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA 
	    = ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)) 
	       | (0xfU & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[0U]));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphU 
	    = (0xffffU & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[2U] 
			   << 0x10U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U] 
					>> 0x10U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphV 
	    = (0xffffU & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData[1U]);
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
	    = ((0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)) 
	       | (0xf00U & (((1U & (IData)((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
					    >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx))))
			      ? ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA) 
				 >> 8U) : ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB) 
					   >> 8U)) 
			    << 8U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
	    = ((0xf0fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)) 
	       | (0xf0U & (((1U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphU) 
				   >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)))
			     ? ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA) 
				>> 4U) : ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB) 
					  >> 4U)) << 4U)));
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
	    = ((0xff0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)) 
	       | (0xfU & ((1U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphV) 
				 >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)))
			   ? (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)
			   : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB))));
    } else {
	if ((0U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U] 
			   << 2U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U] 
				     >> 0x1eU))))) {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
		= ((1U & (IData)((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData 
				  >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx))))
		    ? (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)
		    : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB));
	} else {
	    if ((1U == (3U & ((vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U] 
			       << 2U) | (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U] 
					 >> 0x1eU))))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC 
		    = ((1U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph) 
			      >> (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx)))
		        ? (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA)
		        : (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB));
	    }
	}
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy 
	= ((0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy)) 
	   | (0xf0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		       >> 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy 
	= ((0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy)) 
	   | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		      >> 8U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu 
	= ((0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu)) 
	   | (0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu 
	= ((0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu)) 
	   | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		      >> 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv 
	= ((0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv)) 
	   | (0xf0U & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC) 
		       << 4U)));
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv 
	= ((0xf0U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv)) 
	   | (0xfU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC)));
    // ALWAYS at DcTile3.v:143
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc1 = vlTOPp->ExUnit__DOT__dcfRegInAddr;
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc2 = ((IData)(4U) 
						+ vlTOPp->ExUnit__DOT__dcfRegInAddr);
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc1 
						     >> 4U));
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__dcf__DOT__tRegInPc2 
						     >> 4U));
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutData = VL_ULL(0);
    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3 = vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1;
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd4 = vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[0U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[1U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[2U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[3U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
	= vlTOPp->ExUnit__DOT__dcf__DOT__reqTempBlk[4U];
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 = VL_ULL(0);
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccCommitOK = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqNeedAd = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit = 0U;
    vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 0U;
    if ((5U == (7U & (vlTOPp->ExUnit__DOT__dcfRegInAddr 
		      >> 0x1dU)))) {
	vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 1U;
    }
    if ((6U == (7U & (vlTOPp->ExUnit__DOT__dcfRegInAddr 
		      >> 0x1dU)))) {
	vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 1U;
    }
    if ((7U == (7U & (vlTOPp->ExUnit__DOT__dcfRegInAddr 
		      >> 0x1dU)))) {
	vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache = 1U;
    }
    if ((((IData)(vlTOPp->ExUnit__DOT__dcfRegInOE) 
	  | (IData)(vlTOPp->ExUnit__DOT__dcfRegInWR)) 
	 & (0U == (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt)))) {
	if (vlTOPp->ExUnit__DOT__dcf__DOT__accNoCache) {
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit = 0U;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
		= ((0xc0000003U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
		   | (0x3ffffffcU & vlTOPp->ExUnit__DOT__dcfRegInAddr));
	    VL_EXTEND_WI(128,32, __Vtemp11, (IData)(vlTOPp->ExUnit__DOT__dcfRegInData));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
		= __Vtemp11[0U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U] 
		= __Vtemp11[1U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U] 
		= __Vtemp11[2U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U] 
		= __Vtemp11[3U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE 
		= vlTOPp->ExUnit__DOT__dcfRegInOE;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR 
		= vlTOPp->ExUnit__DOT__dcfRegInWR;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 1U;
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK 
		= vlTOPp->ExUnit__DOT__dcfMemPcOK;
	} else {
	    if (((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1 
		  == vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
		  [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1)]) 
		 & (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2 
		    == vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
		    [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2)]))) {
		vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit = 1U;
	    } else {
		if ((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1 
		     == vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
		     [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1)])) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd2;
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nReqNeedAd 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd1;
		}
	    }
	}
	if (vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccHit) {
	    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
		= ((8U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
		    ? ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
		        ? (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U])))
		        : (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U]))))
		    : ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
		        ? (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U])))
		        : (((QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U])))));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData 
		= ((0x10U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		    ? ((8U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? vlTOPp->ExUnit__DOT__dcfRegInData
			    : (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       ^ vlTOPp->ExUnit__DOT__dcfRegInData))
		        : ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       | vlTOPp->ExUnit__DOT__dcfRegInData)
			    : (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       & vlTOPp->ExUnit__DOT__dcfRegInData)))
		    : ((8U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? vlTOPp->ExUnit__DOT__dcfRegInData
			    : (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       - vlTOPp->ExUnit__DOT__dcfRegInData))
		        : ((4U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
			    ? (vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutDataB 
			       + vlTOPp->ExUnit__DOT__dcfRegInData)
			    : vlTOPp->ExUnit__DOT__dcfRegInData)));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx = 
		(3U == (7U & ((IData)(vlTOPp->ExUnit__DOT__dcfRegInOp) 
			      >> 2U)));
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
			= vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData;
		} else {
		    if ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xff00000000ffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData))) 
				      << 0x18U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x38U))))) 
				      << 0x38U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffff00000000ffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData))) 
				      << 0x10U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x30U))))) 
				      << 0x30U));
			}
		    } else {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff00000000ff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData))) 
				      << 8U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x28U))))) 
				      << 0x28U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff00000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(
							      (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
							       >> 0x20U)))) 
				      << 0x20U));
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))) {
		    if ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff0000ffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x18U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffffU 
						       & (IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
								  >> 0x28U))))) 
				      << 0x28U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff0000ffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x10U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(
							      (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
							       >> 0x20U)))) 
				      << 0x20U));
			}
		    } else {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff0000ff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 8U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffff000000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffffff0000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			}
		    }
		} else {
		    if ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff000000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff00ffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x18U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)((IData)(
							      (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B 
							       >> 0x20U)))) 
				      << 0x20U));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff0000) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffff00ffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 0x10U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffff000000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			}
		    } else {
			if ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffff00ff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | ((QData)((IData)(
						      (0xffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))) 
				      << 8U));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffff) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffffff0000) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			} else {
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xffffffffffffff00) 
				    & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (IData)((IData)(
						     (0xffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegInData)))));
			    vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				= ((VL_ULL(0xff) & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3) 
				   | (VL_ULL(0xffffffffffffff00) 
				      & vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2B));
			}
		    }
		}
	    }
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit 
		= ((IData)(vlTOPp->ExUnit__DOT__dcfRegInWR) 
		   & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accHit));
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 
		= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd3;
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 
		= vlTOPp->ExUnit__DOT__dcf__DOT__tBlkNeedAd4;
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 1U;
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtAccCommitOK 
		= ((IData)(vlTOPp->ExUnit__DOT__dcfRegInWR) 
		   & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accHit));
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK 
		= ((((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accHit) 
		     & (~ (IData)(vlTOPp->ExUnit__DOT__dcfRegInWR))) 
		    | (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__accCommitOK))
		    ? 1U : 2U);
	    vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutData 
		= ((2U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2
		        : ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			    ? ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x37U)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(
								(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								 >> 0x18U))))
			        : (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x2fU)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(
								(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								 >> 0x10U)))))
			    : ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x27U)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(
								(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								 >> 8U))))
			        : (((QData)((IData)(
						    ((1U 
						      & ((IData)(
								 (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
								  >> 0x1fU)) 
							 & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
						      ? 0xfU
						      : 0U))) 
				    << 0x20U) | (QData)((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2))))))
		    : ((1U & (IData)(vlTOPp->ExUnit__DOT__dcfRegInOp))
		        ? ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			    ? ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x27U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(
									   (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									    >> 0x18U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x1fU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(
									   (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									    >> 0x10U)))))))
			    : ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x17U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(
									   (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									    >> 8U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0xfU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 0x10U) | (QData)((IData)(
								(0xffffU 
								 & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2)))))))
		        : ((2U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			    ? ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x1fU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(
									(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									 >> 0x18U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0x17U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(
									(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									 >> 0x10U)))))))
			    : ((1U & vlTOPp->ExUnit__DOT__dcfRegInAddr)
			        ? ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 0xfU)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(
									(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
									 >> 8U))))))
			        : ((((1U & ((IData)(
						    (vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2 
						     >> 7U)) 
					    & (~ (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRdZx))))
				      ? VL_ULL(0xf)
				      : VL_ULL(0)) 
				    << 8U) | (QData)((IData)(
							     (0xffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData2)))))))));
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U];
	    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
		= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U];
	    if ((8U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
		if ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		}
	    } else {
		if ((4U & vlTOPp->ExUnit__DOT__dcfRegInAddr)) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
			= (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3);
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= (IData)((vlTOPp->ExUnit__DOT__dcf__DOT__tBlkData3 
				   >> 0x20U));
		}
	    }
	}
    }
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt;
    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit = 0U;
    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
	if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
		      >> 2U)))) {
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 0xbU;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 0xaU;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 9U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		}
	    }
	}
    } else {
	if ((4U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 7U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 6U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 2U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 5U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt) 
				      << 2U)));
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__icBlkAd
			      [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)] 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[1U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[2U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemOutData[3U] 
			= vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= (0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr);
		} else {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[1U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[2U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[3U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= ((0xfU & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr) 
			   | (vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd 
			      << 4U));
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcWR = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOp = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommit = 1U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 
			= vlTOPp->ExUnit__DOT__dcf__DOT__isReqNeedAd;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqCommitFl = 0U;
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
			= vlTOPp->ExUnit__DOT__dcfMemInData[0U];
		    vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr 
			= (0xfffffff3U & vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr);
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__isReqTileSt))) {
		    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 0U;
		} else {
		    if ((0U != vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)) {
			vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqNeedAd 
			    = vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd;
			vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 4U;
			if ((1U & vlTOPp->ExUnit__DOT__dcf__DOT__icBlkFl
			     [(0xffU & vlTOPp->ExUnit__DOT__dcf__DOT__reqNeedAd)])) {
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[0U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[0U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[1U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[1U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[2U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[2U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[3U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[3U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTempBlk[4U] 
				= vlTOPp->ExUnit__DOT__dcf__DOT__accTempBlk[4U];
			    vlTOPp->ExUnit__DOT__dcf__DOT__nxtReqTileSt = 8U;
			}
		    }
		}
	    }
	}
    }
    vlTOPp->ExUnit__DOT__dcl2__DOT__addrIsRam = ((0xc000000U 
						  <= 
						  (0x1fffffffU 
						   & vlTOPp->ExUnit__DOT__dc2RegInAddr)) 
						 & (0x1e000000U 
						    >= 
						    (0x1fffffffU 
						     & vlTOPp->ExUnit__DOT__dc2RegInAddr)));
    // ALWAYS at IcTile2.v:89
    vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc1 = vlTOPp->ExUnit__DOT__regIfPc;
    vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc2 = ((IData)(4U) 
						+ vlTOPp->ExUnit__DOT__regIfPc);
    vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc1 
						     >> 4U));
    vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2 = (0xfffffffU 
						  & (vlTOPp->ExUnit__DOT__icf__DOT__tRegInPc2 
						     >> 4U));
    vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal = VL_ULL(0xf3b0f3b0f3b);
    vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcOK = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = 0U;
    if (((vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1 
	  == vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd
	  [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)]) 
	 & (vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2 
	    == vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2)]))) {
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[0U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkA
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcOK = 1U;
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkB
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkC
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkD
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)];
	vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U] 
	    = vlTOPp->ExUnit__DOT__icf__DOT__icBlkE
	    [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2)];
	vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal 
	    = (VL_ULL(0xffffffffffff) & ((8U & vlTOPp->ExUnit__DOT__regIfPc)
					  ? ((4U & vlTOPp->ExUnit__DOT__regIfPc)
					      ? ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U])) 
						   << 0x10U) 
						  | ((QData)((IData)(
								     vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						     >> 0x10U))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U]))))
					      : ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[4U])) 
						   << 0x30U) 
						  | (((QData)((IData)(
								      vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						      << 0x10U) 
						     | ((QData)((IData)(
									vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
							>> 0x10U)))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])))))
					  : ((4U & vlTOPp->ExUnit__DOT__regIfPc)
					      ? ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[3U])) 
						   << 0x30U) 
						  | (((QData)((IData)(
								      vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
						      << 0x10U) 
						     | ((QData)((IData)(
									vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U])) 
							>> 0x10U)))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U]))))
					      : ((2U 
						  & vlTOPp->ExUnit__DOT__regIfPc)
						  ? 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[2U])) 
						   << 0x30U) 
						  | (((QData)((IData)(
								      vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U])) 
						      << 0x10U) 
						     | ((QData)((IData)(
									vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[0U])) 
							>> 0x10U)))
						  : 
						 (((QData)((IData)(
								   vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[1U])) 
						   << 0x20U) 
						  | (QData)((IData)(
								    vlTOPp->ExUnit__DOT__icf__DOT__accTempBlk[0U])))))));
    } else {
	if ((0U == (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	    if ((vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1 
		 == vlTOPp->ExUnit__DOT__icf__DOT__icBlkAd
		 [(0xffU & vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1)])) {
		VL_WRITEF("IcMiss2 %x\n",28,vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2);
		vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd 
		    = vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd2;
	    } else {
		VL_WRITEF("IcMiss1 %x\n",28,vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1);
		vlTOPp->ExUnit__DOT__icf__DOT__nReqNeedAd 
		    = vlTOPp->ExUnit__DOT__icf__DOT__tBlkNeedAd1;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = 1U;
	    }
	}
    }
    vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[0U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[1U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[2U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[3U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U] 
	= vlTOPp->ExUnit__DOT__icf__DOT__reqTempBlk[4U];
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1 = 0U;
    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2 = 0U;
    if ((4U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 0U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
	    } else {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 7U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 6U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
	    } else {
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 5U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (0xcU & ((IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt) 
				  << 2U)));
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
	    }
	}
    } else {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))) {
	    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt))))) {
		VL_WRITEF("IcTile2: Get2 %x\n",128,
			  vlTOPp->ExUnit__DOT__memIfPcData);
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[0U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[1U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[1U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[2U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[2U];
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[3U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[3U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = ((0xfU & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr) 
		       | (vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd 
			  << 4U));
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcOE = 1U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 0U;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommit 
		    = (1U == (IData)(vlTOPp->ExUnit__DOT__memIfPcOK));
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd1 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqCommitAd2 
		    = vlTOPp->ExUnit__DOT__icf__DOT__isReqNeedAd;
		vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTempBlk[4U] 
		    = vlTOPp->ExUnit__DOT__memIfPcData[0U];
		vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr 
		    = (0xfffffff3U & vlTOPp->ExUnit__DOT__icf__DOT__tMemPcAddr);
	    }
	} else {
	    if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__icf__DOT__isReqTileSt)))) {
		if (vlTOPp->ExUnit__DOT__icf__DOT__doReqNeedAd) {
		    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqNeedAd 
			= vlTOPp->ExUnit__DOT__icf__DOT__reqNeedAd;
		    vlTOPp->ExUnit__DOT__icf__DOT__nxtReqTileSt = 2U;
		}
	    }
	}
    }
    // ALWAYS at DecOp4_XE.v:82
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord 
	= (0xffffU & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
			      >> 0x10U)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord 
	= (0xffffU & (IData)(vlTOPp->ExUnit__DOT__regIdPcVal));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl 
	= (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
		   >> 8U));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl 
	= (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
		   >> 4U));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegO_Dfl 
	= (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl 
	= (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
		   >> 4U));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_Dfl 
	= (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_FR 
	= (0x40U | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
			    >> 8U)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_FR 
	= (0x40U | (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
			    >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_FR 
	= (0x40U | (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xffffffU : 0U) << 8U) | (0xffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Zx8E 
	= (0xffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Nx8E 
	= (0xffffff00U | (0xffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmM12_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xfffffU : 0U) << 0xcU) | ((0xff0U 
					    & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					       << 4U)) 
					   | (0xfU 
					      & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						 >> 4U))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xfffffU : 0U) << 0xcU) | ((0xff0U 
					    & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					       << 4U)) 
					   | (0xfU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xffffU : 0U) << 0x10U) | ((0xff00U 
					    & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					       << 8U)) 
					   | (0xffU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm20_Sx8E 
	= ((((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord))
	      ? 0xfffU : 0U) << 0x14U) | ((0xff000U 
					   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord) 
					      << 0xcU)) 
					  | (0xfffU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm4_ZxXE 
	= (0xfU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord));
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 3U;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x1fU;
    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 0U;
    if ((0x8000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
	if ((0x4000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
			      >> 0xcU)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 2U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xcU;
		}
	    } else {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
			      >> 0xcU)))) {
		    if ((0x800U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 0xaU)))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x14U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x15U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x13U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x11U;
				}
			    }
			}
		    } else {
			if ((0x400U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					      >> 8U)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x17U;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xdU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x17U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xcU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x17U;
				}
			    }
			} else {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					      >> 8U)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x13U;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x13U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 8U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x13U;
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x31U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xfU;
		} else {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x30U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xfU;
		}
	    } else {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x50U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xcU;
		} else {
		    if ((0x800U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((0x400U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x35U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x34U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    }
			} else {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x37U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    } else {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x36U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x38U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x10U;
				}
			    }
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 0xaU)))) {
			    if ((0x200U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((0x100U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x33U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x32U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xeU;
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((0x4000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x10U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xcU;
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 7U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 6U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 5U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 4U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 7U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 6U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 5U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 4U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xdU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xcU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 6U;
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    if ((0U == (0xfU 
						& ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						   >> 4U)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4cU;
					vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
				    } else {
					if ((1U == 
					     (0xfU 
					      & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						 >> 4U)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x4dU;
					    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
					}
				    }
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x17U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 0U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x16U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 0U;
				}
			    }
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    if ((0x80U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
					if ((0x40U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
					    if ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						if (
						    (1U 
						     & (~ 
							((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
							 >> 4U)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x23U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x14U;
						}
					    } else {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x22U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x14U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x21U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x14U;
						}
					    }
					} else {
					    if ((1U 
						 & (~ 
						    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
						     >> 5U)))) {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x6dU;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x16U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    }
					}
				    } else {
					if ((0x40U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
					    if ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x6cU;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x17U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    } else {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x15U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x14U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    }
					} else {
					    if ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x13U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x12U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						}
					    } else {
						if (
						    (0x10U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x11U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x10U;
						    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0x15U;
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
	    if ((0x2000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					  >> 1U)))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x10U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			} else {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
					  >> 1U)))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x11U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x39U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3aU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3bU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x3cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				}
			    } else {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x38U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 0xaU;
				}
			    }
			}
		    }
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x12U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 2U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x12U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x14U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x15U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0x13U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = 1U;
				}
			    }
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xbU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 8U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 4U;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x1000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 6U;
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xeU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xdU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xcU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xbU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 9U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = 8U;
				    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = 5U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		} else {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		}
	    } else {
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_FR;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_FR;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_FR;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
		    }
		}
	    }
	}
    } else {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			= ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))
			    ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm20_Sx8E
			    : vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E);
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = (0xfU & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord) 
				       >> 8U));
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImmM12_Sx8E;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = ((0U == (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx))
			        ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E
			        : ((1U == (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx))
				    ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Zx8E
				    : ((2U == (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx))
				        ? vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Nx8E
				        : 0U)));
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegO_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm4_ZxXE;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm = 0U;
		    }
		}
	    }
	}
    }
    // ALWAYS at ModTxtMemW.v:114
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontMem
	[(0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx1 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx1Mem
	[(0x7fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx2 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx2Mem
	[(0x7fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData2 
	= ((0x200U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))
	    ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1
	    : ((0x100U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))
	        ? ((0x80U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))
		    ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx1
		    : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx2)
	        : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1));
    // ALWAYS at ExUnit.v:565
    vlTOPp->ExUnit__DOT__exNextFpScr2 = vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr;
    vlTOPp->ExUnit__DOT__exNextFpScr2 = ((0xfffff7ffU 
					  & vlTOPp->ExUnit__DOT__exNextFpScr2) 
					 | (0x800U 
					    & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmOut) 
					       << 8U)));
    vlTOPp->ExUnit__DOT__dcfMemPcAddr = vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr;
    vlTOPp->ExUnit__DOT__dcfMemPcOE = vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE;
    // ALWAYS at Dc2Tile.v:119
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx = (0x7ffU 
						  & (vlTOPp->ExUnit__DOT__dc2RegInAddr 
						     >> 4U));
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx = vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileSt = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOutData = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioAddr = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOE = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR = 0U;
    if (VL_UNLIKELY(((IData)(vlTOPp->ExUnit__DOT__dc2RegInOE) 
		     | (IData)(vlTOPp->ExUnit__DOT__dc2RegInWR)))) {
	VL_WRITEF("DcTile2 %x %1# %1#\n",32,vlTOPp->ExUnit__DOT__dc2RegInAddr,
		  1,(0x100000U >= (0x1fffffffU & vlTOPp->ExUnit__DOT__dc2RegInAddr)),
		  1,(IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__addrIsRam));
	if (VL_UNLIKELY((0x100000U >= (0x1fffffffU 
				       & vlTOPp->ExUnit__DOT__dc2RegInAddr)))) {
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][0U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][1U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][2U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][3U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK = 1U;
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
	    VL_WRITEF("Rom: %x\n",128,vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile);
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			VL_EXTEND_WQ(128,64, __Vtemp14, 
				     (((QData)((IData)(
						       vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U])) 
				       << 0x20U) | (QData)((IData)(
								   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]))));
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = __Vtemp14[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = __Vtemp14[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = __Vtemp14[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = __Vtemp14[3U];
		    } else {
			VL_EXTEND_WQ(128,64, __Vtemp15, 
				     (((QData)((IData)(
						       vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U])) 
				       << 0x20U) | (QData)((IData)(
								   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]))));
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = __Vtemp15[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = __Vtemp15[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = __Vtemp15[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = __Vtemp15[3U];
		    }
		} else {
		    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    VL_EXTEND_WI(128,32, __Vtemp16, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp16[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp16[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp16[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp16[3U];
			} else {
			    VL_EXTEND_WI(128,32, __Vtemp17, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp17[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp17[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp17[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp17[3U];
			}
		    } else {
			if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    VL_EXTEND_WI(128,32, __Vtemp18, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp18[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp18[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp18[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp18[3U];
			} else {
			    VL_EXTEND_WI(128,32, __Vtemp19, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp19[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp19[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp19[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp19[3U];
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		} else {
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		}
	    }
	    VL_WRITEF("Rom: Out=%x\n",128,vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData);
	} else {
	    if (vlTOPp->ExUnit__DOT__dcl2__DOT__addrIsRam) {
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[0U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[1U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[2U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[3U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK 
		    = (((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tAccTileIx) 
			== (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))
		        ? 1U : 2U);
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    VL_EXTEND_WQ(128,64, __Vtemp20, 
					 (((QData)((IData)(
							   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U])) 
					   << 0x20U) 
					  | (QData)((IData)(
							    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]))));
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp20[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp20[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp20[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp20[3U];
			} else {
			    VL_EXTEND_WQ(128,64, __Vtemp21, 
					 (((QData)((IData)(
							   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U])) 
					   << 0x20U) 
					  | (QData)((IData)(
							    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]))));
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp21[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp21[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp21[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp21[3U];
			}
		    } else {
			if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				VL_EXTEND_WI(128,32, __Vtemp22, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp22[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp22[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp22[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp22[3U];
			    } else {
				VL_EXTEND_WI(128,32, __Vtemp23, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp23[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp23[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp23[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp23[3U];
			    }
			} else {
			    if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				VL_EXTEND_WI(128,32, __Vtemp24, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp24[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp24[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp24[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp24[3U];
			    } else {
				VL_EXTEND_WI(128,32, __Vtemp25, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp25[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp25[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp25[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp25[3U];
			    }
			}
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		    } else {
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		    }
		}
		if (vlTOPp->ExUnit__DOT__dc2RegInWR) {
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx;
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileSt = 1U;
		    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
				    = (IData)((((QData)((IData)(
								vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[0U]))));
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
				    = (IData)(((((QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->ExUnit__DOT__dc2RegInData[0U]))) 
					       >> 0x20U));
			    } else {
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
				    = (IData)((((QData)((IData)(
								vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[0U]))));
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
				    = (IData)(((((QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->ExUnit__DOT__dc2RegInData[0U]))) 
					       >> 0x20U));
			    }
			} else {
			    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				} else {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				}
			    } else {
				if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				} else {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				}
			    }
			}
		    } else {
			if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[3U];
			} else {
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[3U];
			}
		    }
		}
	    } else {
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOutData 
		    = vlTOPp->ExUnit__DOT__dc2RegInData[0U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioAddr 
		    = vlTOPp->ExUnit__DOT__dc2RegInAddr;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOE 
		    = vlTOPp->ExUnit__DOT__dc2RegInOE;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR 
		    = vlTOPp->ExUnit__DOT__dc2RegInWR;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK 
		    = vlTOPp->mmioOK;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] = 0U;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] = 0U;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] = 0U;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] = 0U;
	    }
	}
    }
    // ALWAYS at ExUnit.v:454
    vlTOPp->ExUnit__DOT__tRegGenIdStepPc = vlTOPp->ExUnit__DOT__exStepPc2;
    vlTOPp->ExUnit__DOT__tRegGenIdPc = (vlTOPp->ExUnit__DOT__regIfPc 
					+ (IData)(vlTOPp->ExUnit__DOT__tRegGenIdStepPc));
    vlTOPp->ExUnit__DOT__regIfPcVal2 = vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal;
    if ((vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
	 != vlTOPp->ExUnit__DOT__tRegGenIdPc)) {
	vlTOPp->ExUnit__DOT__regIfPcVal2 = VL_ULL(0xf090f090e09);
    }
    // ALWAYS at DecOp4.v:123
    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc = 2U;
    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 3U;
    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__isOpXE = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x1fU;
    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opJQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord = (0xffffU 
						& (IData)(vlTOPp->ExUnit__DOT__regIdPcVal));
    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2A = 2U;
    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2B = 2U;
    if ((1U == (0x1fU & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				 >> 0x2bU))))) {
	if ((((2U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x28U)))) | 
	      (4U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x28U))))) | 
	     (6U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				   >> 0x28U)))))) {
	    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2A = 4U;
	}
    }
    if ((0x11U == (0x1fU & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x1bU))))) {
	if ((((2U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x18U)))) | 
	      (4U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x18U))))) | 
	     (6U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				   >> 0x18U)))))) {
	    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2B = 4U;
	}
    }
    if (((((((((2U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
	       | (4U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	      | (5U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	     | (6U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	    | (7U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	   | (8U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	  | (0x18U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	 | (0x28U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
	if ((2U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
	    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
	    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
	    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 3U;
	} else {
	    if ((4U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
		vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
	    } else {
		if ((5U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
			= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
			    ? 0xbU : 9U);
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
		} else {
		    if ((6U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
			    = ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
			        ? 0xbU : 0xaU);
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
		    } else {
			if ((7U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1fU;
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
			} else {
			    if ((8U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				vlTOPp->ExUnit__DOT__dec__DOT__opImm 
				    = (4U | (0xffffff00U 
					     & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			    } else {
				if ((0x18U == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (3U | (0xffffff00U 
						 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (2U | (0xffffff00U 
						 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (((((((((0x38U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
		   | (0x48U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		  | (0x58U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		 | (0x68U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		| (9U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	       | (0x19U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	      | (0x29U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	     | (0x39U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
	    if ((0x38U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
		vlTOPp->ExUnit__DOT__dec__DOT__opImm 
		    = (8U | (0xffffff00U & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
		vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
	    } else {
		if ((0x48U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
		    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			= (7U | (0xffffff00U & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
		} else {
		    if ((0x58U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = (6U | (0xffffff00U & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
		    } else {
			if ((0x68U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
				= (5U | (0xffffff00U 
					 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			} else {
			    if ((9U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			    } else {
				if ((0x19U == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (1U | (0xffffff00U 
						 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				} else {
				    if ((0x29U == (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x48U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
				    } else {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x49U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (((((((((0xaU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
		       | (0xbU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		      | (0x1bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		     | (0x2bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		    | (0x3bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		   | (0x6bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		  | (0xcU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		 | (0xdU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
		if ((0xaU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 2U;
		} else {
		    if ((0xbU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x40U;
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
		    } else {
			if ((0x1bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
				= (9U | (0xffffff00U 
					 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			} else {
			    if ((0x2bU == (0xf0ffU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x42U;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			    } else {
				if ((0x3bU == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 3U;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 1U;
				} else {
				    if ((0x6bU == (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x41U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				    } else {
					if ((0xcU == 
					     (0xf00fU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
					} else {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
						    ? 0xfU
						    : 0xdU);
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if (((((((((0xeU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
			   | (0x1000U == (0xf000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			  | (0x2000U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			 | (0x2001U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			| (0x2002U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		       | (0x2003U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		      | (0x2004U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		     | (0x2005U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
		    if ((0xeU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
		    } else {
			if ((0x1000U == (0xf000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
				= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
				    ? 0xbU : 0xaU);
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 6U;
			} else {
			    if ((0x2000U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
			    } else {
				if ((0x2001U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
					    ? 0xbU : 9U);
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
				} else {
				    if ((0x2002U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					    = ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
					        ? 0xbU
					        : 0xaU);
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
				    } else {
					if ((0x2003U 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x4fU;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
					} else {
					    if ((0x2004U 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
					    } else {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						    = 
						    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
						      ? 0xbU
						      : 9U);
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
					    }
					}
				    }
				}
			    }
			}
		    }
		} else {
		    if (((((((((0x2006U == (0xf00fU 
					    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
			       | (0x2007U == (0xf00fU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			      | (0x2008U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			     | (0x2009U == (0xf00fU 
					    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			    | (0x200aU == (0xf00fU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			   | (0x200bU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			  | (0x200cU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			 | (0x200dU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
			if ((0x2006U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
				= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
				    ? 0xbU : 0xaU);
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
			} else {
			    if ((0x2007U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5aU;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
			    } else {
				if ((0x2008U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x3dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
				} else {
				    if ((0x2009U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x13U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
				    } else {
					if ((0x200aU 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x15U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					} else {
					    if ((0x200bU 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x14U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					    } else {
						if (
						    (0x200cU 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5cU;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5dU;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						}
					    }
					}
				    }
				}
			    }
			}
		    } else {
			if (((((((((0x200eU == (0xf00fU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
				   | (0x200fU == (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				  | (0x3000U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				 | (0x3002U == (0xf00fU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				| (0x3003U == (0xf00fU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			       | (0x3004U == (0xf00fU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			      | (0x3005U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			     | (0x3006U == (0xf00fU 
					    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
			    if ((0x200eU == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1cU;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
			    } else {
				if ((0x200fU == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
				} else {
				    if ((0x3000U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					    = ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
					        ? 0x78U
					        : 0x38U);
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
				    } else {
					if ((0x3002U 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
						    ? 0x7cU
						    : 0x3cU);
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
					} else {
					    if ((0x3003U 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						    = 
						    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
						      ? 0x7bU
						      : 0x3bU);
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
					    } else {
						if (
						    (0x3004U 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5bU;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						} else {
						    if (
							(0x3005U 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1eU;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
						    } else {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
							    = 
							    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
							      ? 0x7aU
							      : 0x3aU);
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
						    }
						}
					    }
					}
				    }
				}
			    }
			} else {
			    if (((((((((0x3007U == 
					(0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
				       | (0x3008U == 
					  (0xf00fU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				      | (0x300aU == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				     | (0x300bU == 
					(0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				    | (0x300cU == (0xf00fU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				   | (0x300dU == (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				  | (0x300eU == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				 | (0x300fU == (0xf00fU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
				if ((0x3007U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
					    ? 0x79U
					    : 0x39U);
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
				} else {
				    if ((0x3008U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x11U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
				    } else {
					if ((0x300aU 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x19U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					} else {
					    if ((0x300bU 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1bU;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					    } else {
						if (
						    (0x300cU 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x10U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
						} else {
						    if (
							(0x300dU 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1fU;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
						    } else {
							if (
							    (0x300eU 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x18U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
							} else {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1aU;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
							}
						    }
						}
					    }
					}
				    }
				}
			    } else {
				if (((((((((0x4000U 
					    == (0xf0ffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
					   | (0x4010U 
					      == (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					  | (0x4020U 
					     == (0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					 | (0x4001U 
					    == (0xf0ffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					| (0x4011U 
					   == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				       | (0x4021U == 
					  (0xf0ffU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				      | (0x4002U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				     | (0x4003U == 
					(0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
				    if ((0x4000U == 
					 (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x60U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
				    } else {
					if ((0x4010U 
					     == (0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x68U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					} else {
					    if ((0x4020U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x61U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					    } else {
						if (
						    (0x4001U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x62U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						} else {
						    if (
							(0x4011U 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
							    = 
							    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
							      ? 0x7bU
							      : 0x3bU);
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						    } else {
							if (
							    (0x4021U 
							     == 
							     (0xf0ffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x63U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
							} else {
							    if (
								(0x4002U 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
								      ? 0xbU
								      : 0xaU);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 2U;
							    } else {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
								      ? 0xbU
								      : 0xaU);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 3U;
							    }
							}
						    }
						}
					    }
					}
				    }
				} else {
				    if (((((((((0x4004U 
						== 
						(0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
					       | (0x4024U 
						  == 
						  (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					      | (0x4005U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					     | (0x4015U 
						== 
						(0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					    | (0x4025U 
					       == (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					   | (0x4006U 
					      == (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					  | (0x4007U 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					 | (0x4008U 
					    == (0xf0ffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
					if ((0x4004U 
					     == (0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x64U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					} else {
					    if ((0x4024U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x65U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					    } else {
						if (
						    (0x4005U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x66U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						} else {
						    if (
							(0x4015U 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
							    = 
							    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
							      ? 0x79U
							      : 0x39U);
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						    } else {
							if (
							    (0x4025U 
							     == 
							     (0xf0ffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x67U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
							} else {
							    if (
								(0x4006U 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
								      ? 0xfU
								      : 0xeU);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
							    } else {
								if (
								    (0x4007U 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
									= 
									((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
									  ? 0xbU
									  : 0xeU);
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								} else {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
								    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 2U;
								}
							    }
							}
						    }
						}
					    }
					}
				    } else {
					if ((((((((
						   (0x4018U 
						    == 
						    (0xf0ffU 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
						   | (0x4028U 
						      == 
						      (0xf0ffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						  | (0x4009U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						 | (0x4019U 
						    == 
						    (0xf0ffU 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						| (0x4029U 
						   == 
						   (0xf0ffU 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					       | (0x400aU 
						  == 
						  (0xf00fU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					      | (0x400bU 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					     | (0x402bU 
						== 
						(0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
					    if ((0x4018U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
						vlTOPp->ExUnit__DOT__dec__DOT__opImm = 8U;
					    } else {
						if (
						    (0x4028U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
						    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0x10U;
						} else {
						    if (
							(0x4009U 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
							vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0xfffffffeU;
						    } else {
							if (
							    (0x4019U 
							     == 
							     (0xf0ffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
							    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0xfffffff8U;
							} else {
							    if (
								(0x4029U 
								 == 
								 (0xf0ffU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
								vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0xfffffff0U;
							    } else {
								if (
								    (0x400aU 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
								} else {
								    if (
									(0x400bU 
									 == 
									 (0xf0ffU 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x44U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
								    } else {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x46U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
								    }
								}
							    }
							}
						    }
						}
					    }
					} else {
					    if ((((
						   (((((0x403bU 
							== 
							(0xf0ffU 
							 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
						       | (0x404bU 
							  == 
							  (0xf0ffU 
							   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						      | (0x400cU 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						     | (0x400dU 
							== 
							(0xf00fU 
							 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						    | (0x400eU 
						       == 
						       (0xf00fU 
							& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						   | (0x5000U 
						      == 
						      (0xf000U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						  | (0x6000U 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						 | (0x6001U 
						    == 
						    (0xf00fU 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
						if (
						    (0x403bU 
						     != 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    if (
							(0x404bU 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x45U;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						    } else {
							if (
							    (0x400cU 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								= 
								((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
								  ? 0x76U
								  : 0x16U);
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
							} else {
							    if (
								(0x400dU 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
								      ? 0x77U
								      : 0x17U);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
							    } else {
								if (
								    (0x400eU 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								} else {
								    if (
									(0x5000U 
									 == 
									 (0xf000U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 6U;
								    } else {
									if (
									    (0x6000U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
									} else {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
										= 
										((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
										 ? 0xfU
										 : 0xdU);
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
									}
								    }
								}
							    }
							}
						    }
						}
					    } else {
						if (
						    ((((((((0x6002U 
							    == 
							    (0xf00fU 
							     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
							   | (0x6003U 
							      == 
							      (0xf00fU 
							       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							  | (0x6004U 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							 | (0x6005U 
							    == 
							    (0xf00fU 
							     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							| (0x6006U 
							   == 
							   (0xf00fU 
							    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						       | (0x6007U 
							  == 
							  (0xf00fU 
							   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						      | (0x6008U 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						     | (0x6009U 
							== 
							(0xf00fU 
							 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
						    if (
							(0x6002U 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
						    } else {
							if (
							    (0x6003U 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
							} else {
							    if (
								(0x6004U 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
							    } else {
								if (
								    (0x6005U 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
									= 
									((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
									  ? 0xfU
									  : 0xdU);
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								} else {
								    if (
									(0x6006U 
									 == 
									 (0xf00fU 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								    } else {
									if (
									    (0x6007U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x51U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									} else {
									    if (
										(0x6008U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x52U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									    } else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x53U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									    }
									}
								    }
								}
							    }
							}
						    }
						} else {
						    if (
							((((((((0x600aU 
								== 
								(0xf00fU 
								 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
							       | (0x600bU 
								  == 
								  (0xf00fU 
								   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							      | (0x600cU 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							     | (0x600dU 
								== 
								(0xf00fU 
								 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							    | (0x600eU 
							       == 
							       (0xf00fU 
								& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							   | (0x600fU 
							      == 
							      (0xf00fU 
							       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							  | (0x7000U 
							     == 
							     (0xf000U 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							 | (0x8000U 
							    == 
							    (0xff00U 
							     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
							if (
							    (0x600aU 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x59U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
							} else {
							    if (
								(0x600bU 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x58U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
							    } else {
								if (
								    (0x600cU 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x54U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								} else {
								    if (
									(0x600dU 
									 == 
									 (0xf00fU 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x55U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								    } else {
									if (
									    (0x600eU 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x56U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									} else {
									    if (
										(0x600fU 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x57U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									    } else {
										if (
										(0x7000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x10U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xcU;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 6U;
										}
									    }
									}
								    }
								}
							    }
							}
						    } else {
							if (
							    ((((((((0x8100U 
								    == 
								    (0xff00U 
								     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
								   | (0x8200U 
								      == 
								      (0xff00U 
								       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								  | (0x8300U 
								     == 
								     (0xff00U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								 | (0x8400U 
								    == 
								    (0xff00U 
								     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								| (0x8500U 
								   == 
								   (0xff00U 
								    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							       | (0x8600U 
								  == 
								  (0xff00U 
								   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							      | (0x8800U 
								 == 
								 (0xff00U 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							     | (0x8900U 
								== 
								(0xff00U 
								 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
							    if (
								(0x8100U 
								 == 
								 (0xff00U 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 9U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 6U;
							    } else {
								if (
								    (0x8200U 
								     == 
								     (0xff00U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x32U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
								} else {
								    if (
									(0x8300U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
									if (
									    (0x80U 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 3U;
									} else {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 2U;
									}
								    } else {
									if (
									    (0x8400U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 7U;
									} else {
									    if (
										(0x8500U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xdU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 7U;
									    } else {
										if (
										(0x8600U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										if (
										(0x80U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 5U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										}
										} else {
										if (
										(0x8800U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x38U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x36U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
										}
										}
									    }
									}
								    }
								}
							    }
							} else {
							    if (
								((((((((0x8a00U 
									== 
									(0xff00U 
									 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
								       | (0x8b00U 
									  == 
									  (0xff00U 
									   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								      | (0x8c00U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								     | (0x8d00U 
									== 
									(0xff00U 
									 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								    | (0x8e00U 
								       == 
								       (0xff00U 
									& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								   | (0x8f00U 
								      == 
								      (0xff00U 
								       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								  | (0x9000U 
								     == 
								     (0xf000U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								 | (0xa000U 
								    == 
								    (0xf000U 
								     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
								if (
								    (0x8a00U 
								     == 
								     (0xff00U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 2U;
								    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
									= 
									((((1U 
									    & (IData)(
										(vlTOPp->ExUnit__DOT__regIdPcVal 
										>> 7U)))
									    ? 0xffU
									    : 0U) 
									  << 0x18U) 
									 | ((0xff0000U 
									     & ((IData)(vlTOPp->ExUnit__DOT__regIdPcVal) 
										<< 0x10U)) 
									    | (0xffffU 
									       & (IData)(
										(vlTOPp->ExUnit__DOT__regIdPcVal 
										>> 0x10U)))));
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
								} else {
								    if (
									(0x8b00U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x37U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
								    } else {
									if (
									    (0x8c00U 
									     != 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    if (
										(0x8d00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x34U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
									    } else {
										if (
										(0x8e00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__isOpXE = 1U;
										vlTOPp->ExUnit__DOT__dec__DOT__opStepPc = 4U;
										} else {
										if (
										(0x8f00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x35U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
										} else {
										if (
										(0x9000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
										= 
										((0x70U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN)) 
										| (0xfU 
										& ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
										>> 8U)));
										vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x7aU;
										vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7fU;
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xdU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
										vlTOPp->ExUnit__DOT__dec__DOT__opImm 
										= 
										((0xffffff00U 
										& vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
										| (0xffU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x30U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xfU;
										}
										}
										}
									    }
									}
								    }
								}
							    } else {
								if (
								    ((((((((0xb000U 
									    == 
									    (0xf000U 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
									   | (0xc000U 
									      == 
									      (0xff00U 
									       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									  | (0xc100U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									 | (0xc200U 
									    == 
									    (0xff00U 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									| (0xc400U 
									   == 
									   (0xff00U 
									    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								       | (0xc500U 
									  == 
									  (0xff00U 
									   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								      | (0xc600U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								     | (0xc800U 
									== 
									(0xff00U 
									 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
								    if (
									(0xb000U 
									 == 
									 (0xf000U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x31U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xfU;
								    } else {
									if (
									    (0xc000U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    if (vlTOPp->ExUnit__DOT__dec__DOT__opJQ) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xbU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
									    } else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x13U;
									    }
									} else {
									    if (
										(0xc100U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 9U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x13U;
										}
									    } else {
										if (
										(0xc200U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x13U;
										}
										} else {
										if (
										(0xc400U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (vlTOPp->ExUnit__DOT__dec__DOT__opJQ) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xfU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x17U;
										}
										} else {
										if (
										(0xc500U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xdU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x17U;
										}
										} else {
										if (
										(0xc600U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x17U;
										}
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
										= 
										((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
										 ? 0x7dU
										 : 0x3dU);
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x11U;
										}
										}
										}
										}
									    }
									}
								    }
								} else {
								    if (
									((((((((0xc900U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
									       | (0xca00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									      | (0xcb00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									     | (0xd000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									    | (0xe000U 
									       == 
									       (0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									   | (0xf000U 
									      == 
									      (0xf00fU 
									       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									  | (0xf001U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									 | (0xf002U 
									    == 
									    (0xf00fU 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
									if (
									    (0xc900U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x13U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
									} else {
									    if (
										(0xca00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x15U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
									    } else {
										if (
										(0xcb00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x14U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
										} else {
										if (
										(0xd000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
										= 
										((0x70U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN)) 
										| (0xfU 
										& ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
										>> 8U)));
										vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x7bU;
										vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7fU;
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
										vlTOPp->ExUnit__DOT__dec__DOT__opImm 
										= 
										((0xffffff00U 
										& vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
										| (0xffU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
										} else {
										if (
										(0xe000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 2U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xcU;
										} else {
										if (
										(0xf000U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x21U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
										} else {
										if (
										(0xf001U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x22U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x23U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
										}
										}
										}
										}
										}
									    }
									}
								    } else {
									if (
									    (0xf004U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x2aU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
									} else {
									    if (
										(0xf005U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x2bU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
									    } else {
										if (
										(0xf006U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										} else {
										if (
										(0xf007U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 5U;
										} else {
										if (
										(0xf008U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										} else {
										if (
										(0xf009U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										} else {
										if (
										(0xf00aU 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 5U;
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
	}
    }
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl = (0xfU 
						 & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						    >> 8U));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl = (0xfU 
						 & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						    >> 4U));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR = (0x20U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR = (0x60U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN_FR = (0x40U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 8U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_FR = (0x40U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN_N3 = (8U 
						| (7U 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4 = (0xfU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8 = (0xffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx8 = ((((0x80U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))
						   ? 0xffffffU
						   : 0U) 
						 << 8U) 
						| (0xffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx12 = (((
						   (0x800U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))
						    ? 0xfffffU
						    : 0U) 
						  << 0xcU) 
						 | (0xfffU 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
    if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    }
		} else {
		    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		}
	    } else {
		vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8;
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= (0x48U | 
					   (7U & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						  >> 4U)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= (0x48U | 
					   (7U & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						  >> 4U)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_N3;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= ((0xfffffff0U 
					    & vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
					   | (0xfU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (0x10U | 
					   (0xfU & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_N3;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= ((0xfffffff0U 
					    & vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
					   | (0xfU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (0x10U | 
					   (0xfU & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				}
			    }
			}
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_FR;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_FR;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8;
		    }
		}
	    }
	}
    } else {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			= ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))
			    ? vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx12
			    : vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx8);
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx8;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_FR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_FR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				}
			    }
			}
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				}
			    }
			}
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if (vlTOPp->ExUnit__DOT__dec__DOT__isOpXE) {
	vlTOPp->ExUnit__DOT__dec__DOT__opRegN = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN;
	vlTOPp->ExUnit__DOT__dec__DOT__opRegS = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS;
	vlTOPp->ExUnit__DOT__dec__DOT__opRegT = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT;
	vlTOPp->ExUnit__DOT__dec__DOT__opImm = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm;
	vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd;
	vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2 = vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2A;
    } else {
	vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2 = vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2B;
    }
}

VL_INLINE_OPT void VExUnit::_sequent__TOP__5(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_sequent__TOP__5\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ModTxtMemW.v:114
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontMem
	[(0xffU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx1 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx1Mem
	[(0x7fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx2 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx2Mem
	[(0x7fU & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))];
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData2 
	= ((0x200U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))
	    ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1
	    : ((0x100U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))
	        ? ((0x80U & (IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph))
		    ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx1
		    : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx2)
	        : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1));
    // ALWAYS at ExUnit.v:565
    vlTOPp->ExUnit__DOT__exNextFpScr2 = vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr;
    vlTOPp->ExUnit__DOT__exNextFpScr2 = ((0xfffff7ffU 
					  & vlTOPp->ExUnit__DOT__exNextFpScr2) 
					 | (0x800U 
					    & ((IData)(vlTOPp->ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmOut) 
					       << 8U)));
    vlTOPp->ExUnit__DOT__dcfMemPcAddr = vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcAddr;
    vlTOPp->ExUnit__DOT__dcfMemPcOE = vlTOPp->ExUnit__DOT__dcf__DOT__tMemPcOE;
    // ALWAYS at DecOp4.v:123
    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc = 2U;
    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 3U;
    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__isOpXE = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7fU;
    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x1fU;
    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opJQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ = 0U;
    vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord = (0xffffU 
						& (IData)(vlTOPp->ExUnit__DOT__regIdPcVal));
    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2A = 2U;
    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2B = 2U;
    if ((1U == (0x1fU & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				 >> 0x2bU))))) {
	if ((((2U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x28U)))) | 
	      (4U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x28U))))) | 
	     (6U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				   >> 0x28U)))))) {
	    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2A = 4U;
	}
    }
    if ((0x11U == (0x1fU & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x1bU))))) {
	if ((((2U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x18U)))) | 
	      (4U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				    >> 0x18U))))) | 
	     (6U == (7U & (IData)((vlTOPp->ExUnit__DOT__regIdPcVal 
				   >> 0x18U)))))) {
	    vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2B = 4U;
	}
    }
    if (((((((((2U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
	       | (4U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	      | (5U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	     | (6U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	    | (7U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	   | (8U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	  | (0x18U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	 | (0x28U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
	if ((2U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
	    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
	    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
	    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 3U;
	} else {
	    if ((4U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
		vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
	    } else {
		if ((5U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
			= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
			    ? 0xbU : 9U);
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
		} else {
		    if ((6U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
			    = ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
			        ? 0xbU : 0xaU);
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
		    } else {
			if ((7U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1fU;
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
			} else {
			    if ((8U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				vlTOPp->ExUnit__DOT__dec__DOT__opImm 
				    = (4U | (0xffffff00U 
					     & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			    } else {
				if ((0x18U == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (3U | (0xffffff00U 
						 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (2U | (0xffffff00U 
						 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (((((((((0x38U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
		   | (0x48U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		  | (0x58U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		 | (0x68U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		| (9U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	       | (0x19U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	      | (0x29U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
	     | (0x39U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
	    if ((0x38U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
		vlTOPp->ExUnit__DOT__dec__DOT__opImm 
		    = (8U | (0xffffff00U & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
		vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
	    } else {
		if ((0x48U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
		    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			= (7U | (0xffffff00U & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
		} else {
		    if ((0x58U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = (6U | (0xffffff00U & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
		    } else {
			if ((0x68U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
				= (5U | (0xffffff00U 
					 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			} else {
			    if ((9U == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			    } else {
				if ((0x19U == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (1U | (0xffffff00U 
						 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				} else {
				    if ((0x29U == (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x48U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
				    } else {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x49U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (((((((((0xaU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
		       | (0xbU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		      | (0x1bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		     | (0x2bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		    | (0x3bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		   | (0x6bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		  | (0xcU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		 | (0xdU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
		if ((0xaU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
		    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 2U;
		} else {
		    if ((0xbU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x40U;
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
		    } else {
			if ((0x1bU == (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5eU;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
				= (9U | (0xffffff00U 
					 & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			} else {
			    if ((0x2bU == (0xf0ffU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x42U;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
			    } else {
				if ((0x3bU == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 3U;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 1U;
				} else {
				    if ((0x6bU == (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x41U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
				    } else {
					if ((0xcU == 
					     (0xf00fU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
					} else {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
						    ? 0xfU
						    : 0xdU);
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if (((((((((0xeU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
			   | (0x1000U == (0xf000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			  | (0x2000U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			 | (0x2001U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			| (0x2002U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		       | (0x2003U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		      | (0x2004U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
		     | (0x2005U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
		    if ((0xeU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
			vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
		    } else {
			if ((0x1000U == (0xf000U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
				= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
				    ? 0xbU : 0xaU);
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 6U;
			} else {
			    if ((0x2000U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
			    } else {
				if ((0x2001U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
					    ? 0xbU : 9U);
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
				} else {
				    if ((0x2002U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					    = ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
					        ? 0xbU
					        : 0xaU);
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
				    } else {
					if ((0x2003U 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x4fU;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
					} else {
					    if ((0x2004U 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
					    } else {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						    = 
						    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
						      ? 0xbU
						      : 9U);
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
					    }
					}
				    }
				}
			    }
			}
		    }
		} else {
		    if (((((((((0x2006U == (0xf00fU 
					    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
			       | (0x2007U == (0xf00fU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			      | (0x2008U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			     | (0x2009U == (0xf00fU 
					    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			    | (0x200aU == (0xf00fU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			   | (0x200bU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			  | (0x200cU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			 | (0x200dU == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
			if ((0x2006U == (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
				= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPlDQ)
				    ? 0xbU : 0xaU);
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
			    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
			} else {
			    if ((0x2007U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5aU;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
			    } else {
				if ((0x2008U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x3dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
				} else {
				    if ((0x2009U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x13U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
				    } else {
					if ((0x200aU 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x15U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					} else {
					    if ((0x200bU 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x14U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					    } else {
						if (
						    (0x200cU 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5cU;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						} else {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5dU;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						}
					    }
					}
				    }
				}
			    }
			}
		    } else {
			if (((((((((0x200eU == (0xf00fU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
				   | (0x200fU == (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				  | (0x3000U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				 | (0x3002U == (0xf00fU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				| (0x3003U == (0xf00fU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			       | (0x3004U == (0xf00fU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			      | (0x3005U == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
			     | (0x3006U == (0xf00fU 
					    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
			    if ((0x200eU == (0xf00fU 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1cU;
				vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
			    } else {
				if ((0x200fU == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1dU;
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
				} else {
				    if ((0x3000U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					    = ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
					        ? 0x78U
					        : 0x38U);
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
				    } else {
					if ((0x3002U 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
						    ? 0x7cU
						    : 0x3cU);
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
					} else {
					    if ((0x3003U 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
						    = 
						    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
						      ? 0x7bU
						      : 0x3bU);
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
					    } else {
						if (
						    (0x3004U 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x5bU;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						} else {
						    if (
							(0x3005U 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1eU;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
						    } else {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
							    = 
							    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
							      ? 0x7aU
							      : 0x3aU);
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
						    }
						}
					    }
					}
				    }
				}
			    }
			} else {
			    if (((((((((0x3007U == 
					(0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
				       | (0x3008U == 
					  (0xf00fU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				      | (0x300aU == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				     | (0x300bU == 
					(0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				    | (0x300cU == (0xf00fU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				   | (0x300dU == (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				  | (0x300eU == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				 | (0x300fU == (0xf00fU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
				if ((0x3007U == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
					= ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
					    ? 0x79U
					    : 0x39U);
				    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xaU;
				} else {
				    if ((0x3008U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x11U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
				    } else {
					if ((0x300aU 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x19U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					} else {
					    if ((0x300bU 
						 == 
						 (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1bU;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
					    } else {
						if (
						    (0x300cU 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x10U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
						} else {
						    if (
							(0x300dU 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1fU;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xbU;
						    } else {
							if (
							    (0x300eU 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x18U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
							} else {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x1aU;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
							}
						    }
						}
					    }
					}
				    }
				}
			    } else {
				if (((((((((0x4000U 
					    == (0xf0ffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
					   | (0x4010U 
					      == (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					  | (0x4020U 
					     == (0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					 | (0x4001U 
					    == (0xf0ffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					| (0x4011U 
					   == (0xf0ffU 
					       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				       | (0x4021U == 
					  (0xf0ffU 
					   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				      | (0x4002U == 
					 (0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
				     | (0x4003U == 
					(0xf00fU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
				    if ((0x4000U == 
					 (0xf0ffU & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x60U;
					vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
				    } else {
					if ((0x4010U 
					     == (0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x68U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					} else {
					    if ((0x4020U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x61U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					    } else {
						if (
						    (0x4001U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x62U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						} else {
						    if (
							(0x4011U 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
							    = 
							    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
							      ? 0x7bU
							      : 0x3bU);
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						    } else {
							if (
							    (0x4021U 
							     == 
							     (0xf0ffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x63U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
							} else {
							    if (
								(0x4002U 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
								      ? 0xbU
								      : 0xaU);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 2U;
							    } else {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
								      ? 0xbU
								      : 0xaU);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 3U;
							    }
							}
						    }
						}
					    }
					}
				    }
				} else {
				    if (((((((((0x4004U 
						== 
						(0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
					       | (0x4024U 
						  == 
						  (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					      | (0x4005U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					     | (0x4015U 
						== 
						(0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					    | (0x4025U 
					       == (0xf0ffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					   | (0x4006U 
					      == (0xf00fU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					  | (0x4007U 
					     == (0xf00fU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					 | (0x4008U 
					    == (0xf0ffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
					if ((0x4004U 
					     == (0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
					    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x64U;
					    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					} else {
					    if ((0x4024U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x65U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
					    } else {
						if (
						    (0x4005U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x66U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						} else {
						    if (
							(0x4015U 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
							    = 
							    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
							      ? 0x79U
							      : 0x39U);
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						    } else {
							if (
							    (0x4025U 
							     == 
							     (0xf0ffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x67U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
							} else {
							    if (
								(0x4006U 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
								      ? 0xfU
								      : 0xeU);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
							    } else {
								if (
								    (0x4007U 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
									= 
									((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)
									  ? 0xbU
									  : 0xeU);
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								} else {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
								    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 2U;
								}
							    }
							}
						    }
						}
					    }
					}
				    } else {
					if ((((((((
						   (0x4018U 
						    == 
						    (0xf0ffU 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
						   | (0x4028U 
						      == 
						      (0xf0ffU 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						  | (0x4009U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						 | (0x4019U 
						    == 
						    (0xf0ffU 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						| (0x4029U 
						   == 
						   (0xf0ffU 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					       | (0x400aU 
						  == 
						  (0xf00fU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					      | (0x400bU 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
					     | (0x402bU 
						== 
						(0xf0ffU 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
					    if ((0x4018U 
						 == 
						 (0xf0ffU 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
						vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
						vlTOPp->ExUnit__DOT__dec__DOT__opImm = 8U;
					    } else {
						if (
						    (0x4028U 
						     == 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
						    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
						    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0x10U;
						} else {
						    if (
							(0x4009U 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
							vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0xfffffffeU;
						    } else {
							if (
							    (0x4019U 
							     == 
							     (0xf0ffU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
							    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0xfffffff8U;
							} else {
							    if (
								(0x4029U 
								 == 
								 (0xf0ffU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x17U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x12U;
								vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0xfffffff0U;
							    } else {
								if (
								    (0x400aU 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
								} else {
								    if (
									(0x400bU 
									 == 
									 (0xf0ffU 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x44U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
								    } else {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x46U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
								    }
								}
							    }
							}
						    }
						}
					    }
					} else {
					    if ((((
						   (((((0x403bU 
							== 
							(0xf0ffU 
							 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
						       | (0x404bU 
							  == 
							  (0xf0ffU 
							   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						      | (0x400cU 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						     | (0x400dU 
							== 
							(0xf00fU 
							 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						    | (0x400eU 
						       == 
						       (0xf00fU 
							& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						   | (0x5000U 
						      == 
						      (0xf000U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						  | (0x6000U 
						     == 
						     (0xf00fU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						 | (0x6001U 
						    == 
						    (0xf00fU 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
						if (
						    (0x403bU 
						     != 
						     (0xf0ffU 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
						    if (
							(0x404bU 
							 == 
							 (0xf0ffU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x45U;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 2U;
						    } else {
							if (
							    (0x400cU 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								= 
								((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
								  ? 0x76U
								  : 0x16U);
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
							} else {
							    if (
								(0x400dU 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
								    = 
								    ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
								      ? 0x77U
								      : 0x17U);
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 9U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
							    } else {
								if (
								    (0x400eU 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								} else {
								    if (
									(0x5000U 
									 == 
									 (0xf000U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 6U;
								    } else {
									if (
									    (0x6000U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
									} else {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
										= 
										((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
										 ? 0xfU
										 : 0xdU);
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
									}
								    }
								}
							    }
							}
						    }
						}
					    } else {
						if (
						    ((((((((0x6002U 
							    == 
							    (0xf00fU 
							     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
							   | (0x6003U 
							      == 
							      (0xf00fU 
							       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							  | (0x6004U 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							 | (0x6005U 
							    == 
							    (0xf00fU 
							     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							| (0x6006U 
							   == 
							   (0xf00fU 
							    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						       | (0x6007U 
							  == 
							  (0xf00fU 
							   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						      | (0x6008U 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
						     | (0x6009U 
							== 
							(0xf00fU 
							 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
						    if (
							(0x6002U 
							 == 
							 (0xf00fU 
							  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
							vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
						    } else {
							if (
							    (0x6003U 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 1U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
							} else {
							    if (
								(0x6004U 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
							    } else {
								if (
								    (0x6005U 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
									= 
									((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPwDQ)
									  ? 0xfU
									  : 0xdU);
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								} else {
								    if (
									(0x6006U 
									 == 
									 (0xf00fU 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
								    } else {
									if (
									    (0x6007U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x51U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									} else {
									    if (
										(0x6008U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x52U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									    } else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x53U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									    }
									}
								    }
								}
							    }
							}
						    }
						} else {
						    if (
							((((((((0x600aU 
								== 
								(0xf00fU 
								 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
							       | (0x600bU 
								  == 
								  (0xf00fU 
								   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							      | (0x600cU 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							     | (0x600dU 
								== 
								(0xf00fU 
								 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							    | (0x600eU 
							       == 
							       (0xf00fU 
								& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							   | (0x600fU 
							      == 
							      (0xf00fU 
							       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							  | (0x7000U 
							     == 
							     (0xf000U 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							 | (0x8000U 
							    == 
							    (0xff00U 
							     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
							if (
							    (0x600aU 
							     == 
							     (0xf00fU 
							      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
							    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x59U;
							    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
							} else {
							    if (
								(0x600bU 
								 == 
								 (0xf00fU 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x58U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
							    } else {
								if (
								    (0x600cU 
								     == 
								     (0xf00fU 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x54U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								} else {
								    if (
									(0x600dU 
									 == 
									 (0xf00fU 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x55U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
								    } else {
									if (
									    (0x600eU 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x56U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									} else {
									    if (
										(0x600fU 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x57U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 8U;
									    } else {
										if (
										(0x7000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x10U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xcU;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 6U;
										}
									    }
									}
								    }
								}
							    }
							}
						    } else {
							if (
							    ((((((((0x8100U 
								    == 
								    (0xff00U 
								     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
								   | (0x8200U 
								      == 
								      (0xff00U 
								       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								  | (0x8300U 
								     == 
								     (0xff00U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								 | (0x8400U 
								    == 
								    (0xff00U 
								     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								| (0x8500U 
								   == 
								   (0xff00U 
								    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							       | (0x8600U 
								  == 
								  (0xff00U 
								   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							      | (0x8800U 
								 == 
								 (0xff00U 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
							     | (0x8900U 
								== 
								(0xff00U 
								 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
							    if (
								(0x8100U 
								 == 
								 (0xff00U 
								  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 9U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
								vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 6U;
							    } else {
								if (
								    (0x8200U 
								     == 
								     (0xff00U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x32U;
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
								} else {
								    if (
									(0x8300U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
									if (
									    (0x80U 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 3U;
									} else {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 2U;
									}
								    } else {
									if (
									    (0x8400U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 7U;
									} else {
									    if (
										(0x8500U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xdU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 7U;
									    } else {
										if (
										(0x8600U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										if (
										(0x80U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 5U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										}
										} else {
										if (
										(0x8800U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x38U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x36U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
										}
										}
									    }
									}
								    }
								}
							    }
							} else {
							    if (
								((((((((0x8a00U 
									== 
									(0xff00U 
									 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
								       | (0x8b00U 
									  == 
									  (0xff00U 
									   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								      | (0x8c00U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								     | (0x8d00U 
									== 
									(0xff00U 
									 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								    | (0x8e00U 
								       == 
								       (0xff00U 
									& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								   | (0x8f00U 
								      == 
								      (0xff00U 
								       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								  | (0x9000U 
								     == 
								     (0xf000U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								 | (0xa000U 
								    == 
								    (0xf000U 
								     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
								if (
								    (0x8a00U 
								     == 
								     (0xff00U 
								      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
								    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
								    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 2U;
								    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
									= 
									((((1U 
									    & (IData)(
										(vlTOPp->ExUnit__DOT__regIdPcVal 
										>> 7U)))
									    ? 0xffU
									    : 0U) 
									  << 0x18U) 
									 | ((0xff0000U 
									     & ((IData)(vlTOPp->ExUnit__DOT__regIdPcVal) 
										<< 0x10U)) 
									    | (0xffffU 
									       & (IData)(
										(vlTOPp->ExUnit__DOT__regIdPcVal 
										>> 0x10U)))));
								    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
								} else {
								    if (
									(0x8b00U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x37U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
								    } else {
									if (
									    (0x8c00U 
									     != 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    if (
										(0x8d00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x34U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
									    } else {
										if (
										(0x8e00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__isOpXE = 1U;
										vlTOPp->ExUnit__DOT__dec__DOT__opStepPc = 4U;
										} else {
										if (
										(0x8f00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x35U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xeU;
										} else {
										if (
										(0x9000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
										= 
										((0x70U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN)) 
										| (0xfU 
										& ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
										>> 8U)));
										vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x7aU;
										vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7fU;
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xdU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
										vlTOPp->ExUnit__DOT__dec__DOT__opImm 
										= 
										((0xffffff00U 
										& vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
										| (0xffU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x30U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xfU;
										}
										}
										}
									    }
									}
								    }
								}
							    } else {
								if (
								    ((((((((0xb000U 
									    == 
									    (0xf000U 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
									   | (0xc000U 
									      == 
									      (0xff00U 
									       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									  | (0xc100U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									 | (0xc200U 
									    == 
									    (0xff00U 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									| (0xc400U 
									   == 
									   (0xff00U 
									    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								       | (0xc500U 
									  == 
									  (0xff00U 
									   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								      | (0xc600U 
									 == 
									 (0xff00U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
								     | (0xc800U 
									== 
									(0xff00U 
									 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
								    if (
									(0xb000U 
									 == 
									 (0xf000U 
									  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x31U;
									vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xfU;
								    } else {
									if (
									    (0xc000U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    if (vlTOPp->ExUnit__DOT__dec__DOT__opJQ) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xbU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 0U;
									    } else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 8U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x13U;
									    }
									} else {
									    if (
										(0xc100U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 9U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x13U;
										}
									    } else {
										if (
										(0xc200U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x13U;
										}
										} else {
										if (
										(0xc400U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (vlTOPp->ExUnit__DOT__dec__DOT__opJQ) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xfU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x16U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 1U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xcU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x17U;
										}
										} else {
										if (
										(0xc500U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xdU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x17U;
										}
										} else {
										if (
										(0xc600U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										if (
										(1U 
										& (~ (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opJQ)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x17U;
										}
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd 
										= 
										((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opPsDQ)
										 ? 0x7dU
										 : 0x3dU);
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x11U;
										}
										}
										}
										}
									    }
									}
								    }
								} else {
								    if (
									((((((((0xc900U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))) 
									       | (0xca00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									      | (0xcb00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									     | (0xd000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									    | (0xe000U 
									       == 
									       (0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									   | (0xf000U 
									      == 
									      (0xf00fU 
									       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									  | (0xf001U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) 
									 | (0xf002U 
									    == 
									    (0xf00fU 
									     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))))) {
									if (
									    (0xc900U 
									     == 
									     (0xff00U 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x13U;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
									} else {
									    if (
										(0xca00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x15U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
									    } else {
										if (
										(0xcb00U 
										== 
										(0xff00U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x14U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x10U;
										} else {
										if (
										(0xd000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
										= 
										((0x70U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN)) 
										| (0xfU 
										& ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
										>> 8U)));
										vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x7bU;
										vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7fU;
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0U;
										vlTOPp->ExUnit__DOT__dec__DOT__opImm 
										= 
										((0xffffff00U 
										& vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
										| (0xffU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
										} else {
										if (
										(0xe000U 
										== 
										(0xf000U 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 2U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0xcU;
										} else {
										if (
										(0xf000U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x21U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
										} else {
										if (
										(0xf001U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x22U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
										} else {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x23U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
										}
										}
										}
										}
										}
									    }
									}
								    } else {
									if (
									    (0xf004U 
									     == 
									     (0xf00fU 
									      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
									    vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x2aU;
									    vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
									} else {
									    if (
										(0xf005U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0x2bU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 0x14U;
									    } else {
										if (
										(0xf006U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										} else {
										if (
										(0xf007U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 5U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 5U;
										} else {
										if (
										(0xf008U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										} else {
										if (
										(0xf009U 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xeU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 7U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 4U;
										} else {
										if (
										(0xf00aU 
										== 
										(0xf00fU 
										& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)))) {
										vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = 0xaU;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm = 4U;
										vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx = 5U;
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
	}
    }
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl = (0xfU 
						 & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						    >> 8U));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl = (0xfU 
						 & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						    >> 4U));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR = (0x20U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR = (0x60U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN_FR = (0x40U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 8U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegM_FR = (0x40U 
						| (0xfU 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opRegN_N3 = (8U 
						| (7U 
						   & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						      >> 4U)));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4 = (0xfU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8 = (0xffU 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx8 = ((((0x80U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))
						   ? 0xffffffU
						   : 0U) 
						 << 8U) 
						| (0xffU 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
    vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx12 = (((
						   (0x800U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord))
						    ? 0xfffffU
						    : 0U) 
						  << 0xcU) 
						 | (0xfffU 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
    if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    }
		} else {
		    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
		    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		}
	    } else {
		vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
		vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8;
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= (0x48U | 
					   (7U & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						  >> 4U)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= (0x48U | 
					   (7U & ((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord) 
						  >> 4U)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_N3;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= ((0xfffffff0U 
					    & vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
					   | (0xfU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (0x10U | 
					   (0xfU & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_N3;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= ((0xfffffff0U 
					    & vlTOPp->ExUnit__DOT__dec__DOT__opImm) 
					   | (0xfU 
					      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opCmdWord)));
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= (0x10U | 
					   (0xfU & vlTOPp->ExUnit__DOT__dec__DOT__opImm));
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0xfU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
				    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
					= vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
				}
			    }
			}
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_FR;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_FR;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0x21U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx8;
		    }
		}
	    }
	}
    } else {
	if ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			= ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))
			    ? vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx12
			    : vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx8);
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7cU;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Sx8;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    }
		}
	    }
	} else {
	    if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_FR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_FR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
				vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				}
			    }
			}
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opImm_Zx4;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegM_Dfl;
		    }
		}
	    } else {
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7dU;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0x7eU;
				}
			    }
			}
		    } else {
			vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
			vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
			    = vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrm))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegN = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegS = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opRegT = 0U;
			    vlTOPp->ExUnit__DOT__dec__DOT__opImm = 0U;
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__tOpDecXfrmZx))) {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_CR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				} else {
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegN 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegM_SR;
				    vlTOPp->ExUnit__DOT__dec__DOT__opRegS 
					= vlTOPp->ExUnit__DOT__dec__DOT__opRegN_Dfl;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if (vlTOPp->ExUnit__DOT__dec__DOT__isOpXE) {
	vlTOPp->ExUnit__DOT__dec__DOT__opRegN = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegN;
	vlTOPp->ExUnit__DOT__dec__DOT__opRegS = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegS;
	vlTOPp->ExUnit__DOT__dec__DOT__opRegT = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opRegT;
	vlTOPp->ExUnit__DOT__dec__DOT__opImm = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opImm;
	vlTOPp->ExUnit__DOT__dec__DOT__opUCmd = vlTOPp->ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd;
	vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2 = vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2A;
    } else {
	vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2 = vlTOPp->ExUnit__DOT__dec__DOT__opStepPc2B;
    }
    // ALWAYS at ExUnit.v:486
    vlTOPp->ExUnit__DOT__idUCmd2 = vlTOPp->ExUnit__DOT__dec__DOT__opUCmd;
    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
		  >> 7U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
	    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
			  >> 5U)))) {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
			      >> 4U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				  >> 3U)))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x20U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				  >> 3U)))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
			    }
			}
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void VExUnit::_combo__TOP__6(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_combo__TOP__6\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp27,127,0,4);
    VL_SIGW(__Vtemp28,127,0,4);
    VL_SIGW(__Vtemp29,127,0,4);
    VL_SIGW(__Vtemp30,127,0,4);
    VL_SIGW(__Vtemp31,127,0,4);
    VL_SIGW(__Vtemp32,127,0,4);
    VL_SIGW(__Vtemp33,127,0,4);
    VL_SIGW(__Vtemp34,127,0,4);
    VL_SIGW(__Vtemp35,127,0,4);
    VL_SIGW(__Vtemp36,127,0,4);
    VL_SIGW(__Vtemp37,127,0,4);
    VL_SIGW(__Vtemp38,127,0,4);
    // Body
    // ALWAYS at Dc2Tile.v:119
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx = (0x7ffU 
						  & (vlTOPp->ExUnit__DOT__dc2RegInAddr 
						     >> 4U));
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx = vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileSt = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOutData = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioAddr = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOE = 0U;
    vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR = 0U;
    if (VL_UNLIKELY(((IData)(vlTOPp->ExUnit__DOT__dc2RegInOE) 
		     | (IData)(vlTOPp->ExUnit__DOT__dc2RegInWR)))) {
	VL_WRITEF("DcTile2 %x %1# %1#\n",32,vlTOPp->ExUnit__DOT__dc2RegInAddr,
		  1,(0x100000U >= (0x1fffffffU & vlTOPp->ExUnit__DOT__dc2RegInAddr)),
		  1,(IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__addrIsRam));
	if (VL_UNLIKELY((0x100000U >= (0x1fffffffU 
				       & vlTOPp->ExUnit__DOT__dc2RegInAddr)))) {
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][0U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][1U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][2U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__romTile
		[(0xffU & (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))][3U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK = 1U;
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
	    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
		= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
	    VL_WRITEF("Rom: %x\n",128,vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile);
	    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			VL_EXTEND_WQ(128,64, __Vtemp27, 
				     (((QData)((IData)(
						       vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U])) 
				       << 0x20U) | (QData)((IData)(
								   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]))));
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = __Vtemp27[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = __Vtemp27[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = __Vtemp27[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = __Vtemp27[3U];
		    } else {
			VL_EXTEND_WQ(128,64, __Vtemp28, 
				     (((QData)((IData)(
						       vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U])) 
				       << 0x20U) | (QData)((IData)(
								   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]))));
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = __Vtemp28[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = __Vtemp28[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = __Vtemp28[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = __Vtemp28[3U];
		    }
		} else {
		    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    VL_EXTEND_WI(128,32, __Vtemp29, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp29[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp29[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp29[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp29[3U];
			} else {
			    VL_EXTEND_WI(128,32, __Vtemp30, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp30[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp30[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp30[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp30[3U];
			}
		    } else {
			if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    VL_EXTEND_WI(128,32, __Vtemp31, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp31[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp31[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp31[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp31[3U];
			} else {
			    VL_EXTEND_WI(128,32, __Vtemp32, 
					 vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]);
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp32[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp32[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp32[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp32[3U];
			}
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		} else {
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		}
	    }
	    VL_WRITEF("Rom: Out=%x\n",128,vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData);
	} else {
	    if (vlTOPp->ExUnit__DOT__dcl2__DOT__addrIsRam) {
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[0U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[1U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[2U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tRamTile[3U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
		    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK 
		    = (((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tAccTileIx) 
			== (IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx))
		        ? 1U : 2U);
		if ((2U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    VL_EXTEND_WQ(128,64, __Vtemp33, 
					 (((QData)((IData)(
							   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U])) 
					   << 0x20U) 
					  | (QData)((IData)(
							    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]))));
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp33[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp33[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp33[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp33[3U];
			} else {
			    VL_EXTEND_WQ(128,64, __Vtemp34, 
					 (((QData)((IData)(
							   vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U])) 
					   << 0x20U) 
					  | (QData)((IData)(
							    vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]))));
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				= __Vtemp34[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				= __Vtemp34[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				= __Vtemp34[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				= __Vtemp34[3U];
			}
		    } else {
			if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
			    if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				VL_EXTEND_WI(128,32, __Vtemp35, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp35[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp35[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp35[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp35[3U];
			    } else {
				VL_EXTEND_WI(128,32, __Vtemp36, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp36[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp36[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp36[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp36[3U];
			    }
			} else {
			    if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				VL_EXTEND_WI(128,32, __Vtemp37, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp37[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp37[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp37[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp37[3U];
			    } else {
				VL_EXTEND_WI(128,32, __Vtemp38, 
					     vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U]);
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
				    = __Vtemp38[0U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
				    = __Vtemp38[1U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
				    = __Vtemp38[2U];
				vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
				    = __Vtemp38[3U];
			    }
			}
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		    } else {
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[0U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[1U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[2U];
			vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] 
			    = vlTOPp->ExUnit__DOT__dcl2__DOT__tMemTile[3U];
		    }
		}
		if (vlTOPp->ExUnit__DOT__dc2RegInWR) {
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileIx 
			= vlTOPp->ExUnit__DOT__dcl2__DOT__tRegTileIx;
		    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTileSt = 1U;
		    if ((2U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
				    = (IData)((((QData)((IData)(
								vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[0U]))));
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
				    = (IData)(((((QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->ExUnit__DOT__dc2RegInData[0U]))) 
					       >> 0x20U));
			    } else {
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
				    = (IData)((((QData)((IData)(
								vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[0U]))));
				vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
				    = (IData)(((((QData)((IData)(
								 vlTOPp->ExUnit__DOT__dc2RegInData[1U])) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->ExUnit__DOT__dc2RegInData[0U]))) 
					       >> 0x20U));
			    }
			} else {
			    if ((8U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				} else {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				}
			    } else {
				if ((4U & vlTOPp->ExUnit__DOT__dc2RegInAddr)) {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				} else {
				    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
					= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
				}
			    }
			}
		    } else {
			if ((1U & (IData)(vlTOPp->ExUnit__DOT__dc2RegInOp))) {
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[3U];
			} else {
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[0U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[0U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[1U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[1U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[2U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[2U];
			    vlTOPp->ExUnit__DOT__dcl2__DOT__tNextTile[3U] 
				= vlTOPp->ExUnit__DOT__dc2RegInData[3U];
			}
		    }
		}
	    } else {
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOutData 
		    = vlTOPp->ExUnit__DOT__dc2RegInData[0U];
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioAddr 
		    = vlTOPp->ExUnit__DOT__dc2RegInAddr;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOE 
		    = vlTOPp->ExUnit__DOT__dc2RegInOE;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR 
		    = vlTOPp->ExUnit__DOT__dc2RegInWR;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tRegOutOK 
		    = vlTOPp->mmioOK;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[0U] = 0U;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[1U] = 0U;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[2U] = 0U;
		vlTOPp->ExUnit__DOT__dcl2__DOT__tOutData[3U] = 0U;
	    }
	}
    }
    // ALWAYS at ExUnit.v:454
    vlTOPp->ExUnit__DOT__tRegGenIdStepPc = vlTOPp->ExUnit__DOT__exStepPc2;
    vlTOPp->ExUnit__DOT__tRegGenIdPc = (vlTOPp->ExUnit__DOT__regIfPc 
					+ (IData)(vlTOPp->ExUnit__DOT__tRegGenIdStepPc));
    vlTOPp->ExUnit__DOT__regIfPcVal2 = vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal;
    if ((vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
	 != vlTOPp->ExUnit__DOT__tRegGenIdPc)) {
	vlTOPp->ExUnit__DOT__regIfPcVal2 = VL_ULL(0xf090f090e09);
    }
    vlTOPp->mmioWR = vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR;
    vlTOPp->mmioAddr = vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioAddr;
    vlTOPp->mmioOE = vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOE;
    // ALWAYS at ExOp2.v:206
    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId = 0x7fU;
    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutOK = 1U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemData = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs = VL_ULL(0);
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlNxtPc = (vlTOPp->ExUnit__DOT__regExPc 
						 + (IData)(vlTOPp->ExUnit__DOT__exStepPc));
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlPrPc = ((IData)(2U) 
						+ vlTOPp->ExUnit__DOT__exOp__DOT__tCtlNxtPc);
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlBraPc = (vlTOPp->ExUnit__DOT__exOp__DOT__tCtlPrPc 
						 + 
						 (vlTOPp->ExUnit__DOT__exImm 
						  << 1U));
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr = vlTOPp->ExUnit__DOT__gpr__DOT__regSr;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPr = vlTOPp->ExUnit__DOT__gpr__DOT__regPr;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc = vlTOPp->ExUnit__DOT__tRegGenIdPc;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac = vlTOPp->ExUnit__DOT__gpr__DOT__regMac;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSp = vlTOPp->ExUnit__DOT__gpr__DOT__regSp;
    vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi = (vlTOPp->ExUnit__DOT__exRegValT 
						+ vlTOPp->ExUnit__DOT__exImm);
    vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRiSc = ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						    ? 
						   (0xfffffff8U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi 
						       << 3U))
						    : 
						   (0xfffffffcU 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi 
						       << 2U)))
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						    ? 
						   (0xfffffffeU 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi 
						       << 1U))
						    : vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi));
    vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr = (((4U 
						  & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						  ? vlTOPp->ExUnit__DOT__exRegValS
						  : vlTOPp->ExUnit__DOT__exRegValN) 
						+ (
						   (0U 
						    == (IData)(vlTOPp->ExUnit__DOT__exRegT))
						    ? vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi
						    : vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRiSc));
    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
		  >> 7U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
	    if ((0x20U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
			      >> 4U)))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
					  >> 1U)))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 4U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 3U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ0 
					= (1U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						 >> 8U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0 
					= (1U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						 >> 9U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluT0 
					= (1U & vlTOPp->ExUnit__DOT__gpr__DOT__regSr);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ1 
					= (1U & (vlTOPp->ExUnit__DOT__exRegValS 
						 >> 0x1fU));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
					= ((VL_ULL(1) 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1) 
					   | ((QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS)) 
					      << 1U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
					= ((VL_ULL(0x1fffffffe) 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1) 
					   | (IData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluT0)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn2 
					= (VL_ULL(0x1ffffffff) 
					   & (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ0) 
					       == (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0))
					       ? (vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
						  - (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))
					       : (vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
						  + (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluM1 
					= (1U & (IData)(
							(vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn2 
							 >> 0x20U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ2 
					= (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ1) 
					    ^ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0)) 
					   ^ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM1));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluT2 
					= (1U & (~ 
						 ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ2) 
						  ^ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn2);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffeffU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ2) 
					      << 8U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluT2));
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffeffU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (0x100U 
					      & (vlTOPp->ExUnit__DOT__exRegValS 
						 >> 0x17U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffdffU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (0x200U 
					      & (vlTOPp->ExUnit__DOT__exRegValT 
						 >> 0x16U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((vlTOPp->ExUnit__DOT__exRegValS 
						^ vlTOPp->ExUnit__DOT__exRegValT) 
					       >> 0x1fU)));
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((VL_ULL(0x100000000) 
							      | (QData)((IData)(
										(~ vlTOPp->ExUnit__DOT__exRegValS)))) 
							     + 
							     ((1U 
							       & vlTOPp->ExUnit__DOT__gpr__DOT__regSr)
							       ? VL_ULL(0)
							       : VL_ULL(1))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((~ vlTOPp->ExUnit__DOT__exRegValS) 
					   + (IData)(
						     ((1U 
						       & vlTOPp->ExUnit__DOT__gpr__DOT__regSr)
						       ? VL_ULL(0)
						       : VL_ULL(1))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= VL_NEGATE_I(vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((((0x8000U 
					      & vlTOPp->ExUnit__DOT__exRegValS)
					      ? 0xfU
					      : 0U) 
					    << 0x10U) 
					   | (0xffffU 
					      & vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((((0x80U 
					      & vlTOPp->ExUnit__DOT__exRegValS)
					      ? 0xfU
					      : 0U) 
					    << 8U) 
					   | (0xffU 
					      & vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (0xffffU 
					   & vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((0xffff0000U 
					    & (vlTOPp->ExUnit__DOT__exRegValS 
					       << 0x10U)) 
					   | (0xffffU 
					      & (vlTOPp->ExUnit__DOT__exRegValS 
						 >> 0x10U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((0xff000000U 
					    & (vlTOPp->ExUnit__DOT__exRegValS 
					       << 8U)) 
					   | ((0xff0000U 
					       & (vlTOPp->ExUnit__DOT__exRegValS 
						  >> 8U)) 
					      | ((0xff00U 
						  & (vlTOPp->ExUnit__DOT__exRegValS 
						     << 8U)) 
						 | (0xffU 
						    & (vlTOPp->ExUnit__DOT__exRegValS 
						       >> 8U)))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (~ vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((0xffff0000U 
					    & (vlTOPp->ExUnit__DOT__exRegValS 
					       << 0x10U)) 
					   + vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		} else {
		    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				  >> 3U)))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regSPc;
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regSSr;
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSp 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regSGr;
			    } else {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regPr;
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x20U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
					  >> 1U)))) {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
				    = ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				        ? ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (0U == 
					      (vlTOPp->ExUnit__DOT__exRegValS 
					       & vlTOPp->ExUnit__DOT__exRegValT)))
				        : ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (vlTOPp->ExUnit__DOT__exRegValS 
					      >= vlTOPp->ExUnit__DOT__exRegValT)));
			    }
			} else {
			    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
				= ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				        ? ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((vlTOPp->ExUnit__DOT__exRegValS 
						>= vlTOPp->ExUnit__DOT__exRegValT) 
					       ^ ((vlTOPp->ExUnit__DOT__exRegValS 
						   ^ vlTOPp->ExUnit__DOT__exRegValT) 
						  >> 0x1fU))))
				        : ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (vlTOPp->ExUnit__DOT__exRegValS 
					      > vlTOPp->ExUnit__DOT__exRegValT)))
				    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				        ? ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((vlTOPp->ExUnit__DOT__exRegValS 
						> vlTOPp->ExUnit__DOT__exRegValT) 
					       ^ ((vlTOPp->ExUnit__DOT__exRegValS 
						   ^ vlTOPp->ExUnit__DOT__exRegValT) 
						  >> 0x1fU))))
				        : ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (vlTOPp->ExUnit__DOT__exRegValS 
					      == vlTOPp->ExUnit__DOT__exRegValT))));
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlBraPc;
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPr 
				    = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlPrPc;
			    } else {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlBraPc;
			    }
			}
		    }
		}
	    } else {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (((QData)((IData)(
							    ((0x80000000U 
							      & vlTOPp->ExUnit__DOT__exRegValS)
							      ? 0xffffffffU
							      : 0U))) 
					    << 0x20U) 
					   | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= ((((0x8000U 
					      & vlTOPp->ExUnit__DOT__exRegValS)
					      ? VL_ULL(0xffffffffffff)
					      : VL_ULL(0)) 
					    << 0x10U) 
					   | (QData)((IData)(
							     (0xffffU 
							      & vlTOPp->ExUnit__DOT__exRegValS))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (QData)((IData)(
							  (0xffffU 
							   & vlTOPp->ExUnit__DOT__exRegValS)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValS 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS))) 
							     - 
							     (((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValT 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   - vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC) 
					       ^ (vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
						  >> 0x1fU))));
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValS 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS))) 
							     + 
							     (((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValT 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   + vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC) 
					       ^ (vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
						  >> 0x1fU))));
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC 
					= (1U & vlTOPp->ExUnit__DOT__gpr__DOT__regSr);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((QData)((IData)(
									     (vlTOPp->ExUnit__DOT__exRegValS 
									      - vlTOPp->ExUnit__DOT__exRegValT))) 
							     - (QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((vlTOPp->ExUnit__DOT__exRegValS 
					    - vlTOPp->ExUnit__DOT__exRegValT) 
					   - (IData)((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC));
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC 
					= (1U & vlTOPp->ExUnit__DOT__gpr__DOT__regSr);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((QData)((IData)(
									     (vlTOPp->ExUnit__DOT__exRegValS 
									      + vlTOPp->ExUnit__DOT__exRegValT))) 
							     + (QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((vlTOPp->ExUnit__DOT__exRegValS 
					    + vlTOPp->ExUnit__DOT__exRegValT) 
					   + (IData)((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC));
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 2U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   ^ vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   | vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 3U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   - vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   + vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 3U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(8U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 2U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(4U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 1U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(2U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 0U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(1U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 3U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(8U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(8U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 2U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(4U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(4U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 1U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(2U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(2U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 0U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(1U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(1U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__exUCmd)))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exImm;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if ((0U != (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))) {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))) {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
		    = vlTOPp->ExUnit__DOT__gpr__DOT__regMac;
		vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
		    = (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu);
	    } else {
		vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
		    = (vlTOPp->ExUnit__DOT__gpr__DOT__regMac 
		       + vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu);
	    }
	} else {
	    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
		= ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))
		    ? vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu
		    : vlTOPp->ExUnit__DOT__gpr__DOT__regMac);
	}
	vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutOK = 
	    (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpB) 
	      == (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))
	      ? 1U : 2U);
    }
    if ((0U != (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
	vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
	    = vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn;
    }
}

void VExUnit::_settle__TOP__7(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_settle__TOP__7\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ExUnit.v:486
    vlTOPp->ExUnit__DOT__idUCmd2 = vlTOPp->ExUnit__DOT__dec__DOT__opUCmd;
    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
		  >> 7U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
	    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
			  >> 5U)))) {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
			      >> 4U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				  >> 3U)))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x20U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				  >> 3U)))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__idUCmd2 = 0U;
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->mmioWR = vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR;
    vlTOPp->mmioAddr = vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioAddr;
    vlTOPp->mmioOE = vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOE;
    // ALWAYS at ExOp2.v:206
    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId = 0x7fU;
    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutOK = 1U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemData = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs = VL_ULL(0);
    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlNxtPc = (vlTOPp->ExUnit__DOT__regExPc 
						 + (IData)(vlTOPp->ExUnit__DOT__exStepPc));
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlPrPc = ((IData)(2U) 
						+ vlTOPp->ExUnit__DOT__exOp__DOT__tCtlNxtPc);
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlBraPc = (vlTOPp->ExUnit__DOT__exOp__DOT__tCtlPrPc 
						 + 
						 (vlTOPp->ExUnit__DOT__exImm 
						  << 1U));
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr = vlTOPp->ExUnit__DOT__gpr__DOT__regSr;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPr = vlTOPp->ExUnit__DOT__gpr__DOT__regPr;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc = vlTOPp->ExUnit__DOT__tRegGenIdPc;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac = vlTOPp->ExUnit__DOT__gpr__DOT__regMac;
    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSp = vlTOPp->ExUnit__DOT__gpr__DOT__regSp;
    vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi = (vlTOPp->ExUnit__DOT__exRegValT 
						+ vlTOPp->ExUnit__DOT__exImm);
    vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRiSc = ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						    ? 
						   (0xfffffff8U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi 
						       << 3U))
						    : 
						   (0xfffffffcU 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi 
						       << 2U)))
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						    ? 
						   (0xfffffffeU 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi 
						       << 1U))
						    : vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi));
    vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr = (((4U 
						  & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
						  ? vlTOPp->ExUnit__DOT__exRegValS
						  : vlTOPp->ExUnit__DOT__exRegValN) 
						+ (
						   (0U 
						    == (IData)(vlTOPp->ExUnit__DOT__exRegT))
						    ? vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRi
						    : vlTOPp->ExUnit__DOT__exOp__DOT__tAguRtRiSc));
    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
		  >> 7U)))) {
	if ((0x40U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
	    if ((0x20U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
			      >> 4U)))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
					  >> 1U)))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 4U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 3U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		}
	    } else {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ0 
					= (1U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						 >> 8U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0 
					= (1U & (vlTOPp->ExUnit__DOT__gpr__DOT__regSr 
						 >> 9U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluT0 
					= (1U & vlTOPp->ExUnit__DOT__gpr__DOT__regSr);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ1 
					= (1U & (vlTOPp->ExUnit__DOT__exRegValS 
						 >> 0x1fU));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
					= ((VL_ULL(1) 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1) 
					   | ((QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS)) 
					      << 1U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
					= ((VL_ULL(0x1fffffffe) 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1) 
					   | (IData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluT0)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn2 
					= (VL_ULL(0x1ffffffff) 
					   & (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ0) 
					       == (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0))
					       ? (vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
						  - (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))
					       : (vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn1 
						  + (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluM1 
					= (1U & (IData)(
							(vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn2 
							 >> 0x20U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ2 
					= (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ1) 
					    ^ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0)) 
					   ^ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM1));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tAluT2 
					= (1U & (~ 
						 ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ2) 
						  ^ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluM0))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluDn2);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffeffU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluQ2) 
					      << 8U));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tAluT2));
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffeffU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (0x100U 
					      & (vlTOPp->ExUnit__DOT__exRegValS 
						 >> 0x17U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffdffU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (0x200U 
					      & (vlTOPp->ExUnit__DOT__exRegValT 
						 >> 0x16U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((vlTOPp->ExUnit__DOT__exRegValS 
						^ vlTOPp->ExUnit__DOT__exRegValT) 
					       >> 0x1fU)));
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((VL_ULL(0x100000000) 
							      | (QData)((IData)(
										(~ vlTOPp->ExUnit__DOT__exRegValS)))) 
							     + 
							     ((1U 
							       & vlTOPp->ExUnit__DOT__gpr__DOT__regSr)
							       ? VL_ULL(0)
							       : VL_ULL(1))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((~ vlTOPp->ExUnit__DOT__exRegValS) 
					   + (IData)(
						     ((1U 
						       & vlTOPp->ExUnit__DOT__gpr__DOT__regSr)
						       ? VL_ULL(0)
						       : VL_ULL(1))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= VL_NEGATE_I(vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((((0x8000U 
					      & vlTOPp->ExUnit__DOT__exRegValS)
					      ? 0xfU
					      : 0U) 
					    << 0x10U) 
					   | (0xffffU 
					      & vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((((0x80U 
					      & vlTOPp->ExUnit__DOT__exRegValS)
					      ? 0xfU
					      : 0U) 
					    << 8U) 
					   | (0xffU 
					      & vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (0xffffU 
					   & vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((0xffff0000U 
					    & (vlTOPp->ExUnit__DOT__exRegValS 
					       << 0x10U)) 
					   | (0xffffU 
					      & (vlTOPp->ExUnit__DOT__exRegValS 
						 >> 0x10U)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((0xff000000U 
					    & (vlTOPp->ExUnit__DOT__exRegValS 
					       << 8U)) 
					   | ((0xff0000U 
					       & (vlTOPp->ExUnit__DOT__exRegValS 
						  >> 8U)) 
					      | ((0xff00U 
						  & (vlTOPp->ExUnit__DOT__exRegValS 
						     << 8U)) 
						 | (0xffU 
						    & (vlTOPp->ExUnit__DOT__exRegValS 
						       >> 8U)))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (~ vlTOPp->ExUnit__DOT__exRegValS);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((0xffff0000U 
					    & (vlTOPp->ExUnit__DOT__exRegValS 
					       << 0x10U)) 
					   + vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		} else {
		    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				  >> 3U)))) {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regSPc;
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regSSr;
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSp 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regSGr;
			    } else {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__gpr__DOT__regPr;
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x20U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
					  >> 1U)))) {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
				    = ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				        ? ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (0U == 
					      (vlTOPp->ExUnit__DOT__exRegValS 
					       & vlTOPp->ExUnit__DOT__exRegValT)))
				        : ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (vlTOPp->ExUnit__DOT__exRegValS 
					      >= vlTOPp->ExUnit__DOT__exRegValT)));
			    }
			} else {
			    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
				= ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				        ? ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((vlTOPp->ExUnit__DOT__exRegValS 
						>= vlTOPp->ExUnit__DOT__exRegValT) 
					       ^ ((vlTOPp->ExUnit__DOT__exRegValS 
						   ^ vlTOPp->ExUnit__DOT__exRegValT) 
						  >> 0x1fU))))
				        : ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (vlTOPp->ExUnit__DOT__exRegValS 
					      > vlTOPp->ExUnit__DOT__exRegValT)))
				    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))
				        ? ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((vlTOPp->ExUnit__DOT__exRegValS 
						> vlTOPp->ExUnit__DOT__exRegValT) 
					       ^ ((vlTOPp->ExUnit__DOT__exRegValS 
						   ^ vlTOPp->ExUnit__DOT__exRegValT) 
						  >> 0x1fU))))
				        : ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (vlTOPp->ExUnit__DOT__exRegValS 
					      == vlTOPp->ExUnit__DOT__exRegValT))));
			}
		    } else {
			if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exUCmd) 
				      >> 2U)))) {
			    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlBraPc;
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPr 
				    = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlPrPc;
			    } else {
				vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc 
				    = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlBraPc;
			    }
			}
		    }
		}
	    } else {
		if ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (((QData)((IData)(
							    ((0x80000000U 
							      & vlTOPp->ExUnit__DOT__exRegValS)
							      ? 0xffffffffU
							      : 0U))) 
					    << 0x20U) 
					   | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= ((((0x8000U 
					      & vlTOPp->ExUnit__DOT__exRegValS)
					      ? VL_ULL(0xffffffffffff)
					      : VL_ULL(0)) 
					    << 0x10U) 
					   | (QData)((IData)(
							     (0xffffU 
							      & vlTOPp->ExUnit__DOT__exRegValS))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (QData)((IData)(
							  (0xffffU 
							   & vlTOPp->ExUnit__DOT__exRegValS)));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 1U;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValS 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS))) 
							     - 
							     (((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValT 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   - vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC) 
					       ^ (vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
						  >> 0x1fU))));
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValS 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS))) 
							     + 
							     (((QData)((IData)(
									       (1U 
										& (vlTOPp->ExUnit__DOT__exRegValT 
										>> 0x1fU)))) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValT)))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   + vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (1U & 
					      ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC) 
					       ^ (vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
						  >> 0x1fU))));
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC 
					= (1U & vlTOPp->ExUnit__DOT__gpr__DOT__regSr);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((QData)((IData)(
									     (vlTOPp->ExUnit__DOT__exRegValS 
									      - vlTOPp->ExUnit__DOT__exRegValT))) 
							     - (QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((vlTOPp->ExUnit__DOT__exRegValS 
					    - vlTOPp->ExUnit__DOT__exRegValT) 
					   - (IData)((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC));
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC 
					= (1U & vlTOPp->ExUnit__DOT__gpr__DOT__regSr);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC 
					= (1U & (IData)(
							(VL_ULL(1) 
							 & (((QData)((IData)(
									     (vlTOPp->ExUnit__DOT__exRegValS 
									      + vlTOPp->ExUnit__DOT__exRegValT))) 
							     + (QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))) 
							    >> 0x20U))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= ((vlTOPp->ExUnit__DOT__exRegValS 
					    + vlTOPp->ExUnit__DOT__exRegValT) 
					   + (IData)((QData)((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tInAluC))));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr 
					= ((0xfffffffeU 
					    & vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutSr) 
					   | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tOutAluC));
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp = 2U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt 
					= (0xffU & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   ^ vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   | vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   & vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRs 
					= (QData)((IData)(vlTOPp->ExUnit__DOT__exRegValS));
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp = 3U;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   - vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= (vlTOPp->ExUnit__DOT__exRegValS 
					   + vlTOPp->ExUnit__DOT__exRegValT);
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		} else {
		    if ((8U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 3U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(8U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 2U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(4U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 1U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(2U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad = 1U;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 0U;
				    if ((0x7eU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = ((IData)(1U) 
					       + vlTOPp->ExUnit__DOT__exRegValS);
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegS;
				    }
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 3U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(8U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(8U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 2U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(4U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(4U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 1U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(2U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(2U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tMemOpMode = 0U;
				    if ((0x7dU == (IData)(vlTOPp->ExUnit__DOT__exRegT))) {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = (vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr 
					       - (IData)(1U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					    = (vlTOPp->ExUnit__DOT__exRegValN 
					       - (IData)(1U));
					vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					    = vlTOPp->ExUnit__DOT__exRegN;
				    } else {
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemAddr 
					    = vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemData 
					    = vlTOPp->ExUnit__DOT__exRegValS;
					vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore = 1U;
				    }
				}
			    }
			}
		    } else {
			if ((4U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				} else {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exOp__DOT__tAguAddr;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			} else {
			    if ((2U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__exUCmd)))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exImm;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    } else {
				if ((1U & (IData)(vlTOPp->ExUnit__DOT__exUCmd))) {
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
					= vlTOPp->ExUnit__DOT__exRegValS;
				    vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId 
					= vlTOPp->ExUnit__DOT__exRegN;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    if ((0U != (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))) {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))) {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
		    = vlTOPp->ExUnit__DOT__gpr__DOT__regMac;
		vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
		    = (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu);
	    } else {
		vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
		    = (vlTOPp->ExUnit__DOT__gpr__DOT__regMac 
		       + vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu);
	    }
	} else {
	    vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutMac 
		= ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))
		    ? vlTOPp->ExUnit__DOT__exOp__DOT__tMacValRu
		    : vlTOPp->ExUnit__DOT__gpr__DOT__regMac);
	}
	vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutOK = 
	    (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOpB) 
	      == (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMacOp))
	      ? 1U : 2U);
    }
    if ((0U != (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
	vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal 
	    = vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn;
    }
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0 
	= (((IData)(vlTOPp->mmioOE) & (0x80U == (0xffffU 
						 & (vlTOPp->mmioAddr 
						    >> 0x10U))))
	    ? 0xffffffffU : 0U);
    // ALWAYS at ModTxtMemW.v:79
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData = 0U;
    if (((IData)(vlTOPp->mmioOE) & (0x80U == (0xffffU 
					      & (vlTOPp->mmioAddr 
						 >> 0x10U))))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx 
	    = (0x3fffU & (vlTOPp->mmioAddr >> 2U));
	if ((0xffU == (0xffU & (vlTOPp->mmioAddr >> 8U)))) {
	    if ((0U == (0x1fU & (vlTOPp->mmioAddr >> 2U)))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
		    = vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
		    [0U];
	    } else {
		if ((1U == (0x1fU & (vlTOPp->mmioAddr 
				     >> 2U)))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
			= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
			[1U];
		} else {
		    if ((2U == (0x1fU & (vlTOPp->mmioAddr 
					 >> 2U)))) {
			vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
			    = vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
			    [2U];
		    } else {
			if ((3U == (0x1fU & (vlTOPp->mmioAddr 
					     >> 2U)))) {
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
				= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
				[3U];
			} else {
			    if ((8U == (0x1fU & (vlTOPp->mmioAddr 
						 >> 2U)))) {
				vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
				    = vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx;
			    }
			}
		    }
		}
	    }
	} else {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
		= ((8U & vlTOPp->mmioAddr) ? ((4U & vlTOPp->mmioAddr)
					       ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[3U]
					       : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[2U])
		    : ((4U & vlTOPp->mmioAddr) ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U]
		        : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U]));
	}
    }
    // ALWAYS at ExShad32.v:29
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh = 0U;
    if ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
	if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp) 
		      >> 1U)))) {
	    if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp)))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
		    = ((0x80000000U & vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs)
		        ? 0xffffffffU : 0U);
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = (0xffU & VL_NEGATE_I((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt)));
	    }
	}
    } else {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = (0xffU & VL_NEGATE_I((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt)));
	    } else {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
		    = ((0x80000000U & vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs)
		        ? 0xffffffffU : 0U);
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt;
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt;
	    }
	}
    }
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn 
	= ((0x80U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
	    ? ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
	        ? ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0x80000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x1fU)) 
				   | (0x7fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 1U))) : (
						   (0xc0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x1eU)) 
						   | (0x3fffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 2U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xe0000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x1dU)) 
				   | (0x1fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 3U))) : (
						   (0xf0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x1cU)) 
						   | (0xfffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 4U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xf8000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x1bU)) 
				   | (0x7ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 5U))) : (
						   (0xfc000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x1aU)) 
						   | (0x3ffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 6U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfe000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x19U)) 
				   | (0x1ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 7U))) : (
						   (0xff000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x18U)) 
						   | (0xffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 8U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xff800000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x17U)) 
				   | (0x7fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   >> 9U)))
			        : ((0xffc00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x16U)) 
				   | (0x3fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   >> 0xaU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffe00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x15U)) 
				   | (0x1fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   >> 0xbU)))
			        : ((0xfff00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x14U)) 
				   | (0xfffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xcU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfff80000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x13U)) 
				   | (0x7ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xdU)))
			        : ((0xfffc0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x12U)) 
				   | (0x3ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xeU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffe0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x11U)) 
				   | (0x1ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xfU)))
			        : ((0xffff0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x10U)) 
				   | (0xffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x10U)))))))
	        : ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffff8000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xfU)) 
				   | (0x7fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x11U)))
			        : ((0xffffc000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xeU)) 
				   | (0x3fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x12U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffe000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xdU)) 
				   | (0x1fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x13U)))
			        : ((0xfffff000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xcU)) 
				   | (0xfffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x14U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffff800U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xbU)) 
				   | (0x7ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x15U)))
			        : ((0xfffffc00U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xaU)) 
				   | (0x3ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x16U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffe00U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 9U)) 
				   | (0x1ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x17U)))
			        : ((0xffffff00U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 8U)) 
				   | (0xffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x18U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffff80U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 7U)) 
				   | (0x7fU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x19U)))
			        : ((0xffffffc0U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 6U)) 
				   | (0x3fU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x1aU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffffe0U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 5U)) 
				   | (0x1fU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x1bU)))
			        : ((0xfffffff0U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 4U)) 
				   | (0xfU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					      >> 0x1cU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffff8U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 3U)) 
				   | (7U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					    >> 0x1dU)))
			        : ((0xfffffffcU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 2U)) 
				   | (3U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					    >> 0x1eU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffffeU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 1U)) 
				   | (1U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					    >> 0x1fU)))
			        : vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor)))))
	    : ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
	        ? ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0x80000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x1fU)) 
				   | (0x7fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 1U))) : (
						   (0xc0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x1eU)) 
						   | (0x3fffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 2U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xe0000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x1dU)) 
				   | (0x1fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 3U))) : (
						   (0xf0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x1cU)) 
						   | (0xfffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 4U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xf8000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x1bU)) 
				   | (0x7ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 5U))) : (
						   (0xfc000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x1aU)) 
						   | (0x3ffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 6U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfe000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x19U)) 
				   | (0x1ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 7U))) : (
						   (0xff000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x18U)) 
						   | (0xffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 8U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xff800000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x17U)) 
				   | (0x7fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						   >> 9U)))
			        : ((0xffc00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x16U)) 
				   | (0x3fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						   >> 0xaU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffe00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x15U)) 
				   | (0x1fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						   >> 0xbU)))
			        : ((0xfff00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x14U)) 
				   | (0xfffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xcU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfff80000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x13U)) 
				   | (0x7ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xdU)))
			        : ((0xfffc0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x12U)) 
				   | (0x3ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xeU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffe0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x11U)) 
				   | (0x1ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xfU)))
			        : ((0xffff0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x10U)) 
				   | (0xffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x10U)))))))
	        : ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffff8000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xfU)) 
				   | (0x7fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x11U)))
			        : ((0xffffc000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xeU)) 
				   | (0x3fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x12U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffe000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xdU)) 
				   | (0x1fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x13U)))
			        : ((0xfffff000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xcU)) 
				   | (0xfffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x14U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffff800U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xbU)) 
				   | (0x7ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x15U)))
			        : ((0xfffffc00U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xaU)) 
				   | (0x3ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x16U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffe00U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 9U)) 
				   | (0x1ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x17U)))
			        : ((0xffffff00U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 8U)) 
				   | (0xffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x18U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffff80U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 7U)) 
				   | (0x7fU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x19U)))
			        : ((0xffffffc0U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 6U)) 
				   | (0x3fU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x1aU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffffe0U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 5U)) 
				   | (0x1fU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x1bU)))
			        : ((0xfffffff0U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 4U)) 
				   | (0xfU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					      >> 0x1cU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffff8U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 3U)) 
				   | (7U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					    >> 0x1dU)))
			        : ((0xfffffffcU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 2U)) 
				   | (3U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					    >> 0x1eU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffffeU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 1U)) 
				   | (1U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					    >> 0x1fU)))
			        : vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs))))));
    // ALWAYS at ExUnit.v:450
    vlTOPp->ExUnit__DOT__regNextRstTok = 0x55U;
    if (vlTOPp->reset) {
	vlTOPp->ExUnit__DOT__regNextRstTok = 0U;
    }
    vlTOPp->ExUnit__DOT__tRegExHold = 0U;
    if ((1U != (IData)(vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcOK))) {
	vlTOPp->ExUnit__DOT__tRegExHold = 1U;
    }
    if (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad) 
	 | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore))) {
	if ((1U != (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK))) {
	    vlTOPp->ExUnit__DOT__tRegExHold = 1U;
	}
    }
    if ((2U == (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutOK))) {
	vlTOPp->ExUnit__DOT__tRegExHold = 1U;
    }
    vlTOPp->ExUnit__DOT__idRegValN2 = ((0x40U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
				        ? 0U : ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						 ? 
						((0x10U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						   ? 0U
						   : 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						    ? 0U
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 0U
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGbr
						      : 0U)))))
						 : 
						((0x10U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						   ? 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regSp
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8)))
						   : 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A)))))));
    vlTOPp->ExUnit__DOT__idRegValS2 = ((0x40U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
				        ? ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					    ? ((0x10U 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					        ? (
						   (8U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? 0U
						       : 0U)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? 0U
						       : vlTOPp->ExUnit__DOT__dec__DOT__opImm))
						     : 0U)
						    : 0U)
					        : (
						   (8U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? 0U
						    : 
						   ((4U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? 0U
						       : vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? vlTOPp->ExUnit__DOT__gpr__DOT__regFpul
						       : 0U))
						     : 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? vlTOPp->ExUnit__DOT__gpr__DOT__regSGr
						       : vlTOPp->ExUnit__DOT__gpr__DOT__regPr)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? (IData)(vlTOPp->ExUnit__DOT__gpr__DOT__regMac)
						       : (IData)(
								 (vlTOPp->ExUnit__DOT__gpr__DOT__regMac 
								  >> 0x20U)))))))
					    : 0U) : 
				       ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					 ? ((0x10U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					     ? 0U : 
					    ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					      ? 0U : 
					     ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					       ? ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regPc
						    : 0U)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? 0U
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regSPc))
					       : ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regSSr
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regVbr)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGbr
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regSr)))))
					 : ((0x10U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					     ? 0U : 
					    ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					      ? ((4U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regSp
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8)))
					      : ((4U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A)))))));
    vlTOPp->ExUnit__DOT__idRegValT2 = ((0x40U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
				        ? ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
					    ? ((0x10U 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
					        ? (
						   (8U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						       ? 0U
						       : 0U)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						       ? 0U
						       : vlTOPp->ExUnit__DOT__dec__DOT__opImm))
						     : 0U)
						    : 0U)
					        : 0U)
					    : 0U) : 
				       ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
					 ? 0U : ((0x10U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						   ? 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regSp
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8)))
						   : 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A)))))));
    vlTOPp->ExUnit__DOT__wbRegO = vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId;
    vlTOPp->ExUnit__DOT__wbRegValO = vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal;
    vlTOPp->ExUnit__DOT__wbRegFpValO = VL_ULL(0);
    if (((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS) 
	 == (IData)(vlTOPp->ExUnit__DOT__wbRegO))) {
	vlTOPp->ExUnit__DOT__idRegValS2 = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    if (((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT) 
	 == (IData)(vlTOPp->ExUnit__DOT__wbRegO))) {
	vlTOPp->ExUnit__DOT__idRegValT2 = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    if (((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN) 
	 == (IData)(vlTOPp->ExUnit__DOT__wbRegO))) {
	vlTOPp->ExUnit__DOT__idRegValN2 = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    vlTOPp->ExUnit__DOT__exNextPc2 = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc;
    if (VL_UNLIKELY((0x55U != (IData)(vlTOPp->ExUnit__DOT__regRstTok)))) {
	VL_WRITEF("Reset\n");
	vlTOPp->ExUnit__DOT__exNextPc2 = 0xa0000000U;
	vlTOPp->ExUnit__DOT__tRegExHold = 1U;
    }
    VL_WRITEF("IF: %x %x\n",32,vlTOPp->ExUnit__DOT__regIfPc,
	      48,vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal);
    VL_WRITEF("ID: %x %x\n",32,vlTOPp->ExUnit__DOT__regIdPc,
	      48,vlTOPp->ExUnit__DOT__regIdPcVal);
    VL_WRITEF("EX: %x %x %x Rs:R%x=%x Rt:R%x=%x Rn:R%x=%x Wb:R%x=%x\n",
	      32,vlTOPp->ExUnit__DOT__regExPc,48,vlTOPp->ExUnit__DOT__regExPcVal,
	      8,(IData)(vlTOPp->ExUnit__DOT__exUCmd),
	      7,vlTOPp->ExUnit__DOT__exRegS,32,vlTOPp->ExUnit__DOT__exRegValS,
	      7,(IData)(vlTOPp->ExUnit__DOT__exRegT),
	      32,vlTOPp->ExUnit__DOT__exRegValT,7,(IData)(vlTOPp->ExUnit__DOT__exRegN),
	      32,vlTOPp->ExUnit__DOT__exRegValN,7,(IData)(vlTOPp->ExUnit__DOT__wbRegO),
	      32,vlTOPp->ExUnit__DOT__wbRegValO);
}

VL_INLINE_OPT void VExUnit::_combo__TOP__8(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_combo__TOP__8\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0 
	= (((IData)(vlTOPp->mmioOE) & (0x80U == (0xffffU 
						 & (vlTOPp->mmioAddr 
						    >> 0x10U))))
	    ? 0xffffffffU : 0U);
    // ALWAYS at ModTxtMemW.v:79
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx 
	= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx;
    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData = 0U;
    if (((IData)(vlTOPp->mmioOE) & (0x80U == (0xffffU 
					      & (vlTOPp->mmioAddr 
						 >> 0x10U))))) {
	vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx 
	    = (0x3fffU & (vlTOPp->mmioAddr >> 2U));
	if ((0xffU == (0xffU & (vlTOPp->mmioAddr >> 8U)))) {
	    if ((0U == (0x1fU & (vlTOPp->mmioAddr >> 2U)))) {
		vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
		    = vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
		    [0U];
	    } else {
		if ((1U == (0x1fU & (vlTOPp->mmioAddr 
				     >> 2U)))) {
		    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
			= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
			[1U];
		} else {
		    if ((2U == (0x1fU & (vlTOPp->mmioAddr 
					 >> 2U)))) {
			vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
			    = vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
			    [2U];
		    } else {
			if ((3U == (0x1fU & (vlTOPp->mmioAddr 
					     >> 2U)))) {
			    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
				= vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl
				[3U];
			} else {
			    if ((8U == (0x1fU & (vlTOPp->mmioAddr 
						 >> 2U)))) {
				vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
				    = vlTOPp->ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx;
			    }
			}
		    }
		}
	    }
	} else {
	    vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData 
		= ((8U & vlTOPp->mmioAddr) ? ((4U & vlTOPp->mmioAddr)
					       ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[3U]
					       : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[2U])
		    : ((4U & vlTOPp->mmioAddr) ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[1U]
		        : vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1[0U]));
	}
    }
    // ALWAYS at ExShad32.v:29
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = 0U;
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh = 0U;
    if ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
	if ((1U & (~ ((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp) 
		      >> 1U)))) {
	    if ((1U & (~ (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp)))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
		    = ((0x80000000U & vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs)
		        ? 0xffffffffU : 0U);
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = (0xffU & VL_NEGATE_I((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt)));
	    }
	}
    } else {
	if ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = (0xffU & VL_NEGATE_I((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt)));
	    } else {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
		    = ((0x80000000U & vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs)
		        ? 0xffffffffU : 0U);
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt;
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tShadOp))) {
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = 0U;
		vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh 
		    = vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRt;
	    }
	}
    }
    vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn 
	= ((0x80U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
	    ? ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
	        ? ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0x80000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x1fU)) 
				   | (0x7fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 1U))) : (
						   (0xc0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x1eU)) 
						   | (0x3fffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 2U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xe0000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x1dU)) 
				   | (0x1fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 3U))) : (
						   (0xf0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x1cU)) 
						   | (0xfffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 4U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xf8000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x1bU)) 
				   | (0x7ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 5U))) : (
						   (0xfc000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x1aU)) 
						   | (0x3ffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 6U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfe000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x19U)) 
				   | (0x1ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
				       >> 7U))) : (
						   (0xff000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						       << 0x18U)) 
						   | (0xffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
							 >> 8U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xff800000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x17U)) 
				   | (0x7fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   >> 9U)))
			        : ((0xffc00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x16U)) 
				   | (0x3fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   >> 0xaU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffe00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x15U)) 
				   | (0x1fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   >> 0xbU)))
			        : ((0xfff00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x14U)) 
				   | (0xfffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xcU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfff80000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x13U)) 
				   | (0x7ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xdU)))
			        : ((0xfffc0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x12U)) 
				   | (0x3ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xeU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffe0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x11U)) 
				   | (0x1ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						  >> 0xfU)))
			        : ((0xffff0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0x10U)) 
				   | (0xffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x10U)))))))
	        : ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffff8000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xfU)) 
				   | (0x7fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x11U)))
			        : ((0xffffc000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xeU)) 
				   | (0x3fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x12U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffe000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xdU)) 
				   | (0x1fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						 >> 0x13U)))
			        : ((0xfffff000U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xcU)) 
				   | (0xfffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x14U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffff800U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xbU)) 
				   | (0x7ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x15U)))
			        : ((0xfffffc00U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 0xaU)) 
				   | (0x3ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x16U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffe00U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 9U)) 
				   | (0x1ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						>> 0x17U)))
			        : ((0xffffff00U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 8U)) 
				   | (0xffU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x18U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffff80U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 7U)) 
				   | (0x7fU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x19U)))
			        : ((0xffffffc0U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 6U)) 
				   | (0x3fU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x1aU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffffe0U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 5U)) 
				   | (0x1fU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					       >> 0x1bU)))
			        : ((0xfffffff0U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 4U)) 
				   | (0xfU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					      >> 0x1cU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffff8U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 3U)) 
				   | (7U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					    >> 0x1dU)))
			        : ((0xfffffffcU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 2U)) 
				   | (3U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					    >> 0x1eU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffffeU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor 
						   << 1U)) 
				   | (1U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
					    >> 0x1fU)))
			        : vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor)))))
	    : ((0x10U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
	        ? ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0x80000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x1fU)) 
				   | (0x7fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 1U))) : (
						   (0xc0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x1eU)) 
						   | (0x3fffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 2U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xe0000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x1dU)) 
				   | (0x1fffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 3U))) : (
						   (0xf0000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x1cU)) 
						   | (0xfffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 4U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xf8000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x1bU)) 
				   | (0x7ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 5U))) : (
						   (0xfc000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x1aU)) 
						   | (0x3ffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 6U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfe000000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x19U)) 
				   | (0x1ffffffU & 
				      (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
				       >> 7U))) : (
						   (0xff000000U 
						    & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						       << 0x18U)) 
						   | (0xffffffU 
						      & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
							 >> 8U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xff800000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x17U)) 
				   | (0x7fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						   >> 9U)))
			        : ((0xffc00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x16U)) 
				   | (0x3fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						   >> 0xaU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffe00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x15U)) 
				   | (0x1fffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						   >> 0xbU)))
			        : ((0xfff00000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x14U)) 
				   | (0xfffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xcU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfff80000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x13U)) 
				   | (0x7ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xdU)))
			        : ((0xfffc0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x12U)) 
				   | (0x3ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xeU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffe0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x11U)) 
				   | (0x1ffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						  >> 0xfU)))
			        : ((0xffff0000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0x10U)) 
				   | (0xffffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x10U)))))))
	        : ((8U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		    ? ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffff8000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xfU)) 
				   | (0x7fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x11U)))
			        : ((0xffffc000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xeU)) 
				   | (0x3fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x12U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffe000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xdU)) 
				   | (0x1fffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						 >> 0x13U)))
			        : ((0xfffff000U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xcU)) 
				   | (0xfffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x14U)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffff800U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xbU)) 
				   | (0x7ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x15U)))
			        : ((0xfffffc00U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 0xaU)) 
				   | (0x3ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x16U))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffe00U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 9U)) 
				   | (0x1ffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
						>> 0x17U)))
			        : ((0xffffff00U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 8U)) 
				   | (0xffU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x18U))))))
		    : ((4U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
		        ? ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffff80U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 7U)) 
				   | (0x7fU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x19U)))
			        : ((0xffffffc0U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 6U)) 
				   | (0x3fU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x1aU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xffffffe0U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 5U)) 
				   | (0x1fU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					       >> 0x1bU)))
			        : ((0xfffffff0U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 4U)) 
				   | (0xfU & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					      >> 0x1cU)))))
		        : ((2U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			    ? ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffff8U & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 3U)) 
				   | (7U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					    >> 0x1dU)))
			        : ((0xfffffffcU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 2U)) 
				   | (3U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					    >> 0x1eU))))
			    : ((1U & (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh))
			        ? ((0xfffffffeU & (vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs 
						   << 1U)) 
				   | (1U & (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol 
					    >> 0x1fU)))
			        : vlTOPp->ExUnit__DOT__exOp__DOT__tShadValRs))))));
    // ALWAYS at ExUnit.v:450
    vlTOPp->ExUnit__DOT__regNextRstTok = 0x55U;
    if (vlTOPp->reset) {
	vlTOPp->ExUnit__DOT__regNextRstTok = 0U;
    }
    vlTOPp->ExUnit__DOT__tRegExHold = 0U;
    if ((1U != (IData)(vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcOK))) {
	vlTOPp->ExUnit__DOT__tRegExHold = 1U;
    }
    if (((IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemLoad) 
	 | (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tMemStore))) {
	if ((1U != (IData)(vlTOPp->ExUnit__DOT__dcf__DOT__tRegOutOK))) {
	    vlTOPp->ExUnit__DOT__tRegExHold = 1U;
	}
    }
    if ((2U == (IData)(vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutOK))) {
	vlTOPp->ExUnit__DOT__tRegExHold = 1U;
    }
    vlTOPp->ExUnit__DOT__idRegValN2 = ((0x40U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
				        ? 0U : ((0x20U 
						 & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						 ? 
						((0x10U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						   ? 0U
						   : 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						    ? 0U
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 0U
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGbr
						      : 0U)))))
						 : 
						((0x10U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						   ? 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regSp
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8)))
						   : 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A)))))));
    vlTOPp->ExUnit__DOT__idRegValS2 = ((0x40U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
				        ? ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					    ? ((0x10U 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					        ? (
						   (8U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? 0U
						       : 0U)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? 0U
						       : vlTOPp->ExUnit__DOT__dec__DOT__opImm))
						     : 0U)
						    : 0U)
					        : (
						   (8U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? 0U
						    : 
						   ((4U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? 0U
						       : vlTOPp->ExUnit__DOT__gpr__DOT__regFpScr)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? vlTOPp->ExUnit__DOT__gpr__DOT__regFpul
						       : 0U))
						     : 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? vlTOPp->ExUnit__DOT__gpr__DOT__regSGr
						       : vlTOPp->ExUnit__DOT__gpr__DOT__regPr)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						       ? (IData)(vlTOPp->ExUnit__DOT__gpr__DOT__regMac)
						       : (IData)(
								 (vlTOPp->ExUnit__DOT__gpr__DOT__regMac 
								  >> 0x20U)))))))
					    : 0U) : 
				       ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					 ? ((0x10U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					     ? 0U : 
					    ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					      ? 0U : 
					     ((4U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					       ? ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regPc
						    : 0U)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? 0U
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regSPc))
					       : ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regSSr
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regVbr)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGbr
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regSr)))))
					 : ((0x10U 
					     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					     ? 0U : 
					    ((8U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
					      ? ((4U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regSp
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8)))
					      : ((4U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						  ? 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A))
						  : 
						 ((2U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						   ? 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A)
						   : 
						  ((1U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS))
						    ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A
						    : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A)))))));
    vlTOPp->ExUnit__DOT__idRegValT2 = ((0x40U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
				        ? ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
					    ? ((0x10U 
						& (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
					        ? (
						   (8U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						    ? 
						   ((4U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						       ? 0U
						       : 0U)
						      : 
						     ((1U 
						       & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						       ? 0U
						       : vlTOPp->ExUnit__DOT__dec__DOT__opImm))
						     : 0U)
						    : 0U)
					        : 0U)
					    : 0U) : 
				       ((0x20U & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
					 ? 0U : ((0x10U 
						  & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						  ? 0U
						  : 
						 ((8U 
						   & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						   ? 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regSp
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR14)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR13
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR12))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR11
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR10)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR9
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR8)))
						   : 
						  ((4U 
						    & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						    ? 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR7A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR6A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR5A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR4A))
						    : 
						   ((2U 
						     & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						     ? 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR3A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR2A)
						     : 
						    ((1U 
						      & (IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT))
						      ? vlTOPp->ExUnit__DOT__gpr__DOT__regGprR1A
						      : vlTOPp->ExUnit__DOT__gpr__DOT__regGprR0A)))))));
    vlTOPp->ExUnit__DOT__wbRegO = vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutId;
    vlTOPp->ExUnit__DOT__wbRegValO = vlTOPp->ExUnit__DOT__exOp__DOT__tRegOutVal;
    vlTOPp->ExUnit__DOT__wbRegFpValO = VL_ULL(0);
    if (((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegS) 
	 == (IData)(vlTOPp->ExUnit__DOT__wbRegO))) {
	vlTOPp->ExUnit__DOT__idRegValS2 = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    if (((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegT) 
	 == (IData)(vlTOPp->ExUnit__DOT__wbRegO))) {
	vlTOPp->ExUnit__DOT__idRegValT2 = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    if (((IData)(vlTOPp->ExUnit__DOT__dec__DOT__opRegN) 
	 == (IData)(vlTOPp->ExUnit__DOT__wbRegO))) {
	vlTOPp->ExUnit__DOT__idRegValN2 = vlTOPp->ExUnit__DOT__wbRegValO;
    }
    vlTOPp->ExUnit__DOT__exNextPc2 = vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc;
    if (VL_UNLIKELY((0x55U != (IData)(vlTOPp->ExUnit__DOT__regRstTok)))) {
	VL_WRITEF("Reset\n");
	vlTOPp->ExUnit__DOT__exNextPc2 = 0xa0000000U;
	vlTOPp->ExUnit__DOT__tRegExHold = 1U;
    }
    VL_WRITEF("IF: %x %x\n",32,vlTOPp->ExUnit__DOT__regIfPc,
	      48,vlTOPp->ExUnit__DOT__icf__DOT__tRegOutPcVal);
    VL_WRITEF("ID: %x %x\n",32,vlTOPp->ExUnit__DOT__regIdPc,
	      48,vlTOPp->ExUnit__DOT__regIdPcVal);
    VL_WRITEF("EX: %x %x %x Rs:R%x=%x Rt:R%x=%x Rn:R%x=%x Wb:R%x=%x\n",
	      32,vlTOPp->ExUnit__DOT__regExPc,48,vlTOPp->ExUnit__DOT__regExPcVal,
	      8,(IData)(vlTOPp->ExUnit__DOT__exUCmd),
	      7,vlTOPp->ExUnit__DOT__exRegS,32,vlTOPp->ExUnit__DOT__exRegValS,
	      7,(IData)(vlTOPp->ExUnit__DOT__exRegT),
	      32,vlTOPp->ExUnit__DOT__exRegValT,7,(IData)(vlTOPp->ExUnit__DOT__exRegN),
	      32,vlTOPp->ExUnit__DOT__exRegValN,7,(IData)(vlTOPp->ExUnit__DOT__wbRegO),
	      32,vlTOPp->ExUnit__DOT__wbRegValO);
    vlTOPp->mmioData = ((((((((IData)(vlTOPp->mmioOE) 
			      & (0x80U == (0xffffU 
					   & (vlTOPp->mmioAddr 
					      >> 0x10U))))
			      ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData
			      : 0U) & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0) 
			   & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0) 
			  & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0) 
			 | (((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR)
			      ? vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOutData
			      : 0U) & ((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR)
				        ? 0xffffffffU
				        : 0U))) & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0 
						   | ((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR)
						       ? 0xffffffffU
						       : 0U)));
}

void VExUnit::_settle__TOP__9(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_settle__TOP__9\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mmioData = ((((((((IData)(vlTOPp->mmioOE) 
			      & (0x80U == (0xffffU 
					   & (vlTOPp->mmioAddr 
					      >> 0x10U))))
			      ? vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData
			      : 0U) & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0) 
			   & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0) 
			  & vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0) 
			 | (((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR)
			      ? vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioOutData
			      : 0U) & ((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR)
				        ? 0xffffffffU
				        : 0U))) & (vlTOPp->ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0 
						   | ((IData)(vlTOPp->ExUnit__DOT__dcl2__DOT__tMmioWR)
						       ? 0xffffffffU
						       : 0U)));
}

void VExUnit::_eval(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_eval\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->_combo__TOP__8(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VExUnit::_eval_initial(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_eval_initial\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void VExUnit::final() {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::final\n"); );
    // Variables
    VExUnit__Syms* __restrict vlSymsp = this->__VlSymsp;
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VExUnit::_eval_settle(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_eval_settle\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
    vlTOPp->_settle__TOP__9(vlSymsp);
}

VL_INLINE_OPT QData VExUnit::_change_request(VExUnit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_change_request\n"); );
    VExUnit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc ^ vlTOPp->__Vchglast__TOP__ExUnit__DOT__exOp__DOT__tCtlOutPc)
	 | (vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn ^ vlTOPp->__Vchglast__TOP__ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn));
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc ^ vlTOPp->__Vchglast__TOP__ExUnit__DOT__exOp__DOT__tCtlOutPc))) VL_PRINTF("	CHANGE: ExOp2.v:133: ExUnit.exOp.tCtlOutPc\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn ^ vlTOPp->__Vchglast__TOP__ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn))) VL_PRINTF("	CHANGE: ExShad32.v:21: ExUnit.exOp.sh32.tValRn\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__ExUnit__DOT__exOp__DOT__tCtlOutPc 
	= vlTOPp->ExUnit__DOT__exOp__DOT__tCtlOutPc;
    vlTOPp->__Vchglast__TOP__ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn 
	= vlTOPp->ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn;
    return __req;
}

void VExUnit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    extAddr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128,extData);
    extOE = VL_RAND_RESET_I(1);
    extWR = VL_RAND_RESET_I(1);
    extOK = VL_RAND_RESET_I(1);
    mmioAddr = VL_RAND_RESET_I(32);
    mmioData = VL_RAND_RESET_I(32);
    mmioOE = VL_RAND_RESET_I(1);
    mmioWR = VL_RAND_RESET_I(1);
    mmioOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__regRstTok = VL_RAND_RESET_I(8);
    ExUnit__DOT__regNextRstTok = VL_RAND_RESET_I(8);
    ExUnit__DOT__dc2RegInAddr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128,ExUnit__DOT__dc2RegInData);
    ExUnit__DOT__dc2RegInOE = VL_RAND_RESET_I(1);
    ExUnit__DOT__dc2RegInWR = VL_RAND_RESET_I(1);
    ExUnit__DOT__dc2RegInOp = VL_RAND_RESET_I(5);
    ExUnit__DOT__dcfRegInAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcfRegInData = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcfRegInOE = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcfRegInWR = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcfRegInOp = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(128,ExUnit__DOT__dcfMemInData);
    ExUnit__DOT__dcfMemPcAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcfMemPcOE = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcfMemPcOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__regIfPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__regIfSr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128,ExUnit__DOT__memIfPcData);
    ExUnit__DOT__memIfPcOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__regIfPcVal2 = VL_RAND_RESET_Q(48);
    ExUnit__DOT__regIdPcVal = VL_RAND_RESET_Q(48);
    ExUnit__DOT__regIdCsFl = VL_RAND_RESET_I(16);
    ExUnit__DOT__regIdPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__regIdSr = VL_RAND_RESET_I(32);
    ExUnit__DOT__idWbRegO = VL_RAND_RESET_I(7);
    ExUnit__DOT__idWbRegValO = VL_RAND_RESET_I(32);
    ExUnit__DOT__wbRegO = VL_RAND_RESET_I(7);
    ExUnit__DOT__wbRegValO = VL_RAND_RESET_I(32);
    ExUnit__DOT__wbRegFpValO = VL_RAND_RESET_Q(64);
    ExUnit__DOT__idUCmd2 = VL_RAND_RESET_I(8);
    ExUnit__DOT__idRegValN2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__idRegValS2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__idRegValT2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__regExPcVal = VL_RAND_RESET_Q(48);
    ExUnit__DOT__regExPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exRegN = VL_RAND_RESET_I(7);
    ExUnit__DOT__exRegS = VL_RAND_RESET_I(7);
    ExUnit__DOT__exRegT = VL_RAND_RESET_I(7);
    ExUnit__DOT__exImm = VL_RAND_RESET_I(32);
    ExUnit__DOT__exStepPc = VL_RAND_RESET_I(4);
    ExUnit__DOT__exStepPc2 = VL_RAND_RESET_I(4);
    ExUnit__DOT__exUCmd = VL_RAND_RESET_I(8);
    ExUnit__DOT__exRegValN = VL_RAND_RESET_I(32);
    ExUnit__DOT__exRegValS = VL_RAND_RESET_I(32);
    ExUnit__DOT__exRegValT = VL_RAND_RESET_I(32);
    ExUnit__DOT__exNextPc2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__exNextFpul2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__exNextFpScr2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__tRegGenIdPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__tRegGenIdStepPc = VL_RAND_RESET_I(4);
    ExUnit__DOT__tRegExHold = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[__Vi0] = VL_RAND_RESET_I(8);
    }}
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmOut = VL_RAND_RESET_I(4);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmCarry = VL_RAND_RESET_I(1);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8 = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextSt8 = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc = VL_RAND_RESET_I(22);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc = VL_RAND_RESET_I(22);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk = VL_RAND_RESET_I(13);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk = VL_RAND_RESET_I(13);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk = VL_RAND_RESET_I(11);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk = VL_RAND_RESET_I(11);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk = VL_RAND_RESET_I(3);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk = VL_RAND_RESET_I(3);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk = VL_RAND_RESET_I(3);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk = VL_RAND_RESET_I(3);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt = VL_RAND_RESET_I(2);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt = VL_RAND_RESET_I(2);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCb = VL_RAND_RESET_I(5);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCu = VL_RAND_RESET_I(5);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCv = VL_RAND_RESET_I(5);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCu = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCv = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCy = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCu = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCv = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy = VL_RAND_RESET_I(18);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCu = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCv = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCt = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosX = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosY = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCy = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCu = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCv = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData = VL_RAND_RESET_I(32);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx = VL_RAND_RESET_I(14);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx = VL_RAND_RESET_I(14);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontMem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx1Mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx2Mem[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl[__Vi0] = VL_RAND_RESET_I(32);
    }}
    VL_RAND_RESET_W(128,ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData1 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData2 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx1 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx2 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0 = VL_RAND_RESET_I(32);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY = VL_RAND_RESET_I(10);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX = VL_RAND_RESET_I(14);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY = VL_RAND_RESET_I(14);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx = VL_RAND_RESET_I(14);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextIx = VL_RAND_RESET_I(14);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx = VL_RAND_RESET_I(4);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx = VL_RAND_RESET_I(6);
    VL_RAND_RESET_W(128,ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData = VL_RAND_RESET_Q(64);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphU = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphV = VL_RAND_RESET_I(16);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA = VL_RAND_RESET_I(6);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB = VL_RAND_RESET_I(6);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A = VL_RAND_RESET_I(9);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B = VL_RAND_RESET_I(9);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA = VL_RAND_RESET_I(12);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB = VL_RAND_RESET_I(12);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA = VL_RAND_RESET_I(12);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB = VL_RAND_RESET_I(12);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC = VL_RAND_RESET_I(12);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu = VL_RAND_RESET_I(8);
    ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv = VL_RAND_RESET_I(8);
    ExUnit__DOT__dcl2__DOT__tMmioOutData = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcl2__DOT__tMmioAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcl2__DOT__tMmioOE = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcl2__DOT__tMmioWR = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    ExUnit__DOT__dcl2__DOT__memTileA[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    ExUnit__DOT__dcl2__DOT__memTileB[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    ExUnit__DOT__dcl2__DOT__memTileC[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    ExUnit__DOT__dcl2__DOT__memTileD[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    VL_RAND_RESET_W(128,ExUnit__DOT__dcl2__DOT__romTile[__Vi0]);
    }}
    VL_RAND_RESET_W(128,ExUnit__DOT__dcl2__DOT__tRamTile);
    ExUnit__DOT__dcl2__DOT__tAccTileIx = VL_RAND_RESET_I(11);
    VL_RAND_RESET_W(128,ExUnit__DOT__dcl2__DOT__tMemTile);
    VL_RAND_RESET_W(128,ExUnit__DOT__dcl2__DOT__tOutData);
    VL_RAND_RESET_W(128,ExUnit__DOT__dcl2__DOT__tNextTile);
    ExUnit__DOT__dcl2__DOT__tRegTileIx = VL_RAND_RESET_I(11);
    ExUnit__DOT__dcl2__DOT__tNextTileIx = VL_RAND_RESET_I(11);
    ExUnit__DOT__dcl2__DOT__tNextTileSt = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcl2__DOT__tRegOutOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__dcl2__DOT__addrIsRam = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkA[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkB[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkC[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkD[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkE[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkAd[__Vi0] = VL_RAND_RESET_I(28);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__dcf__DOT__icBlkFl[__Vi0] = VL_RAND_RESET_I(4);
    }}
    ExUnit__DOT__dcf__DOT__tRegInPc1 = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcf__DOT__tRegInPc2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcf__DOT__tBlkNeedAd1 = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__tBlkNeedAd2 = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__tBlkNeedAd3 = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__tBlkNeedAd4 = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__tBlkData2 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcf__DOT__tBlkData2B = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcf__DOT__tBlkData3 = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcf__DOT__tRegOutData = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcf__DOT__tRegOutOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__dcf__DOT__tRdZx = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__tRegInData = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcf__DOT__tMemPcAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__dcf__DOT__tMemPcOE = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__tMemPcWR = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128,ExUnit__DOT__dcf__DOT__tMemOutData);
    ExUnit__DOT__dcf__DOT__tMemPcOp = VL_RAND_RESET_I(5);
    ExUnit__DOT__dcf__DOT__reqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__nReqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__tRegOutDataB = VL_RAND_RESET_Q(64);
    ExUnit__DOT__dcf__DOT__isReqTileSt = VL_RAND_RESET_I(4);
    ExUnit__DOT__dcf__DOT__isReqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__nxtReqTileSt = VL_RAND_RESET_I(4);
    ExUnit__DOT__dcf__DOT__nxtReqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__nxtReqCommit = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__nxtReqCommitAd1 = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__nxtReqCommitAd2 = VL_RAND_RESET_I(28);
    ExUnit__DOT__dcf__DOT__nxtReqCommitFl = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(160,ExUnit__DOT__dcf__DOT__reqTempBlk);
    VL_RAND_RESET_W(160,ExUnit__DOT__dcf__DOT__nxtReqTempBlk);
    VL_RAND_RESET_W(160,ExUnit__DOT__dcf__DOT__accTempBlk);
    ExUnit__DOT__dcf__DOT__accHit = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__accNoCache = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__nxtAccHit = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__accCommitOK = VL_RAND_RESET_I(1);
    ExUnit__DOT__dcf__DOT__nxtAccCommitOK = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__icf__DOT__icBlkA[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__icf__DOT__icBlkB[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__icf__DOT__icBlkC[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__icf__DOT__icBlkD[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__icf__DOT__icBlkE[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
	    ExUnit__DOT__icf__DOT__icBlkAd[__Vi0] = VL_RAND_RESET_I(28);
    }}
    ExUnit__DOT__icf__DOT__tRegInPc1 = VL_RAND_RESET_I(32);
    ExUnit__DOT__icf__DOT__tRegInPc2 = VL_RAND_RESET_I(32);
    ExUnit__DOT__icf__DOT__tBlkNeedAd1 = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__tBlkNeedAd2 = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__tRegOutPcVal = VL_RAND_RESET_Q(48);
    ExUnit__DOT__icf__DOT__tRegOutPcOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__icf__DOT__tMemPcAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__icf__DOT__tMemPcOE = VL_RAND_RESET_I(1);
    ExUnit__DOT__icf__DOT__reqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__nReqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__isReqTileSt = VL_RAND_RESET_I(3);
    ExUnit__DOT__icf__DOT__isReqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__nxtReqTileSt = VL_RAND_RESET_I(3);
    ExUnit__DOT__icf__DOT__nxtReqNeedAd = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__doReqNeedAd = VL_RAND_RESET_I(1);
    ExUnit__DOT__icf__DOT__nxtDoReqNeedAd = VL_RAND_RESET_I(1);
    ExUnit__DOT__icf__DOT__nxtReqCommit = VL_RAND_RESET_I(1);
    ExUnit__DOT__icf__DOT__nxtReqCommitAd1 = VL_RAND_RESET_I(28);
    ExUnit__DOT__icf__DOT__nxtReqCommitAd2 = VL_RAND_RESET_I(28);
    VL_RAND_RESET_W(160,ExUnit__DOT__icf__DOT__reqTempBlk);
    VL_RAND_RESET_W(160,ExUnit__DOT__icf__DOT__nxtReqTempBlk);
    VL_RAND_RESET_W(160,ExUnit__DOT__icf__DOT__accTempBlk);
    ExUnit__DOT__dec__DOT__isOpXE = VL_RAND_RESET_I(1);
    ExUnit__DOT__dec__DOT__opPsDQ = VL_RAND_RESET_I(1);
    ExUnit__DOT__dec__DOT__opPwDQ = VL_RAND_RESET_I(1);
    ExUnit__DOT__dec__DOT__opPlDQ = VL_RAND_RESET_I(1);
    ExUnit__DOT__dec__DOT__opJQ = VL_RAND_RESET_I(1);
    ExUnit__DOT__dec__DOT__opCmdWord = VL_RAND_RESET_I(16);
    ExUnit__DOT__dec__DOT__opRegN = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegS = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegT = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opImm = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__opUCmd = VL_RAND_RESET_I(8);
    ExUnit__DOT__dec__DOT__opStepPc = VL_RAND_RESET_I(4);
    ExUnit__DOT__dec__DOT__opStepPc2 = VL_RAND_RESET_I(4);
    ExUnit__DOT__dec__DOT__opStepPc2A = VL_RAND_RESET_I(4);
    ExUnit__DOT__dec__DOT__opStepPc2B = VL_RAND_RESET_I(4);
    ExUnit__DOT__dec__DOT__tOpDecXfrm = VL_RAND_RESET_I(5);
    ExUnit__DOT__dec__DOT__tOpDecXfrmZx = VL_RAND_RESET_I(3);
    ExUnit__DOT__dec__DOT__opRegN_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegM_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegM_CR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegM_SR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegN_FR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegM_FR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opRegN_N3 = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__opImm_Zx4 = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__opImm_Zx8 = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__opImm_Sx8 = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__opImm_Sx12 = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegN = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegS = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegT = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd = VL_RAND_RESET_I(8);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegO_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_Dfl = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_FR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_FR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_FR = VL_RAND_RESET_I(7);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Zx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Nx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm20_Sx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImmM12_Sx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opImm4_ZxXE = VL_RAND_RESET_I(32);
    ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord = VL_RAND_RESET_I(16);
    ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord = VL_RAND_RESET_I(16);
    ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm = VL_RAND_RESET_I(5);
    ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx = VL_RAND_RESET_I(3);
    ExUnit__DOT__gpr__DOT__regMac = VL_RAND_RESET_Q(64);
    ExUnit__DOT__gpr__DOT__regPr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regSGr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regFpul = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regFpScr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regSr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGbr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regVbr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regSSr = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regSPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regSp = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regSrRB = VL_RAND_RESET_I(1);
    ExUnit__DOT__gpr__DOT__regGprR0A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR1A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR2A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR3A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR4A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR5A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR6A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR7A = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR0B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR1B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR2B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR3B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR4B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR5B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR6B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR7B = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR8 = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR9 = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR10 = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR11 = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR12 = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR13 = VL_RAND_RESET_I(32);
    ExUnit__DOT__gpr__DOT__regGprR14 = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tRegOutVal = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tRegOutId = VL_RAND_RESET_I(7);
    ExUnit__DOT__exOp__DOT__tRegOutOK = VL_RAND_RESET_I(2);
    ExUnit__DOT__exOp__DOT__tMemAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tMemData = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tMemLoad = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tMemStore = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tMemOpMode = VL_RAND_RESET_I(5);
    ExUnit__DOT__exOp__DOT__tAguRtRi = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tAguRtRiSc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tAguAddr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutSr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutPr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutMac = VL_RAND_RESET_Q(64);
    ExUnit__DOT__exOp__DOT__tCtlOutSp = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlNxtPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlBraPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlPrPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutGbr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutVbr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutSSr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutSPc = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tCtlOutSGr = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tInAluC = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tOutAluC = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tMacOp = VL_RAND_RESET_I(2);
    ExUnit__DOT__exOp__DOT__tMacValRs = VL_RAND_RESET_Q(64);
    ExUnit__DOT__exOp__DOT__tMacValRu = VL_RAND_RESET_Q(64);
    ExUnit__DOT__exOp__DOT__tMacOpB = VL_RAND_RESET_I(2);
    ExUnit__DOT__exOp__DOT__tShadValRs = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tShadValRt = VL_RAND_RESET_I(8);
    ExUnit__DOT__exOp__DOT__tShadOp = VL_RAND_RESET_I(3);
    ExUnit__DOT__exOp__DOT__tAluDn1 = VL_RAND_RESET_Q(33);
    ExUnit__DOT__exOp__DOT__tAluDn2 = VL_RAND_RESET_Q(33);
    ExUnit__DOT__exOp__DOT__tAluQ0 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tAluM0 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tAluT0 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tAluQ1 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tAluM1 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tAluQ2 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tAluT2 = VL_RAND_RESET_I(1);
    ExUnit__DOT__exOp__DOT__tMacValRsA = VL_RAND_RESET_Q(64);
    ExUnit__DOT__exOp__DOT__tMacOpA0 = VL_RAND_RESET_I(2);
    ExUnit__DOT__exOp__DOT__tMacValRuB_AA = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tMacValRuB_AB = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tMacValRuB_BA = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tMacValRuB_BB = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__tMacOpB0 = VL_RAND_RESET_I(2);
    ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor = VL_RAND_RESET_I(32);
    ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh = VL_RAND_RESET_I(8);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vchglast__TOP__ExUnit__DOT__exOp__DOT__tCtlOutPc = VL_RAND_RESET_I(32);
    __Vchglast__TOP__ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn = VL_RAND_RESET_I(32);
}

void VExUnit::_configure_coverage(VExUnit__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VExUnit::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
