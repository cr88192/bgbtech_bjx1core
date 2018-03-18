/*
 * Decode WJX1 Wide Opcode
 */

`include "CoreDefs.v"
`include "DecWOp1.v"

module DecWOp(
	/* verilator lint_off UNUSED */
	clock, istrWord, opStep,
	idRegN1, idRegS1, idRegT1, idImm1, idUCmd1,
	idRegN2, idRegS2, idRegT2, idImm2, idUCmd2,
	idRegN3, idRegS3, idRegT3, idImm3, idUCmd3,
	idRegN4, idRegS4, idRegT4, idImm4, idUCmd4,
	idRegN5, idRegS5, idRegT5, idImm5, idUCmd5
	);

input			clock;
input[127:0]	istrWord;	//source instruction word
output			opStep;

output[6:0]		idRegN1;
output[6:0]		idRegS1;
output[6:0]		idRegT1;
output[31:0]	idImm1;
output[7:0]		idUCmd1;

output[6:0]		idRegN2;
output[6:0]		idRegS2;
output[6:0]		idRegT2;
output[31:0]	idImm2;
output[7:0]		idUCmd2;

output[6:0]		idRegN3;
output[6:0]		idRegS3;
output[6:0]		idRegT3;
output[31:0]	idImm3;
output[7:0]		idUCmd3;

output[6:0]		idRegN4;
output[6:0]		idRegS4;
output[6:0]		idRegT4;
output[31:0]	idImm4;
output[7:0]		idUCmd4;

output[6:0]		idRegN5;
output[6:0]		idRegS5;
output[6:0]		idRegT5;
output[31:0]	idImm5;
output[7:0]		idUCmd5;


reg[6:0]		opRegN1;
reg[6:0]		opRegS1;
reg[6:0]		opRegT1;	//Index for mem ops
reg[31:0]		opImm1;	//Disp for mem ops
reg[7:0]		opUCmd1;

reg[6:0]		opRegN2;
reg[6:0]		opRegS2;
reg[6:0]		opRegT2;	//Index for mem ops
reg[31:0]		opImm2;	//Disp for mem ops
reg[7:0]		opUCmd2;

reg[6:0]		opRegN3;
reg[6:0]		opRegS3;
reg[6:0]		opRegT3;	//Index for mem ops
reg[31:0]		opImm3;	//Disp for mem ops
reg[7:0]		opUCmd3;

reg[6:0]		opRegN4;
reg[6:0]		opRegS4;
reg[6:0]		opRegT4;	//Index for mem ops
reg[31:0]		opImm4;	//Disp for mem ops
reg[7:0]		opUCmd4;

reg[6:0]		opRegN5;
reg[6:0]		opRegS5;
reg[6:0]		opRegT5;	//Index for mem ops
reg[31:0]		opImm5;	//Disp for mem ops
reg[7:0]		opUCmd5;

assign	idRegN1 = opRegN1;
assign	idRegS1 = opRegS1;
assign	idRegT1 = opRegT1;
assign	idImm1  = opImm1;
assign	idUCmd1 = opUCmd1;

assign	idRegN2 = opRegN2;
assign	idRegS2 = opRegS2;
assign	idRegT2 = opRegT2;
assign	idImm2  = opImm2;
assign	idUCmd2 = opUCmd2;

assign	idRegN3 = opRegN3;
assign	idRegS3 = opRegS3;
assign	idRegT3 = opRegT3;
assign	idImm3  = opImm3;
assign	idUCmd3 = opUCmd3;

assign	idRegN4 = opRegN4;
assign	idRegS4 = opRegS4;
assign	idRegT4 = opRegT4;
assign	idImm4  = opImm4;
assign	idUCmd4 = opUCmd4;

assign	idRegN5 = opRegN5;
assign	idRegS5 = opRegS5;
assign	idRegT5 = opRegT5;
assign	idImm5  = opImm5;
assign	idUCmd5 = opUCmd5;

reg				isWide128;

assign	opStep = isWide128;

wire[6:0]		wop1RegN;
wire[6:0]		wop1RegS;
wire[6:0]		wop1RegT;	//Index for mem ops
wire[31:0]		wop1Imm;	//Disp for mem ops
wire[7:0]		wop1UCmd;

wire[6:0]		wop2RegN;
wire[6:0]		wop2RegS;
wire[6:0]		wop2RegT;	//Index for mem ops
wire[31:0]		wop2Imm;	//Disp for mem ops
wire[7:0]		wop2UCmd;

DecWOp1 dwop1(clock, istrWord[23:0],
	wop1RegN, wop1RegS, wop1RegT,
	wop1Imm, wop1UCmd);

DecWOp1 dwop2(clock, istrWord[47:24],
	wop2RegN, wop2RegS, wop2RegT,
	wop2Imm, wop2UCmd);


wire[6:0]		wop3RegN;
wire[6:0]		wop3RegS;
wire[6:0]		wop3RegT;	//Index for mem ops
wire[31:0]		wop3Imm;	//Disp for mem ops
wire[7:0]		wop3UCmd;

wire[6:0]		wop4RegN;
wire[6:0]		wop4RegS;
wire[6:0]		wop4RegT;	//Index for mem ops
wire[31:0]		wop4Imm;	//Disp for mem ops
wire[7:0]		wop4UCmd;

DecWOp1 dwop3(clock, istrWord[87:64],
	wop3RegN, wop3RegS, wop3RegT,
	wop3Imm, wop3UCmd);

DecWOp1 dwop4(clock, istrWord[111:88],
	wop4RegN, wop4RegS, wop4RegT,
	wop4Imm, wop4UCmd);

wire[6:0]		wop5RegN;
wire[6:0]		wop5RegS;
wire[6:0]		wop5RegT;	//Index for mem ops
wire[31:0]		wop5Imm;	//Disp for mem ops
wire[7:0]		wop5UCmd;

DecWOp1 dwop5(clock, { istrWord[123:112], istrWord[59:48] },
	wop5RegN, wop5RegS, wop5RegT,
	wop5Imm, wop5UCmd);

always @*
begin

	isWide128 = istrWord[63];

	opRegN1 = wop1RegN;
	opRegS1 = wop1RegS;
	opRegT1 = wop1RegT;
	opImm1  = wop1Imm;
	opUCmd1 = wop1UCmd;

	opRegN2 = wop2RegN;
	opRegS2 = wop2RegS;
	opRegT2 = wop2RegT;
	opImm2  = wop2Imm;
	opUCmd2 = wop2UCmd;

	if(isWide128)
	begin
		opRegN3 = wop3RegN;
		opRegS3 = wop3RegS;
		opRegT3 = wop3RegT;
		opImm3  = wop3Imm;
		opUCmd3 = wop3UCmd;

		opRegN4 = wop4RegN;
		opRegS4 = wop4RegS;
		opRegT4 = wop4RegT;
		opImm4  = wop4Imm;
		opUCmd4 = wop4UCmd;

		opRegN5 = wop5RegN;
		opRegS5 = wop5RegS;
		opRegT5 = wop5RegT;
		opImm5  = wop5Imm;
		opUCmd5 = wop5UCmd;
	end
	else
	begin
		opRegN3 = UREG_ZZR;
		opRegS3 = UREG_ZZR;
		opRegT3 = UREG_ZZR;
		opImm3  = UV32_XX;
		opUCmd3 = UCMD_NONE;

		opRegN4 = UREG_ZZR;
		opRegS4 = UREG_ZZR;
		opRegT4 = UREG_ZZR;
		opImm4  = UV32_XX;
		opUCmd4 = UCMD_NONE;

		opRegN5 = UREG_ZZR;
		opRegS5 = UREG_ZZR;
		opRegT5 = UREG_ZZR;
		opImm5  = UV32_XX;
		opUCmd5 = UCMD_NONE;
	end

end

endmodule
