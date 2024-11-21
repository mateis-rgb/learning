# Vitesse et moteur brushless

## Il existe une relation entre la fréquence du PWM (Pulse Width Modulation) et la vitesse d'un moteur brushless contrôlé par un Arduino, mais cette relation est indirecte. Voici comment cela fonctionne et pourquoi la fréquence est importante :

### 1. **Le rôle du signal PWM dans le contrôle d'un moteur brushless :**
   - Pour contrôler un moteur brushless, le signal PWM est utilisé pour ajuster le comportement d'un contrôleur électronique (ESC, Electronic Speed Controller).
   - L'ESC interprète le signal PWM pour déterminer la puissance à envoyer au moteur, ce qui influence directement sa vitesse.

### 2. **Lien entre fréquence PWM et vitesse :**
   - Le **rapport cyclique** du PWM (la proportion du temps où le signal est haut) est ce qui détermine la vitesse effective du moteur. Plus le rapport cyclique est élevé, plus le moteur tourne vite.
   - La **fréquence** du signal PWM, cependant, ne détermine pas directement la vitesse du moteur mais peut avoir une incidence indirecte :
     - Si la fréquence est trop **basse**, le contrôle peut devenir irrégulier, entraînant des vibrations ou des pertes d'efficacité.
     - Si la fréquence est trop **élevée**, le circuit de commande (ESC) peut ne pas être capable de suivre, ce qui peut entraîner un comportement inattendu.

### 3. **Les fréquences typiques pour moteurs brushless :**
   - Les ESC standard pour moteurs brushless sont généralement conçus pour accepter des fréquences PWM d'environ **50 Hz à 500 Hz**.
   - Le signal PWM classique de commande d'un ESC utilise une période de **20 ms (50 Hz)**, avec des impulsions allant de 1 ms (vitesse minimale) à 2 ms (vitesse maximale).

### 4. **Dans le cas de commandes directes (sans ESC) :**
   - Si vous pilotez un moteur brushless sans ESC en générant directement les signaux de commutation (avec une carte Arduino par exemple), alors la fréquence des signaux PWM doit correspondre à la fréquence de commutation nécessaire au moteur, en fonction de sa vitesse de rotation et du nombre de pôles. Cela nécessite une synchronisation précise avec la position du rotor.

### 5. **Recommandations pratiques :**
   - Utilisez la fréquence appropriée à votre ESC (généralement 50 Hz à 500 Hz).
   - Ajustez le rapport cyclique pour contrôler la vitesse.
   - Si vous constatez des comportements anormaux, vérifiez que la fréquence PWM est compatible avec les spécifications de l'ESC.

En résumé, la fréquence du PWM doit être adaptée au système (ESC ou moteur direct) pour un fonctionnement optimal, mais c'est le rapport cyclique qui détermine principalement la vitesse du moteur.

## Pour calculer la **vitesse en tours par minute (RPM)** d’un moteur brushless à partir de la fréquence du PWM, il est essentiel de comprendre le contexte de contrôle et de conversion. Voici les étapes nécessaires :

---

### 1. **Relation entre PWM et vitesse**
- Le **rapport cyclique (duty cycle)** du signal PWM contrôle la puissance que l'ESC envoie au moteur, influençant la vitesse.
- Cependant, la fréquence du signal PWM (typiquement entre 50 Hz et 500 Hz pour un ESC) **ne correspond pas directement à la vitesse de rotation** du moteur. Elle indique seulement les ordres envoyés au contrôleur (ESC).
- Pour obtenir la vitesse du moteur en **RPM**, il faut établir une relation avec :
  - Le **rapport cyclique** du PWM.
  - Les caractéristiques du moteur et de l'ESC.

---

### 2. **Données nécessaires**
Pour effectuer le calcul, vous aurez besoin des informations suivantes :
- **Min et max du PWM (en microsecondes ou rapport cyclique)** :
  - Typiquement : 1 ms (1000 µs) = vitesse minimale, 2 ms (2000 µs) = vitesse maximale.
- **Plage de vitesse du moteur** (en RPM) pour ces valeurs de PWM :
  - Par exemple, 0 RPM à 12 000 RPM.
- **Le rapport entre PWM et vitesse** :
  - Cela peut être linéaire ou non, en fonction de votre ESC et du moteur.

---

### 3. **Formule générale pour la vitesse en RPM**
Si le rapport PWM-vitesse est **linéaire** (cas typique), la formule est :

\[
\text{RPM} = \text{RPM}_{\text{min}} + \left( \frac{\text{PWM}_{\text{actuel}} - \text{PWM}_{\text{min}}}{\text{PWM}_{\text{max}} - \text{PWM}_{\text{min}}} \right) \times (\text{RPM}_{\text{max}} - \text{RPM}_{\text{min}})
\]

- **RPM\(_{\text{min}}\)** : vitesse minimale (souvent 0 RPM).
- **RPM\(_{\text{max}}\)** : vitesse maximale du moteur (donnée par le fabricant).
- **PWM\(_{\text{actuel}}\)** : signal PWM reçu par l'ESC.
- **PWM\(_{\text{min}}\)** et **PWM\(_{\text{max}}\)** : limites du signal PWM (typiquement 1000 µs à 2000 µs, ou un rapport cyclique de 0 à 100%).

---

### 4. **Exemple de calcul**
Supposons :
- Vitesse maximale du moteur : 12 000 RPM.
- Signal PWM de 1000 µs = 0 RPM.
- Signal PWM de 2000 µs = 12 000 RPM.
- Signal PWM actuel = 1500 µs.

La vitesse se calcule ainsi :

\[
\text{RPM} = 0 + \left( \frac{1500 - 1000}{2000 - 1000} \right) \times (12 000 - 0)
\]

\[
\text{RPM} = \left( \frac{500}{1000} \right) \times 12 000 = 0.5 \times 12 000 = 6 000 \, \text{RPM}
\]

---

### 5. **En cas de relation non linéaire**
Certains ESC ou moteurs ont des réponses non linéaires. Dans ce cas :
- Consultez la courbe caractéristique du moteur ou ESC pour déterminer la correspondance entre PWM et vitesse.
- Si vous avez des mesures expérimentales (ex. RPM mesurés pour différents PWM), vous pouvez utiliser une interpolation polynomiale pour modéliser cette relation.

---

### 6. **Cas avec capteurs (feedback)**
Pour des systèmes équipés de capteurs (comme des encodeurs), vous pouvez directement mesurer la fréquence de rotation et éviter de dépendre des approximations liées au PWM.

--- 

En résumé, la fréquence du PWM seule ne suffit pas à calculer la vitesse. Vous devez utiliser le rapport cyclique et la relation caractéristique entre PWM et vitesse pour obtenir une estimation en RPM.

## Pour calculer la **vitesse en RPM** d’un moteur brushless à l’aide d’un capteur, module ou composant, vous devez mesurer directement la fréquence de rotation ou des événements liés à la rotation du moteur. Voici les méthodes principales :

---

### 1. **Avec un capteur de hall intégré au moteur brushless**
Les moteurs brushless équipés de capteurs à effet Hall génèrent des signaux électriques pour chaque changement de position du rotor. Ces signaux peuvent être utilisés pour calculer la vitesse :
- Chaque capteur de Hall génère une impulsion par changement de phase (il y a typiquement 6 changements de phase par tour pour un moteur triphasé).
  
**Formule :**

\[
\text{RPM} = \frac{\text{Fréquence des impulsions} \times 60}{\text{Nombre de changements de phase par tour}}
\]

- **Fréquence des impulsions** : mesurée en Hz.
- **Nombre de changements de phase par tour** : typiquement 6 pour un moteur triphasé.

**Exemple :**
- Si vous mesurez une fréquence de 300 Hz sur un capteur Hall :
\[
\text{RPM} = \frac{300 \times 60}{6} = 3\,000 \, \text{RPM}
\]

---

### 2. **Avec un encodeur rotatif**
Un encodeur rotatif est un dispositif fixé sur l’axe du moteur. Il produit un nombre défini d’impulsions par rotation complète, appelé **résolution** (par exemple, 100 impulsions par tour).

**Étapes :**
1. Comptez le nombre d’impulsions (via une interruption Arduino ou un compteur).
2. Mesurez la durée pendant laquelle ces impulsions ont été générées.
3. Calculez la vitesse en RPM.

**Formule :**
\[
\text{RPM} = \frac{\text{Nombre d’impulsions comptées} \times 60}{\text{Résolution de l’encodeur} \times \text{Temps (en secondes)}}
\]

**Exemple :**
- Résolution : 100 impulsions par tour.
- 500 impulsions comptées en 2 secondes :
\[
\text{RPM} = \frac{500 \times 60}{100 \times 2} = 150 \, \text{RPM}
\]

---

### 3. **Avec un tachymètre optique**
Un tachymètre optique utilise une lumière (souvent un laser) et un capteur pour mesurer les rotations en détectant un marqueur (par exemple, une bande réfléchissante) sur l’axe du moteur.

**Étapes :**
1. Le capteur enregistre une impulsion chaque fois que le marqueur passe devant lui.
2. La fréquence des impulsions est utilisée pour calculer la vitesse.

**Formule :**
\[
\text{RPM} = \text{Fréquence des impulsions (en Hz)} \times 60
\]

**Exemple :**
- Si le tachymètre mesure une fréquence de 50 Hz :
\[
\text{RPM} = 50 \times 60 = 3\,000 \, \text{RPM}
\]

---

### 4. **Avec un capteur de courant ou de tension**
Dans certains cas, la vitesse peut être estimée indirectement en mesurant le courant ou la tension appliquée au moteur. Cela nécessite de connaître la **courbe caractéristique** (tension/courant vs. RPM) du moteur.

**Étapes :**
1. Mesurez la tension ou le courant du moteur.
2. Référez-vous à la courbe caractéristique pour estimer la vitesse.

---

### 5. **Modules disponibles pour mesurer la vitesse**
Voici des modules ou composants que vous pouvez utiliser :
- **Module avec capteur de Hall :** Compatible avec Arduino, ex. **KY-003**.
- **Encodeur rotatif :** Modules comme le **AS5600** ou des encodeurs quadrature (par ex. **AMT102**).
- **Tachymètre optique :** Des modules simples ou professionnels (souvent manuels).
- **Capteur infrarouge ou fourche optique :** Pour mesurer les interruptions dues à un disque rotatif avec des marques.

---

### 6. **Exemple avec Arduino et capteur Hall**
Si vous utilisez un moteur brushless avec un capteur Hall, voici une idée de code Arduino pour mesurer la vitesse :

```cpp
const int hallPin = 2; // Broche du capteur Hall
volatile int pulseCount = 0;
unsigned long lastTime = 0;

void setup() {
  pinMode(hallPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hallPin), countPulse, RISING);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= 1000) { // Calcule toutes les secondes
    noInterrupts();
    int count = pulseCount;
    pulseCount = 0;
    interrupts();
    
    float frequency = count; // En Hz
    float rpm = (frequency * 60) / 6; // Divise par 6 pour un moteur triphasé
    Serial.print("Vitesse : ");
    Serial.print(rpm);
    Serial.println(" RPM");
    
    lastTime = currentTime;
  }
}

void countPulse() {
  pulseCount++;
}
```

---

### Conclusion
La méthode exacte dépend du capteur disponible :
- Les capteurs Hall et encodeurs sont précis et idéaux pour les mesures en temps réel.
- Les tachymètres optiques sont simples à mettre en œuvre pour des mesures ponctuelles.
- La mesure du courant/tension est indirecte et nécessite une connaissance approfondie des caractéristiques du moteur.