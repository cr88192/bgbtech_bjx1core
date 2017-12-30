void BTESR_Op_JMP_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=btesr_getregu64(cpu, op->rm);
	btesr_setregu64(cpu, BTESR_REG_PC, i);
	cpu->trnext=NULL;
}

void BTESR_Op_JSR_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;

//	i=btesr_getregu64(cpu, op->rm);
	i=op->pc+2;
	btesr_setregu64(cpu, BTESR_REG_LR, i);

	i=btesr_getregu64(cpu, op->rm);
	btesr_setregu64(cpu, BTESR_REG_PC, i);
	cpu->trnext=NULL;
}

void BTESR_Op_JMPF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=btesr_getregu64(cpu, op->rm);
	i=op->pc+2+i;
	btesr_setregu64(cpu, BTESR_REG_PC, i);
	cpu->trnext=NULL;
}

void BTESR_Op_JSRF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;

//	i=btesr_getregu64(cpu, op->rm);
	i=op->pc+2;
	btesr_setregu64(cpu, BTESR_REG_LR, i);

	i=btesr_getregu64(cpu, op->rm);
	i=op->pc+2+i;
	btesr_setregu64(cpu, BTESR_REG_PC, i);
	cpu->trnext=NULL;
}

void BTESR_Op_BRA_Abs(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	btesr_setregaddr(cpu, BTESR_REG_PC, op->imm);
	cpu->trnext=NULL;
}

void BTESR_Op_BRT_Abs(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	if(cpu->regs[BTESR_REG_SR]&1)
	{
		btesr_setregaddr(cpu, BTESR_REG_PC, op->imm);
		cpu->trnext=NULL;
	}
}

void BTESR_Op_BRF_Abs(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	if(!(cpu->regs[BTESR_REG_SR]&1))
	{
		btesr_setregaddr(cpu, BTESR_REG_PC, op->imm);
		cpu->trnext=NULL;
	}
}


void BTESR_Op_TRAP_UD(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	cpu->status=BTESR_EXC_UDINST;
	cpu->trnext=NULL;
}

void BTESR_Op_NOP_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
}

void BTESR_Op_RTS_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=btesr_getregu64(cpu, BTESR_REG_LR);
	btesr_setregu64(cpu, BTESR_REG_PC, i);
	cpu->trnext=NULL;
}

void BTESR_Op_SLEEP_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	cpu->status=BTESR_EXC_TRAPSLEEP;
	cpu->trnext=NULL;
}

void BTESR_Op_RTE_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;

	i=btesr_getregu64(cpu, BTESR_REG_ISSP);
	btesr_setregu64(cpu, BTESR_REG_SP, i);

	i=btesr_getregu64(cpu, BTESR_REG_ISSR);
	btesr_setregu64(cpu, BTESR_REG_SR, i);

	i=btesr_getregu64(cpu, BTESR_REG_ISPC);
	btesr_setregu64(cpu, BTESR_REG_PC, i);

	cpu->trnext=NULL;
}

void BTESR_Op_BREAK_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	cpu->status=BTESR_EXC_TRAPBREAK;
	cpu->trnext=NULL;
}

void BTESR_Op_SYNCO_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
}

void BTESR_Op_SYNCI_Z(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	if(!cpu->jit_needflush)
		cpu->jit_needflush=1;
}


void BTESR_Op_BRAOT_Imm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;
	i=btesr_getregaddr(cpu, BTESR_REG_OT);
	j=BTESR_GetAddrQWord(cpu, i+op->imm);
	btesr_setregaddr(cpu, BTESR_REG_PC, j);
	cpu->trnext=NULL;
}

void BTESR_Op_BSROT_Imm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;

//	i=btesr_getregu64(cpu, op->rm);
	i=op->pc+2;
	btesr_setregaddr(cpu, BTESR_REG_LR, i);

	i=btesr_getregaddr(cpu, BTESR_REG_OT);
	j=BTESR_GetAddrQWord(cpu, i+op->imm);
	btesr_setregaddr(cpu, BTESR_REG_PC, j);
	cpu->trnext=NULL;
}
