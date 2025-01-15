set terminal pngcairo enhanced
set output 'plot.png'

# Définition des titres et des légendes
set title "Évolution de la solution numérique et exacte"
set xlabel "Position"
set ylabel "Valeur"

plot 'build/Variable_u_n_0.data' using 1:2 with lines lw 2 title 'initial condition' ,\
     'build/Variable_u_np1_19.data' using 1:2 with lines lw 2 title 'first order upwind solution' ,\
     'build/Variable_u_ref_10.data' using 1:2 with lines lw 2 title 'Exact solution'
     #'build/Variable_u_np1_2nd_order_10.data' using 1:2 with lines lw 2 title 'Second order Lax_Wendroff Solution'  
    