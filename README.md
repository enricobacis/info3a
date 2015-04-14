info3a
======

Progetti per il corso di Informatica 3A presso l'Università degli Studi di Bergamo.

## Cyclone
Il progetto sviluppato è una libreria per la crittografi􏰄a di stringhe utilizzando cifrari a sostituzione con chiavi decise dall'utente.
La libreria non è stata sviluppata con un solo cifrario in mente, ma è pensata in maniera modulare, in modo che sia facile implementare l'utilizzo di diversi cifrari di sostituzione e anche crearne di nuovi.

Come esempi sono state scritte le funzioni per cifrare testi utilizzando il cifrario di Cesare e il cifrario ROT13 oltre al caso di chiave decisa dall'utente.
Oltre a questo sono anche state re-implementate in Cyclone alcune funzioni di supporto per le stringhe come strcpy e strncpy in maniera safe a diff􏰃erenza delle loro controparti in C.

## C++
Il progetto sviluppato rappresenta la struttura di una Università, con tre tipi di persone che vi interagiscono:
- *Studente* può conseguire delle votazioni relative ai corsi.
- *Professore* può insegnare dei corsi.
- *Dottorando* riunisce in sé sia le caratteristiche dello studente che quelle del professore.

Si è cercato di utilizzare un gran numero di costrutti C++ e design pattern tra cui *Template* e *Visitor*.

## JML
Il progetto riprende il tema dell'Università svolto per l'elaborato in C++, e in particolare la parte relativa allo studente e al salvataggio dei voti a cui sono state applicate alcune modi􏰄che per renderla più interessante dal punto di vista di Java e di JML.

Le funzionalità che si sono volute sviluppare sono state:
- Mantenimento dell'anagrafi􏰄ca, dell'anno di corso e dei voti conseguiti dallo Studente con metodi per accedere a tali dati e modi􏰄carli.
- Voti salvati in una struttura che li mantenga ordinati e verifi􏰄ca di questa proprietà attraverso un contratto della classe.

## ASM
Analisi con abstract states machine della procedura che controlla la registrazione dei voti di una Università, per riprendere il tema dei progetti di C++ e di JML. In questo caso ci si è focalizzati più sull'aspetto di sicurezza, quindi permettendo solamente ai professori registrati nel sistema di inserire voti per gli Studenti.

Il progetto deve rispettare le seguenti speci􏰄che:
- Registrazione da parte dei professori di voti (validi) nella lista di voti degli studenti registrati.
- Assicurazione che solamente i professori abbiano accesso al menu per l'inserimento dei voti.
- Possibilità di eff􏰃ettuare il logout da parte del Professore.
- Registrazione in sequenza ordinata in maniera temporale dei voti per lo studente.
- Visualizzazione di tutti i voti dello studente.

## Python e Ruby
La relazione contiene anche un'analisi dei linguaggi Python e Ruby. Per Python si mostrano degli esempi di passaggio di funzioni, lambda functions, paradigma map-reduce, higher order functions, caching, decorator pattern e generatori. Per Ruby si mostrano degli esempi di metaprogrammazione.
