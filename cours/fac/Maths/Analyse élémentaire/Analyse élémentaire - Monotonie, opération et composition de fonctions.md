Définition: Monotonie
Soit $f: D\rightarrow\mathbb{R}$
- $f$ est dite croissante sur $D$ si pour tout $a, b \in D$
$$a\leqslant b \Longrightarrow f(a) \leqslant f(b)$$
- $f$ est dite décroissante sur $D$ si pour tout $a, b \in D$
$$a\leqslant b \Longrightarrow f(a) \geqslant f(b)$$
- $f$ est dite monotone si elle est croissante ou décroissante

Définition: Minoration et Majoration
- $f$ est dite minorée sur $D$ si son image $f(D)$ est une partie minorée de $\mathbb{R}$.
- $f$ est dite majorée sur $D$ si son image $f(D)$ est une partie majorée de $\mathbb{R}$.
- $f$ est dite bornée sur $D$ si elle est minorée et majorée.

Définition: Opération de fonction
Soient $f:D \rightarrow\mathbb{R}$
et $g: D\rightarrow\mathbb{R}$
- La somme de $f+g$ est la fonction
$$
f+g: D\rightarrow\mathbb{R} \\
f+g: x \mapsto f(x)+g(x)
$$
- Le produit $fg$ est la fonction
$$
fg: D\rightarrow\mathbb{R} \\
fg: x \mapsto f(x)g(x)
$$
- Soit $\lambda\in\mathbb{R}$, la fonction $\lambda f$ est la fonction
$$
\lambda f: D\rightarrow\mathbb{R} \\
\lambda f: x\mapsto\lambda f(x)
$$

Définition : Compoition de fonction
Soient $f:D \rightarrow\mathbb{R}$
et $g: D\rightarrow\mathbb{R}$

Si $f(D_f) \rightarrow\mathbb{R}\subset D_g$ alors la composé $g\circ f$ est la fonction composé
$g\circ f: D_f \rightarrow \mathbb{R}$
$g\circ f: x \mapsto g\circ f(x) = g(f(x))$

Exemple: Soient $f$ et $g$ 
$f: [0; +\infty[\rightarrow\mathbb{R}$
$ f: x \mapsto\sqrt x $
$ g: \mathbb{R} \rightarrow \mathbb{R} $
$ g: x \mapsto x + 1 $

$$
g\circ f:[0: +\infty[\rightarrow \mathbb{R} \\
g\circ f: x \mapsto \sqrt x + 1
$$
En revanche on ne peut pas définir $f\circ g$ car $g(\mathbb{R}) \not\subset [0; +\infty[$.
Soit
$\tilde g: [-1; +\infty[ \rightarrow\mathbb{R}$
$\tilde g: x \mapsto x+1$
Cette fois, l'image de $\tilde g$ est $[0; +\infty[$ donc on peut définir la composé
$f\circ\tilde g: [-1; +\infty[\rightarrow \mathbb{R}$
$f\circ\tilde g: x \mapsto \sqrt{x+1}$