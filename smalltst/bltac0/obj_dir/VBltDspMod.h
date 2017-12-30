// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VBltDspMod_H_
#define _VBltDspMod_H_

#include "verilated.h"
class VBltDspMod__Syms;

//----------

VL_MODULE(VBltDspMod) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(pwmOut,1,0);
    VL_IN8(busOE,0,0);
    VL_IN8(busWR,0,0);
    VL_OUT8(busHold,0,0);
    //char	__VpadToAlign6[2];
    VL_IN(busAddr,31,0);
    VL_INOUT(busData,31,0);
    VL_INOUT(busIRQ,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(BltDspMod__DOT__oBusIrqLive,0,0);
    VL_SIG8(BltDspMod__DOT__oNextBusIrqLive,0,0);
    VL_SIG8(BltDspMod__DOT__curCnt10MHz,7,0);
    VL_SIG8(BltDspMod__DOT__curCnt1MHz,7,0);
    VL_SIG8(BltDspMod__DOT__nextCnt10MHz,7,0);
    VL_SIG8(BltDspMod__DOT__nextCnt1MHz,7,0);
    VL_SIG8(BltDspMod__DOT__curSampSideIx2,7,0);
    VL_SIG8(BltDspMod__DOT__nextSampSideIx2,7,0);
    VL_SIG8(BltDspMod__DOT__curPwmOut,1,0);
    VL_SIG8(BltDspMod__DOT__nextPwmOut,1,0);
    VL_SIG8(BltDspMod__DOT__curPwmCarryL,0,0);
    VL_SIG8(BltDspMod__DOT__nextPwmCarryL,0,0);
    VL_SIG8(BltDspMod__DOT__curPwmCarryR,0,0);
    VL_SIG8(BltDspMod__DOT__nextPwmCarryR,0,0);
    VL_SIG8(BltDspMod__DOT__curAdpcmStep,5,0);
    VL_SIG8(BltDspMod__DOT__nextAdpcmStep,5,0);
    VL_SIG8(BltDspMod__DOT__pcmMode,3,0);
    VL_SIG8(BltDspMod__DOT__nextPcmMode,3,0);
    VL_SIG16(BltDspMod__DOT__curCnt32kHz,11,0);
    VL_SIG16(BltDspMod__DOT__nextCnt32kHz,11,0);
    VL_SIG16(BltDspMod__DOT__curPwmStateL,15,0);
    VL_SIG16(BltDspMod__DOT__nextPwmStateL,15,0);
    VL_SIG16(BltDspMod__DOT__curPwmStateR,15,0);
    VL_SIG16(BltDspMod__DOT__nextPwmStateR,15,0);
    VL_SIG16(BltDspMod__DOT__curPwmValueL,15,0);
    VL_SIG16(BltDspMod__DOT__nextPwmValueL,15,0);
    VL_SIG16(BltDspMod__DOT__curPwmValueR,15,0);
    VL_SIG16(BltDspMod__DOT__nextPwmValueR,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeCentMin,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeCentMax,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeSideMin,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeSideMax,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeCenter3,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeCenter2,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeSide2,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeCentAvg,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeCentOfs,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeSideAvg,15,0);
    VL_SIG16(BltDspMod__DOT__pcmRangeSideOfs,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeCentMin,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeCentMax,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeSideMin,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeSideMax,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeCenter3,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeCenter2,15,0);
    VL_SIG16(BltDspMod__DOT__nextPcmRangeSide2,15,0);
    VL_SIG16(BltDspMod__DOT__curAdpcmPred,15,0);
    VL_SIG16(BltDspMod__DOT__nextAdpcmPred,15,0);
    VL_SIG16(BltDspMod__DOT__curAdpcmStepVal,15,0);
    VL_SIG16(BltDspMod__DOT__nextAdpcmStepVal,15,0);
    VL_SIG16(BltDspMod__DOT__tAdpcmStepOfs,15,0);
    VL_SIG(BltDspMod__DOT__curTick10MHz,31,0);
    VL_SIG(BltDspMod__DOT__curTick1MHz,31,0);
    VL_SIG(BltDspMod__DOT__curTick32kHz,31,0);
    VL_SIG(BltDspMod__DOT__curTick1kHz,31,0);
    VL_SIG(BltDspMod__DOT__nextTick10MHz,31,0);
    VL_SIG(BltDspMod__DOT__nextTick1MHz,31,0);
    VL_SIG(BltDspMod__DOT__nextTick32kHz,31,0);
    VL_SIG(BltDspMod__DOT__nextTick1kHz,31,0);
    VL_SIG(BltDspMod__DOT__curCnt1kHz,17,0);
    VL_SIG(BltDspMod__DOT__nextCnt1kHz,17,0);
    VL_SIG(BltDspMod__DOT__curDspBlockA0,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockB0,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockC0,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockD0,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockA0,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockB0,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockC0,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockD0,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockA1,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockB1,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockC1,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockD1,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockA1,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockB1,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockC1,31,0);
    VL_SIG(BltDspMod__DOT__nextDspBlockD1,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockA2,31,0);
    VL_SIG(BltDspMod__DOT__curDspBlockB2,31,0);
    VL_SIG(BltDspMod__DOT__curSampCentIx2,31,0);
    VL_SIG(BltDspMod__DOT__nextSampCentIx2,31,0);
    VL_SIG(BltDspMod__DOT__tPcmRangeCenter3,19,0);
    VL_SIG(BltDspMod__DOT__tPcmRangeCenter2,19,0);
    VL_SIG(BltDspMod__DOT__tPcmRangeSide2,19,0);
    VL_SIG64(BltDspMod__DOT__curSampCentIx3,47,0);
    VL_SIG64(BltDspMod__DOT__nextSampCentIx3,47,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign261[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign268[4];
    VBltDspMod__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VBltDspMod& operator= (const VBltDspMod&);	///< Copying not allowed
    VBltDspMod(const VBltDspMod&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VBltDspMod(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VBltDspMod();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VBltDspMod__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VBltDspMod__Syms* symsp, bool first);
  private:
    static QData	_change_request(VBltDspMod__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__5(VBltDspMod__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VBltDspMod__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VBltDspMod__Syms* __restrict vlSymsp);
    static void	_eval_initial(VBltDspMod__Syms* __restrict vlSymsp);
    static void	_eval_settle(VBltDspMod__Syms* __restrict vlSymsp);
    static void	_initial__TOP__2(VBltDspMod__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(VBltDspMod__Syms* __restrict vlSymsp);
    static void	_settle__TOP__1(VBltDspMod__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(VBltDspMod__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
