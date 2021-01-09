BEGIN{
    FS = ":"
    print "Name                     Exam 1     Exam 2     Exam 3    Average";
    print "==================== ========== ========== ========== ==========";
}
(NR > 1){
    sum = $2 + $3 + $4
    exam1Sum += $2
    exam2Sum += $3
    exam3Sum += $4
    studentAvg = sum / 3
    count++
    printf "%-20s %10d %10d %10d %10.1f\n",$1,$2,$3,$4,studentAvg;    
}
END{
    print "==================== ========== ========== ========== =========="
    exam1Avg = exam1Sum / count
    exam2Avg = exam2Sum / count
    exam3Avg = exam3Sum / count
    totalAverage = (exam1Avg + exam2Avg + exam3Avg) / 3
    printf "%-20s %10d %10d %10d %10.1f\n","Average",exam1Avg,exam2Avg,exam3Avg,totalAverage;
}