// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMemAlu_H_
#define _VMemAlu_H_

#include "verilated.h"
class VMemAlu__Syms;

//----------

VL_MODULE(VMemAlu) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(mode,2,0);
    //char	__VpadToAlign2[2];
    VL_IN(idxAddr,31,0);
    VL_IN(idxDisp,31,0);
    //char	__VpadToAlign12[4];
    VL_IN64(baseAddr,63,0);
    VL_OUT64(outAddr,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(MemAlu__DOT__tIdxAddr,31,0);
    VL_SIG64(MemAlu__DOT__tIdxAddr2,63,0);
    VL_SIG64(MemAlu__DOT__tOutAddr,63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMemAlu__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VMemAlu& operator= (const VMemAlu&);	///< Copying not allowed
    VMemAlu(const VMemAlu&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VMemAlu(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMemAlu();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMemAlu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMemAlu__Syms* symsp, bool first);
  private:
    static QData	_change_request(VMemAlu__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(VMemAlu__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VMemAlu__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VMemAlu__Syms* __restrict vlSymsp);
    static void	_eval_initial(VMemAlu__Syms* __restrict vlSymsp);
    static void	_eval_settle(VMemAlu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
