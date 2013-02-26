Oblig 1, C++ Vår 2013
----------------------------------------------------

#Blackjack i et casino-rammeverk
Du skal implementere et spillrammeverk, som kan benyttes til å implementere flere typer spill, med flere typer grensesnitt, og både menneselige spillere og maskinspillere. Du skal foreølpig kun implementere blackjack, men ha mulighet for andre spill i bakhodet.

##De viktigste reglene
Blackjack er et kortspill som handler om å få så nært "21" som mulig, uten å gå over. Det fungerer som følger:

0. Alle billedkort (Konge, dame, knekt) er verdt 10, Ess (A) er verdt 1 eller 11 - det som gir "best" hånd. Andre kort er verdt sitt "tall" (også 10)
1. Spilleren satser penger. I våre blackjack-regler er det ingen grense.
2. Spilleren får to kort av "dealer", og dealer får selv to kort. Kun ett av dealers kort er synlige for spilleren.
3. Hvis spilleren får 21 på første hånd (10 og A), er det "Blackjack". Spiller vinner da 1.5 ganger sin innsats (3:2)
4. Spilleren må nå velge om hun/han vil ha et kort til (HIT), eller ikke (STAND)
5. Hvis spilleren står (STAND) på under 21, må dealer avgjøre sin hånd. 
   - Dealer må "HIT" på alt under 17, og "STAND" på 17 og høyere.
   - Hvis dealer går over 21 (BUST) vinner spilleren 1:1 av sin innsats
   - Hvis dealer kommer nærmere 21 enn spilleren uten å gå over, vinner dealer spillerens innsats
6. Dersom dealer og spiller ender på det samme, heter det "Push" - da vinner ingen. Dette gjelder ikke dersom det ble blackjack.

Det finnes to regler til, "DOUBLE" og "SPLIT". Disse skal du vente med.  Flere detaljer i rules.md

##Det som skal programmeres
- For hver klasse class_*.h, skal du skrive implementasjonen class_*.cpp (med mindre klassen er abstrakt og du finner det unødig å implementere)
- Tanken med hver klasse er beskrevet i *documentation.md* - der finner du også et diagram over sammenhengen. Blackjack-spillet skal implementeres i henhold til dette designet og blackjack-reglene, over.
- I tillegg skal du skrive blackjack.cpp, som skal gjøre følgende:
  - Starte et blackjackspill med en spiller og en dealer
  - Spilleren skal hente alle beslutninger fra brukeren, via standard input
- Du skal *ikke* endre på header-filene (.h), med unntak av *class_blackjackGame.h*, der du kan legge til medlemmer, men ikke fjerne.
- Det er ikke nødvendig å lage flere klasser. Det er lov, men det bør da motiveres med noen linjer i rapporten.

##Bruk av git underveis
Som nevnt på forelesning håper vi å kunne bruke git som innleveringsverktøy. Det anbefales at du kloner git-repositoryet, og jobber direkte i din egen lokale klone (legg den gjerne i dropbox, så får du automatisk backup). Din .git-mappe, med commit-log skal være en del av innleveringen - det anbefales derfor at du committer lokalt hver gang du har implementert noe nytt, slik at loggen blir leselig og viser din fremgangsmåte. 

**PS:** *Ikke vær bekymret for å vise "tabber" eller gammel, dårlig kode i historikken - det er bare fint. Det eneste som har noe å si er resultatet til slutt.*

**OBS:** *Du skal* **IKKE** *på noe tidspunkt gjøre dine .cpp filer tilgjengelige på github eller andre steder, slik at andre kan se dem. Dette vil bli betraktet som bidrag til juks.*

##Forslag til fremgangsmåte i prioritert rekkefølge 
1. Lag en fungerende kort og kortstokk med 52 kort
3. Skriv en funksjon (evt. del av start()) i blackjackGame, som avgjør hvor mange poeng en hånd (vector av kort) gir. Vurder om dette bør være del av en funksjon, en medlemsfunksjon eller en frittstående funksjon. Husk at du kan redigere *class_blackjackGame.h*, men ikke andre header-filer.
2. Funksjonene blackjackGame::playRound() og blackjackGame::start() må inneholde et *minimum* av funksjonalitet:
   - Det deles ut to kort til en vector for dealer, og to kort til en vector for "spiller" (ikke et gambler-objekt foreløpig)
   - Det skrives ut hvem som har høyest score, av dealer og spiller.
4. Programmet kan ta imot input fra bruker (bruk gjerne `cin >> myString`), og dele ut et kort til i "spillerens" vector hvis "HIT", eller å stoppe hvis "HALT" (Det er helt OK å ta imot tall eller enkelttegn fra bruker, for å representere disse to handlingene)
5. Implementer class_blackjackState (og evt. class_state). Når du ber om input fra bruker, opprett en blackjackState inne i playRound(), og la blackjackState::print() stå for utskrift til skjerm. 
6. Implementer class_blackjackAction (og evt. class_action). Når du mottar input fra bruker, opprett en blackjackAction inne i playRound(), og la blackjackAction::print() stå for utskrift til skjerm
6. Implementer class_blackjackStrategy(og evt. class_strategy). Lag en instans direkte inne playRound(), og la det motta (peker til) blackjackState-objektet som argument, og returnere (peker til)blackjackAction-objektet, for utskrift.
7. Implementer class_gambler, og la den få en blackjackStrategy når den opprettes
8. Implementer veddemål, slik at spiller kan angi et veddemål som trekkes fra "wallet", og så få riktig sum tilbake, hvis man vinner. 
9. Finn en trygg løsning for håndtering av pekerne som brukes (se læringsmål)
10. Lag enkle, men solide løsninger for å håndtere feil som kan oppstå, feks. ugyldig input fra bruker

**OBS:** *Dette er kun et forslag for å hjelpe deg i gang - delmålene under veis vil ikke sjekkes dersom alt er på plass til slutt.*

##Læringsmål
###Generelle hovedmål er å vise at man har tilegnet seg
1. Evne til å implementere et enkelt, fungerende C++ program
2. Evne til å forstå et ferdiglaget objektorientert design med arv og polymorfi. 
3. Evne til å implementere noen andres design iht. en instruks, selv om man kanskje er uenig i designvalgene.
4. Vise, i rapporten, at man ser endrings- og utvidelsesmuligheter
5. Vise at man kan skrive ryddig, strukturert og oversiktlig kode

###Tekniske mål - man skal vise:
1. At man mestrer grunnleggende programmeringsteknikker som løkker og kontrollstrukturer (Dette skal man kunne fra før)
2. At man mstrer grunnleggende, standard bruk av vectorer, herunder iterere med iteratorer, samt legge til og evt. elementer.
3. At man kan implementere og bruke subklasser og polymorfiske funksjoner

###For å få maksimal uttelling bør man også vise 
4. At man har kontroll på de pekerne som benyttes i designet: spesielt bør de være trygge å "dereference" over alt der de brukes (også mtp. at koden rundt kan endres), de bør heller ikke føre til minnelekkasjer.
5. At man kan skrive robust kode, der det er vanskelig å få enkelte deler til å kræsje. (Det er ikke nødvendig å bruke exceptions til dette, men strategisk plasserte "sanity-checks" bør være med)


##Rapport
- Det skal foreligge en liten rapport, i .md-format (som dette). Der skal du:
  - Beskrive implementasjonen, gjerne trekke frem ting du synes var interessant eller vanskelig
  - Diskutere et alternativt programdesign, hvis du har et, eller idéer til et. Er det noe du ville gjort anderledes? Noe du hadde gort anderledes, som gir fordeler eller ulemper?
  - Du kan legge ved din alternative implementasjon, i en mappe kalt "alt" i rotmappen i ditt "repository.
  - Rapporten skal hete "rapport.md" og ligge i rotmappen i ditt "repository" (mer info om dette senere)
- For å se hvordan markdown-koden for denne rapporten er laget, åpne fila og trykk knappen "Raw" ute på github, eller bare åpne den i en tekst-editor.

Du kan lese mer om .md-formatet generelt, her: [Daring fireball, Markdown syntax](http://daringfireball.net/projects/markdown/syntax)
og githubs tilpassede versjon her: [Github Flavored Markdown](https://help.github.com/articles/github-flavored-markdown)

##Hvordan du blir vurdert
- Hver klasse vil bli vurdert for seg, og gi et antall poeng
- blackjack.cpp blir også vurdert for seg
- Helheten blir vurdert og gir et antall poeng

##Er dette for mye?
Nei, jeg tror ikke det. Min implementasjon, med kommentarer og output-tekst er på under 400 linjer. `(cat *.cpp | wc -l)`. Den tok 6-7 timer å lage, og da ble også designet bearbeidet underveis. *OBS: Det er på ingen måte relevant hvor mange linjer dere bruker - bruk heller flere enn færre - det er kun funksjonalitet som har noe å si her*
