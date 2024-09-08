On sait que pour tout $\alpha, \beta$
$\left \{
	\begin{array}{l l}
		cos(\alpha + \beta) = cos(\alpha) cos(\beta) - sin(\alpha) sin\beta \\
		cos(\alpha - \beta) = cos(\alpha) cos(\beta) + sin(\alpha) sin(\beta)
	\end{array}
\right .$
$
\Rightarrow cos(\alpha+\beta) + cos(\alpha-\beta) = 2cos(\alpha) cos(\beta) \\
\Rightarrow cos(\alpha-\beta) - cos(\alpha+\beta) = 2sin(\alpha) sin(\beta)
$
Proposition: Transofrmation somme-produit
Soient $\alpha, \beta \in \mathbb{R}$, alors:
$
cos(\alpha)cos(\beta)=\frac 1 2 (cos(\alpha+\beta) + cos(\alpha-\beta)) \\
sin(\alpha) sin(\beta) = \frac 1 2 (cos(\alpha-\beta) - cos(\alpha+\beta)) \\
cos(\beta) sin(\alpha)^* = \frac 1 2 (sin(\alpha + \beta) + sin(\alpha - \beta))
$

Preuve: ⚠️ On ne prouve que la 3$^{ème}$ égalité$^*$
On a
$\left \{
	\begin{array}{l l}
		sin(\alpha + \beta) = sin(\alpha) cos(\beta) + sin(\alpha) cos\beta \\
		sin(\alpha - \beta) = sin(\alpha) cos(\beta) - sin(\alpha) cos(\beta)
	\end{array}
\right .$
$
\Rightarrow sin(\alpha+\beta) + sin(\alpha-\beta) = 2sin(\alpha) cos(\beta) \\
\Rightarrow sin(\alpha)cos(\beta) = \frac 1 2 (sin(\alpha + \beta) + sin(\alpha - \beta))
$

Remarque :
$
cos(\alpha) + cos(\beta) \\
= cos(\frac{\alpha + \beta}{2} + \frac{\alpha - \beta}{2}) + cos(\frac{\alpha + \beta}{2} - \frac{\alpha - \beta}{2}) \\
$
Ici on posera $\frac{\alpha + \beta}{2} = \theta, \frac{\alpha - \beta}{2} = \phi$

$
= cos(\theta + \phi) + cos(\theta - \phi) \\
= 2cos(\theta)cos(\phi) \\
= 2cos(\frac{\alpha + \beta}{2})cos(\frac{\alpha - \beta}{2}) \\
$
Proposition: Soient $\alpha, \beta \in \mathbb{R}$
$
cos(\alpha) + cos(\beta) = 2cos(\frac{\alpha + \beta}{2})cos(\frac{\alpha - \beta}{2}) \\
sin(\alpha) + sin(\beta) = 2sin(\frac{\alpha + \beta}{2})cos(\frac{\alpha - \beta}{2})
$