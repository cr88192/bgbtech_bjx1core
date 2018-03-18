/*
Execute Module (64-bit, Combined)
*/

`include "ExOp64_3A.v"
`include "ExOp64_3B.v"

module ExOp64_3C(
	/* verilator lint_off UNUSED */
	clock,		reset,
	opStepPc,	idInGenPc,	regOutOK,

	regIdRs1,	regValRs1,	regIdRt1,	regValRt1,
	regIdRn1,	regValRn1,	regIdRw1,	regValRw1,
	immValRi1,	opCmd1,
	regIdRs2,	regValRs2,	regIdRt2,	regValRt2,
	regIdRn2,	regValRn2,	regIdRw2,	regValRw2,
	immValRi2,	opCmd2,
	regIdRs3,	regValRs3,	regIdRt3,	regValRt3,
	regIdRn3,	regValRn3,	regIdRw3,	regValRw3,
	immValRi3,	opCmd3,
	regIdRs4,	regValRs4,	regIdRt4,	regValRt4,
	regIdRn4,	regValRn4,	regIdRw4,	regValRw4,
	immValRi4,	opCmd4,
	regIdRs5,	regValRs5,	regIdRt5,	regValRt5,
	regIdRn5,	regValRn5,	regIdRw5,	regValRw5,
	immValRi5,	opCmd5,

	memAddr,	memData,
	memLoad,	memStore,
	memOpMode,	memOpCmd2,

	ctlInSr,	ctlOutSr,
	ctlInPr,	ctlOutPr,
	ctlInPc,	ctlOutPc,
	ctlInMach,	ctlOutMach,
	ctlInMacl,	ctlOutMacl,
	ctlInSp,	ctlOutSp,

	ctlInGbr,	ctlOutGbr,
	ctlInVbr,	ctlOutVbr,
	ctlInSSr,	ctlOutSSr,
	ctlInSPc,	ctlOutSPc,
	ctlInSGr,	ctlOutSGr
	);

input			clock;
input			reset;

input[3:0]		opStepPc;
input[63:0]		idInGenPc;		//ID's Next PC (Next Fetch)
output[1:0]		regOutOK;		//execute status

/* Lane 1 */
input[6:0]		regIdRs1;
input[6:0]		regIdRt1;
input[6:0]		regIdRn1;
output[6:0]		regIdRw1;		//Rn, value to write

input[63:0]		regValRs1;		//Rs input value
input[63:0]		regValRt1;		//Rt input value
input[63:0]		regValRn1;		//Rn input value
output[63:0]	regValRw1;		//Rn output value
input[63:0]		immValRi1;		//immediate/disp value

input[7:0]		opCmd1;			//command opcode

/* Lane 2 */
input[6:0]		regIdRs2;
input[6:0]		regIdRt2;
input[6:0]		regIdRn2;
output[6:0]		regIdRw2;		//Rn, value to write

input[63:0]		regValRs2;		//Rs input value
input[63:0]		regValRt2;		//Rt input value
input[63:0]		regValRn2;		//Rn input value
output[63:0]	regValRw2;		//Rn output value
input[63:0]		immValRi2;		//immediate/disp value

input[7:0]		opCmd2;			//command opcode

/* Lane 3 */
input[6:0]		regIdRs3;
input[6:0]		regIdRt3;
input[6:0]		regIdRn3;
output[6:0]		regIdRw3;		//Rn, value to write

input[63:0]		regValRs3;		//Rs input value
input[63:0]		regValRt3;		//Rt input value
input[63:0]		regValRn3;		//Rn input value
output[63:0]	regValRw3;		//Rn output value
input[63:0]		immValRi3;		//immediate/disp value

input[7:0]		opCmd3;			//command opcode

/* Lane 4 */
input[6:0]		regIdRs4;
input[6:0]		regIdRt4;
input[6:0]		regIdRn4;
output[6:0]		regIdRw4;		//Rn, value to write

input[63:0]		regValRs4;		//Rs input value
input[63:0]		regValRt4;		//Rt input value
input[63:0]		regValRn4;		//Rn input value
output[63:0]	regValRw4;		//Rn output value
input[63:0]		immValRi4;		//immediate/disp value

input[7:0]		opCmd4;			//command opcode

/* Lane 5 */
input[6:0]		regIdRs5;
input[6:0]		regIdRt5;
input[6:0]		regIdRn5;
output[6:0]		regIdRw5;		//Rn, value to write

input[63:0]		regValRs5;		//Rs input value
input[63:0]		regValRt5;		//Rt input value
input[63:0]		regValRn5;		//Rn input value
output[63:0]	regValRw5;		//Rn output value
input[63:0]		immValRi5;		//immediate/disp value

input[7:0]		opCmd5;			//command opcode


/* Memory */
output[63:0]	memAddr;		//memory address
output[63:0]	memData;		//memory data (write)
output			memLoad;		//load from memory
output			memStore;		//store to memory
output[4:0]		memOpMode;		//mem op mode
output[7:0]		memOpCmd2;		//mem EX chain


/* Special Registers */
input[63:0]		ctlInSr;		//SR in
input[63:0]		ctlInPr;		//PR in
input[63:0]		ctlInPc;		//PC in
output[63:0]	ctlOutSr;		//SR out
output[63:0]	ctlOutPr;		//PR out
output[63:0]	ctlOutPc;		//PC out

input[63:0]		ctlInMach;		//MACH:MACL in
input[63:0]		ctlInMacl;		//MACH:MACL in
output[63:0]	ctlOutMach;		//MACH:MACL out
output[63:0]	ctlOutMacl;		//MACH:MACL out

input[63:0]		ctlInSp;		//SP in
output[63:0]	ctlOutSp;		//SP out

input[63:0]		ctlInGbr;
input[63:0]		ctlInVbr;
input[63:0]		ctlInSSr;
input[63:0]		ctlInSPc;
input[63:0]		ctlInSGr;

output[63:0]	ctlOutGbr;
output[63:0]	ctlOutVbr;
output[63:0]	ctlOutSSr;
output[63:0]	ctlOutSPc;
output[63:0]	ctlOutSGr;

wire[1:0]	tRegOutOK;

wire[1:0]	tRegOutOK1;
wire[1:0]	tRegOutOK2;
wire[1:0]	tRegOutOK3;
wire[1:0]	tRegOutOK4;
wire[1:0]	tRegOutOK5;

wire		tRegOutHold;
wire		tRegOutFault;

assign		tRegOutHold =
	((tRegOutOK1==UMEM_OK_HOLD) ||
	 (tRegOutOK2==UMEM_OK_HOLD) ||
	 (tRegOutOK3==UMEM_OK_HOLD) ||
	 (tRegOutOK4==UMEM_OK_HOLD) ||
	 (tRegOutOK5==UMEM_OK_HOLD));

assign		tRegOutFault =
	((tRegOutOK1==UMEM_OK_FAULT) ||
	 (tRegOutOK2==UMEM_OK_FAULT) ||
	 (tRegOutOK3==UMEM_OK_FAULT) ||
	 (tRegOutOK4==UMEM_OK_FAULT) ||
	 (tRegOutOK5==UMEM_OK_FAULT));

assign	tRegOutOK =
	tRegOutHold ? UMEM_OK_HOLD :
	tRegOutFault ? UMEM_OK_FAULT :
	UMEM_OK_OK;

assign	regOutOK = tRegOutOK;


ExOp64_3A	ex3a1(
	clock,		reset,
	opCmd1,		opStepPc,
	regIdRs1,	regValRs1,
	regIdRt1,	regValRt1,
	regIdRn1,	regValRn1,
	immValRi1,	idInGenPc,
	regIdRw1,	regValRw1,
	tRegOutOK1,

	memAddr,	memData,
	memLoad,	memStore,
	memOpMode,	memOpCmd2,

	ctlInSr,	ctlOutSr,
	ctlInPr,	ctlOutPr,
	ctlInPc,	ctlOutPc,
	ctlInMach,	ctlOutMach,
	ctlInMacl,	ctlOutMacl,
	ctlInSp,	ctlOutSp,

	ctlInGbr,	ctlOutGbr,
	ctlInVbr,	ctlOutVbr,
	ctlInSSr,	ctlOutSSr,
	ctlInSPc,	ctlOutSPc,
	ctlInSGr,	ctlOutSGr
	);

ExOp64_3B	ex3b2(
	clock,		reset,
	opCmd2,		opStepPc,
	regIdRs2,	regValRs2,
	regIdRt2,	regValRt2,
	regIdRn2,	regValRn2,
	immValRi2,	idInGenPc,
	regIdRw2,	regValRw2,
	tRegOutOK2,	ctlInSr);

ExOp64_3B	ex3b3(
	clock,		reset,
	opCmd3,		opStepPc,
	regIdRs3,	regValRs3,
	regIdRt3,	regValRt3,
	regIdRn3,	regValRn3,
	immValRi3,	idInGenPc,
	regIdRw3,	regValRw3,
	tRegOutOK3,	ctlInSr);

ExOp64_3B	ex3b4(
	clock,		reset,
	opCmd4,		opStepPc,
	regIdRs4,	regValRs4,
	regIdRt4,	regValRt4,
	regIdRn4,	regValRn4,
	immValRi4,	idInGenPc,
	regIdRw4,	regValRw4,
	tRegOutOK4,	ctlInSr);

ExOp64_3B	ex3b5(
	clock,		reset,
	opCmd5,		opStepPc,
	regIdRs5,	regValRs5,
	regIdRt5,	regValRt5,
	regIdRn5,	regValRn5,
	immValRi5,	idInGenPc,
	regIdRw5,	regValRw5,
	tRegOutOK5,	ctlInSr);

endmodule
