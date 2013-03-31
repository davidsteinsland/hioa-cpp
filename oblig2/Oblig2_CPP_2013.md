#Mappebidrag 3 
###*Også kalt Oblig2, C++ 2013*

=========================================
**Innleveringsfrist: *Mandag 1.april kl. 23:59:59***

Du skal løse *en* av de fire oppgavene beskrevet under. Følgende krav er felles for alle oppgavene:

- Løsningen skal være et fungerende program for terminal
- Programmet skal kompilere og kjøre på studssh
- På første linje i *hver eneste fil i programmet* skal det stå en kommentar med ditt navn og studentnummer
- Du skal skrive en rapport, der målet er å gjøre det enklest og raskest mulig for en kollega å sette seg inn i din kode. Det vil si fokus på å vise det store bildet - bruk gjerne diagrammer der det er naturlig, unngå "wall of text". Vær konsis - en rapport skal være raskere å lese enn koden - ellers er poenget borte.
- Oppgaven skal leveres via github, i et eget, PRIVAT repository, på samme måte som oblig1. Har du enda ikke fått github-konto, bestill nå! Som sist vil det betraktes som bidrag til juks dersom man gjør sin kode tilgjengelig for andre.
- Programmet skal kunne kompileres med "make", og det skal da også komme ut på skjermen hva man skriver for å starte programmet. (Echo i makefile)
- Oppgaven skal kodes individuelt. Det er lov å spørre om hjelp og å spille ball med andre, men det skal være helt og fullt din kode.
- Det er tillatt å bruke non-standard kodebiblioteker som boost, men det må kompilere på studdssh - og man får da naturligvis ikke poeng for koden andre har laget.
- Man må kunne redegjøre muntlig for hva man har gjort, dersom faglærer finner noe uklart


### 1. *N-på-rad*, fritt frem
Denne oppgaven passer for de som ønsker mer vekt på algoritmiske problemstillinger. Her skal du implementere en generalisert versjon av 3-på-rad (bondesjakk, tic-tac-toe), over terminal - menneske mot maskin. Den klassiske varianten er slik:

1. Det er to spillere, og et spillbrett på 3 x 3 ruter
2. Det trekkes tilfeldig hvem som skal starte
3. Den som starter plasserer en brikke, deretter plasserer nestemann, og så videre.
4. Vinneren er den som først får 3 på rad, horisontalt, vertikalt eller diagonalt. 
5. Dersom det er umulig å få 3 på rad er det uavgjort.

I 4 på rad er det helt like regler, men tallet 3 er erstattet med 4. Du skal implementere spillet, men med mulighet for n x n spill, minst opp til 8 x 8, altså "8 på rad", men gjerne høyere. Max n avgjøres av ditt ambisjonsnivå.

Følgende gjelder:

- Brukeren skal bli bedt om å oppgi et tall mellom 3 og n, der n er minst 8.

- Spillet skal starte iht. reglene over. 

- Det bør skrives ut en matrise med spillets tilstand mellom hvert trekk. Bruk gjerne X og O som betegnelse på brikkene, eller vær kreativ hvis du vil.

- Brukeren kan gjerne oppgi sitt trekk som et koordinat, "x,y", der x er en av [A,B,C,…] og y en av [1,2,3, …], eller du kan finne på noe mer brukervennlig hvis du ønsker.

- Denne oppgaven krever potensielt mindre C++-spesifike ferdigheter, så det legges defor enda større vekt på at programmet kjører fint uten store feil, og generell spillbarhet.

- En nødløsning for deg som sliter: Implementer først 3 og så 4 på rad i denne oppgaven, så har du noe å levere…

- Ekstra (frivillig) utfordring: lag programmet ditt slik at du kan sette maskinen til å spille mot seg selv - eller til å spille mot en annens strategi, og la det være mulig å vise spillet i sakte film i terminalen, slik at man som bruker kan følge med. Sett gjerne ditt program til å spille mot en medstudent sitt - da må dere bli enige om en api. OBS: Dersom du gjør dette, si fra!



### 2. Tre og Fire på rad i casino-rammeverket
Denne oppgaven passer for de som i prinsippet likte å jobbe med casino-rammeverket fra oblig 1, men som så hvordan det kunne vært gjort bedre. Velger du denne oppgaven skal du ta utgangpsunkt i det rammeverket, og følgende krav gjelder:

- Du skal implementere 3-på-rad, og fire-på-rad, menneske mot maskin. Du velger selv om begge spillene skal være en og samme strategi, der tre eller fire er gyldige verdier til konstruktor, eller om det er to separate klasser.

- Du oppfordres til å løse eventuelle problemer med casino-rammeverket, som feks. å legge til destruktorer der det er naturlig, strømlinjeforme kontrollflyt (feks. tilrettelegge for at all kommunikasjon med bruker går via gambler), omstrukturere mer i retning MVC lagdeling etc.

- Du kan endre alle klassene, og også legge til så mange klasser du vil, men ett krav er absolutt: *Det må fremdeles være slik at en gambler kan ha et vilkårlig antall strategier, til minst to ulike spill, og at dette kan endres "runtime"*. Pr. i dag er det lagt opp til at dette ligger i en vector i gambler, og det må da gjøres en "downcast". Hvis du synes downcast er et problem, bør du vurdere oppgave 3. 

- Når spillet starter skal brukeren få en meny over de spillene som er tilgjengelige, og velge et, eller avslutte. Når spillet er ferdig skal man tilbake til menyen.

- Ekstra (frivillig) utfordring: lag programmet ditt slik at du kan sette maskinen til å spille mot seg selv - eller til å spille mot en annens strategi, og la det være mulig å vise spillet i sakte film i terminalen, slik at man som bruker kan følge med. Sett gjerne ditt program til å spille mot en medstudent sitt - da må dere bli enige om en api. OBS: Dersom du gjør dette, si fra!

### 3. Tre og Fire på rad i eget casino-rammeverk
Dette er oppgaven for deg som synes casino-rammeverket var håpløst, eller som av andre grunner ønsker å gjøre et forsøk på å lage et fra scratch. Det som skiller denne oppgaven fra oppgave 1, bortsett fra at man kun trenger 3 og 4 på rad) er at man her skal lage et eget rammeverk. Det betyr at man må tilrettelegge for at man ogå skal kunne spille andre spill, som blackjack og poker, i samme rammeverk. Følgende gjelder:

- Du skal kun implementere 3- og 4 på rad

- Du skal tydelig skissere (dvs. nevne alle klasser og sammenhengen mellom dem) i rapporten hvordan du ville implementert blackjack, og grovt skissere hvordan du ville implementert poker.

- Du skal diskutere styrker og svakheter med ditt design, kontra casino-rammeverket fra oblig1 (husk at det hadde noen innebygde svakheter - ta utgangspunkt i grunnidéene)

- Klarer du å finne en elegant løsning der en gambler har flere strategier til ulike spill, som kan skiftes runtime, uten bruk av downcast? Eller har du et design der dette ikke er relevant, fordi det har andre styrker?

- Ekstra (frivillig) utfordring: lag programmet ditt slik at du kan sette maskinen til å spille mot seg selv - eller til å spille mot en annens strategi, og la det være mulig å vise spillet i sakte film i terminalen, slik at man som bruker kan følge med. Sett gjerne ditt program til å spille mot en medstudent sitt - da må dere bli enige om en api. OBS: Dersom du gjør dette, si fra!

### 4. Blackjack-simulering: Telling av kort
Denne oppgaven er for deg som er interessert i statistikk og sannsynlighet. Alle casinoer vet at det lønner seg for en spiller i blackjack å telle kort. I denne oppgaven skal du finne ut nøyaktig hvor mye det lønner seg. 

Grunnprinsippet med å telle kort er at man holder rede på hvor mange kort som er igjen av hver type, i stokken. Anta at man spiller med én kortstokk, at det har gått 3 ess, og at det er 5 kort igjen. Da er det naturligvis 1/5 sjanse for å få ess, mens det er 1/13 sjanse med full stokk og ingen telling. 

- Du kan enten ta utgangspunkt i casino-rammeverket fra forrige oppgave, eller begynne fra scratch (gjenbruk da gjerne kode fra oblig1 hvis ønkselig - men ikke bruk andres kode). 

- Det blir nå datamaskinen som skal spille mot dealer, og telle kort. Den kan bruke alle hjelpemidler, feks. å ta vare på samtlige kort som kommer, i en vector.

- Når programmet starter skal brukeren få velge mellom to hovedtyper kjøring (brukeren gir beskjed enten via cin eller som kommandolinjeargument):
	
	A. La brukeren spille på samme bord som datamaskinen, når maskinen teller kort, og når den ikke gjør det (man skal bil bedt om å oppgi dette). Det skal da spilles et normalt blackjack-spill, men man skal også hele tiden se hva maskinen gjør, altså se det man ville sett dersom man satt ved siden av den.
	
	B. Kjøre en simulering der brukeren får oppgi følgende:
		
		- Hvor mange runder som skal spilles (int er stort nok)
		
		- Hvor mange kortstokker som skal være med i stokken
		
		- Om det skal stokkes mellom hver gang det deles
		
		- Om maskinen skal telle kort eller ikke. 
		
		
		**Videre gjelder følgende:**
		
		- Maskinen - og andre spillere - vet alltid hvor mange stokker som er med
		
		- Det skal skrives ut hvor mange spill der dealer vant, og hvor mange der maskinen vant, og hvor mange uavgjort.
		
		- Det skal skrives ut i prosent, hvor mange ganger hver av dem vant, hvor mange prosent uavgjort, og for den som vant flest, hvor mange prosent flere spill den vant.
		
		- Det skal skrives ut hvor mye cash maskinen har, og hvor mye cash dealer har, både før og etter spillet. (Du velger startverdi, og budstørrelser for maskinen)
		
		- Det skal skrives ut hvor mye cash hhv. maskinen og dealer har tjent (altså differansen mellom det den startet med og det den endte med), etter spillet
		
- Bortsett fra å lære C++ er målet med oppgaven å finne ut hvor mye man kan tjene på å telle kort. Når programmet er ferdig skal du bruke det til å besvare følgende, i rapporten:

	- Hvor stor fordel er det å telle kort? Dvs. hvor mye 
	
	- Øker eller minsker fordelen med antall kortstokker det spilles med? Evt. Hvor mye?
	
	- Hva er, i følge ditt program, konsekvensen av å stokke mellom hver deling?

- Ekstra (frivillig) utfordring: For at korttelling skal ha en definitiv effekt må man vite hvor mange stokker som er i spill. Anta at det eneste man vet er at det er mellom 1 og 8 kort i bunken. Kan man da lage en strategi som fremdeles tjener på å telle kort? (PS: Dette er et åpent spørsmål!)
	
	



