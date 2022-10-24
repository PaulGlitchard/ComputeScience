1) gdb <filename> | gdb --args <filename> arg1 arg2
2) layout src -> shows you your code,  shows you where code stopped working
3) run -> runs your code
4) refresh -> refresh the display
5) break POINT -> set a breakpoint can be line number, function, etc.
6) next (n) -> one step
7) continue -> continue to next breakpoint
8) print VARIABLE ->prints variable value
9) watch VARIABLE -> watch variable for changes
10) pidof <filename> > sudo gdb <pid>
11) gdb <filename> > run > *deadlock* > CTRL+C > thread apply all bt -> backtracks all threads if program stuck somewhere