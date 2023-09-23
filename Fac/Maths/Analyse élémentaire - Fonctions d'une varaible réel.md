Définition :
- Une fonction d'une variable réelle est la donnée d'un domaine $X \subset \mathbb{R}$ d'un ensemble donné $Y \subset \mathbb{R}$ et pour tout $x \in \mathbb{R}$, d'un unique $y\in\mathbb{R}$ appelé l'image de $x$ par la fonction $f$.
- L'image de $f$ on dit $f(x)$ est l'ensemble de toutes les images de $f(x)=\{ f(x), x\in\ X \}$.
- Un antécédent de $y \in Y$ par la fonction $f$ est un élément de $x\in X$ tel que $y=f(x)$.
- L'ensemble des antécédents de $y$ par la fonction $f$ est noté $f^{-1}(\{ y \})=\{ x \in X, f(x)=y \}$

Exemple :

$f[ 1; 3] \mapsto \mathbb{R}$
$f: x\mapsto 2x+1$

- L'image de $f: f([1;3[) \subset [3; 7[$
Soit $y\in[3; 7[$, il existe un antécédent dans $[1;3[$
$$
	3 \leqslant y < 7 \\
	\iff 2 \leqslant y-1 < 6 \\
	\iff 1 \leqslant \frac{y-1}{2} < 3
$$
Donc ici $\frac{y-1}{2} = x$.
Donc $x$ est un antécédent de $y$ dans $[1;3[$ donc $[3;7[ \subset f([1;3[)$.
L'image de $f$ est $[3;7[$
- Les antécédents de 4 $(\in [3;7[)$
On cherche les $x\in [1;3[$ tels que :
$$
f(x)=4 \\
\iff 2x+1=4 \\
\iff 2x=3 \\
\iff x=\frac3 2
$$
De plus $\frac 3 2 \in [1;3[$, donc 4 a un antécédent par la fonction $f$ qui est $\frac3 2$.

Définition :
- Fonctions usuels :
	- Polynômes :
	Soit $n \in \mathbb{N}$ et soient $a_{0}, ..., a_{n} \in \mathbb{R}$
	La fonction $f: \mathbb{R} \mapsto \mathbb{R}$,
	$f:x \mapsto a_{0} + a_{1}x+...+a_{n}x^{n}$
	est une fonction polynôme de degré $n$.

	- Valeur absolue :
	$\mid\cdot\mid \mathbb{R}\mapsto\mathbb{R}$
	$x \mapsto \left \{
		\begin{array}{r l}
			-x & si & x<0 \\
			x & sinon
		\end{array}
	\right .$
		- Propriété (inégalité triangulaire)
		Soient $x,y \in\mathbb{R}$, on a :
		$\mid x+y\mid \leqslant\mid x\mid + \mid y\mid$
		$\mid \overrightarrow{X}+\overrightarrow{Y}\mid \leqslant\mid \overrightarrow{X}\mid + \mid \overrightarrow{Y}\mid$
		
		- Preuve :
		Soient $x, y\in \mathbb{R}$,
		$-\mid x\mid \leqslant x\leqslant\mid x\mid$
		et $-\mid y\mid \leqslant y\leqslant\mid y\mid$
		En somme, les inégalitées donnent : $-(\mid x\mid + \mid y\mid) \leqslant x+y\leqslant\mid x\mid+\mid y\mid$
		- A SAVOIR!
		$-K\leqslant t\leqslant K$
		$\iff \mid t\mid\leqslant K$
		
		Donc : $\iff\mid x+y\mid \leqslant\mid x\mid + \mid y\mid$

	- Racine Carré:
	