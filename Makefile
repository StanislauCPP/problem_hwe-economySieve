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
	gcc $(LIBSRC) $(PROJECT1).c -lm -O2 -flto -o $(PROJECT1).out
	gcc $(LIBSRC) $(PROJECT2).c -lm -O2 -flto -o $(PROJECT2).out

buildTestGenerator :
	gcc $(GENERATORSRC) -lm -O2 -flto -o $(TESTS)$(GENERATOREX)
	
buildTester :
	gcc $(TESTERSRC) SieveEratosthenesRBO.c -lm -O2 -flto -o $(TESTS)$(TESTEREX)
	
testIsPrime:
	$(ENV) tParametr="i" ./runTest.sh
	
testPrimeNumFromSieveByNumber:
	$(ENV) tParametr="p" ./runTest.sh
