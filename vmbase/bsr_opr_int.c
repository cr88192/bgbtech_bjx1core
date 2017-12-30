void BTESR_Op_ADD_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i+j;
}

void BTESR_Op_ADD_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=i+op->imm;
}

void BTESR_Op_ADD_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i+j;
}

void BTESR_Op_SUB_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i-j;
}

void BTESR_Op_SUB_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=i-op->imm;
}

void BTESR_Op_SUB_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i-j;
}

void BTESR_Op_MUL_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i*j;
}

void BTESR_Op_MUL_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=op->imm;
	cpu->regs[op->rn]=i*j;
}

void BTESR_Op_MUL_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i*j;
}

void BTESR_Op_ADD_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i+j;
}

void BTESR_Op_SUB_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i-j;
}

void BTESR_Op_MUL_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i*j;
}

void BTESR_Op_ADDQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i+j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_ADDQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	
	i=btesr_getregu64(cpu, op->rn);
	j=op->imm;
	k=i+j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_ADDQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i+j;
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_SUBQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i-j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SUBQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i-j;
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_MULQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i*j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_MULQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=op->imm;
	k=i*j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_MULQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i*j;
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_SHLQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregs32(cpu, op->rm);
	k=i<<((byte)j);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SHRQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregs32(cpu, op->rm);
	k=i>>((byte)j);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SARQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregs32(cpu, op->rm);
	k=((s64)i)>>((byte)j);
	btesr_setregu64(cpu, op->rn, k);
}


void BTESR_Op_CMPEQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=op->imm;
	s=cpu->regs[BTESR_REG_SR];
	k=(i==j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHS_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=op->imm;
	s=cpu->regs[BTESR_REG_SR];
	k=(i>=j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGE_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=op->imm;
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>=((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHI_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=op->imm;
	s=cpu->regs[BTESR_REG_SR];
	k=(i>j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGT_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=op->imm;
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}


void BTESR_Op_CMPEQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	s=cpu->regs[BTESR_REG_SR];
	k=(i==j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHS_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	s=cpu->regs[BTESR_REG_SR];
	k=(i>=j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGE_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>=((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHI_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	s=cpu->regs[BTESR_REG_SR];
	k=(i>j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGT_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPPL_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPPZ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>=0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPZ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;
	i=cpu->regs[op->rn];
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)==0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPPLQ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPPZQ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>=0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPZQ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)==0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPZP_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregaddr(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)==0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}


void BTESR_Op_CMPEQP_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;
	u32 k, s;
	i=btesr_getregaddr(cpu, op->rn);
	j=btesr_getregaddr(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(i==j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHSP_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;
	u32 k, s;
	i=btesr_getregaddr(cpu, op->rn);
	j=btesr_getregaddr(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(i>=j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGEP_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;
	u32 k, s;
	i=btesr_getregaddr(cpu, op->rn);
	j=btesr_getregaddr(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>=((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHIP_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;
	u32 k, s;
	i=btesr_getregaddr(cpu, op->rn);
	j=btesr_getregaddr(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(i>j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGTP_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;
	u32 k, s;
	i=btesr_getregaddr(cpu, op->rn);
	j=btesr_getregaddr(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}


void BTESR_Op_CMPEQQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(i==j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHSQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(i>=j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGEQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>=((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPHIQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(i>j);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGTQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(((s32)i)>((s32)j));
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}


#if 0
void BTESR_Op_EXTSB_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rm];
	k=(sbyte)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTSW_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rm];
	k=(s16)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTUB_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rm];
	k=(byte)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTUW_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rm];
	k=(u16)i;
	cpu->regs[op->rn]=k;
}


void BTESR_Op_NEG_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rm];
	k=0-i;
	cpu->regs[op->rn]=k;
}
#endif


void BTESR_Op_EXTSB_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rn];
	k=(sbyte)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTSW_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rn];
	k=(s16)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTUB_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rn];
	k=(byte)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTUW_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rn];
	k=(u16)i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_EXTSI_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, k;
	i=cpu->regs[op->rn];
	k=(s32)i;
	cpu->regs[op->rn]=k;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_EXTUI_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, k;
	i=cpu->regs[op->rn];
	k=(u32)i;
	cpu->regs[op->rn]=k;
	btesr_setregu64(cpu, op->rn, k);
}


void BTESR_Op_NEG_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, k;
	i=cpu->regs[op->rn];
	k=0-i;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_NEGQ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, k;
	i=btesr_getregu64(cpu, op->rn);
	k=0-i;
	btesr_setregu64(cpu, op->rn, k);
}


void BTESR_Op_AND_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i&j;
}

void BTESR_Op_AND_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=i&op->imm;
}

void BTESR_Op_AND_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i&j;
}

void BTESR_Op_AND_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i&j;
}

void BTESR_Op_ANDQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i&j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_ANDQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=op->imm;
	k=i&j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_ANDQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i&j;
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_NOT_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i;
	i=cpu->regs[op->rm];
	cpu->regs[op->rn]=~i;
}

void BTESR_Op_NOT_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=~i;
}

void BTESR_Op_NOTQ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, k;
	i=btesr_getregu64(cpu, op->rn);
	k=~i;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_LNTI_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=!i;
}

void BTESR_Op_LNTQ_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=btesr_getregu64(cpu, op->rn);
	cpu->regs[op->rn]=(i==0);
}

void BTESR_Op_STTI_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i;
	i=cpu->regs[BTESR_REG_SR];
	cpu->regs[op->rn]=(i&1);
}

void BTESR_Op_STNTI_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i;
	i=cpu->regs[BTESR_REG_SR];
	cpu->regs[op->rn]=!(i&1);
}

void BTESR_Op_OR_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i|j;
}

void BTESR_Op_OR_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=i|op->imm;
}

void BTESR_Op_OR_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i|j;
}

void BTESR_Op_OR_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i|j;
}

void BTESR_Op_ORQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i|j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_ORQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=op->imm;
	k=i|j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_ORQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i|j;
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_TST_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;

	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	k=!(i&j);

	s=cpu->regs[BTESR_REG_SR];
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_TST_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k, s;

	i=cpu->regs[op->rn];
	j=op->imm;
	k=!(i&j);

	s=cpu->regs[BTESR_REG_SR];
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_TSTQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;

	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=!(i&j);

	s=cpu->regs[BTESR_REG_SR];
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_TSTQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	u32 k, s;

	i=btesr_getregu64(cpu, op->rn);
	j=op->imm;
	k=!(i&j);

	s=cpu->regs[BTESR_REG_SR];
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_XOR_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i^j;
}

void BTESR_Op_XOR_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	cpu->regs[op->rn]=i^op->imm;
}

void BTESR_Op_XOR_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i^j;
}

void BTESR_Op_XOR_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i^j;
}

void BTESR_Op_XORQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i^j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_XORQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=op->imm;
	k=i^j;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_XORQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i^j;
	btesr_setregu64(cpu, op->ro, k);
}


void BTESR_Op_SHL_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i<<((int)j);
}

void BTESR_Op_SHR_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=i>>((int)j);
}

void BTESR_Op_SAR_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->rn]=((s32)i)>>((int)j);
}

void BTESR_Op_SHL_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=op->imm;
	cpu->regs[op->rn]=i<<((int)j);
}

void BTESR_Op_SHR_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=op->imm;
	cpu->regs[op->rn]=i>>((int)j);
}

void BTESR_Op_SAR_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=op->imm;
	cpu->regs[op->rn]=((s32)i)>>((int)j);
}


void BTESR_Op_SHL_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i<<j;
}

void BTESR_Op_SHL_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i<<j;
}

void BTESR_Op_SHR_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=i>>j;
}

void BTESR_Op_SHR_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=i>>j;
}

void BTESR_Op_SAR_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	cpu->regs[op->ro]=((s32)i)>>j;
}

void BTESR_Op_SAR_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	j=op->imm;
	cpu->regs[op->rn]=((s32)i)>>j;
}



void BTESR_Op_SHLQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i<<((byte)j);
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_SHLQ_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rm);
	j=op->imm;
	k=i<<((byte)j);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SHRQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=i>>((byte)j);
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_SHRQ_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rm);
	j=op->imm;
	k=i>>((byte)j);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SARQ_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=((s64)i)>>((byte)j);
	btesr_setregu64(cpu, op->ro, k);
}

void BTESR_Op_SARQ_RegRegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rm);
	j=op->imm;
	k=((s64)i)>>((byte)j);
	btesr_setregu64(cpu, op->rn, k);
}


void BTESR_Op_UDIV_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	k=j?(i/j):0;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_SDIV_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	s32 i, j, k;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	k=j?(i/j):0;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_UMOD_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j, k;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	k=j?(i%j):0;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_SMOD_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	s32 i, j, k;
	i=cpu->regs[op->rn];
	j=cpu->regs[op->rm];
	k=j?(i%j):0;
	cpu->regs[op->rn]=k;
}

void BTESR_Op_UDIVQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=j?(i/j):0;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SDIVQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	s64 i, j, k;
	i=btesr_getregs64(cpu, op->rn);
	j=btesr_getregs64(cpu, op->rm);
	k=j?(i/j):0;
	btesr_setregs64(cpu, op->rn, k);
}

void BTESR_Op_UMODQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j, k;
	i=btesr_getregu64(cpu, op->rn);
	j=btesr_getregu64(cpu, op->rm);
	k=j?(i%j):0;
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_SMODQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	s64 i, j, k;
	i=btesr_getregs64(cpu, op->rn);
	j=btesr_getregs64(cpu, op->rm);
	k=j?(i%j):0;
	btesr_setregs64(cpu, op->rn, k);
}
