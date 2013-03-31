Oblig2 C++
==========

David Steinsland, s180486, david@davidsteinsland.net

## Abstrakt
Jeg har valgt oppgave 1, "_N-på-rad_, fritt frem". Programmet er utviklet mtp. objektsorienterte paradigmer, slik at oppgaven/besvarelsen må ikke forveksles med oppgave 3.

## Teori
Jeg har benyttet meg av en teknikk basert på matriser, hvor hovedidéene er som følger:

* Gitt et brett av størrelsen _n_ x _n_, så er det _n<sup>2</sup>_ forskjellige posisjoner, og _2n + 2_ forskjellige måter å vinne på (2 diagonaler, _n_ horisontale og _n_ vertikale).
* Når spillet startes, opprettes det en matrise av størrelsen _n<sup>2</sup>_ x _2n + 2_. Det betyr at hver eneste posisjon på brettet får en matrise av størrelsen _2n + 2_. Denne matrisen inneholder informasjon om hvilke "vinnerposisjoner" den bidrar til.

Gitt et brett av størrelsen _3_ x _3_:

	a	b	c
	d	e	f
	g	h	i
Da vil matrisen til `a` se slik ut:

	{1, 1, 0, 0, 1, 0, 0, 0}
Tallet `1` betyr at `a` bidrar til posisjonen, mens `0` betyr det motsatte. Matrisen er av fast størrelse, og kan forklares slik:

* Første element er diagonal 1
* De neste tre elementene er de ulike horisontale retningene
* De neste tre elementene er de ulike vertikale retningene
* Siste element er diagonal 2

Som vi ser av matrisen, så bidrar `a` til den første diagonalen, samt _horisontal 1_ og _vertikal 1_.

Til slutt så har vi en "spill-matrise", som ved oppstart av spillet er nullet ut:

	{0, 0, 0, 0, 0, 0, 0, 0}
Når spiller 1 velger `a`, så legger vi til `a` sin matrise til spill-matrisen.
Når spiller 2 velger som posisjon, for eksempel `b`, så _trekker vi ifra_ `b` sin matrise med spill-matrisen.

Dette gir oss at:

* Hvis det er et element i spill-matrisen som er 3 eller -3, så har en spiller vunnet
* Hvis alle elementer er [-2, 2] og alle posisjoner er opptatt, så er spillet uavgjort
* Hvis det er et element som er -2 eller 2, så må den andre spilleren blokkere den retningen det gjelder, hvis ikke vil den andre spilleren vinne neste runde
* Hvis det finnes to elementer som er -2 eller 2, så har den ene spilleren opprettet en _fork_ (fra sjakk-verden), som betyr at han vinner uansett i neste runde (siden han har to posisjoner som kan gi han seieren, mens den andre spilleren bare kan blokkere én av dem).

Når vi skal utvikle en PC-hjerne, eller en AI, så kan vi bruke disse reglene (la oss nå gå utifra at maskinen er den som behøver _-3_ for å vinne, mens menneske-spilleren trenger _3_).
Sortert etter prioritet gir det oss følgende:

* PC-en må få enhver retning med verdien _-2_ i spill-matrisen til _-3_ (vinne)
* PC-en må lage så mange _-2_ som mulig, uten å la det være noen elementer i spill-matrisen med verdien _2_
* PC-en må gjøre så mange _2_-ere til _1_-ere

**I koden er dette generalisert til å gjelde for enhver brett-størrelse**.

## Praksis
Besvarlsen består av et par klasser, med inspirasjon fra casino-rammeverket:

* `tictactoe`: starter spillet
* `player`: spiller-objektet
* `game_state`: forteller spillets tilstand
* `strategy`: abstrakt strategi-klassen
* `computer_strategy`: automatisert strategi, med utgangspunkt i reglene gitt oven
* `terminal_strategy`: mottar valg fra `cin`