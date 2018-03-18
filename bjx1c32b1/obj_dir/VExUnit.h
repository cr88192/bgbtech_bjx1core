// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VExUnit_H_
#define _VExUnit_H_

#include "verilated_heavy.h"
class VExUnit__Syms;

//----------

VL_MODULE(VExUnit) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(extOE,0,0);
    VL_OUT8(extWR,0,0);
    VL_IN8(extOK,0,0);
    VL_OUT8(mmioOE,0,0);
    VL_OUT8(mmioWR,0,0);
    VL_IN8(mmioOK,1,0);
    VL_OUT(extAddr,31,0);
    //char	__VpadToAlign12[4];
    VL_INOUTW(extData,127,0,4);
    VL_OUT(mmioAddr,31,0);
    VL_INOUT(mmioData,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(ExUnit__DOT__regRstTok,7,0);
    VL_SIG8(ExUnit__DOT__regNextRstTok,7,0);
    VL_SIG8(ExUnit__DOT__dc2RegInOE,0,0);
    VL_SIG8(ExUnit__DOT__dc2RegInWR,0,0);
    VL_SIG8(ExUnit__DOT__dc2RegInOp,4,0);
    VL_SIG8(ExUnit__DOT__dcfRegInOE,0,0);
    VL_SIG8(ExUnit__DOT__dcfRegInWR,0,0);
    VL_SIG8(ExUnit__DOT__dcfRegInOp,4,0);
    VL_SIG8(ExUnit__DOT__dcfMemPcOE,0,0);
    VL_SIG8(ExUnit__DOT__dcfMemPcOK,1,0);
    VL_SIG8(ExUnit__DOT__memIfPcOK,1,0);
    VL_SIG8(ExUnit__DOT__idWbRegO,6,0);
    VL_SIG8(ExUnit__DOT__wbRegO,6,0);
    VL_SIG8(ExUnit__DOT__idUCmd2,7,0);
    VL_SIG8(ExUnit__DOT__exRegN,6,0);
    VL_SIG8(ExUnit__DOT__exRegS,6,0);
    VL_SIG8(ExUnit__DOT__exRegT,6,0);
    VL_SIG8(ExUnit__DOT__exStepPc,3,0);
    VL_SIG8(ExUnit__DOT__exStepPc2,3,0);
    VL_SIG8(ExUnit__DOT__exUCmd,7,0);
    VL_SIG8(ExUnit__DOT__tRegGenIdStepPc,3,0);
    VL_SIG8(ExUnit__DOT__tRegExHold,0,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmOut,3,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmVal,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextVal,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmCarry,0,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmSt8,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPwmNextSt8,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncClk,2,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVSyncNextClk,2,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseClk,2,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVEqPulseNextClk,2,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldCnt,1,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tVFieldNextCnt,1,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCb,4,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCu,4,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPhaseCv,4,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCy,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCu,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixCv,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextFx,3,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextGx,5,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrA,5,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrB,5,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCy,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCu,7,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCv,7,0);
    VL_SIG8(ExUnit__DOT__dcl2__DOT__tMmioOE,0,0);
    VL_SIG8(ExUnit__DOT__dcl2__DOT__tMmioWR,0,0);
    VL_SIG8(ExUnit__DOT__dcl2__DOT__tNextTileSt,0,0);
    VL_SIG8(ExUnit__DOT__dcl2__DOT__tRegOutOK,1,0);
    VL_SIG8(ExUnit__DOT__dcl2__DOT__addrIsRam,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__tRegOutOK,1,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__tRdZx,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__tMemPcOE,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__tMemPcWR,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__tMemPcOp,4,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__isReqTileSt,3,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__nxtReqTileSt,3,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__nxtReqCommit,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__nxtReqCommitFl,3,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__accHit,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__accNoCache,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__nxtAccHit,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__accCommitOK,0,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__nxtAccCommitOK,0,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__tRegOutPcOK,1,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__tMemPcOE,0,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__isReqTileSt,2,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__nxtReqTileSt,2,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__doReqNeedAd,0,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__nxtDoReqNeedAd,0,0);
    VL_SIG8(ExUnit__DOT__icf__DOT__nxtReqCommit,0,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__isOpXE,0,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opPsDQ,0,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opPwDQ,0,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opPlDQ,0,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opJQ,0,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegN,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegS,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegT,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opUCmd,7,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opStepPc,3,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opStepPc2,3,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opStepPc2A,3,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opStepPc2B,3,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__tOpDecXfrm,4,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__tOpDecXfrmZx,2,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegN_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegM_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegM_CR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegM_SR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegN_FR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegM_FR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__opRegN_N3,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegN,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegS,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegT,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opUCmd,7,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegM_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegO_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_Dfl,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegN_FR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegS_FR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__opRegT_FR,6,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrm,4,0);
    VL_SIG8(ExUnit__DOT__dec__DOT__decXe__DOT__tOpDecXfrmZx,2,0);
    VL_SIG8(ExUnit__DOT__gpr__DOT__regSrRB,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tRegOutId,6,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tRegOutOK,1,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMemLoad,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMemStore,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMemOpMode,4,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tInAluC,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tOutAluC,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMacOp,1,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMacOpB,1,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tShadValRt,7,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tShadOp,2,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluQ0,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluM0,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluT0,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluQ1,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluM1,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluQ2,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tAluT2,0,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMacOpA0,1,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__tMacOpB0,1,0);
    VL_SIG8(ExUnit__DOT__exOp__DOT__sh32__DOT__tValSh,7,0);
    //char	__VpadToAlign175[1];
    VL_SIG16(ExUnit__DOT__regIdCsFl,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanPixClk,12,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextPixClk,12,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanRowClk,10,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScanNextRowClk,10,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCu,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModCv,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCu,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tModNextCv,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCy,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCu,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseCv,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCy,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCu,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tBaseNextCv,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCu,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCv,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCt,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosX,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixPosY,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosX,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tPixNextPosY,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tPixCellIx,13,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__nxtPixCellIx,13,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontGlyph,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosX,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixPosY,9,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellX,13,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellY,13,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellIx,13,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tPixCellNextIx,13,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyph,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphU,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontGlyphV,15,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9A,8,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClr9B,8,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbA,11,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrRgbB,11,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvA,11,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvB,11,0);
    VL_SIG16(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tClrYuvC,11,0);
    VL_SIG16(ExUnit__DOT__dcl2__DOT__tAccTileIx,10,0);
    VL_SIG16(ExUnit__DOT__dcl2__DOT__tRegTileIx,10,0);
    VL_SIG16(ExUnit__DOT__dcl2__DOT__tNextTileIx,10,0);
    VL_SIG16(ExUnit__DOT__dec__DOT__opCmdWord,15,0);
    VL_SIG16(ExUnit__DOT__dec__DOT__decXe__DOT__opPfxWord,15,0);
    VL_SIG16(ExUnit__DOT__dec__DOT__decXe__DOT__opCmdWord,15,0);
    //char	__VpadToAlign270[2];
    VL_SIG(ExUnit__DOT__dc2RegInAddr,31,0);
    //char	__VpadToAlign276[4];
    VL_SIGW(ExUnit__DOT__dc2RegInData,127,0,4);
    VL_SIG(ExUnit__DOT__dcfRegInAddr,31,0);
    //char	__VpadToAlign300[4];
    VL_SIGW(ExUnit__DOT__dcfMemInData,127,0,4);
    VL_SIG(ExUnit__DOT__dcfMemPcAddr,31,0);
    VL_SIG(ExUnit__DOT__regIfPc,31,0);
    VL_SIG(ExUnit__DOT__regIfSr,31,0);
    //char	__VpadToAlign332[4];
    VL_SIGW(ExUnit__DOT__memIfPcData,127,0,4);
    VL_SIG(ExUnit__DOT__regIdPc,31,0);
    VL_SIG(ExUnit__DOT__regIdSr,31,0);
    VL_SIG(ExUnit__DOT__idWbRegValO,31,0);
    VL_SIG(ExUnit__DOT__wbRegValO,31,0);
    VL_SIG(ExUnit__DOT__idRegValN2,31,0);
    VL_SIG(ExUnit__DOT__idRegValS2,31,0);
    VL_SIG(ExUnit__DOT__idRegValT2,31,0);
    VL_SIG(ExUnit__DOT__regExPc,31,0);
    VL_SIG(ExUnit__DOT__exImm,31,0);
    VL_SIG(ExUnit__DOT__exRegValN,31,0);
    VL_SIG(ExUnit__DOT__exRegValS,31,0);
    VL_SIG(ExUnit__DOT__exRegValT,31,0);
    VL_SIG(ExUnit__DOT__exNextPc2,31,0);
    VL_SIG(ExUnit__DOT__exNextFpul2,31,0);
    VL_SIG(ExUnit__DOT__exNextFpScr2,31,0);
    VL_SIG(ExUnit__DOT__tRegGenIdPc,31,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbAcc,21,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tCbNextAcc,21,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__tScPwmCy,17,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tBusData,31,0);
    VL_SIGW(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tCell1,127,0,4);
    VL_SIGW(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tCellData,127,0,4);
    VL_SIG(ExUnit__DOT__dcl2__DOT__tMmioOutData,31,0);
    VL_SIG(ExUnit__DOT__dcl2__DOT__tMmioAddr,31,0);
    VL_SIGW(ExUnit__DOT__dcl2__DOT__tRamTile,127,0,4);
    VL_SIGW(ExUnit__DOT__dcl2__DOT__tMemTile,127,0,4);
    VL_SIGW(ExUnit__DOT__dcl2__DOT__tOutData,127,0,4);
    VL_SIGW(ExUnit__DOT__dcl2__DOT__tNextTile,127,0,4);
    VL_SIG(ExUnit__DOT__dcf__DOT__tRegInPc1,31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__tRegInPc2,31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__tBlkNeedAd1,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__tBlkNeedAd2,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__tBlkNeedAd3,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__tBlkNeedAd4,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__tMemPcAddr,31,0);
    //char	__VpadToAlign564[4];
    VL_SIGW(ExUnit__DOT__dcf__DOT__tMemOutData,127,0,4);
    VL_SIG(ExUnit__DOT__dcf__DOT__reqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__nReqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__isReqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__nxtReqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__nxtReqCommitAd1,27,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__nxtReqCommitAd2,27,0);
    VL_SIGW(ExUnit__DOT__dcf__DOT__reqTempBlk,159,0,5);
    //char	__VpadToAlign628[4];
    VL_SIGW(ExUnit__DOT__dcf__DOT__nxtReqTempBlk,159,0,5);
    //char	__VpadToAlign652[4];
    VL_SIGW(ExUnit__DOT__dcf__DOT__accTempBlk,159,0,5);
    VL_SIG(ExUnit__DOT__icf__DOT__tRegInPc1,31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__tRegInPc2,31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__tBlkNeedAd1,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__tBlkNeedAd2,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__tMemPcAddr,31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__reqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__nReqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__isReqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__nxtReqNeedAd,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__nxtReqCommitAd1,27,0);
    VL_SIG(ExUnit__DOT__icf__DOT__nxtReqCommitAd2,27,0);
    VL_SIGW(ExUnit__DOT__icf__DOT__reqTempBlk,159,0,5);
    //char	__VpadToAlign740[4];
    VL_SIGW(ExUnit__DOT__icf__DOT__nxtReqTempBlk,159,0,5);
    //char	__VpadToAlign764[4];
    VL_SIGW(ExUnit__DOT__icf__DOT__accTempBlk,159,0,5);
    VL_SIG(ExUnit__DOT__dec__DOT__opImm,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__opImm_Zx4,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__opImm_Zx8,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__opImm_Sx8,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__opImm_Sx12,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Sx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Zx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm8_Nx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm16_Sx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm20_Sx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImmM12_Sx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImmO12_Sx8E,31,0);
    VL_SIG(ExUnit__DOT__dec__DOT__decXe__DOT__opImm4_ZxXE,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regPr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regSGr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regFpul,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regFpScr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regSr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGbr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regVbr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regSSr,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regSPc,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regPc,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regSp,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR0A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR1A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR2A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR3A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR4A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR5A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR6A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR7A,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR0B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR1B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR2B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR3B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR4B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR5B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR6B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR7B,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR8,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR9,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR10,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR11,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR12,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR13,31,0);
    VL_SIG(ExUnit__DOT__gpr__DOT__regGprR14,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tRegOutVal,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tMemAddr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tMemData,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tAguRtRi,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tAguRtRiSc,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tAguAddr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutSr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutPr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutPc,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutSp,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlNxtPc,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlBraPc,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlPrPc,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutGbr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutVbr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutSSr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutSPc,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tCtlOutSGr,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tShadValRs,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tMacValRuB_AA,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tMacValRuB_AB,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tMacValRuB_BA,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__tMacValRuB_BB,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__sh32__DOT__tValRol,31,0);
    VL_SIG(ExUnit__DOT__exOp__DOT__sh32__DOT__tValRor,31,0);
    //char	__VpadToAlign1084[4];
    VL_SIG64(ExUnit__DOT__dcfRegInData,63,0);
    VL_SIG64(ExUnit__DOT__regIfPcVal2,47,0);
    VL_SIG64(ExUnit__DOT__regIdPcVal,47,0);
    VL_SIG64(ExUnit__DOT__wbRegFpValO,63,0);
    VL_SIG64(ExUnit__DOT__regExPcVal,47,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData1,63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontData2,63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataAsc1,63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx1,63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__tFontDataGfx2,63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbcc__DOT__tFontData,63,0);
    VL_SIG64(ExUnit__DOT__dcf__DOT__tBlkData2,63,0);
    VL_SIG64(ExUnit__DOT__dcf__DOT__tBlkData2B,63,0);
    VL_SIG64(ExUnit__DOT__dcf__DOT__tBlkData3,63,0);
    VL_SIG64(ExUnit__DOT__dcf__DOT__tRegOutData,63,0);
    VL_SIG64(ExUnit__DOT__dcf__DOT__tRegInData,63,0);
    VL_SIG64(ExUnit__DOT__dcf__DOT__tRegOutDataB,63,0);
    VL_SIG64(ExUnit__DOT__icf__DOT__tRegOutPcVal,47,0);
    VL_SIG64(ExUnit__DOT__gpr__DOT__regMac,63,0);
    VL_SIG64(ExUnit__DOT__exOp__DOT__tCtlOutMac,63,0);
    VL_SIG64(ExUnit__DOT__exOp__DOT__tMacValRs,63,0);
    VL_SIG64(ExUnit__DOT__exOp__DOT__tMacValRu,63,0);
    VL_SIG64(ExUnit__DOT__exOp__DOT__tAluDn1,32,0);
    VL_SIG64(ExUnit__DOT__exOp__DOT__tAluDn2,32,0);
    VL_SIG64(ExUnit__DOT__exOp__DOT__tMacValRsA,63,0);
    VL_SIG8(ExUnit__DOT__txtntmod__DOT__ntsc__DOT__cbPwmTab[32],7,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1A[1024],31,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1B[1024],31,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1C[1024],31,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrCell1D[1024],31,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontMem[256],63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx1Mem[128],63,0);
    VL_SIG64(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__fontGfx2Mem[128],63,0);
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__scrRegCtrl[8],31,0);
    VL_SIG(ExUnit__DOT__dcl2__DOT__memTileA[2048],31,0);
    VL_SIG(ExUnit__DOT__dcl2__DOT__memTileB[2048],31,0);
    VL_SIG(ExUnit__DOT__dcl2__DOT__memTileC[2048],31,0);
    VL_SIG(ExUnit__DOT__dcl2__DOT__memTileD[2048],31,0);
    VL_SIGW(ExUnit__DOT__dcl2__DOT__romTile[256],127,0,4);
    VL_SIG(ExUnit__DOT__dcf__DOT__icBlkA[256],31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__icBlkB[256],31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__icBlkC[256],31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__icBlkD[256],31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__icBlkE[256],31,0);
    VL_SIG(ExUnit__DOT__dcf__DOT__icBlkAd[256],27,0);
    VL_SIG8(ExUnit__DOT__dcf__DOT__icBlkFl[256],3,0);
    VL_SIG(ExUnit__DOT__icf__DOT__icBlkA[256],31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__icBlkB[256],31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__icBlkC[256],31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__icBlkD[256],31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__icBlkE[256],31,0);
    VL_SIG(ExUnit__DOT__icf__DOT__icBlkAd[256],27,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    //char	__VpadToAlign71245[3];
    VL_SIG(ExUnit__DOT__txtntmod__DOT__fbmem__DOT__busData__out__en0,31,0);
    VL_SIG(__Vchglast__TOP__ExUnit__DOT__exOp__DOT__tCtlOutPc,31,0);
    VL_SIG(__Vchglast__TOP__ExUnit__DOT__exOp__DOT__sh32__DOT__tValRn,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VExUnit__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VExUnit& operator= (const VExUnit&);	///< Copying not allowed
    VExUnit(const VExUnit&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VExUnit(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VExUnit();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VExUnit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VExUnit__Syms* symsp, bool first);
  private:
    static QData	_change_request(VExUnit__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__6(VExUnit__Syms* __restrict vlSymsp);
    static void	_combo__TOP__8(VExUnit__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(VExUnit__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(VExUnit__Syms* __restrict vlSymsp);
    static void	_eval_initial(VExUnit__Syms* __restrict vlSymsp);
    static void	_eval_settle(VExUnit__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(VExUnit__Syms* __restrict vlSymsp);
    static void	_initial__TOP__3(VExUnit__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(VExUnit__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(VExUnit__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(VExUnit__Syms* __restrict vlSymsp);
    static void	_settle__TOP__7(VExUnit__Syms* __restrict vlSymsp);
    static void	_settle__TOP__9(VExUnit__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
