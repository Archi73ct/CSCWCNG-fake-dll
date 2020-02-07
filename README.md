# CSCWCNG-fake-dll
This project is made to compile a dll that functions like the CSCWCNG.dll file found on Wincor Nixdorf ATM machines.
This can be used to communicate with ATM malware that expects this kind of DLL.

NB:
Make sure to compile with no debugging information from the linker, a lot of the malware is looking up the dll functions by name.
