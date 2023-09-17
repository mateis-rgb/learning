
Le C++ est un langage de programmation : il sert donc à écrire des applications informatiques. Il s'agit d'ailleurs d'un des langages de programmation les plus utilisés aujourd'hui. Chaque programme en C++ doit être écrit en respectant des règles d'écriture très strictes que nous étudierons petit à petit.


## Table des matières




## Importations de modules

Un module est constitué d'un ou plusieurs fichiers de code source compilés dans un fichier binaire. Le fichier binaire décrit tous les types, fonctions et modèles exportés dans le module. Lorsqu'un fichier source importe un module, le compilateur lit le fichier binaire qui contient le contenu du module.

Pour importer un module il faut faire l'instruction suivante :

```c++
#include <module>
```

Ainsi, à la base de tout les programme il y a l'instruction suivante :

```c++
#include <iostream>
```


## La fonction `main()`

La fonction `main()` est l'endroit où votre code source commence l'exécution. Il est a noté que si aucune instruction est noté dans la fonction `main()` mais a l’exterieur de cette fonction, alors rien ne s’exécuteras.

La fonction `main()` se définit ainsi :

```c++
int main () 
{
	// code

	return 0;
}
```

Il est important de mettre l'instruction `return 0;` car sinon le programme ne s’arrête pas. De plus, le 0 est important car il signifie au compilateur que le programme à terminer sans problème.

ATTENTION ⚠️ : Il est important de mettre le point virgule `;` a la fin de chaque instruction pour signifier la fin de la ligne.


## Les variables

Les variables servent à stocker des informations, de par leurs types et leurs valeurs. On définit une variable de la manière suivante :
``` cpp
int x = 3;
```
*Par exemple : ici on définit la variable "x" qui est un entiers et qui a pour valeur 3.*

Plus généralement, on définit une variable par un type et un nom. Le nom d'une variable à une syntaxe bien particulière qui doit être respectée :
* on ne commence jamais par un chiffre ou caractère spécial
* on peut utiliser des lettres minuscules et majuscules, des chiffres (après le premier caractère) et des tirets du bas (ou underscore)
* par conventions, dans ce cours, nous verrons une façon de nommer les variables : 
	* si le nom de la variable est en un seul mot :
		- on met tout le mot en minuscule
	- sinon :
		- on met toute la phrase attaché en minuscule 
		- sauf les premières lettre de chaque mot (excepté le premier mot (cf. exemples de variables ci-dessous))

ATTENTION ⚠️ : Il faut absolument typer les variables et pour cela il existe plusieurs types, voici les plus utilisés :

```cpp
int // entier
float // nombre a virgule
double // nombre a vrigule (plus grand ou égale en taille que le float)
char // caractère
bool // booléen (vrai ou faux)

// si besoin d'optimisation sur du coût en mémoire du programme il existe :
short // pour un entier court
long // pour un entier long
signed // pour une variable signé (qui contient un signe + ou -)
unsigned // pour une variable non signée (qui ne contient pas de signe + ou -)
```

Une fois les types de variables découvert, la syntaxe... Pour créer une variable il y a une syntaxe à respecter, la voici :

```cpp
// syntaxe
<type de la variable> <nom de la variable> = <valeur>;

// ex
int a;
char toto = "b";
bool ceciEstUnNomLong = false;
```

ATTENTION ⚠️ : Il est a noter qu'il n'est pas obligé de donner une valeur au variable, la seule chose d'obligatoire est de les déclarer pour pouvoir les utiliser.

De plus, il existe certain mots clés que l'ont peut ajouter aux variables tel que :

```cpp
// mots clés
const // pour les variables constantes
void // qui permet de définir une fonction (cf. partie sur les fonctions)
struct // qui permet de définir une structure (on le verra dans un prochain cours)

// ex
// On créer un booléen qui ne pourra pas être modifier par la suite
const bool toto = false; 
void HelloWorld () {} // fonction sans type de retour
struct eleve {
	string nom; // c'est comme si on définissait une variable classique
	int age;
	// ect...
}
```

Il est aussi possible d'utilisé des raccourcis pour l'incrémentation et la décrémentation de variables : 

```cpp
int x = O;

x += 1; // => x = x + 1;
x -= 1; // => x = x - 1;

x++; // x = x + 1;
++x; // x = 1 + x;

x--; // x = x - 1;
--x; // x = 1 - x;
```
*ATTENTION ⚠️ : L'ordre est important*.

## La structure d'un programme

Pour qu'un programme fonctionne, il faut qu'il y ait un minimum d'élément dans le fichier `.cpp` pour ça on va commencer par importer la librairie standard :

```cpp
#include <iostream>
```

Ensuite on va définir le contexte (ou namespace), celui ci va nous servir a identifier et grouper un ensemble logique d'éléments utilisés par le programme :

```cpp
using namespace std;
```
*Pour faire simple, ça évite au développeur d'avoir à écrire `std::` devant les instructions qui le nécessitent.*

Ensuite on écrit notre fonction principale :

```cpp
int main ()
{
	// code
	
	return 0;
}
```

Et maintenant on combine tout ça :

```cpp
#include <iostream>

using namspace std;

int main ()
{
	// code
	
	return 0;
}
```

Il faut au minimum écrire ça pour que le programme soit compilé et exécuté (cf. partie sur la compilation et l'exécution ci-dessous).


## La compilation et l'exécution

Une fois le programme fait, il faut l'enregistrer, soit en faisant `fichier -> enregistrer` soit avec un raccourcis `cmd + s` sous macOs, `ctrl + s` sous Windows et Linux, ou voir selon l'éditeur. Pour l'enregistrer, il vous faudra lui donner un nom suivit de l'extension `.cpp`, si cette extension manque, ça ne fonctionneras pas. 

ATTENTION ⚠️ : sur certains éditeurs un type de fichier est présélectionné, faites donc attention à choisir ou bien l'extension que vous souhaitez ou bien a choisir "tout les fichiers" et a noter a la fin `.cpp`.

Lorsque le fichier est enregistrer et bien nommé, il faut le compiler, pour cela on vas utiliser la commande :

ATTENTION ⚠️ : Pour compiler le programme, il faut dans le terminal être dans le répertoire où se trouve le programme, ou écrire le chemin d'accès complet du fichier.

``` sh
g++ <nom du fichier en entré>.cpp -o <nom du fichier en sortie>.out # sous Linux et macOs

g++ <nom du fichier en entré>.cpp -o <nom du fichier en sortie>.exe # sous Windows
```
*Le paramètre de la commande "-o" permet de définir le fichier de sortie après la compilation.*

Remarque : s'il y a des erreurs le compilateur les signaleras et indiqueras l'erreur ainsi que la ligne dans le code ainsi que le caractère.

Si `g++` n'est pas installer sur votre ordinateur, regardez sur internet ou sur le cours dédier (s'il existe, ou demandez le moi). 

Après tout ça, le programme est compiler, il faut maintenant l'exécuter pour qu'il fonctionne.

Sous macOs et Linux, il faut lancer la commande suivante : 

```sh
./<nom du fichier compilé>.out 
```
*Si on se trouve dans le même répertoire.*

```sh
/<chemin d accès complet du fichier compilé>.out
```
*Si on ne se trouve pas dans même répertoire.*

Remarque : dans le terminal, pour les slash "/" des chemin d’accès aux fichier, sous Windows, ces slash, sont inversées. Cela donne quelque chose comme ça : "\\ C: \\ Windows \\ etc".

Sous Windows, il faut lancer la commande suivante : 

``` cmd
.\<nom du fichier compilé>.exe 
```
*Si on se trouve dans le même répertoire.*

```cmd
\<chemin d accès complet du fichier compilé>.out
```
*Si on ne se trouve pas dans même répertoire.*

Et lorsque la commande est lancer le programme se lance.


## Les entrées et sorties

En C++ comme dans d'autres langages il est possible à l'utilisateur de communiquer avec le programme par ces périphériques d'entrée (clavier, souris, etc) et de sortie (écran).

Ici nous ne verrons que les entrées de l'utilisateur au clavier et en sortie les messages dans le terminal.

Pour commencer, le `cout`, littéralement "character out" en anglais. `cout` est un objet utiliser pour afficher la sortie sur le périphérique de sortie standard, en clair, `cout`est un objet qui permet d'afficher des messages ou des variables ou des expressions interprétées dans le terminal lors de l'exécution du programme.

On l’utilise de la manière suivante :

```cpp
cout << "une chaine de caractère";

// sortie : une chaine de caractère
```
*On utilise les chevrons vers la gauche pour signifier que ce qu'on met avant les chevrons vont dans la sortie et non l'inverse.*

De plus, il est possible de combiner plusieurs expressions dans le `cout`:

```cpp
int toto = 3;

cout << "Ceci est une variable " << toto << endl;

// sortie : Ceci est une variable 3
```
*On peut également utiliser `endl` pour dit fait un saut de ligne*.


Ensuite, le `cin` littéralement "character input" en anglais. `cin` est un objet est utilisé pour accepter l'entrée du périphérique d'entrée standard, c'est-à-dire clavier, en clair, `cin`est un objet qui permet a l'utilisateur d'entrer une chaine de caractère via son clavier dans le terminal lors de l'exécution du programme.

On l’utilise de la manière suivante :

```cpp
int uneVariableARemplir;

cin >> uneVariableARemplir;
```
*On utilise les chevrons vers la droite pour signifier que ce qu'on met en entré via le `cin` va dans la variable*.

De plus, il est possible de combiner plusieurs expressions dans le `cin` et de les afficher avec le`cout`:

```cpp
int toto;
int deuxiemeVar;

cout << "Entrez deux valeurs entières : " << endl;
cin >> toto >> deuxiemeVar;

cout << "Ce sont deux variables qui ont été remplies " << toto << " et " << deuxiemeVar << endl;
```


## Les opérateurs & opérateurs logiques

En informatique, l'ordinateur ne comprend que des 0 et des 1, comme l’électricité qui n'a que deux états ouvert (0) ou fermé (1). Le C++ comme dans d'autres langages contient des opérateurs (ou comparateurs) et des opérateurs logiques :

Tout d'abord commençons par les opérateurs, ceux ci servent à faire des comparaisons entre des valeurs ou des variables : 

```cpp
< // strictement inferieur
<= // inferieur ou égale
> // strictement supérieur
>= // supérieur ou égale
== // comparateur d'égalité, à ne pas confondre avec l’afectation qui est un égale simple
!= // n'est pas égal
```

Et dans des exemples concrets :

```cpp
cout << 2 < 3 << endl;
cout << 4 == 3 << endl;

// Sortie : vrai \n faux
```
*Ici le `\n` signifie un saut de ligne*.

Il est important de noter que une comparaison entre deux valeurs ou variables retourne un booléen, ce qui signifie que l'on peut affecter une variable avec une condition :

``` cpp
bool condition = 5 == 3;
```
*Ici implicitement, on définit la variable `condition` de type booléenne `true` (vrai) si 5 est égale à 3, sinon définit la variable `condition` comme `false` (fausse)*.

Et maintenant, les opérateurs logique, quand a eux, ils servent à faire des opérations logiques comme l'addition de deux comparaisons, ou même faire la négation d'un élément, on peut de référer aux tables logique de chaque opérateur pour savoir lequel utiliser.

Il a plusieurs façons d'écrire les opérateurs logique, dans ce cours nous allons en voir une, non pas la plus simple, mais celle qui est la plus rigoureuse et celle qui sera appliquer dans beaucoup d'autres langages de programmation : 

``` cpp
&& // le ET logique
|| // le OU logique
! // la négation
```

Concrètement, la syntaxe est assez simple, les deux opérateurs `&&` et `||` se mettent entre deux conditions. L'opérateur `!` quand a lui se met devant une valeur ou une variable pour dire son contraire.

``` cpp
// ici, si 4 est inférieur à 3 (faux) ou si 5 est égale à 5 (vrai)
cout << 4 < 3 || 5 == 5 << endl;

// Sortie : true

// ici, on demande la négation de true (vrai), et donc sa négation est false (faux)
cout << !true << endl;

// Sortie : false
```


## Les instructions conditionnels

Les instructions conditionnels sont des conditions et si la condition est vrai alors on effectue des instructions sinon on en effectuera d'autres.

Voici la syntaxe :

```cpp
// si la condition est vraie
if (condition) {
	// code
}
// sinon si la confition est vrai
else if (condition) {
	// code
}
// sinon
else {
	// code
}
```

Et voici un exemple :

```cpp

if (3 < 2) {
	cout << "3 est inférieur à 2" << endl;
}
else if (5 != 5) {
	cout << "5 n'est pas égal à 5" << endl;
}
else {
	cout << "Le reste" << endl;
}

// Sortie : Le reste
```

Il faut savoir que le `if-else` n'est pas la seule instruction conditionnelle, il existe aussi le `switch-case` qui lui est utile pour séparer le code en section et qui en fonction d'une variable va changer, par exemple, si on demande à un utilisateur de donner un chiffre entre 1 et 5 et que pour chaque chiffre on affiche quelque chose de différent on peut faire ainsi :

```cpp
int x;

cout << "Entrez un chiffre entre 1 et 5 : ";
cin >> x;

switch (x) {
	case 1:
		cout << "Bravo tu as choisis 1, tu n'as rien gagné" << endl;
		break;

	case 2:
		cout << "Pas de chance tu as choisi 2 maintenant tu peux retenter ta chance." << endl;
		break;
		
	case 3:
		cout << "Pas de chance tu as choisi 3 maintenant tu peux retenter ta chance." << endl;
		break;

	case 4:
		cout << "Toujours rien" << endl;
		break;

	case 5:
		cout << "Flemme de trouver d'autres expressions" << endl;
		break;

	default:
		cout << "le chiffre doit être compris entre 1 et 5." << endl;
		break;
}

```
*Un bloc de case se compose par la condition a côté du mot clé case, a savoir que ce que l'on va mettre a coté est une égalité stricte. Et à la fin de nos case il faut mettre break, sinon le programme va continuer de passer dans les cases. De plus on peut mettre un default, qui veut dire que si aucune valeur n'est entré dans les cases alors on passe dans le default*.


## Les fonctions

Une fonction est un morceau de code indépendant du programme principale et qui est lancé uniquement lorsqu'on l'appelle, on peux envoyer des données dans cette fonction, c'est ce qu'on appel des arguments ou des paramètres. Les fonctions sont principalement utiliser pour éviter la répétition du code, en effet, si une action est faite plusieurs fois a plusieurs endroits différents, il est plus judicieux de faire une fonction.

Les fonctions ont aussi des types, ils sont liés a la valeur de retour de la fonction, pour cela on utilise la mot clé `return` à la fin de la fonction, il est a noter qu'une fois le `return` la fonction s’arrête et donc le code qui se trouve après ne sera pas exécuté. Si les valeurs de retour sont différentes ont utilise le mot clé `void`. Les fonctions peuvent aussi avoir des paramètres, ce sont des comme des variables, ainsi il faut leurs mettre un type et potentiellement une valeur par défaut, par convention les paramètre de la fonction qui sont sans valeurs par défaut sont avant ceux qui en ont. 

Voici la syntaxe d'une fonction :

```cpp
<type> <nom> (<arguments>)
{
	// code
}
```

Ensuite pour appeler cette fonction il suffit de mettre son nom et des parenthèses, s'il y a des arguments à passer il faut juste mettre les valeurs à la suite avec des virgules pour les séparer.

``` cpp
int addition (int a, int b = 3)
{
	return a + b;
}

void toto ()
{
	if (1 == 2) {
		return true;
	}
	
	return 1;
}

int main () {
	cout << addition(3, 5) << endl;
	cout << toto() << endl;

	return 0;
}

// Sortie : 13 \n 1
```

Il faut néanmoins faire la distinction entre définition et déclaration de la fonction :
* La déclaration : l'instruction qui se trouve en entête de la fonction, le type, le nom, les éventuels paramètres.
* La définition : le corps de la fonction, c'est toutes les instruction qui vont être exécutées.
Ainsi il est tout a fait possible de déclarer une fonction sans la définir :

```cpp
int addition (int a, int b);

int main() {
	cout << addition (5, 4) << endl;
	
	return 0;
}

int addition (a, b) {
	return a + b;
}

// Sortie : 9
```


## Les tableaux

Les tableaux sont une structure de donnée qui permettent de stocker plusieurs valeurs de même type dans une variable.

La syntaxe est telle :
```cpp
<type> <nom>[<nb d element du tableau>] = {<valeur1>, <valeur2>, <...>};
```
*Il est recommander de mettre le nombre d'élément du tableau, mais ce n'est pas une obligation*.

Par exemple, on souhaite ranger dans une variable `chiffres` la liste des entiers de 0 à 9 :

```cpp
int chiffres[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
```

Les tableaux sont des structures qui peuvent se parcourir et où l'on peut modifier un élément à partir de son indice. Par exemple sur notre liste de chiffre, on veut récupérer l'élément d'indice 3, et ensuite le modifier pour mettre 20 à la place :

```cpp
int chiffres[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

cout << chiffres[4] << endl;

chiffres[4] = 20;

cout << chiffres << endl;

// Sortie 3 \n {0, 1, 2, 20, 4, 5, 6, 7, 8, 9}
```

ATTENTION  ⚠️ : Lorsque l'on effectue un parcours, il faut compter les éléments en indice, donc en partant de 0. C'est ainsi que le dernier élément d'un tableau de 10 éléments à pour indice 9.

## Les boucles

Les boucles sont des instructions qui permettent de répéter un morceau de code sous une ou plusieurs conditions, il existe 4 types de boucles :
* Les boucles While
* Les boucles Do/While
* Les boucles For
* Le parcours d'une variable avec Foreach

Les boucles While permettent une exécution du code entre accolades tant que la condition est vrai, voici sa syntaxe :

```cpp
while (<condition>) {
	// code
}
```

Il est a noté que ces boucles peuvent être dangereuse si les conditions sont mal faites, il faut toujours mettre un changement de variable dans la boucle pour que la condition d'actualise :

```cpp
int k = 0;

while (k < 5) {
	cout << k << endl;
	
	k++;
} 

// Sortie : 0 \n 1 \n 2 \n 3 \n 4
```
*Ici, la variable k s'incrémente à chaque passage dans la boucle donc la condition `k < 5` sera fausse à un moment*.

Il existe une variante de la boucle `while` c'est la boucle `do/while`, celle ci exécute une fois le code avant de passer dans la condition :

```cpp
do {
	// code
}
while (<condition>);
```

Voici le même exemple que celui au dessus :

```cpp
int k = 0;

do {
	cout << k << endl;

	k++;
}
while (k < 5);

// Sortie : 0 \n 1 \n 2 \n 3 \n 4
```

Remarque : Ces boucles sont vraiment utilisé lorsqu'il faut demander à un utilisateur une information et que l'on réitère la question si la réponse n'est pas correct, voici un exemple :

```cpp
int reponse;

do {
	cout << "Entrez un chiffre entre 0 et 9 : ";
	cin >> reponse;
}
while (reponse < 0 || reponse > 9); 
```

Remarque : On dit que les boucles `while` et `do/while` sont des boucles non bornées.

La boucle `for` quant à elle est dite bornée car on pose dès la déclaration de la boucle le nombre de fois quelle sera exécutée, voici sa syntaxe :

```cpp
for (<etat1>; <etat2>; <etat3>) {
	// code
}
```

On distingue 3 état dans la déclaration de la boucle `for`:
- État 1, qui est exécuté une fois avant le début du code, il sert à initialiser une variable qui permettra de mettre à jour la condition.
- État 2, qui est de la même manière que pour la boucle `while`, la condition de la boucle.
- État 3, qui est exécuté à chaque fois que la boucle à fini, il sert généralement à incrémenter ou a décrémenter la variable initialisé dans l'état 1.

Voici un exemple :

```cpp
for (int k = 0; k < 5; k++) {
	cout << k << endl;
} 

// Sortie : 0 \n 1 \n 2 \n 3 \n 4
```

Remarque : Il est tout à fait possible de mettre des boucles dans des boucles, nous verrons ça lorsque nous verrons les matrices.

Et le dernier type de boucle est utilisé pour le parcours de tableau ou de structure itérables. Pour les boucles `for-each`, on définit une variable de même type que le tableau et on fait un parcours pour chaque élément :

```cpp
for (<type> <variable> : <tableau du même type que la variable>) {
	// code
}
```

Voici un exemple avec un tableau contenant des entiers de 1 à 5 :

```cpp
int chiffres[5] = {1, 2, 3, 4, 5};

for (int chiffre : chiffres) {
	cout << chiffre << endl;
}

// Sortie : 1 \n 2 \n 3 \n 4 \n 5
```


## Les chaînes de caractères

Il y a deux façons de construire une chaine de caractère en C++, ici nous ne verrons que la méthode qui est de passer par une bibliothèque qui gère le type et des méthodes concernant les chaînes de caractères.

Tout d'abord il faut importer la bibliothèque `<string>` :

```cpp
#include <string>
```

ATTENTION  ⚠️ : Si le `using namespace std` n'est pas mit dans le programme alors il faudra mettre devant chaque instruction qui contient les mots clé de la bibliothèque `std::`.

Ensuite on peut déclarer une variable :

```cpp
string mot = "hello";
```

Il est tout a fait possible de faire la concaténation de chaîne de caractères avec des variables :

```cpp
string prenom = "John";
string nom = "Doe";
string nomComplet = prenom + " " + nom;

cout << nomComplet << endl;

// Sortie : John Doe
```

Il existe aussi la méthode `append()` qui existe pour faire de la concaténation :

```cpp
string prenom = "John ";
string nom = "Doe";
string nomComplet = prenom.append(nom);

cout << nomComplet << endl;

// Sortie : John Doe
```

ATTENTION  ⚠️ : La concaténation d'entiers dans des chaînes de caractères resterons des chaînes de caractères, voici un exemple :

```cpp
int x = 1;
int y = 2;

cout << x + y << endl;

// Sortie : 3


string a = "5";
string b = "4";

cout << a + b << endl;

// Sortie : 54
```


Par ailleurs, on peut utiliser la méthode `length()` pour avoir la longueur d'une chaîne de caractères :

```cpp
string mot = "coucou";

cout << mot.lenght() << endl;

// Sortie : 6
```

Remarque : La méthode `size()` existe aussi, il s'agit d'un alias de la méthode `length()`.

Les chaînes de caractères aussi sont des structures itérables, on peut donc les parcourir pour obtenir un caractère.

ATTENTION ⚠️ : Lorsque l'ont fait le parcours d'une chaîne de caractère, un caractère de celle ci n'est plus de type `string` mais de type `char`, voici un exemple :

```cpp
string mot = "coucou";
char lettre = mot[4];

cout << lettre << endl;

// Sortie : o
```
