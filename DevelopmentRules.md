# Les 10 Règles pour Développer du Code Critique en Sécurité

Voici un résumé des "10 règles pour développer du code critique en sécurité", chaque règle étant illustrée par un exemple de code dans le langage le plus approprié, avec une version à éviter et une version recommandée. 
> Ref : [Article complet (en anglais)](https://researchgate.net/publication/220477862_The_Power_of_10_Rules_for_Developing_Safety-Critical_Code)

Ces règles aident à minimiser les erreurs, à améliorer la vérifiabilité et à garantir la fiabilité dans le code pour les systèmes critiques en sécurité.

---

## Règle 1 : Limitez le contrôle de flux à des structures simples

**Détail** : Évitez `goto`, `setjmp`, `longjmp`, et la récursion. Le flux de contrôle doit rester simple et lisible pour permettre une analyse plus facile et prévenir les cycles d'appels de fonctions.

**Exemple en C** :

**Code à éviter** :
```c
void process(int x) {
    if (x < 0) goto error;  // usage de goto
    // autres opérations
error:
    // gestion de l'erreur
}
```

**Code recommandé** :
```c
void process(int x) {
    if (x < 0) {
        // gestion de l'erreur sans goto
        return;
    }
    // autres opérations
}
```

---

## Règle 2 : Donnez une limite maximale d'itérations pour les boucles

**Détail** : Les boucles doivent avoir un nombre maximum d'itérations défini, empêchant les boucles infinies. Cela garantit la terminaison du code et réduit les risques d'erreurs de dépassement.

**Exemple en Python** :

**Code à éviter** :
```python
while node is not None:
    # traitement de chaque nœud
    node = node.next
```

**Code recommandé** :
```python
max_iterations = 100
i = 0
while node is not None and i < max_iterations:
    # traitement de chaque nœud
    node = node.next
    i += 1
```

---

## Règle 3 : Évitez l'allocation dynamique après l'initialisation

**Détail** : N'utilisez pas d'allocations dynamiques (`malloc`, `free` en C ou `new`, `delete` en C++) après l'initialisation. Cela évite les erreurs de gestion de mémoire.

**Exemple en C** :

**Code à éviter** :
```c
void process_data() {
    int *data = malloc(sizeof(int) * 100);  // allocation dynamique
    // traitement
    free(data);
}
```

**Code recommandé** :
```c
void process_data() {
    static int data[100];  // allocation statique
    // traitement
}
```

---

## Règle 4 : Limitez la taille des fonctions

**Détail** : Chaque fonction doit être courte, pas plus de 60 lignes, pour être facilement compréhensible et vérifiable.

**Exemple en C** :

**Code à éviter** :
```c
void long_function() {
    // beaucoup de code réparti sur plusieurs pages
}
```

**Code recommandé** :
```c
void shorter_function() {
    helper_function(); // décomposez en fonctions plus petites
}
```

---

## Règle 5 : Utilisez des assertions pour vérifier les conditions

**Détail** : Chaque fonction doit comporter des assertions pour vérifier les préconditions et postconditions, et détecter les erreurs.

**Exemple en C++** :

**Code à éviter** :
```cpp
void process(int x) {
    // aucun contrôle d'erreur
}
```

**Code recommandé** :
```cpp
#include <cassert>

void process(int x) {
    assert(x > 0);  // précondition
    // traitement
    assert(result != nullptr);  // postcondition
}
```

---

## Règle 6 : Déclarez les données au niveau de portée le plus réduit

**Détail** : Utilisez le plus petit bloc de code pour les déclarations de variables. Cela évite les erreurs et limite l’accès à des variables inutiles.

**Exemple en C** :

**Code à éviter** :
```c
int i; // déclaration globale inutile
void process() {
    for (i = 0; i < 10; i++) { /* traitement */ }
}
```

**Code recommandé** :
```c
void process() {
    for (int i = 0; i < 10; i++) { /* traitement */ }
}
```

---

## Règle 7 : Vérifiez les retours de fonction et la validité des paramètres

**Détail** : Vérifiez que chaque fonction appelle et gère les retours de valeurs correctement. Les paramètres fournis doivent aussi être valides.

**Exemple en Python** :

**Code à éviter** :
```python
def save_data(file):
    file.write("data")  # sans vérifier le résultat
```

**Code recommandé** :
```python
def save_data(file):
    try:
        file.write("data")
    except IOError as e:
        print("Erreur lors de l'écriture :", e)
```

---

## Règle 8 : Limitez l'utilisation du préprocesseur

**Détail** : Utilisez le préprocesseur uniquement pour les inclusions de fichiers d'en-tête et des macros simples. Évitez les macros complexes qui rendent le code moins lisible.

**Exemple en C** :

**Code à éviter** :
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))  // macro complexe
```

**Code recommandé** :
```c
static inline int max(int a, int b) { return (a > b) ? a : b; }  // fonction simple
```

---

## Règle 9 : Limitez l'utilisation des pointeurs

**Détail** : Utilisez au maximum un seul niveau de déréférencement et évitez les pointeurs de fonctions. Les pointeurs doivent être utilisés avec précaution pour éviter les erreurs.

**Exemple en C++** :

**Code à éviter** :
```cpp
int **ptr;  // pointeur de pointeur
```

**Code recommandé** :
```cpp
int *ptr;  // pointeur simple
```

---

## Règle 10 : Activez tous les avertissements du compilateur

**Détail** : Compilez le code avec tous les avertissements activés et corrigez-les tous pour garantir la qualité du code.

**Exemple en C** :

**Code à éviter** :
```c
// compiler sans avertissements
```

**Code recommandé** :
```bash
gcc -Wall -Wextra -pedantic file.c
```

---

Ce guide encourage des pratiques de programmation rigoureuses et assure une meilleure sécurité dans les systèmes critiques. Ces exemples montrent comment rendre le code plus clair, vérifiable, et robuste en suivant des règles strictes mais essentielles.
