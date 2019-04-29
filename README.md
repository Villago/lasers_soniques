	1	Énoncé
	⁃	Jeu de laser sonique 
	2	Description 
	⁃	Ce programme servira d’interface de contrôle et de liaison entre un projet musical audio réactif et une installation audiovisuelle dotée d’une dizaine de laser. 
	3	Analyse des besoins
	•	Laser : Créer un système électronique permettant d’allumer et d’éteindre des lasers à l’aides de fonctions intégrées dans un micro-contrôleur
	•	Contrôle graphique : Créer un système de gestion de l’espace qui possiblement pourrait avoir un feedback visuel
	•	Développer un système de liaison d’un DAW à un système de micro-contrôleurs à l’aide d’un logiciel de type DSP.
	•	Développer un système d’audio-réaction à l’aide d’un logiciel de type DSP
	4	Acquisition de connaissances 
	•	Recherche sur la communication entre Max et Arduino 
	⁃	https://www.youtube.com/watch?v=68L-WHh3Ows&frags=pl%2Cwn
 	⁃	http://playground.arduino.cc/interfacing/MaxMSP
	•	Recherche sur les interfaces graphique pour Arduino 
	•	Recherche sur les outils d’intégration de M4L dans Ableton 
	⁃	https://www.youtube.com/watch?v=ASPzjJ5OYoU&frags=pl%2Cwn
	⁃	Recherche sur l’intégration d’Ableton Link dans Max 
	⁃	https://www.youtube.com/watch?v=8xVeUJPV3Ug&frags=pl%2Cwn
	5	Modèle (une première ébauche)
	•	Une source audio interprétée en temps réels dans Max déclenche une séquence ou agit comme interrupteur d’une dizaine de laser contrôlé à l’aide d’un système Arduino.
	•	Max reçoit un BPM via Ableton Link et permet d’intégrer un rythme au déclenchements des séquences programmés dans Arduino.
	6	Méthodes (une première ébauche)
	•	Comme première ébacuhe, nous tenterons d'analyser une source audio (intensité, registre, etc.) dans Max qui déclenchera une séquence on-off (un à la suite des autres) de laser dans Arduino. 
 	•	Par la suite, nous essaieront de synchroniser un BPM reçu via Ableton Link dans Max avec une séquence Arduino.
	•	Une extension possible au projet serait de déclencher les séquences Arduino à l'aide des messages DMX.
    7    Implémentation
    •    Mon objectif principal était de me familiarisé avec l'environnement de travail Max pour pouvoir dévelloper une série d'outil de performance live et d'analyses audio pouvant communiquer avec un micro contrôleur de type Arduino. Par la suite,  le protocole  OSC à  été rajouté afin de communiquer en Wifi entre Max et un micro controleur Arduino Wifi MKR 1010. Pour résumer, j'ai quelques plugins M4L qui communique avec un patch central Maxpat qui envoie un message OSC avec 24 arguments i.
    • Également, j'ai voulu tester l'éfficacité de la communication Midi entre Ableton Live et Max à l'aide de port midi [from Max 1 & 2]
    8   Test et Maintenance
    •   Plusieurs problèmes sont survenus tout au long du projet. 
    •  Tout au long de la session j'ai eu des problèmes avec l'environmement Max. J'ai décidé d'acheter la version étudiante complète de Max pour obtenir accès aux sorties audio et port midi From Max 1&2. La version de Max et plus stable que M4L sur OS X Mojave. Je ne sais pas si c'est une question de programmation, mais à plusieurs reprises mon patch M4L se refermait toute de suite dès que je l'ouvrais. Afin de ne pas utiliser de version de Max différente dans le même projet j'ai modifié l'app Max  utiliser dans les préférences de Ableton, ce qui a réduit une partie de problème de stabilité.
    •  Problème de flux de données: Le MKR Wifi cesssait toute communication après avoir reçu trop de valeur 12bit sur 24 cannaux. Avec l'objet [speedlim] j'ai été capable de limiter le flux de donnée à un certain débit par millisecondes, ce qui a réglé mon problème.
    
    Extras : 
    Au long de la session je me suis rajouté dans le site de Cycling74 et le groupe facebook Max Msp, donc pour moi ça été une introduction à la communauté de Max et celle de Arduino.

############## Commentaires ###############

Excellent projet! 

Volker Böhm a développé (ou adapté) plusieurs objets d'analyse audio pour MaxMSP. Ils sont disponible sur son site web:

https://vboehm.net/downloads/

Comme les objets externes sont acceptés dans max4live, ce serait un bon point de départ pour commencer l'exploration de l'analyse du signal audio.

10/10

