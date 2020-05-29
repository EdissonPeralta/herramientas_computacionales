set term pdf
set out '1.pdf'
set xlabel 'n'
set ylabel 'Delta'
set title 'SENO'
# Fill here to set log scale in y
plot 'datos.txt' #w lp
