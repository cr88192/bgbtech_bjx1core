#define BTESR_REG_RLO	0x00
#define BTESR_REG_RHI	0x01

#define BTESR_REG_R0		0x00
#define BTESR_REG_R1 		0x02
#define BTESR_REG_R2		0x04
#define BTESR_REG_R3		0x06
#define BTESR_REG_R4		0x08
#define BTESR_REG_R5		0x0A
#define BTESR_REG_R6		0x0C
#define BTESR_REG_R7		0x0E
#define BTESR_REG_R8		0x10
#define BTESR_REG_R9		0x12
#define BTESR_REG_R10		0x14
#define BTESR_REG_R11		0x16
#define BTESR_REG_R12		0x18
#define BTESR_REG_R13		0x1A
#define BTESR_REG_R14		0x1C
#define BTESR_REG_R15		0x1E

#define BTESR_REG_C0		0x20
#define BTESR_REG_C1 		0x22
#define BTESR_REG_C2		0x24
#define BTESR_REG_C3		0x26
#define BTESR_REG_C4		0x28
#define BTESR_REG_C5		0x2A
#define BTESR_REG_C6		0x2C
#define BTESR_REG_C7		0x2E
#define BTESR_REG_C8		0x30
#define BTESR_REG_C9		0x32
#define BTESR_REG_C10		0x34
#define BTESR_REG_C11		0x36
#define BTESR_REG_C12		0x38
#define BTESR_REG_C13		0x3A
#define BTESR_REG_C14		0x3C
#define BTESR_REG_C15		0x3E

#define BTESR_REG_F0		0x40
#define BTESR_REG_F1 		0x42
#define BTESR_REG_F2		0x44
#define BTESR_REG_F3		0x46
#define BTESR_REG_F4		0x48
#define BTESR_REG_F5		0x4A
#define BTESR_REG_F6		0x4C
#define BTESR_REG_F7		0x4E
#define BTESR_REG_F8		0x50
#define BTESR_REG_F9		0x52
#define BTESR_REG_F10		0x54
#define BTESR_REG_F11		0x56
#define BTESR_REG_F12		0x58
#define BTESR_REG_F13		0x5A
#define BTESR_REG_F14		0x5C
#define BTESR_REG_F15		0x5E

#define BTESR_REG_F16		0x60
#define BTESR_REG_F17 		0x62
#define BTESR_REG_F18		0x64
#define BTESR_REG_F19		0x66
#define BTESR_REG_F20		0x68
#define BTESR_REG_F21		0x6A
#define BTESR_REG_F22		0x6C
#define BTESR_REG_F23		0x6E
#define BTESR_REG_F24		0x70
#define BTESR_REG_F25		0x72
#define BTESR_REG_F26		0x74
#define BTESR_REG_F27		0x76
#define BTESR_REG_F28		0x78
#define BTESR_REG_F29		0x7A
#define BTESR_REG_F30		0x7C
#define BTESR_REG_F31		0x7E

#define BTESR_REG_C16		0x80
#define BTESR_REG_C17 		0x82
#define BTESR_REG_C18		0x84
#define BTESR_REG_C19		0x86
#define BTESR_REG_C20		0x88
#define BTESR_REG_C21		0x8A
#define BTESR_REG_C22		0x8C
#define BTESR_REG_C23		0x8E
#define BTESR_REG_C24		0x90
#define BTESR_REG_C25		0x92
#define BTESR_REG_C26		0x94
#define BTESR_REG_C27		0x96
#define BTESR_REG_C28		0x98
#define BTESR_REG_C29		0x9A
#define BTESR_REG_C30		0x9C
#define BTESR_REG_C31		0x9E

#define BTESR_REG_ZZR		0xFE

#define BTESR_REG_LR		BTESR_REG_C0
#define BTESR_REG_SP		BTESR_REG_C1
#define BTESR_REG_PC		BTESR_REG_C2
#define BTESR_REG_SR		BTESR_REG_C3
#define BTESR_REG_CT		BTESR_REG_C4
#define BTESR_REG_OT		BTESR_REG_C5
#define BTESR_REG_TIB1		BTESR_REG_C6
#define BTESR_REG_TIB2		BTESR_REG_C7

#define BTESR_REG_IVBR		BTESR_REG_C16
#define BTESR_REG_IVNR		BTESR_REG_C17
#define BTESR_REG_ISPC		BTESR_REG_C18
#define BTESR_REG_ISSP		BTESR_REG_C19
#define BTESR_REG_ISSR		BTESR_REG_C20

#define BTESR_NMID_INVALID	0x00
#define BTESR_NMID_ADDI		0x01
#define BTESR_NMID_SUBI		0x02
#define BTESR_NMID_MULI		0x03
#define BTESR_NMID_ANDI		0x04
#define BTESR_NMID_ORI		0x05
#define BTESR_NMID_XORI		0x06
#define BTESR_NMID_SHLI		0x07
#define BTESR_NMID_SARI		0x08
#define BTESR_NMID_SHRI		0x09
#define BTESR_NMID_SDIVI	0x0A
#define BTESR_NMID_UDIVI	0x0B
#define BTESR_NMID_UMODI	0x0C
#define BTESR_NMID_SMODI	0x0D
#define BTESR_NMID_TSTI		0x0E
#define BTESR_NMID_NEGI		0x0F
#define BTESR_NMID_NOTI		0x10
#define BTESR_NMID_ADDQ		0x11
#define BTESR_NMID_SUBQ		0x12
#define BTESR_NMID_MULQ		0x13
#define BTESR_NMID_ANDQ		0x14
#define BTESR_NMID_ORQ		0x15
#define BTESR_NMID_XORQ		0x16
#define BTESR_NMID_SHLQ		0x17
#define BTESR_NMID_SARQ		0x18
#define BTESR_NMID_SHRQ		0x19
#define BTESR_NMID_SDIVQ	0x1A
#define BTESR_NMID_UDIVQ	0x1B
#define BTESR_NMID_UMODQ	0x1C
#define BTESR_NMID_SMODQ	0x1D
#define BTESR_NMID_TSTQ		0x1E
#define BTESR_NMID_NEGQ		0x1F
#define BTESR_NMID_NOTQ		0x20
#define BTESR_NMID_ADDF		0x21
#define BTESR_NMID_SUBF		0x22
#define BTESR_NMID_MULF		0x23
#define BTESR_NMID_DIVF		0x24
#define BTESR_NMID_NEGF		0x25
#define BTESR_NMID_ABSF		0x26
#define BTESR_NMID_SQRTF	0x27
#define BTESR_NMID_PUSHI	0x28
#define BTESR_NMID_PUSHF	0x29
#define BTESR_NMID_PUSHQ	0x2A
#define BTESR_NMID_PUSHV	0x2B
#define BTESR_NMID_POPI		0x2C
#define BTESR_NMID_POPF		0x2D
#define BTESR_NMID_POPQ		0x2E
#define BTESR_NMID_POPV		0x2F
#define BTESR_NMID_CMPEQI	0x30
#define BTESR_NMID_CMPGTI	0x31
#define BTESR_NMID_CMPGEI	0x32
#define BTESR_NMID_CMPHII	0x33
#define BTESR_NMID_CMPHSI	0x34
#define BTESR_NMID_CMPPLI	0x35
#define BTESR_NMID_CMPPZI	0x36
#define BTESR_NMID_CMPZI	0x37
#define BTESR_NMID_CMPEQQ	0x38
#define BTESR_NMID_CMPGTQ	0x39
#define BTESR_NMID_CMPGEQ	0x3A
#define BTESR_NMID_CMPHIQ	0x3B
#define BTESR_NMID_CMPHSQ	0x3C
#define BTESR_NMID_CMPPLQ	0x3D
#define BTESR_NMID_CMPPZQ	0x3E
#define BTESR_NMID_CMPZQ	0x3F
#define BTESR_NMID_CMPEQF	0x40
#define BTESR_NMID_CMPGTF	0x41
#define BTESR_NMID_CMPGEF	0x42
#define BTESR_NMID_CMPPLF	0x44
#define BTESR_NMID_CMPPZF	0x45
#define BTESR_NMID_CMPZF	0x46
#define BTESR_NMID_CMPZP	0x47
#define BTESR_NMID_NOP		0x48
#define BTESR_NMID_RTS		0x49
#define BTESR_NMID_SLEEP	0x4A
#define BTESR_NMID_RTE		0x4B
#define BTESR_NMID_BREAK	0x4C
#define BTESR_NMID_SYNCO	0x4D
#define BTESR_NMID_SYNCI	0x4E
#define BTESR_NMID_LABEL	0x4F
#define BTESR_NMID_DIFFPB	0x50
#define BTESR_NMID_DIFFPW	0x51
#define BTESR_NMID_DIFFPI	0x52
#define BTESR_NMID_DIFFPQ	0x53
#define BTESR_NMID_CMPEQP	0x54
#define BTESR_NMID_CMPGTP	0x55
#define BTESR_NMID_CMPGEP	0x56
#define BTESR_NMID_LDCT		0x57
#define BTESR_NMID_MOVB		0x58
#define BTESR_NMID_MOVW		0x59
#define BTESR_NMID_MOVI		0x5A
#define BTESR_NMID_MOVQ		0x5B
#define BTESR_NMID_MOVF		0x5C
#define BTESR_NMID_MOVD		0x5D
#define BTESR_NMID_BRAOT	0x5E
#define BTESR_NMID_BSROT	0x5F
#define BTESR_NMID_LEAB		0x60
#define BTESR_NMID_LEAW		0x61
#define BTESR_NMID_LEAI		0x62
#define BTESR_NMID_LEAQ		0x63
#define BTESR_NMID_LDC8I	0x64
#define BTESR_NMID_LDCTI	0x65
#define BTESR_NMID_BRT		0x66
#define BTESR_NMID_BRF		0x67
#define BTESR_NMID_LDOTQ	0x68
#define BTESR_NMID_LDCTQ	0x69
#define BTESR_NMID_LDCTF	0x6A
#define BTESR_NMID_LDCTD	0x6B
#define BTESR_NMID_LDSPQ	0x6C
#define BTESR_NMID_STSPQ	0x6D
#define BTESR_NMID_LDSPF	0x6E
#define BTESR_NMID_STSPF	0x6F
#define BTESR_NMID_SHLI1	0x70
#define BTESR_NMID_SHLI2	0x71
#define BTESR_NMID_SARI1	0x72
#define BTESR_NMID_SARI2	0x73
#define BTESR_NMID_BRA		0x74
#define BTESR_NMID_JMP		0x75
#define BTESR_NMID_PUSHC	0x76
#define BTESR_NMID_POPC		0x77
#define BTESR_NMID_INCI		0x78
#define BTESR_NMID_DECI		0x79
#define BTESR_NMID_PUSHNN	0x7A
#define BTESR_NMID_POPNN	0x7B
#define BTESR_NMID_JMPF		0x7C
#define BTESR_NMID_JSRF		0x7D
#define BTESR_NMID_JSR		0x7E
#define BTESR_NMID_BSR		0x7F
#define BTESR_NMID_CVTI2F	0x80
#define BTESR_NMID_CVTF2I	0x81
#define BTESR_NMID_LDCR		0x82
#define BTESR_NMID_STCR		0x83
#define BTESR_NMID_BT		0x84
#define BTESR_NMID_BF		0x85
#define BTESR_NMID_EXTSI	0x86
#define BTESR_NMID_EXTUI	0x87
#define BTESR_NMID_EXTSB	0x88
#define BTESR_NMID_EXTUB	0x89
#define BTESR_NMID_EXTSW	0x8A
#define BTESR_NMID_EXTUW	0x8B
#define BTESR_NMID_LNTI		0x8C
#define BTESR_NMID_LNTQ		0x8D
#define BTESR_NMID_STTI		0x8E
#define BTESR_NMID_STNTI	0x8F
#define BTESR_NMID_LDIOI	0x90
#define BTESR_NMID_STIOI	0x91
#define BTESR_NMID_LDIOQ	0x92
#define BTESR_NMID_STIOQ	0x93
#define BTESR_NMID_MOVV		0x94
#define BTESR_NMID_LEAV		0x95
#define BTESR_NMID_LDC20I	0x96

#define BTESR_FMID_UNK				0x00	//<Unknown>
#define BTESR_FMID_NONE				0x01	//<None>
#define BTESR_FMID_REGREG			0x02	//Rn, Rm
#define BTESR_FMID_REGIMM			0x03	//Rn, Imm
#define BTESR_FMID_REGRM			0x04	//Rn
#define BTESR_FMID_REGRN			0x05	//Rm
#define BTESR_FMID_IMM				0x06	//Imm
#define BTESR_FMID_ABS				0x07	//(Imm)
#define BTESR_FMID_REGLDREG			0x08	//Rn, (Rm)
#define BTESR_FMID_STREGREG			0x09	//(Rn), Rm
#define BTESR_FMID_REGLDINCREG		0x0A	//Rn, (Rm+)
#define BTESR_FMID_STINCREGREG		0x0B	//(Rn+), Rm
#define BTESR_FMID_REGLDDECREG		0x0C	//Rn, (Rm-)
#define BTESR_FMID_STDECREGREG		0x0D	//(Rn-), Rm
#define BTESR_FMID_REGLDREGDISP		0x0E	//Rn, (Rm, Disp)
#define BTESR_FMID_STREGDISPREG		0x0F	//(Rn, Disp), Rm
#define BTESR_FMID_REGLDREG2		0x10	//Rn, (Rm, Ro)
#define BTESR_FMID_STREG2REG		0x11	//(Rn, Ro), Rm
#define BTESR_FMID_REGLDREG2DISP	0x12	//Rn, (Rm, Ro, Disp)
#define BTESR_FMID_STREG2DISPREG	0x13	//(Rn, Ro, Disp), Rm
#define BTESR_FMID_REGREGREG		0x14	//Ro, Rn, Rm
#define BTESR_FMID_REGREGIMM		0x15	//Rn, Rm, Imm

#define BTESR_OPFL_CTRLF			0x01	//opcode effects control-flow
#define BTESR_OPFL_FAULT			0x02	//opcode may fault
#define BTESR_OPFL_DLYSLOT			0x04	//delay-slot
#define BTESR_OPFL_INVDLYSLOT		0x08	//invalid in delay-slot
#define BTESR_OPFL_PCADLYSLOTW		0x10	//adjust PC in delay slot (W)
#define BTESR_OPFL_PCADLYSLOTD		0x20	//adjust PC in delay slot (D)
#define BTESR_OPFL_EXTRAWORD		0x40	//uses an extra word

#define BTESR_TRJTFL_ICACHE			0x01
#define BTESR_TRJTFL_JCACHE			0x02
#define BTESR_TRJTFL_LINKED			0x04
#define BTESR_TRJTFL_NOSTOMP_MASK	0x06
#define BTESR_TRJTFL_NOFREE_MASK	0x07


#define BTESR_EXC_POWERON		0x00		//power on
#define BTESR_EXC_STACK1		0x01		//first stack
#define BTESR_EXC_RESET			0x02		//reset
#define BTESR_EXC_STACK2		0x03		//second stack
#define BTESR_EXC_UDINST		0x04		//illegal instruction
#define BTESR_EXC_SLUDINST		0x06		//slot illegal instruction
#define BTESR_EXC_INVADDR		0x09		//invalid address
#define BTESR_EXC_DMAINVADDR	0x0A		//DMAC/DTC address error
#define BTESR_EXC_NMI			0x0B		//NMI
#define BTESR_EXC_UBC			0x0C		//UBC
#define BTESR_EXC_PIT			0x10		//PIT
#define BTESR_EXC_EMAC			0x11		//EMAC interface
#define BTESR_EXC_UART0			0x12		//UART/Console (0)
#define BTESR_EXC_UART2			0x13		//UART/Console (2)
#define BTESR_EXC_GPIO			0x15		//GPIO
#define BTESR_EXC_UART1			0x17		//UART/Console (1)
#define BTESR_EXC_AICCNTDN		0x19		//AIC Countdown

#define BTESR_EXC_TRAPSMC		0x1000		//Trapped Self-Modifying Code
#define BTESR_EXC_TRAPSLEEP		0x1001		//Sleep
#define BTESR_EXC_TRAPBREAK		0x1002		//Sleep



typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef s64 btesr_addr;


#ifndef __cplusplus
#ifndef _BOOL_T
typedef char bool;
#define true 1
#define false 0
#endif
#endif

typedef struct BTESR_Opcode_s BTESR_Opcode;
typedef struct BTESR_Trace_s BTESR_Trace;
typedef struct BTESR_CpuState_s BTESR_CpuState;

struct BTESR_Opcode_s {
u16 opw;				//opcode word
u16 opw2;				//opcode word 2
byte rm;				//register Rm
byte rn;				//register Rn
byte ro;				//register for offsets
byte fl;				//opcode flags
byte nmid;				//name ID (disasm)
byte fmid;				//form ID (disasm)
btesr_addr pc;			//instruction PC value
btesr_addr imm;			//extended immediate or absolute value
void (*Run)(BTESR_CpuState *cpu, BTESR_Opcode *op);
};

#define BTESR_TR_MAXOPS 32

struct BTESR_Trace_s {
BTESR_Opcode *ops[BTESR_TR_MAXOPS];
btesr_addr srcpc;		//source PC for trace
btesr_addr nxtpc;		//next PC
btesr_addr maxpc;		//max PC for trace
btesr_addr jmppc;		//jump PC
byte nops;				//number of ops in trace
byte nwops;				//number of word-ops in trace
byte amiss;
byte csfl;				//control state flags
byte jtrig;				//jit trigger count
byte jtflag;			//JIT flags
byte lnkcnt;			//link ref-count
u32 excnt;				//execution count
BTESR_Trace *(*Run)(BTESR_CpuState *cpu, BTESR_Trace *tr);
BTESR_Trace *trnext;		//next trace to execute
BTESR_Trace *trjmpnext;	//next trace to execute (on a jump)
BTESR_Trace *lnknext;		//next trace in linked traces
};

#define BTESR_TR_HASHSZ		512
#define BTESR_TR_HASHLVL	2

#define BTESR_TR_HASHPR		1048573
#define BTESR_TR_HASHSHR	21

struct BTESR_CpuState_s
{
u32 regs[256];

int status;
byte csfl;
byte jit_needflush;
int tr_dcol;
int tr_dtot;

BTESR_Opcode *free_ops;			//free opcodes
BTESR_Trace *free_tr;			//free traces

BTESR_Trace *trnext;			//next trace to execute
BTESR_Trace *trjmpnext;			//next trace to execute (on a jump)
BTESR_Trace *trlinked[256];		//linked traces

BTESR_Trace *icache[BTESR_TR_HASHSZ*BTESR_TR_HASHLVL];

int (*GetAddrByte)(BTESR_CpuState *cpu, btesr_addr addr);
int (*GetAddrWord)(BTESR_CpuState *cpu, btesr_addr addr);
u32 (*GetAddrDWord)(BTESR_CpuState *cpu, btesr_addr addr);
u64 (*GetAddrQWord)(BTESR_CpuState *cpu, btesr_addr addr);
int (*SetAddrByte)(BTESR_CpuState *cpu, btesr_addr addr, int val);
int (*SetAddrWord)(BTESR_CpuState *cpu, btesr_addr addr, int val);
int (*SetAddrDWord)(BTESR_CpuState *cpu, btesr_addr addr, u32 val);
int (*SetAddrQWord)(BTESR_CpuState *cpu, btesr_addr addr, u64 val);
};

