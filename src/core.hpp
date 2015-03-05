/*FILE: core.hpp
 *Author: Michael Huelsman
 *Description:
 *  Interface for a core ADT
 */

#define CORE_SIZE 1001
#define MAX_CORE_LOC 999
#define DEFAULT_VAL 0.1234567
#define VALID_FLAG_LOC 1000
#define COMP_SUCCEED 1
#define COMP_FAIL 0

class Core{
public:
  //Precond:
  //  None
  //Postcond:
  //  All core locations with the exception of flags is set to default
  Core();

  //Precond:
  // addr carries a valid address
  // to carries a valid double
  //Postcond:
  // The address specified by addr now has the value of to
  // Returns false if change could not be made
  bool changeAddr(int addr, double to);

  //Precond:
  // addr is a valid address
  //Postcond:
  // Returns the value in the address specified by addr
  double getAddrContent(int addr);
protected:
private:
  double data[CORE_SIZE];
};
