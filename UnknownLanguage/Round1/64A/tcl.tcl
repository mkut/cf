set n [gets stdin]
set ans 1
for {set cnt 1} {$cnt <= $n} {incr cnt} {
	set ans [expr $ans * $cnt]
}
puts "$ans"
