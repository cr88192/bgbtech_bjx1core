// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VExUop_H_
#define _VExUop_H_

#include "verilated_heavy.h"
class VExUop__Syms;

//----------

VL_MODULE(VExUop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(extOE,0,0);
    VL_OUT8(extWR,0,0);
    VL_IN8(extNotReady,0,0);
    //char	__VpadToAlign5[3];
    VL_OUT(extAddr,31,0);
    VL_INOUT(extData,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(ExUop__DOT__idRegD,6,0);
    VL_SIG8(ExUop__DOT__idRegS,6,0);
    VL_SIG8(ExUop__DOT__idRegT,6,0);
    VL_SIG8(ExUop__DOT__uopCmd,7,0);
    VL_SIG8(ExUop__DOT__ixRegD,6,0);
    VL_SIG8(ExUop__DOT__ixRegS,6,0);
    VL_SIG8(ExUop__DOT__ixRegT,6,0);
    VL_SIG8(ExUop__DOT__iRegD,6,0);
    VL_SIG8(ExUop__DOT__iRegS,6,0);
    VL_SIG8(ExUop__DOT__iRegT,6,0);
    VL_SIG8(ExUop__DOT__tIdReg2D,6,0);
    VL_SIG8(ExUop__DOT__tIsWr2D,0,0);
    VL_SIG8(ExUop__DOT__tIsQw2D,0,0);
    VL_SIG8(ExUop__DOT__oIdReg2D,6,0);
    VL_SIG8(ExUop__DOT__oIsWr2D,0,0);
    VL_SIG8(ExUop__DOT__oIsQw2D,0,0);
    VL_SIG8(ExUop__DOT__aluCmd,3,0);
    VL_SIG8(ExUop__DOT__aguHasIndex,0,0);
    VL_SIG8(ExUop__DOT__aguCmd,2,0);
    VL_SIG8(ExUop__DOT__fpuOpFp32,0,0);
    VL_SIG8(ExUop__DOT__fpuCmd,3,0);
    VL_SIG8(ExUop__DOT__memRd,0,0);
    VL_SIG8(ExUop__DOT__memWr,0,0);
    VL_SIG8(ExUop__DOT__memCmd,2,0);
    VL_SIG8(ExUop__DOT__imemRd,0,0);
    VL_SIG8(ExUop__DOT__memHold,0,0);
    VL_SIG8(ExUop__DOT__idStepPc,1,0);
    VL_SIG8(ExUop__DOT__uopPcLive,0,0);
    VL_SIG8(ExUop__DOT__uopNextPcLive,0,0);
    VL_SIG8(ExUop__DOT__tResetOK,0,0);
    VL_SIG8(ExUop__DOT__tPipeFlush,2,0);
    VL_SIG8(ExUop__DOT__tNextPipeFlush,2,0);
    VL_SIG8(ExUop__DOT__tPipeDsFlush,0,0);
    VL_SIG8(ExUop__DOT__tNextPipeDsFlush,0,0);
    VL_SIG8(ExUop__DOT__regs__DOT__tIdReg1Lo,5,0);
    VL_SIG8(ExUop__DOT__regs__DOT__tIdReg2Lo,5,0);
    VL_SIG8(ExUop__DOT__regs__DOT__tIdReg3Lo,5,0);
    VL_SIG8(ExUop__DOT__alu1__DOT__tShl,5,0);
    VL_SIG8(ExUop__DOT__alu1__DOT__tSr,3,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__tOpFp32i,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__tSro,3,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__fpadd__DOT__sgna,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnb,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__fpadd__DOT__sgnc,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__fpmul__DOT__sgna,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnb,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__fpmul__DOT__sgnc,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__sgn,0,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tShl,5,0);
    VL_SIG8(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__sgnc,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__dTileMiss,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__iTileMiss,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__dTileMiss2,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__iTileMiss2,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__rdtShl,4,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__irdtShl,4,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqLdTileIdx,6,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqLdTile,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqLdITile,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqLdSTile,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqStTile,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqSyncTile,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqNextSyncTile,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqSyncTileIdx,6,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__reqNextSyncTileIdx,6,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileWIdx,3,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextWIdx,3,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileStAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextStAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileDlyAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextDlyAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileLastAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextLastAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileDn,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextDn,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileExtOE,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextExtOE,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileExtWR,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__ldTileNextExtWR,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__dTileOpWrOK,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__resetAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__resetNextAct,0,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__resetCurTile,6,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__resetNextTile,6,0);
    VL_SIG8(ExUop__DOT__dec1__DOT__srIsDq,0,0);
    VL_SIG8(ExUop__DOT__dec1__DOT__opIs32p,0,0);
    VL_SIG8(ExUop__DOT__dec1__DOT__tIdRegD,6,0);
    VL_SIG8(ExUop__DOT__dec1__DOT__tIdRegS,6,0);
    VL_SIG8(ExUop__DOT__dec1__DOT__tIdRegT,6,0);
    //char	__VpadToAlign111[1];
    VL_SIG16(ExUop__DOT__uopPc,11,0);
    VL_SIG16(ExUop__DOT__uopNextPc,11,0);
    VL_SIG16(ExUop__DOT__tResetMagic,15,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__exa,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__exb,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__exc,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__exm,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_A,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_B,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_C,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_D,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpadd__DOT__tExc_E,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpmul__DOT__exa,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpmul__DOT__exb,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpmul__DOT__exc,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnva__DOT__exa,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnva__DOT__exb,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exa,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnvb__DOT__exb,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exa,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnvc__DOT__exb,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exa,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__exb,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exc,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__exm,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_A,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_B,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_C,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_D,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tExc_E,12,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exa,11,0);
    VL_SIG16(ExUop__DOT__fpu1__DOT__fpcnvd__DOT__exb,11,0);
    VL_SIG16(ExUop__DOT__mem1__DOT__dTileIdx,10,0);
    VL_SIG16(ExUop__DOT__mem1__DOT__iTileIdx,10,0);
    VL_SIG16(ExUop__DOT__mem1__DOT__dTileLimIdx,10,0);
    VL_SIG16(ExUop__DOT__mem1__DOT__iTileLimIdx,10,0);
    VL_SIG16(ExUop__DOT__mem1__DOT__ldTileIdx,10,0);
    VL_SIG16(ExUop__DOT__mem1__DOT__resetTOK,15,0);
    VL_SIG(ExUop__DOT__ifRegPc,31,0);
    VL_SIG(ExUop__DOT__idNextInstWord,31,0);
    VL_SIG(ExUop__DOT__idInstWord,31,0);
    VL_SIG(ExUop__DOT__idImm,31,0);
    VL_SIG(ExUop__DOT__idUopWord,31,0);
    VL_SIG(ExUop__DOT__idRegPc,31,0);
    VL_SIG(ExUop__DOT__idRegNextPc,31,0);
    VL_SIG(ExUop__DOT__uopWord,31,0);
    VL_SIG(ExUop__DOT__uopNextWord,31,0);
    VL_SIG(ExUop__DOT__ixImm,31,0);
    VL_SIG(ExUop__DOT__ixRegPc,31,0);
    VL_SIG(ExUop__DOT__ixRegNextPc,31,0);
    VL_SIG(ExUop__DOT__iImm,31,0);
    VL_SIG(ExUop__DOT__iDataAluS,31,0);
    VL_SIG(ExUop__DOT__iDataAluT,31,0);
    VL_SIG(ExUop__DOT__regNextSr,31,0);
    VL_SIG(ExUop__DOT__regNextPc,31,0);
    VL_SIG(ExUop__DOT__regPrNextPc,31,0);
    VL_SIG(ExUop__DOT__regPrPc,31,0);
    VL_SIG(ExUop__DOT__regNextPr,31,0);
    VL_SIG(ExUop__DOT__tDataAguD,31,0);
    VL_SIG(ExUop__DOT__memAddr,31,0);
    VL_SIG(ExUop__DOT__imemAddr,31,0);
    VL_SIG(ExUop__DOT__tRegStepPc,31,0);
    VL_SIG(ExUop__DOT__regs__DOT__reg_pc,31,0);
    VL_SIG(ExUop__DOT__regs__DOT__reg_pr,31,0);
    VL_SIG(ExUop__DOT__regs__DOT__reg_sr,31,0);
    VL_SIG(ExUop__DOT__alu1__DOT__tDst,31,0);
    VL_SIG(ExUop__DOT__agu1__DOT__tIdxAddr,31,0);
    VL_SIG(ExUop__DOT__agu1__DOT__tOutAddr,31,0);
    VL_SIG(ExUop__DOT__fpu1__DOT__fpcnvd__DOT__tDst,31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__dMemAddr,31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__dMemAddrLim,31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__iMemAddr,31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__iMemAddrLim,31,0);
    VL_SIGW(ExUop__DOT__mem1__DOT__rdtTBlock,95,0,3);
    //char	__VpadToAlign340[4];
    VL_SIGW(ExUop__DOT__mem1__DOT__rdtTBlock2,95,0,3);
    //char	__VpadToAlign356[4];
    VL_SIGW(ExUop__DOT__mem1__DOT__rdtValue,95,0,3);
    //char	__VpadToAlign372[4];
    VL_SIGW(ExUop__DOT__mem1__DOT__irdtTBlock,95,0,3);
    //char	__VpadToAlign388[4];
    VL_SIGW(ExUop__DOT__mem1__DOT__irdtValue,95,0,3);
    VL_SIG(ExUop__DOT__mem1__DOT__reqLdTileBaseLo,25,0);
    VL_SIG(ExUop__DOT__mem1__DOT__ldTileExtAddr,31,0);
    VL_SIG(ExUop__DOT__dec1__DOT__tIdImm,31,0);
    VL_SIG64(ExUop__DOT__iDataD,63,0);
    VL_SIG64(ExUop__DOT__iDataS,63,0);
    VL_SIG64(ExUop__DOT__iDataT,63,0);
    VL_SIG64(ExUop__DOT__tData2D,63,0);
    VL_SIG64(ExUop__DOT__oData2D,63,0);
    VL_SIG64(ExUop__DOT__iDataFpuD,63,0);
    VL_SIG64(ExUop__DOT__iDataFpuS,63,0);
    VL_SIG64(ExUop__DOT__iDataFpuT,63,0);
    VL_SIG64(ExUop__DOT__memWrValue,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fcSrcA,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fcSrcB,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpaSrcA,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpaSrcB,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__tDst2,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpCnvdDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracA1,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracB1,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC1,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_A,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_B,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_C,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_D,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tFracC2_E,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpadd__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracA,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracB,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpmul__DOT__tFracC2,51,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpmul__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpcnva__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpcnvb__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__fpcnvc__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__fra,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2si1__DOT__tDst2,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_A,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_B,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_C,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_D,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tFracC2_E,63,0);
    VL_SIG64(ExUop__DOT__fpu1__DOT__cnv2is1__DOT__tDst,63,0);
    VL_SIG64(ExUop__DOT__mem1__DOT__tDrdValue,63,0);
    VL_SIG64(ExUop__DOT__mem1__DOT__tIrdValue,63,0);
    VL_SIG(ExUop__DOT__regs__DOT__regs_lo[64],31,0);
    VL_SIG(ExUop__DOT__regs__DOT__regs_hi[64],31,0);
    VL_SIG(ExUop__DOT__regs__DOT__creg_lo[16],31,0);
    VL_SIG(ExUop__DOT__regs__DOT__creg_hi[16],31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__dTile[2048],31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__dTileBase[128],25,0);
    VL_SIG8(ExUop__DOT__mem1__DOT__dTileBaseDty[128],0,0);
    VL_SIG(ExUop__DOT__mem1__DOT__iTile[2048],31,0);
    VL_SIG(ExUop__DOT__mem1__DOT__iTileBase[128],25,0);
    VL_SIG16(ExUop__DOT__dec1__DOT__uopPcIdx[256],11,0);
    VL_SIG(ExUop__DOT__dec1__DOT__uopPgm[4096],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vchglast__TOP__ExUop__DOT__iRegD,6,0);
    VL_SIG8(__Vchglast__TOP__ExUop__DOT__iRegS,6,0);
    VL_SIG8(__Vchglast__TOP__ExUop__DOT__iRegT,6,0);
    VL_SIG8(__Vchglast__TOP__ExUop__DOT__alu1__DOT__tSr,3,0);
    VL_SIG8(__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tSro,3,0);
    VL_SIG8(__Vchglast__TOP__ExUop__DOT__mem1__DOT__reqLdTile,0,0);
    //char	__VpadToAlign35899[1];
    VL_SIG(ExUop__DOT__mem1__DOT__extData__out__out0,31,0);
    VL_SIG(__Vchglast__TOP__ExUop__DOT__tDataAguD,31,0);
    VL_SIG(__Vchglast__TOP__ExUop__DOT__alu1__DOT__tDst,31,0);
    VL_SIG64(__Vchglast__TOP__ExUop__DOT__fpu1__DOT__tDst2,63,0);
    VL_SIG64(__Vchglast__TOP__ExUop__DOT__mem1__DOT__tDrdValue,63,0);
    VL_SIG64(__Vchglast__TOP__ExUop__DOT__mem1__DOT__tIrdValue,63,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign35940[4];
    VExUop__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VExUop& operator= (const VExUop&);	///< Copying not allowed
    VExUop(const VExUop&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VExUop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VExUop();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VExUop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VExUop__Syms* symsp, bool first);
  private:
    static QData	_change_request(VExUop__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__10(VExUop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__12(VExUop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__14(VExUop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__16(VExUop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__6(VExUop__Syms* __restrict vlSymsp);
    static void	_combo__TOP__8(VExUop__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VExUop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VExUop__Syms* __restrict vlSymsp);
    static void	_eval_initial(VExUop__Syms* __restrict vlSymsp);
    static void	_eval_settle(VExUop__Syms* __restrict vlSymsp);
    static void	_initial__TOP__2(VExUop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(VExUop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__1(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__11(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__13(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__15(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__7(VExUop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__9(VExUop__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
