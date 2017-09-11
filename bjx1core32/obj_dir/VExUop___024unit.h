// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VExUop.h for the primary calling header

#ifndef _VExUop___024unit_H_
#define _VExUop___024unit_H_

#include "verilated_heavy.h"
class VExUop__Syms;

//----------

VL_MODULE(VExUop___024unit) {
  public:
    // CELLS
    
    // PORTS
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    //char	__VpadToAlign12[4];
    VExUop__Syms*	__VlSymsp;		// Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VExUop___024unit& operator= (const VExUop___024unit&);	///< Copying not allowed
    VExUop___024unit(const VExUop___024unit&);	///< Copying not allowed
  public:
    VExUop___024unit(const char* name="TOP");
    ~VExUop___024unit();
    
    // USER METHODS
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VExUop__Syms* symsp, bool first);
  private:
    void	_configure_coverage(VExUop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
