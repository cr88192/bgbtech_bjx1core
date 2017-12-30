// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBltDspMod.h for the primary calling header

#include "VBltDspMod.h"        // For This
#include "VBltDspMod__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VBltDspMod) {
    VBltDspMod__Syms* __restrict vlSymsp = __VlSymsp = new VBltDspMod__Syms(this, name());
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VBltDspMod::__Vconfigure(VBltDspMod__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VBltDspMod::~VBltDspMod() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VBltDspMod::eval() {
    VBltDspMod__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VBltDspMod::eval\n"); );
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

void VBltDspMod::_eval_initial_loop(VBltDspMod__Syms* __restrict vlSymsp) {
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

void VBltDspMod::_settle__TOP__1(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_settle__TOP__1\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->busHold = 0U;
}

void VBltDspMod::_initial__TOP__2(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_initial__TOP__2\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at BltDspMod.v:40
    vlTOPp->busData = 0U;
}

VL_INLINE_OPT void VBltDspMod::_sequent__TOP__3(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_sequent__TOP__3\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at BltDspMod.v:511
    vlTOPp->BltDspMod__DOT__curTick10MHz = vlTOPp->BltDspMod__DOT__nextTick10MHz;
    // ALWAYS at BltDspMod.v:516
    vlTOPp->BltDspMod__DOT__curCnt10MHz = vlTOPp->BltDspMod__DOT__nextCnt10MHz;
    // ALWAYS at BltDspMod.v:523
    vlTOPp->BltDspMod__DOT__curPwmStateL = vlTOPp->BltDspMod__DOT__nextPwmStateL;
    // ALWAYS at BltDspMod.v:524
    vlTOPp->BltDspMod__DOT__curPwmStateR = vlTOPp->BltDspMod__DOT__nextPwmStateR;
    // ALWAYS at BltDspMod.v:527
    vlTOPp->BltDspMod__DOT__curPwmCarryL = vlTOPp->BltDspMod__DOT__nextPwmCarryL;
    // ALWAYS at BltDspMod.v:528
    vlTOPp->BltDspMod__DOT__curPwmCarryR = vlTOPp->BltDspMod__DOT__nextPwmCarryR;
    // ALWAYS at BltDspMod.v:521
    vlTOPp->BltDspMod__DOT__curPwmOut = vlTOPp->BltDspMod__DOT__nextPwmOut;
    // ALWAYS at BltDspMod.v:509
    vlTOPp->BltDspMod__DOT__oBusIrqLive = vlTOPp->BltDspMod__DOT__oNextBusIrqLive;
    // ALWAYS at BltDspMod.v:530
    vlTOPp->BltDspMod__DOT__curDspBlockA0 = vlTOPp->BltDspMod__DOT__nextDspBlockA0;
    // ALWAYS at BltDspMod.v:531
    vlTOPp->BltDspMod__DOT__curDspBlockB0 = vlTOPp->BltDspMod__DOT__nextDspBlockB0;
    // ALWAYS at BltDspMod.v:532
    vlTOPp->BltDspMod__DOT__curDspBlockC0 = vlTOPp->BltDspMod__DOT__nextDspBlockC0;
    // ALWAYS at BltDspMod.v:533
    vlTOPp->BltDspMod__DOT__curDspBlockD0 = vlTOPp->BltDspMod__DOT__nextDspBlockD0;
    // ALWAYS at BltDspMod.v:512
    vlTOPp->BltDspMod__DOT__curTick1MHz = vlTOPp->BltDspMod__DOT__nextTick1MHz;
    // ALWAYS at BltDspMod.v:513
    vlTOPp->BltDspMod__DOT__curTick32kHz = vlTOPp->BltDspMod__DOT__nextTick32kHz;
    // ALWAYS at BltDspMod.v:514
    vlTOPp->BltDspMod__DOT__curTick1kHz = vlTOPp->BltDspMod__DOT__nextTick1kHz;
    // ALWAYS at BltDspMod.v:517
    vlTOPp->BltDspMod__DOT__curCnt1MHz = vlTOPp->BltDspMod__DOT__nextCnt1MHz;
    // ALWAYS at BltDspMod.v:518
    vlTOPp->BltDspMod__DOT__curCnt32kHz = vlTOPp->BltDspMod__DOT__nextCnt32kHz;
    // ALWAYS at BltDspMod.v:541
    vlTOPp->BltDspMod__DOT__curSampCentIx3 = vlTOPp->BltDspMod__DOT__nextSampCentIx3;
    // ALWAYS at BltDspMod.v:542
    vlTOPp->BltDspMod__DOT__curSampCentIx2 = vlTOPp->BltDspMod__DOT__nextSampCentIx2;
    // ALWAYS at BltDspMod.v:543
    vlTOPp->BltDspMod__DOT__curSampSideIx2 = vlTOPp->BltDspMod__DOT__nextSampSideIx2;
    // ALWAYS at BltDspMod.v:545
    vlTOPp->BltDspMod__DOT__pcmRangeCentMin = vlTOPp->BltDspMod__DOT__nextPcmRangeCentMin;
    // ALWAYS at BltDspMod.v:546
    vlTOPp->BltDspMod__DOT__pcmRangeCentMax = vlTOPp->BltDspMod__DOT__nextPcmRangeCentMax;
    // ALWAYS at BltDspMod.v:547
    vlTOPp->BltDspMod__DOT__pcmRangeSideMin = vlTOPp->BltDspMod__DOT__nextPcmRangeSideMin;
    // ALWAYS at BltDspMod.v:548
    vlTOPp->BltDspMod__DOT__pcmRangeSideMax = vlTOPp->BltDspMod__DOT__nextPcmRangeSideMax;
    // ALWAYS at BltDspMod.v:549
    vlTOPp->BltDspMod__DOT__pcmRangeCenter3 = vlTOPp->BltDspMod__DOT__nextPcmRangeCenter3;
    // ALWAYS at BltDspMod.v:550
    vlTOPp->BltDspMod__DOT__pcmRangeCenter2 = vlTOPp->BltDspMod__DOT__nextPcmRangeCenter2;
    // ALWAYS at BltDspMod.v:551
    vlTOPp->BltDspMod__DOT__pcmRangeSide2 = vlTOPp->BltDspMod__DOT__nextPcmRangeSide2;
    // ALWAYS at BltDspMod.v:552
    vlTOPp->BltDspMod__DOT__pcmMode = vlTOPp->BltDspMod__DOT__nextPcmMode;
    // ALWAYS at BltDspMod.v:554
    vlTOPp->BltDspMod__DOT__curAdpcmPred = vlTOPp->BltDspMod__DOT__nextAdpcmPred;
    // ALWAYS at BltDspMod.v:555
    vlTOPp->BltDspMod__DOT__curAdpcmStep = vlTOPp->BltDspMod__DOT__nextAdpcmStep;
    // ALWAYS at BltDspMod.v:556
    vlTOPp->BltDspMod__DOT__curAdpcmStepVal = vlTOPp->BltDspMod__DOT__nextAdpcmStepVal;
    // ALWAYS at BltDspMod.v:525
    vlTOPp->BltDspMod__DOT__curPwmValueL = vlTOPp->BltDspMod__DOT__nextPwmValueL;
    // ALWAYS at BltDspMod.v:526
    vlTOPp->BltDspMod__DOT__curPwmValueR = vlTOPp->BltDspMod__DOT__nextPwmValueR;
    // ALWAYS at BltDspMod.v:538
    vlTOPp->BltDspMod__DOT__curDspBlockA2 = ((0xc800U 
					      <= vlTOPp->BltDspMod__DOT__curCnt1kHz)
					      ? vlTOPp->BltDspMod__DOT__curDspBlockA1
					      : vlTOPp->BltDspMod__DOT__curDspBlockC1);
    // ALWAYS at BltDspMod.v:539
    vlTOPp->BltDspMod__DOT__curDspBlockB2 = ((0xc800U 
					      <= vlTOPp->BltDspMod__DOT__curCnt1kHz)
					      ? vlTOPp->BltDspMod__DOT__curDspBlockB1
					      : vlTOPp->BltDspMod__DOT__curDspBlockD1);
    vlTOPp->pwmOut = vlTOPp->BltDspMod__DOT__curPwmOut;
    vlTOPp->busIRQ = (0x100U & ((IData)(vlTOPp->BltDspMod__DOT__oBusIrqLive)
				 ? 0U : 0x100U));
    // ALWAYS at BltDspMod.v:198
    vlTOPp->BltDspMod__DOT__nextTick10MHz = vlTOPp->BltDspMod__DOT__curTick10MHz;
    vlTOPp->BltDspMod__DOT__nextCnt10MHz = (0xffU & 
					    ((IData)(vlTOPp->BltDspMod__DOT__curCnt10MHz) 
					     - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextPwmOut = vlTOPp->BltDspMod__DOT__curPwmOut;
    vlTOPp->BltDspMod__DOT__nextPwmStateL = vlTOPp->BltDspMod__DOT__curPwmStateL;
    vlTOPp->BltDspMod__DOT__nextPwmStateR = vlTOPp->BltDspMod__DOT__curPwmStateR;
    vlTOPp->BltDspMod__DOT__nextPwmCarryL = vlTOPp->BltDspMod__DOT__curPwmCarryL;
    vlTOPp->BltDspMod__DOT__nextPwmCarryR = vlTOPp->BltDspMod__DOT__curPwmCarryR;
    if ((0U == (IData)(vlTOPp->BltDspMod__DOT__curCnt10MHz))) {
	vlTOPp->BltDspMod__DOT__nextCnt10MHz = 0xaU;
	vlTOPp->BltDspMod__DOT__nextTick10MHz = ((IData)(1U) 
						 + vlTOPp->BltDspMod__DOT__curTick10MHz);
	vlTOPp->BltDspMod__DOT__nextPwmCarryL = (1U 
						 & (((IData)(vlTOPp->BltDspMod__DOT__curPwmStateL) 
						     + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueL)) 
						    >> 0x10U));
	vlTOPp->BltDspMod__DOT__nextPwmStateL = (0xffffU 
						 & ((IData)(vlTOPp->BltDspMod__DOT__curPwmStateL) 
						    + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueL)));
	vlTOPp->BltDspMod__DOT__nextPwmCarryR = (1U 
						 & (((IData)(vlTOPp->BltDspMod__DOT__curPwmStateR) 
						     + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueR)) 
						    >> 0x10U));
	vlTOPp->BltDspMod__DOT__nextPwmStateR = (0xffffU 
						 & ((IData)(vlTOPp->BltDspMod__DOT__curPwmStateR) 
						    + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueR)));
	vlTOPp->BltDspMod__DOT__nextPwmOut = ((2U & (IData)(vlTOPp->BltDspMod__DOT__nextPwmOut)) 
					      | (IData)(vlTOPp->BltDspMod__DOT__curPwmCarryL));
	vlTOPp->BltDspMod__DOT__nextPwmOut = ((1U & (IData)(vlTOPp->BltDspMod__DOT__nextPwmOut)) 
					      | ((IData)(vlTOPp->BltDspMod__DOT__curPwmCarryR) 
						 << 1U));
    }
    // ALWAYS at BltDspMod.v:534
    vlTOPp->BltDspMod__DOT__curDspBlockA1 = vlTOPp->BltDspMod__DOT__nextDspBlockA1;
    // ALWAYS at BltDspMod.v:536
    vlTOPp->BltDspMod__DOT__curDspBlockC1 = vlTOPp->BltDspMod__DOT__nextDspBlockC1;
    // ALWAYS at BltDspMod.v:535
    vlTOPp->BltDspMod__DOT__curDspBlockB1 = vlTOPp->BltDspMod__DOT__nextDspBlockB1;
    // ALWAYS at BltDspMod.v:537
    vlTOPp->BltDspMod__DOT__curDspBlockD1 = vlTOPp->BltDspMod__DOT__nextDspBlockD1;
    // ALWAYS at BltDspMod.v:519
    vlTOPp->BltDspMod__DOT__curCnt1kHz = vlTOPp->BltDspMod__DOT__nextCnt1kHz;
    // ALWAYS at BltDspMod.v:171
    vlTOPp->BltDspMod__DOT__nextDspBlockA1 = vlTOPp->BltDspMod__DOT__curDspBlockA1;
    vlTOPp->BltDspMod__DOT__nextDspBlockB1 = vlTOPp->BltDspMod__DOT__curDspBlockB1;
    vlTOPp->BltDspMod__DOT__nextDspBlockC1 = vlTOPp->BltDspMod__DOT__curDspBlockC1;
    vlTOPp->BltDspMod__DOT__nextDspBlockD1 = vlTOPp->BltDspMod__DOT__curDspBlockD1;
    vlTOPp->BltDspMod__DOT__nextTick1MHz = vlTOPp->BltDspMod__DOT__curTick1MHz;
    vlTOPp->BltDspMod__DOT__nextTick32kHz = vlTOPp->BltDspMod__DOT__curTick32kHz;
    vlTOPp->BltDspMod__DOT__nextTick1kHz = vlTOPp->BltDspMod__DOT__curTick1kHz;
    vlTOPp->BltDspMod__DOT__nextCnt1MHz = (0xffU & 
					   ((IData)(vlTOPp->BltDspMod__DOT__curCnt1MHz) 
					    - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextCnt32kHz = (0xfffU 
					    & ((IData)(vlTOPp->BltDspMod__DOT__curCnt32kHz) 
					       - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextCnt1kHz = (0x3ffffU 
					   & (vlTOPp->BltDspMod__DOT__curCnt1kHz 
					      - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextPwmValueL = vlTOPp->BltDspMod__DOT__curPwmValueL;
    vlTOPp->BltDspMod__DOT__nextPwmValueR = vlTOPp->BltDspMod__DOT__curPwmValueR;
    vlTOPp->BltDspMod__DOT__nextSampCentIx3 = vlTOPp->BltDspMod__DOT__curSampCentIx3;
    vlTOPp->BltDspMod__DOT__nextSampCentIx2 = vlTOPp->BltDspMod__DOT__curSampCentIx2;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCentMin = vlTOPp->BltDspMod__DOT__pcmRangeCentMin;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCentMax = vlTOPp->BltDspMod__DOT__pcmRangeCentMax;
    vlTOPp->BltDspMod__DOT__nextPcmRangeSideMin = vlTOPp->BltDspMod__DOT__pcmRangeSideMin;
    vlTOPp->BltDspMod__DOT__nextPcmRangeSideMax = vlTOPp->BltDspMod__DOT__pcmRangeSideMax;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCenter3 = vlTOPp->BltDspMod__DOT__pcmRangeCenter3;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCenter2 = vlTOPp->BltDspMod__DOT__pcmRangeCenter2;
    vlTOPp->BltDspMod__DOT__nextPcmRangeSide2 = vlTOPp->BltDspMod__DOT__pcmRangeSide2;
    vlTOPp->BltDspMod__DOT__nextPcmMode = vlTOPp->BltDspMod__DOT__pcmMode;
    vlTOPp->BltDspMod__DOT__nextAdpcmPred = vlTOPp->BltDspMod__DOT__curAdpcmPred;
    vlTOPp->BltDspMod__DOT__nextAdpcmStep = vlTOPp->BltDspMod__DOT__curAdpcmStep;
    vlTOPp->BltDspMod__DOT__nextAdpcmStepVal = vlTOPp->BltDspMod__DOT__curAdpcmStepVal;
    if ((0U == (IData)(vlTOPp->BltDspMod__DOT__curCnt1MHz))) {
	vlTOPp->BltDspMod__DOT__nextCnt1MHz = 0x64U;
	vlTOPp->BltDspMod__DOT__nextTick1MHz = ((IData)(1U) 
						+ vlTOPp->BltDspMod__DOT__curTick1MHz);
	if ((8U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
	    vlTOPp->BltDspMod__DOT__nextPwmValueL = 0x8000U;
	    vlTOPp->BltDspMod__DOT__nextPwmValueR = 0x8000U;
	} else {
	    if ((4U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
		vlTOPp->BltDspMod__DOT__nextPwmValueL = 0x8000U;
		vlTOPp->BltDspMod__DOT__nextPwmValueR = 0x8000U;
	    } else {
		if ((2U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
		    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = vlTOPp->BltDspMod__DOT__curAdpcmPred;
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = vlTOPp->BltDspMod__DOT__curAdpcmPred;
		    } else {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = (0xffffU & ((1U & vlTOPp->BltDspMod__DOT__curTick1kHz)
					   ? 0xbb80U
					   : 0x4000U));
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = (0xffffU & ((2U & vlTOPp->BltDspMod__DOT__curTick1kHz)
					   ? 0xbb80U
					   : 0x4000U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCenter2) 
					  + (((IData)(vlTOPp->BltDspMod__DOT__nextPcmRangeSide2) 
					      - (IData)(0x8000U)) 
					     >> 1U)));
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCenter2) 
					  - (((IData)(vlTOPp->BltDspMod__DOT__nextPcmRangeSide2) 
					      - (IData)(0x8000U)) 
					     >> 1U)));
		    } else {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = vlTOPp->BltDspMod__DOT__pcmRangeCenter3;
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = vlTOPp->BltDspMod__DOT__pcmRangeCenter3;
		    }
		}
	    }
	}
	vlTOPp->BltDspMod__DOT__nextAdpcmStepVal = 
	    (0xffffU & ((4U | (3U & (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep))) 
			<< (0xfU & ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep) 
				    >> 2U))));
    }
    vlTOPp->BltDspMod__DOT__oNextBusIrqLive = 0U;
    if ((0U == vlTOPp->BltDspMod__DOT__curCnt1kHz)) {
	vlTOPp->BltDspMod__DOT__nextCnt1kHz = 0x186a0U;
	vlTOPp->BltDspMod__DOT__nextTick1kHz = ((IData)(1U) 
						+ vlTOPp->BltDspMod__DOT__curTick1kHz);
	vlTOPp->BltDspMod__DOT__nextDspBlockA1 = vlTOPp->BltDspMod__DOT__curDspBlockA0;
	vlTOPp->BltDspMod__DOT__nextDspBlockB1 = vlTOPp->BltDspMod__DOT__curDspBlockB0;
	vlTOPp->BltDspMod__DOT__nextDspBlockC1 = vlTOPp->BltDspMod__DOT__curDspBlockC0;
	vlTOPp->BltDspMod__DOT__nextDspBlockD1 = vlTOPp->BltDspMod__DOT__curDspBlockD0;
	vlTOPp->BltDspMod__DOT__oNextBusIrqLive = 1U;
    }
    if ((0U == (IData)(vlTOPp->BltDspMod__DOT__curCnt32kHz))) {
	vlTOPp->BltDspMod__DOT__tPcmRangeCenter3 = 
	    (0xfffffU & ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
					>> 2U))) ? 
			 ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
					 >> 1U))) ? 
			  ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
			    ? ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax) 
			       << 4U) : (((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin) 
					  << 1U) + 
					 ((IData)(0xeU) 
					  * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax))))
			   : ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
			       ? (((IData)(5U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				  + ((IData)(0xbU) 
				     * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))
			       : (((IData)(7U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				  + ((IData)(9U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))))
			  : ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
					    >> 1U)))
			      ? ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
				  ? (((IData)(9U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				     + ((IData)(7U) 
					* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))
				  : (((IData)(0xbU) 
				      * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				     + ((IData)(5U) 
					* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax))))
			      : ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
				  ? (((IData)(0xeU) 
				      * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				     + ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax) 
					<< 1U)) : ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin) 
						   << 4U)))));
	vlTOPp->BltDspMod__DOT__tPcmRangeCenter2 = 
	    (0xfffffU & ((2U & vlTOPp->BltDspMod__DOT__curSampCentIx2)
			  ? ((1U & vlTOPp->BltDspMod__DOT__curSampCentIx2)
			      ? ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax) 
				 << 4U) : (((IData)(5U) 
					    * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
					   + ((IData)(0xbU) 
					      * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax))))
			  : ((1U & vlTOPp->BltDspMod__DOT__curSampCentIx2)
			      ? (((IData)(0xbU) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				 + ((IData)(5U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))
			      : ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin) 
				 << 4U))));
	vlTOPp->BltDspMod__DOT__tPcmRangeSide2 = (0xfffffU 
						  & ((2U 
						      & (IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2))
						       ? 
						      ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMax) 
						       << 4U)
						       : 
						      (((IData)(5U) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMin)) 
						       + 
						       ((IData)(0xbU) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMax))))
						      : 
						     ((1U 
						       & (IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2))
						       ? 
						      (((IData)(0xbU) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMin)) 
						       + 
						       ((IData)(5U) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMax)))
						       : 
						      ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMin) 
						       << 4U))));
	vlTOPp->BltDspMod__DOT__nextCnt32kHz = 0xc35U;
	vlTOPp->BltDspMod__DOT__nextTick32kHz = ((IData)(1U) 
						 + vlTOPp->BltDspMod__DOT__curTick32kHz);
	vlTOPp->BltDspMod__DOT__nextCnt1kHz = (0x3ffffU 
					       & (vlTOPp->BltDspMod__DOT__curCnt1kHz 
						  - (IData)(1U)));
	vlTOPp->BltDspMod__DOT__nextSampCentIx3 = (VL_ULL(0xffffffffffff) 
						   & (vlTOPp->BltDspMod__DOT__curSampCentIx3 
						      >> 3U));
	vlTOPp->BltDspMod__DOT__nextPcmRangeCenter3 
	    = (0xffffU & (vlTOPp->BltDspMod__DOT__tPcmRangeCenter3 
			  >> 4U));
	vlTOPp->BltDspMod__DOT__nextPcmRangeCenter2 
	    = (0xffffU & (vlTOPp->BltDspMod__DOT__tPcmRangeCenter2 
			  >> 4U));
	vlTOPp->BltDspMod__DOT__nextPcmRangeSide2 = 
	    (0xffffU & (vlTOPp->BltDspMod__DOT__tPcmRangeSide2 
			>> 4U));
	vlTOPp->BltDspMod__DOT__nextSampCentIx2 = (vlTOPp->BltDspMod__DOT__curSampCentIx2 
						   >> 2U);
	if ((3U == (3U & vlTOPp->BltDspMod__DOT__curTick32kHz))) {
	    vlTOPp->BltDspMod__DOT__nextSampSideIx2 
		= (0xffU & ((IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2) 
			    >> 2U));
	}
	if ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
			   >> 1U)))) {
	    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))) {
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = (0x3fU & ((IData)(3U) + (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep)));
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & ((((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				    >> 1U) + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
					      >> 2U)) 
				  + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				     >> 3U)));
	    } else {
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep)));
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & (((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				   >> 1U) + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
					     >> 3U)));
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))) {
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = vlTOPp->BltDspMod__DOT__curAdpcmStep;
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & (((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				   >> 2U) + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
					     >> 3U)));
	    } else {
		if ((0U < (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep))) {
		    vlTOPp->BltDspMod__DOT__nextAdpcmStep 
			= (0x3fU & ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep) 
				    - (IData)(1U)));
		}
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				  >> 3U));
	    }
	}
	vlTOPp->BltDspMod__DOT__nextAdpcmPred = (0xffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->BltDspMod__DOT__curSampCentIx3 
								>> 2U)))
						     ? 
						    ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmPred) 
						     - (IData)(vlTOPp->BltDspMod__DOT__tAdpcmStepOfs))
						     : 
						    ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmPred) 
						     + (IData)(vlTOPp->BltDspMod__DOT__tAdpcmStepOfs))));
	if ((0U == (0xfU & vlTOPp->BltDspMod__DOT__curTick32kHz))) {
	    vlTOPp->BltDspMod__DOT__nextSampCentIx3 
		= ((VL_ULL(0xffff) & vlTOPp->BltDspMod__DOT__nextSampCentIx3) 
		   | ((QData)((IData)(vlTOPp->BltDspMod__DOT__curDspBlockB2)) 
		      << 0x10U));
	    vlTOPp->BltDspMod__DOT__nextSampCentIx2 
		= vlTOPp->BltDspMod__DOT__curDspBlockB2;
	    vlTOPp->BltDspMod__DOT__nextSampSideIx2 
		= (0xffU & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
			    >> 0x18U));
	    if ((0x38U >= (0x3fU & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
		vlTOPp->BltDspMod__DOT__nextPcmMode = 3U;
		vlTOPp->BltDspMod__DOT__nextAdpcmPred 
		    = (0x8000U ^ (0xffc0U & vlTOPp->BltDspMod__DOT__curDspBlockA2));
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = (0x3fU & vlTOPp->BltDspMod__DOT__curDspBlockA2);
	    } else {
		if ((2U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
		    vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
			= (0xfc00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      << 4U));
		    vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
			= (0x3c00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      >> 2U));
		    vlTOPp->BltDspMod__DOT__pcmRangeSideAvg 
			= (0xf800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      >> 5U));
		    vlTOPp->BltDspMod__DOT__pcmRangeSideOfs 
			= (0x3800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      >> 0xaU));
		    vlTOPp->BltDspMod__DOT__nextPcmMode = 1U;
		} else {
		    if ((3U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
			vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
			    = (0xf800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					  << 5U));
			vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
			    = (0xf800U & vlTOPp->BltDspMod__DOT__curDspBlockA2);
			vlTOPp->BltDspMod__DOT__pcmRangeSideAvg 
			    = (0xf800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					  >> 5U));
			vlTOPp->BltDspMod__DOT__pcmRangeSideOfs 
			    = (0x3800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					  >> 0xaU));
			vlTOPp->BltDspMod__DOT__nextPcmMode = 1U;
		    } else {
			if ((4U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
			    vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
				= (0xfe00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					      << 3U));
			    vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
				= (0xe00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					     >> 4U));
			    vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
			    vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
			    vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
			} else {
			    if ((5U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
				vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
				    = (0xfc00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
						  << 4U));
				vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
				    = (0x3c00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
						  >> 2U));
				vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
				vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
				vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
			    } else {
				if ((6U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
				    vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
					= (0xf800U 
					   & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					      << 5U));
				    vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
					= (0xf800U 
					   & vlTOPp->BltDspMod__DOT__curDspBlockA2);
				    vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
				    vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
				    vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
				} else {
				    if ((7U == (7U 
						& vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
					vlTOPp->BltDspMod__DOT__pcmRangeCentAvg = 0x8000U;
					vlTOPp->BltDspMod__DOT__pcmRangeCentOfs = 0xffffU;
					vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
					vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
					vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
				    }
				}
			    }
			}
		    }
		}
		vlTOPp->BltDspMod__DOT__nextPcmRangeCentMin 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentAvg) 
				  - ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentOfs) 
				     >> 1U)));
		vlTOPp->BltDspMod__DOT__nextPcmRangeCentMax 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentAvg) 
				  + ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentOfs) 
				     >> 1U)));
		vlTOPp->BltDspMod__DOT__nextPcmRangeSideMin 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideAvg) 
				  - ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideOfs) 
				     >> 1U)));
		vlTOPp->BltDspMod__DOT__nextPcmRangeSideMax 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideAvg) 
				  + ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideOfs) 
				     >> 1U)));
	    }
	    vlTOPp->BltDspMod__DOT__nextSampCentIx3 
		= ((VL_ULL(0xffffffff0000) & vlTOPp->BltDspMod__DOT__nextSampCentIx3) 
		   | (IData)((IData)((0xffffU & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
						 >> 0x10U)))));
	}
    }
}

void VBltDspMod::_settle__TOP__4(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_settle__TOP__4\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->pwmOut = vlTOPp->BltDspMod__DOT__curPwmOut;
    vlTOPp->busIRQ = (0x100U & ((IData)(vlTOPp->BltDspMod__DOT__oBusIrqLive)
				 ? 0U : 0x100U));
    // ALWAYS at BltDspMod.v:166
    vlTOPp->BltDspMod__DOT__nextDspBlockA0 = vlTOPp->BltDspMod__DOT__curDspBlockA0;
    vlTOPp->BltDspMod__DOT__nextDspBlockB0 = vlTOPp->BltDspMod__DOT__curDspBlockB0;
    vlTOPp->BltDspMod__DOT__nextDspBlockC0 = vlTOPp->BltDspMod__DOT__curDspBlockC0;
    vlTOPp->BltDspMod__DOT__nextDspBlockD0 = vlTOPp->BltDspMod__DOT__curDspBlockD0;
    if ((0xabcde0U == (0xffffffU & (vlTOPp->busAddr 
				    >> 8U)))) {
	if (vlTOPp->busWR) {
	    if ((0U == (0x3fU & (vlTOPp->busAddr >> 2U)))) {
		vlTOPp->BltDspMod__DOT__nextDspBlockA0 
		    = vlTOPp->busData;
	    } else {
		if ((1U == (0x3fU & (vlTOPp->busAddr 
				     >> 2U)))) {
		    vlTOPp->BltDspMod__DOT__nextDspBlockB0 
			= vlTOPp->busData;
		} else {
		    if ((2U == (0x3fU & (vlTOPp->busAddr 
					 >> 2U)))) {
			vlTOPp->BltDspMod__DOT__nextDspBlockC0 
			    = vlTOPp->busData;
		    } else {
			if ((3U == (0x3fU & (vlTOPp->busAddr 
					     >> 2U)))) {
			    vlTOPp->BltDspMod__DOT__nextDspBlockD0 
				= vlTOPp->busData;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at BltDspMod.v:198
    vlTOPp->BltDspMod__DOT__nextTick10MHz = vlTOPp->BltDspMod__DOT__curTick10MHz;
    vlTOPp->BltDspMod__DOT__nextCnt10MHz = (0xffU & 
					    ((IData)(vlTOPp->BltDspMod__DOT__curCnt10MHz) 
					     - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextPwmOut = vlTOPp->BltDspMod__DOT__curPwmOut;
    vlTOPp->BltDspMod__DOT__nextPwmStateL = vlTOPp->BltDspMod__DOT__curPwmStateL;
    vlTOPp->BltDspMod__DOT__nextPwmStateR = vlTOPp->BltDspMod__DOT__curPwmStateR;
    vlTOPp->BltDspMod__DOT__nextPwmCarryL = vlTOPp->BltDspMod__DOT__curPwmCarryL;
    vlTOPp->BltDspMod__DOT__nextPwmCarryR = vlTOPp->BltDspMod__DOT__curPwmCarryR;
    if ((0U == (IData)(vlTOPp->BltDspMod__DOT__curCnt10MHz))) {
	vlTOPp->BltDspMod__DOT__nextCnt10MHz = 0xaU;
	vlTOPp->BltDspMod__DOT__nextTick10MHz = ((IData)(1U) 
						 + vlTOPp->BltDspMod__DOT__curTick10MHz);
	vlTOPp->BltDspMod__DOT__nextPwmCarryL = (1U 
						 & (((IData)(vlTOPp->BltDspMod__DOT__curPwmStateL) 
						     + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueL)) 
						    >> 0x10U));
	vlTOPp->BltDspMod__DOT__nextPwmStateL = (0xffffU 
						 & ((IData)(vlTOPp->BltDspMod__DOT__curPwmStateL) 
						    + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueL)));
	vlTOPp->BltDspMod__DOT__nextPwmCarryR = (1U 
						 & (((IData)(vlTOPp->BltDspMod__DOT__curPwmStateR) 
						     + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueR)) 
						    >> 0x10U));
	vlTOPp->BltDspMod__DOT__nextPwmStateR = (0xffffU 
						 & ((IData)(vlTOPp->BltDspMod__DOT__curPwmStateR) 
						    + (IData)(vlTOPp->BltDspMod__DOT__curPwmValueR)));
	vlTOPp->BltDspMod__DOT__nextPwmOut = ((2U & (IData)(vlTOPp->BltDspMod__DOT__nextPwmOut)) 
					      | (IData)(vlTOPp->BltDspMod__DOT__curPwmCarryL));
	vlTOPp->BltDspMod__DOT__nextPwmOut = ((1U & (IData)(vlTOPp->BltDspMod__DOT__nextPwmOut)) 
					      | ((IData)(vlTOPp->BltDspMod__DOT__curPwmCarryR) 
						 << 1U));
    }
    // ALWAYS at BltDspMod.v:171
    vlTOPp->BltDspMod__DOT__nextDspBlockA1 = vlTOPp->BltDspMod__DOT__curDspBlockA1;
    vlTOPp->BltDspMod__DOT__nextDspBlockB1 = vlTOPp->BltDspMod__DOT__curDspBlockB1;
    vlTOPp->BltDspMod__DOT__nextDspBlockC1 = vlTOPp->BltDspMod__DOT__curDspBlockC1;
    vlTOPp->BltDspMod__DOT__nextDspBlockD1 = vlTOPp->BltDspMod__DOT__curDspBlockD1;
    vlTOPp->BltDspMod__DOT__nextTick1MHz = vlTOPp->BltDspMod__DOT__curTick1MHz;
    vlTOPp->BltDspMod__DOT__nextTick32kHz = vlTOPp->BltDspMod__DOT__curTick32kHz;
    vlTOPp->BltDspMod__DOT__nextTick1kHz = vlTOPp->BltDspMod__DOT__curTick1kHz;
    vlTOPp->BltDspMod__DOT__nextCnt1MHz = (0xffU & 
					   ((IData)(vlTOPp->BltDspMod__DOT__curCnt1MHz) 
					    - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextCnt32kHz = (0xfffU 
					    & ((IData)(vlTOPp->BltDspMod__DOT__curCnt32kHz) 
					       - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextCnt1kHz = (0x3ffffU 
					   & (vlTOPp->BltDspMod__DOT__curCnt1kHz 
					      - (IData)(1U)));
    vlTOPp->BltDspMod__DOT__nextPwmValueL = vlTOPp->BltDspMod__DOT__curPwmValueL;
    vlTOPp->BltDspMod__DOT__nextPwmValueR = vlTOPp->BltDspMod__DOT__curPwmValueR;
    vlTOPp->BltDspMod__DOT__nextSampCentIx3 = vlTOPp->BltDspMod__DOT__curSampCentIx3;
    vlTOPp->BltDspMod__DOT__nextSampCentIx2 = vlTOPp->BltDspMod__DOT__curSampCentIx2;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCentMin = vlTOPp->BltDspMod__DOT__pcmRangeCentMin;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCentMax = vlTOPp->BltDspMod__DOT__pcmRangeCentMax;
    vlTOPp->BltDspMod__DOT__nextPcmRangeSideMin = vlTOPp->BltDspMod__DOT__pcmRangeSideMin;
    vlTOPp->BltDspMod__DOT__nextPcmRangeSideMax = vlTOPp->BltDspMod__DOT__pcmRangeSideMax;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCenter3 = vlTOPp->BltDspMod__DOT__pcmRangeCenter3;
    vlTOPp->BltDspMod__DOT__nextPcmRangeCenter2 = vlTOPp->BltDspMod__DOT__pcmRangeCenter2;
    vlTOPp->BltDspMod__DOT__nextPcmRangeSide2 = vlTOPp->BltDspMod__DOT__pcmRangeSide2;
    vlTOPp->BltDspMod__DOT__nextPcmMode = vlTOPp->BltDspMod__DOT__pcmMode;
    vlTOPp->BltDspMod__DOT__nextAdpcmPred = vlTOPp->BltDspMod__DOT__curAdpcmPred;
    vlTOPp->BltDspMod__DOT__nextAdpcmStep = vlTOPp->BltDspMod__DOT__curAdpcmStep;
    vlTOPp->BltDspMod__DOT__nextAdpcmStepVal = vlTOPp->BltDspMod__DOT__curAdpcmStepVal;
    if ((0U == (IData)(vlTOPp->BltDspMod__DOT__curCnt1MHz))) {
	vlTOPp->BltDspMod__DOT__nextCnt1MHz = 0x64U;
	vlTOPp->BltDspMod__DOT__nextTick1MHz = ((IData)(1U) 
						+ vlTOPp->BltDspMod__DOT__curTick1MHz);
	if ((8U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
	    vlTOPp->BltDspMod__DOT__nextPwmValueL = 0x8000U;
	    vlTOPp->BltDspMod__DOT__nextPwmValueR = 0x8000U;
	} else {
	    if ((4U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
		vlTOPp->BltDspMod__DOT__nextPwmValueL = 0x8000U;
		vlTOPp->BltDspMod__DOT__nextPwmValueR = 0x8000U;
	    } else {
		if ((2U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
		    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = vlTOPp->BltDspMod__DOT__curAdpcmPred;
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = vlTOPp->BltDspMod__DOT__curAdpcmPred;
		    } else {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = (0xffffU & ((1U & vlTOPp->BltDspMod__DOT__curTick1kHz)
					   ? 0xbb80U
					   : 0x4000U));
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = (0xffffU & ((2U & vlTOPp->BltDspMod__DOT__curTick1kHz)
					   ? 0xbb80U
					   : 0x4000U));
		    }
		} else {
		    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__pcmMode))) {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCenter2) 
					  + (((IData)(vlTOPp->BltDspMod__DOT__nextPcmRangeSide2) 
					      - (IData)(0x8000U)) 
					     >> 1U)));
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCenter2) 
					  - (((IData)(vlTOPp->BltDspMod__DOT__nextPcmRangeSide2) 
					      - (IData)(0x8000U)) 
					     >> 1U)));
		    } else {
			vlTOPp->BltDspMod__DOT__nextPwmValueL 
			    = vlTOPp->BltDspMod__DOT__pcmRangeCenter3;
			vlTOPp->BltDspMod__DOT__nextPwmValueR 
			    = vlTOPp->BltDspMod__DOT__pcmRangeCenter3;
		    }
		}
	    }
	}
	vlTOPp->BltDspMod__DOT__nextAdpcmStepVal = 
	    (0xffffU & ((4U | (3U & (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep))) 
			<< (0xfU & ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep) 
				    >> 2U))));
    }
    vlTOPp->BltDspMod__DOT__oNextBusIrqLive = 0U;
    if ((0U == vlTOPp->BltDspMod__DOT__curCnt1kHz)) {
	vlTOPp->BltDspMod__DOT__nextCnt1kHz = 0x186a0U;
	vlTOPp->BltDspMod__DOT__nextTick1kHz = ((IData)(1U) 
						+ vlTOPp->BltDspMod__DOT__curTick1kHz);
	vlTOPp->BltDspMod__DOT__nextDspBlockA1 = vlTOPp->BltDspMod__DOT__curDspBlockA0;
	vlTOPp->BltDspMod__DOT__nextDspBlockB1 = vlTOPp->BltDspMod__DOT__curDspBlockB0;
	vlTOPp->BltDspMod__DOT__nextDspBlockC1 = vlTOPp->BltDspMod__DOT__curDspBlockC0;
	vlTOPp->BltDspMod__DOT__nextDspBlockD1 = vlTOPp->BltDspMod__DOT__curDspBlockD0;
	vlTOPp->BltDspMod__DOT__oNextBusIrqLive = 1U;
    }
    if ((0U == (IData)(vlTOPp->BltDspMod__DOT__curCnt32kHz))) {
	vlTOPp->BltDspMod__DOT__tPcmRangeCenter3 = 
	    (0xfffffU & ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
					>> 2U))) ? 
			 ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
					 >> 1U))) ? 
			  ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
			    ? ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax) 
			       << 4U) : (((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin) 
					  << 1U) + 
					 ((IData)(0xeU) 
					  * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax))))
			   : ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
			       ? (((IData)(5U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				  + ((IData)(0xbU) 
				     * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))
			       : (((IData)(7U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				  + ((IData)(9U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))))
			  : ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
					    >> 1U)))
			      ? ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
				  ? (((IData)(9U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				     + ((IData)(7U) 
					* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))
				  : (((IData)(0xbU) 
				      * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				     + ((IData)(5U) 
					* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax))))
			      : ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))
				  ? (((IData)(0xeU) 
				      * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				     + ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax) 
					<< 1U)) : ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin) 
						   << 4U)))));
	vlTOPp->BltDspMod__DOT__tPcmRangeCenter2 = 
	    (0xfffffU & ((2U & vlTOPp->BltDspMod__DOT__curSampCentIx2)
			  ? ((1U & vlTOPp->BltDspMod__DOT__curSampCentIx2)
			      ? ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax) 
				 << 4U) : (((IData)(5U) 
					    * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
					   + ((IData)(0xbU) 
					      * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax))))
			  : ((1U & vlTOPp->BltDspMod__DOT__curSampCentIx2)
			      ? (((IData)(0xbU) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin)) 
				 + ((IData)(5U) * (IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMax)))
			      : ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentMin) 
				 << 4U))));
	vlTOPp->BltDspMod__DOT__tPcmRangeSide2 = (0xfffffU 
						  & ((2U 
						      & (IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2))
						       ? 
						      ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMax) 
						       << 4U)
						       : 
						      (((IData)(5U) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMin)) 
						       + 
						       ((IData)(0xbU) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMax))))
						      : 
						     ((1U 
						       & (IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2))
						       ? 
						      (((IData)(0xbU) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMin)) 
						       + 
						       ((IData)(5U) 
							* (IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMax)))
						       : 
						      ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideMin) 
						       << 4U))));
	vlTOPp->BltDspMod__DOT__nextCnt32kHz = 0xc35U;
	vlTOPp->BltDspMod__DOT__nextTick32kHz = ((IData)(1U) 
						 + vlTOPp->BltDspMod__DOT__curTick32kHz);
	vlTOPp->BltDspMod__DOT__nextCnt1kHz = (0x3ffffU 
					       & (vlTOPp->BltDspMod__DOT__curCnt1kHz 
						  - (IData)(1U)));
	vlTOPp->BltDspMod__DOT__nextSampCentIx3 = (VL_ULL(0xffffffffffff) 
						   & (vlTOPp->BltDspMod__DOT__curSampCentIx3 
						      >> 3U));
	vlTOPp->BltDspMod__DOT__nextPcmRangeCenter3 
	    = (0xffffU & (vlTOPp->BltDspMod__DOT__tPcmRangeCenter3 
			  >> 4U));
	vlTOPp->BltDspMod__DOT__nextPcmRangeCenter2 
	    = (0xffffU & (vlTOPp->BltDspMod__DOT__tPcmRangeCenter2 
			  >> 4U));
	vlTOPp->BltDspMod__DOT__nextPcmRangeSide2 = 
	    (0xffffU & (vlTOPp->BltDspMod__DOT__tPcmRangeSide2 
			>> 4U));
	vlTOPp->BltDspMod__DOT__nextSampCentIx2 = (vlTOPp->BltDspMod__DOT__curSampCentIx2 
						   >> 2U);
	if ((3U == (3U & vlTOPp->BltDspMod__DOT__curTick32kHz))) {
	    vlTOPp->BltDspMod__DOT__nextSampSideIx2 
		= (0xffU & ((IData)(vlTOPp->BltDspMod__DOT__curSampSideIx2) 
			    >> 2U));
	}
	if ((1U & (IData)((vlTOPp->BltDspMod__DOT__curSampCentIx3 
			   >> 1U)))) {
	    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))) {
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = (0x3fU & ((IData)(3U) + (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep)));
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & ((((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				    >> 1U) + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
					      >> 2U)) 
				  + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				     >> 3U)));
	    } else {
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep)));
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & (((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				   >> 1U) + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
					     >> 3U)));
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->BltDspMod__DOT__curSampCentIx3))) {
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = vlTOPp->BltDspMod__DOT__curAdpcmStep;
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & (((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				   >> 2U) + ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
					     >> 3U)));
	    } else {
		if ((0U < (IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep))) {
		    vlTOPp->BltDspMod__DOT__nextAdpcmStep 
			= (0x3fU & ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStep) 
				    - (IData)(1U)));
		}
		vlTOPp->BltDspMod__DOT__tAdpcmStepOfs 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmStepVal) 
				  >> 3U));
	    }
	}
	vlTOPp->BltDspMod__DOT__nextAdpcmPred = (0xffffU 
						 & ((1U 
						     & (IData)(
							       (vlTOPp->BltDspMod__DOT__curSampCentIx3 
								>> 2U)))
						     ? 
						    ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmPred) 
						     - (IData)(vlTOPp->BltDspMod__DOT__tAdpcmStepOfs))
						     : 
						    ((IData)(vlTOPp->BltDspMod__DOT__curAdpcmPred) 
						     + (IData)(vlTOPp->BltDspMod__DOT__tAdpcmStepOfs))));
	if ((0U == (0xfU & vlTOPp->BltDspMod__DOT__curTick32kHz))) {
	    vlTOPp->BltDspMod__DOT__nextSampCentIx3 
		= ((VL_ULL(0xffff) & vlTOPp->BltDspMod__DOT__nextSampCentIx3) 
		   | ((QData)((IData)(vlTOPp->BltDspMod__DOT__curDspBlockB2)) 
		      << 0x10U));
	    vlTOPp->BltDspMod__DOT__nextSampCentIx2 
		= vlTOPp->BltDspMod__DOT__curDspBlockB2;
	    vlTOPp->BltDspMod__DOT__nextSampSideIx2 
		= (0xffU & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
			    >> 0x18U));
	    if ((0x38U >= (0x3fU & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
		vlTOPp->BltDspMod__DOT__nextPcmMode = 3U;
		vlTOPp->BltDspMod__DOT__nextAdpcmPred 
		    = (0x8000U ^ (0xffc0U & vlTOPp->BltDspMod__DOT__curDspBlockA2));
		vlTOPp->BltDspMod__DOT__nextAdpcmStep 
		    = (0x3fU & vlTOPp->BltDspMod__DOT__curDspBlockA2);
	    } else {
		if ((2U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
		    vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
			= (0xfc00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      << 4U));
		    vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
			= (0x3c00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      >> 2U));
		    vlTOPp->BltDspMod__DOT__pcmRangeSideAvg 
			= (0xf800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      >> 5U));
		    vlTOPp->BltDspMod__DOT__pcmRangeSideOfs 
			= (0x3800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
				      >> 0xaU));
		    vlTOPp->BltDspMod__DOT__nextPcmMode = 1U;
		} else {
		    if ((3U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
			vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
			    = (0xf800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					  << 5U));
			vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
			    = (0xf800U & vlTOPp->BltDspMod__DOT__curDspBlockA2);
			vlTOPp->BltDspMod__DOT__pcmRangeSideAvg 
			    = (0xf800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					  >> 5U));
			vlTOPp->BltDspMod__DOT__pcmRangeSideOfs 
			    = (0x3800U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					  >> 0xaU));
			vlTOPp->BltDspMod__DOT__nextPcmMode = 1U;
		    } else {
			if ((4U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
			    vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
				= (0xfe00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					      << 3U));
			    vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
				= (0xe00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					     >> 4U));
			    vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
			    vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
			    vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
			} else {
			    if ((5U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
				vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
				    = (0xfc00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
						  << 4U));
				vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
				    = (0x3c00U & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
						  >> 2U));
				vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
				vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
				vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
			    } else {
				if ((6U == (7U & vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
				    vlTOPp->BltDspMod__DOT__pcmRangeCentAvg 
					= (0xf800U 
					   & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
					      << 5U));
				    vlTOPp->BltDspMod__DOT__pcmRangeCentOfs 
					= (0xf800U 
					   & vlTOPp->BltDspMod__DOT__curDspBlockA2);
				    vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
				    vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
				    vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
				} else {
				    if ((7U == (7U 
						& vlTOPp->BltDspMod__DOT__curDspBlockA2))) {
					vlTOPp->BltDspMod__DOT__pcmRangeCentAvg = 0x8000U;
					vlTOPp->BltDspMod__DOT__pcmRangeCentOfs = 0xffffU;
					vlTOPp->BltDspMod__DOT__pcmRangeSideAvg = 0x8000U;
					vlTOPp->BltDspMod__DOT__pcmRangeSideOfs = 0U;
					vlTOPp->BltDspMod__DOT__nextPcmMode = 0U;
				    }
				}
			    }
			}
		    }
		}
		vlTOPp->BltDspMod__DOT__nextPcmRangeCentMin 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentAvg) 
				  - ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentOfs) 
				     >> 1U)));
		vlTOPp->BltDspMod__DOT__nextPcmRangeCentMax 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentAvg) 
				  + ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeCentOfs) 
				     >> 1U)));
		vlTOPp->BltDspMod__DOT__nextPcmRangeSideMin 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideAvg) 
				  - ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideOfs) 
				     >> 1U)));
		vlTOPp->BltDspMod__DOT__nextPcmRangeSideMax 
		    = (0xffffU & ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideAvg) 
				  + ((IData)(vlTOPp->BltDspMod__DOT__pcmRangeSideOfs) 
				     >> 1U)));
	    }
	    vlTOPp->BltDspMod__DOT__nextSampCentIx3 
		= ((VL_ULL(0xffffffff0000) & vlTOPp->BltDspMod__DOT__nextSampCentIx3) 
		   | (IData)((IData)((0xffffU & (vlTOPp->BltDspMod__DOT__curDspBlockA2 
						 >> 0x10U)))));
	}
    }
}

VL_INLINE_OPT void VBltDspMod::_combo__TOP__5(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_combo__TOP__5\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at BltDspMod.v:166
    vlTOPp->BltDspMod__DOT__nextDspBlockA0 = vlTOPp->BltDspMod__DOT__curDspBlockA0;
    vlTOPp->BltDspMod__DOT__nextDspBlockB0 = vlTOPp->BltDspMod__DOT__curDspBlockB0;
    vlTOPp->BltDspMod__DOT__nextDspBlockC0 = vlTOPp->BltDspMod__DOT__curDspBlockC0;
    vlTOPp->BltDspMod__DOT__nextDspBlockD0 = vlTOPp->BltDspMod__DOT__curDspBlockD0;
    if ((0xabcde0U == (0xffffffU & (vlTOPp->busAddr 
				    >> 8U)))) {
	if (vlTOPp->busWR) {
	    if ((0U == (0x3fU & (vlTOPp->busAddr >> 2U)))) {
		vlTOPp->BltDspMod__DOT__nextDspBlockA0 
		    = vlTOPp->busData;
	    } else {
		if ((1U == (0x3fU & (vlTOPp->busAddr 
				     >> 2U)))) {
		    vlTOPp->BltDspMod__DOT__nextDspBlockB0 
			= vlTOPp->busData;
		} else {
		    if ((2U == (0x3fU & (vlTOPp->busAddr 
					 >> 2U)))) {
			vlTOPp->BltDspMod__DOT__nextDspBlockC0 
			    = vlTOPp->busData;
		    } else {
			if ((3U == (0x3fU & (vlTOPp->busAddr 
					     >> 2U)))) {
			    vlTOPp->BltDspMod__DOT__nextDspBlockD0 
				= vlTOPp->busData;
			}
		    }
		}
	    }
	}
    }
}

void VBltDspMod::_eval(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_eval\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VBltDspMod::_eval_initial(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_eval_initial\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void VBltDspMod::final() {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::final\n"); );
    // Variables
    VBltDspMod__Syms* __restrict vlSymsp = this->__VlSymsp;
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VBltDspMod::_eval_settle(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_eval_settle\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData VBltDspMod::_change_request(VBltDspMod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_change_request\n"); );
    VBltDspMod* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void VBltDspMod::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    pwmOut = VL_RAND_RESET_I(2);
    busAddr = VL_RAND_RESET_I(32);
    busData = VL_RAND_RESET_I(32);
    busOE = VL_RAND_RESET_I(1);
    busWR = VL_RAND_RESET_I(1);
    busHold = VL_RAND_RESET_I(1);
    busIRQ = VL_RAND_RESET_I(32);
    BltDspMod__DOT__oBusIrqLive = VL_RAND_RESET_I(1);
    BltDspMod__DOT__oNextBusIrqLive = VL_RAND_RESET_I(1);
    BltDspMod__DOT__curTick10MHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curTick1MHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curTick32kHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curTick1kHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextTick10MHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextTick1MHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextTick32kHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextTick1kHz = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curCnt10MHz = VL_RAND_RESET_I(8);
    BltDspMod__DOT__curCnt1MHz = VL_RAND_RESET_I(8);
    BltDspMod__DOT__curCnt32kHz = VL_RAND_RESET_I(12);
    BltDspMod__DOT__curCnt1kHz = VL_RAND_RESET_I(18);
    BltDspMod__DOT__nextCnt10MHz = VL_RAND_RESET_I(8);
    BltDspMod__DOT__nextCnt1MHz = VL_RAND_RESET_I(8);
    BltDspMod__DOT__nextCnt32kHz = VL_RAND_RESET_I(12);
    BltDspMod__DOT__nextCnt1kHz = VL_RAND_RESET_I(18);
    BltDspMod__DOT__curDspBlockA0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockB0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockC0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockD0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockA0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockB0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockC0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockD0 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockA1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockB1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockC1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockD1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockA1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockB1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockC1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextDspBlockD1 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockA2 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curDspBlockB2 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curSampCentIx3 = VL_RAND_RESET_Q(48);
    BltDspMod__DOT__nextSampCentIx3 = VL_RAND_RESET_Q(48);
    BltDspMod__DOT__curSampCentIx2 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__nextSampCentIx2 = VL_RAND_RESET_I(32);
    BltDspMod__DOT__curSampSideIx2 = VL_RAND_RESET_I(8);
    BltDspMod__DOT__nextSampSideIx2 = VL_RAND_RESET_I(8);
    BltDspMod__DOT__curPwmOut = VL_RAND_RESET_I(2);
    BltDspMod__DOT__nextPwmOut = VL_RAND_RESET_I(2);
    BltDspMod__DOT__curPwmStateL = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPwmStateL = VL_RAND_RESET_I(16);
    BltDspMod__DOT__curPwmStateR = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPwmStateR = VL_RAND_RESET_I(16);
    BltDspMod__DOT__curPwmValueL = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPwmValueL = VL_RAND_RESET_I(16);
    BltDspMod__DOT__curPwmValueR = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPwmValueR = VL_RAND_RESET_I(16);
    BltDspMod__DOT__curPwmCarryL = VL_RAND_RESET_I(1);
    BltDspMod__DOT__nextPwmCarryL = VL_RAND_RESET_I(1);
    BltDspMod__DOT__curPwmCarryR = VL_RAND_RESET_I(1);
    BltDspMod__DOT__nextPwmCarryR = VL_RAND_RESET_I(1);
    BltDspMod__DOT__pcmRangeCentMin = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeCentMax = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeSideMin = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeSideMax = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeCenter3 = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeCenter2 = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeSide2 = VL_RAND_RESET_I(16);
    BltDspMod__DOT__tPcmRangeCenter3 = VL_RAND_RESET_I(20);
    BltDspMod__DOT__tPcmRangeCenter2 = VL_RAND_RESET_I(20);
    BltDspMod__DOT__tPcmRangeSide2 = VL_RAND_RESET_I(20);
    BltDspMod__DOT__pcmRangeCentAvg = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeCentOfs = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeSideAvg = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmRangeSideOfs = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeCentMin = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeCentMax = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeSideMin = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeSideMax = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeCenter3 = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeCenter2 = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextPcmRangeSide2 = VL_RAND_RESET_I(16);
    BltDspMod__DOT__curAdpcmPred = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextAdpcmPred = VL_RAND_RESET_I(16);
    BltDspMod__DOT__curAdpcmStep = VL_RAND_RESET_I(6);
    BltDspMod__DOT__nextAdpcmStep = VL_RAND_RESET_I(6);
    BltDspMod__DOT__curAdpcmStepVal = VL_RAND_RESET_I(16);
    BltDspMod__DOT__nextAdpcmStepVal = VL_RAND_RESET_I(16);
    BltDspMod__DOT__tAdpcmStepOfs = VL_RAND_RESET_I(16);
    BltDspMod__DOT__pcmMode = VL_RAND_RESET_I(4);
    BltDspMod__DOT__nextPcmMode = VL_RAND_RESET_I(4);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
}

void VBltDspMod::_configure_coverage(VBltDspMod__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    VBltDspMod::_configure_coverage\n"); );
    // Body
    if (0 && vlSymsp && first) {} // Prevent unused
}
