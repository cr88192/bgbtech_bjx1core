void BTESR_Op_MOV_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=cpu->regs[op->rm];
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOV_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	cpu->regs[op->rn]=op->imm;
}

void BTESR_Op_MOVQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=btesr_getregu64(cpu, op->rm);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_setregu64(cpu, op->rn, op->imm);
}

void BTESR_Op_LDCTI_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr i, j;

	i=btesr_getregaddr(cpu, BTESR_REG_CT);
	j=BTESR_GetAddrDWord(cpu, i+(op->imm*4));
	btesr_setregu32(cpu, op->rn, j);
}

void BTESR_Op_LDCTQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;

	i=btesr_getregaddr(cpu, BTESR_REG_CT);
	j=BTESR_GetAddrQWord(cpu, i+(op->imm*8));
	btesr_setregu64(cpu, op->rn, j);
}

void BTESR_Op_LDCTF_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 j;
	u64 i, k;

	i=btesr_getregaddr(cpu, BTESR_REG_CT);
	j=BTESR_GetAddrDWord(cpu, i+(op->imm*4));
	*(f64 *)(&k)=*(f32 *)(&j);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_LDCTD_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;

	i=btesr_getregaddr(cpu, BTESR_REG_CT);
	j=BTESR_GetAddrQWord(cpu, i+(op->imm*8));
	btesr_setregu64(cpu, op->rn, j);
}

void BTESR_Op_LDOTQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;

	i=btesr_getregaddr(cpu, BTESR_REG_OT);
	j=BTESR_GetAddrQWord(cpu, i+(op->imm*8));
	btesr_setregu64(cpu, op->rn, j);
}

void BTESR_Op_LDSPQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;

	i=btesr_getregaddr(cpu, BTESR_REG_SP);
	j=BTESR_GetAddrQWord(cpu, i+(op->imm*8));
	btesr_setregu64(cpu, op->rn, j);
}

void BTESR_Op_LDSPF_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;

	i=btesr_getregaddr(cpu, BTESR_REG_SP);
	j=BTESR_GetAddrQWord(cpu, i+(op->imm*8));
	btesr_setregu64(cpu, op->rn, j);
}

void BTESR_Op_STSPQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, BTESR_REG_SP)+(op->imm*8),
		btesr_getregu64(cpu, op->rn));
}

void BTESR_Op_STSPF_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, BTESR_REG_SP)+(op->imm*8),
		btesr_getregu64(cpu, op->rn));
}


void BTESR_Op_MOVB_RegLdReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrByte(cpu, btesr_getregaddr(cpu, op->rm));
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrWord(cpu, btesr_getregaddr(cpu, op->rm));
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm));
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm));
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVF_RegLdReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	u64 k;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm));
	*(f64 *)(&k)=*(f32 *)(&i);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_MOVV_RegLdReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+0);
	j=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+8);
	btesr_setregu64(cpu, op->rn+0, i);
	btesr_setregu64(cpu, op->rn+2, j);
}

void BTESR_Op_MOVB_StRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrByte(cpu,
		btesr_getregaddr(cpu, op->rn),
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrWord(cpu,
		btesr_getregaddr(cpu, op->rn),
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVI_StRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrDWord(cpu,
		btesr_getregaddr(cpu, op->rn),
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn),
		btesr_getregu64(cpu, op->rm));
}

void BTESR_Op_MOVF_StRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	u32 j;
	
	i=btesr_getregu64(cpu, op->rm);
	*(f32 *)(&j)=*(f64 *)(&i);
	BTESR_SetAddrDWord(cpu, btesr_getregaddr(cpu, op->rn), j);
}

void BTESR_Op_MOVV_StRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+0,
		btesr_getregu64(cpu, op->rm+0));
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+8,
		btesr_getregu64(cpu, op->rm+2));
}

void BTESR_Op_MOVB_RegLdIncReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;
	a=btesr_getregaddr(cpu, op->rm);
	btesr_setregaddr(cpu, op->rm, a+1);
	i=BTESR_GetAddrByte(cpu, a);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdIncReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;
	a=btesr_getregaddr(cpu, op->rm);
	btesr_setregaddr(cpu, op->rm, a+2);
	i=BTESR_GetAddrWord(cpu, a);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdIncReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;
	a=btesr_getregaddr(cpu, op->rm);
	btesr_setregaddr(cpu, op->rm, a+4);
	i=BTESR_GetAddrDWord(cpu, a);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdIncReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u64 i;
	a=btesr_getregaddr(cpu, op->rm);
	btesr_setregaddr(cpu, op->rm, a+8);
	i=BTESR_GetAddrQWord(cpu, a);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVF_RegLdIncReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;
	u64 k;
	a=btesr_getregaddr(cpu, op->rm);
	btesr_setregaddr(cpu, op->rm, a+4);
	i=BTESR_GetAddrDWord(cpu, a);
	*(f64 *)(&k)=*(f32 *)(&i);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_MOVV_RegLdIncReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u64 i, j;
	a=btesr_getregaddr(cpu, op->rm);
	btesr_setregaddr(cpu, op->rm, a+16);
	i=BTESR_GetAddrQWord(cpu, a+0);
	j=BTESR_GetAddrQWord(cpu, a+8);
	btesr_setregu64(cpu, op->rn+0, i);
	btesr_setregu64(cpu, op->rn+2, j);
}

void BTESR_Op_MOVB_StIncRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn);
	btesr_setregaddr(cpu, op->rn, a+1);
	BTESR_SetAddrByte(cpu, a, cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StIncRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn);
	btesr_setregaddr(cpu, op->rn, a+2);
	BTESR_SetAddrWord(cpu, a, cpu->regs[op->rm]);
}

void BTESR_Op_MOVI_StIncRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn);
	btesr_setregaddr(cpu, op->rn, a+4);
	BTESR_SetAddrDWord(cpu, a, cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StIncRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn);
	btesr_setregaddr(cpu, op->rn, a+8);
	BTESR_SetAddrQWord(cpu, a, btesr_getregu64(cpu, op->rm));
}

void BTESR_Op_MOVF_StIncRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u64 i;
	u32 k;
	a=btesr_getregaddr(cpu, op->rn);
	btesr_setregaddr(cpu, op->rn, a+4);
	i=btesr_getregu64(cpu, op->rm);
	*(f32 *)(&k)=*(f64 *)(&i);
	BTESR_SetAddrDWord(cpu, a, k);
}

void BTESR_Op_MOVV_StIncRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn);
	btesr_setregaddr(cpu, op->rn, a+16);
	BTESR_SetAddrQWord(cpu, a+0, btesr_getregu64(cpu, op->rm+0));
	BTESR_SetAddrQWord(cpu, a+8, btesr_getregu64(cpu, op->rm+2));
}

void BTESR_Op_MOVB_RegLdDecReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;

	a=btesr_getregaddr(cpu, op->rm)-1;
	btesr_setregaddr(cpu, op->rm, a);
	i=BTESR_GetAddrByte(cpu, a);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdDecReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;
	a=btesr_getregaddr(cpu, op->rm)-2;
	btesr_setregaddr(cpu, op->rm, a);
	i=BTESR_GetAddrWord(cpu, a);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdDecReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u32 i, j;
	a=btesr_getregaddr(cpu, op->rm)-4;
	btesr_setregaddr(cpu, op->rm, a);
	i=BTESR_GetAddrDWord(cpu, a);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdDecReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u64 i;
	a=btesr_getregaddr(cpu, op->rm)-8;
	btesr_setregaddr(cpu, op->rm, a);
	i=BTESR_GetAddrQWord(cpu, a);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVV_RegLdDecReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	u64 i, j;
	a=btesr_getregaddr(cpu, op->rm)-16;
	btesr_setregaddr(cpu, op->rm, a);
	i=BTESR_GetAddrQWord(cpu, a+0);
	j=BTESR_GetAddrQWord(cpu, a+8);
	btesr_setregu64(cpu, op->rn+0, i);
	btesr_setregu64(cpu, op->rn+2, j);
}

void BTESR_Op_MOVB_StDecRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn)-1;
	btesr_setregaddr(cpu, op->rn, a);
	BTESR_SetAddrByte(cpu, a, cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StDecRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn)-2;
	btesr_setregaddr(cpu, op->rn, a);
	BTESR_SetAddrWord(cpu, a, cpu->regs[op->rm]);
}

void BTESR_Op_MOVI_StDecRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn)-4;
	btesr_setregaddr(cpu, op->rn, a);
	BTESR_SetAddrDWord(cpu, a, cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StDecRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn)-8;
	btesr_setregaddr(cpu, op->rn, a);
	BTESR_SetAddrQWord(cpu, a, btesr_getregu64(cpu, op->rm));
}

void BTESR_Op_MOVV_StDecRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a;
	a=btesr_getregaddr(cpu, op->rn)-16;
	btesr_setregaddr(cpu, op->rn, a);
	BTESR_SetAddrQWord(cpu, a+0, btesr_getregu64(cpu, op->rm+0));
	BTESR_SetAddrQWord(cpu, a+8, btesr_getregu64(cpu, op->rm+2));
}

void BTESR_Op_MOVB_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrByte(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*1);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrWord(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*2);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*4);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*8);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVF_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	u64 k;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*4);
	*(f64 *)(&k)=*(f32 *)(&i);
	btesr_setregu64(cpu, op->rn, k);
}

void BTESR_Op_MOVV_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*16+0);
	j=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+op->imm*16+8);
	btesr_setregu64(cpu, op->rn+0, i);
	btesr_setregu64(cpu, op->rn+2, j);
}

void BTESR_Op_MOVB_StRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrByte(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*1,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrWord(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*2,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVI_StRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrDWord(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*4,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*8,
		btesr_getregu64(cpu, op->rm));
}

void BTESR_Op_MOVF_StRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	u32 j;
	
	i=btesr_getregu64(cpu, op->rm);
	*(f32 *)(&j)=*(f64 *)(&i);
	BTESR_SetAddrDWord(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*4,
		j);
}

void BTESR_Op_MOVV_StRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*16+0,
		btesr_getregu64(cpu, op->rm+0));
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+op->imm*16+8,
		btesr_getregu64(cpu, op->rm+2));
}


#if 1
void BTESR_Op_MOVB_RegLdReg2Disp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrByte(cpu,
		btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*1);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdReg2Disp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrWord(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*2);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdReg2Disp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*4);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdReg2Disp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*8);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVV_RegLdReg2Disp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i, j;
	i=BTESR_GetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*16+0);
	j=BTESR_GetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*16+8);
	btesr_setregu64(cpu, op->rn+0, i);
	btesr_setregu64(cpu, op->rn+2, j);
}

void BTESR_Op_MOVB_StReg2DispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrByte(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*1,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StReg2DispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*2,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVI_StReg2DispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrDWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*4,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StReg2DispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*8,
		btesr_getregu64(cpu, op->rm));
}

void BTESR_Op_MOVV_StReg2DispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*16+0,
		btesr_getregu64(cpu, op->rm+0));
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*16+8,
		btesr_getregu64(cpu, op->rm+2));
}
#endif

void BTESR_Op_MOVB_RegLdRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrByte(cpu, btesr_getregaddr(cpu, op->rm)+
		btesr_getregs32(cpu, op->ro)*1);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrWord(cpu, btesr_getregaddr(cpu, op->rm)+
		btesr_getregs32(cpu, op->ro)*2);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm)+
		btesr_getregs32(cpu, op->ro)*4);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+
		btesr_getregs32(cpu, op->ro)*8);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVB_StRegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrByte(cpu,
		btesr_getregaddr(cpu, op->rn)+
		btesr_getregs32(cpu, op->ro)*1,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StRegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		btesr_getregs32(cpu, op->ro)*2,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVD_StRegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrDWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		btesr_getregs32(cpu, op->ro)*4,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StRegRegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		btesr_getregs32(cpu, op->ro)*8,
		btesr_getregu64(cpu, op->rm));
}


void BTESR_Op_MOVB_RegLdRegRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrByte(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*1);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVW_RegLdRegRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrWord(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*2);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVI_RegLdRegRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u32 i, j;
	i=BTESR_GetAddrDWord(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*4);
	cpu->regs[op->rn]=i;
}

void BTESR_Op_MOVQ_RegLdRegRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	u64 i;
	i=BTESR_GetAddrQWord(cpu, btesr_getregaddr(cpu, op->rm)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*8);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_MOVB_StRegRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrByte(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*1,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVW_StRegRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*2,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVD_StRegRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrDWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*4,
		cpu->regs[op->rm]);
}

void BTESR_Op_MOVQ_StRegRegDispReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	BTESR_SetAddrQWord(cpu,
		btesr_getregaddr(cpu, op->rn)+
		(btesr_getregs32(cpu, op->ro)+op->imm)*8,
		btesr_getregu64(cpu, op->rm));
}

void BTESR_Op_DIFFPB_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregaddr(cpu, op->rm);
	c=a-b;
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_DIFFPW_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregaddr(cpu, op->rm);
	c=(a-b)>>1;
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_DIFFPI_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregaddr(cpu, op->rm);
	c=(a-b)>>2;
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_DIFFPQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregaddr(cpu, op->rm);
	c=(a-b)>>3;
	btesr_setregaddr(cpu, op->rn, c);
}


void BTESR_Op_LEAB_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregs32(cpu, op->rm);
	c=a+b;
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAW_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregs32(cpu, op->rm);
	c=a+(b<<1);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAI_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregs32(cpu, op->rm);
	c=a+(b<<2);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=btesr_getregs32(cpu, op->rm);
	c=a+(b<<3);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAB_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=(s32)(op->imm);
	c=a+b;
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAW_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=(s32)(op->imm);
	c=a+(b<<1);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAI_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=(s32)(op->imm);
	c=a+(b<<2);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAQ_RegImm(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rn);
	b=(s32)(op->imm);
	c=a+(b<<3);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAB_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	b=(s32)(op->imm);
	c=a+b;
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAW_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	b=(s32)(op->imm);
	c=a+(b<<1);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAI_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	b=(s32)(op->imm);
	c=a+(b<<2);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAQ_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	b=(s32)(op->imm);
	c=a+(b<<3);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LEAV_RegLdRegDisp(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	b=(s32)(op->imm);
	c=a+(b<<4);
	btesr_setregaddr(cpu, op->rn, c);
}

void BTESR_Op_LDIOI_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	c=BTESR_GetIoAddrDWord(cpu, a);
	btesr_setregu32(cpu, op->rn, c);
}

void BTESR_Op_STIOI_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	a=btesr_getregaddr(cpu, op->rm);
	b=btesr_getregu32(cpu, op->rn);
	BTESR_SetIoAddrDWord(cpu, a, b);
}

void BTESR_Op_LDIOQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	u64 i;
	a=btesr_getregaddr(cpu, op->rm);
	i=BTESR_GetIoAddrQWord(cpu, a);
	btesr_setregu64(cpu, op->rn, i);
}

void BTESR_Op_STIOQ_RegReg(BTESR_CpuState *cpu, BTESR_Opcode *op)
{
	btesr_addr a, b, c;
	u64 i;
	a=btesr_getregaddr(cpu, op->rm);
	i=btesr_getregu64(cpu, op->rn);
	BTESR_SetIoAddrQWord(cpu, a, i);
}
