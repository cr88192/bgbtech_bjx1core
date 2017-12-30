#ifdef LITTLEENDIAN

force_inline u64 btesr_getregu64(BTESR_CpuState *cpu, int rm)
	{ return(*(u64 *)(cpu->regs+rm)); }
force_inline void btesr_setregu64(BTESR_CpuState *cpu, int rm, u64 val)
	{ *(u64 *)(cpu->regs+rm)=val; }

force_inline s64 btesr_getregs64(BTESR_CpuState *cpu, int rm)
	{ return(*(s64 *)(cpu->regs+rm)); }
force_inline void btesr_setregs64(BTESR_CpuState *cpu, int rm, s64 val)
	{ *(s64 *)(cpu->regs+rm)=val; }

force_inline s64 btesr_getregaddr(BTESR_CpuState *cpu, int rm)
	{ return((s64)btesr_getregu64(cpu, rm)); }

force_inline f64 btesr_getregreal(BTESR_CpuState *cpu, int rm)
	{ return(*(f64 *)(cpu->regs+rm)); }
force_inline void btesr_setregreal(BTESR_CpuState *cpu, int rm, f64 val)
	{ *(f64 *)(cpu->regs+rm)=val; }

force_inline s32 btesr_getregs32(BTESR_CpuState *cpu, int rm)
	{ return(*(s32 *)(cpu->regs+rm)); }
force_inline void btesr_setregs32(BTESR_CpuState *cpu, int rm, s32 val)
	{ *(s32 *)(cpu->regs+rm)=val; }

#else

force_inline u64 btesr_getregu64(BTESR_CpuState *cpu, int rm)
{
	return(cpu->regs[rm+BTESR_REG_RLO]|
		((u64)cpu->regs[rm+BTESR_REG_RHI]<<32));
}

force_inline s64 btesr_getregs64(BTESR_CpuState *cpu, int rm)
	{ return((s64)btesr_getregu64(cpu, rm)); }

force_inline void btesr_setregu64(BTESR_CpuState *cpu, int rn, u64 val)
{
	cpu->regs[rn+BTESR_REG_RLO]=val;
	cpu->regs[rn+BTESR_REG_RHI]=val>>32;
}

force_inline void btesr_setregs64(BTESR_CpuState *cpu, int rn, s64 val)
	{ btesr_setregu64(cpu, rn, (u64)val); }

#endif

int BTESR_GetAddrByte(BTESR_CpuState *cpu, btesr_addr addr)
	{ return(cpu->GetAddrByte(cpu, addr)); }
int BTESR_GetAddrWord(BTESR_CpuState *cpu, btesr_addr addr)
	{ return(cpu->GetAddrWord(cpu, addr)); }
u32 BTESR_GetAddrDWord(BTESR_CpuState *cpu, btesr_addr addr)
	{ return(cpu->GetAddrDWord(cpu, addr)); }
u64 BTESR_GetAddrQWord(BTESR_CpuState *cpu, btesr_addr addr)
	{ return(cpu->GetAddrQWord(cpu, addr)); }

int BTESR_SetAddrByte(BTESR_CpuState *cpu, btesr_addr addr, int val)
	{ return(cpu->SetAddrByte(cpu, addr, val)); }
int BTESR_SetAddrWord(BTESR_CpuState *cpu, btesr_addr addr, int val)
	{ return(cpu->SetAddrWord(cpu, addr, val)); }
int BTESR_SetAddrDWord(BTESR_CpuState *cpu, btesr_addr addr, u32 val)
	{ return(cpu->SetAddrDWord(cpu, addr, val)); }
int BTESR_SetAddrQWord(BTESR_CpuState *cpu, btesr_addr addr, u64 val)
	{ return(cpu->SetAddrQWord(cpu, addr, val)); }

int btesr_mkgpr(BTESR_CpuState *cpu, int rn)
{
	return(BTESR_REG_R0+(rn<<1));
}

int btesr_mkfpr(BTESR_CpuState *cpu, int rn)
{
	return(BTESR_REG_F0+(rn<<1));
}

int btesr_mkcnr(BTESR_CpuState *cpu, int rn)
{
	return(BTESR_REG_C0+(rn<<1));
}

BTESR_Opcode *BTESR_AllocOpcode(BTESR_CpuState *cpu)
{
	BTESR_Opcode *tmp, *tblk;
	int i;
	
	tmp=cpu->free_ops;
	if(tmp)
	{
		cpu->free_ops=*(BTESR_Opcode **)tmp;
		memset(tmp, 0, sizeof(BTESR_Opcode));
		return(tmp);
	}
	
	tblk=malloc(256*sizeof(BTESR_Opcode));
	tmp=tblk;
	
	for(i=0; i<255; i++)
	{
		*(BTESR_Opcode **)tmp=cpu->free_ops;
		cpu->free_ops=tmp;
		tmp++;
	}

	memset(tmp, 0, sizeof(BTESR_Opcode));
	return(tmp);
}

BTESR_Trace *BTESR_AllocTrace(BTESR_CpuState *cpu)
{
	BTESR_Trace *tmp, *tblk;
	int i;
	
	tmp=cpu->free_tr;
	if(tmp)
	{
		cpu->free_tr=*(BTESR_Trace **)tmp;
		memset(tmp, 0, sizeof(BTESR_Trace));
		return(tmp);
	}
	
	tblk=malloc(256*sizeof(BTESR_Trace));
	tmp=tblk;
	
	for(i=0; i<255; i++)
	{
		*(BTESR_Trace **)tmp=cpu->free_tr;
		cpu->free_tr=tmp;
		tmp++;
	}

	memset(tmp, 0, sizeof(BTESR_Trace));
	return(tmp);
}

void BTESR_FreeOpcode(BTESR_CpuState *cpu, BTESR_Opcode *tmp)
{
	*(BTESR_Opcode **)tmp=cpu->free_ops;
	cpu->free_ops=tmp;
}

void BTESR_FreeTrace(BTESR_CpuState *cpu, BTESR_Trace *tmp)
{
	*(BTESR_Trace **)tmp=cpu->free_tr;
	cpu->free_tr=tmp;
}
