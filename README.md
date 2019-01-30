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


############## Commentaires ###############

Excellent projet! 

Volker Böhm a développé (ou adapté) plusieurs objets d'analyse audio pour MaxMSP. Ils sont disponible sur son site web:

https://vboehm.net/downloads/

Comme les objets externes sont acceptés dans max4live, ce serait un bon point de départ pour commencer l'exploration de l'analyse du signal audio.

10/10

