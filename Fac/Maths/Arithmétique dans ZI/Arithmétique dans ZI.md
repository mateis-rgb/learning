# Arithmétique dans $\mathbb{Z}$ 

<u>Récurrence forte</u>

- Init:
	On vérifie que $P(n_0)$ est vraie
- Hérédité:
	On suppose que $P(n_0),...,P(n)$ sont vraies et on montre $P(n+1)$ est vraie.

Alors, le principe de récurrence forte dit que $P(n)$ est vrai $\forall n >= n_0$

Exemple  :
	Soit $(U_n), n >= 0$ une suite définie par $U_0 = 1, \forall n >= 0$ 
	$U_{n+1}= 1 + U_0 + ... + U_n$
	$U_{n+1}= 1 +$ somme de $k=0$ à $n$ de $U_k$
	On cherche à exprimer $U_n$ en fonction de $n$
	On calcule $U_1=2, U_2=4, U_3=8, U_4=16$

Récurrence forte:
	On montre que $U_n = 2^n = P(n)$
* Init:
	On vérifie que $P(0)$ est vraie (triviale)
* Hérédité :
	On suppose que $P(0), ..., P(n)$ sont vraies et on montre que $P(n+1)$ est vraie
	$U_{n+1} = 1 + U_0+...+U_n=1+2^0+...+2^n$ 

$(a-1)(a^n+a^{n+1}+...+a+1) = a^{n+1}+a^n+...+a^2+a-a^n-a^{n+1}-...-a^2-a-1$
$(a-1)(a^n+a^{n+1}+...+a+1) = a^{n+1}-1$
avec $a=2:2^n+...+1=2^{n+1} = 2^{n+1}$
$U_{n+1}=1+(2^{n+1}-1)=2^{n+1}$
donc $P(n+1)$ est vraie, d'après le principe de récurrence forte, $P(n)$ est vraie $\forall n >= 0$


## Nombres premiers

<u>Déf:</u>
	Soient $a,b\in\mathbb{Z}$ on dit que $b$ est un diviseur de a.
	Si $a=bq$ pour un $q\in\mathbb{Z}$ 
<u>Déf:</u>
	Un nombre $n\in\mathbb{N}$\\{0;1} est premiers si $n$ n'admet que deux diviseurs positifs 
	$P=$ l'ensemble des nombres premiers
		$=\{2;3;5;7;11;13;17;19;...\}$
	$9=3\times3$
	$10=2\times5$
	$32=2\times2\times2\times2\times2$
	<u>Thm:</u>
	Pour tout $n\in\mathbb{N}$\\{0;1\} il existe $P_1,...,P_k$ des nombres tels que $n=P_1,...,P_k$ 
<u>Dém:</u> (Par récurrence forte)
* Init: On vérifie que $P(2)$ est vraie
	$2=2$ est le produit d'un nombre premier
* Hérédité: 
	On suppose que $P(2),...P(n)$ sont vraies, et on montre que $P(n+1)$ est vraie
	Si $n+1$ est premier alors $P(n+1)$ est vraie.
	Si $n+1$ n'est pas premier alors $n+1=pq$ avec $p,q\in\mathbb{N}$
	Par l'hyp. de récurrence, $P(p)$ et $P(q)$ sont vraies, donc $p=p_1,...,p_k$ , $q=q_1,...,q_k$ , $p_i, q_j$ sont premiers
	Donc $n+1=pq=p_1,...,p_k\times q_1,...,q_l$
	
	On conclut donc que $P(n+1)$ est vraie
	Par le principe de récurrence forte, $P(n)$ est vraie, $\forall n >= 2$
	<u>Thm:</u>
	Il y a une infinité de nombres premiers
<u>Dém:</u>
	Par l'absurde, on suppose $P=\{p_1,p_2,...,p_n\}$ et $p_1<p_2<...<p_n$
	On pose que $m=1+p_1\times p_2\times...\times p_n$
	On remarque que $m>P_i, \forall i$
	Donc $m$ n'est pas premier
	On écrit $m=1+q_1\times q_2\times...\times q_k$ avec $q_1,...,q_k$ premiers
	Il existe $i$ tel que $P_i=q_1$ Alors

$1=m-p_1\times p_2\times...\times p_n$
$1=q_1(q_2\times ... \times q_k)-p_1\times p_2\times...\times p_n$

