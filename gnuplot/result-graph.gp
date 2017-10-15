set grid
set title 'Serial x Parallel Execution'
set xlabel 'I-th number found'
set ylabel 'Time (sec)'
plot 'data' u 1:2 w lp t 'Serial Execution', 'data' u 1:3 w lp t 'Parallel Execution'

