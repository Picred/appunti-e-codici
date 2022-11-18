# <font color = #FF0000>IMPIEGATI</font>
CODICEFISCALE | NOME | COGNOME | DATA DI NASCITA | FILIALE
---|-----|--------|------ | ----
 TRPNNT65A41F205E | ANTONIETTA | TRAPANESE | 01/01/1965 | RTZ5W
  FRNSVT80A01F205K | SALVATORE | FARANDA | 12/10/1971 | I36AV
  CHNNCL93L23F205R | NICOLA | CHINDAMO | 23/07/1993 | ZFF31
  RSPRBR78L02F205Q | ROMEO BERNARDINI | RESPIGHI | 02/07/1978 | F02LN
  LMBTMC88T25F839D | TELEMACO | LOMBARDI | 25/12/1988 | ZFF31
  CMRPRZ80A01C351D | PATRIZIA | COMERIATO | 01/01/1980 | RTZ5W
   PVRVSS64M53H501W | VANESSA | PAVAROTTI | 13/08/1964 | I36AV

# <font color = #FF0000>FILIALI</font>
CODICE | SEDE | DIRETTORE
------| ------| ------
F02LN | GROSSETO (GR) |  RSPRBR78L02F205Q
ZFF31 | PISTOIA (PT) | CHNNCL93L23F205R
RTZ5W | CUNEO (CN) |TRPNNT65A41F205E
I36AV | BOLZANO (BZ) | PVRVSS64M53H501W

# <font color = #FF0000>I 3 VINCOLI PRINCIPALI </font>

## <font color = #0000FF>CHIAVI</font>
* CODICE FISCALE (_IMPIEGATI_)
* CODICE (_FILIALI_)

## <font color = #0000FF>CHIAVI ESTERNE</font>
- FILIALE (_IMPIEGATI_ : da codice della filiale)
- DIRETTORE (_FILIALE_: da codice fiscale di impiegati)

## <font color = #0000FF>NULL </font>
>Si può omettere tutto tranne il codice fiscale e la filiale in **IMPIEGATI**
- Si può omettere la sede in **FILIALI**
- Filiali(direttore) non può essere null
- Direttore(filiali) non può essere null

# <font color = #FF0000>ALTRI VINCOLI IMPIEGATI</font>
- Ogni dato dell'attributo filiale deve appartenere alla relazione "filiali" in particolare all'attributo codice.
- Il codice fiscale deve essere composto da 16 caratteri e deve essere una stringa alfanumerica
- Nome e cognome non devono avere caratteri speciali (escluso apostrofo e accenti)
- La data di nascita deve essere del tipo GG/MM/AAAA (giorno, mese, anno)
- Tutti i caratteri devono avere il formato maiuscolo
- Il codice fiscale deve essere univoco

# <font color = #FF0000>ALTRI VINCOLI FILIALI</font>
- Ogni dato dell'attributo direttore deve appartenere alla relazione "impiegati" in particolare all'attributo codice fiscale.
- Le sedi devono essere del formato: CITTA(sigla provincia)
- Il codice deve essere univoco