// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMemTile2_H_
#define _VMemTile2_H_

#include "verilated_heavy.h"
class VMemTile2__Syms;

//----------

VL_MODULE(VMemTile2) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(opRd,0,0);
    VL_IN8(opWr,0,0);
    VL_IN8(opMode,2,0);
    VL_IN8(iopRd,0,0);
    VL_OUT8(extOE,0,0);
    VL_OUT8(extWR,0,0);
    VL_OUT8(extHold,0,0);
    VL_IN8(extNotReady,0,0);
    //char	__VpadToAlign10[2];
    VL_INOUT(extData,31,0);
    VL_IN64(memAddr,63,0);
    VL_IN64(wrValue,63,0);
    VL_OUT64(rdValue,63,0);
    VL_IN64(imemAddr,47,0);
    VL_OUT64(irdValue,63,0);
    VL_OUT64(extAddr,47,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(MemTile2__DOT__dTileMiss,0,0);
    VL_SIG8(MemTile2__DOT__iTileMiss,0,0);
    VL_SIG8(MemTile2__DOT__dTileMiss2,0,0);
    VL_SIG8(MemTile2__DOT__iTileMiss2,0,0);
    VL_SIG8(MemTile2__DOT__rdtShl,4,0);
    VL_SIG8(MemTile2__DOT__irdtShl,4,0);
    VL_SIG8(MemTile2__DOT__reqLdTileIdx,6,0);
    VL_SIG8(MemTile2__DOT__reqLdTile,0,0);
    VL_SIG8(MemTile2__DOT__reqLdITile,0,0);
    VL_SIG8(MemTile2__DOT__reqLdSTile,0,0);
    VL_SIG8(MemTile2__DOT__reqStTile,0,0);
    VL_SIG8(MemTile2__DOT__reqSyncTile,0,0);
    VL_SIG8(MemTile2__DOT__reqNextSyncTile,0,0);
    VL_SIG8(MemTile2__DOT__reqSyncTileIdx,6,0);
    VL_SIG8(MemTile2__DOT__reqNextSyncTileIdx,6,0);
    VL_SIG8(MemTile2__DOT__ldTileWIdx,3,0);
    VL_SIG8(MemTile2__DOT__ldTileNextWIdx,3,0);
    VL_SIG8(MemTile2__DOT__ldTileAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileStAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextStAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileDlyAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextDlyAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileLastAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextLastAct,0,0);
    VL_SIG8(MemTile2__DOT__ldTileDn,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextDn,0,0);
    VL_SIG8(MemTile2__DOT__ldTileExtOE,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextExtOE,0,0);
    VL_SIG8(MemTile2__DOT__ldTileExtWR,0,0);
    VL_SIG8(MemTile2__DOT__ldTileNextExtWR,0,0);
    VL_SIG8(MemTile2__DOT__dTileOpWrOK,0,0);
    VL_SIG8(MemTile2__DOT__resetAct,0,0);
    VL_SIG8(MemTile2__DOT__resetNextAct,0,0);
    VL_SIG8(MemTile2__DOT__resetCurTile,6,0);
    VL_SIG8(MemTile2__DOT__resetNextTile,6,0);
    VL_SIG16(MemTile2__DOT__dTileIdx,10,0);
    VL_SIG16(MemTile2__DOT__iTileIdx,10,0);
    VL_SIG16(MemTile2__DOT__dTileLimIdx,10,0);
    VL_SIG16(MemTile2__DOT__iTileLimIdx,10,0);
    VL_SIG16(MemTile2__DOT__reqLdTileBaseHi,9,0);
    VL_SIG16(MemTile2__DOT__ldTileIdx,10,0);
    VL_SIG16(MemTile2__DOT__resetTOK,15,0);
    //char	__VpadToAlign118[2];
    VL_SIGW(MemTile2__DOT__rdtTBlock,95,0,3);
    //char	__VpadToAlign132[4];
    VL_SIGW(MemTile2__DOT__rdtTBlock2,95,0,3);
    //char	__VpadToAlign148[4];
    VL_SIGW(MemTile2__DOT__rdtValue,95,0,3);
    //char	__VpadToAlign164[4];
    VL_SIGW(MemTile2__DOT__irdtTBlock,95,0,3);
    //char	__VpadToAlign180[4];
    VL_SIGW(MemTile2__DOT__irdtValue,95,0,3);
    VL_SIG(MemTile2__DOT__reqLdTileBaseLo,31,0);
    VL_SIG64(MemTile2__DOT__dMemAddr,47,0);
    VL_SIG64(MemTile2__DOT__dMemAddrLim,47,0);
    VL_SIG64(MemTile2__DOT__iMemAddr,47,0);
    VL_SIG64(MemTile2__DOT__iMemAddrLim,47,0);
    VL_SIG64(MemTile2__DOT__tDrdValue,63,0);
    VL_SIG64(MemTile2__DOT__tIrdValue,63,0);
    VL_SIG64(MemTile2__DOT__ldTileExtAddr,47,0);
    VL_SIG(MemTile2__DOT__dTile[2048],31,0);
    VL_SIG(MemTile2__DOT__dTileBase[128],31,0);
    VL_SIG16(MemTile2__DOT__dTileBaseHi[128],9,0);
    VL_SIG8(MemTile2__DOT__dTileBaseDty[128],0,0);
    VL_SIG(MemTile2__DOT__iTile[2048],31,0);
    VL_SIG(MemTile2__DOT__iTileBase[128],31,0);
    VL_SIG16(MemTile2__DOT__iTileBaseHi[128],9,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign18309[3];
    VL_SIG(MemTile2__DOT__extData__out__out0,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMemTile2__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VMemTile2& operator= (const VMemTile2&);	///< Copying not allowed
    VMemTile2(const VMemTile2&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VMemTile2(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMemTile2();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMemTile2__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMemTile2__Syms* symsp, bool first);
  private:
    static QData	_change_request(VMemTile2__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__3(VMemTile2__Syms* __restrict vlSymsp);
    static void	_combo__TOP__5(VMemTile2__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VMemTile2__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VMemTile2__Syms* __restrict vlSymsp);
    static void	_eval_initial(VMemTile2__Syms* __restrict vlSymsp);
    static void	_eval_settle(VMemTile2__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VMemTile2__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(VMemTile2__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(VMemTile2__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
