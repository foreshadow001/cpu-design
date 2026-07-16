// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMINIRV_SOC__SYMS_H_
#define VERILATED_VMINIRV_SOC__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VminiRV_SoC.h"

// INCLUDE MODULE CLASSES
#include "VminiRV_SoC___024root.h"
#include "VminiRV_SoC_miniRV_SoC.h"
#include "VminiRV_SoC_cpu_top.h"
#include "VminiRV_SoC_Inst_ROM.h"
#include "VminiRV_SoC_cpu_core.h"
#include "VminiRV_SoC_ALU.h"
#include "VminiRV_SoC_IROM.h"
#include "VminiRV_SoC_multiplier.h"
#include "VminiRV_SoC_multiplier__W21.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VminiRV_SoC* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VminiRV_SoC___024root          TOP;
    VminiRV_SoC_miniRV_SoC         TOP__miniRV_SoC;
    VminiRV_SoC_cpu_top            TOP__miniRV_SoC__U_cpu;
    VminiRV_SoC_cpu_core           TOP__miniRV_SoC__U_cpu__U_core;
    VminiRV_SoC_ALU                TOP__miniRV_SoC__U_cpu__U_core__U_ALU;
    VminiRV_SoC_multiplier         TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mul;
    VminiRV_SoC_multiplier__W21    TOP__miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu;
    VminiRV_SoC_Inst_ROM           TOP__miniRV_SoC__U_cpu__U_irom;
    VminiRV_SoC_IROM               TOP__miniRV_SoC__U_cpu__U_irom__U_irom;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_miniRV_SoC__U_cpu__U_core;
    VerilatedScope* __Vscopep_miniRV_SoC__U_cpu__U_core__U_ALU;
    VerilatedScope* __Vscopep_miniRV_SoC__U_cpu__U_core__U_ALU__U_mul;
    VerilatedScope* __Vscopep_miniRV_SoC__U_cpu__U_core__U_ALU__U_mulu;
    VerilatedScope* __Vscopep_miniRV_SoC__U_cpu__U_dram__U_dram;
    VerilatedScope* __Vscopep_miniRV_SoC__U_cpu__U_irom__U_irom;

    // CONSTRUCTORS
    VminiRV_SoC__Syms(VerilatedContext* contextp, const char* namep, VminiRV_SoC* modelp);
    ~VminiRV_SoC__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
