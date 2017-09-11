// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFpuFp64_H_
#define _VFpuFp64_H_

#include "verilated.h"
class VFpuFp64__Syms;

//----------

VL_MODULE(VFpuFp64) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(opf32,0,0);
    VL_IN8(opMode,3,0);
    VL_IN8(sri,3,0);
    VL_OUT8(sro,3,0);
    //char	__VpadToAlign5[3];
    VL_IN64(srca,63,0);
    VL_IN64(srcb,63,0);
    VL_OUT64(dst,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(FpuFp64__DOT__tOpFp32i,0,0);
    VL_SIG8(FpuFp64__DOT__tSro,3,0);
    VL_SIG8(FpuFp64__DOT__fpadd__DOT__sgna,0,0);
    VL_SIG8(FpuFp64__DOT__fpadd__DOT__sgnb,0,0);
    VL_SIG8(FpuFp64__DOT__fpadd__DOT__sgnc,0,0);
    VL_SIG8(FpuFp64__DOT__fpmul__DOT__sgna,0,0);
    VL_SIG8(FpuFp64__DOT__fpmul__DOT__sgnb,0,0);
    VL_SIG8(FpuFp64__DOT__fpmul__DOT__sgnc,0,0);
    VL_SIG8(FpuFp64__DOT__cnv2si1__DOT__sgn,0,0);
    VL_SIG8(FpuFp64__DOT__cnv2si1__DOT__tShl,5,0);
    VL_SIG8(FpuFp64__DOT__cnv2is1__DOT__sgnc,0,0);
    //char	__VpadToAlign47[1];
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__exa,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__exb,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__exc,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__exm,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__tExc_A,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__tExc_B,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__tExc_C,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__tExc_D,12,0);
    VL_SIG16(FpuFp64__DOT__fpadd__DOT__tExc_E,12,0);
    VL_SIG16(FpuFp64__DOT__fpmul__DOT__exa,12,0);
    VL_SIG16(FpuFp64__DOT__fpmul__DOT__exb,12,0);
    VL_SIG16(FpuFp64__DOT__fpmul__DOT__exc,12,0);
    VL_SIG16(FpuFp64__DOT__fprcp__DOT__exa,12,0);
    VL_SIG16(FpuFp64__DOT__fprcp__DOT__exb,12,0);
    VL_SIG16(FpuFp64__DOT__fpcnva__DOT__exa,11,0);
    VL_SIG16(FpuFp64__DOT__fpcnva__DOT__exb,11,0);
    VL_SIG16(FpuFp64__DOT__fpcnvb__DOT__exa,11,0);
    VL_SIG16(FpuFp64__DOT__fpcnvb__DOT__exb,11,0);
    VL_SIG16(FpuFp64__DOT__cnv2si1__DOT__exa,11,0);
    VL_SIG16(FpuFp64__DOT__cnv2si1__DOT__exb,11,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__exc,12,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__exm,12,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__tExc_A,12,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__tExc_B,12,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__tExc_C,12,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__tExc_D,12,0);
    VL_SIG16(FpuFp64__DOT__cnv2is1__DOT__tExc_E,12,0);
    VL_SIG16(FpuFp64__DOT__fpcnvc__DOT__exa,11,0);
    VL_SIG16(FpuFp64__DOT__fpcnvc__DOT__exb,11,0);
    //char	__VpadToAlign106[2];
    VL_SIG(FpuFp64__DOT__fpcnvc__DOT__tDst,31,0);
    VL_SIG64(FpuFp64__DOT__fcSrcA,63,0);
    VL_SIG64(FpuFp64__DOT__fcSrcB,63,0);
    VL_SIG64(FpuFp64__DOT__fpmSrcB,63,0);
    VL_SIG64(FpuFp64__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__fpCnvcDst,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracA,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracB,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracA1,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracB1,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC1,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC2,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC2_A,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC2_B,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC2_C,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC2_D,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tFracC2_E,63,0);
    VL_SIG64(FpuFp64__DOT__fpadd__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__fpmul__DOT__tFracA,63,0);
    VL_SIG64(FpuFp64__DOT__fpmul__DOT__tFracB,63,0);
    VL_SIG64(FpuFp64__DOT__fpmul__DOT__tFracC,63,0);
    VL_SIG64(FpuFp64__DOT__fpmul__DOT__tFracC2,51,0);
    VL_SIG64(FpuFp64__DOT__fpmul__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__fprcp__DOT__fra,52,0);
    VL_SIG64(FpuFp64__DOT__fprcp__DOT__frb,52,0);
    VL_SIG64(FpuFp64__DOT__fprcp__DOT__tFr2,52,0);
    VL_SIG64(FpuFp64__DOT__fprcp__DOT__tFr3,52,0);
    VL_SIG64(FpuFp64__DOT__fprcp__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__fpcnva__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__fpcnvb__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2si1__DOT__fra,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2si1__DOT__tDst,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2si1__DOT__tDst2,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC2,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC2_A,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC2_B,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC2_C,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC2_D,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tFracC2_E,63,0);
    VL_SIG64(FpuFp64__DOT__cnv2is1__DOT__tDst,63,0);
    VL_SIG16(FpuFp64__DOT__fprcp__DOT__rcpLut[256],15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFpuFp64__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VFpuFp64& operator= (const VFpuFp64&);	///< Copying not allowed
    VFpuFp64(const VFpuFp64&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VFpuFp64(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFpuFp64();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VFpuFp64__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFpuFp64__Syms* symsp, bool first);
  private:
    static QData	_change_request(VFpuFp64__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__11(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_combo__TOP__3(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_combo__TOP__5(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_combo__TOP__7(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_combo__TOP__9(VFpuFp64__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VFpuFp64__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_eval_initial(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_eval_settle(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_initial__TOP__2(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_settle__TOP__1(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_settle__TOP__10(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(VFpuFp64__Syms* __restrict vlSymsp);
    static void	_settle__TOP__8(VFpuFp64__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
