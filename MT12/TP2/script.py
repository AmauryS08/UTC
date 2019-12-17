from math import *
import matplotlib.pyplot as plt
N = 10;  # Valeur de N
an=0; # Initialisation du terme An
L=10;Tmax=4;a=4; # Variable fixe
somme=[[0 for k in range(Tmax)] for k in range(L)];  #Initialisation de la somme
x=0;t=0;    # Variable x et t
for x in range(L):  # Boucle pour x
    for t in range(Tmax):   # Boucle pour t
        for i in range(N):      # Boucle pour la somme
            an= 1 - (pow(L,2)*pow(-1,i)/4*pow(pi,2)*pow(i,2)) + ((pow(L,2)/2*pi*i)*(L/2*pi*i - pow(-1,i)));  # Calcul du terme An en fonction de N
            somme[x][t] = somme[x][t] + an*sin(((i*pi)/L)*x)*exp(-((pow(i,2)*pow(a,2)*pow(pi,2))/pow(L,2))*t);  # Calcul de la somme en fonction de N, x et t
print(somme);   # On affiche le résultat de la somme
plt.plot(somme);  # On initialise la courbe
plt.show(); # On affiche la courbe
