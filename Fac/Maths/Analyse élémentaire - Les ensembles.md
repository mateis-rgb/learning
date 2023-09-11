
Connaissances :
	$\mathbb{N}$ -> entiers naturels
	$\mathbb{Q}$ -> entiers rationnels
	$\mathbb{Z}$ -> entiers relatifs
	$\mathbb{R}$ -> entiers réels
	$\mathbb{C}$ -> les nombres complexes

“Un ensemble est un sac dans lequel, je trouve des éléments dont l'emplacement des éléments dans le sac n'importe pas.“

## I - Les ensembles définis en extensions.

Il existe plusieurs façons de définir un ensemble, une premiere façon est par "extension", l'ordre n'importe pas, on dresse la liste de ces éléments.

Ex: $E=\left\{ 1; \pi; \frac{-3}{7}; \sqrt{5}; \frac{-1}{2}+i \right\}$

Donc on peut écrire $E$ d'une manière différente.
=> $E = \left\{ \frac{-3}{7}; \pi; \frac{-1}{2}+i; 1; \sqrt{5} \right\}$

-> Ensemble ne contenant aucun éléments $\left\{\right\}$, est noté $\emptyset$


## II - Appartenance, inclusion et égalité des ensembles.

Notations:
- $\in$ :
	- appartenance à un ensemble
	- s'écrit $x \in E$
	- soit "x appartient à E"
	- ou "E a pour élément x"
- $\notin$ 
	- négation d'appartenance à un ensemble
	- s'écrit $x \notin E$
	- soit "x n'appartient pas à E"
- $\subset$ 
	- inclusion dans un ensemble, si tout les éléments du premier ensemble sont dans le second
	- s'écrit $E\subset F$ si $\forall x \in E, x \in F$
	* soit "pour tout x appartenant à E, x appartient à F, alors E est un sous ensemble de F"
* $\not\subset$
	* n'est pas inclu dans l'ensemble
	* s'écrit $E \not\subset F$ si $\exists x \in E, x \not\in F$
	* soit "il existe un x appartenant à E qui n'appartient pas à F alors E n'est pas inclu dans F"
* $=$ 
	* égalité de deux ensembles si tout les éléments d'un ensemble sont dans l'autre
	* s'écrit $A=B$ $\iff$ $\forall a \in A, a \in B$ et $\forall b \in B, b \in A$ 
	* s'écrit aussi $A=B$ $\iff$ $A \subset B$ et $B \subset A$  


## III - Définition d'un ensemble par compréhension

Une seconde façon de définir un ensemble est par "compréhension". Pour utiliser cette méthode de définition, il faut trouver une caractéristique, une propriété qui s'applique aux éléments que l'ont veux ajouter. On diras alors que l'ensemble est défini par compréhension.

La structure :
	$E = \left\{ x \in \mathbb{N} | \exists k \in \mathbb{N}, n = 2k \right\}$ 
	=> On créer l'ensemble E qui est un sous ensemble de $\mathbb{N}$ mais on ne met dedans que des éléments pairs

En général :
	$\left\{ x \in E | P(x) \right\}$
	=> E est un ensemble
	=> P une propriété (ou condition) défini $\forall E$

Exemples :
- $\left\{ x \in \mathbb{R} | x \ge 0 \right\}$ on note cet ensemble $\mathbb{R}^{+}$
- $\left\{ x+iy \in \mathbb{C} | x \in \mathbb{R}, y \in \mathbb{R}, y > 0 \right\}$ on nomme cet ensemble, le demi plan de Pointcaré


## IV - Opérations sur les ensembles

Il existe plusieurs opérations sur les ensembles, l'intersection, l'union, le produit cartésien, etc.

* L'union
	* $A \cup B$, les éléments appartiennent à A ou à B.
	* $A \cup B$ = $\left\{ x | x \in A || x \in B \right\}$
* L'intersection
	* $A \cap B$, les éléments appartient à A et à B.
	* $A \cap B$ = $\left\{ x | x \in A, x \in B \right\}$
* Privation d'un élément dans un ensemble
	* $A \setminus B$ = $\left\{ x | x \in A, x \not\in B \right\}$
* Éléments complémentaires
	* $A^{C}$=$\left\{ x \in B | x \not\in A \right\}$
* Le produit cartésien
	- ATTENTION ⚠️: L'ordre du produit n'est pas commutatif
	* $A \times B$ = $\left\{ (a,b) | a \in A b \in B \right\}$
	* $\mathbb{R}\times\mathbb{R}$ = $\left\{ (x, y) | x\in\mathbb{R}, y\in\mathbb{R} \right\}$ = $\mathbb{R}^{2}$


## V - Intervalles de $\mathbb{R}$

ATTENTION ⚠️: $\mathbb{R}$ est muni d'une relation d'ordre $\le$ .

* $[A, B]$ = $\left\{ x \in \mathbb{R} | a \le x \le b \right\}$
=> L'intervalle est fermé, il inclu donc les valeurs misent aux bornes de celui ci.
* $]A, B[$ = $\left\{ x \in \mathbb{R} | a < x < b \right\}$
=> L'intervalle est ouvert, il exclu donc les valeurs misent aux bornes de celui ci.

Remarque$^{1}$: il existe des intervalles semi ouvert.
Remarque$^{2}$: les intervalles $\mathbb{R}$ et $\emptyset$ sont ouverts et fermés.


## VI - La minoration et la majoration d'ensembles

Soit a un sous ensemble de $\mathbb{R}$ :
	$A \subset\mathbb{R}$ $\iff$ $\forall (x,y) \in A \times A, x \le y, [x,y] \subset A$

* A est dit majoré si $\exists M \in\mathbb{R}, \forall x \in A, x \le M$
* A est dit minoré si $\exists m \in\mathbb{R}, \forall x \in A, m \le x$

Remarque: A est borné s'il est minoré et majoré.
