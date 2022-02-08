#! /bin/bash

# Automated testing using bash for Hacker Rank challenges.
prog="./counting_valleys.o"
indir="tests/in"
expdir="tests/exp"
resdir="tests/res"
cpu=10
climit=1000
for tfile in ${indir}/* ; do
    fname=$(basename ${tfile%%.*})
    efile="${expdir}/${fname}.exp"
    ofile="${resdir}/${fname}.out"
    dfile=$(mktemp)
    retv=0
    $(ulimit -t ${cpu}; ${prog} < ${tfile} 2>&1 > /dev/null)
    retv=$?
    if [ $retv -ne 0 ] ; then
        echo "${tfile} failed: non-zero exit status"
    else
        (ulimit -t ${cpu}; (${prog} < ${tfile} 2>&1 | head -c ${climit} > ${ofile}))
        (((diff ${ofile} ${efile} 2>&1 > ${dfile}) && (echo "${tfile} passed")) || (echo "${tfile} failed"))
    fi
done
