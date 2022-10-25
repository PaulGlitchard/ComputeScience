1) gdb <filename> -> debug files
2) layout src -> displays your code
3) run @param1 @param2 ... -> runs code in gdb (@param = arguments)
4) break <POINT> -> POINT where the break should be can be for example line number
5) continue -> continue to next breakpoint
6) s -> goes one step
7) for deadlock backtrack
	1) thread apply all bt -> prints all threads and in which functions and lines they stuck
	2) p <mutex_name> -> prints data of mutex (owner is the thread who i currently allowed to execute the locked area (the LWP number from 7.1))