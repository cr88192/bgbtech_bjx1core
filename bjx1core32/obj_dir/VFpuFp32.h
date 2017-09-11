// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFpuFp32_H_
#define _VFpuFp32_H_

#include "verilated.h"
class VFpuFp32__Syms;

//----------

VL_MODULE(VFpuFp32) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(opMode,3,0);
    //char	__VpadToAlign2[2];
    VL_IN(srca,31,0);
    VL_IN(srcb,31,0);
    VL_OUT(dst,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(FpuFp32__DOT__fpadd__DOT__sgna,0,0);
    VL_SIG8(FpuFp32__DOT__fpadd__DOT__sgnb,0,0);
    VL_SIG8(FpuFp32__DOT__fpadd__DOT__sgnc,0,0);
    VL_SIG8(FpuFp32__DOT__fpmul__DOT__sgna,0,0);
    VL_SIG8(FpuFp32__DOT__fpmul__DOT__sgnb,0,0);
    VL_SIG8(FpuFp32__DOT__fpmul__DOT__sgnc,0,0);
    VL_SIG8(FpuFp32__DOT__fprcp__DOT__exa,7,0);
    VL_SIG8(FpuFp32__DOT__fprcp__DOT__exb,7,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__exa,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__exb,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__exc,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__exm,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__tExc_A,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__tExc_B,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__tExc_C,9,0);
    VL_SIG16(FpuFp32__DOT__fpadd__DOT__tExc_D,9,0);
    VL_SIG16(FpuFp32__DOT__fpmul__DOT__exa,9,0);
    VL_SIG16(FpuFp32__DOT__fpmul__DOT__exb,9,0);
    VL_SIG16(FpuFp32__DOT__fpmul__DOT__exc,9,0);
    //char	__VpadToAlign50[2];
    VL_SIG(FpuFp32__DOT__fpaDst,31,0);
    VL_SIG(FpuFp32__DOT__fpmSrcB,31,0);
    VL_SIG(FpuFp32__DOT__fpmDst,31,0);
    VL_SIG(FpuFp32__DOT__fpRcpDst,31,0);
    VL_SIG(FpuFp32__DOT__tDst,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracA,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracB,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracA1,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracB1,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC1,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC2,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC2_A,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC2_B,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC2_C,31,0);
    VL_SIG(FpuFp32__DOT__fpadd__DOT__tFracC2_D,31,0);
    VL_SIG(FpuFp32__DOT__fpmul__DOT__tFracC2,22,0);
    VL_SIG(FpuFp32__DOT__fpmul__DOT__tDst,31,0);
    VL_SIG(FpuFp32__DOT__fprcp__DOT__fra,23,0);
    VL_SIG(FpuFp32__DOT__fprcp__DOT__frb,23,0);
    VL_SIG(FpuFp32__DOT__fprcp__DOT__tFr2,23,0);
    VL_SIG64(FpuFp32__DOT__fpmul__DOT__tFracA,47,0);
    VL_SIG64(FpuFp32__DOT__fpmul__DOT__tFracB,47,0);
    VL_SIG64(FpuFp32__DOT__fpmul__DOT__tFracC,47,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VFpuFp32__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VFpuFp32& operator= (const VFpuFp32&);	///< Copying not allowed
    VFpuFp32(const VFpuFp32&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VFpuFp32(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VFpuFp32();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VFpuFp32__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VFpuFp32__Syms* symsp, bool first);
  private:
    static QData	_change_request(VFpuFp32__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(VFpuFp32__Syms* __restrict vlSymsp);
    static void	_combo__TOP__3(VFpuFp32__Syms* __restrict vlSymsp);
    static void	_combo__TOP__5(VFpuFp32__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VFpuFp32__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VFpuFp32__Syms* __restrict vlSymsp);
    static void	_eval_initial(VFpuFp32__Syms* __restrict vlSymsp);
    static void	_eval_settle(VFpuFp32__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(VFpuFp32__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(VFpuFp32__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
