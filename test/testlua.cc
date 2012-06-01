#include <iostream>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

void report_errors(lua_State *L, int status)
{
  if ( status!=0 ) {
      std::cerr << "-- " << lua_tostring(L, -1) << std::endl;
	      lua_pop(L, 1); // remove error message
		    }
			}

			int main(int argc, char** argv)
			{
			  for ( int n=1; n<argc; ++n ) {
			      const char* file = argv[n];

				      lua_State *L = lua_open();

					      luaopen_io(L); // provides io.*
						      luaopen_base(L);
							      luaopen_table(L);
								      luaopen_string(L);
									      luaopen_math(L);
										      luaopen_loadlib(L);

											      std::cerr << "-- Loading file: " << file << std::endl;

												      int s = luaL_loadfile(L, file);

													      if ( s==0 ) {
														        // execute Lua program
																      s = lua_pcall(L, 0, LUA_MULTRET, 0);
																	      }

																		      report_errors(L, s);
																			      lua_close(L);
																				      std::cerr << std::endl;
																					    }

																						  return 0;
																						  }
