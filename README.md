stcalc - simple terminal calculator
===================================
a simple command-line calculator written in C

Known Issue(s)
--------------
- pressing "Ctrl + D" (EOF) will result in never-ending loop.
	- if this happens, kill the process using another program such as `killall`

Installation
------------
Enter the following command the build and install stcalc (run as root):

	make install

Removal
-------
To uninstall, run (as root):

	make uninstall

Author
------
Madison Lynch <madi@mxdi.xyz>
