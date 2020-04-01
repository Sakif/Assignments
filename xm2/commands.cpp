#include "all.hpp"

bool processCommands(string cmd) {
  auto commandIndex = checkCommandsTable(cmd);
  if (commandIndex == COMMAND_NOT_FOUND)
    return false;
  else {
    auto command = commands[commandIndex];
    if (command.type == DIRECTORY) {
      processDirectory(commandIndex);
    } else {
      processOperands(commandIndex);
      programCounter += 2;
    }
    return true;
  }
}

bool checkSecondToken() {
  if (tokens.size() > 1) {
    auto secondToken = tokens[1];
    processCommands(secondToken);
  }
  return true;
}

bool checkFirstToken() {
  auto tokenIsLable = false;
  auto firstToken = tokens[0];
  auto isCommand = processCommands(firstToken);
  if (!isCommand) {
    tokenIsLable = true;
    if (validLabel(firstToken)) {
      auto duplicateSymbol = symbolTable.find(firstToken);
      if (duplicateSymbol == nullptr)
        symbolTable.newSymbol(firstToken, LABEL, programCounter);
      else {
        errorCount++;
        lisFile << err << "Symbol already exist: " << firstToken << endl;
      }
    } else {
      errorCount++;
      lisFile << err << "Invalid label" << endl;
    }
  }
  return tokenIsLable;
}

/*Command commands[COMMAND_TABLE_SIZE]*/
const vector<Command> commands = {
    {"ADD", INSTRUCTION, 2, CR_R, W, 0x4000},
    {"ADD.B", INSTRUCTION, 2, CR_R, B, 0x4040},
    {"ADD.W", INSTRUCTION, 2, CR_R, W, 0x4000},
    {"ADDC", INSTRUCTION, 2, CR_R, W, 0x4100},
    {"ADDC.B", INSTRUCTION, 2, CR_R, B, 0x4140},
    {"ADDC.W", INSTRUCTION, 2, CR_R, W, 0x4100},
    {"ALIGN", DIRECTORY, 0, NONE, W, 0},
    {"AND", INSTRUCTION, 2, CR_R, W, 0x4700},
    {"AND.B", INSTRUCTION, 2, CR_R, B, 0x4740},
    {"AND.W", INSTRUCTION, 2, CR_R, W, 0x4700},
    {"BC", INSTRUCTION, 1, BRAop, W, 0x2800},
    {"BEQ", INSTRUCTION, 1, BRAop, W, 0x2000},
    {"BGE", INSTRUCTION, 1, BRAop, W, 0x3400},
    {"BHS", INSTRUCTION, 1, BRAop, W, 0x2800},
    {"BIC", INSTRUCTION, 2, CR_R, W, 0x4900},
    {"BIC.B", INSTRUCTION, 2, CR_R, B, 0x4940},
    {"BIC.W", INSTRUCTION, 2, CR_R, W, 0x4900},
    {"BIS", INSTRUCTION, 2, CR_R, W, 0x4A00},
    {"BIS.B", INSTRUCTION, 2, CR_R, B, 0x4A40},
    {"BIS.W", INSTRUCTION, 2, CR_R, W, 0x4A00},
    {"BIT", INSTRUCTION, 2, CR_R, W, 0x4800},
    {"BIT.B", INSTRUCTION, 2, CR_R, B, 0x4840},
    {"BIT.W", INSTRUCTION, 2, CR_R, W, 0x4800},
    {"BL", INSTRUCTION, 1, BRA13, W, 0x0000},
    {"BLO", INSTRUCTION, 1, BRAop, W, 0x2C00},
    {"BLT", INSTRUCTION, 1, BRAop, W, 0x3800},
    {"BN", INSTRUCTION, 1, BRAop, W, 0x3000},
    {"BNC", INSTRUCTION, 1, BRAop, W, 0x2C00},
    {"BNE", INSTRUCTION, 1, BRAop, W, 0x2400},
    {"BNZ", INSTRUCTION, 1, BRAop, W, 0x2400},
    {"BRA", INSTRUCTION, 1, BRAop, W, 0x3C00},
    {"BSS", DIRECTORY, 1, C, W, 0},
    {"BYTE", DIRECTORY, 1, C, B, 0},
    {"BZ", INSTRUCTION, 1, BRAop, W, 0x2000},
    {"CEX", INSTRUCTION, 3, CEXop, W, 0x5C00},
    {"CMP", INSTRUCTION, 2, CR_R, W, 0x4500},
    {"CMP.B", INSTRUCTION, 2, CR_R, B, 0x4540},
    {"CMP.W", INSTRUCTION, 2, CR_R, W, 0x4500},
    {"DADD", INSTRUCTION, 2, CR_R, W, 0x4400},
    {"DADD.B", INSTRUCTION, 2, CR_R, B, 0x4440},
    {"DADD.W", INSTRUCTION, 2, CR_R, W, 0x4400},
    {"END", DIRECTORY, 1, Opt, W, 0},
    {"EQU", DIRECTORY, 1, V, W, 0},
    {"LD", INSTRUCTION, 2, LDop, W, 0x5000},
    {"LD.B", INSTRUCTION, 2, LDop, B, 0x5040},
    {"LD.W", INSTRUCTION, 2, LDop, W, 0x5000},
    {"LDR", INSTRUCTION, 3, LDRop, W, 0x8000},
    {"LDR.B", INSTRUCTION, 3, LDRop, B, 0x8040},
    {"LDR.W", INSTRUCTION, 3, LDRop, W, 0x8000},
    {"MOV", INSTRUCTION, 2, CR_R, W, 0x4B00},
    {"MOV.B", INSTRUCTION, 2, CR_R, B, 0x4B40},
    {"MOV.W", INSTRUCTION, 2, CR_R, W, 0x4B00},
    {"MOVH", INSTRUCTION, 2, V_R, W, 0x7800},
    {"MOVL", INSTRUCTION, 2, V_R, W, 0x6000},
    {"MOVLS", INSTRUCTION, 2, V_R, W, 0x7000},
    {"MOVLZ", INSTRUCTION, 2, V_R, W, 0x6800},
    {"ORG", DIRECTORY, 1, V, W, 0},
    {"RRC", INSTRUCTION, 1, R, W, 0x4E00},
    {"RRC.B", INSTRUCTION, 1, R, B, 0x4E40},
    {"RRC.W", INSTRUCTION, 1, R, W, 0x4E00},
    {"SRA", INSTRUCTION, 1, R, W, 0x4D00},
    {"SRA.B", INSTRUCTION, 1, R, B, 0x4D40},
    {"SRA.W", INSTRUCTION, 1, R, W, 0x4D00},
    {"ST", INSTRUCTION, 2, STop, W, 0x5400},
    {"ST.B", INSTRUCTION, 2, STop, B, 0x5440},
    {"ST.W", INSTRUCTION, 2, STop, W, 0x5400},
    {"STR", INSTRUCTION, 3, STRop, W, 0xC000},
    {"STR.B", INSTRUCTION, 3, STRop, B, 0xC040},
    {"STR.W", INSTRUCTION, 3, STRop, W, 0xC000},
    {"SUB", INSTRUCTION, 2, CR_R, W, 0x4200},
    {"SUB.B", INSTRUCTION, 2, CR_R, B, 0x4240},
    {"SUB.W", INSTRUCTION, 2, CR_R, W, 0x4200},
    {"SUBC", INSTRUCTION, 2, CR_R, W, 0x4300},
    {"SUBC.B", INSTRUCTION, 2, CR_R, B, 0x4340},
    {"SUBC.W", INSTRUCTION, 2, CR_R, W, 0x4300},
    {"SVC", INSTRUCTION, 1, SA, W, 0x5800},
    {"SWAP", INSTRUCTION, 2, R_R, W, 0x4C00},
    {"SWPB", INSTRUCTION, 1, R, W, 0x4F00},
    {"SXT", INSTRUCTION, 1, R, W, 0x4F80},
    {"WORD", DIRECTORY, 1, C, W, 0},
    {"XOR", INSTRUCTION, 2, CR_R, W, 0x4600},
    {"XOR.B", INSTRUCTION, 2, CR_R, B, 0x4640},
    {"XOR.W", INSTRUCTION, 2, CR_R, W, 0x4600}};

int checkCommandsTable(string cmd) {
  for_each(cmd.begin(), cmd.end(), [](char& c) { c = ::toupper(c); });
  int low = 0, high = commands.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (strcmp(cmd.c_str(), commands[mid].name.c_str()) == 0)
      return mid;
    else if (strcmp(cmd.c_str(), commands[mid].name.c_str()) < 0)
      high = mid - 1;
    else if (strcmp(cmd.c_str(), commands[mid].name.c_str()) > 0)
      low = mid + 1;
  }
  return COMMAND_NOT_FOUND;
}

void processDirectory(int commandIndex) {
  auto command = commands[commandIndex];
  switch (commandIndex) {
    case ALIGN:
      lisFile << "Directory: align" << endl;
      break;

    case BSS:
      lisFile << "Directory: bss" << endl;
      break;

    case BYTE:
      lisFile << "Directory: byte" << endl;
      break;

    case END:
      lisFile << "Directory: end" << endl;
      break;

    case EQU:
      lisFile << "Directory: equ" << endl;
      break;

    case ORG:
      lisFile << "Directory: org" << endl;
      break;

    case WORD:
      lisFile << "Directory: word" << endl;
      break;

    default:
      lisFile << "Not a directory" << endl;
      break;
  }
}
