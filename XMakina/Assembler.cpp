/* ECED 3403 - XM2 Assembler Project
Sakif Fahmid Zaman - B00756635

-- XM2 Assembler implementation

 */

#include "Assembler.hpp"

//default constructor
Assembler::Assembler() {
  raw_lines = {};
  records = {};
  SymTab = {};
  InstructionSet = {"BL", "BEQ", "BZ", "BNE", "BNZ", "BC", "BHS", "BNC", "BLO", "BN", "BGE", "BLT", "BRA", "ADD", "ADDC", "SUB", "SUBC", "DADD", "CMP", "XOR", "AND", "AND", "BIT", "BIC", "BIS", "MOV", "SWAP", "SRA", "RRC", "SWPB", "SXT", "LD", "ST", "SVC", "CEX", "MOVL", "MOVLZ", "MOVLS", "MOVLH", "MOVH", "LDR", "STR"};
  Directives = {"ALIGN", "BSS", "BYTE", "END", "EQU", "ORG", "WORD"};
} //if the default behavior is changed, the new Instruction sets can be declared through a file

//constructor for revised instruction/directive sets
Assembler::Assembler(std::string f1) {
  //not yet implemented
}

bool Assembler::read_input_assembly_file(std::string f) {
  std::ifstream ifile; //input file
  ifile.open(f);       //open the

  if (ifile.is_open()) { //could open the file - so, valid
    //store the file name for future use
    fname = f;
    std::string line; //contains whole line
    while (getline(ifile, line)) {

      raw_lines.emplace_back(line);
    }
    //close the filestream
    ifile.close();

    /* //test - lloks good
        std::cout<<"Total "<<raw_lines.size()<< " lines in the "<< f<< " file"<<std::endl;
        for(int i=0; i<raw_lines.size(); i++){
            std::cout<<raw_lines[i].data()<<std::endl;
        } */
    return true;
  } else { //could not open file
    std::cout << "\n Error Opening file " << f << std::endl;
    return false;
  }
}

/*determine if the string s is a mnemonic or not, if so, return the assembler nmemonic and its type   */
std::string Assembler::check_token(std::string s) {

  std::locale loc;
  //if the string is empty -return false -- remove this check as NO EMPTY STR should be passed
  if (s.empty()) {
    //isMnemonic = false;
    return "";
  }
  //otherwise look at the instruction and directive sets
  for (auto ms : InstructionSet) { //check instruction set
    bool b = (ms.size() == s.size()) && std::equal(ms.begin(), ms.end(), s.begin(), [](char &c1, char &c2) { return std::toupper(c1) == std::toupper(c2); });
    if (b) {
      return "INST";
    }
  }

  for (auto ms : Directives) { //check directives
    bool b = (ms.size() == s.size()) && std::equal(ms.begin(), ms.end(), s.begin(), [](char &c1, char &c2) { return std::toupper(c1) == std::toupper(c2); });
    if (b) {
      return "DIR";
    }
  }
  //not a nmemonic - either an operand or a LBL
  //-- check for operand
  if (s[0] == '#') { //signed or unsigned int  operand
    return "OPINT";
  }
  if (s[0] == '$') { //hex number operand
    return "OPHEX";
  }

  if ((s.front() == '\'') && (s.back() == '\'')) { //a char operand
    return "OPCHR";
  }
  //check for label or register operand in SYMTAB
  for (auto sym : SymTab) {
    if (!s.compare(sym.name)) {       //found an entry in the SYMTAB
      if (!sym.type.compare("REG")) { //register operand
        return "OPREG";
      }
      if (!sym.type.compare("LBL")) { //label operand
        return "OPLBL";
      }
      if (!sym.type.compare("UNK")) { //unknown label operand
        return "OPUNK";
      }
    }
  }
  // it should a label (LBL) then
  return "LBL";
}

/* returns cleaned (removes comments, ) */
std::vector<std::vector<std::string>> Assembler::get_cleaned() {
  std::vector<std::vector<std::string>> cleaned; //vector to be returned
  for (auto line : raw_lines) {                  //get all lines
    //std::cout<<"original:"<<line<<std::endl;
    //strip off comments - remove everything after the ";" (comment) symbol
    std::string stripped = line.substr(0, line.find(";"));
    // empty lines - insert empty vector to cleaned vector and return
    if (stripped.empty()) {
      cleaned.push_back({}); //std::vector<std::string> v = {}
      continue;
    }
    //replace tabs with blank space (' ') and split into tokens
    std::replace(stripped.begin(), stripped.end(), '\t', ' '); //remove tabs
    std::stringstream ss(stripped);
    std::string token;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, token, ' ')) {
      splittedStrings.push_back(token);
    }
    std::vector<std::string> cleaned_lines;
    //only non-empty one
    for (auto s : splittedStrings) {
      s.erase(std::remove_if(s.begin(), s.end(),
                             [](char &c) {
                               return std::isspace<char>(c, std::locale::classic());
                             }),
              s.end());

      if (!s.empty()) {
        cleaned_lines.push_back(s);
      }
    }
    //store the cleaned_tokens
    cleaned.push_back(cleaned_lines);
  }

  return cleaned; //done - return it
}

/* check whether the label is valid or not and returns 3-tupe:
    - if it is valid, if valid true
    - if it is followed by other token - none ("EMPT"), instruction ("INST") or directive ("DIR")
    - error message, if invalid - 
 */

std::string Assembler::validate_label(std::string lbl) {

  //check for valid name
  // -- first letter must be alphabetic
  if (!isalpha(lbl[0])) {
    return "***Invalid Label: first character must be alphabetic..";
  }
  //must contain only alphanumeric
  if (!(std::find_if(lbl.begin(), lbl.end(), [](char c) { return !std::isalnum(c); }) == lbl.end())) {
    return "*** Invalid Label: non-alphanumeric chars..";
  }
  //lenght should be at most 32
  if (lbl.size() > 32) {
    return "*** Labels length is more than 32..";
  }
  return "";
}
/* This function operates on the cleaned non-empty lines of the .asm file (passed as argument)
    - implemented Section 5.2: XM2 Assembler -User's Guide
 */
bool Assembler::pass1(std::vector<std::vector<std::string>> recs) {
  //step 1 and part of Step 2 of the Ref is already done prior to this function call
  SymTab.clear(); //clear the symbol table - in case!
  //populate the built-in symbols first
  for (int i = 0; i < 8; i++) { //there are 8 sysmbols
    std::stringstream ss;       //to convert from dec to hex
    ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << i;
    SymTab.insert(SymTab.begin(), Symbol{"R" + std::to_string(i), "REG", ss.str(), i});
  }
  //test init - done - NOTE: Symbol.type should be STR -done
  /* for(auto s:SymTab){
        std::cout<<s.name<<"\t"<<s.type<<"\t"<<s.hex_value<<"\t"<<s.dec_value<<std::endl;
    } */

  //clear record to fresh start
  records.clear();
  int err_counter = 0;                         //error counter in First pass
  int loc_counter;                             //location counter
  for (int i = 0; i < raw_lines.size(); i++) { //apply pass 1 algorithm and populate each record accordingly

    //for empty lines
    if (recs[i].empty()) {
      records.push_back({raw_lines[i].data(), "", "", "", "", "", "", false, loc_counter});
      continue;
    } else { //record is not empty - check tokens
      //check all the tokens type
      std::vector<std::string> tokentypes; //container for type of each token
      for (auto tok : recs[i]) {
        tokentypes.push_back(check_token(tok));
      }

      // start applying logic
      if (!tokentypes[0].compare("LBL")) { //first token is "LBL" type
        //check for valid label name
        auto err = validate_label(recs[i][0]);
        if (!err.empty()) { //error in label - update records but not SymTab
          records.push_back({raw_lines[i].data(), "", "", "", "", "", err, true, loc_counter});
          err_counter++;
          continue;
        } else { //label has  valid name
          //check for duplicate
          bool has_dup = false;
          for (auto s : SymTab) {
            //compare
            if (!recs[i][0].compare(s.name)) { //found an entry in symbol table -
              //auto err1 = "*** Duplicate label..";
              //records.push_back({raw_lines[i].data(), "","","","","",err1,true, loc_counter});
              //continue;
              has_dup = true;
            }
          }
          if (has_dup) { //has duplicate - update records but not SymTab or loc_counter
            records.push_back({raw_lines[i].data(), "", "", "", "", "", "*** Duplicate label..", true, loc_counter});
            err_counter++;
            continue;
          } else { //valid LBL with no duplicate  - update records and symtab
            // - however check for syntax - INST/DIR must follow the first LBL
            if (tokentypes.size() == 1) { // a lone label
              records.push_back({raw_lines[i].data(), recs[i][0], "", "", "", "", "", false, loc_counter});
              //update symtab
              std::stringstream ss; //to convert from dec to hex
              ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << loc_counter;
              SymTab.insert(SymTab.begin(), Symbol{recs[i][0], "LBL", ss.str(), loc_counter});
              continue;
            }
            if (tokentypes.size() > 1 && !(!tokentypes[1].compare("DIR") || !tokentypes[1].compare("INST"))) {
              records.push_back({raw_lines[i].data(), recs[i][0], "", "", "", "", "*** Expected INST/DIR..", true, loc_counter});
              //update symtab
              std::stringstream ss; //to convert from dec to hex
              ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << loc_counter;
              SymTab.insert(SymTab.begin(), Symbol{recs[i][0], "LBL", ss.str(), loc_counter});
              err_counter++;
              continue;
            }
            if (tokentypes.size() > 1 && !tokentypes[1].compare("INST")) { //LBL +INST
              records.push_back({raw_lines[i].data(), "", recs[i][0], "INST", "", "", "", false, loc_counter});
              //update symtab
              std::stringstream ss; //to convert from dec to hex
              ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << loc_counter;
              SymTab.insert(SymTab.begin(), Symbol{recs[i][0], "LBL", ss.str(), loc_counter});
              loc_counter++;
              continue;
            }
            if (tokentypes.size() > 1 && !tokentypes[1].compare("DIR")) { //LBL +DIR
              records.push_back({raw_lines[i].data(), "", recs[i][0], "DIR", "", "", "", false, loc_counter});
              //update symtab
              std::stringstream ss; //to convert from dec to hex
              ss << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << loc_counter;
              SymTab.insert(SymTab.begin(), Symbol{recs[i][0], "LBL", ss.str(), loc_counter});
              loc_counter++;
              continue;
            }
          }
        }
      }
    }
  }
  for (auto r : records) {
    std::cout << r.src << std::endl;
    if (r.hasErr) {
      std::cout << "\t\t" << r.err_message << std::endl;
    }
  }

  for (auto s : SymTab) {
    std::cout << s.name << "\t" << s.type << "\t" << s.hex_value << "\t" << s.dec_value << std::endl;
  }
  return true;
}

/*
                // std::cout<<"original:"<<raw_lines[i].data()<<std::endl;
                // std::cout<<err<<std::endl;
                if(err.empty()){ // apparently no error found in LBL -either next token DIR/INST or empty
                    //insert label in SYMTAB
                    std::stringstream ss; //to convert from dec to hex
                    ss<<std::uppercase<<std::setfill('0')<<std::setw(4)<<std::hex<<loc_counter;
                    SymTab.insert(SymTab.begin(),Symbol{recs[i][0],"REG", ss.str(),loc_counter});
                    if(recs[i].size()==1){ // lone label - no INST/DIR
                        //store it in records
                        records.push_back({raw_lines[i].data(), recs[i][0],"","","","","",false, loc_counter});
                        loc_counter++;
                        continue;
                    }
                    else{ //label followed by INST/DIR
                        //check following token and validate
                        auto i_d = check_token(recs[i][1]);
                        if(!i_d.compare("INST")) {// it's an Instruction (INST)
                             auto err2 = validate_inst()
                    }
                    //records.push_back({raw_lines[i].data(), "","","","","","",false, loc_counter});
                }
                else{ //found err

                } 
            }

        }


    }    
    return true;
}
*/

/* This function identify all the relevant information in a line  
- creates a record for each line 
- if a line is empty (before or after removing a the comment)- creates an empty record
- flag error - if any error is found - it is stored as well
*/
void Assembler::process_lines() {

  //get the cleaned tokens
  std::vector<std::vector<std::string>> cleaned_lines = get_cleaned();

  //check - LOOKS fine
  /* 
    //std::cout<<"size(cleaned_lines): "<< cleaned_lines.size()<<"size(original): "<<raw_lines.size()<<std::endl;
    for(int i=0; i<raw_lines.size(); i++){
        std::cout<<"original:"<<raw_lines[i].data()<<std::endl;
        std::cout<<"cleaned:"<<std::endl;
        if(!cleaned_lines[i].empty()){
            for(auto word : cleaned_lines[i]){
            std::cout<<word<<std::endl;
            }
        } 
        
    }
    */
  if (pass1(cleaned_lines)) {
    std::cout << "\nWell done...so far\n";
  }
}