int BTESR_Trace_TraceUpdateJTrig(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	tr->excnt++;
	if(tr->jtrig)
	{
		tr->jtrig--;
		if(!tr->jtrig)
		{
			BTESR_TryJitTrace(cpu, tr);
			tr->Run(cpu, tr);
			return(1);
		}
	}
	return(0);
}

BTESR_Trace *BTESR_Trace_Run1(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run2(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run3(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run4(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run5(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run6(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run7(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run8(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run9(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run10(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run11(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run12(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run13(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run14(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

#if 0
BTESR_Trace *BTESR_Trace_Run14B(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;
	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run14C(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;
	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run14D(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;
	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}
#endif

BTESR_Trace *BTESR_Trace_Run15(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run16(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run17(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run18(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run19(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run20(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run21(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run22(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run23(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run24(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run25(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run26(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run27(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run28(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run29(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run30(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run31(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

BTESR_Trace *BTESR_Trace_Run32(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	BTESR_Opcode **ops;

	if(BTESR_Trace_TraceUpdateJTrig(cpu, tr)>0)
		return(cpu->trnext);

	ops=tr->ops;
	cpu->regs[BTESR_REG_PC]=tr->nxtpc;
	cpu->trnext=tr->trnext;
	cpu->trjmpnext=tr->trjmpnext;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops); ops++;
	(*ops)->Run(cpu, *ops); ops++;	(*ops)->Run(cpu, *ops);
	return(cpu->trnext);
}

int BTESR_DecodeTrace(BTESR_CpuState *cpu,
	BTESR_Trace *tr, btesr_addr spc)
{
	BTESR_Opcode *op, *op1;
	static int rov;
	btesr_addr pc, brapc, jmppc;
	int i0, i1, i2, i3;
	int i, j, k, n;
	
	tr->srcpc=spc;
	tr->csfl=cpu->csfl;
	
	pc=spc; n=0; brapc=0; jmppc=0;
	while(n<BTESR_TR_MAXOPS)
	{
		BTESR_MarkAddrTrapSmc(cpu, pc);
		op=BTESR_AllocOpcode(cpu);
		
		op->rm=BTESR_REG_ZZR;
		op->rn=BTESR_REG_ZZR;
		op->ro=BTESR_REG_ZZR;
		
		BTESR_DecodeOpcode(cpu, op, pc);
		pc+=2;
		if(op->fl&BTESR_OPFL_EXTRAWORD)
			pc+=2;
		if(pc>tr->maxpc)
			tr->maxpc=pc;
		
		if(!op->Run)
		{
			op->nmid=BTESR_NMID_INVALID;
			op->fmid=BTESR_FMID_NONE;
			op->fl=BTESR_OPFL_CTRLF;
			op->Run=BTESR_Op_TRAP_UD;
		}
		
		if(op->fl&BTESR_OPFL_CTRLF)
		{
			if((	(op->nmid==BTESR_NMID_BF) ||
					(op->nmid==BTESR_NMID_BT) ||
					(op->nmid==BTESR_NMID_BSR)) &&
				(op->fmid==BTESR_FMID_ABS))
			{
				jmppc=op->imm;
			}

			tr->ops[n++]=op;
			break;
		}else
		{
			tr->ops[n++]=op;
		}
	}
	
	tr->nxtpc=pc;
	tr->nops=n;
	tr->nwops=(pc-spc)/2;
	
	if(brapc)
	{
		tr->nxtpc=brapc;
	}
	tr->jmppc=jmppc;
	
	switch(n)
	{
	case  1: tr->Run=BTESR_Trace_Run1; break;
	case  2: tr->Run=BTESR_Trace_Run2; break;
	case  3: tr->Run=BTESR_Trace_Run3; break;
	case  4: tr->Run=BTESR_Trace_Run4; break;
	case  5: tr->Run=BTESR_Trace_Run5; break;
	case  6: tr->Run=BTESR_Trace_Run6; break;
	case  7: tr->Run=BTESR_Trace_Run7; break;
	case  8: tr->Run=BTESR_Trace_Run8; break;
	case  9: tr->Run=BTESR_Trace_Run9; break;
	case 10: tr->Run=BTESR_Trace_Run10; break;
	case 11: tr->Run=BTESR_Trace_Run11; break;
	case 12: tr->Run=BTESR_Trace_Run12; break;
	case 13: tr->Run=BTESR_Trace_Run13; break;
	case 14: tr->Run=BTESR_Trace_Run14; break;
	case 15: tr->Run=BTESR_Trace_Run15; break;
	case 16: tr->Run=BTESR_Trace_Run16; break;

	case 17: tr->Run=BTESR_Trace_Run17; break;
	case 18: tr->Run=BTESR_Trace_Run18; break;
	case 19: tr->Run=BTESR_Trace_Run19; break;
	case 20: tr->Run=BTESR_Trace_Run20; break;
	case 21: tr->Run=BTESR_Trace_Run21; break;
	case 22: tr->Run=BTESR_Trace_Run22; break;
	case 23: tr->Run=BTESR_Trace_Run23; break;
	case 24: tr->Run=BTESR_Trace_Run24; break;

	case 25: tr->Run=BTESR_Trace_Run25; break;
	case 26: tr->Run=BTESR_Trace_Run26; break;
	case 27: tr->Run=BTESR_Trace_Run27; break;
	case 28: tr->Run=BTESR_Trace_Run28; break;
	case 29: tr->Run=BTESR_Trace_Run29; break;
	case 30: tr->Run=BTESR_Trace_Run30; break;
	case 31: tr->Run=BTESR_Trace_Run31; break;
	case 32: tr->Run=BTESR_Trace_Run32; break;

	default: break;
	}

	tr->jtrig=30;
	tr->excnt=0;

	return(0);
}

void BTESR_FlushTrace(BTESR_CpuState *cpu, BTESR_Trace *tr)
{
	int i;

	if(tr->maxpc==0xDEADFEED)
	{
		__debugbreak();
		return;
	}
	
	if((tr->nops<0) || (tr->nops>BTESR_TR_MAXOPS))
	{
		__debugbreak();
		i=-1;
		return;
	}
	
	if(tr->jtflag&BTESR_TRJTFL_NOSTOMP_MASK)
		__debugbreak();
	
	if(tr->srcpc==(btesr_addr)(-1))
	{
		if(!(tr->jtflag&BTESR_TRJTFL_ICACHE) ||
			(tr->jtflag&BTESR_TRJTFL_NOSTOMP_MASK))
				__debugbreak();
		i=-2;
		return;
	}
	
	tr->Run=NULL;
	BTESR_JitUnlinkTrace(cpu, tr->trnext);
	BTESR_JitUnlinkTrace(cpu, tr->trjmpnext);
	
	for(i=0; i<tr->nops; i++)
	{
		BTESR_FreeOpcode(cpu, tr->ops[i]);
	}
	
	memset(tr, 0, sizeof(BTESR_Trace));

	tr->srcpc=-1;
	tr->csfl=-1;
	
//	tr->nops=0;
}

void BTESR_FlushTracesFull(BTESR_CpuState *cpu)
{
	BTESR_Trace *tr, *tr1;
	int i, j, k;
	
	cpu->trnext=NULL;
	cpu->trjmpnext=NULL;

	for(i=0; i<(BTESR_TR_HASHSZ*BTESR_TR_HASHLVL); i++)
	{
		tr=cpu->icache[i];
		if(!tr)
			continue;
		cpu->icache[i]=NULL;

		tr->jtflag&=~BTESR_TRJTFL_ICACHE;
		if(!(tr->jtflag&BTESR_TRJTFL_NOFREE_MASK))
		{
			BTESR_FlushTrace(cpu, tr);
			BTESR_FreeTrace(cpu, tr);
		}
	}

#ifdef BTESR_TR_JHASHSZ
	for(i=0; i<(BTESR_TR_JHASHSZ*BTESR_TR_JHASHLVL); i++)
	{
		tr=cpu->jcache[i];
		if(!tr)
			continue;
		cpu->jcache[i]=NULL;

//		tr->jtflag&=~BTESR_TRJTFL_LINKED;

		tr->jtflag&=~BTESR_TRJTFL_JCACHE;
		if(!(tr->jtflag&BTESR_TRJTFL_NOFREE_MASK))
		{
			BTESR_FlushTrace(cpu, tr);
			BTESR_FreeTrace(cpu, tr);
		}
	}
#endif

	for(i=0; i<256; i++)
	{
		tr=cpu->trlinked[i];
		cpu->trlinked[i]=NULL;
		
		while(tr)
		{
			tr1=tr->lnknext;
			tr->jtflag&=~BTESR_TRJTFL_LINKED;
			tr->trnext=NULL;	tr->trjmpnext=NULL;
			BTESR_FlushTrace(cpu, tr);
			BTESR_FreeTrace(cpu, tr);
			tr=tr1;
		}
	}
}

int BTESR_LinkTrace(BTESR_CpuState *cpu, BTESR_Trace *trj)
{
	int h, hp;

	if(!(trj->jtflag&BTESR_TRJTFL_LINKED))
	{
		hp=(trj->srcpc^trj->csfl)*BTESR_TR_HASHPR;
		h=(hp>>BTESR_TR_HASHSHR)&(BTESR_TR_HASHSZ-1);

		trj->lnknext=cpu->trlinked[h&255];
		cpu->trlinked[h&255]=trj;
		trj->jtflag|=BTESR_TRJTFL_LINKED;
	}
	
	return(0);
}

BTESR_Trace *BTESR_LinkTraceForAddr(BTESR_CpuState *cpu, btesr_addr spc)
{
	BTESR_Trace *tr0, *tr1, *tr2, *tr3, *tr4;
	btesr_addr spc1;
	int h, h0, h1, h2, h3, hp, hp1;
	int i, j, k;
	
//	return(NULL);
	
	hp=(spc^cpu->csfl)*BTESR_TR_HASHPR;
	h=(hp>>BTESR_TR_HASHSHR)&(BTESR_TR_HASHSZ-1);

	tr4=cpu->trlinked[h&255];
	while(tr4)
	{
		if((tr4->srcpc==spc) && (tr4->csfl==cpu->csfl))
		{
//			BTESR_JTraceAddTrace(cpu, tr4);
			return(tr4);
		}
		tr4=tr4->lnknext;
	}

	return(NULL);
}

force_inline BTESR_Trace *BTESR_TraceForAddr(
	BTESR_CpuState *cpu, btesr_addr spc)
{
	BTESR_Trace *tr, *tr1, *tr2;
	btesr_addr spc1;
	int h, h0, h1, hp, hp1;
	int i, j, k;
	
	hp=(spc^cpu->csfl)*BTESR_TR_HASHPR;
	h=(hp>>BTESR_TR_HASHSHR)&(BTESR_TR_HASHSZ-1);

	h0=h*2+0;
	tr=cpu->icache[h0];
	if(tr)
	{
		if((tr->srcpc==spc) && (tr->csfl==cpu->csfl))
		{
			return(tr);
		}

#if 1
		h1=h*2+1;
		tr1=cpu->icache[h1];

		if(tr1)
		{
			tr->jtflag|=BTESR_TRJTFL_ICACHE;
			tr1->jtflag|=BTESR_TRJTFL_ICACHE;

			if((tr1->srcpc==spc) && (tr1->csfl==cpu->csfl))
			{
				cpu->icache[h0]=tr1;
				cpu->icache[h1]=tr;
				return(tr1);
			}

#if 1
			tr2=BTESR_LinkTraceForAddr(cpu, spc);
			if(tr2)
			{
				cpu->icache[h0]=tr2;
				cpu->icache[h1]=tr;
				tr->jtflag|=BTESR_TRJTFL_ICACHE;
				tr2->jtflag|=BTESR_TRJTFL_ICACHE;
				tr1->jtflag&=~BTESR_TRJTFL_ICACHE;
				if(!(tr1->jtflag&BTESR_TRJTFL_NOFREE_MASK))
				{
					BTESR_FlushTrace(cpu, tr1);
					BTESR_FreeTrace(cpu, tr1);
				}
				return(tr2);
			}
#endif

			tr1->jtflag|=BTESR_TRJTFL_ICACHE;
			tr->jtflag|=BTESR_TRJTFL_ICACHE;

			cpu->icache[h0]=tr1;
			cpu->icache[h1]=tr;
			tr=tr1;
			
			if(!(tr->jtflag&BTESR_TRJTFL_NOSTOMP_MASK))
			{
				BTESR_FlushTrace(cpu, tr);
				cpu->tr_dcol++;
				tr->jtflag|=BTESR_TRJTFL_ICACHE;
			}else
			{
				tr=BTESR_AllocTrace(cpu);
				cpu->icache[h0]=tr;
				tr->jtflag|=BTESR_TRJTFL_ICACHE;
			}
		}else
		{
#if 1
			tr2=BTESR_LinkTraceForAddr(cpu, spc);
			if(tr2)
			{
				cpu->icache[h0]=tr2;
				cpu->icache[h1]=tr;
				tr2->jtflag|=BTESR_TRJTFL_ICACHE;
				tr->jtflag|=BTESR_TRJTFL_ICACHE;
				return(tr2);
			}
#endif

			cpu->icache[h1]=tr;
			tr->jtflag|=BTESR_TRJTFL_ICACHE;

			tr=BTESR_AllocTrace(cpu);
			cpu->icache[h0]=tr;
			tr->jtflag|=BTESR_TRJTFL_ICACHE;
		}
#else
		BTESR_FlushTrace(cpu, tr);
		cpu->tr_dcol++;
#endif
	}else
	{
#if 1
		tr2=BTESR_LinkTraceForAddr(cpu, spc);
		if(tr2)
		{
			cpu->icache[h0]=tr2;
			tr2->jtflag|=BTESR_TRJTFL_ICACHE;
			return(tr2);
		}
#endif

		tr=BTESR_AllocTrace(cpu);
		cpu->icache[h0]=tr;
		tr->jtflag|=BTESR_TRJTFL_ICACHE;
	}
	
	if(cpu->jit_needflush)
	{
		tr->srcpc=-2;
	
		printf("BTESR_TraceForAddr: Full Flush\n");
		cpu->jit_needflush=0;
		BTESR_FlushTracesFull(cpu);
//		UAX_ExHeapResetMark();
		return(BTESR_TraceForAddr(cpu, spc));
	}
	
	cpu->tr_dtot++;
	BTESR_DecodeTrace(cpu, tr, spc);
	return(tr);
}
