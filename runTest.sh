#!/bin/bash

cd ${tPath}
genCommand=testGenerator/gCom.in
for i in $(seq 1 1 10); do echo ${tParametr} $((${RANDOM}*${i}*${i})) > ${genCommand}; ./${generator} < ${genCommand} > t${tParametr}${i}.test ; done
rm ${genCommand}

for i in $(seq 1 1 10); do echo ; echo t${tParametr}${i}.test; ./${tester} < t${tParametr}${i}.test; done
