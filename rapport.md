Rapport
=======

I starten var det et par problemer ang. implementasjonen og foreståelsen av denne; spesielt dette med å finne
ut hvilke metoder som ikke trengte implementeres. 
Samtidig er det også en del data som ikke deles i klassene, f.eks så har ikke `strategy`-klassene tilgang til
`controlType`, som kan skape litt forvirring.

Ellers var det litt vanskelig mtp. dealer; om den skulle være en gambler eller ikke, og hvordan dealer's strategi kunne
løses på en god og effektiv måte.

Jeg har også gått for en egen sorterings/shuffling-algoritme, istedenfor å bruke en ferdigbygd i C++. Dette valget kan
diskuteres, men jeg mener stokkealgoritmen min fungerer til sitt bruk.

Implementasjonen er ikke helt fullbyrdet, for eksempel så er det ingen plass å legge spiller-satsingene. Dette kan selvfølgelis lagres i 
et lokalt `cash`-array i automatic memory. 

