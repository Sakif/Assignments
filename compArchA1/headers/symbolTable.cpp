#include <string>
#include <list>

using namespace std;

enum symbolType = {UNKNOWN,REGISTER,LABEL};

struct symbol{
	string name;
	int value;
	symbolType type;
};

class symbolTable{
	private:
	list<symbol> symbolList;
	bool isInTable(string) const;
	public:
	void addToTable(string,int,symbolType);
	symbol findSymbol(string);
	
};