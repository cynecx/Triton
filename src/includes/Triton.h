
#ifndef   __TRITON_H__
#define   __TRITON_H__

#include <asm/unistd.h>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <boost/format.hpp>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <z3++.h>

#include "SnapshotEngine.h"
#include "SolverEngine.h"
#include "SymbolicEngine.h"
#include "TaintEngine.h"

#define LOCKED        1
#define UNLOCKED      !LOCKED
#define TAINTED       1

#define ID_RAX        0
#define ID_RBX        1
#define ID_RCX        2
#define ID_RDX        3
#define ID_RDI        4
#define ID_RSI        5
#define ID_RBP        6
#define ID_RSP        7
#define ID_R8         8
#define ID_R9         9
#define ID_R10        10
#define ID_R11        11
#define ID_R12        12
#define ID_R13        13
#define ID_R14        14
#define ID_R15        15
#define ID_CF         16
#define ID_PF         17
#define ID_AF         18
#define ID_ZF         19
#define ID_SF         20
#define ID_TF         21
#define ID_IF         22
#define ID_DF         23
#define ID_OF         24


/* Extern decl */

extern SnapshotEngine           *snapshotEngine;
extern TaintEngine              *taintEngine;
extern SymbolicEngine           *symbolicEngine;
extern UINT32                   _analysisStatus;
extern KNOB<std::string>        KnobStartAnalysis;
extern boost::format            outputInstruction;


/* decl */
REG             getHighReg(REG reg);
UINT64          derefMem(UINT64 mem, UINT64 readSize);
UINT64          translatePinRegToID(REG reg);
VOID            Image(IMG img, VOID *v);
VOID            Instruction(INS ins, VOID *v);
VOID            addRegImm(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, UINT64 imm);
VOID            addRegReg(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, REG reg2);
VOID            branchs(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, UINT32 opcode);
VOID            cmpMemImm(std::string insDis, ADDRINT insAddr, UINT64 imm, UINT64 mem, UINT32 readSize);
VOID            cmpRegImm(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, UINT64 imm);
VOID            cmpRegReg(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, REG reg2);
VOID            lockAnalysis(void);
VOID            movMemImm(std::string insDis, ADDRINT insAddr, UINT64 imm, UINT64 mem, UINT32 writeSize, INT32 opcode);
VOID            movMemReg(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, UINT64 mem, UINT32 writeSize, INT32 opcode);
VOID            movRegImm(std::string insDis, ADDRINT insAddr, REG reg1, UINT64 imm, INT32 opcode);
VOID            movRegMem(std::string insDis, ADDRINT insAddr, REG reg1, UINT64 mem, UINT32 readSize, INT32 opcode);
VOID            movRegReg(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, REG reg2, INT32 opcode);
VOID            notImplemented(std::string insDis, ADDRINT insAddr);
VOID            popReg(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, UINT64 mem, UINT32 readSize);
VOID            pushImm(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, UINT64 imm, UINT64 mem, UINT32 writeSize);
VOID            pushReg(std::string insDis, ADDRINT insAddr, CONTEXT *ctx, REG reg1, UINT64 mem, UINT32 writeSize);
VOID            taintParams(CONTEXT *ctx);
VOID            unlockAnalysis(void);


VOID displayTrace(ADDRINT addr, const std::string &insDis, const std::string &expr, UINT64 isTainted);

#endif     /* !__TRITON_H__ */

