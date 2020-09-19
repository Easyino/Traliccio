void aggiornaValori() {
  // voltaggio=(float)random(450,550)/100;   //RANDOM
  if (random(1, 5) % 2 == 0) {
    if (voltaggio < 100) {
      voltaggio ++;
    }
  }
  else if (voltaggio > 0){
    voltaggio --;
  }
  corrente = 5;
  potenza = voltaggio * corrente;
  Serial.println(n_valori);
  if (potenza > soglia_potenza)inSovraccarico = true;
  else {
    inSovraccarico = false;
    prima_volta = true;
  }
  if (digitalRead(pala))inVerde = true;
  else inVerde = false;
}
