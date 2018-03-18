// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VExUnit.h for the primary calling header

#ifndef _VExUnit___024unit_H_
#define _VExUnit___024unit_H_

#include "verilated_heavy.h"
class VExUnit__Syms;

//----------

VL_MODULE(VExUnit___024unit) {
  public:
    // CELLS
    
    // PORTS
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    //char	__VpadToAlign12[4];
    VExUnit__Syms*	__VlSymsp;		// Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VExUnit___024unit& operator= (const VExUnit___024unit&);	///< Copying not allowed
    VExUnit___024unit(const VExUnit___024unit&);	///< Copying not allowed
  public:
    VExUnit___024unit(const char* name="TOP");
    ~VExUnit___024unit();
    
    // USER METHODS
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VExUnit__Syms* symsp, bool first);
  private:
    void	_configure_coverage(VExUnit__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
