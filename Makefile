LIBSRC = SieveEratosthenesRBO.c
PROJECT1 = checkPrime
PROJECT2 = primeByNumber
TESTS = tests/
GENERATOR = testGenerator
GENERATORSRC = $(wildcard $(TESTS)$(GENERATOR)/*.c)
TESTER = tester
TESTERSRC = $(wildcard $(TESTS)$(TESTER)/*.c)
GENERATOREX = $(GENERATOR)/$(GENERATOR).out
TESTEREX = $(TESTER)/$(TESTER).out
ENV = env tPath=${TESTS} generator=${GENERATOREX} tester=${TESTEREX}

build :
	gcc $(LIBSRC) $(PROJECT1).c -lm -O3 -o $(PROJECT1).out
	gcc $(LIBSRC) $(PROJECT2).c -lm -O3 -o $(PROJECT2).out

buildTestGenerator :
	gcc $(GENERATORSRC) -O3 -o $(TESTS)$(GENERATOREX)
	
buildTester :
	gcc $(TESTERSRC) SieveEratosthenesRBO.c -lc -O3 -o $(TESTS)$(TESTEREX)
	
testFillSieve:
	$(ENV) tParametr="f" ./runTest.sh
	
testIsPrime:
	$(ENV) tParametr="i" ./runTest.sh
