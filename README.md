# text

V tomto projekte sa pracuje s textom

## Inštalácia

1. Klonuj repozitár:
   ```bash
   git clone git@github.com:filiplancaric1/console-text-processor.git
   cd console-text-processor
Prelož program:

bash
Kopírovať
Upraviť
gcc main.c -o processor -lm

### Použitie – dostupné príkazy
I/O príkazy
in – načítaj vstup

out op – vypíš aktuálny výstup

out range – vypíš zadaný rozsah

out mem – vypíš pamäťový blok

Pohyb v texte
move {sp/ep} n – posuň sp (start pointer) alebo ep (end pointer) o n slov

start {sp/ep} – nastav začiatok

end {sp/ep} – nastav koniec

Detekcia slov
first – nastav na prvé slovo

last – nastav na posledné slovo

prev – predchádzajúce slovo

next – nasledujúce slovo

Operácie s reťazcami
del – zmaž výber

crop – orež výber

copy – skopíruj výber

insert {n/mem} – vlož slovo z pamäte alebo pozície

replace – nahraď výber

Ukončenie programu
exit alebo quit
