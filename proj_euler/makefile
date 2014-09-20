# specify [NAME].cpp to build corresponding executable
#
# example: make p4 			--> build p4.cpp into p4.exec

CXX= g++-4.9
CXX_FLAGS= -std=c++14 -Wall -Wextra

%:
	@echo 'Building $@.cpp...'
	${CXX} ${CXX_FLAGS} $@.cpp -o $@.exec
	@echo
	@echo 'Running $@.exec...'
	@echo '_________________________________________'
	./$@.exec
	@echo '_________________________________________'
	@echo

clean:
	rm *.exec
