int BTESR_InterpRun(BTESR_CpuState *cpu, int limit)
{
	BTESR_Trace *tr;
	btesr_addr pc;
	int lim;

//	cpu->status=0;
	
	lim=limit;
	while(lim && !cpu->status)
	{
		tr=cpu->trnext;
		if(!tr)
		{
			pc=btesr_getregaddr(cpu, BTESR_REG_PC);
			tr=BTESR_TraceForAddr(cpu, pc)
			if(!tr)
			{
				cpu->status=BTESH2_EXC_RESET;
				break;
			}
		}
		while(tr && (lim--))
			{ tr=tr->Run(cpu, tr); }		
	}
	
	return(cpu->status);
}
