# Libraries
A Qt subdir project with multiple libraries

Base: 
	Is a static library
	It contains base classes that are used in most of my projects
	
Message:
	Is a shared library
	Uses the Base library 
	It contains base classes for specific SQL databases classes
	
SQL:
	Is a shared library
	Uses the Base library 
	It contains base classes for SQL 
	It also contains classes for Databases [SQLite,MySQL,MariaDb]


