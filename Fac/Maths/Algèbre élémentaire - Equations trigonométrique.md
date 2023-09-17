
On souhaite résoudre des équations du type :
$$I - \left \{
   \begin{array}{l l}
      & sin(x) & = & a && x\in \mathbb{R} \\
	  & cos(x) & = & a && a \in \left[ -1; 1 \right[
   \end{array}
\right .$$
Ou :
$$ II - \left \{
   \begin{array}{l l}
      & sin(x) & = & sin(y) && x,y \in \mathbb{R} \\
	  & cos(x) & = & cos(y)
   \end{array}
\right .$$


## Proposition (Résolution des équations $I$)

Soit $a \in \left[-1; 1 \right]$

L'équation $sin(x) = a$ d’inconnu $x$ a toujours une et une seule solution dans l'intervalle $\left[-\frac\pi 2 \frac\pi 2 \right]$ (noté $arcsin(a)$ en analyse). L'ensemble des solutions de $sin(x) = a$ est l'ensemble $\left\{ arcsin(a) + 2k\pi, k \in \mathbb{Z} \right\} \cup \left\{ -arcsin(a) + 2k\pi, k \in \mathbb{Z} \right\}$

L'équation $cos(x) = a$ d’inconnu $x$ a toujours une et une seule solution dans l'intervalle $\left[0; \pi \right]$ (noté $arccos(a)$ en analyse). L'ensemble des solutions de $cos(x) = a$ est l'ensemble $\left\{ arccos(a) + 2k\pi, k \in \mathbb{Z} \right\} \cup \left\{ -arccos(a) + 2k\pi, k \in \mathbb{Z} \right\}$

Ex : 
$sin(x) = -\frac{\sqrt{3}}{2}$ 
$\iff$ $x \in \left\{ \frac\pi 3 + 2k\pi, k \in \mathbb{Z} \right\} \cup \left\{\frac{2\pi}{3} + 2k\pi, k \in \mathbb{Z} \right\}$
$\iff$ $x=\frac\pi 3 \left[ 2\pi \right]$ ou $x=\frac{2\pi} 3 \left[ 2\pi \right]$ avec la notation modulo

$cos(x) = -\frac{\sqrt{3}}{2}$ 
$\iff$ $x \in \left\{ \frac\pi 6 + 2k\pi, k \in \mathbb{Z} \right\} \cup \left\{-\frac{\pi}{6} + 2k\pi, k \in \mathbb{Z} \right\}$
$\iff$ $x=\frac\pi 6 \left[ 2\pi \right]$ ou $x=-\frac{\pi} 6 \left[ 2\pi \right]$ avec la notation modulo


## Proposition (Résolution des équations $II$)

Soit $y \in \mathbb{R}$

L'ensemble des solutions de l'équation $sin(x)=sin(y)$ est  $\left\{ y + 2k\pi, k \in \mathbb{Z} \right\} \cup \left\{ -y + 2k\pi, k \in \mathbb{Z} \right\}$

L'ensemble des solutions de l'équation $cos(x)=cos(y)$ est  $\left\{ y + 2k\pi, k \in \mathbb{Z} \right\} \cup \left\{ -y + 2k\pi, k \in \mathbb{Z} \right\}$

Ex :  $sin(2x) = sin(x)$
$\iff$ $2x=x+2k\pi, k \in \mathbb{Z}$
	ou $2x=\pi-x+2k\pi, k \in \mathbb{Z}$
$\iff$ $x=2k\pi, k \in \mathbb{Z}$
	ou $3x=\pi+2k\pi, k \in \mathbb{Z}$
$\iff$ $x=2k\pi, k \in \mathbb{Z}$
	ou $x=\frac\pi 3 + \frac{2k\pi} 3, k \in \mathbb{Z}$

Avec la notation modulo 
$\iff$ $x = 0\left[2\pi\right]$
	ou $3x = \pi\left[2\pi\right]$
$\iff$ $x = 0\left[2\pi\right]$
	ou $x = \frac\pi 3\left[2\pi\right]$


## Proposition (Résolution des équations avec $tan()$)

Soit $a \in \mathbb{R}$

L'équation $tan(x)=a$, possède une et une seule solution noté $arctan(a)$ dans l'intervalle $\left]-\frac\pi 2 \frac\pi 2 \right[$.
L'ensemble des solutions de l'équation est $\left\{ arctan(a) + k\pi, k \in \mathbb{Z} \right\}$ ou $\left\{ arctan(a)\left[\pi\right] \right\}$ en notation modulo.


## Formules d'addition et de duplication :

Théorème : soient $\alpha, \beta \in \mathbb{R}$

Alors : $sin(\alpha + \beta) = sin(\alpha)cos(\beta) + sin(\beta)cos(\alpha)$

Corollaire :
- $sin(\alpha + \beta) = sin(\alpha)cos(\beta) + sin(\beta)cos(\alpha)$
- $sin(\alpha - \beta) = sin(\alpha)cos(\beta) - sin(\beta)cos(\alpha)$
- $cos(\alpha + \beta) = cos(\alpha)cos(\beta) - sin(\alpha)sin(\beta)$
- $cos(\alpha - \beta) = cos(\alpha)cos(\beta) + sin(\alpha)sin(\beta)$
- $tan(\alpha+\beta)=\frac{tan(\alpha) + tan(\beta)}{1 - tan(\alpha) + tan(\beta)}$