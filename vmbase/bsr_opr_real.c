void BTESR_Op_ADDF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x+y;
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_SUBF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x-y;
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_MULF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x*y;
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_DIVF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x/y;
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_ADDF_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x+y;
	btesr_setregreal(cpu, op->ro, z);
}

void BTESR_Op_SUBF_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x-y;
	btesr_setregreal(cpu, op->ro, z);
}

void BTESR_Op_MULF_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x*y;
	btesr_setregreal(cpu, op->ro, z);
}

void BTESR_Op_DIVF_RegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	z=x/y;
	btesr_setregreal(cpu, op->ro, z);
}

void BTESR_Op_NEGF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	z=-x;
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_ABSF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	z=(x>=0)?x:(-x);
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_SQRTF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	z=(x>=0)?sqrt(x):(-sqrt(-x));
	btesr_setregreal(cpu, op->rn, z);
}

void BTESR_Op_CVTI2F_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x;
	x=btesr_getregs32(cpu, op->rn);
	btesr_setregreal(cpu, op->rn, x);
}

void BTESR_Op_CVTF2I_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	f64 x;
	x=btesr_getregreal(cpu, op->rn);
	btesr_setregs32(cpu, op->rn, x);
}

void BTESR_Op_CMPEQF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 k, s;
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(x==y);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGTF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 k, s;
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(x>y);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPGEF_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 k, s;
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	y=btesr_getregreal(cpu, op->rm);
	s=cpu->regs[BTESR_REG_SR];
	k=(x>=y);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPPZF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 k, s;
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(x>=0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPPLF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 k, s;
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(x>0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}

void BTESR_Op_CMPZF_Reg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 k, s;
	f64 x, y, z;
	x=btesr_getregreal(cpu, op->rn);
	s=cpu->regs[BTESR_REG_SR];
	k=(x==0);
	s=(s&(~1))|(k&1);
	cpu->regs[BTESR_REG_SR]=s;
}
