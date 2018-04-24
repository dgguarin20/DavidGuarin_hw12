DavidGuarin_graph.py:advection.txt
	python DavidGuarin_graph.py

advection.txt:DavidGuarin_advection.cpp
	c++ DavidGuarin_advection.cpp
	./a.out >> advection.txt
